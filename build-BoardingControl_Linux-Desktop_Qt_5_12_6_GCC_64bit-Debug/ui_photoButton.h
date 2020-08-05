/********************************************************************************
** Form generated from reading UI file 'photoButton.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOBUTTON_H
#define UI_PHOTOBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoButtonSinglePPL
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *label_photo;
    QLabel *label_transferType;
    QWidget *widget_info;
    QLabel *label_seatNO;
    QLabel *label_flightDay;

    void setupUi(QWidget *PhotoButtonSinglePPL)
    {
        if (PhotoButtonSinglePPL->objectName().isEmpty())
            PhotoButtonSinglePPL->setObjectName(QString::fromUtf8("PhotoButtonSinglePPL"));
        PhotoButtonSinglePPL->resize(170, 270);
        PhotoButtonSinglePPL->setMinimumSize(QSize(170, 270));
        PhotoButtonSinglePPL->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(PhotoButtonSinglePPL);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 2);
        widget = new QWidget(PhotoButtonSinglePPL);
        widget->setObjectName(QString::fromUtf8("widget"));
        label_photo = new QLabel(widget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(0, 0, 168, 214));
        label_photo->setMinimumSize(QSize(160, 214));
        label_photo->setMaximumSize(QSize(168, 214));
        label_photo->setPixmap(QPixmap(QString::fromUtf8(":/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\347\205\247\347\211\207-\345\260\217.png")));
        label_photo->setAlignment(Qt::AlignCenter);
        label_transferType = new QLabel(widget);
        label_transferType->setObjectName(QString::fromUtf8("label_transferType"));
        label_transferType->setGeometry(QRect(5, 5, 50, 30));
        label_transferType->setStyleSheet(QString::fromUtf8(""));
        label_transferType->setPixmap(QPixmap(QString::fromUtf8(":/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\350\277\207\347\253\231.png")));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_info = new QWidget(PhotoButtonSinglePPL);
        widget_info->setObjectName(QString::fromUtf8("widget_info"));
        widget_info->setMinimumSize(QSize(170, 52));
        widget_info->setMaximumSize(QSize(170, 52));
        widget_info->setStyleSheet(QString::fromUtf8("#widget_info{border-radius:10px;background-color: rgb(1, 65, 109);border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\347\237\251\345\275\242-4363.png);}\n"
"\n"
"\n"
""));
        label_seatNO = new QLabel(widget_info);
        label_seatNO->setObjectName(QString::fromUtf8("label_seatNO"));
        label_seatNO->setGeometry(QRect(0, 0, 82, 54));
        QFont font;
        font.setPointSize(24);
        label_seatNO->setFont(font);
        label_seatNO->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_seatNO->setAlignment(Qt::AlignCenter);
        label_flightDay = new QLabel(widget_info);
        label_flightDay->setObjectName(QString::fromUtf8("label_flightDay"));
        label_flightDay->setGeometry(QRect(80, 15, 90, 41));
        QFont font1;
        font1.setPointSize(12);
        label_flightDay->setFont(font1);
        label_flightDay->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_flightDay->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(widget_info, 1, 0, 1, 1);


        retranslateUi(PhotoButtonSinglePPL);

        QMetaObject::connectSlotsByName(PhotoButtonSinglePPL);
    } // setupUi

    void retranslateUi(QWidget *PhotoButtonSinglePPL)
    {
        PhotoButtonSinglePPL->setWindowTitle(QApplication::translate("PhotoButtonSinglePPL", "Form", nullptr));
        label_photo->setText(QString());
        label_transferType->setText(QString());
        label_seatNO->setText(QApplication::translate("PhotoButtonSinglePPL", "OINF", nullptr));
        label_flightDay->setText(QApplication::translate("PhotoButtonSinglePPL", "2020.05.05", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhotoButtonSinglePPL: public Ui_PhotoButtonSinglePPL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOBUTTON_H
