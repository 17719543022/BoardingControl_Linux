#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QEventLoop>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog() override;

    void initUI();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_yes_clicked();

    void on_pushButton_exit_clicked();

private:
    void keyPressEvent(QKeyEvent *) override;

private:
    Ui::LoginDialog *ui;
    QString m_username;
    QString m_password;

};

#endif // LOGINDIALOG_H
