#ifndef PORTRAITCOLLECTION_H
#define PORTRAITCOLLECTION_H

#include  "ServerInterface/api_param_def.h"

#include <QWidget>
#include <QDate>


class MessageDialog;

namespace Ui {
class PortraitCollection;
}

class PortraitCollection : public QWidget
{
    Q_OBJECT
private:
    enum ChannelId{
        Channel_L = 1,
        Channel_R = 2
    };

public:
    explicit PortraitCollection(QWidget *parent = nullptr);
    ~PortraitCollection();

public:
    void updateCurrentDate();

    void updtCrrntCllctInfo(int channel, QJsonObject json);

    inline FlightPlan* getFlightPlan(){
        return &m_flightPlan;
    }

signals:
    void GateNetStat(const QString title = "", const QString msg = "");
    void recivedTicketInfo_adult();
    void recivedTicketInfo_baby();

private slots:
    void on_ReadDataResult(const BoardingTicketInfo& ticketInfo);

    void on_selectionChanged();

    void on_calendarWidgetHide();

    void on_pushButton_calendar_clicked();

    void on_pushButton_keyboard_clicked();

    void on_pushButton_commit_clicked();

    void on_pushButton_cancel_Colecting_clicked();

    void on_pushButton_start_Colecting_clicked();

    void on_pushButton_end_Colecting_clicked();

    void on_pushButton_manualInputInfo_clicked();

    void on_toolButton_childMode_R_clicked(bool checked);

    void on_toolButton_childMode_L_clicked(bool checked);

    void on_pushButton_release_R_clicked();

    void on_pushButton_release_L_clicked();

    void on_pushButton_prevent_R_clicked();

    void on_pushButton_prevent_L_clicked();

private:
    void setUI();
    bool isContentComplete();
    void showFlightInfo();
    void showCollectResult(int channel, int result, Collect_Info &info);
    void updateCollectCount(Collect_Info &info);
    void clearCurrentCollectInfo(ChannelId channel);
    void childButtonClicked(ChannelId channel);
    int  ticket_manualPass(ChannelId channel);
    void endCollect();
    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    typedef struct siglePPLInfo_judgeExsist{
        QString flightNo;
        QString flightDay;
        QString boardingNumber;
        QString seatId;
        QString startPort;
        QString endPort;
        QString cardId;
        QString nameZh;

        siglePPLInfo_judgeExsist& setAdult(const Collect_Info& collect){
            this->flightNo = collect.flightNo;
            this->flightDay = collect.flightDay;
            this->boardingNumber = collect.boardingNumber;
            this->seatId = collect.seatId;
            this->startPort = collect.startPort;
            this->endPort = collect.endPort;
            this->cardId = collect.cardId;
            this->nameZh = collect.nameZh;

            return *this;
        }

        siglePPLInfo_judgeExsist& setBaby(const Collect_Info& collect){
            this->flightNo = collect.babyFlightNo;
            this->flightDay = collect.babyFlightDay;
            this->boardingNumber = collect.babyBoardingNumber;
            this->seatId = collect.babySeatId;
            this->startPort = collect.babyStartPort;
            this->endPort = collect.babyEndPort;
            this->cardId = collect.babyCardId;
            this->nameZh = collect.babyNameZh;

            return *this;
        }

        bool operator==(const siglePPLInfo_judgeExsist& other)const{
            if (this == &other){
                return true;
            }

            if (!this->cardId.isEmpty() && this->cardId == other.cardId){
                return true;
            }
            else if(this->flightNo == other.flightNo
                    && this->boardingNumber == other.boardingNumber
                    && this->flightDay == other.flightDay
                    && this->seatId == other.seatId
                    && !this->flightNo.isEmpty()
                    && !this->boardingNumber.isEmpty()
                    && !this->seatId.isEmpty()
                    && !this->flightDay.isEmpty()){
                return true;
            }
            else return false;
        }
    }siglePPLInfo_judgeExsist;

private:
    Ui::PortraitCollection *ui;

    int m_collectType{1};  //采集类型： 0-中转采集（暂时不用）, 1-过站，2-备降采集
    int m_Type_face_or_fast{1};  //采集方式： 0-人像采集， 1-快速采集

    QStringList m_enquiryFlightNO;
    QDate m_enqueryFlightDate;
    FlightPlan m_flightPlan;//从服务器查询的航班计划

    Collect_Info m_currentInfo_L;
    Collect_Info m_currentInfo_R;
    bool isForceTakephoto_L{false}; //强制抓拍
    bool isForceTakephoto_R{false}; //强制抓拍

    int m_collect_ppl_count{0};
    QVector<siglePPLInfo_judgeExsist> m_all_siglePPLInfos;//采用的本地累加人数方式,用于判重

    BoardingTicketInfo m_adultTicket;
    BoardingTicketInfo m_babyTicket;

    MessageDialog* exceptionFlightNo_dlg{nullptr};

    friend class HomePage;
    friend class RealtimeBoarding;
};

#endif // PORTRAITCOLLECTION_H
