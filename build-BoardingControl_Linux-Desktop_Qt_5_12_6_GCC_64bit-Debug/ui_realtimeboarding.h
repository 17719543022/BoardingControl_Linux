/********************************************************************************
** Form generated from reading UI file 'realtimeboarding.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEBOARDING_H
#define UI_REALTIMEBOARDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include <ScrollText.h>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_RealtimeBoarding
{
public:
    QWidget *widget_ALL;
    QWidget *widget_flight;
    ScrollText_Horizontal *label_midPlace;
    QWidget *layoutWidget_1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_picture_plane;
    QLabel *label_mainFlightNO_;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_22;
    ScrollText_Horizontal *label_fromPlace;
    QLabel *label_picture_pointTo;
    ScrollText_Horizontal *label_arrivalPlace;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_text_shareFlight;
    ScrollText_Vertical *ScrollText_shareFlight;
    QWidget *widget_pplNum;
    QLabel *label_countTotal;
    QLabel *label_text0;
    QLabel *label_1text;
    QSplitter *splitter_3;
    QLabel *label_2text;
    QLabel *label_countStart;
    QSplitter *splitter_4;
    QLabel *label_3text;
    QLabel *label_countTransfer;
    QSplitter *splitter_5;
    QLabel *label_text4;
    QLabel *label_countMidway;
    QLabel *label_countBoarding;
    QSplitter *splitter_6;
    QLabel *label_text4_2;
    QLabel *label_babyNum;
    QLabel *label_verticalSpace;
    QWidget *widget_time;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLabel *label_departureTime;
    QSplitter *splitter_1;
    QLabel *label_1;
    QLabel *label_boardingTime;
    QWidget *widget_through1;
    QLabel *label_1t;
    QLabel *label_2t;
    QLabel *label_3t;
    QLabel *label_name_L;
    QLabel *label_flightNO__L;
    QLabel *label_seatNO__L;
    QLabel *label_resultStamp_L;
    QLabel *label_name_L_2;
    QPushButton *pushButton_faceImage_L;
    QLabel *label_4t_2;
    QLabel *label_cardNO__L;
    QPushButton *pushButton_psngrInfo_L;
    QLabel *label_transferType_L;
    QLabel *label_resultTab_L;
    QWidget *widget_through2;
    QLabel *label_5t;
    QLabel *label_seatNO__R;
    QLabel *label_flightNO__R;
    QLabel *label_resultStamp_R;
    QLabel *label_6t;
    QLabel *label_4t;
    QLabel *label_name_R;
    QLabel *label_name_L_3;
    QPushButton *pushButton_faceImage_R;
    QLabel *label_cardNO__R;
    QLabel *label_7t;
    QPushButton *pushButton_psngrInfo_R;
    QLabel *label_transferType_R;
    QLabel *label_resultTab_R;
    QPushButton *pushButton_startBoarding;
    QPushButton *pushButton_cancelFlight;
    QPushButton *pushButton_pplStats;
    QPushButton *pushButton_otherFlight;
    QPushButton *pushButton_endBoarding;
    QPushButton *pushButton_find;

    void setupUi(QWidget *RealtimeBoarding)
    {
        if (RealtimeBoarding->objectName().isEmpty())
            RealtimeBoarding->setObjectName(QString::fromUtf8("RealtimeBoarding"));
        RealtimeBoarding->resize(800, 978);
        widget_ALL = new QWidget(RealtimeBoarding);
        widget_ALL->setObjectName(QString::fromUtf8("widget_ALL"));
        widget_ALL->setGeometry(QRect(0, 0, 800, 978));
        widget_ALL->setStyleSheet(QString::fromUtf8("#widget_ALL{background-color: rgb(1, 64, 109);}"));
        widget_flight = new QWidget(widget_ALL);
        widget_flight->setObjectName(QString::fromUtf8("widget_flight"));
        widget_flight->setGeometry(QRect(15, 15, 770, 338));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(50);
        widget_flight->setFont(font);
        widget_flight->setStyleSheet(QString::fromUtf8("#widget_flight{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\350\210\252\347\217\255\345\217\267bg.png);}"));
        label_midPlace = new ScrollText_Horizontal(widget_flight);
        label_midPlace->setObjectName(QString::fromUtf8("label_midPlace"));
        label_midPlace->setGeometry(QRect(270, 230, 200, 30));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_midPlace->setFont(font1);
        label_midPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_midPlace->setTextFormat(Qt::AutoText);
        label_midPlace->setScaledContents(true);
        label_midPlace->setAlignment(Qt::AlignCenter);
        layoutWidget_1 = new QWidget(widget_flight);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(6, 0, 772, 142));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(30, 0, 0, 0);
        label_picture_plane = new QLabel(layoutWidget_1);
        label_picture_plane->setObjectName(QString::fromUtf8("label_picture_plane"));
        label_picture_plane->setMinimumSize(QSize(155, 120));
        label_picture_plane->setMaximumSize(QSize(155, 110));
        label_picture_plane->setStyleSheet(QString::fromUtf8("image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\237\242\351\207\217\345\211\252\345\275\261\351\243\236\346\234\272.png);"));

        horizontalLayout_11->addWidget(label_picture_plane);

        label_mainFlightNO_ = new QLabel(layoutWidget_1);
        label_mainFlightNO_->setObjectName(QString::fromUtf8("label_mainFlightNO_"));
        label_mainFlightNO_->setMinimumSize(QSize(580, 140));
        label_mainFlightNO_->setMaximumSize(QSize(580, 140));
        QFont font2;
        font2.setPointSize(90);
        font2.setBold(true);
        font2.setWeight(75);
        label_mainFlightNO_->setFont(font2);
        label_mainFlightNO_->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_mainFlightNO_->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_mainFlightNO_);

        layoutWidget_2 = new QWidget(widget_flight);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 240, 751, 71));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_22->setSpacing(10);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(20, 0, 0, 0);
        label_fromPlace = new ScrollText_Horizontal(layoutWidget_2);
        label_fromPlace->setObjectName(QString::fromUtf8("label_fromPlace"));
        label_fromPlace->setMinimumSize(QSize(220, 0));
        label_fromPlace->setMaximumSize(QSize(220, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(40);
        font3.setBold(true);
        font3.setWeight(75);
        label_fromPlace->setFont(font3);
        label_fromPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_fromPlace->setScaledContents(true);
        label_fromPlace->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_fromPlace);

        label_picture_pointTo = new QLabel(layoutWidget_2);
        label_picture_pointTo->setObjectName(QString::fromUtf8("label_picture_pointTo"));
        label_picture_pointTo->setMinimumSize(QSize(237, 21));
        label_picture_pointTo->setMaximumSize(QSize(237, 21));
        label_picture_pointTo->setStyleSheet(QString::fromUtf8("image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\275\242\347\212\266-2.png);"));

        horizontalLayout_22->addWidget(label_picture_pointTo);

        label_arrivalPlace = new ScrollText_Horizontal(layoutWidget_2);
        label_arrivalPlace->setObjectName(QString::fromUtf8("label_arrivalPlace"));
        label_arrivalPlace->setMinimumSize(QSize(220, 60));
        label_arrivalPlace->setMaximumSize(QSize(250, 60));
        label_arrivalPlace->setFont(font3);
        label_arrivalPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_arrivalPlace->setScaledContents(true);
        label_arrivalPlace->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_arrivalPlace);

        layoutWidget_3 = new QWidget(widget_flight);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(200, 150, 371, 61));
        horizontalLayout_33 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(0, 0, 0, 0);
        label_text_shareFlight = new QLabel(layoutWidget_3);
        label_text_shareFlight->setObjectName(QString::fromUtf8("label_text_shareFlight"));
        QFont font4;
        font4.setPointSize(26);
        label_text_shareFlight->setFont(font4);
        label_text_shareFlight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_text_shareFlight->setTextFormat(Qt::RichText);

        horizontalLayout_33->addWidget(label_text_shareFlight);

        ScrollText_shareFlight = new ScrollText_Vertical(layoutWidget_3);
        ScrollText_shareFlight->setObjectName(QString::fromUtf8("ScrollText_shareFlight"));
        ScrollText_shareFlight->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu"));
        font5.setPointSize(26);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        ScrollText_shareFlight->setFont(font5);
        ScrollText_shareFlight->setStyleSheet(QString::fromUtf8("color: #0fff7a;\n"
"font: bold 26pt \"Ubuntu\";"));

        horizontalLayout_33->addWidget(ScrollText_shareFlight);

        widget_pplNum = new QWidget(widget_ALL);
        widget_pplNum->setObjectName(QString::fromUtf8("widget_pplNum"));
        widget_pplNum->setGeometry(QRect(15, 368, 770, 116));
        widget_pplNum->setStyleSheet(QString::fromUtf8("#widget_pplNum{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\273\272\345\272\223\344\272\272\346\225\260.png);}"));
        label_countTotal = new QLabel(widget_pplNum);
        label_countTotal->setObjectName(QString::fromUtf8("label_countTotal"));
        label_countTotal->setGeometry(QRect(145, 60, 81, 45));
        label_countTotal->setMinimumSize(QSize(0, 0));
        label_countTotal->setMaximumSize(QSize(16677725, 16777215));
        QFont font6;
        font6.setPointSize(24);
        font6.setBold(true);
        font6.setWeight(75);
        label_countTotal->setFont(font6);
        label_countTotal->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countTotal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_text0 = new QLabel(widget_pplNum);
        label_text0->setObjectName(QString::fromUtf8("label_text0"));
        label_text0->setGeometry(QRect(110, 60, 20, 45));
        label_text0->setMinimumSize(QSize(20, 0));
        label_text0->setMaximumSize(QSize(20, 16777215));
        label_text0->setFont(font6);
        label_text0->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_text0->setAlignment(Qt::AlignCenter);
        label_1text = new QLabel(widget_pplNum);
        label_1text->setObjectName(QString::fromUtf8("label_1text"));
        label_1text->setGeometry(QRect(20, 13, 241, 45));
        label_1text->setMinimumSize(QSize(0, 0));
        label_1text->setMaximumSize(QSize(16777215, 16777215));
        QFont font7;
        font7.setPointSize(24);
        label_1text->setFont(font7);
        label_1text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_1text->setAlignment(Qt::AlignCenter);
        splitter_3 = new QSplitter(widget_pplNum);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(300, 7, 100, 99));
        splitter_3->setMinimumSize(QSize(100, 0));
        splitter_3->setMaximumSize(QSize(130, 16777215));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setHandleWidth(0);
        label_2text = new QLabel(splitter_3);
        label_2text->setObjectName(QString::fromUtf8("label_2text"));
        label_2text->setMinimumSize(QSize(100, 0));
        label_2text->setMaximumSize(QSize(130, 16777215));
        label_2text->setFont(font7);
        label_2text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2text->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(label_2text);
        label_countStart = new QLabel(splitter_3);
        label_countStart->setObjectName(QString::fromUtf8("label_countStart"));
        label_countStart->setMinimumSize(QSize(100, 0));
        label_countStart->setMaximumSize(QSize(130, 16777215));
        label_countStart->setFont(font6);
        label_countStart->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countStart->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(label_countStart);
        splitter_4 = new QSplitter(widget_pplNum);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(400, 7, 100, 99));
        splitter_4->setMinimumSize(QSize(100, 0));
        splitter_4->setMaximumSize(QSize(130, 16777215));
        splitter_4->setOrientation(Qt::Vertical);
        splitter_4->setHandleWidth(0);
        label_3text = new QLabel(splitter_4);
        label_3text->setObjectName(QString::fromUtf8("label_3text"));
        label_3text->setMinimumSize(QSize(100, 0));
        label_3text->setMaximumSize(QSize(130, 16777215));
        label_3text->setFont(font7);
        label_3text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3text->setAlignment(Qt::AlignCenter);
        splitter_4->addWidget(label_3text);
        label_countTransfer = new QLabel(splitter_4);
        label_countTransfer->setObjectName(QString::fromUtf8("label_countTransfer"));
        label_countTransfer->setMinimumSize(QSize(100, 0));
        label_countTransfer->setMaximumSize(QSize(130, 16777215));
        label_countTransfer->setFont(font6);
        label_countTransfer->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countTransfer->setAlignment(Qt::AlignCenter);
        splitter_4->addWidget(label_countTransfer);
        splitter_5 = new QSplitter(widget_pplNum);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setGeometry(QRect(500, 7, 100, 99));
        splitter_5->setMinimumSize(QSize(100, 0));
        splitter_5->setMaximumSize(QSize(130, 16777215));
        splitter_5->setOrientation(Qt::Vertical);
        splitter_5->setHandleWidth(0);
        label_text4 = new QLabel(splitter_5);
        label_text4->setObjectName(QString::fromUtf8("label_text4"));
        label_text4->setMinimumSize(QSize(100, 0));
        label_text4->setMaximumSize(QSize(130, 16777215));
        label_text4->setFont(font7);
        label_text4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_text4->setAlignment(Qt::AlignCenter);
        splitter_5->addWidget(label_text4);
        label_countMidway = new QLabel(splitter_5);
        label_countMidway->setObjectName(QString::fromUtf8("label_countMidway"));
        label_countMidway->setMinimumSize(QSize(100, 0));
        label_countMidway->setMaximumSize(QSize(130, 16777215));
        label_countMidway->setFont(font6);
        label_countMidway->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countMidway->setAlignment(Qt::AlignCenter);
        splitter_5->addWidget(label_countMidway);
        label_countBoarding = new QLabel(widget_pplNum);
        label_countBoarding->setObjectName(QString::fromUtf8("label_countBoarding"));
        label_countBoarding->setGeometry(QRect(20, 60, 81, 45));
        label_countBoarding->setMinimumSize(QSize(0, 0));
        label_countBoarding->setMaximumSize(QSize(16777215, 16777215));
        label_countBoarding->setFont(font6);
        label_countBoarding->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countBoarding->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_6 = new QSplitter(widget_pplNum);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setGeometry(QRect(635, 7, 130, 99));
        splitter_6->setMinimumSize(QSize(100, 0));
        splitter_6->setMaximumSize(QSize(130, 16777215));
        splitter_6->setOrientation(Qt::Vertical);
        splitter_6->setHandleWidth(0);
        label_text4_2 = new QLabel(splitter_6);
        label_text4_2->setObjectName(QString::fromUtf8("label_text4_2"));
        label_text4_2->setMinimumSize(QSize(100, 0));
        label_text4_2->setMaximumSize(QSize(130, 16777215));
        label_text4_2->setFont(font7);
        label_text4_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_text4_2->setAlignment(Qt::AlignCenter);
        splitter_6->addWidget(label_text4_2);
        label_babyNum = new QLabel(splitter_6);
        label_babyNum->setObjectName(QString::fromUtf8("label_babyNum"));
        label_babyNum->setMinimumSize(QSize(100, 0));
        label_babyNum->setMaximumSize(QSize(130, 16777215));
        label_babyNum->setFont(font6);
        label_babyNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_babyNum->setAlignment(Qt::AlignCenter);
        splitter_6->addWidget(label_babyNum);
        label_verticalSpace = new QLabel(widget_pplNum);
        label_verticalSpace->setObjectName(QString::fromUtf8("label_verticalSpace"));
        label_verticalSpace->setGeometry(QRect(620, 20, 20, 90));
        label_verticalSpace->setMinimumSize(QSize(0, 0));
        label_verticalSpace->setMaximumSize(QSize(130, 16777215));
        QFont font8;
        font8.setPointSize(10);
        label_verticalSpace->setFont(font8);
        label_verticalSpace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"line-height:8px"));
        label_verticalSpace->setAlignment(Qt::AlignCenter);
        widget_time = new QWidget(widget_ALL);
        widget_time->setObjectName(QString::fromUtf8("widget_time"));
        widget_time->setEnabled(true);
        widget_time->setGeometry(QRect(15, 3680, 770, 78));
        widget_time->setStyleSheet(QString::fromUtf8("#widget_time{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\350\265\267\351\243\236\346\227\266\351\227\264.png);}"));
        splitter_2 = new QSplitter(widget_time);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(410, 10, 335, 53));
        splitter_2->setMinimumSize(QSize(335, 0));
        splitter_2->setMaximumSize(QSize(300, 16777215));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(0);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(160, 0));
        label_2->setMaximumSize(QSize(160, 16777215));
        QFont font9;
        font9.setPointSize(30);
        label_2->setFont(font9);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_2->addWidget(label_2);
        label_departureTime = new QLabel(splitter_2);
        label_departureTime->setObjectName(QString::fromUtf8("label_departureTime"));
        label_departureTime->setMinimumSize(QSize(140, 0));
        label_departureTime->setMaximumSize(QSize(140, 16777215));
        QFont font10;
        font10.setPointSize(30);
        font10.setBold(true);
        font10.setWeight(75);
        label_departureTime->setFont(font10);
        label_departureTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_departureTime->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        splitter_2->addWidget(label_departureTime);
        splitter_1 = new QSplitter(widget_time);
        splitter_1->setObjectName(QString::fromUtf8("splitter_1"));
        splitter_1->setGeometry(QRect(30, 10, 335, 53));
        splitter_1->setMinimumSize(QSize(335, 0));
        splitter_1->setMaximumSize(QSize(300, 16777215));
        splitter_1->setOrientation(Qt::Horizontal);
        splitter_1->setHandleWidth(0);
        label_1 = new QLabel(splitter_1);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMinimumSize(QSize(160, 0));
        label_1->setMaximumSize(QSize(160, 16777215));
        label_1->setFont(font9);
        label_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_1->addWidget(label_1);
        label_boardingTime = new QLabel(splitter_1);
        label_boardingTime->setObjectName(QString::fromUtf8("label_boardingTime"));
        label_boardingTime->setMinimumSize(QSize(140, 0));
        label_boardingTime->setMaximumSize(QSize(140, 16777215));
        label_boardingTime->setFont(font10);
        label_boardingTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_boardingTime->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        splitter_1->addWidget(label_boardingTime);
        widget_through1 = new QWidget(widget_ALL);
        widget_through1->setObjectName(QString::fromUtf8("widget_through1"));
        widget_through1->setGeometry(QRect(15, 500, 378, 401));
        widget_through1->setStyleSheet(QString::fromUtf8("#widget_through1{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\351\200\232\351\201\223\350\223\235.png);}"));
        label_1t = new QLabel(widget_through1);
        label_1t->setObjectName(QString::fromUtf8("label_1t"));
        label_1t->setGeometry(QRect(190, 70, 180, 25));
        QFont font11;
        font11.setPointSize(16);
        label_1t->setFont(font11);
        label_1t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2t = new QLabel(widget_through1);
        label_2t->setObjectName(QString::fromUtf8("label_2t"));
        label_2t->setGeometry(QRect(190, 145, 180, 25));
        label_2t->setFont(font11);
        label_2t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3t = new QLabel(widget_through1);
        label_3t->setObjectName(QString::fromUtf8("label_3t"));
        label_3t->setGeometry(QRect(190, 225, 180, 25));
        label_3t->setFont(font11);
        label_3t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_name_L = new QLabel(widget_through1);
        label_name_L->setObjectName(QString::fromUtf8("label_name_L"));
        label_name_L->setGeometry(QRect(190, 100, 180, 25));
        QFont font12;
        font12.setPointSize(16);
        font12.setBold(true);
        font12.setWeight(75);
        label_name_L->setFont(font12);
        label_name_L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_flightNO__L = new QLabel(widget_through1);
        label_flightNO__L->setObjectName(QString::fromUtf8("label_flightNO__L"));
        label_flightNO__L->setGeometry(QRect(190, 175, 180, 25));
        label_flightNO__L->setFont(font12);
        label_flightNO__L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_seatNO__L = new QLabel(widget_through1);
        label_seatNO__L->setObjectName(QString::fromUtf8("label_seatNO__L"));
        label_seatNO__L->setGeometry(QRect(190, 255, 180, 25));
        label_seatNO__L->setFont(font12);
        label_seatNO__L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_resultStamp_L = new QLabel(widget_through1);
        label_resultStamp_L->setObjectName(QString::fromUtf8("label_resultStamp_L"));
        label_resultStamp_L->setGeometry(QRect(15, 110, 161, 142));
        label_resultStamp_L->setStyleSheet(QString::fromUtf8(""));
        label_name_L_2 = new QLabel(widget_through1);
        label_name_L_2->setObjectName(QString::fromUtf8("label_name_L_2"));
        label_name_L_2->setGeometry(QRect(10, 8, 111, 41));
        QFont font13;
        font13.setPointSize(18);
        font13.setBold(true);
        font13.setWeight(75);
        label_name_L_2->setFont(font13);
        label_name_L_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        pushButton_faceImage_L = new QPushButton(widget_through1);
        pushButton_faceImage_L->setObjectName(QString::fromUtf8("pushButton_faceImage_L"));
        pushButton_faceImage_L->setGeometry(QRect(10, 70, 171, 228));
        pushButton_faceImage_L->setFocusPolicy(Qt::NoFocus);
        pushButton_faceImage_L->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border:none;background-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\205\247\347\211\207-\345\244\247.png);}\n"
"\n"
""));
        pushButton_faceImage_L->setIconSize(QSize(171, 228));
        label_4t_2 = new QLabel(widget_through1);
        label_4t_2->setObjectName(QString::fromUtf8("label_4t_2"));
        label_4t_2->setGeometry(QRect(190, 300, 180, 25));
        label_4t_2->setFont(font11);
        label_4t_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_cardNO__L = new QLabel(widget_through1);
        label_cardNO__L->setObjectName(QString::fromUtf8("label_cardNO__L"));
        label_cardNO__L->setGeometry(QRect(190, 330, 180, 50));
        label_cardNO__L->setFont(font12);
        label_cardNO__L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_cardNO__L->setWordWrap(true);
        pushButton_psngrInfo_L = new QPushButton(widget_through1);
        pushButton_psngrInfo_L->setObjectName(QString::fromUtf8("pushButton_psngrInfo_L"));
        pushButton_psngrInfo_L->setGeometry(QRect(0, 0, 380, 401));
        pushButton_psngrInfo_L->setFocusPolicy(Qt::NoFocus);
        pushButton_psngrInfo_L->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;}\n"
"\n"
""));
        pushButton_psngrInfo_L->setIconSize(QSize(171, 228));
        label_transferType_L = new QLabel(widget_through1);
        label_transferType_L->setObjectName(QString::fromUtf8("label_transferType_L"));
        label_transferType_L->setGeometry(QRect(15, 78, 50, 30));
        label_resultTab_L = new QLabel(widget_through1);
        label_resultTab_L->setObjectName(QString::fromUtf8("label_resultTab_L"));
        label_resultTab_L->setGeometry(QRect(10, 315, 171, 65));
        label_1t->raise();
        label_2t->raise();
        label_3t->raise();
        label_name_L->raise();
        label_flightNO__L->raise();
        label_seatNO__L->raise();
        label_name_L_2->raise();
        pushButton_faceImage_L->raise();
        label_4t_2->raise();
        label_cardNO__L->raise();
        label_transferType_L->raise();
        label_resultTab_L->raise();
        label_resultStamp_L->raise();
        pushButton_psngrInfo_L->raise();
        widget_through2 = new QWidget(widget_ALL);
        widget_through2->setObjectName(QString::fromUtf8("widget_through2"));
        widget_through2->setGeometry(QRect(407, 500, 378, 401));
        widget_through2->setStyleSheet(QString::fromUtf8("#widget_through2{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\351\200\232\351\201\223\350\223\235.png);}"));
        label_5t = new QLabel(widget_through2);
        label_5t->setObjectName(QString::fromUtf8("label_5t"));
        label_5t->setGeometry(QRect(190, 145, 180, 25));
        label_5t->setFont(font11);
        label_5t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_seatNO__R = new QLabel(widget_through2);
        label_seatNO__R->setObjectName(QString::fromUtf8("label_seatNO__R"));
        label_seatNO__R->setGeometry(QRect(190, 255, 180, 25));
        label_seatNO__R->setFont(font12);
        label_seatNO__R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_flightNO__R = new QLabel(widget_through2);
        label_flightNO__R->setObjectName(QString::fromUtf8("label_flightNO__R"));
        label_flightNO__R->setGeometry(QRect(190, 175, 180, 25));
        label_flightNO__R->setFont(font12);
        label_flightNO__R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_resultStamp_R = new QLabel(widget_through2);
        label_resultStamp_R->setObjectName(QString::fromUtf8("label_resultStamp_R"));
        label_resultStamp_R->setGeometry(QRect(15, 110, 161, 142));
        label_6t = new QLabel(widget_through2);
        label_6t->setObjectName(QString::fromUtf8("label_6t"));
        label_6t->setGeometry(QRect(190, 225, 180, 25));
        label_6t->setFont(font11);
        label_6t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4t = new QLabel(widget_through2);
        label_4t->setObjectName(QString::fromUtf8("label_4t"));
        label_4t->setGeometry(QRect(190, 70, 180, 25));
        label_4t->setFont(font11);
        label_4t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_name_R = new QLabel(widget_through2);
        label_name_R->setObjectName(QString::fromUtf8("label_name_R"));
        label_name_R->setGeometry(QRect(190, 100, 180, 25));
        label_name_R->setFont(font12);
        label_name_R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_name_L_3 = new QLabel(widget_through2);
        label_name_L_3->setObjectName(QString::fromUtf8("label_name_L_3"));
        label_name_L_3->setGeometry(QRect(10, 8, 111, 41));
        label_name_L_3->setFont(font13);
        label_name_L_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        pushButton_faceImage_R = new QPushButton(widget_through2);
        pushButton_faceImage_R->setObjectName(QString::fromUtf8("pushButton_faceImage_R"));
        pushButton_faceImage_R->setGeometry(QRect(10, 70, 171, 228));
        pushButton_faceImage_R->setFocusPolicy(Qt::NoFocus);
        pushButton_faceImage_R->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border:none;background-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\205\247\347\211\207-\345\244\247.png);}\n"
"\n"
""));
        pushButton_faceImage_R->setIconSize(QSize(171, 228));
        label_cardNO__R = new QLabel(widget_through2);
        label_cardNO__R->setObjectName(QString::fromUtf8("label_cardNO__R"));
        label_cardNO__R->setGeometry(QRect(190, 330, 180, 50));
        label_cardNO__R->setFont(font12);
        label_cardNO__R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_cardNO__R->setWordWrap(true);
        label_7t = new QLabel(widget_through2);
        label_7t->setObjectName(QString::fromUtf8("label_7t"));
        label_7t->setGeometry(QRect(190, 300, 180, 25));
        label_7t->setFont(font11);
        label_7t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_psngrInfo_R = new QPushButton(widget_through2);
        pushButton_psngrInfo_R->setObjectName(QString::fromUtf8("pushButton_psngrInfo_R"));
        pushButton_psngrInfo_R->setGeometry(QRect(0, 0, 380, 401));
        pushButton_psngrInfo_R->setFocusPolicy(Qt::NoFocus);
        pushButton_psngrInfo_R->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;}\n"
"\n"
""));
        pushButton_psngrInfo_R->setIconSize(QSize(171, 228));
        label_transferType_R = new QLabel(widget_through2);
        label_transferType_R->setObjectName(QString::fromUtf8("label_transferType_R"));
        label_transferType_R->setGeometry(QRect(15, 78, 50, 30));
        label_resultTab_R = new QLabel(widget_through2);
        label_resultTab_R->setObjectName(QString::fromUtf8("label_resultTab_R"));
        label_resultTab_R->setGeometry(QRect(10, 315, 171, 65));
        label_5t->raise();
        label_seatNO__R->raise();
        label_flightNO__R->raise();
        label_6t->raise();
        label_4t->raise();
        label_name_R->raise();
        label_name_L_3->raise();
        pushButton_faceImage_R->raise();
        label_cardNO__R->raise();
        label_7t->raise();
        label_transferType_R->raise();
        label_resultStamp_R->raise();
        label_resultTab_R->raise();
        pushButton_psngrInfo_R->raise();
        pushButton_startBoarding = new QPushButton(widget_ALL);
        pushButton_startBoarding->setObjectName(QString::fromUtf8("pushButton_startBoarding"));
        pushButton_startBoarding->setGeometry(QRect(16, 910, 180, 60));
        pushButton_startBoarding->setFocusPolicy(Qt::NoFocus);
        pushButton_startBoarding->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\274\200-\345\247\213-\347\231\273-\346\234\272.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\274\200-\345\247\213-\347\231\273-\346\234\272-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_startBoarding->setIconSize(QSize(180, 50));
        pushButton_cancelFlight = new QPushButton(widget_ALL);
        pushButton_cancelFlight->setObjectName(QString::fromUtf8("pushButton_cancelFlight"));
        pushButton_cancelFlight->setGeometry(QRect(408, 910, 180, 60));
        pushButton_cancelFlight->setFocusPolicy(Qt::NoFocus);
        pushButton_cancelFlight->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\346\222\244\351\224\200\350\210\252\347\217\255.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\346\222\244\351\224\200\350\210\252\347\217\255-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_cancelFlight->setIconSize(QSize(185, 55));
        pushButton_pplStats = new QPushButton(widget_ALL);
        pushButton_pplStats->setObjectName(QString::fromUtf8("pushButton_pplStats"));
        pushButton_pplStats->setGeometry(QRect(212, 910, 180, 60));
        pushButton_pplStats->setFocusPolicy(Qt::NoFocus);
        pushButton_pplStats->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\344\272\272\346\225\260\347\273\237\350\256\241.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\344\272\272\346\225\260\347\273\237\350\256\241-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        pushButton_pplStats->setIconSize(QSize(180, 50));
        pushButton_otherFlight = new QPushButton(widget_ALL);
        pushButton_otherFlight->setObjectName(QString::fromUtf8("pushButton_otherFlight"));
        pushButton_otherFlight->setGeometry(QRect(604, 910, 180, 60));
        pushButton_otherFlight->setFocusPolicy(Qt::NoFocus);
        pushButton_otherFlight->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\205\266\344\273\226\350\210\252\347\217\255.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\205\266\344\273\226\350\210\252\347\217\255-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        pushButton_otherFlight->setIconSize(QSize(180, 50));
        pushButton_endBoarding = new QPushButton(widget_ALL);
        pushButton_endBoarding->setObjectName(QString::fromUtf8("pushButton_endBoarding"));
        pushButton_endBoarding->setGeometry(QRect(16, 910, 180, 60));
        pushButton_endBoarding->setFocusPolicy(Qt::NoFocus);
        pushButton_endBoarding->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\273\223-\346\235\237-\347\231\273-\346\234\272.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\273\223-\346\235\237-\347\231\273-\346\234\272-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_endBoarding->setIconSize(QSize(180, 50));
        pushButton_find = new QPushButton(widget_ALL);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(604, 910, 180, 60));
        pushButton_find->setFocusPolicy(Qt::NoFocus);
        pushButton_find->setStyleSheet(QString::fromUtf8("QPushButton{background:transparent;border-radius:10px;image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\346\237\245---\350\257\242.png);}\n"
"QPushButton:pressed{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\346\237\245---\350\257\242-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_find->setIconSize(QSize(180, 50));
        widget_time->raise();
        widget_flight->raise();
        widget_pplNum->raise();
        widget_through1->raise();
        widget_through2->raise();
        pushButton_pplStats->raise();
        pushButton_endBoarding->raise();
        pushButton_find->raise();
        pushButton_startBoarding->raise();
        pushButton_otherFlight->raise();
        pushButton_cancelFlight->raise();

        retranslateUi(RealtimeBoarding);

        QMetaObject::connectSlotsByName(RealtimeBoarding);
    } // setupUi

    void retranslateUi(QWidget *RealtimeBoarding)
    {
        RealtimeBoarding->setWindowTitle(QApplication::translate("RealtimeBoarding", "\345\256\236\346\227\266\347\231\273\346\234\272", nullptr));
        label_midPlace->setText(QString());
        label_picture_plane->setText(QString());
        label_mainFlightNO_->setText(QApplication::translate("RealtimeBoarding", "- - - - - -", nullptr));
        label_fromPlace->setText(QApplication::translate("RealtimeBoarding", "- - - -", nullptr));
        label_picture_pointTo->setText(QString());
        label_arrivalPlace->setText(QApplication::translate("RealtimeBoarding", "- - - -", nullptr));
        label_text_shareFlight->setText(QApplication::translate("RealtimeBoarding", "\345\205\261\344\272\253\350\210\252\347\217\255\357\274\232\n"
"", nullptr));
        label_countTotal->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_text0->setText(QApplication::translate("RealtimeBoarding", "/", nullptr));
        label_1text->setText(QApplication::translate("RealtimeBoarding", "\345\267\262\347\231\273\346\234\272/\350\210\252\347\217\255\344\272\272\346\225\260", nullptr));
        label_2text->setText(QApplication::translate("RealtimeBoarding", "\345\247\213\345\217\221", nullptr));
        label_countStart->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_3text->setText(QApplication::translate("RealtimeBoarding", "\344\270\255\350\275\254", nullptr));
        label_countTransfer->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_text4->setText(QApplication::translate("RealtimeBoarding", "\347\273\217\345\201\234", nullptr));
        label_countMidway->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_countBoarding->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_text4_2->setText(QApplication::translate("RealtimeBoarding", "\345\220\253\345\251\264\345\204\277", nullptr));
        label_babyNum->setText(QApplication::translate("RealtimeBoarding", "0", nullptr));
        label_verticalSpace->setText(QApplication::translate("RealtimeBoarding", "<p style='line-height:40%'>\344\270\250</p>\n"
"<p style='line-height:40%'>\344\270\250</p>\n"
"<p>\344\270\250</p>", nullptr));
        label_2->setText(QApplication::translate("RealtimeBoarding", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        label_departureTime->setText(QApplication::translate("RealtimeBoarding", "- - : - -", nullptr));
        label_1->setText(QApplication::translate("RealtimeBoarding", "\347\231\273\346\234\272\346\227\266\351\227\264", nullptr));
        label_boardingTime->setText(QApplication::translate("RealtimeBoarding", "- - : - -", nullptr));
        label_1t->setText(QApplication::translate("RealtimeBoarding", "\346\227\205\345\256\242\345\247\223\345\220\215\357\274\232", nullptr));
        label_2t->setText(QApplication::translate("RealtimeBoarding", "\350\210\252\347\217\255\345\217\267 / \345\272\217\345\217\267\357\274\232", nullptr));
        label_3t->setText(QApplication::translate("RealtimeBoarding", "\345\272\247\344\275\215\345\217\267\357\274\232", nullptr));
        label_name_L->setText(QString());
        label_flightNO__L->setText(QString());
        label_seatNO__L->setText(QString());
        label_resultStamp_L->setText(QString());
        label_name_L_2->setText(QApplication::translate("RealtimeBoarding", "| 1\345\217\267\351\200\232\351\201\223", nullptr));
        pushButton_faceImage_L->setText(QString());
        label_4t_2->setText(QApplication::translate("RealtimeBoarding", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        pushButton_psngrInfo_L->setText(QString());
        label_transferType_L->setText(QString());
        label_resultTab_L->setText(QString());
        label_5t->setText(QApplication::translate("RealtimeBoarding", "\350\210\252\347\217\255\345\217\267 / \345\272\217\345\217\267\357\274\232", nullptr));
        label_seatNO__R->setText(QString());
        label_flightNO__R->setText(QString());
        label_resultStamp_R->setText(QString());
        label_6t->setText(QApplication::translate("RealtimeBoarding", "\345\272\247\344\275\215\345\217\267\357\274\232", nullptr));
        label_4t->setText(QApplication::translate("RealtimeBoarding", "\346\227\205\345\256\242\345\247\223\345\220\215\357\274\232", nullptr));
        label_name_R->setText(QString());
        label_name_L_3->setText(QApplication::translate("RealtimeBoarding", "| 2\345\217\267\351\200\232\351\201\223", nullptr));
        pushButton_faceImage_R->setText(QString());
        label_cardNO__R->setText(QString());
        label_7t->setText(QApplication::translate("RealtimeBoarding", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        pushButton_psngrInfo_R->setText(QString());
        label_transferType_R->setText(QString());
        label_resultTab_R->setText(QString());
        pushButton_startBoarding->setText(QString());
        pushButton_cancelFlight->setText(QString());
        pushButton_pplStats->setText(QString());
        pushButton_otherFlight->setText(QString());
        pushButton_endBoarding->setText(QString());
        pushButton_find->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RealtimeBoarding: public Ui_RealtimeBoarding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEBOARDING_H
