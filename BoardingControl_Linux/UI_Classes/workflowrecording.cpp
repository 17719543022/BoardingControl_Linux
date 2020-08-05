﻿#include "workflowrecording.h"
#include "ui_workflowrecording.h"
#include "ServerInterface/httpAPI.h"
#include <QGridLayout>
#include "homepage.h"
#include "ticketScancer/serialportser.h"
#include "ServerInterface/IDCardRead_Recog.h"

WorkflowRecording::WorkflowRecording(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkflowRecording),
    isBabyMode(false)
{
    ui->setupUi(this);

    ui->flowTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->flowTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->flowTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->flowTableWidget->verticalHeader()->setVisible(false);
    ui->flowTableWidget->horizontalHeader()->setVisible(false);
    ui->flowTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->flowTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->flowTableWidget->setStyleSheet("image: 0; border: 0; background: transparent;");
    ui->flowTableWidget->setShowGrid(false);
    ui->flowTableWidget->setColumnCount(1);
    ui->flowTableWidget->setColumnWidth(0, 766);

    connect(this, &WorkflowRecording::networkStat, HomePage::global_instance, &HomePage::on_networkStat);
    connect(SerialPortSer::instance(TicketScanner), &SerialPortSer::readBoardingTicketResult, this, &WorkflowRecording::on_ReadDataResult);
    connect(IDCardLoader::instance(), &IDCardLoader::readOK, this, &WorkflowRecording::on_IDCardReadInfo);

}

WorkflowRecording::~WorkflowRecording()
{
    delete ui;
}

void WorkflowRecording::on_flowQueryPushButton_clicked()
{
    queryFlowInfo(ui->flowQueryLineEdit->text());
}

void WorkflowRecording::on_ReadDataResult(const BoardingTicketInfo& ticketINfo)
{
    if (this != HomePage::global_instance->translationWidget->getCurrentPage())
        return;

    ui->flowQueryLineEdit->setText(ticketINfo.flightNo+ "#" + ticketINfo.boardingNumber);
    on_flowQueryPushButton_clicked();
}

void WorkflowRecording::on_IDCardReadInfo(QString cardID, QString nameZh, QByteArray img)
{
    Q_UNUSED(nameZh)
    Q_UNUSED(img)

    if (this != HomePage::global_instance->translationWidget->getCurrentPage())
        return;

    ui->flowQueryLineEdit->setText(cardID);
    on_flowQueryPushButton_clicked();
}

QPixmap WorkflowRecording::getQPixmapSync(QString str)
{
    const QUrl url = QUrl::fromUserInput(str);

    QNetworkRequest request(url);
    QNetworkAccessManager *naManager = new QNetworkAccessManager(this);
    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    QTimer timer;
    connect(&timer, &QTimer::timeout, [&eventLoop]{
        eventLoop.exit(-1);
    });
    timer.start(MSEC_EVENTLOOP_TIMEOUT);
    if (0 == eventLoop.exec()){
        emit networkStat(true);
    }
    else {
        emit networkStat(false, "全流程记录", QString("访问网络图片超时\n[%1...]").arg(str.left(25)));
    }

    QByteArray byteArray = reply->readAll();
    delete reply;
    reply = nullptr;
    delete naManager;
    naManager = nullptr;

    QPixmap pixmap;
    pixmap.loadFromData(byteArray);

    if (pixmap.isNull()) {
        QImage zhaoImage;
        zhaoImage.load(":/4全流程记录/Images/4全流程记录/照片-.png");
        zhaoImage = zhaoImage.scaled(150, 226, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        pixmap = QPixmap::fromImage(zhaoImage);
    }

    return pixmap;
}


void WorkflowRecording::showSecurityInfo(FlowReviewResult &result, int &widgetIndex)
{
    // 人证验证信息:securityInfo
    if (result.hasSecurityInfo) {
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        ui->flowTableWidget->insertRow(widgetIndex);
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        QWidget *securityWidget = new QWidget();

        addSecurityInfo_toWidget(result.userInfo.isDelete, result.securityInfo, securityWidget);
        setSplitWidget(securityWidget);
        ui->flowTableWidget->setCellWidget(widgetIndex, 0, securityWidget);
        widgetIndex++;
    }
}

void WorkflowRecording::showReviewInfo(FlowReviewResult &result, int &widgetIndex)
{
    // 通道复核信息
    if (result.hasReviewInfo) {
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        ui->flowTableWidget->insertRow(widgetIndex);
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);

        QWidget *reviewWidget = new QWidget();
        addReviewInfo_toWidget(result.userInfo.isDelete, result.reviewInfo, reviewWidget);
        setSplitWidget(reviewWidget);
        ui->flowTableWidget->setCellWidget(widgetIndex, 0, reviewWidget);
        widgetIndex++;
    }
}

void WorkflowRecording::showTransferInfo(FlowReviewResult &result, int &widgetIndex)
{
    // 采集信息，中转经停和备降:transferInfo
    if (result.hasTransferInfo) {
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        ui->flowTableWidget->insertRow(widgetIndex);
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        QWidget *transferWidget = new QWidget();

        addTransferInfo_toWidget(result.userInfo.isDelete, result.transferInfo, transferWidget);
        setSplitWidget(transferWidget);
        ui->flowTableWidget->setCellWidget(widgetIndex, 0, transferWidget);
        widgetIndex++;
    }
}

void WorkflowRecording::showBoardingInfo(FlowReviewResult & result, int &widgetIndex)
{
    // 登机口复核信息
    if (result.hasBoardingInfo) {
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);
        ui->flowTableWidget->insertRow(widgetIndex);
        ui->flowTableWidget->setRowHeight(widgetIndex, 226);

        QWidget *boardingWidget = new QWidget();
        addBoardingInfo_toWidget(result.userInfo.isDelete, result.boardingInfo, boardingWidget);
        setSplitWidget(boardingWidget);
        ui->flowTableWidget->setCellWidget(widgetIndex, 0, boardingWidget);
        widgetIndex++;
    }
}

void WorkflowRecording::setSplitWidget(QWidget *splitWidget)
{
    QLabel *splitLabel = new QLabel(splitWidget);
    splitLabel->setGeometry(13, 0, 740, 2);
    splitLabel->setStyleSheet("image: 0; background: 0; border-radius: 0; border-width: 1px; border-style: dashed; border-color: rgb(135, 183, 194);");
}

void WorkflowRecording::addSecurityInfo_toWidget(int isDelete, SecurityInfo &securityInfo, QWidget *securityWidget)
{
    securityWidget->setFixedSize(766, 226);

    QPixmap pixmap = getQPixmapSync(securityInfo.photoPath);
    pixmap = pixmap.scaled(150
                           , 198
                           , Qt::IgnoreAspectRatio
                           , Qt::SmoothTransformation);
    QLabel *securityPhotoLabel = new QLabel(securityWidget);
    securityPhotoLabel->setGeometry(280, 0, 150, 226);
    securityPhotoLabel->setPixmap(pixmap);
    securityPhotoLabel->setFixedSize(150, 226);
    securityPhotoLabel->setAlignment(Qt::AlignCenter);

    if (isDelete == 1) {
        QImage zhiJiCancelBGImage;
        zhiJiCancelBGImage.load(":/4全流程记录/Images/4全流程记录/值机取消-斜章.png");
        zhiJiCancelBGImage = zhiJiCancelBGImage.scaled(150
                                                       , 117
                                                       , Qt::IgnoreAspectRatio
                                                       , Qt::SmoothTransformation);
        QPixmap zhiJiCancelBGPixmap = QPixmap::fromImage(zhiJiCancelBGImage);
        QLabel *zhiJiCancelBGLabel = new QLabel(securityWidget);
        zhiJiCancelBGLabel->setGeometry(280, 0, 150, 226);
        zhiJiCancelBGLabel->setPixmap(zhiJiCancelBGPixmap);
        zhiJiCancelBGLabel->setFixedSize(150, 226);
        zhiJiCancelBGLabel->setAlignment(Qt::AlignCenter);
    }

    QLabel *securityGateTitleLabel = new QLabel(securityWidget);
    securityGateTitleLabel->setGeometry(514, 14, 144, 38);
    securityGateTitleLabel->setText("通过位置：");
    securityGateTitleLabel->setFixedSize(144, 38);
    securityGateTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    securityGateTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *securityGateValueLabel = new QLabel(securityWidget);
    securityGateValueLabel->setGeometry(514, 54, 292, 38);
    securityGateValueLabel->setText(securityInfo.channelName);
    securityGateValueLabel->setFixedSize(292, 38);
    securityGateValueLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    securityGateValueLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *securityTimeTitleLabel = new QLabel(securityWidget);
    securityTimeTitleLabel->setGeometry(514, 94, 144, 38);
    securityTimeTitleLabel->setText("通过时间：");
    securityTimeTitleLabel->setFixedSize(144, 38);
    securityTimeTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    securityTimeTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *securityTimeValueLabel_1 = new QLabel(securityWidget);
    securityTimeValueLabel_1->setGeometry(514, 134, 292, 38);
    QString passTime = securityInfo.passTime;
    securityTimeValueLabel_1->setText(passTime.left(4) + "/" + passTime.mid(4, 2) + "/" + passTime.mid(6, 2));
    securityTimeValueLabel_1->setFixedSize(292, 38);
    securityTimeValueLabel_1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    securityTimeValueLabel_1->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *securityTimeValueLabel_2 = new QLabel(securityWidget);
    securityTimeValueLabel_2->setGeometry(514, 174, 292, 38);
    securityTimeValueLabel_2->setText(passTime.mid(8, 2) + ":" + passTime.mid(10, 2) + ":" + passTime.mid(12, 2));
    securityTimeValueLabel_2->setFixedSize(292, 38);
    securityTimeValueLabel_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    securityTimeValueLabel_2->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QImage securityModalImage;
    int passType = securityInfo.passType;
    int passStatus = securityInfo.passStatus;

    if (0 == passType){// 0人证1:1 1人工放行 2闸机B门通过 3 验票通过 4-未知
        switch (passStatus) {
        case 0://pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检验证通过.png");
            break;
        case 1://no pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/系统验证不通过.png");
            break;
        case 2://unkown
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png");
            break;
        case 3://ID card expired
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png");
            break;
        default:
            break;
        }
    }
    else if (1 == passType){
        switch (passStatus) {
        case 0://pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/人工验证通过.png");
            break;
        case 1://no pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png");
            break;
        case 2://unkown
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png");
            break;
        case 3://ID card expired
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png");
            break;
        default:
            break;
        }
    }
    else if (2 == passType){
        switch (passStatus) {
        case 0://pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检验证通过.png");
            break;
        case 1://no pass
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/系统验证不通过.png");
            break;
        case 2://unkown
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png");
            break;
        case 3://ID card expired
            securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/证件失效.png");
            break;
        default:
            break;
        }
    }
    else if (3 == passType){
        securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/人工验证通过.png");
    }
    else {
        securityModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/安检无记录.png");
    }
    securityModalImage = securityModalImage.scaled(169
                                                   , 50
                                                   , Qt::IgnoreAspectRatio
                                                   , Qt::SmoothTransformation);
    QPixmap securityModalPixmap = QPixmap::fromImage(securityModalImage);
    QLabel *securityModalLabel = new QLabel(securityWidget);
    securityModalLabel->setGeometry(26, 88, 169, 50);
    securityModalLabel->setFixedSize(169, 50);
    securityModalLabel->setPixmap(securityModalPixmap);
    securityModalLabel->setStyleSheet("image: 0; border: 0; background: 0;");
}

void WorkflowRecording::addReviewInfo_toWidget(int isDelete, ReviewInfo &reviewInfo, QWidget *reviewWidget)
{
    reviewWidget->setFixedSize(766, 226);

    QPixmap pixmap = getQPixmapSync(reviewInfo.photoPath);
    pixmap = pixmap.scaled(150
                           , 198
                           , Qt::IgnoreAspectRatio
                           , Qt::SmoothTransformation);
    QLabel *reviewPhotoLabel = new QLabel(reviewWidget);
    reviewPhotoLabel->setGeometry(280, 0, 150, 226);
    reviewPhotoLabel->setPixmap(pixmap);
    reviewPhotoLabel->setFixedSize(150, 226);
    reviewPhotoLabel->setAlignment(Qt::AlignCenter);

    if (isDelete == 1) {
        QImage zhiJiCancelBGImage;
        zhiJiCancelBGImage.load(":/4全流程记录/Images/4全流程记录/值机取消-斜章.png");
        zhiJiCancelBGImage = zhiJiCancelBGImage.scaled(150
                                                       , 117
                                                       , Qt::IgnoreAspectRatio
                                                       , Qt::SmoothTransformation);
        QPixmap zhiJiCancelBGPixmap = QPixmap::fromImage(zhiJiCancelBGImage);
        QLabel *zhiJiCancelBGLabel = new QLabel(reviewWidget);
        zhiJiCancelBGLabel->setGeometry(280, 0, 150, 226);
        zhiJiCancelBGLabel->setPixmap(zhiJiCancelBGPixmap);
        zhiJiCancelBGLabel->setFixedSize(150, 226);
        zhiJiCancelBGLabel->setAlignment(Qt::AlignCenter);
    }

    QLabel *reviewGateTitleLabel = new QLabel(reviewWidget);
    reviewGateTitleLabel->setGeometry(514, 14, 144, 38);
    reviewGateTitleLabel->setText("通过位置：");
    reviewGateTitleLabel->setFixedSize(144, 38);
    reviewGateTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    reviewGateTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *reviewGateValueLabel = new QLabel(reviewWidget);
    reviewGateValueLabel->setGeometry(514, 54, 292, 38);
    reviewGateValueLabel->setText(reviewInfo.channelName);
    reviewGateValueLabel->setFixedSize(292, 38);
    reviewGateValueLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    reviewGateValueLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *reviewTimeTitleLabel = new QLabel(reviewWidget);
    reviewTimeTitleLabel->setGeometry(514, 94, 144, 38);
    reviewTimeTitleLabel->setText("通过时间：");
    reviewTimeTitleLabel->setFixedSize(144, 38);
    reviewTimeTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    reviewTimeTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *reviewTimeValueLabel_1 = new QLabel(reviewWidget);
    reviewTimeValueLabel_1->setGeometry(514, 134, 292, 38);
    QString passTime = reviewInfo.passTime;
    reviewTimeValueLabel_1->setText(passTime.left(4) + "/" + passTime.mid(4, 2)+ "/" + passTime.mid(6, 2));
    reviewTimeValueLabel_1->setFixedSize(292, 38);
    reviewTimeValueLabel_1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    reviewTimeValueLabel_1->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *reviewTimeValueLabel_2 = new QLabel(reviewWidget);
    reviewTimeValueLabel_2->setGeometry(514, 174, 292, 38);
    reviewTimeValueLabel_2->setText(passTime.mid(8, 2) + ":" + passTime.mid(10, 2) + ":" + passTime.mid(12, 2));
    reviewTimeValueLabel_2->setFixedSize(292, 38);
    reviewTimeValueLabel_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    reviewTimeValueLabel_2->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QImage reviewModalImage;
    int passType = reviewInfo.passType;
    int passStatus = reviewInfo.passStatus;

    if (2 == passType){//0 通道复核 1 人工复核-放行 2自助闸机 3 人工复核-报警 4 未知
        switch (passStatus) {
        case 0://pass
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/系统复核通过.png");
            break;
        case 1://no pass
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/复核异常.png");
            break;
        case 2://unkown
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png");
            break;
        default:
            break;
        }
    }
    else if (0 == passType || 1 == passType){
        switch (passStatus) {
        case 0://pass
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/人工复核通过.png");
            break;
        case 1://no pass
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png");
            break;
        case 2://unkown
            reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png");
            break;
        default:
            break;
        }
    }
    else if (3 == passType){
        reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png");
    }
    else {
        reviewModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/复核无记录.png");
    }
    reviewModalImage = reviewModalImage.scaled(169
                                                 , 50
                                                 , Qt::IgnoreAspectRatio
                                                 , Qt::SmoothTransformation);
    QPixmap reviewModalPixmap = QPixmap::fromImage(reviewModalImage);
    QLabel *reviewModalLabel = new QLabel(reviewWidget);
    reviewModalLabel->setGeometry(26, 88, 169, 50);
    reviewModalLabel->setFixedSize(169, 50);
    reviewModalLabel->setPixmap(reviewModalPixmap);
    reviewModalLabel->setStyleSheet("image: 0; border: 0; background: 0;");
}

void WorkflowRecording::addBoardingInfo_toWidget(int isDelete, BoardingInfo &boardingInfo, QWidget *boardingWidget)
{
    boardingWidget->setFixedSize(766, 226);

    QPixmap pixmap = getQPixmapSync(boardingInfo.photoPath);
    pixmap = pixmap.scaled(150
                           , 198
                           , Qt::IgnoreAspectRatio
                           , Qt::SmoothTransformation);
    QLabel *boardingPhotoLabel = new QLabel(boardingWidget);
    boardingPhotoLabel->setGeometry(280, 0, 150, 226);
    boardingPhotoLabel->setPixmap(pixmap);
    boardingPhotoLabel->setFixedSize(150, 226);
    boardingPhotoLabel->setAlignment(Qt::AlignCenter);

    if (isDelete == 1) {
        QImage zhiJiCancelBGImage;
        zhiJiCancelBGImage.load(":/4全流程记录/Images/4全流程记录/值机取消-斜章.png");
        zhiJiCancelBGImage = zhiJiCancelBGImage.scaled(150
                                                       , 117
                                                       , Qt::IgnoreAspectRatio
                                                       , Qt::SmoothTransformation);
        QPixmap zhiJiCancelBGPixmap = QPixmap::fromImage(zhiJiCancelBGImage);
        QLabel *zhiJiCancelBGLabel = new QLabel(boardingWidget);
        zhiJiCancelBGLabel->setGeometry(280, 0, 150, 226);
        zhiJiCancelBGLabel->setPixmap(zhiJiCancelBGPixmap);
        zhiJiCancelBGLabel->setFixedSize(150, 226);
        zhiJiCancelBGLabel->setAlignment(Qt::AlignCenter);
    }

    QLabel *boardingGateTitleLabel = new QLabel(boardingWidget);
    boardingGateTitleLabel->setGeometry(514, 14, 144, 38);
    boardingGateTitleLabel->setText("通过位置：");
    boardingGateTitleLabel->setFixedSize(144, 38);
    boardingGateTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    boardingGateTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *boardingGateValueLabel = new QLabel(boardingWidget);
    boardingGateValueLabel->setGeometry(514, 54, 292, 38);
    boardingGateValueLabel->setText(boardingInfo.channelName);
    boardingGateValueLabel->setFixedSize(292, 38);
    boardingGateValueLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    boardingGateValueLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *boardingTimeTitleLabel = new QLabel(boardingWidget);
    boardingTimeTitleLabel->setGeometry(514, 94, 144, 38);
    boardingTimeTitleLabel->setText("通过时间：");
    boardingTimeTitleLabel->setFixedSize(144, 38);
    boardingTimeTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    boardingTimeTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *boardingTimeValueLabel_1 = new QLabel(boardingWidget);
    boardingTimeValueLabel_1->setGeometry(514, 134, 292, 38);
    QString passTime = boardingInfo.passTime;
    boardingTimeValueLabel_1->setText(passTime.left(4) + "/" + passTime.mid(4, 2) + "/" + passTime.mid(6, 2));
    boardingTimeValueLabel_1->setFixedSize(292, 38);
    boardingTimeValueLabel_1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    boardingTimeValueLabel_1->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *boardingTimeValueLabel_2 = new QLabel(boardingWidget);
    boardingTimeValueLabel_2->setGeometry(514, 174, 292, 38);
    boardingTimeValueLabel_2->setText(passTime.mid(8, 2) + ":" + passTime.mid(10, 2) + ":" + passTime.mid(12, 2));
    boardingTimeValueLabel_2->setFixedSize(292, 38);
    boardingTimeValueLabel_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    boardingTimeValueLabel_2->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QImage boardingModalImage;
    int passType = boardingInfo.passType;
    int passStatus = boardingInfo.passStatus;

    if (0 == passType){// 0通道复核  1人工放行 2 人工报警
        switch (passStatus) {
        case 0://pass
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/登机识别通过.png");
            break;
        case 1://no pass
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/识别失败.png");
            break;
        case 2://unkown
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/待核验.png");
            break;
        default:
            break;
        }
    }
    else {
        switch (passStatus) {
        case 0://pass
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/登机人工放行.png");
            break;
        case 1://no pass
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/已拦截.png");
            break;
        case 2://unkown
            boardingModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/待核验.png");
            break;
        default:
            break;
        }
    }
    boardingModalImage = boardingModalImage.scaled(169
                                                   , 50
                                                   , Qt::IgnoreAspectRatio
                                                   , Qt::SmoothTransformation);
    QPixmap boardingModalPixmap = QPixmap::fromImage(boardingModalImage);
    QLabel *boardingModalLabel = new QLabel(boardingWidget);
    boardingModalLabel->setGeometry(26, 88, 169, 50);
    boardingModalLabel->setFixedSize(169, 50);
    boardingModalLabel->setPixmap(boardingModalPixmap);
    boardingModalLabel->setStyleSheet("image: 0; border: 0; background: 0;");
}

void WorkflowRecording::addTransferInfo_toWidget(int isDelete, TransferInfo &transferInfo, QWidget *transferWidget)
{
    transferWidget->setFixedSize(766, 226);

    QPixmap pixmap = getQPixmapSync(transferInfo.photoPath);
    pixmap = pixmap.scaled(150
                           , 198
                           , Qt::IgnoreAspectRatio
                           , Qt::SmoothTransformation);
    QLabel *transferPhotoLabel = new QLabel(transferWidget);
    transferPhotoLabel->setGeometry(280, 0, 150, 226);
    transferPhotoLabel->setPixmap(pixmap);
    transferPhotoLabel->setFixedSize(150, 226);
    transferPhotoLabel->setAlignment(Qt::AlignCenter);

    if (isDelete == 1) {
        QImage zhiJiCancelBGImage;
        zhiJiCancelBGImage.load(":/4全流程记录/Images/4全流程记录/值机取消-斜章.png");
        zhiJiCancelBGImage = zhiJiCancelBGImage.scaled(150
                                                       , 117
                                                       , Qt::IgnoreAspectRatio
                                                       , Qt::SmoothTransformation);
        QPixmap zhiJiCancelBGPixmap = QPixmap::fromImage(zhiJiCancelBGImage);
        QLabel *zhiJiCancelBGLabel = new QLabel(transferWidget);
        zhiJiCancelBGLabel->setGeometry(280, 0, 150, 226);
        zhiJiCancelBGLabel->setPixmap(zhiJiCancelBGPixmap);
        zhiJiCancelBGLabel->setFixedSize(150, 226);
        zhiJiCancelBGLabel->setAlignment(Qt::AlignCenter);
    }

    QLabel *transferGateTitleLabel = new QLabel(transferWidget);
    transferGateTitleLabel->setGeometry(514, 14, 144, 38);
    transferGateTitleLabel->setText("通过位置：");
    transferGateTitleLabel->setFixedSize(144, 38);
    transferGateTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    transferGateTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *transferGateValueLabel = new QLabel(transferWidget);
    transferGateValueLabel->setGeometry(514, 54, 292, 38);
    transferGateValueLabel->setText(transferInfo.channelName);
    transferGateValueLabel->setFixedSize(292, 38);
    transferGateValueLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    transferGateValueLabel->setStyleSheet("iamge: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *transferTimeTitleLabel = new QLabel(transferWidget);
    transferTimeTitleLabel->setGeometry(514, 94, 144, 38);
    transferTimeTitleLabel->setText("通过时间：");
    transferTimeTitleLabel->setFixedSize(144, 38);
    transferTimeTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    transferTimeTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *transferTimeValueLabel_1 = new QLabel(transferWidget);
    transferTimeValueLabel_1->setGeometry(514, 134, 292, 38);
    QString collectTime = transferInfo.collectTime;
    transferTimeValueLabel_1->setText(collectTime.left(4) + "/" + collectTime.mid(4, 2) + "/" + collectTime.mid(6, 2));
    transferTimeValueLabel_1->setFixedSize(292, 38);
    transferTimeValueLabel_1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    transferTimeValueLabel_1->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *transferTimeValueLabel_2 = new QLabel(transferWidget);
    transferTimeValueLabel_2->setGeometry(514, 174, 292, 38);
    transferTimeValueLabel_2->setText(collectTime.mid(8, 2) + ":" + collectTime.mid(10, 2) + ":" + collectTime.mid(12, 2));
    transferTimeValueLabel_2->setFixedSize(292, 38);
    transferTimeValueLabel_2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    transferTimeValueLabel_2->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QImage transferModalImage;
    int sourceType = transferInfo.sourceType;

    switch (sourceType) {
    case 0://中转
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/中转采集.png");
        break;
    case 1://经停
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png");
        break;
    case 2://备降
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/备降采集.png");
        break;
    case 3://中转人工放行
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/中转采集.png");
        break;
    case 4://经停人工放行
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png");
        break;
    case 5://备降人工放行
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/备降采集.png");
        break;
    case 6://经停人工放行
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/过站采集.png");
        break;
    default:
        transferModalImage.load(":/3实时登机/Images/3实时登机/3.2.1/信息缺失.png");
        break;
    }
    transferModalImage = transferModalImage.scaled(169
                                                   , 50
                                                   , Qt::IgnoreAspectRatio
                                                   , Qt::SmoothTransformation);
    QPixmap transferModalPixmap = QPixmap::fromImage(transferModalImage);
    QLabel *transferModalLabel = new QLabel(transferWidget);
    transferModalLabel->setGeometry(26, 88, 169, 50);
    transferModalLabel->setFixedSize(169, 50);
    transferModalLabel->setPixmap(transferModalPixmap);
    transferModalLabel->setStyleSheet("image: 0; border: 0; background: 0;");
}

void WorkflowRecording::clearInfo()
{
    ui->passengerNameLabel_2->clear();
    ui->passengerCodeLabel_2->clear();
    ui->passengerFlightLabel_2->clear();
    ui->boardingNumberLabel_2->clear();
    ui->seatIdLabel_2->clear();
    ui->gateNoLabel_2->clear();

    ui->flowTableWidget->scrollToTop();
    while (ui->flowTableWidget->rowCount() > 0 ) {
        ui->flowTableWidget->removeRow(0);
    }
}

void WorkflowRecording::queryFlowInfo(const QString &str)
{
    FlowReviewRequest request;
    request.input = str.toUpper();

    if ((request.input.length() == 0) || (request.input.length() > 18)) {
        MessageDialog msg(this, nullptr, "请输入有效信息!", 1);
        msg.exec();

        return;
    }

    this->clearInfo();//清除显示

    FlowReviewResponse response = HttpAPI::instance()->enquiryPPL(request);
    if (!response.founded && response.errorCode == 0) {
        MessageDialog msg(this, "人员回查", "没有该旅客的信息！", 1);
        msg.exec();
        return;
    }

    ui->flowQueryLineEdit->clear();//查询到之后才清除查询框

    int flowIndex = 0;

    if (response.interface.flowNum > 1) {
        MessageDialog msg(this, "请选择旅客", "", 0, response.interface.flowNum, response);
        flowIndex = msg.exec();

        if (flowIndex < 65535) {
            return;
        } else {
            flowIndex -= 65535;
        }
    }

    QString flightNo_userInfo;
    QString flightNo_transfer;

    if (response.interface.result[flowIndex].hasTransferInfo) {
        flightNo_transfer = response.interface.result[flowIndex].transferInfo.flightNo;
    }
    if (response.interface.result[flowIndex].hasUserInfo) {
        ui->passengerNameLabel_2->setText(response.interface.result[flowIndex].userInfo.passengerName);
        ui->passengerCodeLabel_2->setText(response.interface.result[flowIndex].userInfo.certificateNumber);
        ui->passengerFlightLabel_2->setText(response.interface.result[flowIndex].userInfo.flightNo);
        ui->boardingNumberLabel_2->setText(response.interface.result[flowIndex].userInfo.boardingNumber);
        ui->gateNoLabel_2->setText(response.interface.result[flowIndex].userInfo.gateNo);
        ui->seatIdLabel_2->setText(response.interface.result[flowIndex].userInfo.seatId);
        flightNo_userInfo = response.interface.result[flowIndex].userInfo.flightNo;
    }

    int widgetIndex = 0;

    if (flightNo_transfer == flightNo_userInfo || flightNo_transfer.isEmpty()){
        showTransferInfo(response.interface.result[flowIndex], widgetIndex);
        showSecurityInfo(response.interface.result[flowIndex], widgetIndex);
        showReviewInfo(response.interface.result[flowIndex], widgetIndex);
        showBoardingInfo(response.interface.result[flowIndex], widgetIndex);
    }
    else /*if (flightNo_transfer == HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
             || HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_transfer)){
        showTransferInfo(response.interface.result[flowIndex], ++widgetIndex);
        showBoardingInfo(response.interface.result[flowIndex], ++widgetIndex);
    }
    else if (flightNo_userInfo == HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.twoFlightNo
             || HomePage::global_instance->m_RealtimeBoarding->m_flightPlan.shareFltno.contains(flightNo_userInfo))*/{
        showSecurityInfo(response.interface.result[flowIndex], widgetIndex);
        showReviewInfo(response.interface.result[flowIndex], widgetIndex);
        showBoardingInfo(response.interface.result[flowIndex], widgetIndex);
    }
}
