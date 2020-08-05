#include "amqpmanager.h"
#include <QDebug>

AmqpManager::AmqpManager(const char* ip,
                         int port,
                         const char* user_name,
                         const char* password)
    :QObject(nullptr),
    _strIp(ip),
    _port(port),
    _user(user_name),
    _password(password),
    _is_open_guard(false)
{
    for(int i = 0; i < MAX_MQCHANNEL; i++)
    {
        _vecChannel.push_back(true);
    }
}

AmqpManager::~AmqpManager()
{
    unInit_auto_reconn();
}

void AmqpManager::init_auto_reconn()
{
    if (!_is_open_guard){
        _is_open_guard = true;
        _thread = std::thread(&AmqpManager::autoReconnect, this);
    }
}

void AmqpManager::unInit_auto_reconn()
{
    if (_is_open_guard){
        _is_open_guard = false;
        if(_thread.joinable())
            _thread.join();
    }
}

//创建通道
int AmqpManager::create_channel(const char* exchange_id, ChannelType type, consumer_msg_cb cb, void* userData,
                                const char* queue_name, const char* bingding_key, const char* vhost, int sec_heatbeat)
{

    int channel = GetChannel();
    if( channel == -1)
        return -1;

    {
        std::lock_guard<std::mutex> lock(_mtx);
        AmqpImpPtr ptr(new AmqpImp);
        try
        {
            ptr->create_channel(_strIp.c_str(), _port, _user.c_str(), _password.c_str(), exchange_id, type, cb, userData, queue_name, bingding_key, vhost, sec_heatbeat);
        }
        catch(MQException& exp)
        {
            qCritical() << exp.message().c_str();
            channel = -1;
        }
        _mapImp[channel] = ptr;
    }
    init_auto_reconn();
    return channel;
}

//关闭通道
void AmqpManager::destory_channel(int channel)
{
    {
        std::lock_guard<std::mutex> lock(_mtx);

        auto it = _mapImp.find(channel);
        if(it != _mapImp.end())
        {
            AmqpImpPtr tmp = it->second;
            try
            {
                tmp->close_channel();
            }catch(MQException& exp)
            {
                qWarning() << exp.message().c_str();
            }
            _mapImp.erase(it);
            ReleaseChannel(channel);
        }
        else return;
    }

    unInit_auto_reconn();

}

//发送消息
void AmqpManager::public_message(int channel, const char* msg, const char* exchangeName, const char* exchangeKey)
{
    AmqpImpPtr tmp(nullptr);

    {
        std::lock_guard<std::mutex> lock(_mtx);
        std::map<int, AmqpImpPtr>::iterator it = _mapImp.find(channel);
        if(it != _mapImp.end())
        {
            tmp = it->second;
        }
    }

    if(tmp.get() != nullptr)
    {
        tmp->publish_message(msg, exchangeName, exchangeKey);
    }
}

int AmqpManager::GetChannel()
{
    for(int i = 0; i < static_cast<int>(_vecChannel.size()); i++)
    {
        if(_vecChannel[i])
        {
            _vecChannel[i] = false;
            return i;
        }
    }

    return -1;
}

void AmqpManager::ReleaseChannel(int channel)
{
    _vecChannel[channel] = true;
}


void AmqpManager::autoReconnect()
{
    while (_is_open_guard)
    {
        {
            std::lock_guard<std::mutex> lock(_mtx);
            std::map<int, AmqpImpPtr>::iterator it = _mapImp.begin();//only the first of ma_channel will reconnecte
            while (it != _mapImp.end())
            {
                AmqpImpPtr tmp = it->second;
                if(tmp->get_connect_state() == 0)
                {
                    emit mqServerStat(it->first, false);
                    qWarning() << "[AmqpManager::autoReconnect] amqp disconnected, try reconnecting...";
                    try
                    {
                        tmp->reconnect();
                        qInfo() << "[AmqpManager::autoReconnect] reconnect success";
                    }catch(MQException& exp)
                    {
                        qCritical() << exp.message().c_str();
                    }
                }
                else {
                    emit mqServerStat(it->first, true);
                }
                it++;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}
