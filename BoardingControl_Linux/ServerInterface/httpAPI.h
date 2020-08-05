#ifndef HTTPAPI_H
#define HTTPAPI_H

#include "ServerInterface/api_param_def.h"

#include <QObject>
#include <QByteArray>
#include <QDate>

class HttpAPI : public QObject
{
    Q_OBJECT
public:
    virtual ~HttpAPI(void);
    static HttpAPI* instance();

    enum GateChannel
    {
        Channel_1,
        Channel_2
    };

    //2.3.17 调度系统拉取航班计划
    Return_Flight_Plan_Param getFlightPlan(const QString& boardingGateNo);
    //实时登机界面的几个按钮控制接口
    Return_MSG Post(PostUrlType type, const QString& flightNo, const QString& boardingGate, const QString& flightDay);
    //2.3.26 调度系统航班查询
    Return_Flight_Plan_Param queryFlight(const QString& flightNo, const QDate &flightDate = QDate());
    //2.3.26 人员回查接口
    int enquiryPPL(const QString& flightNo, const QString& boardingNumber, QJsonObject& outObject, const QString& seatNO = QString(), bool isBaby = false, const QString &flightDay = "");
    int enquiryPPL(const QString& cardId, QJsonObject& outObject, bool isBaby = false);
    FlowReviewResponse enquiryPPL(const FlowReviewRequest& request);
    // 2.3.32 底库拦截标记接口/2.3.32 底库取消拦截标记接口
    Return_MSG interceptOrCancel(QString flightNo, QString id, QString date, int isInterceptLabel);

    //闸机控制
    Return_MSG GateCtrl(const int gateChannelNO, gateWorkStatus workStat, gateDoorStatus doorStat);
    //登机模式下人工放行
    Return_MSG BoardingMode_ManualPass(const int gateChannelNO, BoardingMode_ManualPass_Send&);
    //采集模式人工放行
    Return_MSG CollectingMode_ManualPass(const int gateChannelNO, Collect_Info& content, int collectTyoe);
    //推送航班或采集计划接口
    Return_MSG pushPlan(const int gateChannelNO, FlightPlan& plan, int mode, int face_fastType, int collectType = 0, int status = 0);

    //LiuYong
    FlightReviewResponse get_ppl_in_flight(const FlightReviewRequest& request);
    LibDeleteResponse removeSpecific(const LibDeleteRequest& request);

signals:
    void networkStat(bool netStat, const QString title= "",const QString msg= "");
    void pushPlanStat(int channel, bool netStat, const QString title, const QString msg);

private:
    explicit HttpAPI(QObject *parent = nullptr);

    int Init();
    int UnInit();
    int setHeader(QString &addr, QString &API);
    int removeHeader(QString &addr, QString &API);

private:
    QString caPath;
//    QString apiId;/*libHTTP default set*/
//    QString apiKey;/*libHTTP default set*/
    QString m_reqId;
    bool m_isLogData{true};
    int maxPostFailTimes{1};

    QString flight_palne_Addr;
    QString startBording_Addr;
    QString endBording_Addr;
    QString otherFlight_Addr;
    QString cancelFlight_Addr;
    QString exceptionFlight_Addr;
    QString queryFlight_Addr;
    QString queryPPL_Addr;

    QString flight_palne_API;
    QString startBording_API;
    QString endBording_API;
    QString otherFlight_API;
    QString cancelFlight_API;
    QString exceptionFlight_API;
    QString queryFlight_API;
    QString queryPPL_API;

/*LiuYong*/
    QString flightReviewServer_Addr;
    QString flightReview_API;
    QString libDeleteFlight_API;
/**/

    QString GateChannel_Addr[2];
    QString pushPlan_API;
    QString gate_ctrl_API;
    QString boardingMode_manualCtrl_API;
    QString collectingMode_cmd_API;
    QString collectingMode_manualCtrl_API;

};

inline HttpAPI* HttpAPI::instance()
{
    static HttpAPI hcSer;
    return &hcSer;
}

#endif // HTTPAPI_H
