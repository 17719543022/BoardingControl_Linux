#ifndef FLIGHTENQUIRES_H
#define FLIGHTENQUIRES_H

#include <QWidget>
#include <QTableWidget>
#include "ServerInterface/api_param_def.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QNetworkAccessManager>

namespace Ui {
class FlightEnquires;

enum DisplayTab {
    DepositoryTab,
    BoardingTab,
    NotBoardingTab
};

enum DisplayType {
    DisplayNormal,
    DisplayNullErr
};
}

class InterceptPushButton : public QPushButton
{
    Q_OBJECT

public:
    InterceptPushButton(QWidget *parent, bool isInterceptLabel);

private slots:
    void changeIsInterceptLabel();

private:
    int isInterceptLabel;
};

class FlightEnquires : public QWidget
{
    Q_OBJECT

public:
    explicit FlightEnquires(QWidget *parent = Q_NULLPTR);

    void ppl_statistics(QString m_queryFlightNo);
    void enterStatisticsMode();
    void quitStatisticsMode();

    void fillDepAndUnboardWithMQ(const QJsonArray &content);

    void fillBoardAndUnboard_whileBoarding(QString flightNo
                                      , QString flightDay
                                      , const QByteArray &faceImg
                                      , int recheckType
                                      , const QJsonObject &userInfo
                                      , const QJsonObject &manualInfo);

    ~FlightEnquires();

signals:
    void networkStat(bool netStat, const QString title = "", const QString msg = "");


private slots:
    void on_queryPushButton_clicked();

    void on_orgDepPushButton_clicked();

    void on_boardingPushButton_clicked();

    void on_notboardingPushButton_clicked();

    void on_filterPushButton_clicked();

    void on_orgDepSliderChanged(int p);

    void on_boardingSliderChanged(int p);

    void on_notBoardingSliderChanged(int p);

    void on_removeRowClicked(int widgetIndex);

    void on_interceptClicked(int widgetIndex);

    void on_PhotoClicked(const FlightReviewResult *result);

private:
    int query(QString &flightNo);

    void fillTableGradually(const FlightReviewResponse &m_all_ppl_infos, QTableWidget *table, Ui::DisplayTab tab, QString boardingNumber = QString());

    QPixmap getQPixmapSync(QString str);

    bool isAlreadyExist(const QJsonValue &json);

    void showFlightInfo(FlightPlan &flightInfo);

    void clearAllInfo();

    void showResultOnTableWidget(const FlightReviewResult *results, QWidget *itemWidget);

    QString findPhotoPath(QString cardNumber
                                          , QString flightNumber
                                          , QString boardingNumber
                                          , QString seatNumber);
private:
    Ui::FlightEnquires *ui;

    FlightReviewResponse m_all_ppl_infos;

    QNetworkAccessManager *naManager;

    QString m_queryFlightNo;

    FlightPlan m_flightPlan;

    bool isStatisticsMode;

    int orgDepFilledNum;

    int orgDepFillIndex;

    int boardingFilledNum;

    int boardingFillIndex;

    int notboardingFilledNum;

    int notboardingFillIndex;

    QString boardingNumberForSlider;

    QPushButton *returnThisPage{nullptr};

    friend class HomePage;
};

#endif // FLIGHTENQUIRES_H
