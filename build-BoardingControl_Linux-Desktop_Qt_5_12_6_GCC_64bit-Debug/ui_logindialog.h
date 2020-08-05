/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QFrame *frame_error;
    QWidget *we;
    QLabel *label;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_exit;
    QFrame *frame_input;
    QWidget *widget_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QWidget *widget_1;
    QLabel *label_1;
    QLineEdit *lineEdit_userName;
    QPushButton *pushButton_login;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(800, 1280);
        frame_error = new QFrame(LoginDialog);
        frame_error->setObjectName(QString::fromUtf8("frame_error"));
        frame_error->setGeometry(QRect(0, 0, 800, 1280));
        frame_error->setStyleSheet(QString::fromUtf8("#frame_error{background-color: rgba(0, 0, 0, 0.5);}"));
        we = new QWidget(frame_error);
        we->setObjectName(QString::fromUtf8("we"));
        we->setGeometry(QRect(124, 468, 552, 345));
        QFont font;
        font.setPointSize(20);
        we->setFont(font);
        we->setStyleSheet(QString::fromUtf8("#we{image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\274\271\347\252\227BG.png);}\n"
""));
        label = new QLabel(we);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 130, 552, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setKerning(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        pushButton_yes = new QPushButton(we);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(206, 230, 140, 40));
        pushButton_yes->setFocusPolicy(Qt::NoFocus);
        pushButton_yes->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\347\241\256--\350\256\244-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\347\241\256--\350\256\244-\346\213\267\350\264\235-2.png);}"));
        pushButton_yes->setIconSize(QSize(139, 39));
        pushButton_exit = new QPushButton(we);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(485, 40, 30, 30));
        pushButton_exit->setFocusPolicy(Qt::NoFocus);
        pushButton_exit->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235-\346\214\211\344\270\213.png);}"));
        pushButton_exit->setIconSize(QSize(29, 29));
        frame_input = new QFrame(LoginDialog);
        frame_input->setObjectName(QString::fromUtf8("frame_input"));
        frame_input->setGeometry(QRect(0, 0, 800, 1280));
        frame_input->setFocusPolicy(Qt::NoFocus);
        frame_input->setLayoutDirection(Qt::LeftToRight);
        frame_input->setStyleSheet(QString::fromUtf8("#frame_input{background-image: url(Images/\347\231\273\345\275\225\347\225\214\351\235\242/BG.png);}\n"
""));
        frame_input->setFrameShape(QFrame::StyledPanel);
        frame_input->setFrameShadow(QFrame::Plain);
        widget_2 = new QWidget(frame_input);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(186, 843, 428, 72));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);}"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 80, 72));
        label_2->setStyleSheet(QString::fromUtf8("image:url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/mima-(2).png);"));
        lineEdit_password = new QLineEdit(widget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(70, 0, 350, 72));
        QFont font2;
        font2.setPointSize(30);
        lineEdit_password->setFont(font2);
        lineEdit_password->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_password->setStyleSheet(QString::fromUtf8("QLineEdit{color: rgb(255, 255, 255);\n"
"background:transparent;\n"
"border-style:none;}\n"
"\n"
""));
        lineEdit_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhPreferLowercase|Qt::ImhSensitiveData);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        widget_1 = new QWidget(frame_input);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setGeometry(QRect(186, 690, 428, 72));
        widget_1->setLayoutDirection(Qt::LeftToRight);
        widget_1->setAutoFillBackground(false);
        widget_1->setStyleSheet(QString::fromUtf8("#widget_1{image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);}"));
        label_1 = new QLabel(widget_1);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 0, 80, 72));
        label_1->setStyleSheet(QString::fromUtf8("image:url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\347\224\250\346\210\267\345\220\215.png);"));
        lineEdit_userName = new QLineEdit(widget_1);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(70, 0, 350, 72));
        lineEdit_userName->setFont(font2);
        lineEdit_userName->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_userName->setStyleSheet(QString::fromUtf8("QLineEdit{color: rgb(255, 255, 255);\n"
"background:transparent;\n"
"border-style:none;}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        lineEdit_userName->setInputMethodHints(Qt::ImhPreferLowercase);
        lineEdit_userName->setReadOnly(true);
        pushButton_login = new QPushButton(frame_input);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(289, 983, 222, 72));
        QFont font3;
        font3.setPointSize(40);
        pushButton_login->setFont(font3);
        pushButton_login->setFocusPolicy(Qt::TabFocus);
        pushButton_login->setStyleSheet(QString::fromUtf8("border:0;\n"
"background-color: rgb(13, 225, 255);\n"
"border-radius:10px;"));
        frame_input->raise();
        frame_error->raise();
        QWidget::setTabOrder(lineEdit_userName, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_login);
        QWidget::setTabOrder(pushButton_login, pushButton_yes);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201", nullptr));
        pushButton_yes->setText(QString());
        pushButton_exit->setText(QString());
        label_2->setText(QString());
        lineEdit_password->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        label_1->setText(QString());
        lineEdit_userName->setText(QApplication::translate("LoginDialog", "admin", nullptr));
        lineEdit_userName->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
