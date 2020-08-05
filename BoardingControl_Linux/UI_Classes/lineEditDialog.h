#ifndef CHANGEFLIGHTDIALOG_H
#define CHANGEFLIGHTDIALOG_H

#include <QDialog>
#include "ticketScancer/paramdef.h"

namespace Ui {
class ChangeFlightDialog;
}

class QString;
class LineEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LineEditDialog(QWidget *parent = nullptr);
    ~LineEditDialog();

public :
    inline QString getLineEditText(){return m_lineEditText;}
    void setTitle(const QString& title);
    void setLineEdit_PlaceholderText(const QString& text);
    void on_IDCardReadOK(QString cardID, QString nameZh, QByteArray faceImg);
    void on_TicketRead(const BoardingTicketInfo& btInfo);

private:
    void setUI();

private slots:
    void on_pushButton_commit_clicked();

    void on_pushButton_X_big_clicked();

public:
    QByteArray IDCard_Img;
    QString IDcard_NameZh;
    QString IDCard_CardID;
    BoardingTicketInfo ticketInfo;

private:
    Ui::ChangeFlightDialog *ui;

    QString m_lineEditText = "";

};

#endif // CHANGEFLIGHTDIALOG_H
