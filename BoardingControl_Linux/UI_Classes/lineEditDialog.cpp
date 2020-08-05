#include "lineEditDialog.h"
#include "ui_lineEditDialog.h"

LineEditDialog::LineEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeFlightDialog)
{
    ui->setupUi(this);
    this->setUI();
}

LineEditDialog::~LineEditDialog()
{
    delete ui;
}

void LineEditDialog::setUI()
{
    this->setWindowFlags(Qt::FramelessWindowHint);          //Set no border, no minimize button.
    this->setAttribute(Qt::WA_TranslucentBackground,true);        //Set transparent background.
//    this->QWidget::setCursor(QCursor(Qt::BlankCursor));           //Hide mouse point.

    this->setFixedSize(800, 978);
    this->move(0,0);
}

void LineEditDialog::setTitle(const QString& title)
{
    ui->label_title->setText(title);
}
void LineEditDialog::setLineEdit_PlaceholderText(const QString& text)
{
    ui->lineEdit_flightNO_->setPlaceholderText(text);
}

void LineEditDialog::on_IDCardReadOK(QString cardID, QString nameZh, QByteArray faceImg)
{
    IDCard_CardID = cardID;
    IDcard_NameZh = nameZh;
    IDCard_Img = faceImg;
    ui->lineEdit_flightNO_->setText(cardID);
}

void LineEditDialog::on_TicketRead(const BoardingTicketInfo& btInfo)
{
  ticketInfo = btInfo;
  //出发点＃到达站＃航班号＃航班日期＃序号＃座位号
  ui->lineEdit_flightNO_->setText(btInfo.startPort+"#"+btInfo.endPort+"#"+btInfo.flightNo+"#"+btInfo.flightDay+"#"+btInfo.boardingNumber+"#"+btInfo.seatId);
}


void LineEditDialog::on_pushButton_commit_clicked()
{
    if (ui->lineEdit_flightNO_->text().isEmpty()){
        return;
    }
    m_lineEditText = ui->lineEdit_flightNO_->text();
    done(1);
}


void LineEditDialog::on_pushButton_X_big_clicked()
{
    done(0);
}

