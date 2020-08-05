/********************************************************************************
** Form generated from reading UI file 'lineEditDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEEDITDIALOG_H
#define UI_LINEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeFlightDialog
{
public:
    QWidget *widget_msg_big;
    QWidget *widget_border;
    QPushButton *pushButton_X_big;
    QLabel *label_title;
    QWidget *widget_inputFlighNO_;
    QPushButton *pushButton_commit;
    QLabel *label_curFlightNO_;
    QLineEdit *lineEdit_flightNO_;

    void setupUi(QDialog *ChangeFlightDialog)
    {
        if (ChangeFlightDialog->objectName().isEmpty())
            ChangeFlightDialog->setObjectName(QString::fromUtf8("ChangeFlightDialog"));
        ChangeFlightDialog->resize(800, 978);
        widget_msg_big = new QWidget(ChangeFlightDialog);
        widget_msg_big->setObjectName(QString::fromUtf8("widget_msg_big"));
        widget_msg_big->setEnabled(true);
        widget_msg_big->setGeometry(QRect(0, 0, 800, 978));
        widget_msg_big->setFocusPolicy(Qt::NoFocus);
        widget_msg_big->setStyleSheet(QString::fromUtf8("#widget_msg_big{background-color: rgba(0, 0, 0, 0.5);}"));
        widget_border = new QWidget(widget_msg_big);
        widget_border->setObjectName(QString::fromUtf8("widget_border"));
        widget_border->setGeometry(QRect(100, 330, 600, 350));
        QFont font;
        font.setPointSize(20);
        widget_border->setFont(font);
        widget_border->setFocusPolicy(Qt::NoFocus);
        widget_border->setStyleSheet(QString::fromUtf8("#widget_border{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\345\244\247\345\274\271\347\252\227BG.png);}\n"
"\n"
""));
        pushButton_X_big = new QPushButton(widget_border);
        pushButton_X_big->setObjectName(QString::fromUtf8("pushButton_X_big"));
        pushButton_X_big->setGeometry(QRect(520, 15, 37, 37));
        pushButton_X_big->setFocusPolicy(Qt::NoFocus);
        pushButton_X_big->setStyleSheet(QString::fromUtf8("border:0;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_X_big->setIcon(icon);
        pushButton_X_big->setIconSize(QSize(29, 29));
        label_title = new QLabel(widget_border);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(0, 0, 552, 62));
        QFont font1;
        font1.setPointSize(30);
        label_title->setFont(font1);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_title->setScaledContents(true);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->raise();
        pushButton_X_big->raise();
        widget_inputFlighNO_ = new QWidget(widget_msg_big);
        widget_inputFlighNO_->setObjectName(QString::fromUtf8("widget_inputFlighNO_"));
        widget_inputFlighNO_->setGeometry(QRect(150, 380, 500, 280));
        pushButton_commit = new QPushButton(widget_inputFlighNO_);
        pushButton_commit->setObjectName(QString::fromUtf8("pushButton_commit"));
        pushButton_commit->setGeometry(QRect(80, 180, 336, 47));
        pushButton_commit->setFocusPolicy(Qt::NoFocus);
        pushButton_commit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:0;\n"
"	image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\346\217\220\344\272\244.png);\n"
"}\n"
"QPushButton:pressed{\n"
"	image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\346\217\220\344\272\244-\346\213\267\350\264\235.png);\n"
"}\n"
""));
        pushButton_commit->setIconSize(QSize(140, 40));
        label_curFlightNO_ = new QLabel(widget_inputFlighNO_);
        label_curFlightNO_->setObjectName(QString::fromUtf8("label_curFlightNO_"));
        label_curFlightNO_->setGeometry(QRect(290, 20, 150, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(26);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setKerning(true);
        label_curFlightNO_->setFont(font2);
        label_curFlightNO_->setFocusPolicy(Qt::NoFocus);
        label_curFlightNO_->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_curFlightNO_->setTextFormat(Qt::AutoText);
        label_curFlightNO_->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        lineEdit_flightNO_ = new QLineEdit(widget_inputFlighNO_);
        lineEdit_flightNO_->setObjectName(QString::fromUtf8("lineEdit_flightNO_"));
        lineEdit_flightNO_->setEnabled(true);
        lineEdit_flightNO_->setGeometry(QRect(80, 70, 336, 50));
        lineEdit_flightNO_->setFont(font);
        lineEdit_flightNO_->setFocusPolicy(Qt::StrongFocus);
        lineEdit_flightNO_->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background:transparent;\n"
"	border-image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        lineEdit_flightNO_->setInputMethodHints(Qt::ImhPreferUppercase);
        lineEdit_flightNO_->setAlignment(Qt::AlignCenter);

        retranslateUi(ChangeFlightDialog);

        QMetaObject::connectSlotsByName(ChangeFlightDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeFlightDialog)
    {
        ChangeFlightDialog->setWindowTitle(QApplication::translate("ChangeFlightDialog", "Dialog", nullptr));
        pushButton_X_big->setText(QString());
        label_title->setText(QApplication::translate("ChangeFlightDialog", "\346\226\260\345\242\236\350\210\252\347\217\255", nullptr));
        pushButton_commit->setText(QString());
        label_curFlightNO_->setText(QString());
        lineEdit_flightNO_->setInputMask(QString());
        lineEdit_flightNO_->setText(QString());
        lineEdit_flightNO_->setPlaceholderText(QApplication::translate("ChangeFlightDialog", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeFlightDialog: public Ui_ChangeFlightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEEDITDIALOG_H
