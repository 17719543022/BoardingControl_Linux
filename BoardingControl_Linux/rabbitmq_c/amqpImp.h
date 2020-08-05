#ifndef AMQPIMP_H
#define AMQPIMP_H

#include "amqp.h"
#include "utils.h"
#include <thread>
//#include <memory>

#define DEFAULT_QUEUE_ID "application_boarding_ctrl"
#define DEFAULT_EXCHANGE_ID "amq.fanout"
#define DEFAULT_BINDING_KEY ""

#ifdef _WIN32
#define CALLBACK __stdcall
#else
#define CALLBACK
#endif

typedef void CALLBACK ( *consumer_msg_cb)(const char* msg, void* userData);

typedef enum _ChannelType
{
    CHANNEL_PRODUCER = 0,
    CHANNEL_CONSUMER,

}ChannelType;

class AmqpImp
{
public:
    AmqpImp();
    virtual ~AmqpImp(void);

    //创建通道 /*areaId_deviceId 构成 queueName*/
    int create_channel(const char* hostname, int port, const char* user_name, const char* password,
                       const char* exchange_id, ChannelType type = CHANNEL_CONSUMER,
                       consumer_msg_cb cb = nullptr, void* userData = nullptr,
                       const char* queue_name = nullptr, const char* binding_key = nullptr,
                       const char* vhost = AMQP_DEFAULT_VHOST, int sec_heartbeat = 0);
    //关闭通道
    int close_channel();
        //发送消息public
    int publish_message(const char* message, const char* exchange, const char* rout_key);
    //获取信息public
    char* get_message(const char* queue_name_, uint64_t* out_body_size);
    //重连
    void reconnect();
    //查询连接状态
    int get_connect_state();

private:
    //创建连接, 设置连接和通道,登录以及设置心跳参数
    int setup_connection();    //关闭销毁连接
    int close_and_destory_connection();
    //创建消息接收队列绑定
    int queue_declare_and_bind(const char* queue_name, const char* exchange_name, const char* routingKey, int ttl, int msglen);
	//获取信息
	char* basic_get(const char* queue_name, uint64_t* out_body_size);
	//发布消息
	int  basic_publish(const char* message, const char* exchange, const char* rout_key);
	//消费消息
	void consume_message();

private:
    amqp_connection_state_t _conn_state{nullptr};
    int _channel{1};
    int _connect_states{0};

    std::string m_hostname;
    int m_port{5672};
    std::string m_vhost;
    std::string m_user_name;
    std::string m_password;
    ChannelType m_channelType;
    std::string m_queueID;
    std::string m_exchange_id;
    std::string m_binding_key;
    int m_sec_heartbeat{0};

    consumer_msg_cb _msg_cb{nullptr};
    void* _userData{nullptr};
	std::thread _consume_thread;
    bool  _consum_loop{false};
};

typedef std::shared_ptr<AmqpImp> AmqpImpPtr;

#endif //AMQPIMP_H
