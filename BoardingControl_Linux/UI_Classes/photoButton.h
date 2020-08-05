#ifndef WIDGETSINGLEPPL_H
#define WIDGETSINGLEPPL_H

#include <QToolButton>
#include <QUrl>

#include "ServerInterface/api_param_def.h"


namespace Ui {
class PhotoButtonSinglePPL;
}

class QNetworkReply;
class PhotoButtonSinglePPL : public QToolButton
{
    Q_OBJECT

public:
    PhotoButtonSinglePPL(const QByteArray &photoData, const BoardingMode_ManualPass_Send &userInfo, const QJsonObject &qJson, QWidget *parent = nullptr);
    PhotoButtonSinglePPL(const QUrl &photoUrl, const BoardingMode_ManualPass_Send &userInfo, const QJsonObject &qJson, QWidget *parent = nullptr);

    ~PhotoButtonSinglePPL();

    inline const QJsonObject& getSrcData(){return _srcData;}
    inline const BoardingMode_ManualPass_Send& getUserInfo(){return _userInfo;}

private slots:
    void on_replyFinished(QNetworkReply* reply);

private:
    void setUI();

private:
    Ui::PhotoButtonSinglePPL *ui;

    QPixmap _photo;
    QUrl _photoUrl;

    QJsonObject _srcData;
    BoardingMode_ManualPass_Send _userInfo;
};

#endif // WIDGETSINGLEPPL_H
