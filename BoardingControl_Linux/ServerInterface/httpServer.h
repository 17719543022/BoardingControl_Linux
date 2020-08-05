#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "HTTPServerExp.h"
#include "ticketScancer/paramdef.h"
#include "json/json.h"
#include <QObject>
#include<QJsonObject>

#define STAT_SUCCEES 0
#define PARAME_ERROR 417
#define SEND_DEPARTURE_INFO_FAILED 500

class HttpServer : public QObject, public RequstListener
{
    Q_OBJECT
public:
    static inline HttpServer *instance(){
        static HttpServer singleton;
        return &singleton;
    }
    ~HttpServer();

private:
    explicit HttpServer(QObject* parent = nullptr);

    bool parse(const std::string &str, Json::Value& value);
    bool parse(const QString &str, QJsonObject& value);

    //fllow funcs are not used;
    void manualBoarding(const std::string& strRequstBody, std::string& strResponse);

    void pullPlan(const std::string& strRequstBody, std::string& strResponse);

    void boardingResult(const std::string& strRequstBody, std::string& strResponse);

    void collectResult(const std::string& strRequstBody, std::string& strResponse);

    int boardingResultPares(QJsonObject json);

signals:
    void GateNetStat(const QString title = "", const QString msg = "");
    void recheckInfo(QJsonObject json); //实时登机模块接收的用户信息
    void collectInfo(int channel, QJsonObject json); //采集模块接收的用户信息
    void sendDepartureInfo(BoardingTicketInfo ticketInfo);
    void showBoardingResult(int channel, bool isManualOperation, int result, int transferType, bool hasSecurityInfo
                            , int seatLabel, bool hasBaby, bool moreTicket, bool isMarked
                            , const QString name, const QString cardId, const BoardingTicketInfo ticketinfo, const QByteArray faceImage);

    //如果正处于航班回查界面时，有人成功登机时，要更新已登机人数
    void boardingInfo_to_updateBoardingNum(QString flightNo, QString FlightDay, QByteArray faceImg, int recheckType, QJsonObject userInfo, QJsonObject manualInfo);

private:
    std::string pullPlan_API = "/api/v1/face/boarding/pull-plan";
    std::string recheckResult_API = "/api/v1/face/boarding/recheck-result";
    std::string collectResult_API = "/api/v1/face/boarding/collect-result";

private:

    /* 功能：用于回调HTTP multipart/form-data请求；
    ** 参数：uri, 请求uri
    **      mapDataInfo，从请求Json解析出的键值对；
    **	    strResponse，该请求的Response;
    ** 返回值：无
    ** 说明：无
    */
    void MultipartRequstListen(const std::string& uri, const std::map<std::string, DataInfo>& mapDataInfo, std::string& strResponse);

    /* 功能：用于回调HTTP其他Content-Type的请求
    ** 参数：uri, 请求uri
    **      strRequstBody，HTTP请求内容
    **		strResponse，该请求的Response;
    ** 返回值：无
    ** 说明:无
    */
    void CommonRequstListen(const std::string& url, const std::string& strRequstBody, std::string& strResponse);
};



#endif // HTTPSERVER_H
