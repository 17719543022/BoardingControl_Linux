#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QThread>
#include <ServerInterface/api_param_def.h>

#include "UI_Classes/UI_include_all.h"
#include "translationwidget.h"

namespace Ui {
class HomePage;
}

class ParseMQmsg;
class HttpServer;
class RealtimeBoarding;
class WorkflowRecording;
class FlightEnquires;
class PortraitCollection;
class TranslationWidget;
class QTimeLine;
class HomePage : public QMainWindow
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

    int setBoardingModeDefault();
    void showSignInDlg();

public slots:
    /*about control*/
    void onRecivedMQmsg(int type);
    void on_mqServerStat(int channel, bool stat);
    void on_networkStat(bool netStat, const QString title, const QString msg);
    void on_GateNetError(const QString title, const QString msg);
    void on_PushPlanStat(int channel, bool netStat, const QString title, const QString msg);
    void on_IDCardReaderstat(bool stat);
    void on_PassportReaderstat(bool stat);
    void on_serialPortStat(bool stat);
    void on_mousePressEventFilter();
private:
    void setUI();
    void initMenuFrame();
    void initTranslationWidget();
    void initIDCardReaer();
    void initSerialPort();
    void initSubThread();
    void initMqServer();
    void initHttpServer();
    void mousePressEvent(QMouseEvent *);

private slots:
    /*about UI*/
    void updateTime_regularyRestart();
    void frameChange(int f);
    void onPageChanged(const int pageIndex);
    void on_Button_menu_clicked();
    void on_Button_return_clicked();
    void on_Button_HomePage_clicked();
    void on_Button_RealtimeBoarding_clicked();
    void on_Button_WorkflowRecording_clicked();
    void on_Button_FlightEnquires_clicked();
    void on_Button_PortraitCollection_clicked();
    void on_Button_FlightEnquires_2_clicked();
    void on_Button_PortraitCollection_2_clicked();
    void on_Button_RealtimeBoarding_2_clicked();
    void on_Button_WorkflowRecording_2_clicked();
    void on_Button_A1_clicked();
    void on_Button_B1_clicked();
    void on_Button_A2_clicked();
    void on_Button_B2_clicked();
    void on_Button_SideDoor1_clicked();
    void on_Button_SideDoor2_clicked();
    void on_Button_stop1_clicked();
    void on_Button_stop2_clicked();
    void on_Button_keepClose1_clicked();
    void on_Button_keepClose2_clicked();
    void on_Button_SignOut_clicked();

    void on_Button_changeBoardingMode_face_clicked(bool checked);

    void on_Button_changeBoardingMode_quick_clicked(bool checked);

signals:
        void timeLineStart();
        void otherThread_GateCtrl(const int GateChannelNO, gateWorkStatus workStat, gateDoorStatus doorStat);
        void otherThread_getFlightPlane();

public:
        static HomePage* global_instance;
        static int s_mode;//模式: 0-登机模式，1-采集模式
        static int s_type;//类型: 0-人脸模式，1-快速模式
        static int s_collectType;//采集类型: 0-经停采集，1-备降采集
        static int s_status;//状态: 0-无计划，1-等待开始，2-开始，3-结束
        TranslationWidget *translationWidget{nullptr};//滑动窗口
        RealtimeBoarding *m_RealtimeBoarding{nullptr};  //实时登机页面
        WorkflowRecording *m_WorkflowRecording{nullptr};    //全流程记录页面
        FlightEnquires * m_FlightEnquires{nullptr}; //航班回查页面
        PortraitCollection *m_PortraitCollection{nullptr};  //人像采集页面

private:
    Ui::HomePage *ui{nullptr};
    QThread m_subThread;
    ParseMQmsg *m_pMQmsg{nullptr};
    HttpServer* httpServer{nullptr};
    bool httpServerStarted{false};

    QTimeLine *timeLine{nullptr};//菜单栏下滑效果
    QList<QWidget *> list{nullptr};

    bool m_isChangingBordingMode{false};//由于按钮控制其他模块，用此参数保证按钮任务未执行完之前只生效一次

    QString m_boardingGateNo;//登机口编号

    bool _isSignin{false};
    QTimer *autoSignOut{nullptr};

    friend class WorkAnotherThread;
    friend class ParseMQmsg;
    friend class HttpServer;
    friend class RealtimeBoarding;
    friend class PortraitCollection;
    friend class FlightEnquires;
    friend class WorkflowRecording;
};

#endif // HOMEPAGE_H
