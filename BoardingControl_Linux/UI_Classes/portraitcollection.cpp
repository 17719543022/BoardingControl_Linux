#include "portraitcollection.h"
#include "ui_portraitcollection.h"
#include "homepage.h"
#include "settings.h"
#include "ticketScancer/serialportser.h"
#include "ServerInterface/httpAPI.h"
#include "ServerInterface/httpServer.h"
#include "ServerInterface/IDCardRead_Recog.h"
#include <QMouseEvent>
#include <QDebug>

#define Color_Bule "color: #00e4ff;"
#define Color_Green "color: #04ff7a;"
#define Color_Red "color: #ff0000;"

PortraitCollection::PortraitCollection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PortraitCollection)
{
    ui->setupUi(this);
    setUI();
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, &PortraitCollection::on_selectionChanged);
    connect(ui->calendarWidget, &QCalendarWidget::activated, this, &PortraitCollection::on_calendarWidgetHide);
    connect(SerialPortSer::instance(TicketScanner), &SerialPortSer::readBoardingTicketResult, this, &PortraitCollection::on_ReadDataResult);
//    ui->widget_colecting->show();//
//    ui->widget_setting->hide();//
//    ui->pushButton_manualInputInfo->show();//
}

PortraitCollection::~PortraitCollection()
{
    delete ui;
}

void PortraitCollection::setUI()
{
    QTextCharFormat format;
    format.setForeground(QColor("#ffffff"));
    format.setBackground(QColor("#01406d"));
    ui->calendarWidget->setDateTextFormat(QDate::currentDate(), format);
    ui->calendarWidget_background->hide();

    ui->widget_colecting->hide();
    ui->pushButton_cancel_Colecting->show();
    ui->pushButton_start_Colecting->show();
    ui->pushButton_end_Colecting->hide();
    ui->pushButton_manualInputInfo->hide();
    ui->pushButton_release_L->hide();
    ui->pushButton_release_R->hide();
    ui->pushButton_prevent_L->hide();
    ui->pushButton_prevent_R->hide();

    ui->label_frontGround_L->hide();
    ui->label_frontGround_R->hide();
}

bool PortraitCollection::isContentComplete()
{
//    if (ui->radioButton_midWayColecting->isChecked()){
//        m_collectType = 0;
//        HomePage::s_collectType = m_collectType;
//    }
    if (ui->radioButton_suspendColecting->isChecked()){
        m_collectType = 1;
        HomePage::s_collectType = m_collectType;
    }
    else if (ui->radioButton_landedColecting->isChecked()){
        m_collectType = 2;
    }
    else{
        MessageDialog dlg(this, nullptr, "请选择采集类型！", 1);
        dlg.exec();
        return false;
    }

    if (ui->radioButton_faceColecting->isChecked()){
        m_Type_face_or_fast = 0;
        ui->toolButton_childMode_L->show();
        ui->toolButton_childMode_R->show();
    }
    else if (ui->radioButton_quickColecting->isChecked()){
        m_Type_face_or_fast = 1;
        ui->toolButton_childMode_L->hide();
        ui->toolButton_childMode_R->hide();
    }
    else{
        MessageDialog dlg(this, nullptr, "请选择采集方式！", 1);
        dlg.exec();
        return false;
    }

    if (!ui->lineEdit_flightNO_->text().isEmpty()){
        m_enquiryFlightNO = ui->lineEdit_flightNO_->text().toUpper().split(";", QString::SkipEmptyParts);
//        for (int i=0; i<m_enquiryFlightNO.size(); i++){
//            if (m_enquiryFlightNO.at(i).length() != 6){
//                MessageDialog dlg(this, nullptr, "航班号格式错误！\n长度必须为6位，并请用 ' ; ' 隔开", 1);
//                dlg.exec();
//                return false;
//            }
//        }
    }
    else{
        MessageDialog dlg(this, nullptr, "请填写航班号！", 1);
        dlg.exec();
        return false;
    }

    if (!ui->lineEdit_flightDate->text().isEmpty()){
        QString str_flightDate_ = ui->lineEdit_flightDate->text();

        if (str_flightDate_.contains("-")){
            m_enqueryFlightDate = QDate::fromString(str_flightDate_, Qt::ISODate);
        }
        else if (str_flightDate_.contains("/")){
            m_enqueryFlightDate = QDate::fromString(str_flightDate_, "yyyy/MM/dd");
        }
        else if (str_flightDate_.contains(".")){
            m_enqueryFlightDate = QDate::fromString(str_flightDate_, "yyyy.MM.dd");
        }

        if (m_enqueryFlightDate.isValid()){
            if (std::abs(m_enqueryFlightDate.daysTo(QDate::currentDate())) >= 7){
                MessageDialog dlg(this, nullptr, QString("航班日期与今天相差过大，确认吗？\n今天：%1\n选择日期：%2").arg((QDate::currentDate().toString(Qt::ISODate))).arg(m_enqueryFlightDate.toString(Qt::ISODate)), 2);
                if (!dlg.exec()) return false;
            }
        }
        else{
            MessageDialog dlg(this, nullptr, "航班日期无效 或 格式不正确！", 1);
            dlg.exec();
            return false;
        }
    }
    else{
        MessageDialog dlg(this, nullptr, "请选择航班日期！", 1);
        dlg.exec();
        return false;
    }

    return true;
}

void PortraitCollection::showFlightInfo()
{
    ui->label_countColected->setText(QString::number(m_collect_ppl_count));
    if (!m_flightPlan.twoFlightNo.isEmpty())
        ui->label_mainFlightNO_->setText(m_flightPlan.twoFlightNo);
    else ui->label_mainFlightNO_->setText("- - - - - -");

    if (!m_flightPlan.depAirportName.isEmpty())
        ui->label_fromPlace->setText(m_flightPlan.depAirportName);
    else ui->label_fromPlace->setText("- - - -");

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

    ui->ScrollText_shareFlight->setInterval_scrollTimer(2000);
    ui->ScrollText_shareFlight->setInterval_animation(1000);
    if (!m_flightPlan.shareFltno.isEmpty()){
        ui->ScrollText_shareFlight->setTextList(m_flightPlan.shareFltno);
        ui->ScrollText_shareFlight->setScrollStat(true);
    } else {
        ui->ScrollText_shareFlight->setTextList(QStringList("- - - -"));
        ui->ScrollText_shareFlight->setScrollStat(false);
    }
}

void PortraitCollection::showCollectResult(int channel, int result, Collect_Info &info)
{
    QLabel *label_faceImage = nullptr;
    QLabel *label_flightNO = nullptr;
    QLabel *label_boardingNO = nullptr;
    QLabel *label_seatNO = nullptr;
    QLabel *label_cardID = nullptr;
    QLabel *label_colectResult = nullptr;
    QPushButton *pushButton_release = nullptr;
    QPushButton *pushButton_prevent = nullptr;

    bool *isForceTakephoto = nullptr;

    if (channel == 1){
        label_faceImage = ui->label_faceImage_L;
        label_flightNO = ui->label_flightNO_L;
        label_boardingNO = ui->label_boardingNO_L;
        label_seatNO = ui->label_seatNO_L;
        label_cardID = ui->label_cardID_L;
        label_colectResult = ui->label_colectResult_L;
        pushButton_release = ui->pushButton_release_L;
        pushButton_prevent = ui->pushButton_prevent_L;
        isForceTakephoto = &isForceTakephoto_L;
    }
    else {
        label_faceImage = ui->label_faceImage_R;
        label_flightNO = ui->label_flightNO_R;
        label_boardingNO = ui->label_boardingNO_R;
        label_seatNO = ui->label_seatNO_R;
        label_cardID = ui->label_cardID_R;
        label_colectResult = ui->label_colectResult_R;
        pushButton_release = ui->pushButton_release_R;
        pushButton_prevent = ui->pushButton_prevent_R;
        isForceTakephoto = &isForceTakephoto_R;
    }

    QPixmap Image;
    if (!info.faceImage.isEmpty() && info.isBaby == 0)
        Image.loadFromData(info.faceImage);
    else if (!info.largePhoto.isEmpty())
        Image.loadFromData(info.largePhoto);

    label_faceImage->setPixmap(Image.scaled(label_faceImage->size()));
    label_flightNO->setText(info.flightNo + " " +info.babyFlightNo);
    label_boardingNO->setText(info.boardingNumber + " " +info.babyBoardingNumber);
    label_seatNO->setText(info.seatId + " " +info.babySeatId);
    label_cardID->setText(info.cardId + " " +info.babyCardId);

    //航班异常
    if ((!info.flightNo.isEmpty() && m_flightPlan.twoFlightNo != info.flightNo && !m_flightPlan.shareFltno.contains(info.flightNo))
            || (!info.babyFlightNo.isEmpty() && m_flightPlan.twoFlightNo != info.babyFlightNo && !m_flightPlan.shareFltno.contains(info.babyFlightNo))){
        label_colectResult->setStyleSheet(Color_Red);
        label_colectResult->setText("航班异常");
        pushButton_release->setVisible(false);
        pushButton_prevent->setVisible(true);
        *isForceTakephoto = false;
    }

    switch(result){
    case 0: //成功
        label_colectResult->setStyleSheet(Color_Green);
        label_colectResult->setText("采集成功");
        pushButton_release->setVisible(false);
        pushButton_prevent->setVisible(false);
        *isForceTakephoto = false;
        break;
    case 1: //戴口罩
        label_colectResult->setStyleSheet(Color_Bule);
        label_colectResult->setText("戴有口罩");
        pushButton_release->setVisible(true);
        pushButton_prevent->setVisible(true);
        *isForceTakephoto = true;
        break;
    case 2: //2.对失败（带证件照）
        label_colectResult->setStyleSheet(Color_Red);
        if (info.cardId.isEmpty())
            label_colectResult->setText("采集失败");
        else label_colectResult->setText("比对失败");
        pushButton_release->setVisible(true);
        pushButton_prevent->setVisible(true);
        *isForceTakephoto = true;
        break;
    case 3: //3.抓拍超时
        label_colectResult->setStyleSheet(Color_Red);
        if (info.cardId.isEmpty())
            label_colectResult->setText("采集失败");
        else label_colectResult->setText("比对失败");
        pushButton_release->setVisible(true);
        pushButton_prevent->setVisible(true);
        *isForceTakephoto = true;
        break;
    default:
        break;
    }
}

void PortraitCollection::updateCollectCount(Collect_Info &info)
{
    if (info.isBaby == 0){
        siglePPLInfo_judgeExsist adult;

        adult.setAdult(info);
        if (!m_all_siglePPLInfos.contains(adult)){
            m_all_siglePPLInfos.append(adult);
            ui->label_countColected->setNum(++m_collect_ppl_count);//采用的本地累加人数方式
        }
    }
    else if (info.isBaby == 1){
        siglePPLInfo_judgeExsist adult;
        siglePPLInfo_judgeExsist baby;
        adult.setAdult(info);
        baby.setBaby(info);

        if (!m_all_siglePPLInfos.contains(adult)){
            m_all_siglePPLInfos.append(adult);
            ui->label_countColected->setNum(++m_collect_ppl_count);//采用的本地累加人数方式
        }
        if (!m_all_siglePPLInfos.contains(baby)){
            m_all_siglePPLInfos.append(baby);
            ui->label_countColected->setNum(++m_collect_ppl_count);//采用的本地累加人数方式

        }
    }
}


void PortraitCollection::clearCurrentCollectInfo(ChannelId id)
{
    switch (id) {
    case Channel_L:
        isForceTakephoto_L = false;
        m_currentInfo_L = Collect_Info();

        ui->pushButton_release_L->setVisible(false);
        ui->pushButton_prevent_L->setVisible(false);
        //        ui->label_colectResult_L->setStyleSheet(Color_Green);
        ui->label_colectResult_L->clear();
        ui->label_faceImage_L->clear();
        ui->label_flightNO_L->clear();
        ui->label_boardingNO_L->clear();
        ui->label_seatNO_L->clear();
        ui->label_cardID_L->clear();
        break;
    case Channel_R:
        isForceTakephoto_R = false;
        m_currentInfo_R = Collect_Info();

        ui->pushButton_release_R->setVisible(false);
        ui->pushButton_prevent_R->setVisible(false);
        //        ui->label_colectResult_R->setStyleSheet(Color_Green);
        ui->label_colectResult_R->clear();
        ui->label_faceImage_R->clear();
        ui->label_flightNO_R->clear();
        ui->label_boardingNO_R->clear();
        ui->label_seatNO_R->clear();
        ui->label_cardID_R->clear();
        break;
    }
}

void PortraitCollection::childButtonClicked(ChannelId channel)
{
    QToolButton *toolButton_childMode = nullptr;

    switch (channel) {
    case Channel_L:
        toolButton_childMode = ui->toolButton_childMode_L;
        break;
    case Channel_R:
        toolButton_childMode = ui->toolButton_childMode_R;
        break;
    }

    if (HomePage::s_mode != 1 || HomePage::s_status != 2){
        MessageDialog isStart(this, "开始采集", "还没有开始采集\n是否开始？", 2);
        if (1 == isStart.exec())
            on_pushButton_start_Colecting_clicked();
        else return;
    }

    m_adultTicket = BoardingTicketInfo();
    m_babyTicket = BoardingTicketInfo();

    MessageDialog tmpDlg1(this, nullptr, "请刷一张登机牌", 0);
    //链接刷登机的信号
    int ret_dlg = 0;
    connect(this, &PortraitCollection::recivedTicketInfo_adult, &tmpDlg1, &MessageDialog::on_pushButton_YES_clicked);
    connect(this, &PortraitCollection::recivedTicketInfo_baby, &tmpDlg1, &MessageDialog::on_pushButton_YES_clicked);
    ret_dlg = tmpDlg1.exec();
    disconnect(this, &PortraitCollection::recivedTicketInfo_adult, &tmpDlg1, &MessageDialog::on_pushButton_YES_clicked);
    disconnect(this, &PortraitCollection::recivedTicketInfo_baby, &tmpDlg1, &MessageDialog::on_pushButton_YES_clicked);

    if (0 == ret_dlg){
        toolButton_childMode->setChecked(false);
        return;
    }

    if (!m_adultTicket.flightNo.isEmpty()){//如果刚才刷的是监护人登机牌
        MessageDialog babyDlg(this, nullptr, "请刷婴儿登机牌！", 0);
        connect(this, &PortraitCollection::recivedTicketInfo_baby, &babyDlg, &MessageDialog::on_pushButton_YES_clicked);
        ret_dlg = babyDlg.exec();
        disconnect(this, &PortraitCollection::recivedTicketInfo_baby, &babyDlg, &MessageDialog::on_pushButton_YES_clicked);
        if (0 == ret_dlg){
            toolButton_childMode->setChecked(false);
            return;
        }
    }
    else if (!m_babyTicket.flightNo.isEmpty()){//如果刚才刷的是婴儿登机牌
        MessageDialog adultDlg(this, nullptr, "请刷监护人登机牌！", 0);
        connect(this, &PortraitCollection::recivedTicketInfo_adult, &adultDlg, &MessageDialog::on_pushButton_YES_clicked);
        ret_dlg = adultDlg.exec();
        disconnect(this, &PortraitCollection::recivedTicketInfo_adult, &adultDlg, &MessageDialog::on_pushButton_YES_clicked);
        if (0 == ret_dlg){
            toolButton_childMode->setChecked(false);
            return;
        }
    }

    clearCurrentCollectInfo(channel);
    ticket_manualPass(channel);
    toolButton_childMode->setChecked(false);
}


int PortraitCollection::ticket_manualPass(ChannelId channel)
{
    //获取读卡器的证件信息
    Collect_Info info;
    info.mainFlightNo = m_flightPlan.twoFlightNo;
    info.flightNo = m_adultTicket.flightNo;
    info.flightDay = m_adultTicket.flightDay;
    info.seatId = m_adultTicket.seatId;
    info.boardingNumber = m_adultTicket.boardingNumber;
    info.startPort = m_adultTicket.startPort;
    info.endPort = m_adultTicket.endPort;
    info.babyFlightNo = m_babyTicket.flightNo;
    info.babyFlightDay = m_babyTicket.flightDay;
    info.babySeatId = m_babyTicket.seatId;
    info.babyBoardingNumber = m_babyTicket.boardingNumber;
    info.babyStartPort = m_babyTicket.startPort;
    info.babyEndPort = m_babyTicket.endPort;

    info.isBaby = 1;
    int ret = -1;
    switch (m_collectType) {
    case 0:
        info.sourceType = 0;
        info.babySourceType= 0;
        break;
    case 1:
        info.sourceType = 1;
        info.babySourceType= 1;
        break;
    case 2:
        info.sourceType = 2;
        info.babySourceType=2;
        break;
    default:
        break;
    }
    if (m_Type_face_or_fast == 0){
        ret = HttpAPI::instance()->CollectingMode_ManualPass(channel, info, 0).serverStatus;
    }
    else if (m_Type_face_or_fast == 1){
        ret = HttpAPI::instance()->CollectingMode_ManualPass(channel, info, 2).serverStatus;
    }
    if (0 != ret)
    {
        m_adultTicket = BoardingTicketInfo();
        m_babyTicket = BoardingTicketInfo();
        return -1;
    }
    m_adultTicket = BoardingTicketInfo();
    m_babyTicket = BoardingTicketInfo();
    return 0;
}

void PortraitCollection::endCollect()
{
    int ret_1 = HttpAPI::instance()->pushPlan(1,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 3).serverStatus;
    int ret_2 = HttpAPI::instance()->pushPlan(2,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 3).serverStatus;
    if (0 != ret_1 && 0 != ret_2){
        //给两个闸机都推送失败
    }

    clearCurrentCollectInfo(Channel_L);
    clearCurrentCollectInfo(Channel_R);

    m_all_siglePPLInfos.clear();
    m_collect_ppl_count = 0;

    ui->pushButton_manualInputInfo->hide();
    ui->pushButton_cancel_Colecting->show();
    ui->pushButton_start_Colecting->show();
    ui->pushButton_end_Colecting->hide();

    on_pushButton_cancel_Colecting_clicked();
}

void PortraitCollection::updateCurrentDate()
{
    ui->lineEdit_flightDate->setText(QDate::currentDate().toString(Qt::ISODate));
}

void PortraitCollection::updtCrrntCllctInfo(int channel, QJsonObject json)
{
    Collect_Info *info = nullptr;
    if (channel == 1)
        info = &m_currentInfo_L;
    else info = &m_currentInfo_R;

    if (json["netStatus"].toInt() != 1) //闸机和服务器的网络状态; 0-故障，1-OK;
    {
        emit GateNetStat("采集失败", "闸机与服务器网络通信异常！");
        if (channel == 1){
            ui->label_colectResult_L->setStyleSheet(Color_Red);
            ui->label_colectResult_L->setText("网络异常");
    //        ui->pushButton_release_L->setVisible(true);
        }
        else {
            ui->label_colectResult_R->setStyleSheet(Color_Red);
            ui->label_colectResult_R->setText("网络异常");
    //        ui->pushButton_release_R->setVisible(true);
        }
        return;
    }

    //1.解析所需要字段;
    info->flightNo = json.value("flightNo").toString();
    info->flightDay = json.value("flightDay").toString();
    info->boardingNumber = json.value("boardingNumber").toString();
    info->seatId = json.value("seatId").toString();
    info->startPort = json.value("startPort").toString();
    info->endPort = json.value("endPort").toString();
    info->cardId = json.value("cardId").toString();
    info->nameZh = json.value("nameZh").toString();
    info->cardPhoto = QByteArray::fromBase64(json.value("cardPhoto").toString().toLatin1());
    info->faceImage = QByteArray::fromBase64(json.value("faceImage").toString().toLatin1());
    info->largePhoto = QByteArray::fromBase64(json.value("largePhoto").toString().toLatin1());
    info->sourceType = json.value("sourceType").toInt();
    info->mainFlightNo = json.value("mainFlightNo").toString();
    info->isBaby = json.value("isBaby").toInt();
    info->babyFlightNo = json.value("babyFlightNo").toString();
    info->babyFlightDay = json.value("babyFlightDay").toString();
    info->babyBoardingNumber = json.value("babyBoardingNumber").toString();
    info->babySeatId = json.value("babySeatId").toString();
    info->babyStartPort = json.value("babyStartPort").toString();
    info->babyEndPort = json.value("babyEndPort").toString();
    info->babyCardId = json.value("babyCardId").toString();
    info->babyNameZh = json.value("babyNameZh").toString();
    info->babySourceType = json.value("babyBoardingNumber").toInt();

    int collectStep = json["collectStep"].toInt(0); //采集步骤：0-采集模式下第一道门推送预先采集信息，不上传服务器，用于中控台预先显示，同时推送离港系统；1-采集模式下第二道门推送采集结果信息，上传服务器，用于中控台采集结果显示，不推送离港系统
    int result = json["result"].toInt(-1); //人脸模式下采集结果 0-成功，1-戴口罩，2-比对失败（带证件照）,3-自动抓拍超时。刷票模式下，0-成功

    if (m_collectType == 1 && collectStep == 0){
        //传输离港信息;
        if (info->cardId.isEmpty()){
            BoardingTicketInfo adultInfo;
            adultInfo.seatId = info->seatId;
            adultInfo.endPort = info->endPort;
            adultInfo.flightNo = info->flightNo;
            adultInfo.flightDay = info->flightDay;
            adultInfo.startPort = info->startPort;
            adultInfo.boardingNumber = info->boardingNumber;
            QMetaObject::invokeMethod(SerialPortSer::instance(DepartureInfoSender), "sendDepartureInfo", Qt::QueuedConnection, Q_ARG(BoardingTicketInfo, adultInfo));
        }
        //传输离港信息;
        if (info->isBaby == 1 && info->babyCardId.isEmpty()){
            BoardingTicketInfo babyInfo;
            babyInfo.seatId = info->babySeatId;
            babyInfo.endPort = info->babyEndPort;
            babyInfo.flightNo = info->babyFlightNo;
            babyInfo.flightDay = info->babyFlightDay;
            babyInfo.startPort = info->babyStartPort;
            babyInfo.boardingNumber = info->babyBoardingNumber;
            QMetaObject::invokeMethod(SerialPortSer::instance(DepartureInfoSender), "sendDepartureInfo", Qt::QueuedConnection, Q_ARG(BoardingTicketInfo, babyInfo));
        }
    }
    else if (collectStep == 1){
        showCollectResult(channel, result, *info);
        if (result == 0){
            updateCollectCount(*info);
        }
    }
    else {// param error
        return;
    }
}

void PortraitCollection::on_ReadDataResult(const BoardingTicketInfo& ticketInfo)
{
    if (!ui->toolButton_childMode_L->isChecked() && !ui->toolButton_childMode_R->isChecked()){
        if (ui->lineEdit_flightNO_->hasFocus()){
            ui->lineEdit_flightNO_->setText(ticketInfo.flightNo);
        }
        return;
    }

    //航班异常
    if (exceptionFlightNo_dlg == nullptr){
        exceptionFlightNo_dlg = new MessageDialog(this, "异常航班", "机票航班不在本次采集的航班之内！", 1);
    }

    if ((ticketInfo.flightNo != m_flightPlan.twoFlightNo && !m_flightPlan.shareFltno.contains(ticketInfo.flightNo))
            || (ticketInfo.flightDay != m_flightPlan.flightDate.right(2))){
        exceptionFlightNo_dlg->raise();
        exceptionFlightNo_dlg->show();
        return;
    }

    if  (ticketInfo.seatId == "INF"){
        m_babyTicket = ticketInfo;
        emit recivedTicketInfo_baby();
    }
    else {
        m_adultTicket = ticketInfo;
        emit recivedTicketInfo_adult();
    }
    exceptionFlightNo_dlg->hide();
}


void PortraitCollection::on_selectionChanged(){
    QDate selectionDate = ui->calendarWidget->selectedDate();
    ui->lineEdit_flightDate->setText(selectionDate.toString(Qt::ISODate));
}

void PortraitCollection::on_calendarWidgetHide()
{
    QDate selectionDate = ui->calendarWidget->selectedDate();
    ui->lineEdit_flightDate->setText(selectionDate.toString(Qt::ISODate));
    ui->calendarWidget_background->hide();
}

void PortraitCollection::on_pushButton_calendar_clicked()
{
    ui->calendarWidget_background->show();
}

void PortraitCollection::on_pushButton_keyboard_clicked()
{
//    QString keyboardName = LocalSettings::instance()->value("System/defaultKeyBoardTool", "onboard").toString();
//    try {
//        int ret = -1;
//        if (!isKeyboardOpen){
//            ui->lineEdit_flightNO_->setFocus();
//            ret = system(strcat(keyboardName.toLatin1().data(), "&"));
//        }else {
//            this->clearFocus();
//            char cmd[20] = "pkill ";
//            ret = system(strcat(cmd, keyboardName.toLatin1().data()));
//        }
//        if (-1 == ret){
//            qWarning() << QString("open keyboard <%1> failed!").arg(keyboardName);
//            return;
//        }
//    } catch (std::exception &exp) {
//        qWarning() << QString("reciving an error while using system keyboard <%1>\n%2").arg(keyboardName).arg(exp.what());
//        return;
//    }
//    isKeyboardOpen = !isKeyboardOpen;
}

void PortraitCollection::on_pushButton_commit_clicked()
{
    if (HomePage::s_mode == 0 && HomePage::s_status == 2){
        MessageDialog tip(this, "采集模式", "当前有航班正在登机\n请结束登机之后再进入采集模式", 1);
        tip.exec();
        return;
    }
    //校验信息填写的完整性
    if (!isContentComplete()) return;
    //服务器查询是否有当前航班信息
    //1.查询航班状态
    Return_Flight_Plan_Param ret_info = HttpAPI::instance()->queryFlight(m_enquiryFlightNO.at(0), m_enqueryFlightDate);
    if (ret_info.curl_err_code != 0) return;
    else if ((ret_info.serverStatus != 0 && ret_info.serverStatus != -1) || ret_info.flightPlan.flightDate!=m_enqueryFlightDate.toString("yyyy-MM-dd"))//未查到匹配的航班
    {
        MessageDialog msgbox(this, "人像采集",QString("%1\n未查询到该航班信息\n是否强制建库？") .arg(m_enquiryFlightNO.at(0)), 2);
        if (msgbox.exec()){
            m_flightPlan.boardingGate = LocalSettings::instance()->value("Device/boardingGateNo").toString();
            m_flightPlan.twoFlightNo = m_enquiryFlightNO.at(0);
            m_flightPlan.flightDate = m_enqueryFlightDate.toString("yyyy-MM-dd");
            m_flightPlan.shareFltno = m_enquiryFlightNO;
            m_flightPlan.shareFltno.removeFirst();
        }
        else return;
    }
    else{    //查询到了
        m_flightPlan = ret_info.flightPlan;
        m_flightPlan.boardingGate = LocalSettings::instance()->value("Device/boardingGateNo").toString();
    }
    //change to collection mode;
    int ret_1 = HttpAPI::instance()->pushPlan(1,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 1).serverStatus;
    int ret_2 = HttpAPI::instance()->pushPlan(2,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 1).serverStatus;
    if (0 != ret_1 && 0 != ret_2){
        return;
    }
    else {
        HomePage::s_mode = 1;
        HomePage::s_collectType = m_collectType;
        HomePage::s_type = m_Type_face_or_fast;
        HomePage::s_status = 1;

        ui->widget_setting->hide();
        ui->widget_colecting->show();
        m_all_siglePPLInfos.clear();
        showFlightInfo();
    }
}

void PortraitCollection::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton){
        if (!ui->calendarWidget->underMouse()){
            ui->calendarWidget_background->hide();
        }
    }
}

void PortraitCollection::on_pushButton_cancel_Colecting_clicked()
{
    m_flightPlan = FlightPlan();
    showFlightInfo();

    ui->lineEdit_flightNO_->clear();
    ui->widget_setting->show();
    ui->widget_colecting->hide();

    HomePage::s_mode = 0;
    HomePage::s_collectType = m_collectType;
    HomePage::s_type = HomePage::global_instance->m_RealtimeBoarding->m_boardingMode;
    HomePage::s_status = 1;

    HomePage::global_instance->on_Button_RealtimeBoarding_clicked();//for Push flightPlan
    HomePage::global_instance->on_Button_HomePage_clicked();
}

void PortraitCollection::on_pushButton_start_Colecting_clicked()
{
    int ret_1 = HttpAPI::instance()->pushPlan(1,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 2).serverStatus;
    int ret_2 = HttpAPI::instance()->pushPlan(2,m_flightPlan, 1, m_Type_face_or_fast, m_collectType, 2).serverStatus;
    if (0 != ret_1 && 0 != ret_2){
        return;
    }
    else{
        HomePage::s_mode = 1;
        HomePage::s_collectType = m_collectType;
        HomePage::s_type = m_Type_face_or_fast;
        HomePage::s_status = 2;

        ui->pushButton_manualInputInfo->show();
        ui->pushButton_cancel_Colecting->hide();
        ui->pushButton_start_Colecting->hide();
        ui->pushButton_end_Colecting->show();
    }
}

void PortraitCollection::on_pushButton_end_Colecting_clicked()
{
    MessageDialog chiledDlg(this, "结束采集", "是否确认？", 2);
    if (1 == chiledDlg.exec()) {
        this->endCollect();
    }
}

void PortraitCollection::on_pushButton_manualInputInfo_clicked()
{
    ChannelId channelId = LocalSettings::instance()->value("Device/collectionModeDefaultChannel").toInt() == 1
            ? ChannelId(LocalSettings::instance()->value("Device/collectionModeDefaultChannel").toInt()) : Channel_L;

    LineEditDialog infoDlg(this);
    infoDlg.setLineEdit_PlaceholderText("请录入证件号或机票信息");
    infoDlg.setTitle("手动录入信息");
    connect(IDCardLoader::instance(), &IDCardLoader::readOK, &infoDlg, &LineEditDialog::on_IDCardReadOK);
    connect(SerialPortSer::instance(TicketScanner), &SerialPortSer::readBoardingTicketResult, &infoDlg, &LineEditDialog::on_TicketRead);

    infoDlg.show();
    while (infoDlg.exec()){

        Collect_Info info;
        QString lineText = infoDlg.getLineEditText().toUpper();

        info.mainFlightNo = m_flightPlan.twoFlightNo;
        if (!lineText.contains("#")){
            info.flightNo = m_flightPlan.twoFlightNo;
            info.flightDay = m_flightPlan.flightDate.right(2);
            info.cardId = lineText;
            info.nameZh = infoDlg.IDcard_NameZh;
            info.cardPhoto = infoDlg.IDCard_Img;
        }
        else {
            //出发点＃到达站＃航班号＃航班日期＃序号＃座位号
            info.startPort = lineText.section("#",0,0);
            info.endPort = lineText.section("#",1,1);
            info.flightNo = lineText.section("#",2,2);
            info.flightDay = lineText.section("#",3,3);
            info.boardingNumber = lineText.section("#",4,4);
            info.seatId = lineText.section("#",5,5);

            if (info.startPort.isEmpty() || info.endPort.isEmpty() || info.flightNo.isEmpty()
                    || info.flightDay.isEmpty() || info.boardingNumber.isEmpty() ||info.seatId.isEmpty()){
                MessageDialog msg(this, "机票格式错误", "请按照格式补全信息：\n\"始发＃终点＃航班＃日期＃序号＃座位\"", 1);
                msg.exec();
                continue;
            }
        }

        clearCurrentCollectInfo(channelId);

        switch (m_collectType) {
        case 0:
            info.sourceType =0;
            info.babySourceType =0;
            break;
        case 1:
            info.sourceType =1;
            info.babySourceType =1;
            break;
        case 2:
            info.sourceType = 2;
            info.babySourceType =2;
            break;
        default:
            break;
        }

        if (m_Type_face_or_fast == 0){
            HttpAPI::instance()->CollectingMode_ManualPass(channelId, info, 0);
        }
        else if (m_Type_face_or_fast == 1){
            HttpAPI::instance()->CollectingMode_ManualPass(channelId, info, 2);
        }

        break;
    }
}

void PortraitCollection::on_toolButton_childMode_R_clicked(bool checked)
{
    if (!checked)
        return;

    childButtonClicked(Channel_R);
}

void PortraitCollection::on_toolButton_childMode_L_clicked(bool checked)
{
    if (!checked)
        return;

    childButtonClicked(Channel_L);
}

void PortraitCollection::on_pushButton_release_R_clicked()
{
    m_currentInfo_R.mainFlightNo = m_flightPlan.twoFlightNo;

    switch (m_collectType) {
    case 0:
        m_currentInfo_R.sourceType =3;
        m_currentInfo_R.babySourceType=3;
        break;
    case 1:
        m_currentInfo_R.sourceType =4;
        m_currentInfo_R.babySourceType=4;
        break;
    case 2:
        m_currentInfo_R.sourceType = 5;
        m_currentInfo_R.babySourceType=5;
        break;
    default:
        break;
    }

    int ret = -1;

    if (isForceTakephoto_R)
        ret = HttpAPI::instance()->CollectingMode_ManualPass(Channel_R, m_currentInfo_R, 1).serverStatus;
    else ret = HttpAPI::instance()->CollectingMode_ManualPass(Channel_R, m_currentInfo_R, 0).serverStatus;
    if (0 == ret)
    {
        clearCurrentCollectInfo(Channel_R);
    }
}

void PortraitCollection::on_pushButton_release_L_clicked()
{
    m_currentInfo_L.mainFlightNo = m_flightPlan.twoFlightNo;

    switch (m_collectType) {
    case 0:
        m_currentInfo_L.sourceType =3;
        m_currentInfo_L.babySourceType=3;
        break;
    case 1:
        m_currentInfo_L.sourceType =4;
        m_currentInfo_L.babySourceType=4;
        break;
    case 2:
        m_currentInfo_L.sourceType = 5;
        m_currentInfo_L.babySourceType=5;
        break;
    default:
        break;
    }

    int ret = -1;

    if (isForceTakephoto_L)
        ret = HttpAPI::instance()->CollectingMode_ManualPass(Channel_L, m_currentInfo_L, 1).serverStatus;
    else ret = HttpAPI::instance()->CollectingMode_ManualPass(Channel_L, m_currentInfo_L, 0).serverStatus;
    if (0 == ret)
    {
        clearCurrentCollectInfo(Channel_L);
    }
}

void PortraitCollection::on_pushButton_prevent_R_clicked()
{
    HomePage::global_instance->on_Button_A2_clicked();
}

void PortraitCollection::on_pushButton_prevent_L_clicked()
{
    HomePage::global_instance->on_Button_A1_clicked();
}
