#include "homepage.h"
#include "ui_homepage.h"

#include "logindialog.h"
#include "ui_realtimeboarding.h"
#include "ui_portraitcollection.h"
#include "settings.h"
#include "ServerInterface/workanotherthread.h"
#include "ServerInterface/mqmsg_parse.h"
#include "ServerInterface/httpServer.h"
#include "ServerInterface/httpAPI.h"
#include "ServerInterface/IDCardRead_Recog.h"
#include "ticketScancer/serialportser.h"
#include <QMessageBox>
#include <QTimeLine>
#include <QGridLayout>
#include <QScrollArea>
#include <QTimer>
#include <QTime>
#include <QDebug>

HomePage* HomePage::global_instance = nullptr;

int HomePage::s_mode = 0;
int HomePage::s_type = 0;
int HomePage::s_collectType = 0;
int HomePage::s_status = 0;

HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    global_instance = this;

    setUI();
    initMenuFrame();
    initTranslationWidget();

    initSubThread();

    initMqServer();
    initHttpServer();

    initSerialPort();

    initIDCardReaer();

    emit otherThread_getFlightPlane();
}

HomePage::~HomePage()
{
    SerialPortSer::instance(TicketScanner)->UnInit();
    SerialPortSer::instance(DepartureInfoSender)->UnInit();
    IDCardLoader::instance()->unInit();  //2020.06.08 found an unsolved bug: Only under release version, exit this application while a QDialog showing, can cause a crash at internal the dynamic link library ;

    if (nullptr != httpServer && httpServerStarted){
        if (0 != StopHTTPServer()){
            qWarning()<<"httpServer stopped error !";
        }
    }

    m_subThread.quit();
    m_subThread.wait();
    delete ui;
}

void HomePage::showSignInDlg()
{
    m_WorkflowRecording->clearInfo();//清空全流程记录的缓存
    m_FlightEnquires->clearAllInfo();//清空航班回查的缓存
    on_Button_HomePage_clicked();
    if (ui->Button_menu->isChecked()){
        ui->Button_menu->setChecked(false);
        ui->widget_workForeground->hide();
        emit timeLineStart();
    }

    static LoginDialog *login = nullptr;

    if (login == nullptr){
        login = new LoginDialog(this);
        login->move(0,0);

        connect(login, &LoginDialog::accepted, [&]{
            _isSignin = true;
            qInfo()<<"[Sign In Success]";
            login->hide();
        });
    }

    login->initUI();
    login->show(); //qt virtualkeyboard has bug, while using "QDialog::exec()", we should "QDialog::show()" before do that;
}

void HomePage::setUI()
{
    this->setWindowIcon(QIcon(QApplication::applicationFilePath() + "/Images/windowIcon.jpg"));
    this->setWindowFlags(Qt::FramelessWindowHint);          //Set no border, no minimize button.
//    this->setAttribute(Qt::WA_TranslucentBackground,true);        //Set transparent background.
//    this->QWidget::setCursor(QCursor(Qt::BlankCursor));           //Hide mouse point.

    if (1 == LocalSettings::instance()->value("Device/setScrollWindow", 0).toInt()){
        QScrollArea *area = new QScrollArea(ui->centralWidget);
        area->setWidget(ui->widget_ALL);
        area->setGeometry(0,0,800,1080);
        area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

    QTimer *time_sync = new QTimer(this);
    connect(time_sync, SIGNAL(timeout()), this, SLOT(updateTime_regularyRestart()));
    time_sync->start(250);

    ui->widget_workForeground->hide();

    m_boardingGateNo = LocalSettings::instance()->value("Device/boardingGateNo").toString();
    ui->label_boardingGateNo_->setText(m_boardingGateNo);
  }

int HomePage::setBoardingModeDefault()
{
    int settingBoardingMode = LocalSettings::instance()->value("Device/defaultBoardingMode", 1).toInt();

    if (0 != settingBoardingMode && 1 != settingBoardingMode){
        MessageDialog errorBoardingMode(ui->widget_work, "error setting", "设置登机模式错误!\n系统默认将采用人脸登机模式！", 1);
        errorBoardingMode.exec();
        settingBoardingMode = 0;
    }

    //改变按钮样式
    if (0 == settingBoardingMode){
        ui->Button_changeBoardingMode_face->setChecked(true);
        ui->Button_changeBoardingMode_quick->setChecked(false);
    }else if (1 == settingBoardingMode){
        ui->Button_changeBoardingMode_face->setChecked(false);
        ui->Button_changeBoardingMode_quick->setChecked(true);
    }

    return settingBoardingMode;
}

void HomePage::initMenuFrame()
{
    timeLine = new QTimeLine(200, this);

    timeLine->setFrameRange(-96, 100);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(frameChange(int)));
    connect(this, SIGNAL(timeLineStart()), timeLine, SLOT(start()));//use connection to be compatible with multiThread;
}

void HomePage::initTranslationWidget()
{
    m_RealtimeBoarding = new RealtimeBoarding(ui->centralWidget);
    m_FlightEnquires =  new FlightEnquires(ui->centralWidget);
    m_WorkflowRecording = new WorkflowRecording(ui->centralWidget);
    m_PortraitCollection = new PortraitCollection(ui->centralWidget);

    list[0]=ui->widget_home;     //Qt's bug : Creat a QList in  the menber variable of Class need to occupy an index. Wrote at 2019-12-30, 02:15, by monster_zee!
    list.append(m_RealtimeBoarding);
    list.append(m_WorkflowRecording);
    list.append(m_FlightEnquires);
    list.append(m_PortraitCollection);

    translationWidget = new TranslationWidget(list,ui->widget_work);
    connect(translationWidget, SIGNAL(currentPageChanged(int)), this, SLOT(onPageChanged(int)));

    QGridLayout *workLayout = new QGridLayout(ui->widget_work);
    workLayout->addWidget(translationWidget);
    workLayout->setMargin(0);

    bool movableUI = LocalSettings::instance()->value("System/movableUI", false).toBool();
    translationWidget->setMoveEnabled(movableUI);
}

void HomePage::initIDCardReaer()
{
    int Type = LocalSettings::instance()->value("IDCardLoader/deviceType", 0).toInt();
    QString keyNumber = LocalSettings::instance()->value("IDCardLoader/keyNumber", 0).toString();
    int interval = LocalSettings::instance()->value("IDCardLoader/readInterval", 1000).toInt();

    connect(IDCardLoader::instance(), &IDCardLoader::IDCardReaderstat, this, &HomePage::on_IDCardReaderstat);
    connect(IDCardLoader::instance(), &IDCardLoader::PassportReaderstat, this, &HomePage::on_PassportReaderstat);
    IDCardLoader::instance()->init(Type, interval, keyNumber);
}

void HomePage::initSerialPort()
{
    SerialPortSer::instance_count = 0;
    connect(SerialPortSer::instance(TicketScanner), &SerialPortSer::spStat, this, &HomePage::on_serialPortStat, Qt::QueuedConnection);
    SerialPortSer::instance(TicketScanner)->Init();

    connect(SerialPortSer::instance(DepartureInfoSender), &SerialPortSer::spStat, this, &HomePage::on_serialPortStat, Qt::QueuedConnection);
    SerialPortSer::instance(DepartureInfoSender)->Init();
}

void HomePage::initSubThread()
{
    WorkAnotherThread *worker = new WorkAnotherThread;
    worker->moveToThread(&m_subThread);
    connect(&m_subThread, &QThread::finished, worker, &QObject::deleteLater);

    connect(this, SIGNAL(otherThread_getFlightPlane()), worker, SLOT(on_getFlightPlane()));
    connect(worker, &WorkAnotherThread::results_flightPlane, m_RealtimeBoarding, &RealtimeBoarding::handleResults_flightPlane);
    connect(this, &HomePage::otherThread_GateCtrl, worker, &WorkAnotherThread::on_GateCtrl);

    m_subThread.start();
    emit translationWidget->currentPageChanged(0);
}

void HomePage::initMqServer()
{
    m_pMQmsg = new ParseMQmsg(this);
    connect(m_pMQmsg, &ParseMQmsg::recivedMQmsg, this, &HomePage::onRecivedMQmsg);
}

void HomePage::initHttpServer()
{
    httpServer = HttpServer::instance();
    connect(httpServer, &HttpServer::GateNetStat, this, &HomePage::on_GateNetError);
    connect(httpServer, &HttpServer::sendDepartureInfo, SerialPortSer::instance(DepartureInfoSender), &SerialPortSer::sendDepartureInfo);
    connect(httpServer, &HttpServer::collectInfo, m_PortraitCollection, &PortraitCollection::updtCrrntCllctInfo);

    int portNO_=LocalSettings::instance()->value("LocalHttpServer/port", 8080).toInt();
    int nRet = StartHTTPServer(portNO_, httpServer);
    if(nRet != 0)
    {
        httpServerStarted = false;
        qWarning()<<QString("Http server start at port(%1) failed").arg(portNO_);
        QString err("[Http服务启动失败]");
        QString curr_errs = ui->label_statTips->getText();
        if (!curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.append(err));
        else if (curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.remove(err));
            MessageDialog *msgDlg = new MessageDialog(ui->widget_work, "Http服务启动失败", "HttpServer启动失败\n请重启程序！", 1);
            msgDlg->setAttribute(Qt::WA_DeleteOnClose, true);
            msgDlg->show();
    }
    else{
        httpServerStarted = true;
        qInfo()<<QString("Http server start success! port = %1").arg(portNO_);
        QString err("[Http服务启动失败]");
        QString curr_errs = ui->label_statTips->getText();
        if (curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.remove(err));
    }

    connect(HttpAPI::instance(), &HttpAPI::networkStat, this, &HomePage::on_networkStat);
    connect(HttpAPI::instance(), &HttpAPI::pushPlanStat, this, &HomePage::on_PushPlanStat);
    connect(m_PortraitCollection, &PortraitCollection::GateNetStat, this, &HomePage::on_GateNetError);
}

void HomePage::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton && ui->widget_workForeground->underMouse()){
        if (ui->Button_menu->isChecked()){
            ui->Button_menu->setChecked(false);
            ui->widget_workForeground->hide();
            emit timeLineStart();
        }
    }
}

void HomePage::frameChange(int f)
{
    if(!ui->Button_menu->isChecked()){
        ui->widget_menuBelow->move(0,0-f);
    }
    else{
        ui->widget_menuBelow->move(0,0+f);
    }
}

void HomePage::on_Button_menu_clicked()
{
    if (ui->Button_menu->isChecked()){
        ui->widget_workForeground->show();  //this widget is forward on widget_work, equa to set widget_work disable;
    }
    else{
        ui->widget_workForeground->hide();
    }
    emit timeLineStart();
}

void HomePage::on_Button_return_clicked()
{
    if (ui->Button_menu->isChecked()){
        ui->Button_menu->setChecked(false);
        ui->widget_workForeground->hide();
        emit timeLineStart();
        return;
    }

    if (translationWidget != nullptr){
        if (translationWidget->getCurrentPage() == list.at(0)){
            on_Button_SignOut_clicked();
            return;
        }
        else if (m_FlightEnquires->isStatisticsMode){

            on_Button_RealtimeBoarding_clicked();
            return;
        }
        else {
            on_Button_HomePage_clicked();
            return;
        }
    }
}

void HomePage::on_Button_HomePage_clicked()
{
    int currentPage = 0;
    translationWidget->setCurrentPage(currentPage, true);
}

void HomePage::on_Button_RealtimeBoarding_clicked()
{
    int currentPage = 1;
    translationWidget->setCurrentPage(currentPage, true);
}

void HomePage::on_Button_WorkflowRecording_clicked()
{
    m_WorkflowRecording->clearInfo(); //清空全流程记录的缓存

    m_FlightEnquires->quitStatisticsMode();

    int currentPage = 2;
    translationWidget->setCurrentPage(currentPage, true);
}

void HomePage::on_Button_FlightEnquires_clicked()
{
    m_FlightEnquires->quitStatisticsMode();

    int currentPage = 3;
    translationWidget->setCurrentPage(currentPage, true);
}

void HomePage::on_Button_PortraitCollection_clicked()
{
    int currentPage = 4;
    translationWidget->setCurrentPage(currentPage, true);
}

void HomePage::on_Button_SignOut_clicked()
{
    MessageDialog msg(ui->centralWidget, nullptr, "确 认 退 出 登 录 ?");
    if (msg.exec()){
        _isSignin = false;
        qInfo()<<"[Sign Out]";
        showSignInDlg();
    }
}

void HomePage::on_Button_FlightEnquires_2_clicked()
{
    on_Button_FlightEnquires_clicked();
}

void HomePage::on_Button_PortraitCollection_2_clicked()
{
    on_Button_PortraitCollection_clicked();
}

void HomePage::on_Button_RealtimeBoarding_2_clicked()
{
    on_Button_RealtimeBoarding_clicked();
}

void HomePage::on_Button_WorkflowRecording_2_clicked()
{
    on_Button_WorkflowRecording_clicked();
}

void HomePage::on_Button_A1_clicked()
{
    emit otherThread_GateCtrl(1, NoneWorkStat, Open_A_Door);
}

void HomePage::on_Button_B1_clicked()
{
    emit otherThread_GateCtrl(1, NoneWorkStat, Open_B_Door);
}

void HomePage::on_Button_A2_clicked()
{
    emit otherThread_GateCtrl(2, NoneWorkStat, Open_A_Door);
}

void HomePage::on_Button_B2_clicked()
{
    emit otherThread_GateCtrl(2, NoneWorkStat, Open_B_Door);
}

void HomePage::on_Button_SideDoor1_clicked()
{
    emit otherThread_GateCtrl(1, NoneWorkStat, Open_C_Door);
}

void HomePage::on_Button_SideDoor2_clicked()
{
    emit otherThread_GateCtrl(2, NoneWorkStat, Open_C_Door);
}

void HomePage::on_Button_stop1_clicked()
{
   emit otherThread_GateCtrl(1, Pause, NoneDoorStat);
}

void HomePage::on_Button_stop2_clicked()
{
    emit otherThread_GateCtrl(2, Pause, NoneDoorStat);
}

void HomePage::on_Button_keepClose1_clicked()
{
    emit otherThread_GateCtrl(1, KeepClose, NoneDoorStat);
}

void HomePage::on_Button_keepClose2_clicked()
{
    emit otherThread_GateCtrl(2, KeepClose, NoneDoorStat);
}

void HomePage::updateTime_regularyRestart()
{//此函数每250ms触发一次
    ui->label_currentTime->setText(QTime::currentTime().toString());

    // 每天十二点清空缓存
    if (QTime::currentTime().msecsTo(QTime(0,0,0,0)) == 0){
        m_WorkflowRecording->clearInfo();//清空全流程记录的缓存
        m_FlightEnquires->clearAllInfo();//清空航班回查的缓存
    }

    QTime restartTime = QTime::fromString(LocalSettings::instance()->value("System/restartTime").toString(),"HH:mm:ss");
    if (restartTime.isNull())
        return;

    int sec = QTime::currentTime().secsTo(restartTime);

    //因为每250ms触发一次，所以一秒内会触发多次
    if (sec <= 60 && sec >= -1){
        static MessageDialog *rstDlg = nullptr;
        static bool s_restart_or_not = true; //是否重启标志
        static bool hasEnsured = false; // 是否已经确认标志

        if (rstDlg == nullptr){
            rstDlg = new MessageDialog(this, "自动重启", QString("系统将在 %1 秒之后重启\n是否确认？").arg(sec), 2);

            connect(rstDlg, &MessageDialog::accepted, [&]{
                s_restart_or_not = true;
                hasEnsured = true;
            });
            connect(rstDlg, &MessageDialog::rejected, [&]{
                s_restart_or_not = false;
                hasEnsured = true;
            });
        }

        //已经确认是否重启
        if (hasEnsured){
            rstDlg->hide();
        }
        else if (-1 != sec){//sec == -1时hasEnsured为false
            rstDlg->setText(QString("系统将在 %1 秒之后重启\n是否确认？").arg(sec));
            rstDlg->show();
        }

        //重启
        if (s_restart_or_not){
            if (sec <= 3 && sec >= 0){
                rstDlg->setText(QString("系统将在 %1 秒之后重启\n是否确认？").arg(sec));
                rstDlg->show();
            }
            if (0 == sec){
                QCoreApplication::exit(773);
            }
        }
        //不重启，恢复标志状态，才能使第二天仍然可以触发自动重启
        else if (-1 == sec){
            s_restart_or_not = true;
            hasEnsured = false;
        }
    }
}

void HomePage::onRecivedMQmsg(int type)
{
    switch (type) {
    case 100:
    {
        m_RealtimeBoarding->changeFlightPlan(m_pMQmsg->flight_plan);
        break;
    }
    case 101:
        //Date:2020-04-27:[Bug:1298];建库消息全部按照航班计划处理,
        m_RealtimeBoarding->colorPlaneLabel(m_pMQmsg->creat_repository);
        break;
    case 102:
        if (m_RealtimeBoarding->is_statrtBoarding(m_pMQmsg->bording_start)){
            HttpAPI::instance()->pushPlan(1, m_pMQmsg->bording_start, HomePage::s_mode, m_RealtimeBoarding->m_boardingMode,  HomePage::s_collectType, 2);
            HttpAPI::instance()->pushPlan(2, m_pMQmsg->bording_start, HomePage::s_mode, m_RealtimeBoarding->m_boardingMode,  HomePage::s_collectType, 2);
        }
        break;

    case 103:
        if (m_RealtimeBoarding->is_endBoarding(m_pMQmsg->boarding_end)){
            HttpAPI::instance()->pushPlan(1, m_pMQmsg->boarding_end, HomePage::s_mode, m_RealtimeBoarding->m_boardingMode,  HomePage::s_collectType, 3);
            HttpAPI::instance()->pushPlan(2, m_pMQmsg->boarding_end, HomePage::s_mode, m_RealtimeBoarding->m_boardingMode,  HomePage::s_collectType, 3);
        }
        break;

    case 109:
//        HomePage::s_status = m_pMQmsg->remove_repository.status;
        break;

    case 300:
        // do nothing!
        break;

    case 301:
        if (s_mode == 0)
            m_RealtimeBoarding->update_ppl_num(m_pMQmsg->ppl_num);
//        if (s_mode == 1)    //not used, because the mq_server won't push this msg at collecting mode;
//            m_PortraitCollection->on_show_ppl_num(m_pMQmsg->ppl_num);
        break;

    case 302:
        m_FlightEnquires->fillDepAndUnboardWithMQ(m_pMQmsg->new_repository);
        break;
    default:
        break;
    }
}


void HomePage::onPageChanged(const int pageIndex)
{
    switch (pageIndex) {
    case 0://homePage
        ui->Button_menu->hide();
        ui->Button_changeBoardingMode_face->hide();
        ui->Button_changeBoardingMode_quick->hide();
        m_FlightEnquires->quitStatisticsMode();
        break;

    case 1://realTimeBoarding
        ui->Button_menu->show();
        ui->Button_changeBoardingMode_face->show();
        ui->Button_changeBoardingMode_quick->show();
        m_FlightEnquires->quitStatisticsMode();

        if (m_RealtimeBoarding->m_isBording){
            HomePage::s_status = 2;
        }
        else {
            HomePage::s_status = 1;
        }
        emit otherThread_getFlightPlane();
        break;

    case 2://workflowrecording
        ui->Button_menu->show();
        ui->Button_changeBoardingMode_face->hide();
        ui->Button_changeBoardingMode_quick->hide();
        break;

    case 3://flightenquiers
        ui->Button_menu->show();
        ui->Button_changeBoardingMode_face->hide();
        ui->Button_changeBoardingMode_quick->hide();
        break;

    case 4://portraitcollecton
        ui->Button_menu->show();
        ui->Button_changeBoardingMode_face->hide();
        ui->Button_changeBoardingMode_quick->hide();
        m_FlightEnquires->quitStatisticsMode();
        m_PortraitCollection->updateCurrentDate();
        break;

    default:
        break;
    }
}

void HomePage::on_mqServerStat(int channel, bool stat)
{
    QString err(QString("[MQ_%1服务异常] ").arg(channel));
    QString curr_errs = ui->label_statTips->getText();
    if (!stat && !curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.append(err));
    else if (stat && curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.remove(err));

    if (stat){
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/有.png"));
    }
    else {
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/无.png"));
    }
}


void HomePage::on_networkStat(bool netStat, const QString title, const QString msg)
{
    QString err("[网络环境存在异常]");
    QString curr_errs = ui->label_statTips->getText();
    if (!netStat && !curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.append(err));
    else if (netStat && curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.remove(err));

    if (netStat){
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/有.png"));
    }
    else {
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/无.png"));
    }

    if ((!title.isEmpty()) && (!msg.isEmpty())){
        MessageDialog *msgDlg = new MessageDialog(ui->widget_work, title, msg, 1);
        msgDlg->setAttribute(Qt::WA_DeleteOnClose, true);
        msgDlg->show();
    }
}

void HomePage::on_GateNetError(const QString title, const QString msg)
{
    if ((!title.isEmpty()) && (!msg.isEmpty())){
        MessageDialog msgDlg(ui->widget_work, title, msg, 1);
        msgDlg.show();
    }
}

void HomePage::on_PushPlanStat(int channel, bool netStat, const QString title, const QString msg)
{
    QString err("[网络环境存在异常]");
    QString curr_errs = ui->label_statTips->getText();
    if (!netStat && !curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.append(err));
    else if (netStat && curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.remove(err));

    if (netStat){
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/有.png"));
    }
    else {
        ui->label_netStat->setPixmap(QPixmap(":/2系统首页/Images/2系统首页/wifi/无.png"));
    }

    switch (channel) {
    case 1:
        if ((!title.isEmpty()) && (!msg.isEmpty())){
            static MessageDialog *pushFail_1 = nullptr;
            if (pushFail_1 == nullptr){
                pushFail_1 = new MessageDialog(ui->widget_work, title, msg, 1);
            }
            pushFail_1->show();
        }
        break;
    case 2:
        if ((!title.isEmpty()) && (!msg.isEmpty())){
            static MessageDialog *pushFail_2 = nullptr;
            if (pushFail_2 == nullptr){
                pushFail_2 = new MessageDialog(ui->widget_work, title, msg, 1);
            }
            pushFail_2->show();
        }
        break;
    default:
        break;
    }
}

void HomePage::on_IDCardReaderstat(bool stat)
{
    QString err("[身份证阅读器故障] ");
    QString curr_errs = ui->label_statTips->getText();
    if (!stat && !curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.append(err));
    else if (stat && curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.remove(err));
}

void HomePage::on_PassportReaderstat(bool stat)
{
    QString err("[护照阅读器故障] ");
    QString curr_errs = ui->label_statTips->getText();
    if (!stat && !curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.append(err));
    else if (stat && curr_errs.contains(err))
        ui->label_statTips->setText(curr_errs.remove(err));
}

void HomePage::on_serialPortStat(bool stat)
{
    if (sender() == SerialPortSer::instance(TicketScanner)){
        QString err("[机票扫描枪故障] ");
        QString curr_errs = ui->label_statTips->getText();
        if (!stat && !curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.append(err));
        else if (stat && curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.remove(err));
    }

    if (sender() == SerialPortSer::instance(DepartureInfoSender)){
        QString err("[离港传输接口故障] ");
        QString curr_errs = ui->label_statTips->getText();
        if (!stat && !curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.append(err));
        else if (stat && curr_errs.contains(err))
            ui->label_statTips->setText(curr_errs.remove(err));

        if (!stat){
            MessageDialog *msg = new MessageDialog(ui->widget_work, "关键设备异常", "离港传输串口连接异常！\n旅客将无法正常登机！", 1);
            msg->setAttribute(Qt::WA_DeleteOnClose, true);
            msg->show();
        }
    }

}

void HomePage::on_Button_changeBoardingMode_face_clicked(bool checked)
{
    ui->Button_changeBoardingMode_face->setChecked(!checked);

    if(m_isChangingBordingMode){
        return;
    }
    else m_isChangingBordingMode = true;

    if (!checked){
        //由按下到释放
        ui->Button_changeBoardingMode_face->setChecked(true);
        m_isChangingBordingMode = false;
        return;
    }else if (m_RealtimeBoarding->m_isBording || HomePage::s_mode != 0){
        ui->Button_changeBoardingMode_face->setChecked(false);
        m_isChangingBordingMode = false;
        return;
    }
    else if (-1 != m_RealtimeBoarding->on_changeBoardingMod()){

        //改变成功
        ui->Button_changeBoardingMode_face->setChecked(true);
        ui->Button_changeBoardingMode_quick->setChecked(false);
        m_isChangingBordingMode = false;
        return;
    }
    else {
        //改变模式失败
        ui->Button_changeBoardingMode_face->setChecked(false);
    }
    m_isChangingBordingMode = false;
}

void HomePage::on_Button_changeBoardingMode_quick_clicked(bool checked)
{
    ui->Button_changeBoardingMode_quick->setChecked(!checked);

    if(m_isChangingBordingMode){
        return;
    }
    else m_isChangingBordingMode = true;

    if (!checked){
        //由按下到释放
        ui->Button_changeBoardingMode_quick->setChecked(true);
        m_isChangingBordingMode = false;
        return;
    }else if (m_RealtimeBoarding->m_isBording || HomePage::s_mode != 0){
        ui->Button_changeBoardingMode_quick->setChecked(false);
        m_isChangingBordingMode = false;
        return;
    }
    else if (-1 != m_RealtimeBoarding->on_changeBoardingMod()){
        //改变成功
        ui->Button_changeBoardingMode_face->setChecked(false);
        ui->Button_changeBoardingMode_quick->setChecked(true);
        m_isChangingBordingMode = false;
        return;
    }
    else //改变模式失败
    {
        ui->Button_changeBoardingMode_quick->setChecked(false);
    }

    m_isChangingBordingMode = false;
}

void HomePage::on_mousePressEventFilter()
{
    if (autoSignOut == nullptr){
        autoSignOut = new QTimer(this);
        autoSignOut->setSingleShot(true);
        connect(autoSignOut, &QTimer::timeout, [=]
        {
            if (_isSignin && !m_RealtimeBoarding->m_isBording) {
                _isSignin = false;
                qInfo()<<"[Auto sign out without operating for a long time]";
                showSignInDlg();
            }
        });
    }

    autoSignOut->start(LocalSettings::instance()->value("System/autoSignOutInterval", 30).toInt()*60*1000);
}
