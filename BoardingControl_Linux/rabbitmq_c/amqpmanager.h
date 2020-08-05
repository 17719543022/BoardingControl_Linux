#ifndef AMQPMANAGER_H
#define AMQPMANAGER_H

#include "amqpImp.h"
#include <mutex>
#include <vector>
#include <map>
#include <cstring>
#include <thread>
#include <QObject>

#define MAX_MQCHANNEL 24

class AmqpManager :public QObject
{
    Q_OBJECT
public:
    AmqpManager(const char* ip, int port, const char* user_name, const char* password);

    virtual ~AmqpManager();

    //创建通道
    int create_channel(const char* exchange_id,
                       ChannelType type = CHANNEL_CONSUMER, consumer_msg_cb cb = nullptr, void* userData = nullptr,
                       const char* queue_name = nullptr, const char* bingding_key = nullptr,
                       const char* vhost = AMQP_DEFAULT_VHOST, int sec_heartbeat = 0);
    //关闭通道
    void destory_channel(int channel);

    //发送消息
    void public_message(int channel, const char* msg, const char* exchangeName, const char* exchangeKey);


signals:
    void mqServerStat(int channel, bool bOk);

private:
    void init_auto_reconn();
    void unInit_auto_reconn();

    int GetChannel();
    void ReleaseChannel(int channel);

    void autoReconnect();

private:
    std::string _strIp;
    int _port;
    std::string _vhost;
    std::string _user;
    std::string _password;
    std::thread _thread;
    bool _is_open_guard;
    std::mutex _mtx;
    std::vector<bool> _vecChannel;
    std::map<int, AmqpImpPtr> _mapImp;
};

#endif // AMQPMANAGER_H
