#include "flightenquires.h"
#include "ui_flightenquires.h"
#include "ServerInterface/httpAPI.h"
#include "ServerInterface/httpServer.h"
#include "homepage.h"
#include "ui_homepage.h"
#include "settings.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVBoxLayout>
#include <QTimer>
#include <QScrollBar>

InterceptPushButton::InterceptPushButton(QWidget *parent, bool isInterceptLabel) :
    QPushButton(parent),
    isInterceptLabel(isInterceptLabel)
{
    if (isInterceptLabel == 0) {
        this->setStyleSheet("border: 0; image: 0; background: 0; background-image: url(:/6航班回查/Images/6航班回查/标记拦截.png);");
    }

    if (isInterceptLabel == 1) {
        this->setStyleSheet("border: 0; image: 0; background: 0; background-image: url(:/6航班回查/Images/6航班回查/取消拦截.png);");
    }

    connect(this, SIGNAL(clicked()), this, SLOT(changeIsInterceptLabel()));
}

void InterceptPushButton::changeIsInterceptLabel()
{
    if (isInterceptLabel == 0) {
        this->setStyleSheet("border: 0; image: 0; background: 0; background-image: url(:/6航班回查/Images/6航班回查/取消拦截.png);");
        isInterceptLabel = 1;

        return;
    }

    if (isInterceptLabel == 1) {
        this->setStyleSheet("border: 0; image: 0; background: 0; background-image: url(:/6航班回查/Images/6航班回查/标记拦截.png);");
        isInterceptLabel = 0;

        return;
    }
}

FlightEnquires::FlightEnquires(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightEnquires),
    m_queryFlightNo(QString()),
    isStatisticsMode(false),
    isFillingTable(false),
    orgDepFilledNum(0),
    orgDepFillIndex(0),
    boardingFilledNum(0),
    boardingFillIndex(0),
    notboardingFilledNum(0),
    notboardingFillIndex(0),
    boardingNumberForSlider(QString())
{
    ui->setupUi(this);
    ui->filterWidget->hide();

    naManager = new QNetworkAccessManager(this);

    ui->orgDepTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->orgDepTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->orgDepTableWidget->verticalHeader()->setVisible(true);
    ui->orgDepTableWidget->horizontalHeader()->setVisible(false);
    ui->orgDepTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->orgDepTableWidget->setStyleSheet("border:none;background:transparent;");
    ui->orgDepTableWidget->verticalScrollBar()->setStyleSheet("background-color: rgb(1, 65, 109);");
//    ui->orgDepTableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{width:15px;margin:0px,0px,0px,0px;padding-top:15px;padding-bottom:15px;}"
//                                                              "QScrollBar::handle:vertical{min-height:20;background-color:rgba(10,10,10,0.5);border-radius:6px;}");
    ui->orgDepTableWidget->setShowGrid(false);
    ui->orgDepTableWidget->setColumnCount(1);
    ui->orgDepTableWidget->setColumnWidth(0, 766);

    ui->boardingTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->boardingTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->boardingTableWidget->verticalHeader()->setVisible(true);
    ui->boardingTableWidget->horizontalHeader()->setVisible(false);
    ui->boardingTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->boardingTableWidget->setStyleSheet("border:none;background:transparent;");
    ui->boardingTableWidget->verticalScrollBar()->setStyleSheet("background-color: rgb(1, 65, 109);");
    ui->boardingTableWidget->setShowGrid(false);
    ui->boardingTableWidget->setColumnCount(1);
    ui->boardingTableWidget->setColumnWidth(0, 766);

    ui->notboardingTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->notboardingTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->notboardingTableWidget->verticalHeader()->setVisible(true);
    ui->notboardingTableWidget->horizontalHeader()->setVisible(false);
    ui->notboardingTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->notboardingTableWidget->setStyleSheet("border:none;background:transparent;");
    ui->notboardingTableWidget->verticalScrollBar()->setStyleSheet("background-color: rgb(1, 65, 109);");
    ui->notboardingTableWidget->setShowGrid(false);
    ui->notboardingTableWidget->setColumnCount(1);
    ui->notboardingTableWidget->setColumnWidth(0, 766);

    connect((QObject*)ui->orgDepTableWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(on_orgDepSliderChanged(int)));
    connect((QObject*)ui->boardingTableWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(on_boardingSliderChanged(int)));
    connect((QObject*)ui->notboardingTableWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(on_notBoardingSliderChanged(int)));

    connect(this, &FlightEnquires::networkStat, HomePage::global_instance, &HomePage::on_networkStat);
    connect(HttpServer::instance(), &HttpServer::boardingInfo_to_updateBoardingNum, this, &FlightEnquires::fillBoardAndUnboard_whileBoarding);
}

void FlightEnquires::ppl_statistics(QString flight)
{
    this->enterStatisticsMode();

    this->query(flight);
}

void FlightEnquires::enterStatisticsMode()
{
    this->isStatisticsMode =true;

    ui->filterLineEdit->clear();
    ui->inputWidget->setVisible(false);
    ui->filterWidget->setVisible(true);
    ui->tabWidget->move(15, 320);
    ui->widget_flight->move(15, 6);
}

void FlightEnquires::quitStatisticsMode()
{
    if (isStatisticsMode){
        clearAllInfo();
    }
    this->isStatisticsMode = false;

    ui->inputWidget->setVisible(true);
    ui->widget_flight->move(15, 53);
    ui->tabWidget->move(15, 361);

    if (returnThisPage != nullptr){
        returnThisPage->disconnect();
        delete returnThisPage;
        returnThisPage = nullptr;
    }
}

bool FlightEnquires::isAlreadyExist(const QJsonValue &json)
{
    bool exist = false;

    for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
        if (0 == QString::compare(m_all_ppl_infos.parsedResult.results[i].id, json.toObject().value("id").toString())) {
            m_all_ppl_infos.parsedResult.results[i].boardingNumber = json.toObject().value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.results[i].boardingStatus = json.toObject().value("boardingStatus").toInt();
            m_all_ppl_infos.parsedResult.results[i].cardNo = json.toObject().value("cardNo").toString();
            m_all_ppl_infos.parsedResult.results[i].flightNumber = json.toObject().value("flightNumber").toString();
            m_all_ppl_infos.parsedResult.results[i].id = json.toObject().value("id").toString();
            m_all_ppl_infos.parsedResult.results[i].passengerName = json.toObject().value("passengerName").toString();
            m_all_ppl_infos.parsedResult.results[i].photoPath = json.toObject().value("photoPath").toString();
            m_all_ppl_infos.parsedResult.results[i].repeatFlag = json.toObject().value("repeatFlag").toInt();
            m_all_ppl_infos.parsedResult.results[i].seatNumber = json.toObject().value("seatNumber").toString();
            m_all_ppl_infos.parsedResult.results[i].updateTime = json.toObject().value("updateTime").toString();
            m_all_ppl_infos.parsedResult.results[i].boardingTime = json.toObject().value("boardingTime").toString();

            exist = true;
        }

        if (0 == QString::compare(m_all_ppl_infos.parsedResult.unboard[i].id, json.toObject().value("id").toString())) {
            m_all_ppl_infos.parsedResult.unboard[i].boardingNumber = json.toObject().value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[i].boardingStatus = json.toObject().value("boardingStatus").toInt();
            m_all_ppl_infos.parsedResult.unboard[i].cardNo = json.toObject().value("cardNo").toString();
            m_all_ppl_infos.parsedResult.unboard[i].flightNumber = json.toObject().value("flightNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[i].id = json.toObject().value("id").toString();
            m_all_ppl_infos.parsedResult.unboard[i].passengerName = json.toObject().value("passengerName").toString();
            m_all_ppl_infos.parsedResult.unboard[i].photoPath = json.toObject().value("photoPath").toString();
            m_all_ppl_infos.parsedResult.unboard[i].repeatFlag = json.toObject().value("repeatFlag").toInt();
            m_all_ppl_infos.parsedResult.unboard[i].seatNumber = json.toObject().value("seatNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[i].updateTime = json.toObject().value("updateTime").toString();
            m_all_ppl_infos.parsedResult.unboard[i].boardingTime = json.toObject().value("boardingTime").toString();

            exist = true;
        }
    }

    return exist;
}

void FlightEnquires::fillDepAndUnboardWithMQ(const QJsonArray &content)
{
    for (int j = 0; j < content.size(); j++) {
        QString updateTime = content.at(j).toObject().value("updateTime").toString();
        QString boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
        QString flightNumber = content.at(j).toObject().value("flightNumber").toString();

        if (0 != QString::compare(flightNumber, m_flightPlan.twoFlightNo)
                && !m_flightPlan.shareFltno.contains(flightNumber)) {
            continue;
        }

        if (isAlreadyExist(content.at(j))) {
            continue;
        }

        // fill OrgDepository
        if (m_all_ppl_infos.parsedResult.validSize == 0) {
            m_all_ppl_infos.parsedResult.results[0].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.results[0].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
            m_all_ppl_infos.parsedResult.results[0].cardNo = content.at(j).toObject().value("cardNo").toString();
            m_all_ppl_infos.parsedResult.results[0].flightNumber = content.at(j).toObject().value("flightNumber").toString();
            m_all_ppl_infos.parsedResult.results[0].id = content.at(j).toObject().value("id").toString();
            m_all_ppl_infos.parsedResult.results[0].passengerName = content.at(j).toObject().value("passengerName").toString();
            m_all_ppl_infos.parsedResult.results[0].photoPath = content.at(j).toObject().value("photoPath").toString();
            m_all_ppl_infos.parsedResult.results[0].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
            m_all_ppl_infos.parsedResult.results[0].seatNumber = content.at(j).toObject().value("seatNumber").toString();
            m_all_ppl_infos.parsedResult.results[0].updateTime = content.at(j).toObject().value("updateTime").toString();
            m_all_ppl_infos.parsedResult.results[0].boardingTime = content.at(j).toObject().value("boardingTime").toString();
            m_all_ppl_infos.parsedResult.results[0].isSameBoardingNumber = false;
        } else {
            bool isSameboardingNumber = false;
            int sameBoardingNumber = 0;
            for (int s = 0; s < m_all_ppl_infos.parsedResult.validSize; s++) {
                if (boardingNumber == m_all_ppl_infos.parsedResult.results[s].boardingNumber) {
                    isSameboardingNumber = true;
                    sameBoardingNumber = s;
                    break;
                }
            }

            if (isSameboardingNumber) {
                QString tempBoardingNumber = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].boardingNumber;
                int tempBoardingStatus = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].boardingStatus;
                QString tempCardNo = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].cardNo;
                QString tempFlightNumber = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].flightNumber;
                QString tempId = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].id;
                QString tempPassengerName = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].passengerName;
                QString tempPhotoPath = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].photoPath;
                int tempRepeatFlag = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].repeatFlag;
                QString tempSeatNumber = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].seatNumber;
                QString tempUpdateTime = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].updateTime;
                QString tempBoardingTime = m_all_ppl_infos.parsedResult.results[sameBoardingNumber].boardingTime;

                for (int k = m_all_ppl_infos.parsedResult.validSize; k > 0; k--) {
                    if (k > sameBoardingNumber + 1) {
                        m_all_ppl_infos.parsedResult.results[k].boardingNumber = m_all_ppl_infos.parsedResult.results[k - 1].boardingNumber;
                        m_all_ppl_infos.parsedResult.results[k].boardingStatus = m_all_ppl_infos.parsedResult.results[k - 1].boardingStatus;
                        m_all_ppl_infos.parsedResult.results[k].cardNo = m_all_ppl_infos.parsedResult.results[k - 1].cardNo;
                        m_all_ppl_infos.parsedResult.results[k].flightNumber = m_all_ppl_infos.parsedResult.results[k - 1].flightNumber;
                        m_all_ppl_infos.parsedResult.results[k].id = m_all_ppl_infos.parsedResult.results[k - 1].id;
                        m_all_ppl_infos.parsedResult.results[k].passengerName = m_all_ppl_infos.parsedResult.results[k - 1].passengerName;
                        m_all_ppl_infos.parsedResult.results[k].photoPath = m_all_ppl_infos.parsedResult.results[k - 1].photoPath;
                        m_all_ppl_infos.parsedResult.results[k].repeatFlag = m_all_ppl_infos.parsedResult.results[k - 1].repeatFlag;
                        m_all_ppl_infos.parsedResult.results[k].seatNumber = m_all_ppl_infos.parsedResult.results[k - 1].seatNumber;
                        m_all_ppl_infos.parsedResult.results[k].updateTime = m_all_ppl_infos.parsedResult.results[k - 1].updateTime;
                        m_all_ppl_infos.parsedResult.results[k].boardingTime = m_all_ppl_infos.parsedResult.results[k - 1].boardingTime;
                        m_all_ppl_infos.parsedResult.results[k].isSameBoardingNumber = m_all_ppl_infos.parsedResult.results[k - 1].isSameBoardingNumber;
                    } else if (k >= 2) {
                        m_all_ppl_infos.parsedResult.results[k].boardingNumber = m_all_ppl_infos.parsedResult.results[k - 2].boardingNumber;
                        m_all_ppl_infos.parsedResult.results[k].boardingStatus = m_all_ppl_infos.parsedResult.results[k - 2].boardingStatus;
                        m_all_ppl_infos.parsedResult.results[k].cardNo = m_all_ppl_infos.parsedResult.results[k - 2].cardNo;
                        m_all_ppl_infos.parsedResult.results[k].flightNumber = m_all_ppl_infos.parsedResult.results[k - 2].flightNumber;
                        m_all_ppl_infos.parsedResult.results[k].id = m_all_ppl_infos.parsedResult.results[k - 2].id;
                        m_all_ppl_infos.parsedResult.results[k].passengerName = m_all_ppl_infos.parsedResult.results[k - 2].passengerName;
                        m_all_ppl_infos.parsedResult.results[k].photoPath = m_all_ppl_infos.parsedResult.results[k - 2].photoPath;
                        m_all_ppl_infos.parsedResult.results[k].repeatFlag = m_all_ppl_infos.parsedResult.results[k - 2].repeatFlag;
                        m_all_ppl_infos.parsedResult.results[k].seatNumber = m_all_ppl_infos.parsedResult.results[k - 2].seatNumber;
                        m_all_ppl_infos.parsedResult.results[k].updateTime = m_all_ppl_infos.parsedResult.results[k - 2].updateTime;
                        m_all_ppl_infos.parsedResult.results[k].boardingTime = m_all_ppl_infos.parsedResult.results[k - 1].boardingTime;
                        m_all_ppl_infos.parsedResult.results[k].isSameBoardingNumber = m_all_ppl_infos.parsedResult.results[k - 2].isSameBoardingNumber;
                    }
                }

                m_all_ppl_infos.parsedResult.results[1].boardingNumber = tempBoardingNumber;
                m_all_ppl_infos.parsedResult.results[1].boardingStatus = tempBoardingStatus;
                m_all_ppl_infos.parsedResult.results[1].cardNo = tempCardNo;
                m_all_ppl_infos.parsedResult.results[1].flightNumber = tempFlightNumber;
                m_all_ppl_infos.parsedResult.results[1].id = tempId;
                m_all_ppl_infos.parsedResult.results[1].passengerName = tempPassengerName;
                m_all_ppl_infos.parsedResult.results[1].photoPath = tempPhotoPath;
                m_all_ppl_infos.parsedResult.results[1].repeatFlag = tempRepeatFlag;
                m_all_ppl_infos.parsedResult.results[1].seatNumber = tempSeatNumber;
                m_all_ppl_infos.parsedResult.results[1].updateTime = tempUpdateTime;
                m_all_ppl_infos.parsedResult.results[1].boardingTime = tempBoardingTime;
                m_all_ppl_infos.parsedResult.results[1].isSameBoardingNumber = true;

                m_all_ppl_infos.parsedResult.results[0].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
                m_all_ppl_infos.parsedResult.results[0].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
                m_all_ppl_infos.parsedResult.results[0].cardNo = content.at(j).toObject().value("cardNo").toString();
                m_all_ppl_infos.parsedResult.results[0].flightNumber = content.at(j).toObject().value("flightNumber").toString();
                m_all_ppl_infos.parsedResult.results[0].id = content.at(j).toObject().value("id").toString();
                m_all_ppl_infos.parsedResult.results[0].passengerName = content.at(j).toObject().value("passengerName").toString();
                m_all_ppl_infos.parsedResult.results[0].photoPath = content.at(j).toObject().value("photoPath").toString();
                m_all_ppl_infos.parsedResult.results[0].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
                m_all_ppl_infos.parsedResult.results[0].seatNumber = content.at(j).toObject().value("seatNumber").toString();
                m_all_ppl_infos.parsedResult.results[0].updateTime = content.at(j).toObject().value("updateTime").toString();
                m_all_ppl_infos.parsedResult.results[0].boardingTime = content.at(j).toObject().value("boardingTime").toString();
                m_all_ppl_infos.parsedResult.results[0].isSameBoardingNumber = true;
            } else {
                for (int m = 0; m < m_all_ppl_infos.parsedResult.validSize; m++) {
                    if (updateTime > m_all_ppl_infos.parsedResult.results[m].updateTime && !m_all_ppl_infos.parsedResult.results[m].isSameBoardingNumber) {
                        for (int n = m_all_ppl_infos.parsedResult.validSize - 1; n >= m; n--) {
                            m_all_ppl_infos.parsedResult.results[n + 1].boardingNumber = m_all_ppl_infos.parsedResult.results[n].boardingNumber;
                            m_all_ppl_infos.parsedResult.results[n + 1].boardingStatus = m_all_ppl_infos.parsedResult.results[n].boardingStatus;
                            m_all_ppl_infos.parsedResult.results[n + 1].cardNo = m_all_ppl_infos.parsedResult.results[n].cardNo;
                            m_all_ppl_infos.parsedResult.results[n + 1].flightNumber = m_all_ppl_infos.parsedResult.results[n].flightNumber;
                            m_all_ppl_infos.parsedResult.results[n + 1].id = m_all_ppl_infos.parsedResult.results[n].id;
                            m_all_ppl_infos.parsedResult.results[n + 1].passengerName = m_all_ppl_infos.parsedResult.results[n].passengerName;
                            m_all_ppl_infos.parsedResult.results[n + 1].photoPath = m_all_ppl_infos.parsedResult.results[n].photoPath;
                            m_all_ppl_infos.parsedResult.results[n + 1].repeatFlag = m_all_ppl_infos.parsedResult.results[n].repeatFlag;
                            m_all_ppl_infos.parsedResult.results[n + 1].seatNumber = m_all_ppl_infos.parsedResult.results[n].seatNumber;
                            m_all_ppl_infos.parsedResult.results[n + 1].updateTime = m_all_ppl_infos.parsedResult.results[n].updateTime;
                            m_all_ppl_infos.parsedResult.results[n + 1].boardingTime = m_all_ppl_infos.parsedResult.results[n].boardingTime;
                            m_all_ppl_infos.parsedResult.results[n + 1].isSameBoardingNumber = m_all_ppl_infos.parsedResult.results[n].isSameBoardingNumber;
                        }
                        m_all_ppl_infos.parsedResult.results[m].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
                        m_all_ppl_infos.parsedResult.results[m].cardNo = content.at(j).toObject().value("cardNo").toString();
                        m_all_ppl_infos.parsedResult.results[m].flightNumber = content.at(j).toObject().value("flightNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m].id = content.at(j).toObject().value("id").toString();
                        m_all_ppl_infos.parsedResult.results[m].passengerName = content.at(j).toObject().value("passengerName").toString();
                        m_all_ppl_infos.parsedResult.results[m].photoPath = content.at(j).toObject().value("photoPath").toString();
                        m_all_ppl_infos.parsedResult.results[m].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
                        m_all_ppl_infos.parsedResult.results[m].seatNumber = content.at(j).toObject().value("seatNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m].updateTime = content.at(j).toObject().value("updateTime").toString();
                        m_all_ppl_infos.parsedResult.results[m].boardingTime = content.at(j).toObject().value("boardingTime").toString();
                        m_all_ppl_infos.parsedResult.results[m].isSameBoardingNumber = false;
                        break;
                    }
                    if (m == m_all_ppl_infos.parsedResult.validSize - 1) {
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].cardNo = content.at(j).toObject().value("cardNo").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].flightNumber = content.at(j).toObject().value("flightNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].id = content.at(j).toObject().value("id").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].passengerName = content.at(j).toObject().value("passengerName").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].photoPath = content.at(j).toObject().value("photoPath").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].seatNumber = content.at(j).toObject().value("seatNumber").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].updateTime = content.at(j).toObject().value("updateTime").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].boardingTime = content.at(j).toObject().value("boardingTime").toString();
                        m_all_ppl_infos.parsedResult.results[m_all_ppl_infos.parsedResult.validSize].isSameBoardingNumber = false;
                        break;
                    }
                }
            }
        }

        // fill Unboard
        QString seatNumber = content.at(j).toObject().value("seatNumber").toString();
        if (m_all_ppl_infos.parsedResult.validSize == 0) {
            m_all_ppl_infos.parsedResult.unboard[0].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[0].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
            m_all_ppl_infos.parsedResult.unboard[0].cardNo = content.at(j).toObject().value("cardNo").toString();
            m_all_ppl_infos.parsedResult.unboard[0].flightNumber = content.at(j).toObject().value("flightNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[0].id = content.at(j).toObject().value("id").toString();
            m_all_ppl_infos.parsedResult.unboard[0].passengerName = content.at(j).toObject().value("passengerName").toString();
            m_all_ppl_infos.parsedResult.unboard[0].photoPath = content.at(j).toObject().value("photoPath").toString();
            m_all_ppl_infos.parsedResult.unboard[0].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
            m_all_ppl_infos.parsedResult.unboard[0].seatNumber = content.at(j).toObject().value("seatNumber").toString();
            m_all_ppl_infos.parsedResult.unboard[0].updateTime = content.at(j).toObject().value("updateTime").toString();
            m_all_ppl_infos.parsedResult.unboard[0].boardingTime = content.at(j).toObject().value("boardingTime").toString();
            m_all_ppl_infos.parsedResult.unboard[0].isSameBoardingNumber = false;
        } else {
            for (int m = 0; m < m_all_ppl_infos.parsedResult.validSize; m++) {
                if (seatNumber < m_all_ppl_infos.parsedResult.unboard[m].seatNumber) {
                    for (int k = m_all_ppl_infos.parsedResult.validSize - 1; k >= m; k--) {
                        m_all_ppl_infos.parsedResult.unboard[k + 1].boardingNumber = m_all_ppl_infos.parsedResult.unboard[k].boardingNumber;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].boardingStatus = m_all_ppl_infos.parsedResult.unboard[k].boardingStatus;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].cardNo = m_all_ppl_infos.parsedResult.unboard[k].cardNo;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].flightNumber = m_all_ppl_infos.parsedResult.unboard[k].flightNumber;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].id = m_all_ppl_infos.parsedResult.unboard[k].id;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].passengerName = m_all_ppl_infos.parsedResult.unboard[k].passengerName;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].photoPath = m_all_ppl_infos.parsedResult.unboard[k].photoPath;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].repeatFlag = m_all_ppl_infos.parsedResult.unboard[k].repeatFlag;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].seatNumber = m_all_ppl_infos.parsedResult.unboard[k].seatNumber;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].updateTime = m_all_ppl_infos.parsedResult.unboard[k].updateTime;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].boardingTime = m_all_ppl_infos.parsedResult.unboard[k].boardingTime;
                        m_all_ppl_infos.parsedResult.unboard[k + 1].isSameBoardingNumber = m_all_ppl_infos.parsedResult.unboard[k].isSameBoardingNumber;
                    }
                    m_all_ppl_infos.parsedResult.unboard[m].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
                    m_all_ppl_infos.parsedResult.unboard[m].cardNo = content.at(j).toObject().value("cardNo").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].flightNumber = content.at(j).toObject().value("flightNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].id = content.at(j).toObject().value("id").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].passengerName = content.at(j).toObject().value("passengerName").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].photoPath = content.at(j).toObject().value("photoPath").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
                    m_all_ppl_infos.parsedResult.unboard[m].seatNumber = content.at(j).toObject().value("seatNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].updateTime = content.at(j).toObject().value("updateTime").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].boardingTime = content.at(j).toObject().value("boardingTime").toString();
                    m_all_ppl_infos.parsedResult.unboard[m].isSameBoardingNumber = false;
                    break;
                }
                if (m == m_all_ppl_infos.parsedResult.validSize - 1) {
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].boardingNumber = content.at(j).toObject().value("boardingNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].boardingStatus = content.at(j).toObject().value("boardingStatus").toInt();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].cardNo = content.at(j).toObject().value("cardNo").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].flightNumber = content.at(j).toObject().value("flightNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].id = content.at(j).toObject().value("id").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].passengerName = content.at(j).toObject().value("passengerName").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].photoPath = content.at(j).toObject().value("photoPath").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].repeatFlag = content.at(j).toObject().value("repeatFlag").toInt();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].seatNumber = content.at(j).toObject().value("seatNumber").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].updateTime = content.at(j).toObject().value("updateTime").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].boardingTime = content.at(j).toObject().value("boardingTime").toString();
                    m_all_ppl_infos.parsedResult.unboard[m_all_ppl_infos.parsedResult.validSize].isSameBoardingNumber = false;
                }
            }
        }
        m_all_ppl_infos.parsedResult.validSize += 1;
        m_all_ppl_infos.parsedResult.dataInfo.faceNums += 1;
    }

    on_orgDepPushButton_clicked();
}

void FlightEnquires::fillBoardAndUnboard_whileBoarding(QString flightNo
                                                  , QString flightDay
                                                  , const QByteArray &faceImg
                                                  , int recheckType
                                                  , const QJsonObject &userInfo
                                                  , const QJsonObject &manualInfo)
{
    if ((flightNo != m_flightPlan.twoFlightNo && !m_flightPlan.shareFltno.contains(flightNo))
            || (flightDay != m_flightPlan.flightDate.right(2))){
        return;
    }

    QString flightNumber = "";
    QString boardingNumber = "";
    QString seatNumber = "";
    QString photoPath = "";

    if ((recheckType == 0) || (recheckType == 2)) {
        flightNumber = userInfo.value("flightNumber").toString();
        boardingNumber = userInfo.value("boardingNumber").toString();
        seatNumber= userInfo.value("seatNumber").toString();
        photoPath = findPhotoPath(userInfo.value("cardNo").toString(), flightNumber, boardingNumber, seatNumber);
    } else if ((recheckType == 1) || (recheckType == 3)) {
        flightNumber = manualInfo.value("flightNo").toString();
        boardingNumber = manualInfo.value("boardingNumber").toString();
        seatNumber = manualInfo.value("seatId").toString();
        photoPath = findPhotoPath(manualInfo.value("cardId").toString(), flightNumber, boardingNumber, seatNumber);
    } else {
        qInfo() << "recheckType error: " << recheckType;
        return;
    }

    // fill boarded
    bool isRepeated = false;
    for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
        if ((m_all_ppl_infos.parsedResult.boarded[i].flightNumber == flightNumber)
                && (m_all_ppl_infos.parsedResult.boarded[i].boardingNumber == boardingNumber)
                && (m_all_ppl_infos.parsedResult.boarded[i].seatNumber == seatNumber)
                && (m_all_ppl_infos.parsedResult.boarded[i].boardingStatus == 1)) {
            isRepeated = true;

            QString tempBoardingNumber = m_all_ppl_infos.parsedResult.boarded[i].boardingNumber;
            int tempBoardingStatus = 1;
            QString tempCardNo = "";
            QString tempPassengerName = "";
            if ((recheckType == 0) || (recheckType == 2)) {
                tempCardNo = userInfo.value("cardNo").toString();
                tempPassengerName = userInfo.value("nameZh").toString();
//                tempBasePhoto = userInfo.value("basePhoto").toString();
            }
            if ((recheckType == 1) || (recheckType == 3)) {
                tempCardNo = manualInfo.value("cardId").toString();
                tempPassengerName = manualInfo.value("passengerName").toString();
//                tempBasePhoto = manualInfo.value("scenePhoto").toString();
            }
            QByteArray tempBasePhoto = faceImg;
            QString tempFlightNumber = m_all_ppl_infos.parsedResult.boarded[i].flightNumber;
            QString tempId = "";
            QString tempPhotoPath = photoPath;
            int tempRepeatFlag = 0;
            QString tempSeatNumber = m_all_ppl_infos.parsedResult.boarded[i].seatNumber;
            QString tempUpdateTime = "";
            QString tempBoardingTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
            bool tempIsSameBoardingNumber = false;

            for (int j = i; j > 0; j--) { //place other tableWidget lower
                m_all_ppl_infos.parsedResult.boarded[j].boardingNumber = m_all_ppl_infos.parsedResult.boarded[j - 1].boardingNumber;
                m_all_ppl_infos.parsedResult.boarded[j].boardingStatus = m_all_ppl_infos.parsedResult.boarded[j - 1].boardingStatus;
                m_all_ppl_infos.parsedResult.boarded[j].cardNo = m_all_ppl_infos.parsedResult.boarded[j - 1].cardNo;
                m_all_ppl_infos.parsedResult.boarded[j].flightNumber = m_all_ppl_infos.parsedResult.boarded[j - 1].flightNumber;
                m_all_ppl_infos.parsedResult.boarded[j].id = m_all_ppl_infos.parsedResult.boarded[j - 1].id;
                m_all_ppl_infos.parsedResult.boarded[j].passengerName = m_all_ppl_infos.parsedResult.boarded[j - 1].passengerName;
                m_all_ppl_infos.parsedResult.boarded[j].photoPath = m_all_ppl_infos.parsedResult.boarded[j - 1].photoPath;
                m_all_ppl_infos.parsedResult.boarded[j].basePhoto = m_all_ppl_infos.parsedResult.boarded[j - 1].basePhoto;
                m_all_ppl_infos.parsedResult.boarded[j].repeatFlag = m_all_ppl_infos.parsedResult.boarded[j - 1].repeatFlag;
                m_all_ppl_infos.parsedResult.boarded[j].seatNumber = m_all_ppl_infos.parsedResult.boarded[j - 1].seatNumber;
                m_all_ppl_infos.parsedResult.boarded[j].updateTime = m_all_ppl_infos.parsedResult.boarded[j - 1].updateTime;
                m_all_ppl_infos.parsedResult.boarded[j].boardingTime = m_all_ppl_infos.parsedResult.boarded[j - 1].boardingTime;
                m_all_ppl_infos.parsedResult.boarded[j].isSameBoardingNumber = m_all_ppl_infos.parsedResult.boarded[j - 1].isSameBoardingNumber;
            }

            //palce the repeated Info on the top
            m_all_ppl_infos.parsedResult.boarded[0].boardingNumber = tempBoardingNumber;
            m_all_ppl_infos.parsedResult.boarded[0].boardingStatus = tempBoardingStatus;
            m_all_ppl_infos.parsedResult.boarded[0].cardNo = tempCardNo;
            m_all_ppl_infos.parsedResult.boarded[0].flightNumber = tempFlightNumber;
            m_all_ppl_infos.parsedResult.boarded[0].id = tempId;
            m_all_ppl_infos.parsedResult.boarded[0].passengerName = tempPassengerName;
            m_all_ppl_infos.parsedResult.boarded[0].photoPath = tempPhotoPath;
            m_all_ppl_infos.parsedResult.boarded[0].basePhoto = tempBasePhoto;
            m_all_ppl_infos.parsedResult.boarded[0].repeatFlag = tempRepeatFlag;
            m_all_ppl_infos.parsedResult.boarded[0].seatNumber = tempSeatNumber;
            m_all_ppl_infos.parsedResult.boarded[0].updateTime = tempUpdateTime;
            m_all_ppl_infos.parsedResult.boarded[0].boardingTime = tempBoardingTime;
            m_all_ppl_infos.parsedResult.boarded[0].isSameBoardingNumber = tempIsSameBoardingNumber;
        }
    }

    if (!isRepeated) {
        for (int i = m_all_ppl_infos.parsedResult.validSize; i > 0; i--) {
            m_all_ppl_infos.parsedResult.boarded[i].boardingNumber = m_all_ppl_infos.parsedResult.boarded[i - 1].boardingNumber;
            m_all_ppl_infos.parsedResult.boarded[i].boardingStatus = m_all_ppl_infos.parsedResult.boarded[i - 1].boardingStatus;
            m_all_ppl_infos.parsedResult.boarded[i].cardNo = m_all_ppl_infos.parsedResult.boarded[i - 1].cardNo;
            m_all_ppl_infos.parsedResult.boarded[i].flightNumber = m_all_ppl_infos.parsedResult.boarded[i - 1].flightNumber;
            m_all_ppl_infos.parsedResult.boarded[i].id = m_all_ppl_infos.parsedResult.boarded[i - 1].id;
            m_all_ppl_infos.parsedResult.boarded[i].passengerName = m_all_ppl_infos.parsedResult.boarded[i - 1].passengerName;
            m_all_ppl_infos.parsedResult.boarded[i].photoPath = m_all_ppl_infos.parsedResult.boarded[i - 1].photoPath;
            m_all_ppl_infos.parsedResult.boarded[i].basePhoto = m_all_ppl_infos.parsedResult.boarded[i - 1].basePhoto;
            m_all_ppl_infos.parsedResult.boarded[i].repeatFlag = m_all_ppl_infos.parsedResult.boarded[i - 1].repeatFlag;
            m_all_ppl_infos.parsedResult.boarded[i].seatNumber = m_all_ppl_infos.parsedResult.boarded[i - 1].seatNumber;
            m_all_ppl_infos.parsedResult.boarded[i].updateTime = m_all_ppl_infos.parsedResult.boarded[i - 1].updateTime;
            m_all_ppl_infos.parsedResult.boarded[i].boardingTime = m_all_ppl_infos.parsedResult.boarded[i - 1].boardingTime;
            m_all_ppl_infos.parsedResult.boarded[i].isSameBoardingNumber = m_all_ppl_infos.parsedResult.boarded[i - 1].isSameBoardingNumber;
        }

        if ((recheckType == 0) || (recheckType == 2)) {
            m_all_ppl_infos.parsedResult.boarded[0].boardingNumber = userInfo.value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.boarded[0].cardNo = userInfo.value("cardNo").toString();
            m_all_ppl_infos.parsedResult.boarded[0].flightNumber = userInfo.value("flightNumber").toString();
            m_all_ppl_infos.parsedResult.boarded[0].passengerName = userInfo.value("nameZh").toString();
            m_all_ppl_infos.parsedResult.boarded[0].seatNumber = userInfo.value("seatNumber").toString();
        }
        if ((recheckType == 1) || (recheckType == 3)) {
            m_all_ppl_infos.parsedResult.boarded[0].boardingNumber = manualInfo.value("boardingNumber").toString();
            m_all_ppl_infos.parsedResult.boarded[0].cardNo = manualInfo.value("cardId").toString();
            m_all_ppl_infos.parsedResult.boarded[0].flightNumber = manualInfo.value("flightNo").toString();
            m_all_ppl_infos.parsedResult.boarded[0].passengerName = manualInfo.value("passengerName").toString();
            m_all_ppl_infos.parsedResult.boarded[0].seatNumber = manualInfo.value("seatId").toString();
        }
        m_all_ppl_infos.parsedResult.boarded[0].basePhoto = faceImg;
        m_all_ppl_infos.parsedResult.boarded[0].boardingStatus = 1;
        m_all_ppl_infos.parsedResult.boarded[0].id = "";
        m_all_ppl_infos.parsedResult.boarded[0].photoPath = photoPath;
        m_all_ppl_infos.parsedResult.boarded[0].repeatFlag = 0;
        m_all_ppl_infos.parsedResult.boarded[0].updateTime = "";
        m_all_ppl_infos.parsedResult.boarded[0].boardingTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        m_all_ppl_infos.parsedResult.boarded[0].isSameBoardingNumber = false;

        m_all_ppl_infos.parsedResult.validSize += 1;
        m_all_ppl_infos.parsedResult.dataInfo.boardingNum += 1;

        // del Unboard
        for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
            if ((m_all_ppl_infos.parsedResult.unboard[i].flightNumber == flightNumber)
                    && (m_all_ppl_infos.parsedResult.unboard[i].boardingNumber == boardingNumber)
                    && (m_all_ppl_infos.parsedResult.unboard[i].seatNumber == seatNumber)) {
                for (int j = i; j < m_all_ppl_infos.parsedResult.validSize; j++) {
                    m_all_ppl_infos.parsedResult.unboard[j].boardingNumber = m_all_ppl_infos.parsedResult.unboard[j + 1].boardingNumber;
                    m_all_ppl_infos.parsedResult.unboard[j].boardingStatus = m_all_ppl_infos.parsedResult.unboard[j + 1].boardingStatus;
                    m_all_ppl_infos.parsedResult.unboard[j].cardNo = m_all_ppl_infos.parsedResult.unboard[j + 1].cardNo;
                    m_all_ppl_infos.parsedResult.unboard[j].flightNumber = m_all_ppl_infos.parsedResult.unboard[j + 1].flightNumber;
                    m_all_ppl_infos.parsedResult.unboard[j].id = m_all_ppl_infos.parsedResult.unboard[j + 1].id;
                    m_all_ppl_infos.parsedResult.unboard[j].passengerName = m_all_ppl_infos.parsedResult.unboard[j + 1].passengerName;
                    m_all_ppl_infos.parsedResult.unboard[j].photoPath = m_all_ppl_infos.parsedResult.unboard[j + 1].photoPath;
                    m_all_ppl_infos.parsedResult.unboard[j].repeatFlag = m_all_ppl_infos.parsedResult.unboard[j + 1].repeatFlag;
                    m_all_ppl_infos.parsedResult.unboard[j].seatNumber = m_all_ppl_infos.parsedResult.unboard[j + 1].seatNumber;
                    m_all_ppl_infos.parsedResult.unboard[j].updateTime = m_all_ppl_infos.parsedResult.unboard[j + 1].updateTime;
                    m_all_ppl_infos.parsedResult.unboard[j].boardingTime = m_all_ppl_infos.parsedResult.unboard[j + 1].boardingTime;
                    m_all_ppl_infos.parsedResult.unboard[j].isSameBoardingNumber = m_all_ppl_infos.parsedResult.unboard[j + 1].isSameBoardingNumber;
                }
            }
        }
    }

    on_boardingPushButton_clicked();
}


FlightEnquires::~FlightEnquires()
{
    delete ui;
}

void FlightEnquires::on_queryPushButton_clicked()
{
    QString queryFlightNo = ui->queryLineEdit->text().toUpper();

    if (queryFlightNo.length() == 0) {
        MessageDialog *msg = new MessageDialog(this, nullptr, "请输入正确的航班号!", 1);
        msg->setAttribute(Qt::WA_DeleteOnClose, true);
        msg->show();
        return;
    }

    if (Ui::DisplayType::DisplayNormal == query(queryFlightNo)) {
//         MessageDialog *msg = new MessageDialog(this, nullptr, "没有查询到该航班的信息！", 1);
//         msg->setAttribute(Qt::WA_DeleteOnClose, true);
//         msg->show();
     }
}


void FlightEnquires::on_orgDepPushButton_clicked()
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }
    ui->filterLineEdit->clear();

    int unBoardingNum = 0;
    for (int i=0; i<m_all_ppl_infos.parsedResult.validSize; i++){
        if (m_all_ppl_infos.parsedResult.unboard[i].boardingStatus == 0 && !m_all_ppl_infos.parsedResult.unboard[i].id.isEmpty()){
            unBoardingNum ++;
        }
    }
    ui->notboardingPushButton->setText("未登机人数：" + QString::number(unBoardingNum));
    ui->orgDepPushButton->setText("航班人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.faceNums));
    ui->boardingPushButton->setText("已登机人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.boardingNum));

    ui->orgDepPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(255, 255, 255); background-color: rgb(88, 129, 157);");
    ui->boardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");
    ui->notboardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");

    ui->orgDepTableWidget->show();
    ui->boardingTableWidget->hide();
    ui->notboardingTableWidget->hide();

    ui->orgDepTableWidget->scrollToTop();
    while (ui->orgDepTableWidget->rowCount() > 0) {
        ui->orgDepTableWidget->removeRow(0);
    }
    orgDepFilledNum = 0;
    orgDepFillIndex = 0;

    fillTableGradually(m_all_ppl_infos, ui->orgDepTableWidget, Ui::DisplayTab::DepositoryTab);
}

void FlightEnquires::on_boardingPushButton_clicked()
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }
    ui->filterLineEdit->clear();

    int unBoardingNum = 0;
    for (int i=0; i<m_all_ppl_infos.parsedResult.validSize; i++){
        if (m_all_ppl_infos.parsedResult.unboard[i].boardingStatus == 0 && !m_all_ppl_infos.parsedResult.unboard[i].id.isEmpty()){
            unBoardingNum ++;
        }
    }
    ui->notboardingPushButton->setText("未登机人数：" + QString::number(unBoardingNum));
    ui->orgDepPushButton->setText("航班人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.faceNums));
    ui->boardingPushButton->setText("已登机人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.boardingNum));

    ui->orgDepPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");
    ui->boardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(255, 255, 255); background-color: rgb(88, 129, 157);");
    ui->notboardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");

    ui->orgDepTableWidget->hide();
    ui->boardingTableWidget->show();
    ui->notboardingTableWidget->hide();

    ui->boardingTableWidget->scrollToTop();
    while (ui->boardingTableWidget->rowCount() > 0) {
        ui->boardingTableWidget->removeRow(0);
    }
    boardingFilledNum = 0;
    boardingFillIndex = 0;

    fillTableGradually(m_all_ppl_infos, ui->boardingTableWidget, Ui::DisplayTab::BoardingTab);
}

void FlightEnquires::on_notboardingPushButton_clicked()
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }
    ui->filterLineEdit->clear();

    int unBoardingNum = 0;
    for (int i=0; i<m_all_ppl_infos.parsedResult.validSize; i++){
        if (m_all_ppl_infos.parsedResult.unboard[i].boardingStatus == 0 && !m_all_ppl_infos.parsedResult.unboard[i].id.isEmpty()){
            unBoardingNum ++;
        }
    }
    ui->notboardingPushButton->setText("未登机人数：" + QString::number(unBoardingNum));
    ui->orgDepPushButton->setText("航班人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.faceNums));
    ui->boardingPushButton->setText("已登机人数：" + QString::number(m_all_ppl_infos.parsedResult.dataInfo.boardingNum));

    ui->orgDepPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");
    ui->boardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(0, 228, 255); background-color: rgb(0, 36, 60);");
    ui->notboardingPushButton->setStyleSheet("border: 0; border-radius: 4; color: rgb(255, 255, 255); background-color: rgb(88, 129, 157);");

    ui->orgDepTableWidget->hide();
    ui->boardingTableWidget->hide();
    ui->notboardingTableWidget->show();

    ui->notboardingTableWidget->scrollToTop();
    while (ui->notboardingTableWidget->rowCount() > 0) {
        ui->notboardingTableWidget->removeRow(0);
    }
    notboardingFilledNum = 0;
    notboardingFillIndex = 0;

    fillTableGradually(m_all_ppl_infos, ui->notboardingTableWidget, Ui::DisplayTab::NotBoardingTab);
}

void FlightEnquires::on_filterPushButton_clicked()
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }

    ui->orgDepTableWidget->clear();
    ui->orgDepTableWidget->scrollToTop();
    while (ui->orgDepTableWidget->rowCount() > 0) {
        ui->orgDepTableWidget->removeRow(0);
    }
    ui->boardingTableWidget->clear();
    ui->boardingTableWidget->scrollToTop();
    while (ui->boardingTableWidget->rowCount() > 0) {
        ui->boardingTableWidget->removeRow(0);
    }
    ui->notboardingTableWidget->clear();
    ui->notboardingTableWidget->scrollToTop();
    while (ui->notboardingTableWidget->rowCount() > 0) {
        ui->notboardingTableWidget->removeRow(0);
    }

    orgDepFilledNum = 0;
    orgDepFillIndex = 0;
    boardingFilledNum = 0;
    boardingFillIndex = 0;
    notboardingFilledNum = 0;
    notboardingFillIndex = 0;

    if (ui->orgDepTableWidget->isVisible()) {
        fillTableGradually(m_all_ppl_infos, ui->orgDepTableWidget, Ui::DisplayTab::DepositoryTab, ui->filterLineEdit->text());
    }

    if (ui->boardingTableWidget->isVisible()) {
        fillTableGradually(m_all_ppl_infos, ui->boardingTableWidget, Ui::DisplayTab::BoardingTab, ui->filterLineEdit->text());
    }

    if (ui->notboardingTableWidget->isVisible()) {
        fillTableGradually(m_all_ppl_infos, ui->notboardingTableWidget, Ui::DisplayTab::NotBoardingTab, ui->filterLineEdit->text());
    }
}

void FlightEnquires::on_orgDepSliderChanged(int p)
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }

    if ((p+2) == orgDepFilledNum) {
        if (boardingNumberForSlider == QString()) {
            fillTableGradually(m_all_ppl_infos, ui->orgDepTableWidget, Ui::DisplayTab::DepositoryTab);
        } else {
            fillTableGradually(m_all_ppl_infos, ui->orgDepTableWidget, Ui::DisplayTab::DepositoryTab, boardingNumberForSlider);
        }
    }
}

void FlightEnquires::on_boardingSliderChanged(int p)
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }

    if ((p+2) == boardingFilledNum) {
        if (boardingNumberForSlider == QString()) {
            fillTableGradually(m_all_ppl_infos, ui->boardingTableWidget, Ui::DisplayTab::BoardingTab);
        } else {
            fillTableGradually(m_all_ppl_infos, ui->boardingTableWidget, Ui::DisplayTab::BoardingTab, boardingNumberForSlider);
        }
    }
}

void FlightEnquires::on_notBoardingSliderChanged(int p)
{
    if (isFillingTable) {
        return;
    } else {
        isFillingTable = true;
    }

    if ((p+2) == notboardingFilledNum) {
        if (boardingNumberForSlider == QString()) {
            fillTableGradually(m_all_ppl_infos, ui->notboardingTableWidget, Ui::DisplayTab::NotBoardingTab);
        } else {
            fillTableGradually(m_all_ppl_infos, ui->notboardingTableWidget, Ui::DisplayTab::NotBoardingTab, boardingNumberForSlider);
        }
    }
}

void FlightEnquires::on_removeRowClicked(int widgetIndex)
{
    LibDeleteRequest libDelReq;
    LibDeleteResponse libDelRsp;

    libDelReq.flightNo = m_all_ppl_infos.parsedResult.results[widgetIndex].flightNumber;
    libDelReq.flightDate = m_flightPlan.flightDate;
    libDelReq.id = m_all_ppl_infos.parsedResult.results[widgetIndex].id;

    libDelRsp = HttpAPI::instance()->removeSpecific(libDelReq);
    if (libDelRsp.status != 0)
        return;

    this->query(m_queryFlightNo);
    ///////////////////////////
//    QString flightNoClicked = response.interface.results[widgetIndex].flightNumber;
//    QString boardingNumberClicked = response.interface.results[widgetIndex].boardingNumber;

//    for (int i = widgetIndex; i < response.interface.validSize - 1 && i < 1000; i++) {
//        response.interface.results[i] = response.interface.results[i + 1];
//    }
//    response.interface.results[response.interface.validSize - 1] = FlightReviewResult();
//    response.interface.validSize -= 1;

//    FlightReviewResult partener;
//    int count = 0;
//    int index = -1;
//    for (int i = 0; i < response.interface.validSize; i++) {
//        if ((response.interface.results[i].flightNumber == flightNoClicked)
//                && (response.interface.results[i].boardingNumber == boardingNumberClicked)) {
//            count += 1;
//            index = i;
//        }
//    }

//    if (count == 1) {
//        partener = response.interface.results[index];
//        partener.isSameBoardingNumber = false;

//        for (int i = index; i < response.interface.validSize - 1; i++) {
//            response.interface.results[i] = response.interface.results[i + 1];
//        }
//        response.interface.results[response.interface.validSize - 1] = FlightReviewResult();
//        response.interface.validSize -= 1;

//        for (int i = 0; i < response.interface.validSize; i++) {
//            if (partener.updateTime > response.interface.results[i].updateTime && !response.interface.results[i].isSameBoardingNumber) {
//                for (int k = response.interface.validSize - 1; k >= i; k--) {
//                    response.interface.results[k + 1] = response.interface.results[k];
//                }
//                response.interface.results[i] = partener;
//                response.interface.validSize += 1;
//                break;
//            }
//            if (i == response.interface.validSize - 1) {
//                response.interface.results[i] = partener;
//                response.interface.validSize += 1;
//            }
//        }
//    }

//    ui->orgDepTableWidget->scrollToTop();
//    while (ui->orgDepTableWidget->rowCount() > 0 ) {
//        ui->orgDepTableWidget->removeRow(0);
//    }

//    orgDepFilledNum = 0;
//    orgDepFillIndex = 0;

//    ui->orgDepPushButton->setText("航班人数：" + QString::number(response.interface.validSize));
//    fillTableGradually(response, ui->orgDepTableWidget, Ui::DisplayTab::DepositoryTab);
}

void FlightEnquires::on_interceptClicked(int widgetIndex)
{
    int isInterceptLabel = m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel;
    qDebug() << "m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel: " << isInterceptLabel;

    if (m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel == 0) {
        m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel = 1;
    }

    if (m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel == 1) {
        m_all_ppl_infos.parsedResult.results[widgetIndex].isInterceptLabel = 0;
    }

    HttpAPI::instance()->interceptOrCancel(m_all_ppl_infos.parsedResult.results[widgetIndex].flightNumber
                                           , m_all_ppl_infos.parsedResult.results[widgetIndex].id
                                           , m_flightPlan.flightDate
                                           , isInterceptLabel);
}

void FlightEnquires::on_PhotoClicked(const FlightReviewResult *result)
{    
    HomePage::global_instance->translationWidget->setCurrentPage(2, true);

    if (result->cardNo.isEmpty()){
        QString str;
        str.append(result->flightNumber).append("#").append(result->boardingNumber);
        HomePage::global_instance->m_WorkflowRecording->queryFlowInfo(str);
    }
    else{
        HomePage::global_instance->m_WorkflowRecording->queryFlowInfo(result->cardNo);
    }

    if (returnThisPage == nullptr){
        returnThisPage = new QPushButton(HomePage::global_instance->ui->widget_menuUp);
    }
    returnThisPage->setGeometry(HomePage::global_instance->ui->Button_return->geometry());
    returnThisPage->setStyleSheet(HomePage::global_instance->ui->Button_return->styleSheet());
    returnThisPage->setFocusPolicy(Qt::NoFocus);
    returnThisPage->show();

    connect(returnThisPage, &QPushButton::clicked, [&]
    {
        HomePage::global_instance->translationWidget->setCurrentPage(3, true);

        if (returnThisPage != nullptr){
            returnThisPage->disconnect();
            delete returnThisPage;
            returnThisPage = nullptr;
        }
    });
}

QPixmap FlightEnquires::getQPixmapSync(QString str)
{
    const QUrl url = QUrl::fromUserInput(str);

    QNetworkRequest request(url);
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
        emit networkStat(false, "航班回查", QString("访问网络图片超时\n[%1...]").arg(str.left(25)));
    }

    QByteArray byteArray = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(byteArray);
    delete reply;
    reply = nullptr;

    if (pixmap.isNull()) {
        QImage zhaoImage;
        zhaoImage.load(":/4全流程记录/Images/4全流程记录/照片-.png");
        zhaoImage = zhaoImage.scaled(150
                                     , 226
                                     , Qt::IgnoreAspectRatio
                                     , Qt::SmoothTransformation);
        pixmap = QPixmap::fromImage(zhaoImage);
    }
    return pixmap;
}

void FlightEnquires::fillTableGradually(const FlightReviewResponse &response, QTableWidget *table, Ui::DisplayTab tab, QString boardingNumber)
{
    boardingNumberForSlider = boardingNumber;

    const FlightReviewResult * results[1000];
    for (int i = 0; i < response.parsedResult.validSize; i++) {
        if (tab == Ui::DisplayTab::DepositoryTab) {
            results[i] = &response.parsedResult.results[i];
        }
        if (tab == Ui::DisplayTab::BoardingTab) {
            results[i] = &response.parsedResult.boarded[i];
        }
        if (tab == Ui::DisplayTab::NotBoardingTab) {
            results[i] = &response.parsedResult.unboard[i];
        }
    }

    int widgetIndex = 0;
    int resultIndex = 0;

    if (tab == Ui::DisplayTab::DepositoryTab) {
        widgetIndex = orgDepFilledNum;
        resultIndex = orgDepFillIndex;
    }
    if (tab == Ui::DisplayTab::BoardingTab) {
        widgetIndex = boardingFilledNum;
        resultIndex = boardingFillIndex;
    }
    if (tab == Ui::DisplayTab::NotBoardingTab) {
        widgetIndex = notboardingFilledNum;
        resultIndex = notboardingFillIndex;
    }

    int filledLine = 0;
    for (int i = resultIndex; (i < response.parsedResult.validSize) && (filledLine < 3); i++) {
        if (tab == Ui::DisplayTab::DepositoryTab) {
            orgDepFillIndex += 1;

            if (results[i]->id == "") {
                continue;
            }

            orgDepFilledNum += 1;
        }

        if (tab == Ui::DisplayTab::BoardingTab) {
            boardingFillIndex += 1;

            if (results[i]->boardingStatus != 1) {
                continue;
            }

            boardingFilledNum += 1;
        }

        if (tab == Ui::DisplayTab::NotBoardingTab) {
            notboardingFillIndex += 1;

            if (!(results[i]->id != ""
                  && results[i]->boardingStatus == 0)) {
                continue;
            }

            notboardingFilledNum += 1;
        }

        if (!boardingNumber.isEmpty() && (boardingNumber != results[i]->boardingNumber)) {
            continue;
        }

        QWidget *itemWidget = new QWidget();/*ButtonWidget(this, isStatisticsMode, tab, widgetIndex);*/
        itemWidget->resize(table->width(),206);

        showResultOnTableWidget(results[i], itemWidget);

        if (isStatisticsMode && (tab == Ui::DisplayTab::DepositoryTab)) {
            if (results[i]->isSameBoardingNumber
                    && ((results[i]->sourceType == 0) || (results[i]->sourceType == 4) || (results[i]->sourceType == 5) || (results[i]->sourceType == 7))) {
                QPushButton *removePushButton = new QPushButton(itemWidget);
                removePushButton->setGeometry(580, 148, 140, 40);
                removePushButton->setFixedSize(140, 40);
                removePushButton->setStyleSheet("border: 0; image: 0; background: 0; background-image: url(:/6航班回查/Images/6航班回查/删除.png);");

                connect(removePushButton, &QPushButton::clicked, [=]{on_removeRowClicked(widgetIndex);});
            }

            InterceptPushButton *interceptPushButton = new InterceptPushButton(itemWidget, results[i]->isInterceptLabel);
            interceptPushButton->setGeometry(580, 18, 140, 40);
            interceptPushButton->setFixedSize(140, 40);

            connect(interceptPushButton, &QPushButton::clicked, [=]{on_interceptClicked(widgetIndex);});
        }

        table->insertRow(widgetIndex);
        table->setRowHeight(widgetIndex, 206);
        table->setCellWidget(widgetIndex, 0, itemWidget);
        filledLine += 1;
        widgetIndex += 1;
    }

    isFillingTable = false;
}

int FlightEnquires::query(QString &flightNo)
{
    m_queryFlightNo = flightNo;
    //1.服务器查询是否有当前航班信息
    Return_Flight_Plan_Param ret_info = HttpAPI::instance()->queryFlight(m_queryFlightNo);
    if (ret_info.curl_err_code != 0)
        return Ui::DisplayType::DisplayNullErr;
    else if (ret_info.serverStatus != 0){
        MessageDialog *msg = new MessageDialog(this, "航班回查", "没有查询到该航班信息!", 1);
        msg->setAttribute(Qt::WA_DeleteOnClose, true);
        msg->show();

        clearAllInfo();
        return Ui::DisplayType::DisplayNullErr;
    }
    else{    //查询到了
        showFlightInfo(ret_info.flightPlan);
    }

    FlightReviewRequest request;
    request.input = ret_info.flightPlan.twoFlightNo;
    request.flightDtae = ret_info.flightPlan.flightDate;
    request.queryType = 3;  // queryType写死为3,以后0/1/2都不用了

    m_all_ppl_infos = HttpAPI::instance()->get_ppl_in_flight(request);
    if (!m_all_ppl_infos.founded) {
        return Ui::DisplayType::DisplayNullErr;
    }

    ui->queryLineEdit->clear();
    on_orgDepPushButton_clicked();
    return Ui::DisplayType::DisplayNormal;
}

void FlightEnquires::showFlightInfo(FlightPlan &flightInfo)
{
    m_flightPlan = flightInfo;

    ui->label_mainFlightNO_->setText(flightInfo.twoFlightNo);
    ui->label_fromPlace->setText(flightInfo.depAirportName);

    if (m_flightPlan.arrAirportName.isEmpty()){
        ui->label_midPlace->setText("");
        ui->label_arrivalPlace->setText("- - - -");
    }
    else if (m_flightPlan.midwayName == flightInfo.arrAirportName){
        ui->label_midPlace->setText("");
        ui->label_arrivalPlace->setText(flightInfo.midwayName);
    }
    else {
        ui->label_midPlace->setText(flightInfo.arrAirportName);
        ui->label_arrivalPlace->setText(flightInfo.midwayName.remove("-").remove(flightInfo.arrAirportName));
    }

    ui->ScrollText_shareFlight->setTextList(flightInfo.shareFltno);
    ui->ScrollText_shareFlight->setInterval_scrollTimer(2000);
    ui->ScrollText_shareFlight->setInterval_animation(1000);

    if (flightInfo.twoFlightNo.isEmpty())
        ui->label_mainFlightNO_->setText("- - - - - -");
    if (flightInfo.depAirportName.isEmpty())
        ui->label_fromPlace->setText("- - - -");
    if (flightInfo.arrAirportName.isEmpty())
        ui->label_arrivalPlace->setText("- - - -");
}

void FlightEnquires::clearAllInfo()
{
    ui->label_mainFlightNO_->setText("- - - - - -");
    ui->label_fromPlace->setText("- - - -");
    ui->label_arrivalPlace->setText("- - - -");
    ui->label_midPlace->setText("");
    ui->ScrollText_shareFlight->setTextList(QStringList());
    ui->filterLineEdit->clear();

    m_queryFlightNo = "";
    m_flightPlan = FlightPlan();
    m_all_ppl_infos = FlightReviewResponse();
    on_orgDepPushButton_clicked();
}

void FlightEnquires::showResultOnTableWidget(const FlightReviewResult *result, QWidget *itemWidget)
{
    if (result->isSameBoardingNumber) {
        QImage sameBoardingNumberBGImage;
        sameBoardingNumberBGImage.load(":/6航班回查/Images/6航班回查/矩形-4365.png");
        if (!sameBoardingNumberBGImage.isNull())
            sameBoardingNumberBGImage = sameBoardingNumberBGImage.scaled(766, 206, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        QPixmap sameBoardingNumberBGPixmap = QPixmap::fromImage(sameBoardingNumberBGImage);
        QLabel *sameBoardingNumberBGLabel = new QLabel(itemWidget);
        sameBoardingNumberBGLabel->setGeometry(0, 0, 766, 206);
        sameBoardingNumberBGLabel->setPixmap(sameBoardingNumberBGPixmap);
        sameBoardingNumberBGLabel->setFixedSize(766, 206);
        sameBoardingNumberBGLabel->setAlignment(Qt::AlignCenter);
    }

    QPixmap pixmap = QPixmap();
    pixmap = getQPixmapSync(result->photoPath);

    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(131, 186, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    QPushButton *photoButton = new QPushButton(itemWidget);
    photoButton->setFocusPolicy(Qt::NoFocus);
    photoButton->setGeometry(30, 10, 131, 186);
    photoButton->setIconSize(QSize(131, 186));
    photoButton->setIcon(pixmap.scaled(131, 186));
    connect(photoButton, &QPushButton::clicked, [=]
    {
        itemWidget->setFocus();
        on_PhotoClicked(result);
    });

    if ((result->sourceType == 5) || (result->sourceType == 6)) {
        QImage zhongZhuanModalImage;
        zhongZhuanModalImage.load(":/6航班回查/Images/6航班回查/中转.png");
        zhongZhuanModalImage = zhongZhuanModalImage.scaled(48
                                                           , 24
                                                           , Qt::IgnoreAspectRatio
                                                           , Qt::SmoothTransformation);
        QPixmap zhongZhuanModalPixmap = QPixmap::fromImage(zhongZhuanModalImage);
        QLabel *zhongZhuanModalLabel = new QLabel(itemWidget);
        zhongZhuanModalLabel->raise();
        zhongZhuanModalLabel->setGeometry(32, 12, 48, 24);
        zhongZhuanModalLabel->setPixmap(zhongZhuanModalPixmap);
        zhongZhuanModalLabel->setFixedSize(48, 24);
        zhongZhuanModalLabel->setAlignment(Qt::AlignCenter);
    }

    if ((result->sourceType == 7) || (result->sourceType == 8)) {
        QImage guoZhanModalImage;
        guoZhanModalImage.load(":/6航班回查/Images/6航班回查/过站.png");
        guoZhanModalImage = guoZhanModalImage.scaled(48
                                                     , 24
                                                     , Qt::IgnoreAspectRatio
                                                     , Qt::SmoothTransformation);
        QPixmap guoZhanModalPixmap = QPixmap::fromImage(guoZhanModalImage);
        QLabel *guoZhanModalLabel = new QLabel(itemWidget);
        guoZhanModalLabel->raise();
        guoZhanModalLabel->setGeometry(35, 15, 48, 24);
        guoZhanModalLabel->setPixmap(guoZhanModalPixmap);
        guoZhanModalLabel->setFixedSize(48, 24);
        guoZhanModalLabel->setAlignment(Qt::AlignCenter);
    }

    QLabel *nameTitleLabel = new QLabel(itemWidget);
    nameTitleLabel->setGeometry(180, 15, 145, 38);
    nameTitleLabel->setText("旅客姓名：");
    nameTitleLabel->setFixedSize(145, 38);
    nameTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    nameTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *nameLabel = new QLabel(itemWidget);
    nameLabel->setGeometry(306, 15, 330, 38);
    nameLabel->setText(result->passengerName);
    nameLabel->setFixedSize(330, 38);
    nameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    nameLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *cardTitleLabel = new QLabel(itemWidget);
    cardTitleLabel->setGeometry(180, 60, 117, 38);
    cardTitleLabel->setText("证件号：");
    cardTitleLabel->setFixedSize(117, 38);
    cardTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    cardTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *cardLabel = new QLabel(itemWidget);
    cardLabel->setGeometry(278, 60, 350, 38);
    cardLabel->setText(result->cardNo);
    cardLabel->setFixedSize(350, 38);
    cardLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    cardLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");


    QLabel *flightTitleLabel = new QLabel(itemWidget);
    flightTitleLabel->setGeometry(180, 105, 180, 38);
    flightTitleLabel->setText("航班号/序号：");
    flightTitleLabel->setFixedSize(180, 38);
    flightTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    flightTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *flightLabel = new QLabel(itemWidget);
    flightLabel->setGeometry(342, 105, 300, 38);
    flightLabel->setText(result->flightNumber + "/" + result->boardingNumber);
    flightLabel->setFixedSize(300, 38);
    flightLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    flightLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QLabel *seatTitleLabel = new QLabel(itemWidget);
    seatTitleLabel->setGeometry(180, 150, 117, 38);
    seatTitleLabel->setText("座位号：");
    seatTitleLabel->setFixedSize(117, 38);
    seatTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    seatTitleLabel->setStyleSheet("image: 0; border: 0; background: 0; font: 19pt; color: rgb(255, 255, 255);");

    QLabel *seatLabel = new QLabel(itemWidget);
    seatLabel->setGeometry(278, 150, 300, 38);
    seatLabel->setText(result->seatNumber);
    seatLabel->setFixedSize(300, 38);
    seatLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    seatLabel->setStyleSheet("image: 0; border: 0; background: 0; font: bold 19pt; color: rgb(0, 228, 255);");

    QPushButton *pushButton = new QPushButton(itemWidget);
    pushButton->setGeometry(0,0,itemWidget->width(),itemWidget->height());
    pushButton->setFocusPolicy(Qt::NoFocus);
    connect(pushButton, &QPushButton::clicked, [=]
    {
        itemWidget->setFocus();
        on_PhotoClicked(result);
    });

    //splitWidget;
    QLabel *splitLabel = new QLabel(itemWidget);
    splitLabel->setGeometry(6, 0, 740, 2);
    splitLabel->setStyleSheet("image: 0; background: 0; border-radius: 0; border-width: 1px; border-style: dashed; border-color: rgb(135, 183, 194);");
}


QString FlightEnquires::findPhotoPath(QString cardNumber
                                      , QString flightNumber
                                      , QString boardingNumber
                                      , QString seatNumber)
{
    if (!cardNumber.isEmpty()) {
        int count = 0;
        int found = 0;
        for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
            if (0 == QString::compare(cardNumber, m_all_ppl_infos.parsedResult.results[i].cardNo)) {
                count += 1;
                found = i;
            }
        }

        if (count == 1) {
            return m_all_ppl_infos.parsedResult.results[found].photoPath;
        } else {
            for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
                if ((0 == QString::compare(flightNumber, m_all_ppl_infos.parsedResult.results[i].flightNumber))
                        &&(0 == QString::compare(boardingNumber, m_all_ppl_infos.parsedResult.results[i].boardingNumber))
                        &&(0 == QString::compare(seatNumber, m_all_ppl_infos.parsedResult.results[i].seatNumber))) {
                    return m_all_ppl_infos.parsedResult.results[i].photoPath;
                }
            }
        }
    } else {
        for (int i = 0; i < m_all_ppl_infos.parsedResult.validSize; i++) {
            if ((0 == QString::compare(flightNumber, m_all_ppl_infos.parsedResult.results[i].flightNumber))
                    &&(0 == QString::compare(boardingNumber, m_all_ppl_infos.parsedResult.results[i].boardingNumber))
                    &&(0 == QString::compare(seatNumber, m_all_ppl_infos.parsedResult.results[i].seatNumber))) {
                return m_all_ppl_infos.parsedResult.results[i].photoPath;
            }
        }
    }

    return QString();
}
