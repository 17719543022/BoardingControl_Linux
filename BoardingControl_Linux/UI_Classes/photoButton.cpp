#include "photoButton.h"
#include "ui_photoButton.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

PhotoButtonSinglePPL::PhotoButtonSinglePPL(const QByteArray &photoData, const BoardingMode_ManualPass_Send &userInfo, const QJsonObject &qJson, QWidget *parent) :
    QToolButton(parent),
    ui(new Ui::PhotoButtonSinglePPL),
    _srcData(qJson),
    _userInfo(userInfo)

{
    ui->setupUi(this);

    _photo.loadFromData(photoData);

    setUI();
}

PhotoButtonSinglePPL::PhotoButtonSinglePPL(const QUrl &photoUrl, const BoardingMode_ManualPass_Send &userInfo, const QJsonObject &qJson, QWidget *parent) :
    QToolButton(parent),
    ui(new Ui::PhotoButtonSinglePPL),
    _photoUrl(photoUrl),
    _srcData(qJson),
    _userInfo(userInfo)
{
    ui->setupUi(this);

    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
    connect(mngr, &QNetworkAccessManager::finished, this, &PhotoButtonSinglePPL::on_replyFinished/*, Qt::BlockingQueuedConnection*/);
    mngr->get(QNetworkRequest(_photoUrl));

    setUI();
}



void PhotoButtonSinglePPL::setUI()
{
    this->setCheckable(true);
    this->setAutoExclusive(true);

    this->setStyleSheet("QToolButton{border:none; \
                        } \
                        QToolButton:checked{border:none; \
                            background-color: rgb(150, 200, 200); \
                        }");

    QString flightDay = _userInfo.date;
    ui->label_seatNO->setText(_userInfo.seatId);
    ui->label_flightDay->setText(flightDay.insert(4,".").insert(7,"."));

    if (!_photo.isNull()) ui->label_photo->setPixmap(_photo);

    switch (_userInfo.transferSourceType) {
        case 0:
            ui->label_transferType->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
            break;
        case 1:
                ui->label_transferType->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
            break;
        case 3:
            ui->label_transferType->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/中转.png"));
            break;
        case 4:
            ui->label_transferType->setPixmap(QPixmap(":/3实时登机/Images/3实时登机/3.2.1/过站.png"));
            break;
        default:
            ui->label_transferType->clear();
            break;
    }
}


PhotoButtonSinglePPL::~PhotoButtonSinglePPL()
{
    delete ui;
}


void PhotoButtonSinglePPL::on_replyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytePhoto = reply->readAll();
        _photo.loadFromData(bytePhoto);
        ui->label_photo->setPixmap(_photo.scaled(ui->label_photo->size()));
    }
    reply->deleteLater();
}
