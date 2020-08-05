#ifndef MQMSG_PARSING
#define MQMSG_PARSING

#include "rabbitmq_c/amqpmanager.h"
#include "api_param_def.h"

#include<QMutex>
#include <QList>
#include <QObject>

#define RUN_IN_CALLBACK

class ParseMQmsg : public QObject
{
    Q_OBJECT
public:
    explicit ParseMQmsg(QObject* parent = 0);
    virtual ~ParseMQmsg();

signals:
    void recivedMQmsg(int type);

private:
    void initAmqp();

    static void CALLBACK msgRecivedCallBack(const char* jsonMsg, void* userData);

    void RUN_IN_CALLBACK recive_msg(QByteArray &byte_jsonMsg);

    //100-发布航班计划
    void RUN_IN_CALLBACK optType100(QJsonObject &object);
    //101-建库消息
    void RUN_IN_CALLBACK optType101(QJsonObject &object);
    //102-开始登机消息
    void RUN_IN_CALLBACK optType102(QJsonObject &object);
    //103-结束登机消息
    void RUN_IN_CALLBACK optType103(QJsonObject &object);
    //109-删库消息
    void RUN_IN_CALLBACK optType109(QJsonObject &object);
    //300-识别结果推送
    void RUN_IN_CALLBACK optType300(QJsonObject &object);
    //301-航班的登机人数
    void RUN_IN_CALLBACK optType301(QJsonObject &object);

    void RUN_IN_CALLBACK optType302(QJsonArray &array);

public:
    FlightPlan flight_plan;       //航班计划
    FlightPlan creat_repository;       //建库消息
    FlightPlan bording_start;       //开始登机消息
    FlightPlan boarding_end;       //结束登机消息
    content109 remove_repository;       //删库消息
    content300 face_identify_res;       //识别结果推送
    content301 ppl_num;      //航班的登机人数
    QJsonArray new_repository;

private:
    QMutex m_mutex;
    AmqpManager *m_Amqp{nullptr};
    int m_channel_id{-1};
};

#endif // MQMSG_PARSING

