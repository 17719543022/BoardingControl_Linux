#include "logindialog.h"
#include "ui_logindialog.h"
#include "settings.h"

#include <QKeyEvent>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);          //Set no border, no minimize button.
    this->setModal(false);
//    this->setAttribute(Qt::WA_TranslucentBackground,true);        //Set transparent background.
//    this->QWidget::setCursor(QCursor(Qt::BlankCursor));           //Hide mouse point.

    this->initUI();

    QByteArray userBase64 = LocalSettings::instance()->value("System/username", "YWRtaW4=").toByteArray();
    QByteArray passwdBase64 = LocalSettings::instance()->value("System/password", "YWRtaW4=").toByteArray();
    m_username = QByteArray::fromBase64(userBase64);
    m_password = QByteArray::fromBase64(passwdBase64);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initUI()
{
    ui->frame_error->hide();
//    ui->lineEdit_userName->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_password->setFocus();
}

void LoginDialog::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    if ((username == m_username) && (password == m_password)){
        accept();
        initUI();
    }
    else
    {
        ui->frame_error->show();
    }
}

void LoginDialog::on_pushButton_yes_clicked()
{
    this->initUI();
}

void LoginDialog::on_pushButton_exit_clicked()
{
    // 不清空用户名和密码
    ui->frame_error->hide();
    ui->pushButton_login->setFocus();
}

void LoginDialog::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        break;
    default:
        return QDialog::keyPressEvent(event);
    }
}
