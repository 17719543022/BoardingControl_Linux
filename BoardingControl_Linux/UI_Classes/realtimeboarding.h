#ifndef REALTIMEBOARDING_H
#define REALTIMEBOARDING_H

#include  "ServerInterface/api_param_def.h"
#include <QWidget>
#include <QJsonObject>

namespace Ui {
class RealtimeBoarding;
}

class MessageDialog;
class RealtimeBoarding : public QWidget
{
    Q_OBJECT

public:
    typedef struct user_BoardingInfo{
            QString name;
            BoardingTicketInfo_S ticket;
            QByteArray scenePhoto;
            void clear(){
                name.clear();
                ticket.clear();
                scenePhoto.clear();
            }
    }user_BoardingInfo;


    explicit RealtimeBoarding(QWidget *parent = nullptr);
    ~RealtimeBoarding();

    inline FlightPlan* getFlightPlan(){
        return &m_flightPlan;
    }

public slots:
    void handleResults_flightPlane(API_PARAM_TYPE type, void* m_flightPlan);
    void colorPlaneLabel(const FlightPlan&);
    bool is_statrtBoarding(const FlightPlan&);
    bool is_endBoarding(const FlightPlan&);
    void update_ppl_num(const content301&);
    int on_changeBoardingMod();

private slots:
    void on_pushButton_startBoarding_clicked();
    void on_pushButton_endBoarding_clicked();
    void on_pushButton_cancelFlight_clicked();
    void on_pushButton_pplStats_clicked();
    void on_pushButton_otherFlight_clicked();
    void on_pushButton_find_clicked();
    void on_pushButton_faceImage_L_clicked();
    void on_pushButton_faceImage_R_clicked();

    void on_pushButton_psngrInfo_L_clicked();

    void on_pushButton_psngrInfo_R_clicked();

private:
    void setUI();
    void showFlightInfo();

    void on_showBoardingResult(int channel, bool isManualOperation, int result, int transferType, bool hasSecurityInfo
                                                 , int seatLabel, bool hasBaby, bool moreTicket, bool isMarked
                                                 , const QString name, const QString cardId, const BoardingTicketInfo ticketinfo, const QByteArray faceImage);
    void clearAllBoardingInfos();
    void clearInfoThrough_L();
    void clearInfoThrough_R();
    void changeButtonStatus(bool isBording);

public:
    FlightPlan m_flightPlan;
    user_BoardingInfo user_left;//左通道用户
    user_BoardingInfo user_right;//右通道用户

    int m_boardingMode{0};//登机模式： 0-人脸登机； 1-快速登机

private:
    Ui::RealtimeBoarding *ui;

    bool m_isBording{false};//是否正在登机
    int m_boardingNum{0};    //当前登机人数

    MessageDialog *excpDlg{nullptr};

    friend class HomePage;
    friend class inquiryWidget;
//    friend class ParseMQmsg;
//    friend class WorkAnotherThread;
};

#endif // REALTIMEBOARDING_H
