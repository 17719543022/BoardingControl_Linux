#include "inquiryWidget.h"
#include "ui_inquiryWidget.h"
#include "UI_Classes/photoButton.h"

#include "settings.h"
#include "homepage.h"
#include "ServerInterface/httpAPI.h"
#include "ticketScancer/serialportser.h"
#include "ServerInterface/IDCardRead_Recog.h"

#include <QTimeLine>
#include <QBuffer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>


inquiryWidget *inquiryWidget::m_pInstance = nullptr;
inquiryWidget::CGarbo inquiryWidget::Garbo;

inquiryWidget::inquiryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inquiryWidget)
{
    ui->setupUi(this);

    setUI();
    initFrame();
    initNetManager();
    connect(SerialPortSer::instance(TicketScanner), &SerialPortSer::readBoardingTicketResult, this, &inquiryWidget::on_ReadTicketResult);
    connect(IDCardLoader::instance(), &IDCardLoader::readOK, this, &inquiryWidget::on_IDCardReadInfo);
}

inquiryWidget::~inquiryWidget()
{
    if (securityImg != nullptr){
        delete securityImg;
        securityImg = nullptr;
    }
    if (securityStat != nullptr){
        delete securityStat;
        securityStat = nullptr;
    }
    if (recheckImg != nullptr){
        delete recheckImg;
        recheckImg = nullptr;
    }
    if (recheckStat != nullptr){
        delete recheckStat;
        recheckStat = nullptr;
    }
    if (transferImg != nullptr){
        delete transferImg;
        transferImg = nullptr;
    }
    if (transferStat != nullptr){
        delete transferStat;
        transferStat = nullptr;
    }
    if (boardingImg != nullptr){
        delete boardingImg;
        boardingImg = nullptr;
    }
    if (boardingStat != nullptr){
        delete boardingStat;
        boardingStat = nullptr;
    }
    if (cancelTicket_security != nullptr){
        delete cancelTicket_security;
        cancelTicket_security = nullptr;
    }
    if (cancelTicket_review != nullptr){
        delete cancelTicket_review;
        cancelTicket_review = nullptr;
    }
    delete ui;

    //注意:这句很关键,单例如果在外部通过qt的setParent父类销毁时作为子类会被Qt优先销毁,
    //但是Qt父子关系销毁的对象没有置空指针;
    //而程序结束时CGarbo（static）也会自动判断是否销毁此单例,所以必须手动置空指针;
    m_pInstance = nullptr;
    //在任何保证只能通过instance()接口进入的单例模式的析构函数中均可将指针置空；预防耶指针；
}

void inquiryWidget::setUI()
{
    this->move(800,0);

    ui->widget_pass_or_prevent->hide();
    ui->widget_choice_channel->hide();
    ui-> widget_choice_ppl->hide();

    securityImg = new QLabel;
    securityImg->setFixedSize(170,209);
    securityStat = new QLabel;
    securityStat->setFixedSize(170,50);
    recheckImg = new QLabel;
    recheckImg->setFixedSize(170,209);
    recheckStat = new QLabel;
    recheckStat->setFixedSize(170,50);
    transferImg = new QLabel;
    transferImg->setFixedSize(170,209);
    transferStat = new QLabel;
    transferStat->setFixedSize(170,50);
    boardingImg = new QLabel;
    boardingImg->setFixedSize(170,209);
    boardingStat = new QLabel;
    boardingStat->setFixedSize(170,50);

    if (cancelTicket_security == nullptr){
        cancelTicket_security = new QLabel(securityImg);
        cancelTicket_security->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/值机取消-斜章.png"));
        cancelTicket_security->setGeometry(0,38,170,133);
        cancelTicket_security->hide();
    }
    if (cancelTicket_review == nullptr){
        cancelTicket_review = new QLabel(recheckImg);
        cancelTicket_review->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/值机取消-斜章.png"));
        cancelTicket_review->setGeometry(0,38,170,133);
        cancelTicket_review->hide();
    }
}

void inquiryWidget::resetEnquiryInfo()
{
    clearSelectPplLayout();

    while (!ui->Layout_result->isEmpty()){
        ui->Layout_result->removeItem(ui->Layout_result->itemAt(0));
    }

    securityImg->clear();
    securityStat->clear();
    recheckImg->clear();
    recheckStat->clear();
    transferImg->clear();
    transferStat->clear();
    boardingImg->clear();
    boardingStat->clear();
    cancelTicket_security->hide();
    cancelTicket_review->hide();

    ui->label_name->clear();
    ui->label_idNo_->clear();
    ui->label_flightNo_->clear();
    ui->label_orderNo_->clear();
    ui->label_seatNo_->clear();
    ui->label_boardingGateNo_->clear();

    ui->widget_choice_ppl->hide();
    ui->widget_pass_or_prevent->hide();
    ui->widget_choice_channel->hide();
    ui->pushButton_pass->hide();
    ui->pushButton_prevent->hide();

    m_userInfo.init();
}

void inquiryWidget::initFrame()
{
    timeLine = new QTimeLine(200, this);
    timeLine->setFrameRange(800, 0);
    connect(timeLine, &QTimeLine::frameChanged, [=](int f){
        this->move(f,0);//从 800>>0 移动;
    });
}

void inquiryWidget::initNetManager()
{
    netPicture_securityImg = new QNetworkAccessManager(this); //QT += network
    netPicture_recheckImg = new QNetworkAccessManager(this);
    netPicture_transferImg = new QNetworkAccessManager(this);
    netPicture_boardingImg = new QNetworkAccessManager(this);

    connect(netPicture_securityImg, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_replyFinished(QNetworkReply*)));
    connect(netPicture_recheckImg, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_replyFinished(QNetworkReply*)));
    connect(netPicture_transferImg, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_replyFinished(QNetworkReply*)));
    connect(netPicture_boardingImg, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_replyFinished(QNetworkReply*)));
}

int inquiryWidget::enquiry_ppl(const QString &text, QJsonObject &retObject)
{
    if (!text.contains("#")){
        return HttpAPI::instance()->enquiryPPL(text, retObject);
    }
    else if (1 == text.count("#") && -1 != text.indexOf("#")){
        QStringList list = text.split("#");
        return HttpAPI::instance()->enquiryPPL(list.at(0), list.at(1), retObject);
    }
    else if (2 == text.count("#")){
        QStringList list = text.split("#");
        return HttpAPI::instance()->enquiryPPL(list.at(0), list.at(1), retObject, list.at(2));
    }
    else {
        MessageDialog msgDlg(this->parentWidget(), nullptr, "请正确输入信息", 1);
        msgDlg.exec();
        return -1;
    }
}

int inquiryWidget::enquiry_ppl(const BoardingTicketInfo& tickertInfo, QJsonObject &retObject)
{
    if (this->x() != 0)
        return -1;
    bool isBaby = false;
    if (tickertInfo.seatId == "INF")
        isBaby = true;
    return HttpAPI::instance()->enquiryPPL(tickertInfo.flightNo, tickertInfo.boardingNumber, retObject, tickertInfo.seatId, isBaby, tickertInfo.flightDay);
}


void inquiryWidget::set_security_stat_label(int security_passType, int status)
{
    if (0 == security_passType){// 0人证1:1 1人工放行 2闸机B门通过 3 验票通过 4-未知
        switch (status) {
        case 0://pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检验证通过.png"));
            break;
        case 1://no pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/系统验证不通过.png"));
            break;
        case 2://unkown
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png"));
            break;
        case 3://ID card expired
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png"));
            break;
        default:
            break;
        }
    }
    else if (1 == security_passType){
        switch (status) {
        case 0://pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/人工验证通过.png"));
            break;
        case 1://no pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            break;
        case 2://unkown
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png"));
            break;
        case 3://ID card expired
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png"));
            break;
        default:
            break;
        }
    }
    else if (2 == security_passType){
        switch (status) {
        case 0://pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检验证通过.png"));
            break;
        case 1://no pass
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/系统验证不通过.png"));
            break;
        case 2://unkown
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png"));
            break;
        case 3://ID card expired
            securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png"));
            break;
        default:
            break;
        }
    }
    else if (3 == security_passType){
        securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/人工验证通过.png"));
    }
    else {
        securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png"));
    }

}

void inquiryWidget::set_review_stat_label(int security_passType, int status)
{
    if (2 == security_passType){//0 通道复核 1 人工复核-放行 2自助闸机 3 人工复核-报警 4 未知
        switch (status) {
        case 0://pass
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/系统复核通过.png"));
            break;
        case 1://no pass
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/复核异常.png"));
            break;
        case 2://unkown
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png"));
            break;
        default:
            break;
        }
    }
    else if (0 == security_passType || 1 == security_passType){
        switch (status) {
        case 0://pass
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/人工复核通过.png"));
            break;
        case 1://no pass
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            break;
        case 2://unkown
            recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png"));
            break;
        default:
            break;
        }
    }
    else if (3 == security_passType){
        recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
    }
    else {
        recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png"));
    }
}

void inquiryWidget::set_transfer_stat_label(int type)
{
    switch (type) {
    case 0://中转
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转采集.png"));
        break;
    case 1://经停
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png"));
        break;
    case 2://备降
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/备降采集.png"));
        break;
    case 3://中转人工放行
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转采集.png"));
        break;
    case 4://经停人工放行
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png"));
        break;
    case 5://备降人工放行
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/备降采集.png"));
        break;
    case 6://经停人工放行
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png"));
        break;
    default:
        transferStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/信息缺失.png"));
        break;
    }
}

void inquiryWidget::set_boarding_stat_label(int boarding_passType, int status)
{
    if (0 == boarding_passType){// 0通道复核  1人工放行 2 人工报警
        switch (status) {
        case 0://pass
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/登机识别通过.png"));
            break;
        case 1://no pass
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/识别失败.png"));
            break;
        case 2://unkown
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/待核验.png"));
            break;
        default:
            break;
        }
    }
    else {
        switch (status) {
        case 0://pass
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/登机人工放行.png"));
            break;
        case 1://no pass
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            break;
        case 2://unkown
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/待核验.png"));
            break;
        default:
            break;
        }
    }
}

void inquiryWidget::show_select_ppl_widget(const QJsonArray &arry)
{
    ui->widget_choice_ppl->show();

    ui->widget_pass_or_prevent->hide();
    ui->widget_choice_channel->hide();

    for (int i=0; i<arry.size(); i++){
        QJsonObject object = arry.at(i).toObject();

        BoardingMode_ManualPass_Send singlePPLInfo;
        singlePPLInfo.flightNo = object["userInfo"].toObject().value("flightNo").toString();
        singlePPLInfo.date = object["userInfo"].toObject().value("flightDay").toString();
        singlePPLInfo.boardingGate = object["userInfo"].toObject().value("gateNo").toString();
        singlePPLInfo.passengerName = object["userInfo"].toObject().value("passengerName").toString();
        singlePPLInfo.cardId = object["userInfo"].toObject().value("certificateNumber").toString();
        singlePPLInfo.boardingNumber = object["userInfo"].toObject().value("boardingNumber").toString();
        singlePPLInfo.seatId = object["userInfo"].toObject().value("seatId").toString();
        singlePPLInfo.startPort = object["userInfo"].toObject().value("startPort").toString();
        singlePPLInfo.endPort = object["userInfo"].toObject().value("endPort").toString();
        singlePPLInfo.isFocus = object["userInfo"].toObject().value("isFocus").toInt();
        singlePPLInfo.hasBaby = object["userInfo"].toObject().value("hasBaby").toInt();
        singlePPLInfo.moreTicket = object["userInfo"].toObject().value("moreTicket").toInt();
        singlePPLInfo.isSpecialChannel = object["userInfo"].toObject().value("isSpecialChannel").toInt();
        singlePPLInfo.transferSourceType = object["transferInfo"].toObject().value("sourceType").toInt(-1);

        QString photoPath_url_1;
        if (!object.value("securityInfo").isNull() && !object.value("securityInfo").toObject().value("photoPath").isNull()){
            photoPath_url_1 = object.value("securityInfo").toObject().value("photoPath").toString();
        }
        else if (!object.value("reviewInfo").isNull() && !object.value("reviewInfo").toObject().value("photoPath").isNull()){
            photoPath_url_1 = object.value("reviewInfo").toObject().value("photoPath").toString();
        }
        else if (!object.value("transferInfo").isNull() && !object.value("transferInfo").toObject().value("photoPath").isNull()){
            photoPath_url_1 = object.value("transferInfo").toObject().value("photoPath").toString();
        }

        PhotoButtonSinglePPL *pb = new PhotoButtonSinglePPL(photoPath_url_1, singlePPLInfo, object);
        int index = 0;
        for (; index<ui->layout_selectPPL->count(); index++){
            if (pb->getUserInfo().seatId <= static_cast<PhotoButtonSinglePPL*>(ui->layout_selectPPL->itemAt(index)->widget())->getUserInfo().seatId)
                break;
        }
        ui->layout_selectPPL->insertWidget(index, pb, Qt::AlignCenter);
    }
}

void inquiryWidget::show_result_widget(const QJsonObject &result)
{
    ui->widget_pass_or_prevent->show();
    ui->widget_choice_ppl->hide();
    ui->widget_choice_channel->hide();
    ui->pushButton_pass->show();
    ui->pushButton_prevent->show();

    m_userInfo.flightNo = result["userInfo"].toObject().value("flightNo").toString();
    m_userInfo.date = result["userInfo"].toObject().value("flightDay").toString();
    m_userInfo.boardingGate = result["userInfo"].toObject().value("gateNo").toString();
    m_userInfo.passengerName = result["userInfo"].toObject().value("passengerName").toString();
    m_userInfo.cardId = result["userInfo"].toObject().value("certificateNumber").toString();
    m_userInfo.boardingNumber = result["userInfo"].toObject().value("boardingNumber").toString();
    m_userInfo.seatId = result["userInfo"].toObject().value("seatId").toString();
    m_userInfo.startPort = result["userInfo"].toObject().value("startPort").toString();
    m_userInfo.endPort = result["userInfo"].toObject().value("endPort").toString();
    m_userInfo.isFocus = result["userInfo"].toObject().value("isFocus").toInt();
    m_userInfo.hasBaby = result["userInfo"].toObject().value("hasBaby").toInt();
    m_userInfo.moreTicket = result["userInfo"].toObject().value("moreTicket").toInt();
    m_userInfo.isSpecialChannel = result["userInfo"].toObject().value("isSpecialChannel").toInt();
    m_userInfo.transferSourceType = result["transferInfo"].toObject().value("sourceType").toInt(-1);
    m_userInfo.hasSecurityInfo = !result["securityInfo"].isNull() && !result["securityInfo"].isUndefined()
                                 && !result["reviewInfo"].isNull() && !result["reviewInfo"].isUndefined()
                                 ? 1 : 0;
    m_userInfo.secondBoardingPass = !result["boardingInfo"].isNull() && !result["boardingInfo"].isUndefined()
                                    && result["boardingInfo"].toObject()["passType"].toInt(2)!=2
                                    ? 1 : 0;

    //following these three param must be set while buttonPass clicking;
//    m_userInfo.scenePhoto = result["userInfo"].toObject().value("scenePhoto").toVariant().toByteArray();
//    m_userInfo.sourceType = result["userInfo"].toObject().value("sourceType").toInt();
//    m_userInfo.controlType = result["userInfo"].toObject().value("controlType").toInt();

    QString name = result["userInfo"].toObject().value("passengerName").toString();
    QString certificateNumber = result["userInfo"].toObject().value("certificateNumber").toString();
    QString flightNo_userInfo = result["userInfo"].toObject().value("flightNo").toString();
    QString boardingNumber_userInfo = result["userInfo"].toObject().value("boardingNumber").toString();
    QString seatId_userInfo = result["userInfo"].toObject().value("seatId").toString();

    QString flightNo_transfer = result["transferInfo"].toObject()["flightNo"].toString();
    QString gateNo_transfer = result["transferInfo"].toObject().value("gateNo").toString();


    int column = 0;
    //登机和采集一致 或者 只有登机采集信息是空的
    if (flightNo_userInfo == flightNo_transfer || flightNo_transfer.isEmpty()){
        //如果采集信息是空的，则需要 判断安检是否缺失
        if (flightNo_transfer.isEmpty()){
            if (!result["securityInfo"].isNull() && !result["securityInfo"].isUndefined())
                showSecurityInfo(result, column);
            else showNoSecurityInfo(result, column);

            if (!result["reviewInfo"].isNull() && !result["reviewInfo"].isUndefined())
                showReviewInfo(result, column);
            else if (m_userInfo.isSpecialChannel != 1) //特殊通道可以没有安检信息
                showNoReviewInfo(result, column);
        }
        else {
            showSecurityInfo(result, column);
            showReviewInfo(result, column);
        }

        showTransferInfo(result, column);
        showBoardingInfo(result, column);

        if (flightNo_userInfo != HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
                && !HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_userInfo)){
            ui->pushButton_pass->hide();
            HomePage::global_instance->m_RealtimeBoarding->excpDlg->raise();
            HomePage::global_instance->m_RealtimeBoarding->excpDlg->show();
        }
    }
    //采集航班号一样，登机航班号不一样
    else if (flightNo_transfer == HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
             || HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_transfer)){

        m_userInfo.flightNo = flightNo_transfer;
        m_userInfo.boardingGate = gateNo_transfer;
        m_userInfo.seatId.clear();
        m_userInfo.boardingNumber.clear();

        showTransferInfo(result, column);
        showBoardingInfo(result, column);
    }
    //登机航班号一样，采集航班号不一样
    else if (flightNo_userInfo == HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
             || HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_userInfo)){
        m_userInfo.transferSourceType = -1; //设置为非过站旅客
        //判断安检是否缺失
        if (!result["securityInfo"].isNull() && !result["securityInfo"].isUndefined())
            showSecurityInfo(result, column);
        else showNoSecurityInfo(result, column);

        if (!result["reviewInfo"].isNull() && !result["reviewInfo"].isUndefined())
            showReviewInfo(result, column);
        else if (m_userInfo.isSpecialChannel != 1) //特殊通道可以没有安检信息
            showNoReviewInfo(result, column);

        showBoardingInfo(result, column);
    }
    //登机和采集都跟当前航班不一致
    else {
        m_userInfo.transferSourceType = -1; //设置为非过站旅客

        showSecurityInfo(result, column);
        showReviewInfo(result, column);
        showBoardingInfo(result, column);

        ui->pushButton_pass->hide();
        HomePage::global_instance->m_RealtimeBoarding->excpDlg->raise();
        HomePage::global_instance->m_RealtimeBoarding->excpDlg->show();
    }

    ui->label_name->setText(m_userInfo.passengerName);
    ui->label_idNo_->setText(m_userInfo.cardId);
    ui->label_flightNo_->setText(m_userInfo.flightNo);
    ui->label_orderNo_->setText(m_userInfo.boardingNumber);
    ui->label_seatNo_->setText(m_userInfo.seatId);
    ui->label_boardingGateNo_->setText(m_userInfo.boardingGate);
}

void inquiryWidget::showSecurityInfo(const QJsonObject &result, int &column)
{
    if (!result["securityInfo"].isNull() && !result["securityInfo"].isUndefined()){
        QString security_photoPath_url = result["securityInfo"].toObject().value("photoPath").toString();

        securityImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-小.png"));
        netPicture_securityImg->get(QNetworkRequest(QUrl(security_photoPath_url)));

        int security_passType = result["securityInfo"].toObject().value("passType").toInt(0);
        int security_status = result["securityInfo"].toObject().value("passStatus").toInt(0);
        set_security_stat_label(security_passType, security_status);
        if (!LocalSettings::instance()->value("Debug/showMnulPassBtnAnyWay").toBool()
                && security_status != 0 && security_passType != 3) //security_passType:3 验票通过, in this situation, security_status = 2, means unkown;
            ui->pushButton_pass->hide();

        ui->Layout_result->addWidget(securityImg,1,column);
        ui->Layout_result->addWidget(securityStat,2,column);
        column++;
    }
    if (result["userInfo"].toObject().value("isDelete").toInt(0) == 1){
        cancelTicket_security->show();
    }
}

void inquiryWidget::showNoSecurityInfo(const QJsonObject &result, int &column)
{
    Q_UNUSED(result)

    if (!LocalSettings::instance()->value("Debug/showMnulPassBtnAnyWay").toBool())
        ui->pushButton_pass->hide();

    securityImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-退回安检.png"));
    securityStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png"));
    ui->Layout_result->addWidget(securityImg,1,column);
    ui->Layout_result->addWidget(securityStat,2,column);
    column++;
}

void inquiryWidget::showReviewInfo(const QJsonObject &result, int &column)
{
    if (!result["reviewInfo"].isNull() && !result["reviewInfo"].isUndefined()){
        QString review_photoPath_url = result["reviewInfo"].toObject().value("photoPath").toString();

        recheckImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-小.png"));
        netPicture_recheckImg->get(QNetworkRequest(QUrl(review_photoPath_url)));

        int review_passType = result["reviewInfo"].toObject().value("passType").toInt(0);
        int review_status = result["reviewInfo"].toObject().value("passStatus").toInt(0);
        if (!LocalSettings::instance()->value("Debug/showMnulPassBtnAnyWay").toBool()
                && review_status != 0)
            ui->pushButton_pass->hide();

        set_review_stat_label(review_passType, review_status);

        ui->Layout_result->addWidget(recheckImg,1,column);
        ui->Layout_result->addWidget(recheckStat,2,column);
        column++;
    }
    if (result["userInfo"].toObject().value("isDelete").toInt(0) == 1){
        cancelTicket_review->show();
    }
}

void inquiryWidget::showNoReviewInfo(const QJsonObject &result, int &column)
{
    Q_UNUSED(result)

    if (!LocalSettings::instance()->value("Debug/showMnulPassBtnAnyWay").toBool())
        ui->pushButton_pass->hide();

    recheckImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-退回安检.png"));
    recheckStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png"));
    ui->Layout_result->addWidget(recheckImg,1,column);
    ui->Layout_result->addWidget(recheckStat,2,column);
    column++;
}

void inquiryWidget::showTransferInfo(const QJsonObject &result, int &column)
{
    if (!result["transferInfo"].isNull() && !result["transferInfo"].isUndefined()){
        QString transfer_photoPath_url = result["transferInfo"].toObject().value("photoPath").toString();

        transferImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-小.png"));
        netPicture_transferImg->get(QNetworkRequest(QUrl(transfer_photoPath_url)));

        int transfer_type = result["transferInfo"].toObject().value("sourceType").toInt();
        set_transfer_stat_label(transfer_type);

        ui->Layout_result->addWidget(transferImg,1,column);
        ui->Layout_result->addWidget(transferStat,2,column);
        column++;
    }
}
void inquiryWidget::showBoardingInfo(const QJsonObject &result, int &column)
{
    if (!result["boardingInfo"].isNull() && !result["boardingInfo"].isUndefined()){
        QString boarding_photoPath_url = result["boardingInfo"].toObject().value("photoPath").toString();

        boardingImg->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-小.png"));
        netPicture_boardingImg->get(QNetworkRequest(QUrl(boarding_photoPath_url)));

        int boarding_passType = result["boardingInfo"].toObject().value("passType").toInt();
        int boarding_status = result["boardingInfo"].toObject().value("passStatus").toInt();
        set_boarding_stat_label(boarding_passType, boarding_status);

        ui->Layout_result->addWidget(boardingImg,1,column);
        ui->Layout_result->addWidget(boardingStat,2,column);
        column++;
    }
}

void inquiryWidget::on_IDCardReadInfo(QString cardID, QString nameZh, QByteArray img)
{
    Q_UNUSED(nameZh)
    Q_UNUSED(img)

    if (HomePage::global_instance->m_RealtimeBoarding->m_isBording && (HomePage::global_instance->translationWidget->getCurrentPage() == HomePage::global_instance->m_RealtimeBoarding)){
        if(x() == 800){
            openWindow(Channel_Special);
        }
        enquiry(cardID);
    }
}

void inquiryWidget::on_ReadTicketResult(const BoardingTicketInfo& ticketINfo)
{
    if (!HomePage::global_instance->m_RealtimeBoarding->m_isBording || HomePage::global_instance->translationWidget->getCurrentPage() != HomePage::global_instance->m_RealtimeBoarding)
        return;

    if(x() == 800){
        openWindow(Channel_Special);
    }

    resetEnquiryInfo();
    ui->lineEdit_enquiry->setText(ticketINfo.flightNo+ "#" + ticketINfo.boardingNumber+ "#" + ticketINfo.seatId);
    QJsonObject retObject;

    if (0 != enquiry_ppl(ticketINfo, retObject))
        return;

    if (!retObject["result"].isArray()){
        MessageDialog msg(this->parentWidget(), "人员回查", "没有该旅客的信息！", 1);
        msg.exec();
        return;
    }

    arry_info = retObject["result"].toArray();

    if (arry_info.size() == 1){
        QJsonObject result = arry_info.at(0).toObject();
        show_result_widget(result);
    }
    else if (arry_info.size() > 1){
        show_select_ppl_widget(arry_info);
    }
    else return;
}


void inquiryWidget::on_replyFinished(QNetworkReply* reply)
{
//    if (reply->error() == QNetworkReply::NoError)
//    {
    QPixmap sencePhoto;
    QByteArray bytePhoto = reply->readAll();
    reply->deleteLater();
    sencePhoto.loadFromData(bytePhoto);

    if (sencePhoto.isNull()){
        sencePhoto = QPixmap(":/3实时登机/Images/3实时登机/3.2.1/照片-小.png");
    }

    if (QObject::sender() == netPicture_securityImg){
        securityImg->setPixmap(sencePhoto.scaled(securityImg->width(), securityImg->height()));
    }
    else if (QObject::sender() == netPicture_recheckImg){
        recheckImg->setPixmap(sencePhoto.scaled(recheckImg->width(), recheckImg->height()));
    }
    else if (QObject::sender() == netPicture_transferImg){
        transferImg->setPixmap(sencePhoto.scaled(transferImg->width(), transferImg->height()));
    }
    else if (QObject::sender() == netPicture_boardingImg){
        m_userInfo.scenePhoto = bytePhoto;
        boardingImg->setPixmap(sencePhoto.scaled(boardingImg->width(), boardingImg->height()));
    }
    else return;
//    }
}

void inquiryWidget::startMove(Direction direction)
{
    if (timeLine->state() == QTimeLine::Running) return;

    switch (direction){
    case LeftToRight:
        if (this->x() != 0) return;
        timeLine->setDirection(QTimeLine::Backward);
        timeLine->start();
        break;
    case RightToLeft:
        if (this->x() != 800) return;
        timeLine->setDirection(QTimeLine::Forward);
        timeLine->start();
        break;
    }
}


void inquiryWidget::openWindow(Channel Channel)
{
    if (0 == this->x()) return;//x()==0，查询界面处于可见状态
    this->show();

    _channel = Channel;
    startMove(inquiryWidget::RightToLeft);
}
void inquiryWidget::closeWindow()
{
    on_pushButton_return_clicked();
}

void inquiryWidget::on_pushButton_return_clicked()
{
    startMove(LeftToRight);
    _channel = Channel_Special;
    ui->lineEdit_enquiry->clear();
    resetEnquiryInfo();
}

void inquiryWidget::enquiry(const QString& text)
{
    ui->lineEdit_enquiry->setText(text);
    on_pushButton_enquiry_clicked();
}

void inquiryWidget::on_pushButton_enquiry_clicked()
{
    resetEnquiryInfo();
    QString text = ui->lineEdit_enquiry->text().toUpper();

    QJsonObject retObject;

    if (0 != enquiry_ppl(text, retObject))
        return;

    if (!retObject["result"].isArray()){
        MessageDialog msg(this->parentWidget(), "人员回查", "没有该旅客的信息！", 1);
        msg.exec();
        return;
    }

    arry_info = retObject["result"].toArray();

    if (arry_info.size() == 1){
        QJsonObject result = arry_info.at(0).toObject();
        show_result_widget(result);
    }
    else if (arry_info.size() > 1){
        show_select_ppl_widget(arry_info);
    }
    else return;
}


void inquiryWidget::on_pushButton_pass_clicked()
{
    m_isPass = true;

    ui->widget_pass_or_prevent->hide();
//    ui->widget_choice_channel->show();

    if (m_userInfo.seatId.contains("INF")){
//        ui->pushButton_specialPassenger->show();
        on_pushButton_specialPassenger_clicked();
    }
    else {
//        ui->pushButton_specialPassenger->hide();

        //老版本：与实时登机的两个通道的信息做比对，匹配就省略开门动作
        if ((m_userInfo.flightNo == dynamic_cast<RealtimeBoarding*>(parent())->user_left.ticket.flightNo
             && m_userInfo.boardingNumber == dynamic_cast<RealtimeBoarding*>(parent())->user_left.ticket.boardingNumber)){
            m_userInfo.scenePhoto = dynamic_cast<RealtimeBoarding*>(parent())->user_left.scenePhoto;
//            on_pushButton_channel_1_clicked();
        }
        else if ((m_userInfo.flightNo == dynamic_cast<RealtimeBoarding*>(parent())->user_right.ticket.flightNo
                  && m_userInfo.boardingNumber == dynamic_cast<RealtimeBoarding*>(parent())->user_right.ticket.boardingNumber)){
            m_userInfo.scenePhoto = dynamic_cast<RealtimeBoarding*>(parent())->user_right.scenePhoto;
//            on_pushButton_channel_2_clicked();
        }

        //新版新增：直接依据进入此查询界面的位置
        switch (_channel) {
        case Channel_Special:
            on_pushButton_specialPassenger_clicked();
            break;
        case Channel_1:
            on_pushButton_channel_1_clicked();
            break;
        case Channel_2:
            on_pushButton_channel_2_clicked();
            break;
        }
    }
}

void inquiryWidget::on_pushButton_prevent_clicked()
{
    m_isPass = false;

    ui->widget_pass_or_prevent->hide();
    ui->pushButton_specialPassenger->hide();
//    ui->widget_choice_channel->show();

    if (m_userInfo.seatId.contains("INF")){
//        ui->pushButton_specialPassenger->show();
        on_pushButton_specialPassenger_clicked();
    }
    else {
        //老版本：与实时登机的两个通道的信息做比对，匹配就省略开门动作
        if ((m_userInfo.flightNo == dynamic_cast<RealtimeBoarding*>(parent())->user_left.ticket.flightNo
             && m_userInfo.boardingNumber == dynamic_cast<RealtimeBoarding*>(parent())->user_left.ticket.boardingNumber)){
            m_userInfo.scenePhoto = dynamic_cast<RealtimeBoarding*>(parent())->user_left.scenePhoto;
//            on_pushButton_channel_1_clicked();
        }
        else if ((m_userInfo.flightNo == dynamic_cast<RealtimeBoarding*>(parent())->user_right.ticket.flightNo
                  && m_userInfo.boardingNumber == dynamic_cast<RealtimeBoarding*>(parent())->user_right.ticket.boardingNumber)){
            m_userInfo.scenePhoto = dynamic_cast<RealtimeBoarding*>(parent())->user_right.scenePhoto;
//            on_pushButton_channel_2_clicked();
        }

        //新版新增：直接依据进入此查询界面的位置
        switch (_channel) {
        case Channel_Special:
            on_pushButton_specialPassenger_clicked();
            break;
        case Channel_1:
            on_pushButton_channel_1_clicked();
            break;
        case Channel_2:
            on_pushButton_channel_2_clicked();
            break;
        }
    }
}

void inquiryWidget::on_pushButton_channel_1_clicked()
{
    if (m_isPass){
        //闸机通道一发送放行指令
        m_userInfo.sourceType = 0; //放行
        m_userInfo.controlType = 0; //控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(1, m_userInfo).serverStatus){
            dynamic_cast<RealtimeBoarding*>(parent())->clearInfoThrough_L();
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/登机人工放行.png"));
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }
    else{
        //向闸机通道一发送拦截指令
        m_userInfo.sourceType = 1; //拦截
        m_userInfo.controlType = 0; //控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(1, m_userInfo).serverStatus){
            dynamic_cast<RealtimeBoarding*>(parent())->clearInfoThrough_L();
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            this->on_pushButton_return_clicked();
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }

    closeWindow();
}

void inquiryWidget::on_pushButton_channel_2_clicked()
{
    if (m_isPass){
        //闸机通道二发送放行指令
        m_userInfo.sourceType = 0; //放行
        m_userInfo.controlType = 0; //控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(2, m_userInfo).serverStatus){
            dynamic_cast<RealtimeBoarding*>(parent())->clearInfoThrough_R();
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/登机人工放行.png"));
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }
    else{
        //向闸机通道二发送拦截指令
        m_userInfo.sourceType = 1; //拦截
        m_userInfo.controlType = 0; //控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(2, m_userInfo).serverStatus){
            dynamic_cast<RealtimeBoarding*>(parent())->clearInfoThrough_R();
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            this->on_pushButton_return_clicked();
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }
    closeWindow();
}

void inquiryWidget::on_pushButton_specialPassenger_clicked()
{
    if (m_isPass){
        //婴儿和大人的身份证号相同，将婴儿证件号抹除，避免服务端优先使用身份证号
        if (arry_info.size() > 1
                && arry_info[0].toObject()["userInfo"].toObject()["certificateNumber"] == arry_info[1].toObject()["userInfo"].toObject()["certificateNumber"]){
            m_userInfo.cardId = "";
        }

        //向闸机发送婴儿放行指令
        m_userInfo.sourceType = 0; //放行
        m_userInfo.controlType = 1; //不控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(1, m_userInfo).serverStatus){
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/登机人工放行.png"));
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }
    else {
        //向闸机发送婴儿拦截指令
        m_userInfo.sourceType = 1; //拦截
        m_userInfo.controlType = 1; //不控制闸机门
        if (0 == HttpAPI::instance()->BoardingMode_ManualPass(1, m_userInfo).serverStatus){
            //当前登机口状态改为
            boardingStat->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png"));
            this->on_pushButton_return_clicked();
        }
        else{
            ui->widget_pass_or_prevent->show();
            ui->widget_choice_channel->hide();
        }
    }
    closeWindow();
}

void inquiryWidget::on_pushButton_cancelPass_clicked()
{
    ui->widget_pass_or_prevent->show();
    ui->widget_choice_channel->hide();
}


void inquiryWidget::on_pushButton_choice_ppl_commit_clicked()
{
    //new versoin at 2020.07.09 17:12:40
    int count = ui->layout_selectPPL->count();
    int i = 0;
    for (; i<count; i++){
        PhotoButtonSinglePPL* p = static_cast<PhotoButtonSinglePPL*>(ui->layout_selectPPL->itemAt(i)->widget());
        if (p->isChecked()){
            show_result_widget(p->getSrcData());
            clearSelectPplLayout();
            break;
        }
    }
}

void inquiryWidget::clearSelectPplLayout()
{
    QLayoutItem *child;
    while ((child = ui->layout_selectPPL->takeAt(0)) != nullptr){
        if (child->widget())
            delete child->widget();
        delete child;
    }
}
