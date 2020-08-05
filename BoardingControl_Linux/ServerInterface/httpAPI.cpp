#include "httpAPI.h"
#include "libHTTP.h"
#include "settings.h"

#include <QThread>
#include <QCoreApplication>
#include <QUuid>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>
#include <QDate>

HttpAPI::HttpAPI(QObject *parent) : QObject(parent)
{
    caPath=QCoreApplication::applicationDirPath()+"/boot/cacert.crt";
//    apiId="123456";
//    apiKey="1285384ddfb057814bad78127bc789be";
    m_reqId = QUuid::createUuid().toRfc4122().toHex();
    m_isLogData = LocalSettings::instance()->value("Debug/isLogData", false).toBool();

    bool b_ok;
    maxPostFailTimes = LocalSettings::instance()->value("Debug/maxPostFailTimes", 1).toInt(&b_ok);
    if (!b_ok || 0 == maxPostFailTimes)
        maxPostFailTimes = 1;

    flight_palne_Addr=LocalSettings::instance()->value("Server/flight_palne_Addr").toString();
    startBording_Addr=LocalSettings::instance()->value("Server/startBording_Addr").toString();
    endBording_Addr=LocalSettings::instance()->value("Server/endBording_Addr").toString();
    otherFlight_Addr=LocalSettings::instance()->value("Server/otherFlight_Addr").toString();
    cancelFlight_Addr=LocalSettings::instance()->value("Server/cancelFlight_Addr").toString();
    exceptionFlight_Addr=LocalSettings::instance()->value("Server/exceptionFlight_Addr").toString();
    queryFlight_Addr=LocalSettings::instance()->value("Server/queryFlight_Addr").toString();
    queryPPL_Addr=LocalSettings::instance()->value("Server/queryPPL_Addr").toString();
    flight_palne_API="/api/v1/face/boarding/flightplan";
    startBording_API="/api/v1/face/boarding/start";
    endBording_API="/api/v1/face/boarding/finish";
    otherFlight_API="/api/v1/face/boarding/strange";
    cancelFlight_API="/api/v1/face/boarding/cancel";
    exceptionFlight_API="/api/v1/face/boarding/active";
    queryFlight_API="/api/v1/face/boarding/queryFlights";
    queryPPL_API="/api/v1/face/data/flowback-query";


/*LiuYong*/
    flightReviewServer_Addr = LocalSettings::instance()->value("Server/flightReviewServer").toString();
    flightReview_API = "/api/v1/face/boarding/passenger-query";
    libDeleteFlight_API = "/api/v1/face/boarding/lib-delete";
/*LiuYong*/


    GateChannel_Addr[0]=LocalSettings::instance()->value("GateChannel_1/gateChannel_Addr").toString();
    GateChannel_Addr[1]=LocalSettings::instance()->value("GateChannel_2/gateChannel_Addr").toString();

    gate_ctrl_API="/api/v1/face/boarding/gate-control";
    boardingMode_manualCtrl_API="/api/v1/face/boarding/manual-boarding";
    collectingMode_cmd_API="/api/v1/face/boarding/collect-control";
    collectingMode_manualCtrl_API="/api/v1/face/boarding/manual-collect";
    pushPlan_API="/api/v1/face/boarding/push-plan";

    Init();
}

HttpAPI::~HttpAPI()
{
    UnInit();
}

int HttpAPI::Init()
{
    int res=-1;
    try {
        char* chr_caPath=caPath.toLatin1().data();

        res=LIBInit(chr_caPath);
        if(res!=0)
        {
            qCritical()<<QString("LIBInit res:%1").arg(res);
            return res;
        } else {
            qInfo()<<"HttpLib init finished";
        }
        setHeader(flight_palne_Addr, flight_palne_API);
        setHeader(startBording_Addr, startBording_API);
        setHeader(endBording_Addr, endBording_API);
        setHeader(otherFlight_Addr, otherFlight_API);
        setHeader(cancelFlight_Addr, cancelFlight_API);
        setHeader(exceptionFlight_Addr, exceptionFlight_API);
        setHeader(queryFlight_Addr, queryFlight_API);
        setHeader(queryPPL_Addr, queryPPL_API);
        //LiuYong
        setHeader(flightReviewServer_Addr, flightReview_API);
        setHeader(flightReviewServer_Addr, libDeleteFlight_API);

        for (int i=0; i<2; i++){
            setHeader(GateChannel_Addr[i], gate_ctrl_API);
            setHeader(GateChannel_Addr[i], boardingMode_manualCtrl_API);
            setHeader(GateChannel_Addr[i], collectingMode_cmd_API);
            setHeader(GateChannel_Addr[i], collectingMode_manualCtrl_API);
            setHeader(GateChannel_Addr[i], pushPlan_API);


        }

        return res;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

int HttpAPI::UnInit()
{
    int res=-1;
    try {
        removeHeader(flight_palne_Addr, flight_palne_API);
        removeHeader(startBording_Addr, startBording_API);
        removeHeader(endBording_Addr, endBording_API);
        removeHeader(otherFlight_Addr, otherFlight_API);
        removeHeader(cancelFlight_Addr, cancelFlight_API);
        removeHeader(exceptionFlight_Addr, exceptionFlight_API);
        removeHeader(queryFlight_Addr, queryFlight_API);
        removeHeader(queryPPL_Addr, queryPPL_API);
        //LiuYong
        removeHeader(flightReviewServer_Addr, flightReview_API);
        removeHeader(flightReviewServer_Addr, libDeleteFlight_API);

        for (int i=0; i<2; i++){
            removeHeader(GateChannel_Addr[i], gate_ctrl_API);
            removeHeader(GateChannel_Addr[i], boardingMode_manualCtrl_API);
            removeHeader(GateChannel_Addr[i], collectingMode_cmd_API);
            removeHeader(GateChannel_Addr[i], collectingMode_manualCtrl_API);
            removeHeader(GateChannel_Addr[i], pushPlan_API);
        }
        res=LIBUnInit();
        return res;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return res;
    }
}

int HttpAPI::setHeader(QString &addr, QString &API)
{
    QByteArray header;
    QJsonObject json;

    json.insert("url",API);
    header.append(QJsonDocument(json).toJson());
    const char* chr_header=header.data();

    QString str_url = addr + API;
    QByteArray byte_url = str_url.toUtf8();
    const char* chr_url=byte_url.data();

    int res=LIBSetHeaderEx(chr_url, chr_header);
    if(res!=0)
    {
        qCritical()<<QString("LIBSetHeaderEx res:%1").arg(res);
    }
    return res;
}

int HttpAPI::removeHeader(QString &addr, QString &API)
{
    QString faceurl=addr+API;
    char* chrurl=faceurl.toLatin1().data();

    int res=LIBRemoveHeader(chrurl);
    if(res!=0)
    {
        qCritical()<<QString("LIBRemoveHeader res:%1").arg(res);
    }
    return res;
}

Return_Flight_Plan_Param HttpAPI::getFlightPlan(const QString& boardingGateNo)
{
    Return_Flight_Plan_Param result;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId",m_reqId);
        json.insert("gateNo",boardingGateNo);
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(flight_palne_Addr).arg(flight_palne_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = flight_palne_Addr.toLatin1();
        QByteArray byte_api = flight_palne_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), "获取航班计划失败！\n请检查网络连接后重试！");
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code) << QThread::currentThread();
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject json1 = document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(flight_palne_API).arg(flight_palne_API)<<json1;
                }
                if(json1.contains("reqId")){
                    result.reqId=json1["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(json1.contains("msg")){
                    result.msg=json1["msg"].toString();
                }
                if(json1.contains("status")){
                    result.serverStatus=json1["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus) ,"获取航班计划失败！");
                    }
                }
                if(json1.contains("flightPlan")){
                    QJsonArray arry_flightPlan=json1["flightPlan"].toArray();
                    for (int i=0; i<arry_flightPlan.size(); i++){
                        if (arry_flightPlan.at(i).toObject().value("boardingGate").toString()
                                == LocalSettings::instance()->value("Device/boardingGateNo").toString()){
                            QJsonObject flightPlan = arry_flightPlan.at(i).toObject().value("content").toObject();

                            result.flightPlan.threeFlightNo=flightPlan.value("threeFlightNo").toString();
                            result.flightPlan.twoFlightNo=flightPlan.value("twoFlightNo").toString();
                            result.flightPlan.depTimeJ=flightPlan.value("depTimeJ").toString();
                            result.flightPlan.depTimeS=flightPlan.value("depTimeS").toString();
                            result.flightPlan.boardingTime=flightPlan.value("boardingTime").toString();
                            result.flightPlan.flightDate=flightPlan.value("flightDate").toString();
                            result.flightPlan.status=flightPlan.value("status").toInt();
                            result.flightPlan.midwayCode=flightPlan.value("midwayCode").toString();
                            result.flightPlan.midwayName=flightPlan.value("midwayName").toString();
                            result.flightPlan.arrAirportCode=flightPlan.value("arrAirportCode").toString();
                            result.flightPlan.arrAirportName=flightPlan.value("arrAirportName").toString();
                            result.flightPlan.depAirportCode=flightPlan.value("depAirportCode").toString();
                            result.flightPlan.depAirportName=flightPlan.value("depAirportName").toString();
                            result.flightPlan.boardingNum=flightPlan.value("boardingNum").toInt();
                            result.flightPlan.orgDepNum=flightPlan.value("orgDepNum").toInt();
                            result.flightPlan.transferNum=flightPlan.value("transferNum").toInt();
                            result.flightPlan.midwayNum=flightPlan.value("midwayNum").toInt();
                            result.flightPlan.faceNums=flightPlan.value("faceNums").toInt();
                            result.flightPlan.babyNum=flightPlan.value("babyNum").toInt();
                            result.flightPlan.shareFltno=flightPlan.value("shareFltno").toString().split(",", QString::SkipEmptyParts);
                            result.flightPlan.kindType=flightPlan.value("kindType").toInt();
                            result.flightPlan.manulOpt=flightPlan.value("manulOpt").toBool();
                            result.flightPlan.boardingGate=flightPlan.value("boardingGate").toString();
                        }
                    }
                    if (result.flightPlan.boardingGate.isEmpty()){
                        result.flightPlan.boardingGate= LocalSettings::instance()->value("Device/boardingGateNo").toString();
                        result.flightPlan.status = 0;
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

Return_Flight_Plan_Param HttpAPI::queryFlight(const QString& flightNo, const QDate &flightDate)
{
    Return_Flight_Plan_Param result;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId",m_reqId);
        json.insert("flightNo",flightNo);
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(queryFlight_Addr).arg(queryFlight_API)<<json;
        }
        char* body=bytes.data();
        char* response[1024];
        int resLen=0;
        QByteArray byte_addr = queryFlight_Addr.toLatin1();
        QByteArray byte_api = queryFlight_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(), byte_api.data(),body,response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), "航班查询失败！\n请检查网络连接后重试！");
            return result;
        }
        QByteArray ret_data=QByteArray(*response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject json1 = document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(queryFlight_Addr).arg(queryFlight_API)<<json1;
                }
                if(json1.contains("reqId")){
                    result.reqId=json1["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(json1.contains("msg")){
                    result.msg=json1["msg"].toString();
                }
                if(json1.contains("status")){
                    result.serverStatus=json1["status"].toInt();
                    //                    if (result.serverStatus != 0){
                    //                        emit networkStat(true/*, QString("%1(%2)").arg(result.msg).arg(result.serverStatus) ,"没有查询到此航班信息！"*/);
                    //                    }
                }
                if(json1.value("flightPlan").isArray()){
                    QJsonArray arry_flightPlan=json1["flightPlan"].toArray();
                    for (int i=0; i<arry_flightPlan.size(); i++){
                        QJsonObject flightPlan = arry_flightPlan.at(i).toObject();

                        ////TODO:认为查询结果只会有一个航班,不做日期比对
                        //有传日期就要做日期比对
                        if (flightDate.isNull() || (flightPlan.value("flightDate").toString() == flightDate.toString("yyyy-MM-dd"))){
                            result.flightPlan.threeFlightNo=flightPlan.value("threeFlightNo").toString();
                            result.flightPlan.twoFlightNo=flightPlan.value("twoFlightNo").toString();
                            result.flightPlan.depTimeJ=flightPlan.value("depTimeJ").toString();
                            result.flightPlan.boardingTime=flightPlan.value("boardingTime").toString();
                            result.flightPlan.flightDate=flightPlan.value("flightDate").toString();
                            result.flightPlan.status=flightPlan.value("status").toInt();
                            result.flightPlan.midwayCode=flightPlan.value("midwayCode").toString();
                            result.flightPlan.midwayName=flightPlan.value("midwayName").toString();
                            result.flightPlan.arrAirportCode=flightPlan.value("arrAirportCode").toString();
                            result.flightPlan.arrAirportName=flightPlan.value("arrAirportName").toString();
                            result.flightPlan.depAirportCode=flightPlan.value("depAirportCode").toString();
                            result.flightPlan.depAirportName=flightPlan.value("depAirportName").toString();
                            result.flightPlan.orgDepNum=flightPlan.value("orgDepNum").toInt();
                            result.flightPlan.transferNum=flightPlan.value("transferNum").toInt();
                            result.flightPlan.midwayNum=flightPlan.value("midwayNum").toInt();
                            result.flightPlan.faceNums=flightPlan.value("faceNums").toInt();
                            result.flightPlan.shareFltno=flightPlan.value("shareFltno").toString().split(",", QString::SkipEmptyParts);
                            result.flightPlan.kindType=flightPlan.value("kindType").toInt();
                            result.flightPlan.manulOpt=flightPlan.value("manulOpt").toBool();
                            result.flightPlan.boardingGate=flightPlan.value("boardingGate").toString();
                        }
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

int HttpAPI::enquiryPPL(const QString& flightNo, const QString& boardingNumber, QJsonObject& outObject, const QString& seatNO, bool isBaby, const QString& flightDay)
{
    int ret = -1;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId",m_reqId);
//        json.insert("cardId","");
        json.insert("flightNo",flightNo);
        json.insert("boardingNumber",boardingNumber);
        json.insert("seatId",seatNO);
        if (!flightDay.isEmpty())
            json.insert("flightDay", flightDay);
        json.insert("isFuzzyQuery", 1);
        if (isBaby)
            json.insert("seatId", "INF");
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post Boarding <%1%2> send body]: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = queryPPL_Addr.toLatin1();
        QByteArray byte_api = queryPPL_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != ret && tmp_post_times++ < maxPostFailTimes) {
            ret = LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (ret == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(ret)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(ret), "信息查询失败！\n请检查网络连接后重试！");
            return ret;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = document.object();
                if (m_isLogData){
                    qInfo()<<QString("post Boarding <%1%2> response: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<ret_json;
                                    }
                if(ret_json.contains("reqId")){
                    QString reqId=ret_json["reqId"].toString();
                    if (ret == 0 && reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return -1;
                    }
                }
                QString msg = "";
                if(ret_json.contains("msg")){
                    msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    int serverStatus=ret_json["status"].toInt();
                    if (serverStatus == 0) outObject = ret_json;
                    else emit networkStat(true);
                }
            }
        }
        return ret;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return ret;
    }
}

int HttpAPI::enquiryPPL(const QString& cardId, QJsonObject& outObject, bool isBaby)
{
    int ret = -1;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId",m_reqId);
        json.insert("cardId",cardId);
//        json.insert("flightNo","");
//        json.insert("boardingNumber","");
        json.insert("isFuzzyQuery", 0);//目前不支持模糊查询
        if (isBaby) json.insert("seatId", "INF");
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post Boarding <%1%2> send body]: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = queryPPL_Addr.toLatin1();
        QByteArray byte_api = queryPPL_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != ret && tmp_post_times++ < maxPostFailTimes) {
            ret=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (ret == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(ret)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(ret), "信息查询失败！\n请检查网络连接后重试！");
            return ret;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = document.object();
                if (m_isLogData){
                    qInfo()<<QString("post Boarding <%1%2> response: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    QString reqId=ret_json["reqId"].toString();
                    if (ret == 0 && reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return -1;
                    }
                }
                QString msg = "";
                if(ret_json.contains("msg")){
                    msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    int serverStatus=ret_json["status"].toInt();
                    if (serverStatus == 0) outObject = ret_json;
                    else emit networkStat(true);
                }
            }
        }
        return ret;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return ret;
    }
}

FlowReviewResponse HttpAPI::enquiryPPL(const FlowReviewRequest& request)
{
    FlowReviewResponse result;

    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId", m_reqId);
        // isFuzzyQuery的填写规则是,如果是通过身份证查询则填0,通过机票加航班号查询时,手动输入填1,刷票输入填0
        // flightDay的填写规则是,如果用扫码枪扫入,则将机票年月日的日填入,如果手动输入则为-1,查询历史所有
        if (request.input.contains("#", Qt::CaseSensitive)) {
            json.insert("cardId", "");
            json.insert("flightNo", request.input.section("#", 0, 0));
            json.insert("boardingNumber", request.input.section("#", 1, 1));
            json.insert("isFuzzyQuery", 1);
        } else {
            json.insert("cardId", request.input);
            json.insert("flightNo", "");
            json.insert("boardingNumber", "");
            json.insert("isFuzzyQuery", 0);
        }
        json.insert("flightDay", "-1");
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post ProcessRecording <%1%2> send body]: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<json;
        }

        char *response = nullptr;
        int resLen = 0;
        int res = -1;

        int tmp_post_times = 0;
        while (0 != res && tmp_post_times++ < maxPostFailTimes) {
            res = LIBPostSynEx(queryPPL_Addr.toLatin1().data(), queryPPL_API.toLatin1().data(), bytes.data(), &response, &resLen, true);
        }
        result.errorCode = res;
        if (res == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(res)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(res), "信息查询失败！\n请检查网络连接后重试！");
            return result;
        }

        QByteArray array = QByteArray(response, resLen);

        if(array != nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(array, &jsonParseError);
            if (m_isLogData){
                qInfo()<<QString("post ProcessRecording <%1%2> response: \n").arg(queryPPL_Addr).arg(queryPPL_API)<<document;
            }
            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                result.update(document);

                QJsonObject json1 = document.object();
                QString msg;
                if(json1.contains("reqId")){
                    QString reqId=json1["reqId"].toString();
                    if (result.errorCode == 0 && reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(json1.contains("msg")){
                    QString msg=json1["msg"].toString();
                }
                if(json1.contains("status")){
                    result.errorCode=json1["status"].toInt();
                    if (result.errorCode != 0){
                        emit networkStat(true, "人员回查", "没有该旅客的信息");
                    }
                }
            }
        }

        return result;
    } catch (std::exception &ex) {
        qCritical() << ex.what();

        return result;
    }
}

Return_MSG HttpAPI::Post(PostUrlType type, const QString& flightNo, const QString& boardingGate, const QString& flightDay)
{
    Return_MSG result;
    try {
        QJsonObject json;
        QByteArray bytes;

        json.insert("reqId", m_reqId);
        json.insert("gateNo", LocalSettings::instance()->value("Device/gateNo").toString());
        json.insert("deviceCode", LocalSettings::instance()->value("Device/deviceCode").toString());
        json.insert("flightNo", flightNo);
        json.insert("boardingGate", boardingGate);
        json.insert("flightDay", flightDay);
        bytes.append(QJsonDocument(json).toJson());

        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr;
        QByteArray byte_api;
        QString tmpStr;
        switch (type) {
        case Start_Boarding_Clicked:
            byte_addr = startBording_Addr.toLatin1();
            byte_api = startBording_API.toLatin1();
            tmpStr = "开始登机失败！";
            break;
        case End_Boarding_Clicked:
            byte_addr = endBording_Addr.toLatin1();
            byte_api = endBording_API.toLatin1();
            tmpStr = "结束登机失败！";
            break;
        case Other_Flight_Clicked:
            byte_addr = otherFlight_Addr.toLatin1();
            byte_api = otherFlight_API.toLatin1();
            tmpStr = "新增航班失败！";
            break;
        case Exception_Flight_Clicked:
            byte_addr = exceptionFlight_Addr.toLatin1();
            byte_api = exceptionFlight_API.toLatin1();
            tmpStr = "异常航班激活失败！";
            break;
        case Cancel_Flight_Clicked:
            byte_addr = cancelFlight_Addr.toLatin1();
            byte_api = cancelFlight_API.toLatin1();
            tmpStr = "撤销航班失败！";
            break;
        }
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(QString(byte_addr)).arg(QString(byte_api))<<json;
        }
        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), QString("%1\n请检查网络连接后重试！").arg(tmpStr));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(QString(byte_addr)).arg(QString(byte_api))<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true/*, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("%1").arg(tmpStr)*/);
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

Return_MSG HttpAPI::interceptOrCancel(QString flightNo, QString id, QString date, int isInterceptLabel)
{
    Return_MSG result;
    try {
        QJsonObject json;
        QByteArray bytes;

        json.insert("reqId", m_reqId);
        json.insert("flightNo", flightNo);
        json.insert("gateNo", LocalSettings::instance()->value("Device/gateNo").toString());
        json.insert("boardingGate", LocalSettings::instance()->value("Device/boardingGateNo").toString());
        json.insert("deviceCode", LocalSettings::instance()->value("Device/deviceCode").toString());
        json.insert("id", id);
        json.insert("date", date);
        bytes.append(QJsonDocument(json).toJson());

        char* body = bytes.data();
        char* response = nullptr;
        int resLen = 0;
        QByteArray byte_addr = LocalSettings::instance()->value("Server/intercept_Addr").toString().toLatin1();
        QByteArray byte_api = (isInterceptLabel == 0) ? "/api/v1/face/boarding/lib-label" : "/api/v1/face/boarding/lib-labelcancel";

        if (m_isLogData) {
            qInfo() << QString("[post <%1%2> send body]: \n").arg(QString(byte_addr)).arg(QString(byte_api)) << json;
        }
        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), QString("%1\n请检查网络连接后重试！").arg("底库拦截标记接口"));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(QString(byte_addr)).arg(QString(byte_api))<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true/*, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("%1").arg(tmpStr)*/);
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical() << ex.what();
        return  result;
    }
}

Return_MSG HttpAPI::GateCtrl(const int gateChannelNO, gateWorkStatus workStat, gateDoorStatus doorStat)
{
    Return_MSG result;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId", m_reqId);
        json.insert("gateDoorStatus", static_cast<int>(doorStat));
        json.insert("gateWorkStatus", static_cast<int>(workStat));
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(gate_ctrl_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = GateChannel_Addr[gateChannelNO-1].toLatin1();
        QByteArray byte_api = gate_ctrl_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), QString("向通道%1发送指令失败！\n请检查网络连接后重试！").arg(gateChannelNO));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(gate_ctrl_API)<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("向通道%1发送指令失败，请重试！").arg(gateChannelNO));
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

Return_MSG HttpAPI::BoardingMode_ManualPass(const int gateChannelNO, BoardingMode_ManualPass_Send &content)
{
    Return_MSG result;
    try {
        QByteArray bytes;
        QJsonObject json;
        json.insert("deviceCode",LocalSettings::instance()->value("Device/deviceCode").toString());
        json.insert("gateNo",LocalSettings::instance()->value("Device/gateNo").toString());
        json.insert("reqId",m_reqId);
        json.insert("boardingGate",content.boardingGate);
        json.insert("cardId",content.cardId);
        json.insert("date",content.date);
        json.insert("flightNo",content.flightNo);
        json.insert("scenePhoto", content.scenePhoto.toBase64().data());
        json.insert("sourceType",content.sourceType);
        json.insert("passengerName",content.passengerName);
        json.insert("boardingNumber",content.boardingNumber);
        json.insert("seatId",content.seatId);
        json.insert("startPort",content.startPort);
        json.insert("endPort",content.startPort);
        json.insert("isFocus",content.isFocus);
        json.insert("hasBaby",content.hasBaby);
        json.insert("moreTicket",content.moreTicket);
        json.insert("isSpecialChannel",content.isSpecialChannel);
        json.insert("secondBoardingPass",content.secondBoardingPass);
        json.insert("controlType",content.controlType);
        json.insert("transferSourceType",content.transferSourceType);
        json.insert("hasSecurityInfo",content.hasSecurityInfo);
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(boardingMode_manualCtrl_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = GateChannel_Addr[gateChannelNO-1].toLatin1();
        QByteArray byte_api = boardingMode_manualCtrl_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), QString("向通道%1发送指令失败！\n请检查网络连接后重试！").arg(gateChannelNO));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(boardingMode_manualCtrl_API)<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("向通道%1发送指令失败，请重试！").arg(gateChannelNO));
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

Return_MSG HttpAPI::CollectingMode_ManualPass(const int gateChannelNO, Collect_Info &content, int collectType)
{
    Return_MSG result;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId", m_reqId);
        json.insert("flightNo",content.flightNo);
        json.insert("flightDay",content.flightDay);
        json.insert("boardingNumber",content.boardingNumber);
        json.insert("seatId",content.seatId);
        json.insert("startPort",content.startPort);
        json.insert("endPort",content.endPort);
        json.insert("cardId",content.cardId);
        json.insert("nameZh",content.nameZh);
        json.insert("cardPhoto",content.cardPhoto.toBase64().data());
        json.insert("faceImage",content.faceImage.toBase64().data());
        json.insert("largePhoto",content.largePhoto.toBase64().data());
        json.insert("sourceType",content.sourceType);
        json.insert("mainFlightNo",content.mainFlightNo);
        json.insert("isBaby",content.isBaby);
        json.insert("babyFlightNo",content.babyFlightNo);
        json.insert("babyFlightDay",content.babyFlightDay);
        json.insert("babyBoardingNumber",content.babyBoardingNumber);
        json.insert("babySeatId",content.babySeatId);
        json.insert("babyStartPort",content.babyStartPort);
        json.insert("babyEndPort",content.babyEndPort);
        json.insert("babyCardId",content.babyCardId);
        json.insert("babyNameZh",content.babyNameZh);
        json.insert("babySourceType",content.babySourceType);
        json.insert("collectType",collectType);
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1> send body]: \n").arg(collectingMode_manualCtrl_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = GateChannel_Addr[gateChannelNO-1].toLatin1();
        QByteArray byte_api = collectingMode_manualCtrl_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code), QString("向通道%1发送指令失败！\n请检查网络连接后重试！").arg(gateChannelNO));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(collectingMode_manualCtrl_API)<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
                        emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("发送通道%1发送指令失败，请重试！").arg(gateChannelNO));
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}

Return_MSG HttpAPI::pushPlan(const int gateChannelNO, FlightPlan& plan, int mode, int face_fastType, int collectType, int status)
{
    Return_MSG result;
    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId",m_reqId);
        json.insert("boardingGate",plan.boardingGate);
        json.insert("threeFlightNo",plan.threeFlightNo);
        json.insert("twoFlightNo",plan.twoFlightNo);
        json.insert("depTimeJ",plan.depTimeJ);
        json.insert("depTimeS",plan.depTimeS);
        json.insert("boardingTime",plan.boardingTime);
        json.insert("flightDate",plan.flightDate);
        json.insert("midwayCode",plan.midwayCode);
        json.insert("midwayName",plan.midwayName);
        json.insert("arrAirportCode",plan.arrAirportCode);
        json.insert("arrAirportName",plan.arrAirportName);
        json.insert("depAirportCode",plan.depAirportCode);
        json.insert("depAirportName",plan.depAirportName);
        json.insert("shareFltno",plan.shareFltno.join(","));
        json.insert("faceNums",plan.faceNums);
        json.insert("orgDepNum",plan.orgDepNum);
        json.insert("transferNum",plan.transferNum);
        json.insert("midwayNum",plan.midwayNum);
        json.insert("boardingNum",plan.boardingNum);
        json.insert("mode",mode);
        json.insert("type",face_fastType);
        json.insert("collectType",collectType);
        json.insert("status",status);
        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(pushPlan_API)<<json;
        }
        char* body=bytes.data();
        char* response = nullptr;
        int resLen=0;
        QByteArray byte_addr = GateChannel_Addr[gateChannelNO-1].toLatin1();
        QByteArray byte_api = pushPlan_API.toLatin1();

        int tmp_post_times = 0;
        while (0 != result.curl_err_code && tmp_post_times++ < maxPostFailTimes) {
            result.curl_err_code=LIBPostSynEx(byte_addr.data(),byte_api.data(),body,&response,&resLen,true);
        }
        if (result.curl_err_code == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(result.curl_err_code)<<QThread::currentThread();
//            emit networkStat(false, QString("网络状态异常(%1)").arg(result.curl_err_code),QString("向闸机通道%1推送计划失败！\n请检查网络连接！").arg(gateChannelNO));
            emit pushPlanStat(gateChannelNO, false, QString("网络状态异常(%1)").arg(result.curl_err_code),QString("向闸机通道%1推送计划失败！\n请检查网络连接！").arg(gateChannelNO));
            return result;
        }

        QByteArray ret_data=QByteArray(response,resLen);

        if(ret_data!=nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument ret_document = QJsonDocument::fromJson(ret_data, &jsonParseError);

            if(!ret_document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                QJsonObject ret_json = ret_document.object();

                if (m_isLogData){
                    qInfo()<<QString("post <%1%2> response: \n").arg(GateChannel_Addr[gateChannelNO-1]).arg(pushPlan_API)<<ret_json;
                }
                if(ret_json.contains("reqId")){
                    result.reqId=ret_json["reqId"].toString();
                    if (result.curl_err_code == 0 && result.reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(ret_json.contains("msg")){
                    result.msg=ret_json["msg"].toString();
                }
                if(ret_json.contains("status")){
                    result.serverStatus=ret_json["status"].toInt();
                    if (result.serverStatus != 0){
//                        emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("向闸机通道%1推送计划失败！").arg(gateChannelNO));
                        emit pushPlanStat(gateChannelNO, true, QString("%1(%2)").arg(result.msg).arg(result.serverStatus), QString("向闸机通道%1推送计划失败！").arg(gateChannelNO));
                    }
                }
            }
        }
        return result;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return result;
    }
}


FlightReviewResponse HttpAPI::get_ppl_in_flight(const FlightReviewRequest& request)
{
    FlightReviewResponse result;
    result.queryType = request.queryType;

    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId", m_reqId);
        json.insert("flightNo", request.input);
        json.insert("date", request.flightDtae);
        json.insert("queryType", request.queryType);
        json.insert("pageNum", 1);
        json.insert("pageSize", 1000);
        json.insert("isCount", 1);
        json.insert("gateNo", LocalSettings::instance()->value("Device/gateNo").toString());
        json.insert("boardingGate", LocalSettings::instance()->value("Device/boardingGateNo").toString());
        if (m_isLogData){
            qInfo()<<QString("[post <%1%2> send body]: \n").arg(flightReviewServer_Addr).arg(flightReview_API)<<json;
        }
        bytes.append(QJsonDocument(json).toJson());

        char *response = nullptr;
        int resLen = 0;
        int res = -1;

        int tmp_post_times = 0;
        while (0 != res && tmp_post_times++ < maxPostFailTimes) {
            res = LIBPostSynEx(flightReviewServer_Addr.toLatin1().data(), flightReview_API.toLatin1().data(), bytes.data(), &response, &resLen, true);
        }
        result.errorCode = res;
        if (res == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(res)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(res), "人员信息查询失败！\n请检查网络连接后重试！");
            return result;
        }

        QByteArray array = QByteArray(response, resLen);

        if(array != nullptr)
        {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(array, &jsonParseError);
            if (m_isLogData){
                qInfo()<<QString("post <%1%2> response: \n").arg(flightReviewServer_Addr).arg(flightReview_API)<<document;
            }
            if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
            {
                result.update(document);

                QJsonObject json1 = document.object();
                QString msg;
                if(json1.contains("reqId")){
                    QString reqId=json1["reqId"].toString();
                    if (result.errorCode == 0 && reqId != m_reqId){
                        qCritical()<<"【Warning】：http returned <reqId> was not yourself !";
                        return result;
                    }
                }
                if(json1.contains("msg")){
                    QString msg=json1["msg"].toString();
                }
                if(json1.contains("status")){
                    result.errorCode=json1["status"].toInt();
                    if (result.errorCode != 0){
                        emit networkStat(true, QString("%1(%2)").arg(msg).arg(result.errorCode) ,"查询不到该航班的人员信息！");
                    }
                }
            }
        }

        return result;
    } catch (std::exception &ex) {
        qCritical() << ex.what();

        return result;
    }
}

LibDeleteResponse HttpAPI::removeSpecific(const LibDeleteRequest& request)
{
    LibDeleteResponse result;

    try {
        QByteArray bytes;
        QJsonObject json;

        json.insert("reqId", m_reqId);
        json.insert("flightNo", request.flightNo);
        json.insert("date", request.flightDate);
        json.insert("gateNo", LocalSettings::instance()->value("Device/gateNo").toString());
        json.insert("boardingGate", LocalSettings::instance()->value("Device/boardingGateNo").toString());
        json.insert("deviceCode", LocalSettings::instance()->value("Device/deviceCode").toString());
        json.insert("id", request.id);

        bytes.append(QJsonDocument(json).toJson());
        if (m_isLogData){
            qInfo()<<QString("[LibDeleteRequest post <%1%2> send body]: \n").arg(flightReviewServer_Addr).arg(libDeleteFlight_API)<<json;
        }
        char *response = nullptr;
        int resLen = 0;
        int res = -1;

        int tmp_post_times = 0;
        while (0 != res && tmp_post_times++ < maxPostFailTimes) {
            res = LIBPostSynEx(flightReviewServer_Addr.toLatin1().data(), libDeleteFlight_API.toLatin1().data(), bytes.data(), &response, &resLen, true);
        }
        if (res == 0 && resLen != 0){
            emit networkStat(true);
        }
        else {
            qCritical()<<QString("LIBPostSynEx failed, res:%1").arg(res)<<QThread::currentThread();
            emit networkStat(false, QString("网络状态异常(%1)").arg(res), "删除失败！\n请检查网络连接后重试！");
            return result;
        }

        QByteArray array = QByteArray(response, resLen);

        if (array != nullptr) {
            QJsonParseError jsonParseError;
            QJsonDocument document = QJsonDocument::fromJson(array, &jsonParseError);

            if (m_isLogData){
                qInfo()<<QString("LibDeleteRequest post <%1%2> response: \n").arg(flightReviewServer_Addr).arg(libDeleteFlight_API)<<document;
            }
            if (!document.isNull() && jsonParseError.error == QJsonParseError::NoError) {
                result.reqId = document.object().value("reqId").toString();
                result.status = document.object().value("status").toInt();
                result.msg = document.object().value("msg").toString();

                if (result.status != 0){
                    emit networkStat(true, QString("%1(%2)").arg(result.msg).arg(result.status) ,"删除失败！");
                }
            }
        }

        return  result;
    } catch (std::exception &e) {
        qCritical() << e.what();

        return result;
    }
}

