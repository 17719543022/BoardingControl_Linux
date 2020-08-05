#include "settings.h"
#include "homepage.h"
#include "ServerInterface/httpServer.h"
#include "ticketScancer/serialportser.h"
#include "libHTTP.h"

#include <iostream>
#include <fstream>
#include <memory>
#include <string.h>
#include <QtGlobal>
#include <QJsonDocument>
#include <QTimer>
#include <QDebug>

HttpServer::HttpServer(QObject* parent)
    :QObject (parent)
{
}

HttpServer::~HttpServer()
{
}

void HttpServer::MultipartRequstListen(const std::string& uri, const std::map<std::string, DataInfo>& mapDataInfo, std::string& strResponse)
{
    Q_UNUSED(uri)
    Q_UNUSED(mapDataInfo)

    strResponse = std::string("nonsupport Content-Type(multipart/form-data) request, please use another Content-Type");
//    auto it = mapDataInfo.begin();
//    for(; it != mapDataInfo.end(); it++)
//    {
//        strResponse += it->first + " = " + std::string(it->second.szBuf) + "\n";
//    }
}

void HttpServer::CommonRequstListen(const std::string& url, const std::string& strRequstBody, std::string& strResponse)
{
    size_t pos = url.find_first_of("/api/");
    std::string api = url.substr(pos);

    if (LocalSettings::instance()->value("Debug/isLogData", false).toBool())
        qInfo() << "HttpService[" << QString::fromStdString(url) << "]requstBody: " << QJsonDocument::fromJson(QByteArray(strRequstBody.data(), int(strRequstBody.size())));

    if(0 == api.compare(pullPlan_API)){
        pullPlan(strRequstBody, strResponse);
    }
    else if(0 == api.compare(recheckResult_API)){
        boardingResult(strRequstBody, strResponse);
    }
    else if (0 == api.compare(collectResult_API)){
         collectResult(strRequstBody, strResponse);
    }
    else{
        strResponse = "parame [api] error!";
        std::string log_url(url);
        log_url.insert(0,"Warning: the URL(");
        log_url.append(") is unkown customer: ");
        log_url.append(strRequstBody);
        qWarning() << QString::fromStdString(log_url);
    }

    if (LocalSettings::instance()->value("Debug/isLogData",false).toBool()){
       qInfo() << "HttpService[" << QString::fromStdString(url) << "]response: " << QJsonDocument::fromJson(QByteArray(strResponse.data(), int(strResponse.size())));
    }
//    //log
//    std::ofstream fstr("./../log/request.log", std::ofstream::out | std::ofstream::binary);
//    fstr.write(strRequstBody.c_str(), static_cast<int>(strRequstBody.length()));
//    fstr.close();
}

bool HttpServer::parse(const std::string& str, Json::Value& value){
    std::string errs;
    Json::CharReaderBuilder readerBuilder;
    std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader());

    return jsonReader->parse(str.c_str(), str.c_str() + str.length(), &value, &errs);
}

bool HttpServer::parse(const QString &str, QJsonObject& value){
    QJsonParseError jsonParseError;
    QJsonDocument document = QJsonDocument::fromJson(str.toUtf8(), &jsonParseError);

    if(!document.isNull() && jsonParseError.error == QJsonParseError::NoError)
    {
        value = document.object();
        return true;
    }
    else return false;
}

void HttpServer::pullPlan(const std::string& strRequstBody, std::string& strResponse)
{
    Json::Value value;
    Json::Value response;

    if (!parse(strRequstBody, value)) return;

    std::string reqId = value["reqId"].asString();
    std::string boardingGateNo = value["boardingGate"].asString();
    std::string local_boardingGateNo = LocalSettings::instance()->value("Device/boardingGateNo").toString().toStdString();
    if (boardingGateNo != local_boardingGateNo){
        response["reqId"] = reqId;
        response["status"] = PARAME_ERROR;
        response["msg"] = "parame [boardingGateNo] error!";
    }
    else{
        HomePage* homePage = HomePage::global_instance;
        Q_ASSERT(homePage);
        FlightPlan* flightPlan = nullptr;
        if (HomePage::s_mode == 0){
            flightPlan = homePage->m_RealtimeBoarding->getFlightPlan();
        }
        else if (HomePage::s_mode == 1){
            flightPlan = homePage->m_PortraitCollection->getFlightPlan();
        }

        Json::Value content;
        content["boardingGate"]=flightPlan->boardingGate.toStdString();
        content["threeFlightNo"]=flightPlan->threeFlightNo.toStdString();
        content["twoFlightNo"]=flightPlan->twoFlightNo.toStdString();
        content["depTimeJ"]=flightPlan->depTimeJ.toStdString();
        content["depTimeS"]=flightPlan->depTimeS.toStdString();
        content["boardingTime"] = flightPlan->boardingTime.toStdString();
        content["flightDate"]=flightPlan->flightDate.toStdString();
        content["midwayCode"]=flightPlan->midwayCode.toStdString();
        content["midwayName"]=flightPlan->midwayName.toStdString();
        content["arrAirportCode"]=flightPlan->arrAirportCode.toStdString();
        content["arrAirportName"]=flightPlan->arrAirportName.toStdString();
        content["depAirportCode"]=flightPlan->depAirportCode.toStdString();
        content["depAirportName"]=flightPlan->depAirportName.toStdString();
        content["shareFltno"]=flightPlan->shareFltno.join(",").toStdString();
        content["faceNums"]=flightPlan->faceNums;
        content["orgDepNum"]=flightPlan->orgDepNum;
        content["transferNum"]=flightPlan->transferNum;
        content["midwayNum"]=flightPlan->midwayNum;
        content["boardingNum"]=flightPlan->boardingNum;
        content["mode"]=HomePage::s_mode;
        content["type"]=HomePage::s_type;
        content["collectType"]=HomePage::s_collectType;
        content["status"]=HomePage::s_status;

        response["reqId"] = reqId;
        response["status"] = STAT_SUCCEES;
        response["msg"] = "success";
        response["content"] = content;
    }

    strResponse = response.toStyledString();
}

void HttpServer::boardingResult(const std::string& strRequstBody, std::string& strResponse)
{
    QString body = QString::fromStdString(strRequstBody);
    QJsonObject json;

    if (!parse(body,json)) return;

    QJsonObject response;
    QString local_boardingGateNo = LocalSettings::instance()->value("Device/boardingGateNo").toString();

    response.insert("reqId",json["reqId"]);
    if (json["boardingGate"].toString() != local_boardingGateNo){
        response.insert("status", PARAME_ERROR);
        response.insert("msg","parame [boardingGate] error");
    }
    else{
        int nRet = boardingResultPares(json);
        if (nRet == STAT_SUCCEES){
            response.insert("status",STAT_SUCCEES);
            response.insert("msg","success");
        }
        else {
            response.insert("status",nRet);
            response.insert("msg","failed!");
        }
    }
    QByteArray tmpBA= QJsonDocument(response).toJson();
    strResponse = tmpBA.data();
}

void HttpServer::collectResult(const std::string& strRequstBody, std::string& strResponse)
{
    QString body = QString::fromStdString(strRequstBody);
    QJsonObject json;

    if (!parse(body,json)) return;

    QJsonObject response;
    QString local_boardingGateNo = LocalSettings::instance()->value("Device/boardingGateNo").toString();

    response.insert("reqId",json["reqId"]);
    if (json["boardingGate"].toString() != local_boardingGateNo){
        response.insert("status", PARAME_ERROR);
        response.insert("msg","parame [boardingGate] error");
    }
    else{
        int channel = 0;
        QString local_deviceCide_1 = LocalSettings::instance()->value("GateChannel_1/deviceCode").toString();
        QString local_deviceCide_2 = LocalSettings::instance()->value("GateChannel_2/deviceCode").toString();

        if (json["deviceCode"].toString() == local_deviceCide_1)
            channel = 1;
        else if (json["deviceCode"].toString() == local_deviceCide_2)
            channel = 2;
        else {
            qWarning()<<QString("recieved [deviceCode]:%1, there are not found in local settings ! [local_deviceCide_1 = %2] [local_deviceCide_2 = %3]").arg(json["deviceCode"].toString()).arg(local_deviceCide_1).arg(local_deviceCide_2);
            response.insert("status", PARAME_ERROR);
            response.insert("msg","parame [deviceCode] error");
            QByteArray tmpBA= QJsonDocument(response).toJson();
            strResponse = tmpBA.data();
            return;
        }

        emit collectInfo(channel, json);

        response.insert("status",STAT_SUCCEES);
        response.insert("msg","success");
    }

    QByteArray tmpBA= QJsonDocument(response).toJson();
    strResponse = tmpBA.data();
}

int HttpServer::boardingResultPares(QJsonObject json)
{
    //做数据校验和反馈
    if (json["netStatus"].toInt() == 0){ //闸机和服务器的网络状态; 0-故障，1-OK;
        emit GateNetStat("识别失败", "闸机与服务器网络通信异常！");
        return STAT_SUCCEES;
    }

    int channel = 0;
    QString local_deviceCide_1 = LocalSettings::instance()->value("GateChannel_1/deviceCode").toString();
    QString local_deviceCide_2 = LocalSettings::instance()->value("GateChannel_2/deviceCode").toString();
    if (json["deviceCode"].toString() == local_deviceCide_1)
        channel = 1;
    else if (json["deviceCode"].toString() == local_deviceCide_2)
        channel = 2;
    else {
        qWarning()<<QString("recieved [deviceCode]:%1, there are not found in local settings ! [local_deviceCide_1 = %2] [local_deviceCide_2 = %3]").arg(json["deviceCode"].toString().arg(local_deviceCide_1).arg(local_deviceCide_2));
        return PARAME_ERROR;
    }

    //解析所需要字段;
    int recognizeType = -1; // -1 不通过, 0-正常旅客，1-保留，2-可疑人员,显示复核异常，3-流程缺失,显示未过安检，4-二次登机
    bool isManualOperation = false; //是否人工操作
    bool isVipChannel = false;  //是否vip通道, not used
    bool hasBaby = false;       //是否携带婴儿  1-携带，0-未携带
    bool moreTicket = false;    //本航班是否购买多张票，1-多张票，0-单张票
    bool isMarked = false; //是否人工标记拦截，1-已标记，0-未标记
    int seatLabel = 0;      //0-正常；1-有更改座位号；2-无座位号
    int transferType = -1;  //-1，没有中转经停信息, 0-中转；1-经停
    bool hasSecurityInfo = false;

    QString name = json.value("nameZh").toString();
    QString cardId = json.value("cardId").toString();
    QByteArray faceImage = QByteArray::fromBase64(json["faceImage"].toVariant().toByteArray());
    BoardingTicketInfo ticketInfo;
    ticketInfo.flightNo = json.value("flightNo").toString();
    ticketInfo.flightDay = json.value("flightDay").toString().right(2);
    ticketInfo.boardingNumber = json.value("boardingNumber").toString();
    ticketInfo.seatId = json.value("seatId").toString();

    //0-人脸模式下人脸识别验证类型；1-人脸模式下人工验证类型；2-刷票模式下自助验证类型；3-刷票模式下人工验证类型
    if (0 == json["recheckType"].toInt() || 2 == json["recheckType"].toInt()){
        isManualOperation = false;

        if (json["userInfo"].isObject()){
            QJsonObject userInfo = json["userInfo"].toObject();
            ticketInfo.startPort = userInfo.value("startPort").toString("");
            ticketInfo.endPort = userInfo.value("endPort").toString("");
            recognizeType = userInfo.value("recognizeType").toInt(-1);
            isVipChannel = userInfo.value("isVipChannel").toInt(0) == 1 ? true : false;
            hasBaby = userInfo.value("isCarryBaby").toInt(0);
            moreTicket = userInfo.value("isMultiTicket").toInt(0);
            isMarked = userInfo.value("isInterceptLabel").toInt(0);
            seatLabel = userInfo.value("seatLabel").toInt(-1);
            QJsonObject transferInfo = userInfo["transferInfo"].toObject();
            QString flightNo_transfer = transferInfo["flightNo"].toString();
            if (flightNo_transfer == HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
                    || HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_transfer)){
                transferType = transferInfo["sourceType"].toInt(-1);
            }
            hasSecurityInfo = !userInfo["securityInfo"].isNull() && !userInfo["securityInfo"].isUndefined()
                                && !userInfo["reviewInfo"].isNull() && !userInfo["reviewInfo"].isUndefined();
        }
    }
    else/* if (1 == json["recheckType"].toInt() || 3 == json["recheckType"].toInt())*/{
        isManualOperation  = true;
        recognizeType = 0; //人工放行全部视为通过,后续根据"result"字段(放行或拦截)来判断

        if (json["manualInfo"].isObject()){
            QJsonObject manualInfo = json["manualInfo"].toObject();
            ticketInfo.startPort = manualInfo.value("startPort").toString("");
            ticketInfo.endPort = manualInfo.value("endPort").toString("");
            isVipChannel = manualInfo.value("isSpecialChannel").toInt(0);
            hasBaby = manualInfo.value("hasBaby").toInt(0);
            moreTicket = manualInfo.value("moreTicket").toInt(0);
            isMarked = manualInfo.value("isInterceptLabel").toInt(0);
            seatLabel = manualInfo.value("seatLabel").toInt(0);
            transferType = manualInfo["transferSourceType"].toInt(-1);
            hasSecurityInfo =  manualInfo["hasSecurityInfo"].toInt(0);
        }
    }

    // 判断结果并处理
    if (json["result"].toInt(-1) == 1){ // json["result"]:0-识别成功/人工放行，1-识别失败/人工拦截
            recognizeType = -1;
        }
    else if (json["result"].toInt(-1) == 0){
        if(recognizeType == 0){
            if ((isManualOperation && json["manualInfo"].toObject().value("secondBoardingPass").toInt(0) != 1)  //人工,不是二次登机
                 || (!isManualOperation && !isMarked && seatLabel == 0 && !hasBaby && !moreTicket)) //不是人工操作的,没有座位缺失，携带婴儿，多张票等警告信息
            {
                //传输离港信息;
                QEventLoop pause;
                QTimer delay;
                connect(&delay, &QTimer::timeout, &pause, &QEventLoop::quit);
                connect(SerialPortSer::instance(DepartureInfoSender), &SerialPortSer::sendDepartureInfoResult, &pause, &QEventLoop::quit);
                emit sendDepartureInfo(ticketInfo);
                delay.start(MSEC_EVENTLOOP_TIMEOUT);
                pause.exec();

                if (SerialPortSer::instance(DepartureInfoSender)->is_sendDepartureOk()){
                    //emit to "flightEnquires.cpp", which needing update already on board ppl count;
                    emit boardingInfo_to_updateBoardingNum(ticketInfo.flightNo, ticketInfo.flightDay, faceImage
                                                           , json["recheckType"].toInt(), json["userInfo"].toObject(), json["manualInfo"].toObject());
                }
                else { //离港信息传输失败
                    return SEND_DEPARTURE_INFO_FAILED;
                }
            }
        }
    }
    else { //unkown result
        return PARAME_ERROR;
    }

    emit showBoardingResult(channel, isManualOperation, recognizeType, transferType, hasSecurityInfo
                            , seatLabel, hasBaby, moreTicket, isMarked
                            , name, cardId, ticketInfo, faceImage);

    return STAT_SUCCEES;
}


//unused
void HttpServer::manualBoarding(const std::string& strRequstBody, std::string& strResponse){

    strResponse = "unused";

    Json::Value value;

    if (!parse(strRequstBody, value)) return;
    if (value["faceInfos"].isArray())
    {
        int outLen;
        Json::Value arry = value["faceInfos"];

        for(int i = 0; i < static_cast<int>(arry.size()); i++)
        {
            Json::Value faceInfo = arry[i];
            std::string userInfo = faceInfo["userInfo"].asString();

            outLen = 0;
            std::string faceImg = faceInfo["faceImg"].asString();
            char* jpegImg = new char[faceImg.length()];
            LIBBase64Decode(faceImg.c_str(), &jpegImg, &outLen);
            std::ofstream fstr(userInfo + "1.jpeg", std::ofstream::out | std::ofstream::binary);
            fstr.write(jpegImg, outLen);
            fstr.close();

            outLen = 0;
            std::string registImg = faceInfo["registImg"].asString();
            LIBBase64Decode(registImg.c_str(), &jpegImg, &outLen);

            fstr.open(userInfo + "2.jpeg", std::ofstream::out | std::ofstream::binary);
            fstr.write(jpegImg, outLen);
            fstr.close();
            delete[] jpegImg;
            jpegImg = nullptr;
        }
    }
}


