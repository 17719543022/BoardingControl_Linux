#include "realtimeboarding.h"
#include "ui_realtimeboarding.h"
#include "settings.h"
#include "homepage.h"
#include "ServerInterface/httpAPI.h"
#include "ServerInterface/IDCardRead_Recog.h"
#include "ServerInterface/httpServer.h"
#include "ticketScancer/serialportser.h"
#include <QDebug>
#include <QTime>
#include <QSound>

RealtimeBoarding::RealtimeBoarding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealtimeBoarding)
{
    ui->setupUi(this);

    m_boardingMode = HomePage::global_instance->setBoardingModeDefault();
    HomePage::s_type = m_boardingMode;

    setUI();
    connect(HttpServer::instance(), &HttpServer::showBoardingResult, this, &RealtimeBoarding::on_showBoardingResult, Qt::QueuedConnection);
}

RealtimeBoarding::~RealtimeBoarding()
{
    delete ui;
}

void RealtimeBoarding::setUI()
{
    inquiryWidget::instance()->setParent(this);

    excpDlg = new MessageDialog(this, "航班错误", "非本航班旅客禁止登机！", 1);
    excpDlg->hide();

    ui->pushButton_endBoarding->hide();
    ui->pushButton_find->hide();

    ui->widget_time->hide();
}

void RealtimeBoarding::showFlightInfo()
{
    if (m_flightPlan.twoFlightNo.isEmpty())
        ui->label_mainFlightNO_->setText("- - - - - -");
    else ui->label_mainFlightNO_->setText(m_flightPlan.twoFlightNo);

    if (m_flightPlan.depAirportName.isEmpty())
        ui->label_fromPlace->setText("- - - -");
    else ui->label_fromPlace->setText(m_flightPlan.depAirportName);

    if (m_flightPlan.arrAirportName.isEmpty()){
        ui->label_midPlace->setText("");
        ui->label_arrivalPlace->setText("- - - -");
    }
    else if (m_flightPlan.midwayName == m_flightPlan.arrAirportName){
        ui->label_midPlace->setText("");
        ui->label_arrivalPlace->setText(m_flightPlan.midwayName);
    }
    else {
        ui->label_midPlace->setText(m_flightPlan.arrAirportName);
        ui->label_arrivalPlace->setText(m_flightPlan.midwayName.remove("-").remove(m_flightPlan.arrAirportName));
    }

    ui->ScrollText_shareFlight->setTextList(m_flightPlan.shareFltno);
    ui->ScrollText_shareFlight->setInterval_scrollTimer(2000);
    ui->ScrollText_shareFlight->setInterval_animation(1000);

    if (!m_flightPlan.depTimeJ.isEmpty()){
        QString tmp_depTimeJ = m_flightPlan.depTimeJ.left(2)+":"+m_flightPlan.depTimeJ.mid(2);
        ui->label_departureTime->setText(tmp_depTimeJ);
    }
    else {
        ui->label_departureTime->setText("--:--");
    }
    if (!m_flightPlan.boardingTime.isEmpty()){
        QString tmp_boardingTIme = m_flightPlan.boardingTime.left(2)+":"+m_flightPlan.boardingTime.mid(2);
        ui->label_boardingTime->setText(tmp_boardingTIme);
    }
    else{
        ui->label_boardingTime->setText("--:--");
    }

    ui->label_countBoarding->setNum(m_flightPlan.boardingNum);
    ui->label_countTotal->setNum(m_flightPlan.faceNums);
    ui->label_countStart->setNum(m_flightPlan.orgDepNum);
    ui->label_countTransfer->setNum(m_flightPlan.transferNum);
    ui->label_countMidway->setNum(m_flightPlan.midwayNum);

    if (m_flightPlan.status != 1 && m_flightPlan.status != 2){//未建库的
           ui->label_picture_plane->setStyleSheet("image: url(:/3实时登机/Images/3实时登机/3.0-3.2/矢量剪影飞机-拷贝.png);");
           ui->label_mainFlightNO_->setStyleSheet("color: rgb(200, 200, 200);");
    }
    else{
        ui->label_picture_plane->setStyleSheet("image: url(:/3实时登机/Images/3实时登机/3.0-3.2/矢量剪影飞机.png);");
        ui->label_mainFlightNO_->setStyleSheet("color: rgb(0, 228, 255);");
    }
}

void RealtimeBoarding::on_showBoardingResult(int channel, bool isManualOperation, int result, int transferType, bool hasSecurityInfo
                                             , int seatLabel, bool hasBaby, bool moreTicket, bool isMarked
                                             , const QString name, const QString cardId, const BoardingTicketInfo ticketinfo, const QByteArray faceImage){
    QPixmap pixmap;
    pixmap.loadFromData(faceImage);
    QString flight_order_No_;

    if (1 == channel){
        user_left.name = name;
        user_left.ticket = ticketinfo;
        user_left.scenePhoto = faceImage;

        if (!ticketinfo.flightNo.isEmpty() && !ticketinfo.boardingNumber.isEmpty()){
            flight_order_No_ = ticketinfo.flightNo + "/" + ticketinfo.boardingNumber;
        }
        else if (!ticketinfo.flightNo.isEmpty() || !ticketinfo.boardingNumber.isEmpty()){
            flight_order_No_ = ticketinfo.flightNo + ticketinfo.boardingNumber;
        }
    }
    else if (2 == channel){
        user_right.name = name;
        user_right.ticket = ticketinfo;
        user_right.scenePhoto = faceImage;

        if (!ticketinfo.flightNo.isEmpty() && !ticketinfo.boardingNumber.isEmpty()){
            flight_order_No_ = ticketinfo.flightNo + "/" + ticketinfo.boardingNumber;
        }
        else if (!ticketinfo.flightNo.isEmpty() || !ticketinfo.boardingNumber.isEmpty()){
            flight_order_No_ = ticketinfo.flightNo + ticketinfo.boardingNumber;
        }
    }

//    if (result == -1){
//        flight_order_No_ = "";
//    }

    bool bErrorPlay = true;

    switch (channel) {
        case 1://1通道
            ui->pushButton_faceImage_L->setIcon(pixmap.scaled(ui->pushButton_faceImage_L->size()));
            ui->label_name_L->setText(name);
            ui->label_flightNO__L->setText(flight_order_No_);
            ui->label_seatNO__L->setText(ticketinfo.seatId);
            ui->label_cardNO__L->setText(cardId.left(14) + "\n" + cardId.mid(14));
            ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道蓝.png);}");
            ui->label_resultStamp_L->move(15,110);

            switch (transferType) {
                case 0:
                    ui->label_transferType_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
                    break;
                case 1:
                    ui->label_transferType_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
                    break;
                case 3:
                    ui->label_transferType_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
                    break;
                case 4:
                    ui->label_transferType_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
                    break;
                default:
                    ui->label_transferType_L->clear();
                    break;
            }

            switch (result){ // -1 不通过, 0-正常旅客，1-保留，2-可疑人员,显示复核异常，3-流程缺失,显示未过安检，4-二次登机
                case -1:
                    ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    if (isManualOperation){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    else {
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/识别失败.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/识别失败1.png"));
                        bErrorPlay = false;
                    }
                    break;

                case 0:
                    if (isMarked && !isManualOperation){
                        ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    else if (seatLabel == 1 && !isManualOperation){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位变更.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位变更1.png"));
                    }
                    else if (hasBaby && !isManualOperation){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/携带婴儿.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/携带婴儿1.png"));
                    }
                    else if (moreTicket && !isManualOperation){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/多次购票.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/多次购票1.png"));
                    }
                    else if (seatLabel == 2 && !isManualOperation) {
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位缺失.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位缺失1.png"));
                    }
                    else if (hasSecurityInfo){
                        ui->label_resultStamp_L->move(215,160);
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/安检验讫.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/安检验讫1.png"));
                        bErrorPlay = false;
                    }
                    else if (transferType == 0 || transferType == 3){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/中转旅客.png"));
                        ui->label_resultStamp_L->clear();
                        bErrorPlay = false;
                    }
                    else if (transferType == 1 || transferType == 4){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/过站旅客.png"));
                        ui->label_resultStamp_L->clear();
                        bErrorPlay = false;
                    }
                    break;

                case 1://保留
                    break;

                case 2:
                    ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/复核异常.png"));
                    ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/复核异常1.png"));
                    break;

                case 3:
                    ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/未过安检.png"));
                    ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/退回安检.png"));
                    break;

                case 4:
                    ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/二次登机.png"));
                    ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/二次登机1.png"));
                    if (isMarked){
                        ui->label_resultTab_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_L->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    break;

                default:
                    ui->label_resultTab_L->clear();
                    ui->label_resultStamp_L->clear();
                    break;
            }
        break;

        case 2://2通道
            ui->pushButton_faceImage_R->setIcon(pixmap.scaled(ui->pushButton_faceImage_R->size()));
            ui->label_name_R->setText(name);
            ui->label_flightNO__R->setText(flight_order_No_);
            ui->label_seatNO__R->setText(ticketinfo.seatId);
            ui->label_cardNO__R->setText(cardId.left(14) + "\n" + cardId.mid(14));
            ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道蓝.png);}");
            ui->label_resultStamp_R->move(15,110);

            switch (transferType) {
                case 0:
                    ui->label_transferType_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
                    break;
                case 1:
                    ui->label_transferType_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
                    break;
                case 3:
                    ui->label_transferType_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
                    break;
                case 4:
                    ui->label_transferType_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
                    break;
                default:
                    ui->label_transferType_R->clear();
                    break;
            }

            switch (result){ // -1 不通过, 0-正常旅客，1-保留，2-可疑人员,显示复核异常，3-流程缺失,显示未过安检，4-二次登机
                case -1:
                    ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    if (isManualOperation){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    else {
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/识别失败.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/识别失败1.png"));
                        bErrorPlay = false;
                    }
                    break;

                case 0:
                    if (isMarked && !isManualOperation){
                        ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    else if (seatLabel == 1 && !isManualOperation){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位变更.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位变更1.png"));
                    }
                    else if (hasBaby && !isManualOperation){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/携带婴儿.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/携带婴儿1.png"));
                    }
                    else if (moreTicket && !isManualOperation){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/多次购票.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/多次购票1.png"));
                    }
                    else if (seatLabel == 1 && !isManualOperation) {
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位缺失.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/座位缺失1.png"));
                    }
                    else if (hasSecurityInfo){
                        ui->label_resultStamp_R->move(215,160);
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/安检验讫.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/安检验讫1.png"));
                        bErrorPlay = false;
                    }
                    else if (transferType == 0 || transferType == 3){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/中转旅客.png"));
                        ui->label_resultStamp_R->clear();
                        bErrorPlay = false;
                    }
                    else if (transferType == 1 || transferType == 4){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/过站旅客.png"));
                        ui->label_resultStamp_R->clear();
                        bErrorPlay = false;
                    }
                    break;

                case 1://保留
                    break;

                case 2:
                    ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/复核异常.png"));
                    ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/复核异常1.png"));
                    break;

                case 3:
                    ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道红.png);}");
                    ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/未过安检.png"));
                    ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/退回安检.png"));
                    break;

                case 4:
                    ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/二次登机.png"));
                    ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/二次登机1.png"));
                    if (isMarked){
                        ui->label_resultTab_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截.png"));
                        ui->label_resultStamp_R->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.0-3.2/标记拦截1.png"));
                    }
                    break;

                default:
                    ui->label_resultTab_R->clear();
                    ui->label_resultStamp_R->clear();
                    break;
            }
            break;

        default:
            break;
    }


    if (bErrorPlay && channel ==1)
        QSound::play("sound/excp1");
    else if (bErrorPlay && channel ==2)
        QSound::play("sound/excp2");
}

void RealtimeBoarding::colorPlaneLabel(const FlightPlan& data)
{
    Q_UNUSED(data)
    if (data.twoFlightNo == m_flightPlan.twoFlightNo){
        m_flightPlan = data;
        if (HomePage::s_mode == 0){
            HomePage::s_status = m_flightPlan.status;
            HomePage::s_type = m_boardingMode;
        }
        ui->label_picture_plane->setStyleSheet("image: url(:/3实时登机/Images/3实时登机/3.0-3.2/矢量剪影飞机.png);");
        ui->label_mainFlightNO_->setStyleSheet("color: rgb(0, 228, 255);");
    }
}

void RealtimeBoarding::update_ppl_num(const content301& data)
{
    if (data.flightNo == m_flightPlan.twoFlightNo && data.flightDate == m_flightPlan.flightDate){
        m_flightPlan.faceNums=data.faceNums;
        m_flightPlan.orgDepNum=data.orgDepNum;
        m_flightPlan.midwayNum=data.midwayNum;
        m_flightPlan.transferNum=data.transferNum;
        m_flightPlan.boardingNum=data.boardingNum;

        ui->label_countBoarding->setNum(data.boardingNum);
        ui->label_countTotal->setNum(data.faceNums);
        ui->label_countStart->setNum(data.orgDepNum);
        ui->label_countMidway->setNum(data.midwayNum);
        ui->label_countTransfer->setNum(data.transferNum);
        ui->label_babyNum->setNum(data.babyNum);

    }
}

bool RealtimeBoarding::is_statrtBoarding(const FlightPlan& data)
{
    if (HomePage::s_mode == 1){//正在采集
        MessageDialog tip(this, "实时登机", QString("航班%1已经开始登机\n是否结束当前采集立即进行登机？").arg(m_flightPlan.twoFlightNo), 2);
        if (1 == tip.exec()){
            HomePage::global_instance->m_PortraitCollection->endCollect();
        }
        else return false;
    }

    if (m_isBording && (data.twoFlightNo != m_flightPlan.twoFlightNo)){
        MessageDialog msg(this, "登机确认",QString("调度系统开始登机消息：\n是否切换到该航班登机？\n航班号  %1，").arg(data.twoFlightNo),2);
        if (msg.exec() == 1){
            if (HttpAPI::instance()->Post(Cancel_Flight_Clicked, m_flightPlan.twoFlightNo, m_flightPlan.boardingGate, m_flightPlan.flightDate).serverStatus != 0){
                return false;
            }
            if (HttpAPI::instance()->Post(Other_Flight_Clicked, data.twoFlightNo, data.boardingGate, data.flightDate).serverStatus == 0){
                Return_MSG ret_2 = HttpAPI::instance()->Post(Start_Boarding_Clicked, data.twoFlightNo, data.boardingGate, data.flightDate);
            }
            else {
                MessageDialog *error = new MessageDialog(this, "错误提示", "服务器通信时出现故障\n请手动拉取该航班进行登机!", 1);
                error->setAttribute(Qt::WA_DeleteOnClose, true);
                error->show();
            }
            return false;
        }
        else return false;
    }

    m_flightPlan = data;
    m_isBording = true;
    showFlightInfo();
    changeButtonStatus(true);
    HomePage::s_status = 2;
    HomePage::s_type = m_boardingMode;
    HomePage::global_instance->on_Button_RealtimeBoarding_clicked();

    return true;
}

bool RealtimeBoarding::is_endBoarding(const FlightPlan& data)
{
    if (data.twoFlightNo != m_flightPlan.twoFlightNo){
        return false;
    }

    m_isBording = false;
    HomePage::s_status = 3;
    changeButtonStatus(false);
    clearAllBoardingInfos();

    MessageDialog *msg = new MessageDialog(HomePage::global_instance, "结束登机", QString("%1\n已经结束登机").arg(data.twoFlightNo), 1);
    msg->move(0,110);
    msg->setAttribute(Qt::WA_DeleteOnClose, true);
    msg->show();

    {//跳到人数统计
        if (0 == inquiryWidget::instance()->x()){
            inquiryWidget::instance()->closeWindow();
        }
        HomePage::global_instance->on_Button_FlightEnquires_clicked();
        HomePage::global_instance->m_FlightEnquires->ppl_statistics(data.twoFlightNo);
    }

    return true;
}

void RealtimeBoarding::handleResults_flightPlane(API_PARAM_TYPE type, void* _flightPlan)
 {
     if(type == FLIGHT_PALNE)
     {
         m_flightPlan = *static_cast<FlightPlan*>(_flightPlan);

         showFlightInfo();

         if (2 == HomePage::s_status){
             if (is_statrtBoarding(m_flightPlan)){
                 HomePage::global_instance->on_Button_RealtimeBoarding_clicked();
             }
         }
         if (3 == HomePage::s_status){
             is_endBoarding(m_flightPlan);
         }
     }
 }

int RealtimeBoarding::on_changeBoardingMod()
{
    QString currentMode;
    QString changeToMode;

    if (0 == m_boardingMode){
        currentMode = "人脸登机(默认)";
        changeToMode = "刷牌登机";
    }else{
        currentMode = "刷牌登机";
        changeToMode = "人脸登机(默认)";
    }

    QWidget *widget = new QWidget;
    QLabel *label1 = new QLabel(widget);
    label1->setGeometry(60, 30, 500, 60);
    label1->setText(QString("<font color=white size=6>当前登机模式为</font><font color=#00e4ff size=6><i>%1</i></font>").arg(currentMode));
    QLabel *label2 = new QLabel(widget);
    label2->setGeometry(60, 80, 500, 60);
    label2->setText(QString("<font color=white size=6>是否确认切换为</font><font color=#00e4ff size=6><i>%1</i></font><font color=white size=6> ？</font>").arg(changeToMode));

    MessageDialog msgDlg(this);
    msgDlg.addWidget(widget);
    if (0 == msgDlg.exec())
        return -1;

    int tmpBoardingMode = 0;
    if (m_boardingMode == 0)
        tmpBoardingMode = 1;
    else if (m_boardingMode == 1)
        tmpBoardingMode = 0;
    else {
        MessageDialog errorBoardingMode(this, "error setting", "设置登机模式错误!", 1);
        errorBoardingMode.exec();
        return -1;
    }

    if (0 != HttpAPI::instance()->pushPlan(1, m_flightPlan, 0, tmpBoardingMode, HomePage::s_collectType, HomePage::s_status).serverStatus
            && 0 != HttpAPI::instance()->pushPlan(2, m_flightPlan, 0, tmpBoardingMode, HomePage::s_collectType, HomePage::s_status).serverStatus){
        MessageDialog *fail = new MessageDialog(this, "切换登机模式", "登机模式切换失败", 1);
        fail->setAttribute(Qt::WA_DeleteOnClose, true);
        fail->show();
        return -1;
    }
    else{
        m_boardingMode = tmpBoardingMode; //切换登机模式
        HomePage::s_type = tmpBoardingMode;
        return m_boardingMode;
    }
}

 void RealtimeBoarding::on_pushButton_startBoarding_clicked()
 {
     //开始登机
     if (!m_isBording && (m_flightPlan.twoFlightNo != "- - - - - -") && (!m_flightPlan.twoFlightNo.isEmpty())){
         MessageDialog msgbox(this, "登机确认", "确认开始登机？");
         if (msgbox.exec()){
             Return_MSG ret = HttpAPI::instance()->Post(Start_Boarding_Clicked, m_flightPlan.twoFlightNo, m_flightPlan.boardingGate, m_flightPlan.flightDate);
             if (ret.curl_err_code != 0)
                 return;
             else if (ret.serverStatus != 0)
             {
                 MessageDialog msgbox(this, "错误提示", QString("开始登机失败！(%1)\n%2").arg(ret.serverStatus).arg(ret.msg), 1);
                 msgbox.exec();
             }
             else{
//                 m_isBording = true;
//                 HomePage::s_status = 2;
                 //waiting for mq msg, then go to "HomePage::recivedMQmsg()";
             }
         }
     }
 }

 void RealtimeBoarding::on_pushButton_endBoarding_clicked()
 {
     //结束登机
     if (m_isBording){
         MessageDialog msgbox(this, "登机确认", "确认结束登机？");
         if (msgbox.exec()){
             Return_MSG ret = HttpAPI::instance()->Post(End_Boarding_Clicked, m_flightPlan.twoFlightNo, m_flightPlan.boardingGate, m_flightPlan.flightDate);
             if (ret.curl_err_code != 0)
                 return;
             else if (ret.serverStatus != 0)
             {
                 MessageDialog msgbox(this, "错误提示", QString("结束登机失败！(%1)\n%2").arg(ret.serverStatus).arg(ret.msg), 1);
                 msgbox.exec();
             }
             else{
//                 m_isBording = false;
//                 HomePage::s_status = 3;
                 //waiting for mq msg, then go to "HomePage::recivedMQmsg()";
             }
         }
     }
 }

void RealtimeBoarding::on_pushButton_cancelFlight_clicked()
{
    if (m_isBording || (m_flightPlan.twoFlightNo == "- - - - - -") || (m_flightPlan.twoFlightNo.isEmpty()))
        return;

    //航班撤销
    MessageDialog msgbox(this, nullptr, "确认撤销本航班？");
    if (msgbox.exec()){
        Return_MSG ret = HttpAPI::instance()->Post(Cancel_Flight_Clicked, m_flightPlan.twoFlightNo, m_flightPlan.boardingGate, m_flightPlan.flightDate);
        if (ret.curl_err_code != 0)
            return;
        else if (ret.serverStatus == 0)
        {
            MessageDialog *msg = new MessageDialog(this, nullptr, "航班撤销成功！",1);
            msg->setAttribute(Qt::WA_DeleteOnClose, true);
            msg->show();
            //waiting for mq msg, then go to "HomePage::recivedMQmsg()";
        }
        else{
            MessageDialog msgbox(this, "错误提示", QString("服务器请求失败(%1)\n%2").arg(ret.serverStatus).arg(ret.msg), 1);
            msgbox.exec();
            return;
        }
    }
}

void RealtimeBoarding::on_pushButton_otherFlight_clicked()
{
    //其他航班
    LineEditDialog inputDlg(this);
    while (inputDlg.exec()){
        QString otherflightNo = inputDlg.getLineEditText().toUpper();

        QWidget *widget = new QWidget(&inputDlg);
        QLabel *label1 = new QLabel(widget);
        label1->setGeometry(40, 20, 310, 60);
        label1->setStyleSheet("font:26pt \"Ubuntu\";color:#ffffff;");
        label1->setText("是否新增航班：");
        QLabel *label2 = new QLabel(widget);
        label2->setGeometry(40, 90, 452, 60);
        label2->setAlignment(Qt::AlignCenter);
        label2->setStyleSheet("font:bold 36pt \"Ubuntu\";color:#ffffff;");
        label2->setText(otherflightNo);

        MessageDialog ensureDlg(this, "新增航班");
        ensureDlg.addWidget(widget);
        if (ensureDlg.exec()){
            if (otherflightNo != m_flightPlan.twoFlightNo){
                //1.查询航班状态
                Return_Flight_Plan_Param ret_flightPlan = HttpAPI::instance()->queryFlight(otherflightNo);
                if (ret_flightPlan.serverStatus == 0)
                {
                    Return_MSG ret_tmp;
                    if (ret_flightPlan.flightPlan.status == 3){
                        //航班状态 == 3, 属于已结束登机
                        MessageDialog msg(this, "其他航班", "该航班已结束登机\n确认重新拉取该航班？",2);
                        if (msg.exec()){
                            ret_tmp = HttpAPI::instance()->Post(Other_Flight_Clicked, ret_flightPlan.flightPlan.twoFlightNo, LocalSettings::instance()->value("Device/boardingGateNo").toString(), ret_flightPlan.flightPlan.flightDate);
                        }
                        else return;
                    }
                    else if (ret_flightPlan.flightPlan.status == 4){
                        //航班状态 == 4, 属于异常航班
                        MessageDialog msg(this, "其他航班", "该航班已起飞\n是否按返航模式激活该航班？",2);
                        if (msg.exec()){
                            ret_tmp = HttpAPI::instance()->Post(Exception_Flight_Clicked, ret_flightPlan.flightPlan.twoFlightNo, LocalSettings::instance()->value("Device/boardingGateNo").toString(), ret_flightPlan.flightPlan.flightDate);
                            if (ret_tmp.serverStatus == 0)
                                ret_tmp = HttpAPI::instance()->Post(Other_Flight_Clicked, ret_flightPlan.flightPlan.twoFlightNo, LocalSettings::instance()->value("Device/boardingGateNo").toString(), ret_flightPlan.flightPlan.flightDate);
                        }
                        else return;
                    }
                    else{//0,1，2状态的航班不需要提示
                        //其他状态直接拉取过来
                        ret_tmp = HttpAPI::instance()->Post(Other_Flight_Clicked, ret_flightPlan.flightPlan.twoFlightNo, LocalSettings::instance()->value("Device/boardingGateNo").toString(), ret_flightPlan.flightPlan.flightDate);
                    }

                    if (ret_tmp.serverStatus == 0)
                    {
                        MessageDialog *msg = new MessageDialog(this, "其他航班", "新增航班成功！",1);
                        msg->setAttribute(Qt::WA_DeleteOnClose, true);
                        msg->show();

                        //waiting for mq msg, then go to "HomePage::recivedMQmsg()";
                        return;
                    }
                    else if (ret_tmp.curl_err_code == 0){
                        MessageDialog msgbox(this, "新增航班", QString("新增航班失败!"), 1);
                        msgbox.exec();
                    }
                }
                else if (ret_flightPlan.curl_err_code == 0){
                    MessageDialog msgbox(this, "新增航班", QString("新增航班失败!\n没有匹配的航班!"), 1);
                    msgbox.exec();
                }
            }
            else {
                MessageDialog msg(this, nullptr, "输入航班号与当前航班相同！",1);
                msg.exec();
            }
        }
    }
}

void RealtimeBoarding::on_pushButton_pplStats_clicked()
{
    //人数统计
    if (0 == inquiryWidget::instance()->x()){
        inquiryWidget::instance()->closeWindow();
    }

    HomePage::global_instance->on_Button_FlightEnquires_clicked();
    HomePage::global_instance->m_FlightEnquires->ppl_statistics(m_flightPlan.twoFlightNo);
}

void RealtimeBoarding::on_pushButton_find_clicked()
{
    inquiryWidget::instance()->openWindow(inquiryWidget::Channel_Special);
}

void RealtimeBoarding::on_pushButton_faceImage_L_clicked()
{
    if (!m_isBording)
        return;
    if (user_left.ticket.flightNo.isEmpty() && user_left.ticket.boardingNumber.isEmpty())
        return;

    inquiryWidget::instance()->openWindow(inquiryWidget::Channel_1);
    inquiryWidget::instance()->enquiry(user_left.ticket.flightNo + "#" + user_left.ticket.boardingNumber + "#" + user_left.ticket.seatId);
}

void RealtimeBoarding::on_pushButton_faceImage_R_clicked()
{
    if (!m_isBording)
        return;
    if (user_right.ticket.flightNo.isEmpty() && user_right.ticket.boardingNumber.isEmpty())
        return;

    inquiryWidget::instance()->openWindow(inquiryWidget::Channel_2);
    inquiryWidget::instance()->enquiry(user_right.ticket.flightNo + "#" + user_right.ticket.boardingNumber + "#" + user_right.ticket.seatId);
}

void RealtimeBoarding::clearAllBoardingInfos()
{
    ui->label_countBoarding->setNum(0);
    ui->label_countTotal->setNum(0);
    ui->label_countStart->setNum(0);
    ui->label_countMidway->setNum(0);
    ui->label_countTransfer->setNum(0);
    ui->label_picture_plane->setStyleSheet("image: url(:/3实时登机/Images/3实时登机/3.0-3.2/矢量剪影飞机-拷贝.png);");
    ui->label_mainFlightNO_->setText("- - - - - -");
    ui->label_fromPlace->setText("- - - -");
    ui->label_arrivalPlace->setText("- - - -");
    ui->label_midPlace->clear();
    ui->label_boardingTime->setText("--:--");
    ui->label_departureTime->setText("--:--");
    ui->ScrollText_shareFlight->setTextList(QStringList());
    clearInfoThrough_L();
    clearInfoThrough_R();
}

void RealtimeBoarding::clearInfoThrough_L()
{
    user_left.clear();

    ui->pushButton_faceImage_L->setIcon(QIcon());
    ui->label_name_L->clear();
    ui->label_flightNO__L->clear();
    ui->label_seatNO__L->clear();
    ui->label_cardNO__L->clear();
    ui->widget_through1->setStyleSheet("#widget_through1{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道蓝.png);}");
    ui->label_transferType_L->clear();
    ui->label_resultTab_L->clear();
    ui->label_resultStamp_L->clear();
    ui->label_resultStamp_L->move(15,110);
}

void RealtimeBoarding::clearInfoThrough_R()
{
    user_right.clear();

    ui->pushButton_faceImage_R->setIcon(QIcon());
    ui->label_name_R->clear();
    ui->label_flightNO__R->clear();
    ui->label_seatNO__R->clear();
    ui->label_cardNO__R->clear();
    ui->widget_through2->setStyleSheet("#widget_through2{border-image: url(:/3实时登机/Images/3实时登机/3.0-3.2/通道蓝.png);}");
    ui->label_transferType_R->clear();
    ui->label_resultTab_R->clear();
    ui->label_resultStamp_R->clear();
    ui->label_resultStamp_R->move(15,110);}

void RealtimeBoarding::changeButtonStatus(bool isBording)
{
    if (isBording){
        ui->pushButton_startBoarding->hide();
        ui->pushButton_endBoarding->show();
        ui->pushButton_otherFlight->hide();
        ui->pushButton_find->show();
        ui->pushButton_cancelFlight->setEnabled(false);
        ui->pushButton_cancelFlight->setStyleSheet("QPushButton{background:transparent;border-radius:10px;image: url(:/3实时登机/Images/3实时登机/3.0-3.2/撤销航班-灰置.png);}");

        ui->label_picture_plane->setStyleSheet("image: url(:/3实时登机/Images/3实时登机/3.0-3.2/矢量剪影飞机.png);");
        ui->label_mainFlightNO_->setStyleSheet("color: rgb(0, 228, 255);");
    }
    else {
        ui->pushButton_startBoarding->show();
        ui->pushButton_endBoarding->hide();
        ui->pushButton_otherFlight->show();
        ui->pushButton_find->hide();
        ui->pushButton_cancelFlight->setEnabled(true);
        ui->pushButton_cancelFlight->setStyleSheet("QPushButton{background:transparent;border-radius:10px;image: url(:/3实时登机/Images/3实时登机/3.0-3.2/撤销航班.png);}"
                                                   "QPushButton:pressed{image: url(:/3实时登机/Images/3实时登机/3.0-3.2/撤销航班-拷贝.png);}");
    }
}

void RealtimeBoarding::on_pushButton_psngrInfo_L_clicked()
{
    on_pushButton_faceImage_L_clicked();
}

void RealtimeBoarding::on_pushButton_psngrInfo_R_clicked()
{
    on_pushButton_faceImage_R_clicked();
}
