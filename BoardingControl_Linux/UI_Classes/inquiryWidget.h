#ifndef INQUIRYWIDGET_H
#define INQUIRYWIDGET_H

#include <QWidget>
#include <QJsonArray>
#include "ServerInterface/api_param_def.h"


namespace Ui {
class inquiryWidget;
}

class QTimeLine;
class QNetworkAccessManager;
class  QNetworkReply;
class QLabel;
class inquiryWidget : public QWidget
{
    Q_OBJECT

public:
    ~inquiryWidget();

    inline static inquiryWidget* instance(){
        //static类型的单例无法方便的使用QObject::setParent();
        //如果使用static实例化qt界面单例对象，那么需要在每次QObject::setParent()之后将parent重新设为nullptr，解除父子关系；
        //所以用new的单例可以进行QObject::setParent();对于界面类非常好用;
        if (m_pInstance == nullptr)
            m_pInstance = new inquiryWidget();
        return m_pInstance;
    }

private:
    //内嵌类，检查是否已经销毁new出来的单例。
    class CGarbo{
        public:
        ~CGarbo(){
            //注意:利用析构函数中将m_pInstance置空来判断是否已经销毁该单例;
            if (m_pInstance != nullptr){
                delete m_pInstance;
                m_pInstance = nullptr;
            }
        }
    };

    explicit inquiryWidget(QWidget *parent = nullptr);
    static inquiryWidget *m_pInstance;
    static CGarbo Garbo;//定义一个静态成员，程序结束时会自动调用析构函数；

public:
    enum Channel {
        Channel_Special = 0,
        Channel_1,
        Channel_2,
    };

    void openWindow(Channel Channel);
    void closeWindow();

    //channel旅客通道：0-表示点击查询按钮打开的此页面，1-１号通道,　2-２号通道
    void enquiry(const QString& text);

private:
    Ui::inquiryWidget *ui;

    QTimeLine *timeLine{nullptr};
    enum Direction {
        LeftToRight,
        RightToLeft
    };

    QNetworkAccessManager *netPicture_securityImg{nullptr}; //use to show net picture;
    QNetworkAccessManager *netPicture_recheckImg{nullptr}; //use to show net picture;
    QNetworkAccessManager *netPicture_transferImg{nullptr}; //use to show net picture;
    QNetworkAccessManager *netPicture_boardingImg{nullptr}; //use to show net picture;

    QJsonArray arry_info; //存放查询到的用户信息,可能多个; (more infomation at Yapi:2.3.24)

    BoardingMode_ManualPass_Send m_userInfo;

    QLabel *securityImg{nullptr};    //安检照片
    QLabel *securityStat{nullptr};   //安检状态
    QLabel *recheckImg{nullptr};     //复核照片
    QLabel *recheckStat{nullptr};    //复核状态
    QLabel *transferImg{nullptr};    //中转经停照片
    QLabel *transferStat{nullptr};   //中转经停状态
    QLabel *boardingImg{nullptr};    //登机口照片
    QLabel *boardingStat{nullptr};   //登机口状态
    QLabel *cancelTicket_security{nullptr};    //取消值机
    QLabel *cancelTicket_review{nullptr};    //取消值机

    Channel _channel{Channel_Special};

    bool m_isPass = false; //是否通行, 是-通行,否-拦截;

private:
    void setUI();
    void resetEnquiryInfo();
    void initFrame();
    void initNetManager();
    void startMove(Direction direction);

    int enquiry_ppl(const QString &text, QJsonObject &retObject);
    int enquiry_ppl(const BoardingTicketInfo& tickertInfo, QJsonObject &retObject);

    void set_security_stat_label(int security_passType, int status);
    void set_review_stat_label(int security_passType, int status);
    void set_transfer_stat_label(int status);
    void set_boarding_stat_label(int boarding_passType, int status);

    void showSecurityInfo(const QJsonObject & result, int &column);
    void showNoSecurityInfo(const QJsonObject & result, int &column);
    void showReviewInfo(const QJsonObject & result, int &column);
    void showNoReviewInfo(const QJsonObject & result, int &column);
    void showTransferInfo(const QJsonObject & result, int &column);
    void showBoardingInfo(const QJsonObject & result, int &column);

    void show_select_ppl_widget(const QJsonArray &arry_info);
    void show_result_widget(const QJsonObject & result);
    void clearSelectPplLayout();

private slots:
    void on_IDCardReadInfo(QString cardID, QString nameZh, QByteArray img);

    void on_ReadTicketResult(const BoardingTicketInfo& ticketINfo);

    void on_replyFinished(QNetworkReply* reply);

    void on_pushButton_enquiry_clicked();

    void on_pushButton_choice_ppl_commit_clicked();

    void on_pushButton_pass_clicked();

    void on_pushButton_prevent_clicked();

    void on_pushButton_channel_1_clicked();

    void on_pushButton_channel_2_clicked();

    void on_pushButton_cancelPass_clicked();

    void on_pushButton_specialPassenger_clicked();


    void on_pushButton_return_clicked();

};

#endif // INQUIRYWIDGET_H
