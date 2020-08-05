/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QWidget *widget_msgbox;
    QWidget *centralWidget;
    QLabel *label_txt;
    QPushButton *pushButton_YES;
    QPushButton *pushButton_X;
    QPushButton *pushButton_NO;
    ScrollText_Horizontal *label_title;
    QTableWidget *flowTableWidget;

    void setupUi(QDialog *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QString::fromUtf8("MessageDialog"));
        MessageDialog->resize(800, 1280);
        MessageDialog->setStyleSheet(QString::fromUtf8(""));
        widget_msgbox = new QWidget(MessageDialog);
        widget_msgbox->setObjectName(QString::fromUtf8("widget_msgbox"));
        widget_msgbox->setEnabled(true);
        widget_msgbox->setGeometry(QRect(0, 0, 800, 1280));
        widget_msgbox->setFocusPolicy(Qt::NoFocus);
        widget_msgbox->setStyleSheet(QString::fromUtf8("#widget_msgbox{background-color: rgba(0, 0, 0, 0.5);}"));
        centralWidget = new QWidget(widget_msgbox);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(100, 330, 600, 350));
        QFont font;
        font.setPointSize(20);
        centralWidget->setFont(font);
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\345\260\217\345\274\271\347\252\227BG.png);}\n"
""));
        label_txt = new QLabel(centralWidget);
        label_txt->setObjectName(QString::fromUtf8("label_txt"));
        label_txt->setGeometry(QRect(0, 75, 600, 170));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setKerning(true);
        label_txt->setFont(font1);
        label_txt->setFocusPolicy(Qt::NoFocus);
        label_txt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_txt->setTextFormat(Qt::AutoText);
        label_txt->setScaledContents(false);
        label_txt->setAlignment(Qt::AlignCenter);
        pushButton_YES = new QPushButton(centralWidget);
        pushButton_YES->setObjectName(QString::fromUtf8("pushButton_YES"));
        pushButton_YES->setGeometry(QRect(360, 260, 140, 40));
        pushButton_YES->setFocusPolicy(Qt::NoFocus);
        pushButton_YES->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\347\241\256--\350\256\244-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\347\241\256--\350\256\244-\346\213\267\350\264\235-2.png);}\n"
""));
        pushButton_YES->setIconSize(QSize(140, 40));
        pushButton_X = new QPushButton(centralWidget);
        pushButton_X->setObjectName(QString::fromUtf8("pushButton_X"));
        pushButton_X->setGeometry(QRect(530, 15, 37, 37));
        pushButton_X->setFocusPolicy(Qt::NoFocus);
        pushButton_X->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235-\346\214\211\344\270\213.png);}"));
        pushButton_X->setIconSize(QSize(29, 29));
        pushButton_NO = new QPushButton(centralWidget);
        pushButton_NO->setObjectName(QString::fromUtf8("pushButton_NO"));
        pushButton_NO->setGeometry(QRect(110, 260, 140, 40));
        pushButton_NO->setFocusPolicy(Qt::NoFocus);
        pushButton_NO->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\217\226\346\266\210-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\217\226\346\266\210-\346\213\267\350\264\235-2.png);}\n"
""));
        pushButton_NO->setIconSize(QSize(140, 40));
        label_title = new ScrollText_Horizontal(centralWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(50, 0, 480, 62));
        QFont font2;
        font2.setPointSize(30);
        label_title->setFont(font2);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_title->setAlignment(Qt::AlignCenter);
        flowTableWidget = new QTableWidget(centralWidget);
        flowTableWidget->setObjectName(QString::fromUtf8("flowTableWidget"));
        flowTableWidget->setGeometry(QRect(50, 75, 500, 260));
        flowTableWidget->setStyleSheet(QString::fromUtf8(""));
        flowTableWidget->raise();
        label_title->raise();
        pushButton_NO->raise();
        pushButton_YES->raise();
        label_txt->raise();
        pushButton_X->raise();

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Dialog", nullptr));
        label_txt->setText(QApplication::translate("MessageDialog", "\346\230\257 \345\220\246 \347\241\256 \350\256\244 \357\274\237", nullptr));
        pushButton_YES->setText(QString());
        pushButton_X->setText(QString());
        pushButton_NO->setText(QString());
        label_title->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
