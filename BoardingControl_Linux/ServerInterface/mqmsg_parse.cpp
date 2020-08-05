#include "mqmsg_parse.h"
#include "settings.h"
#include "homepage.h"
#include "ServerInterface/httpAPI.h"
#include <QJsonDocument>
#include <QDebug>

ParseMQmsg::ParseMQmsg(QObject* parent)
    :QObject(parent)
{
    initAmqp();
}

ParseMQmsg::~ParseMQmsg()
{
    if (m_Amqp != nullptr){
        if (m_channel_id != -1)
            m_Amqp->destory_channel(m_channel_id);

        delete m_Amqp;
        m_Amqp = nullptr;
    }
}

void ParseMQmsg::initAmqp()
{
    QByteArray hostname = LocalSettings::instance()->value("amqpServer/hostname").toByteArray();
    int port=LocalSettings::instance()->value("amqpServer/port").toInt();
    QByteArray user_name=LocalSettings::instance()->value("amqpServer/user_name").toByteArray();
    QByteArray password=LocalSettings::instance()->value("amqpServer/password").toByteArray();
    QByteArray exchange_id=LocalSettings::instance()->value("amqpServer/exchange_id").toByteArray();
    QByteArray binding_key=LocalSettings::instance()->value("amqpServer/binding_key").toByteArray();

    ChannelType type=CHANNEL_CONSUMER;
    QString str_queue_name = QApplication::applicationName() + "_" + LocalSettings::instance()->value("Device/deviceCode").toString() + "_" + LocalSettings::instance()->value("Device/boardingGateNo").toString();
    QByteArray byte_queue_name = str_queue_name.toLatin1();
    consumer_msg_cb callback = msgRecivedCallBack;
    void* userData = this;

    m_Amqp = new AmqpManager(hostname.data(), port, user_name.data(), password.data());
    //创建通道,注册消息队列回调
    m_channel_id = m_Amqp->create_channel(exchange_id.data(), type, callback, userData, byte_queue_name.data(), binding_key.data());

    connect(m_Amqp, SIGNAL(mqServerStat(int, bool)), HomePage::global_instance, SLOT(on_mqServerStat(int, bool)));
}

void CALLBACK ParseMQmsg::msgRecivedCallBack(const char* jsonMsg, void* userData)
{
    ParseMQmsg *this_data = static_cast <ParseMQmsg*> (userData);
    QByteArray byte_JsonMsg(jsonMsg);

    this_data->recive_msg(byte_JsonMsg);
}

void ParseMQmsg::recive_msg(QByteArray &byte_jsonMsg)
{
    QMutexLocker locker(&m_mutex);

    if (byte_jsonMsg!=nullptr)
    {
        QJsonParseError jsonParseError;
        QJsonDocument jd_jsonMsg = QJsonDocument::fromJson(byte_jsonMsg, &jsonParseError);

        if (!jd_jsonMsg.isNull() && jsonParseError.error == QJsonParseError::NoError)
        {
            QJsonObject jo_jsonMsg = jd_jsonMsg.object();
            if (LocalSettings::instance()->value("Debug/isLogData", false).toBool())
                qInfo() << "[MQ MSG DebugInfo]" << jo_jsonMsg;

            int n_type = 0;
            if (jo_jsonMsg.contains("optType")){
                n_type = jo_jsonMsg["optType"].toInt();
            }

            if(jo_jsonMsg["msg"].isArray()){
                QJsonArray arry_msg = jo_jsonMsg["msg"].toArray();
                int size = arry_msg.size();
                int i = 0;
                bool found = false;

                for (; i<size; i++){
                    QJsonObject msg = arry_msg[i].toObject();

                    if (0 == QString::compare(msg.value("boardingGate").toString(), LocalSettings::instance()->value("Device/boardingGateNo").toString())){
                        QJsonObject content = msg["content"].toObject();
                        found = true;
                        switch (n_type) {
                        case 100:
                            optType100(content);
                            break;

                        case 101:
                            //Date:2020-04-27:[Bug:1298];建库消息全部按照航班计划处理,
                            optType100(content);
                            optType101(content);
                            break;

                        case 102:
                            optType102(content);
                            break;

                        case 103:
                            optType103(content);
                            break;

                        case 109:
                            optType109(content);
                            break;

                        case 300:
                            optType300(content);
                            break;

                        case 301:
                            optType301(content);
                            break;
                        case 302:
                        {
                            QJsonArray arry = msg["content"].toArray();
                            optType302(arry);
                        }
                            break;
                        default:
                            qWarning()<<QString("recived mq msg  parse to 'Json' ok, but unknowm <optType = %1> !").arg(n_type);
                            break;
                        }
                    }
                }
                if (!found)
                    qWarning()<<"recived mq msg Parsed, not found  match 'boardingGateNo'!";
            }
            else qWarning()<<"recived mq msg Parsed, <msg> param error, not 'QJsonArry'!";
        }
        else
        {
            qWarning()<<"mq msg recived  parse to 'Json' error!";
        }
    }
}

void ParseMQmsg::optType100(QJsonObject& content)
{
    flight_plan.arrAirportCode=content["arrAirportCode"].toString();
    flight_plan.arrAirportName=content["arrAirportName"].toString();
    flight_plan.boardingGate=content["boardingGate"].toString();
    flight_plan.depAirportCode=content["depAirportCode"].toString();
    flight_plan.depAirportName=content["depAirportName"].toString();
    flight_plan.depTimeJ=content["depTimeJ"].toString();
    flight_plan.depTimeS=content["depTimeS"].toString();
    flight_plan.boardingTime=content["boardingTime"].toString();
    flight_plan.flightDate=content["flightDate"].toString();
    flight_plan.kindType=content["kindType"].toInt();
    flight_plan.manulOpt=content["manulOpt"].toBool();
    flight_plan.midwayCode=content["midwayCode"].toString();
    flight_plan.midwayName=content["midwayName"].toString();
    flight_plan.boardingNum=content["boardingNum"].toInt();
    flight_plan.orgDepNum=content["orgDepNum"].toInt();
    flight_plan.transferNum=content["transferNum"].toInt();
    flight_plan.midwayNum=content["midwayNum"].toInt();
    flight_plan.faceNums=content["faceNums"].toInt();
    flight_plan.babyNum=content["babyNum"].toInt();
    QString tmpStr=content["shareFltno"].toString();
    flight_plan.shareFltno=tmpStr.split(",", QString::SkipEmptyParts);
    flight_plan.status=content["status"].toInt();
    flight_plan.threeFlightNo=content["threeFlightNo"].toString();
    flight_plan.twoFlightNo=content["twoFlightNo"].toString();

    if (flight_plan.boardingGate.isEmpty()){
        flight_plan.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
        flight_plan.status = 0;
    }
    if (HomePage::s_mode == 0){//异步推送航班计划
        HomePage::s_type = HomePage::global_instance->m_RealtimeBoarding->m_boardingMode;
        HomePage::s_status = flight_plan.status;
        HttpAPI::instance()->pushPlan(1, flight_plan, HomePage::s_mode, HomePage::s_type,  HomePage::s_collectType, flight_plan.status);
        HttpAPI::instance()->pushPlan(2, flight_plan, HomePage::s_mode, HomePage::s_type,  HomePage::s_collectType, flight_plan.status);
    }
    emit recivedMQmsg(100);
}

void ParseMQmsg::optType101(QJsonObject &content)
{
    creat_repository.arrAirportCode=content["arrAirportCode"].toString();
    creat_repository.arrAirportName=content["arrAirportName"].toString();
    creat_repository.boardingGate=content["boardingGate"].toString();
    creat_repository.depAirportCode=content["depAirportCode"].toString();
    creat_repository.depAirportName=content["depAirportName"].toString();
    creat_repository.depTimeJ=content["depTimeJ"].toString();
    creat_repository.depTimeS=content["depTimeS"].toString();
    creat_repository.boardingTime=content["boardingTime"].toString();
    creat_repository.flightDate=content["flightDate"].toString();
    creat_repository.kindType=content["kindType"].toInt();
    creat_repository.manulOpt=content["manulOpt"].toBool();
    creat_repository.midwayCode=content["midwayCode"].toString();
    creat_repository.midwayName=content["midwayName"].toString();
    creat_repository.boardingNum=content["boardingNum"].toInt();
    creat_repository.orgDepNum=content["orgDepNum"].toInt();
    creat_repository.transferNum=content["transferNum"].toInt();
    creat_repository.midwayNum=content["midwayNum"].toInt();
    creat_repository.faceNums=content["faceNums"].toInt();
    creat_repository.babyNum=content["babyNum"].toInt();
    QString tmpStr=content["shareFltno"].toString();
    creat_repository.shareFltno=tmpStr.split(",", QString::SkipEmptyParts);
    creat_repository.status=content["status"].toInt();
    creat_repository.threeFlightNo=content["threeFlightNo"].toString();
    creat_repository.twoFlightNo=content["twoFlightNo"].toString();

    if (creat_repository.boardingGate.isEmpty()){
        creat_repository.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
        creat_repository.status = 0;
    }
    emit recivedMQmsg(101);
}

void ParseMQmsg::optType102(QJsonObject &content)
{
    bording_start.arrAirportCode=content["arrAirportCode"].toString();
    bording_start.arrAirportName=content["arrAirportName"].toString();
    bording_start.boardingGate=content["boardingGate"].toString();
    bording_start.depAirportCode=content["depAirportCode"].toString();
    bording_start.depAirportName=content["depAirportName"].toString();
    bording_start.depTimeJ=content["depTimeJ"].toString();
    bording_start.depTimeS=content["depTimeS"].toString();
    bording_start.boardingTime=content["boardingTime"].toString();
    bording_start.flightDate=content["flightDate"].toString();
    bording_start.kindType=content["kindType"].toInt();
    bording_start.manulOpt=content["manulOpt"].toBool();
    bording_start.midwayCode=content["midwayCode"].toString();
    bording_start.midwayName=content["midwayName"].toString();
    bording_start.boardingNum=content["boardingNum"].toInt();
    bording_start.orgDepNum=content["orgDepNum"].toInt();
    bording_start.transferNum=content["transferNum"].toInt();
    bording_start.midwayNum=content["midwayNum"].toInt();
    bording_start.faceNums=content["faceNums"].toInt();
    bording_start.babyNum=content["babyNum"].toInt();
    QString tmpStr=content["shareFltno"].toString();
    bording_start.shareFltno=tmpStr.split(",", QString::SkipEmptyParts);
    bording_start.status=content["status"].toInt();
    bording_start.threeFlightNo=content["threeFlightNo"].toString();
    bording_start.twoFlightNo=content["twoFlightNo"].toString();

    if (bording_start.boardingGate.isEmpty()){
        bording_start.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
        bording_start.status = 0;
    }
    emit recivedMQmsg(102);

}

void ParseMQmsg::optType103(QJsonObject &content)
{
//    boarding_end = content103();
    boarding_end = FlightPlan();
    boarding_end.arrAirportCode=content["arrAirportCode"].toString();
    boarding_end.arrAirportName=content["arrAirportName"].toString();
    boarding_end.boardingGate=content["boardingGate"].toString();
    boarding_end.boardingTime=content["boardingTime"].toString();
    boarding_end.depAirportCode=content["depAirportCode"].toString();
    boarding_end.depAirportName=content["depAirportName"].toString();
    boarding_end.depTimeJ=content["depTimeJ"].toString();
    boarding_end.depTimeS=content["depTimeS"].toString();
    boarding_end.flightDate=content["flightDate"].toString();
    boarding_end.kindType=content["kindType"].toInt();
    boarding_end.manulOpt=content["manulOpt"].toBool();
    boarding_end.midwayCode=content["midwayCode"].toString();
    boarding_end.midwayName=content["midwayName"].toString();
    QString tmpStr=content["shareFltno"].toString();
    boarding_end.shareFltno=tmpStr.split(",", QString::SkipEmptyParts);
    boarding_end.status=content["status"].toInt();
    boarding_end.threeFlightNo=content["threeFlightNo"].toString();
    boarding_end.boardingNum=content["boardingNum"].toInt();
    boarding_end.orgDepNum=content["orgDepNum"].toInt();
    boarding_end.transferNum=content["transferNum"].toInt();
    boarding_end.midwayNum=content["midwayNum"].toInt();
    boarding_end.faceNums=content["faceNums"].toInt();
    boarding_end.babyNum=content["babyNum"].toInt();

//    boarding_end.lastRecogTime=content["lastRecogTime"].toString();
    boarding_end.twoFlightNo=content["twoFlightNo"].toString();

    if (boarding_end.boardingGate.isEmpty()){
        boarding_end.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
        boarding_end.status = 0;
    }
    emit recivedMQmsg(103);
}

void ParseMQmsg::optType109(QJsonObject &content)
{
    remove_repository = content109();
    remove_repository.arrAirportCode=content["arrAirportCode"].toString();
    remove_repository.arrAirportName=content["arrAirportName"].toString();
    remove_repository.boardingGate=content["boardingGate"].toString();
    remove_repository.boardingTime=content["boardingTime"].toString();
    remove_repository.depAirportCode=content["depAirportCode"].toString();
    remove_repository.depAirportName=content["depAirportName"].toString();
    remove_repository.depTimeJ=content["depTimeJ"].toString();
    remove_repository.flightDate=content["flightDate"].toString();
    remove_repository.kindType=content["kindType"].toInt();
    remove_repository.manulOpt=content["manulOpt"].toBool();
    remove_repository.midwayCode=content["midwayCode"].toString();
    remove_repository.midwayName=content["midwayName"].toString();
    QString tmpStr=content["shareFltno"].toString();
    remove_repository.shareFltno=tmpStr.split(",", QString::SkipEmptyParts);
    remove_repository.status=content["status"].toInt();
    remove_repository.threeFlightNo=content["threeFlightNo"].toString();
    remove_repository.twoFlightNo=content["twoFlightNo"].toString();

    if (remove_repository.boardingGate.isEmpty()){
        remove_repository.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
        remove_repository.status = 0;
    }
    emit recivedMQmsg(109);
}

void ParseMQmsg::optType300(QJsonObject &content)
{
    face_identify_res = content300();
    face_identify_res.basePhoto=QByteArray::fromBase64(content["basePhoto"].toVariant().toByteArray());
    face_identify_res.boardingNumber=content["boardingNumber"].toString();
    face_identify_res.boardingStatus=content["boardingStatus"].toInt();
    face_identify_res.cardNo=content["cardNo"].toString();
    face_identify_res.cardType=content["cardType"].toInt();
    face_identify_res.endPort=content["endPort"].toString();
    face_identify_res.faceImage=QByteArray::fromBase64(content["faceImage"].toVariant().toByteArray());
    face_identify_res.fId=content["fId"].toString();
    face_identify_res.flightDay=content["flightDay"].toString();
    face_identify_res.flightNumber=content["flightNumber"].toString();
    face_identify_res.isVipChannel=content["isVipChannel"].toString();
    face_identify_res.nameEn=content["nameEn"].toString();
    face_identify_res.nameZh=content["nameZh"].toString();
    face_identify_res.recognizeTime=content["recognizeTime"].toString();
    face_identify_res.reviewInfo=content["reviewInfo"].toString();
    face_identify_res.score=content["score"].toVariant().toFloat();
    face_identify_res.seatNumber=content["seatNumber"].toString();
    face_identify_res.securityInfo=content["securityInfo"].toString();
    face_identify_res.sex=content["sex"].toInt();
    face_identify_res.sourceType=content["sourceType"].toString();
    face_identify_res.startPort=content["startPort"].toString();
    face_identify_res.threshold=content["threshold"].toVariant().toFloat();
    face_identify_res.transferInfo=content["transferInfo"].toString();

    emit recivedMQmsg(300);
}

void ParseMQmsg::optType301(QJsonObject &content)
{
    ppl_num = content301();
    ppl_num.flightNo=content["flightNo"].toString();
    ppl_num.flightDate=content["flightDate"].toString();
    ppl_num.boardingNum=content["boardingNum"].toInt();
    ppl_num.faceNums=content["faceNums"].toInt();
    ppl_num.transferNum=content["transferNum"].toInt();
    ppl_num.orgDepNum=content["orgDepNum"].toInt();
    ppl_num.midwayNum=content["midwayNum"].toInt();
    ppl_num.babyNum=content["babyNum"].toInt();

    emit recivedMQmsg(301);
}


void ParseMQmsg::optType302(QJsonArray &arry)
{
    new_repository = arry;

    emit recivedMQmsg(302);
}
