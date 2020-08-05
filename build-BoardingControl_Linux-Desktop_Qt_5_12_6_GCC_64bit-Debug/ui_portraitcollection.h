/********************************************************************************
** Form generated from reading UI file 'portraitcollection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTRAITCOLLECTION_H
#define UI_PORTRAITCOLLECTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <ScrollText.h>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_PortraitCollection
{
public:
    QWidget *widget_ALL;
    QWidget *widget_colecting;
    QPushButton *pushButton_start_Colecting;
    QWidget *widget_colectedPPLcount;
    QSplitter *splitter_3;
    QLabel *label_1text;
    QLabel *label_countColected;
    QWidget *widget_through2;
    QLabel *label_faceImage_R;
    QLabel *label_8t;
    QPushButton *pushButton_release_R;
    QLabel *label_colectResult_R;
    QToolButton *toolButton_childMode_R;
    QSplitter *splitter_5;
    QLabel *label_4t;
    ScrollText_Horizontal *label_flightNO_R;
    QSplitter *splitter_6;
    QLabel *label_5t;
    QLabel *label_boardingNO_R;
    QSplitter *splitter_7;
    QLabel *label_6t;
    QLabel *label_seatNO_R;
    QLabel *label_frontGround_R;
    QLabel *label_3t_3;
    QLabel *label_cardID_R;
    QPushButton *pushButton_prevent_R;
    QWidget *widget_through1;
    QLabel *label_faceImage_L;
    QLabel *label_9t;
    QPushButton *pushButton_release_L;
    QLabel *label_colectResult_L;
    QToolButton *toolButton_childMode_L;
    QSplitter *splitter_4;
    QLabel *label_1t;
    ScrollText_Horizontal *label_flightNO_L;
    QSplitter *splitter_8;
    QLabel *label_3t;
    QLabel *label_seatNO_L;
    QSplitter *splitter_9;
    QLabel *label_2t;
    QLabel *label_boardingNO_L;
    QLabel *label_frontGround_L;
    QLabel *label_cardID_L;
    QLabel *label_3t_4;
    QPushButton *pushButton_prevent_L;
    QPushButton *pushButton_end_Colecting;
    QPushButton *pushButton_manualInputInfo;
    QPushButton *pushButton_cancel_Colecting;
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
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_text_shareFlight;
    ScrollText_Vertical *ScrollText_shareFlight;
    QWidget *widget_setting;
    QWidget *widget_inputSetting;
    QPushButton *pushButton_commit;
    QLabel *label_1tt;
    QLabel *label_3tt;
    QLabel *label_2tt;
    QLabel *label_4tt;
    QLineEdit *lineEdit_flightNO_;
    QLineEdit *lineEdit_flightDate;
    QPushButton *pushButton_keyboard;
    QPushButton *pushButton_calendar;
    QSplitter *splitter_1;
    QRadioButton *radioButton_suspendColecting;
    QRadioButton *radioButton_landedColecting;
    QSplitter *splitter;
    QRadioButton *radioButton_faceColecting;
    QRadioButton *radioButton_quickColecting;
    QWidget *calendarWidget_background;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *PortraitCollection)
    {
        if (PortraitCollection->objectName().isEmpty())
            PortraitCollection->setObjectName(QString::fromUtf8("PortraitCollection"));
        PortraitCollection->resize(800, 978);
        widget_ALL = new QWidget(PortraitCollection);
        widget_ALL->setObjectName(QString::fromUtf8("widget_ALL"));
        widget_ALL->setGeometry(QRect(0, 0, 800, 978));
        widget_ALL->setFocusPolicy(Qt::NoFocus);
        widget_ALL->setStyleSheet(QString::fromUtf8(""));
        widget_colecting = new QWidget(widget_ALL);
        widget_colecting->setObjectName(QString::fromUtf8("widget_colecting"));
        widget_colecting->setGeometry(QRect(0, 0, 800, 978));
        widget_colecting->setFocusPolicy(Qt::NoFocus);
        widget_colecting->setStyleSheet(QString::fromUtf8("#widget_colecting{background-color: rgb(1, 64, 109);}"));
        pushButton_start_Colecting = new QPushButton(widget_colecting);
        pushButton_start_Colecting->setObjectName(QString::fromUtf8("pushButton_start_Colecting"));
        pushButton_start_Colecting->setGeometry(QRect(306, 910, 187, 59));
        pushButton_start_Colecting->setFocusPolicy(Qt::NoFocus);
        pushButton_start_Colecting->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:10px;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\274\200\345\247\213\351\207\207\351\233\206.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\274\200\345\247\213\351\207\207\351\233\206-\346\213\267\350\264\235.png);}"));
        widget_colectedPPLcount = new QWidget(widget_colecting);
        widget_colectedPPLcount->setObjectName(QString::fromUtf8("widget_colectedPPLcount"));
        widget_colectedPPLcount->setGeometry(QRect(15, 368, 770, 85));
        widget_colectedPPLcount->setFocusPolicy(Qt::NoFocus);
        widget_colectedPPLcount->setStyleSheet(QString::fromUtf8("#widget_time{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\350\265\267\351\243\236\346\227\266\351\227\264.png);}"));
        splitter_3 = new QSplitter(widget_colectedPPLcount);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(15, 15, 440, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setMinimumSize(QSize(0, 0));
        splitter_3->setMaximumSize(QSize(440, 50));
        splitter_3->setFocusPolicy(Qt::NoFocus);
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setHandleWidth(0);
        label_1text = new QLabel(splitter_3);
        label_1text->setObjectName(QString::fromUtf8("label_1text"));
        sizePolicy.setHeightForWidth(label_1text->sizePolicy().hasHeightForWidth());
        label_1text->setSizePolicy(sizePolicy);
        label_1text->setMinimumSize(QSize(240, 0));
        label_1text->setMaximumSize(QSize(240, 50));
        QFont font;
        font.setPointSize(30);
        label_1text->setFont(font);
        label_1text->setFocusPolicy(Qt::NoFocus);
        label_1text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_1text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_3->addWidget(label_1text);
        label_countColected = new QLabel(splitter_3);
        label_countColected->setObjectName(QString::fromUtf8("label_countColected"));
        label_countColected->setMinimumSize(QSize(100, 50));
        label_countColected->setMaximumSize(QSize(200, 50));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        label_countColected->setFont(font1);
        label_countColected->setFocusPolicy(Qt::NoFocus);
        label_countColected->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_countColected->setLineWidth(-5);
        label_countColected->setTextFormat(Qt::AutoText);
        label_countColected->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        splitter_3->addWidget(label_countColected);
        widget_through2 = new QWidget(widget_colecting);
        widget_through2->setObjectName(QString::fromUtf8("widget_through2"));
        widget_through2->setGeometry(QRect(408, 468, 377, 435));
        widget_through2->setFocusPolicy(Qt::NoFocus);
        widget_through2->setStyleSheet(QString::fromUtf8("#widget_through2{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/bg.png);}"));
        label_faceImage_R = new QLabel(widget_through2);
        label_faceImage_R->setObjectName(QString::fromUtf8("label_faceImage_R"));
        label_faceImage_R->setGeometry(QRect(10, 60, 171, 228));
        label_faceImage_R->setFocusPolicy(Qt::NoFocus);
        label_faceImage_R->setStyleSheet(QString::fromUtf8("image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\347\205\247\347\211\207-\345\244\247.png);"));
        label_8t = new QLabel(widget_through2);
        label_8t->setObjectName(QString::fromUtf8("label_8t"));
        label_8t->setGeometry(QRect(10, 8, 111, 25));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        label_8t->setFont(font2);
        label_8t->setFocusPolicy(Qt::NoFocus);
        label_8t->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        pushButton_release_R = new QPushButton(widget_through2);
        pushButton_release_R->setObjectName(QString::fromUtf8("pushButton_release_R"));
        pushButton_release_R->setGeometry(QRect(285, 366, 84, 38));
        pushButton_release_R->setFocusPolicy(Qt::NoFocus);
        pushButton_release_R->setStyleSheet(QString::fromUtf8("QPushButton{border:none;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\224\276--\350\241\214.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\224\276--\350\241\2142.png);}"));
        label_colectResult_R = new QLabel(widget_through2);
        label_colectResult_R->setObjectName(QString::fromUtf8("label_colectResult_R"));
        label_colectResult_R->setGeometry(QRect(10, 360, 180, 50));
        label_colectResult_R->setMinimumSize(QSize(180, 50));
        label_colectResult_R->setMaximumSize(QSize(200, 50));
        label_colectResult_R->setFont(font1);
        label_colectResult_R->setFocusPolicy(Qt::NoFocus);
        label_colectResult_R->setStyleSheet(QString::fromUtf8(""));
        label_colectResult_R->setLineWidth(-5);
        label_colectResult_R->setTextFormat(Qt::AutoText);
        label_colectResult_R->setAlignment(Qt::AlignCenter);
        toolButton_childMode_R = new QToolButton(widget_through2);
        toolButton_childMode_R->setObjectName(QString::fromUtf8("toolButton_childMode_R"));
        toolButton_childMode_R->setGeometry(QRect(250, 6, 114, 32));
        toolButton_childMode_R->setFocusPolicy(Qt::NoFocus);
        toolButton_childMode_R->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border:none;\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\251\264\345\204\277\346\250\241\345\274\217.png);\n"
"}\n"
"QToolButton:checked{\n"
"image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\251\264\345\204\277\346\250\241\345\274\2172.png);\n"
"}"));
        toolButton_childMode_R->setIconSize(QSize(114, 32));
        toolButton_childMode_R->setCheckable(true);
        toolButton_childMode_R->setChecked(false);
        splitter_5 = new QSplitter(widget_through2);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setGeometry(QRect(190, 60, 181, 56));
        splitter_5->setMinimumSize(QSize(180, 0));
        splitter_5->setFocusPolicy(Qt::NoFocus);
        splitter_5->setOrientation(Qt::Vertical);
        splitter_5->setHandleWidth(0);
        label_4t = new QLabel(splitter_5);
        label_4t->setObjectName(QString::fromUtf8("label_4t"));
        QFont font3;
        font3.setPointSize(16);
        label_4t->setFont(font3);
        label_4t->setFocusPolicy(Qt::NoFocus);
        label_4t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_5->addWidget(label_4t);
        label_flightNO_R = new ScrollText_Horizontal(splitter_5);
        label_flightNO_R->setObjectName(QString::fromUtf8("label_flightNO_R"));
        label_flightNO_R->setFont(font2);
        label_flightNO_R->setFocusPolicy(Qt::NoFocus);
        label_flightNO_R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_5->addWidget(label_flightNO_R);
        splitter_6 = new QSplitter(widget_through2);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setGeometry(QRect(190, 140, 181, 56));
        splitter_6->setMinimumSize(QSize(180, 0));
        splitter_6->setFocusPolicy(Qt::NoFocus);
        splitter_6->setOrientation(Qt::Vertical);
        splitter_6->setHandleWidth(0);
        label_5t = new QLabel(splitter_6);
        label_5t->setObjectName(QString::fromUtf8("label_5t"));
        label_5t->setFont(font3);
        label_5t->setFocusPolicy(Qt::NoFocus);
        label_5t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_6->addWidget(label_5t);
        label_boardingNO_R = new QLabel(splitter_6);
        label_boardingNO_R->setObjectName(QString::fromUtf8("label_boardingNO_R"));
        label_boardingNO_R->setFont(font2);
        label_boardingNO_R->setFocusPolicy(Qt::NoFocus);
        label_boardingNO_R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_6->addWidget(label_boardingNO_R);
        splitter_7 = new QSplitter(widget_through2);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setGeometry(QRect(190, 220, 181, 56));
        splitter_7->setMinimumSize(QSize(180, 0));
        splitter_7->setFocusPolicy(Qt::NoFocus);
        splitter_7->setOrientation(Qt::Vertical);
        splitter_7->setHandleWidth(0);
        label_6t = new QLabel(splitter_7);
        label_6t->setObjectName(QString::fromUtf8("label_6t"));
        label_6t->setFont(font3);
        label_6t->setFocusPolicy(Qt::NoFocus);
        label_6t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_7->addWidget(label_6t);
        label_seatNO_R = new QLabel(splitter_7);
        label_seatNO_R->setObjectName(QString::fromUtf8("label_seatNO_R"));
        label_seatNO_R->setFont(font2);
        label_seatNO_R->setFocusPolicy(Qt::NoFocus);
        label_seatNO_R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_7->addWidget(label_seatNO_R);
        label_frontGround_R = new QLabel(widget_through2);
        label_frontGround_R->setObjectName(QString::fromUtf8("label_frontGround_R"));
        label_frontGround_R->setGeometry(QRect(0, 0, 377, 435));
        label_frontGround_R->setStyleSheet(QString::fromUtf8("background-color: rgba(91, 86, 86, 0.5);"));
        label_3t_3 = new QLabel(widget_through2);
        label_3t_3->setObjectName(QString::fromUtf8("label_3t_3"));
        label_3t_3->setGeometry(QRect(10, 290, 90, 30));
        label_3t_3->setFont(font3);
        label_3t_3->setFocusPolicy(Qt::NoFocus);
        label_3t_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_cardID_R = new QLabel(widget_through2);
        label_cardID_R->setObjectName(QString::fromUtf8("label_cardID_R"));
        label_cardID_R->setGeometry(QRect(10, 320, 350, 30));
        label_cardID_R->setFont(font2);
        label_cardID_R->setFocusPolicy(Qt::NoFocus);
        label_cardID_R->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        pushButton_prevent_R = new QPushButton(widget_through2);
        pushButton_prevent_R->setObjectName(QString::fromUtf8("pushButton_prevent_R"));
        pushButton_prevent_R->setGeometry(QRect(196, 366, 84, 38));
        pushButton_prevent_R->setFocusPolicy(Qt::NoFocus);
        pushButton_prevent_R->setStyleSheet(QString::fromUtf8("QPushButton{border:none;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\351\200\200-\345\207\272.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\351\200\200-\345\207\2722.png);}"));
        label_3t_3->raise();
        label_cardID_R->raise();
        label_faceImage_R->raise();
        label_8t->raise();
        pushButton_release_R->raise();
        label_colectResult_R->raise();
        toolButton_childMode_R->raise();
        splitter_5->raise();
        splitter_6->raise();
        splitter_7->raise();
        pushButton_prevent_R->raise();
        label_frontGround_R->raise();
        widget_through1 = new QWidget(widget_colecting);
        widget_through1->setObjectName(QString::fromUtf8("widget_through1"));
        widget_through1->setGeometry(QRect(15, 468, 377, 435));
        widget_through1->setFocusPolicy(Qt::NoFocus);
        widget_through1->setStyleSheet(QString::fromUtf8("#widget_through1{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/bg.png);}"));
        label_faceImage_L = new QLabel(widget_through1);
        label_faceImage_L->setObjectName(QString::fromUtf8("label_faceImage_L"));
        label_faceImage_L->setGeometry(QRect(10, 60, 171, 228));
        label_faceImage_L->setFocusPolicy(Qt::NoFocus);
        label_faceImage_L->setStyleSheet(QString::fromUtf8("image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\347\205\247\347\211\207-\345\244\247.png);"));
        label_9t = new QLabel(widget_through1);
        label_9t->setObjectName(QString::fromUtf8("label_9t"));
        label_9t->setGeometry(QRect(10, 8, 111, 25));
        label_9t->setFont(font2);
        label_9t->setFocusPolicy(Qt::NoFocus);
        label_9t->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        pushButton_release_L = new QPushButton(widget_through1);
        pushButton_release_L->setObjectName(QString::fromUtf8("pushButton_release_L"));
        pushButton_release_L->setGeometry(QRect(285, 366, 84, 38));
        pushButton_release_L->setFocusPolicy(Qt::NoFocus);
        pushButton_release_L->setStyleSheet(QString::fromUtf8("QPushButton{border:none;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\224\276--\350\241\214.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\224\276--\350\241\2142.png);}"));
        label_colectResult_L = new QLabel(widget_through1);
        label_colectResult_L->setObjectName(QString::fromUtf8("label_colectResult_L"));
        label_colectResult_L->setGeometry(QRect(10, 360, 180, 50));
        label_colectResult_L->setMinimumSize(QSize(180, 50));
        label_colectResult_L->setMaximumSize(QSize(200, 50));
        label_colectResult_L->setFont(font1);
        label_colectResult_L->setFocusPolicy(Qt::NoFocus);
        label_colectResult_L->setStyleSheet(QString::fromUtf8(""));
        label_colectResult_L->setLineWidth(-5);
        label_colectResult_L->setTextFormat(Qt::AutoText);
        label_colectResult_L->setAlignment(Qt::AlignCenter);
        toolButton_childMode_L = new QToolButton(widget_through1);
        toolButton_childMode_L->setObjectName(QString::fromUtf8("toolButton_childMode_L"));
        toolButton_childMode_L->setGeometry(QRect(250, 6, 114, 32));
        toolButton_childMode_L->setFocusPolicy(Qt::NoFocus);
        toolButton_childMode_L->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border:none;\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\251\264\345\204\277\346\250\241\345\274\217.png);\n"
"}\n"
"QToolButton:checked{\n"
"image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\251\264\345\204\277\346\250\241\345\274\2172.png);\n"
"}"));
        toolButton_childMode_L->setIconSize(QSize(114, 32));
        toolButton_childMode_L->setCheckable(true);
        splitter_4 = new QSplitter(widget_through1);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(190, 60, 181, 56));
        splitter_4->setMinimumSize(QSize(180, 0));
        splitter_4->setFocusPolicy(Qt::NoFocus);
        splitter_4->setOrientation(Qt::Vertical);
        splitter_4->setHandleWidth(0);
        label_1t = new QLabel(splitter_4);
        label_1t->setObjectName(QString::fromUtf8("label_1t"));
        label_1t->setFont(font3);
        label_1t->setFocusPolicy(Qt::NoFocus);
        label_1t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_4->addWidget(label_1t);
        label_flightNO_L = new ScrollText_Horizontal(splitter_4);
        label_flightNO_L->setObjectName(QString::fromUtf8("label_flightNO_L"));
        label_flightNO_L->setFont(font2);
        label_flightNO_L->setFocusPolicy(Qt::NoFocus);
        label_flightNO_L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_4->addWidget(label_flightNO_L);
        splitter_8 = new QSplitter(widget_through1);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setGeometry(QRect(190, 220, 181, 56));
        splitter_8->setMinimumSize(QSize(180, 0));
        splitter_8->setFocusPolicy(Qt::NoFocus);
        splitter_8->setOrientation(Qt::Vertical);
        splitter_8->setHandleWidth(0);
        label_3t = new QLabel(splitter_8);
        label_3t->setObjectName(QString::fromUtf8("label_3t"));
        label_3t->setFont(font3);
        label_3t->setFocusPolicy(Qt::NoFocus);
        label_3t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_8->addWidget(label_3t);
        label_seatNO_L = new QLabel(splitter_8);
        label_seatNO_L->setObjectName(QString::fromUtf8("label_seatNO_L"));
        label_seatNO_L->setFont(font2);
        label_seatNO_L->setFocusPolicy(Qt::NoFocus);
        label_seatNO_L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_8->addWidget(label_seatNO_L);
        splitter_9 = new QSplitter(widget_through1);
        splitter_9->setObjectName(QString::fromUtf8("splitter_9"));
        splitter_9->setGeometry(QRect(190, 140, 181, 56));
        splitter_9->setMinimumSize(QSize(180, 0));
        splitter_9->setFocusPolicy(Qt::NoFocus);
        splitter_9->setOrientation(Qt::Vertical);
        splitter_9->setHandleWidth(0);
        label_2t = new QLabel(splitter_9);
        label_2t->setObjectName(QString::fromUtf8("label_2t"));
        label_2t->setFont(font3);
        label_2t->setFocusPolicy(Qt::NoFocus);
        label_2t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        splitter_9->addWidget(label_2t);
        label_boardingNO_L = new QLabel(splitter_9);
        label_boardingNO_L->setObjectName(QString::fromUtf8("label_boardingNO_L"));
        label_boardingNO_L->setFont(font2);
        label_boardingNO_L->setFocusPolicy(Qt::NoFocus);
        label_boardingNO_L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        splitter_9->addWidget(label_boardingNO_L);
        label_frontGround_L = new QLabel(widget_through1);
        label_frontGround_L->setObjectName(QString::fromUtf8("label_frontGround_L"));
        label_frontGround_L->setGeometry(QRect(0, 0, 377, 435));
        label_frontGround_L->setStyleSheet(QString::fromUtf8("background-color: rgba(91, 86, 86, 0.5);"));
        label_cardID_L = new QLabel(widget_through1);
        label_cardID_L->setObjectName(QString::fromUtf8("label_cardID_L"));
        label_cardID_L->setGeometry(QRect(10, 320, 350, 30));
        label_cardID_L->setFont(font2);
        label_cardID_L->setFocusPolicy(Qt::NoFocus);
        label_cardID_L->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_3t_4 = new QLabel(widget_through1);
        label_3t_4->setObjectName(QString::fromUtf8("label_3t_4"));
        label_3t_4->setGeometry(QRect(10, 290, 81, 30));
        label_3t_4->setFont(font3);
        label_3t_4->setFocusPolicy(Qt::NoFocus);
        label_3t_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_prevent_L = new QPushButton(widget_through1);
        pushButton_prevent_L->setObjectName(QString::fromUtf8("pushButton_prevent_L"));
        pushButton_prevent_L->setGeometry(QRect(196, 366, 84, 38));
        pushButton_prevent_L->setFocusPolicy(Qt::NoFocus);
        pushButton_prevent_L->setStyleSheet(QString::fromUtf8("QPushButton{border:none;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\351\200\200-\345\207\272.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\351\200\200-\345\207\2722.png);}"));
        label_faceImage_L->raise();
        label_9t->raise();
        pushButton_release_L->raise();
        label_colectResult_L->raise();
        toolButton_childMode_L->raise();
        splitter_4->raise();
        splitter_8->raise();
        splitter_9->raise();
        label_cardID_L->raise();
        label_3t_4->raise();
        pushButton_prevent_L->raise();
        label_frontGround_L->raise();
        pushButton_end_Colecting = new QPushButton(widget_colecting);
        pushButton_end_Colecting->setObjectName(QString::fromUtf8("pushButton_end_Colecting"));
        pushButton_end_Colecting->setGeometry(QRect(306, 910, 187, 59));
        pushButton_end_Colecting->setFocusPolicy(Qt::NoFocus);
        pushButton_end_Colecting->setStyleSheet(QString::fromUtf8("QPushButton{border:none;image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\347\273\223\346\235\237\351\207\207\351\233\206.png);}\n"
"QPushButton:pressed{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\347\273\223\346\235\237\351\207\207\351\233\206-\346\213\267\350\264\235.png);}"));
        pushButton_manualInputInfo = new QPushButton(widget_colecting);
        pushButton_manualInputInfo->setObjectName(QString::fromUtf8("pushButton_manualInputInfo"));
        pushButton_manualInputInfo->setGeometry(QRect(590, 910, 196, 58));
        pushButton_manualInputInfo->setFocusPolicy(Qt::NoFocus);
        pushButton_manualInputInfo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\211\213\345\212\250\345\275\225\345\205\245\344\277\241\346\201\257.png);\n"
"}\n"
"QPushButton:pressed{\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\211\213\345\212\250\345\275\225\345\205\245\344\277\241\346\201\257-\346\213\267\350\264\235.png);\n"
"}"));
        pushButton_manualInputInfo->setIconSize(QSize(159, 39));
        pushButton_manualInputInfo->setCheckable(true);
        pushButton_cancel_Colecting = new QPushButton(widget_colecting);
        pushButton_cancel_Colecting->setObjectName(QString::fromUtf8("pushButton_cancel_Colecting"));
        pushButton_cancel_Colecting->setGeometry(QRect(15, 910, 187, 59));
        pushButton_cancel_Colecting->setFocusPolicy(Qt::NoFocus);
        pushButton_cancel_Colecting->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\217\226\346\266\210\351\207\207\351\233\206.png);}\n"
"QPushButton:pressed{border-image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\217\226\346\266\210\351\207\207\351\233\206-\346\213\267\350\264\235.png);}"));
        widget_flight = new QWidget(widget_colecting);
        widget_flight->setObjectName(QString::fromUtf8("widget_flight"));
        widget_flight->setGeometry(QRect(15, 15, 770, 338));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu"));
        font4.setPointSize(50);
        widget_flight->setFont(font4);
        widget_flight->setStyleSheet(QString::fromUtf8("#widget_flight{image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\350\210\252\347\217\255\345\217\267bg.png);}"));
        label_midPlace = new ScrollText_Horizontal(widget_flight);
        label_midPlace->setObjectName(QString::fromUtf8("label_midPlace"));
        label_midPlace->setGeometry(QRect(270, 230, 200, 30));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setWeight(75);
        label_midPlace->setFont(font5);
        label_midPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_midPlace->setTextFormat(Qt::AutoText);
        label_midPlace->setScaledContents(true);
        label_midPlace->setAlignment(Qt::AlignCenter);
        layoutWidget_1 = new QWidget(widget_flight);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(16, 1, 766, 142));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
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
        QFont font6;
        font6.setPointSize(90);
        font6.setBold(true);
        font6.setWeight(75);
        label_mainFlightNO_->setFont(font6);
        label_mainFlightNO_->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));

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
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu"));
        font7.setPointSize(40);
        font7.setBold(true);
        font7.setWeight(75);
        label_fromPlace->setFont(font7);
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
        label_arrivalPlace->setFont(font7);
        label_arrivalPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_arrivalPlace->setScaledContents(true);
        label_arrivalPlace->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_arrivalPlace);

        widget_3 = new QWidget(widget_flight);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(200, 150, 371, 51));
        horizontalLayout_33 = new QHBoxLayout(widget_3);
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(-1, 0, -1, 0);
        label_text_shareFlight = new QLabel(widget_3);
        label_text_shareFlight->setObjectName(QString::fromUtf8("label_text_shareFlight"));
        QFont font8;
        font8.setPointSize(26);
        label_text_shareFlight->setFont(font8);
        label_text_shareFlight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_text_shareFlight->setTextFormat(Qt::RichText);

        horizontalLayout_33->addWidget(label_text_shareFlight);

        ScrollText_shareFlight = new ScrollText_Vertical(widget_3);
        ScrollText_shareFlight->setObjectName(QString::fromUtf8("ScrollText_shareFlight"));
        ScrollText_shareFlight->setMaximumSize(QSize(16777215, 16777215));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Ubuntu"));
        font9.setPointSize(26);
        font9.setBold(true);
        font9.setItalic(false);
        font9.setWeight(75);
        ScrollText_shareFlight->setFont(font9);
        ScrollText_shareFlight->setStyleSheet(QString::fromUtf8("color: #0fff7a;\n"
"font: bold 26pt \"Ubuntu\";"));

        horizontalLayout_33->addWidget(ScrollText_shareFlight);

        widget_colectedPPLcount->raise();
        widget_through2->raise();
        widget_through1->raise();
        pushButton_end_Colecting->raise();
        pushButton_start_Colecting->raise();
        pushButton_manualInputInfo->raise();
        pushButton_cancel_Colecting->raise();
        widget_flight->raise();
        widget_setting = new QWidget(widget_ALL);
        widget_setting->setObjectName(QString::fromUtf8("widget_setting"));
        widget_setting->setGeometry(QRect(0, 0, 800, 978));
        widget_setting->setFocusPolicy(Qt::NoFocus);
        widget_setting->setStyleSheet(QString::fromUtf8("#widget_setting{background-color: rgb(1, 64, 109);}"));
        widget_inputSetting = new QWidget(widget_setting);
        widget_inputSetting->setObjectName(QString::fromUtf8("widget_inputSetting"));
        widget_inputSetting->setGeometry(QRect(15, 10, 770, 956));
        widget_inputSetting->setFocusPolicy(Qt::NoFocus);
        widget_inputSetting->setStyleSheet(QString::fromUtf8("#widget_inputSetting{image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\350\256\276\347\275\256bg-\346\213\267\350\264\235.png);}"));
        pushButton_commit = new QPushButton(widget_inputSetting);
        pushButton_commit->setObjectName(QString::fromUtf8("pushButton_commit"));
        pushButton_commit->setGeometry(QRect(240, 850, 276, 47));
        pushButton_commit->setFocusPolicy(Qt::TabFocus);
        pushButton_commit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:0;\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\217\220\344\272\244.png);\n"
"}\n"
"QPushButton:pressed{\n"
"image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\217\220\344\272\244-\346\213\267\350\264\235.png);\n"
"}\n"
""));
        pushButton_commit->setIconSize(QSize(140, 40));
        label_1tt = new QLabel(widget_inputSetting);
        label_1tt->setObjectName(QString::fromUtf8("label_1tt"));
        label_1tt->setGeometry(QRect(40, 30, 380, 60));
        label_1tt->setMinimumSize(QSize(0, 0));
        label_1tt->setMaximumSize(QSize(16677725, 16777215));
        QFont font10;
        font10.setPointSize(36);
        font10.setBold(true);
        font10.setWeight(75);
        label_1tt->setFont(font10);
        label_1tt->setFocusPolicy(Qt::NoFocus);
        label_1tt->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_1tt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3tt = new QLabel(widget_inputSetting);
        label_3tt->setObjectName(QString::fromUtf8("label_3tt"));
        label_3tt->setGeometry(QRect(40, 430, 380, 60));
        label_3tt->setMinimumSize(QSize(0, 0));
        label_3tt->setMaximumSize(QSize(16677725, 16777215));
        label_3tt->setFont(font10);
        label_3tt->setFocusPolicy(Qt::NoFocus);
        label_3tt->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_3tt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2tt = new QLabel(widget_inputSetting);
        label_2tt->setObjectName(QString::fromUtf8("label_2tt"));
        label_2tt->setGeometry(QRect(40, 230, 380, 60));
        label_2tt->setMinimumSize(QSize(0, 0));
        label_2tt->setMaximumSize(QSize(16677725, 16777215));
        label_2tt->setFont(font10);
        label_2tt->setFocusPolicy(Qt::NoFocus);
        label_2tt->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_2tt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4tt = new QLabel(widget_inputSetting);
        label_4tt->setObjectName(QString::fromUtf8("label_4tt"));
        label_4tt->setGeometry(QRect(40, 630, 380, 60));
        label_4tt->setMinimumSize(QSize(0, 0));
        label_4tt->setMaximumSize(QSize(16677725, 16777215));
        label_4tt->setFont(font10);
        label_4tt->setFocusPolicy(Qt::NoFocus);
        label_4tt->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        label_4tt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_flightNO_ = new QLineEdit(widget_inputSetting);
        lineEdit_flightNO_->setObjectName(QString::fromUtf8("lineEdit_flightNO_"));
        lineEdit_flightNO_->setEnabled(true);
        lineEdit_flightNO_->setGeometry(QRect(150, 530, 444, 62));
        lineEdit_flightNO_->setFont(font);
        lineEdit_flightNO_->setFocusPolicy(Qt::StrongFocus);
        lineEdit_flightNO_->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background:transparent;\n"
"border-image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        lineEdit_flightNO_->setInputMethodHints(Qt::ImhPreferUppercase);
        lineEdit_flightDate = new QLineEdit(widget_inputSetting);
        lineEdit_flightDate->setObjectName(QString::fromUtf8("lineEdit_flightDate"));
        lineEdit_flightDate->setGeometry(QRect(150, 730, 444, 62));
        lineEdit_flightDate->setFont(font);
        lineEdit_flightDate->setFocusPolicy(Qt::StrongFocus);
        lineEdit_flightDate->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-image: url(:/1\347\231\273\345\275\225\347\225\214\351\235\242/Images/1\347\231\273\345\275\225\347\225\214\351\235\242/\345\234\206\350\247\222\347\237\251\345\275\242-1.png);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        pushButton_keyboard = new QPushButton(widget_inputSetting);
        pushButton_keyboard->setObjectName(QString::fromUtf8("pushButton_keyboard"));
        pushButton_keyboard->setGeometry(QRect(610, 540, 57, 39));
        pushButton_keyboard->setFocusPolicy(Qt::NoFocus);
        pushButton_keyboard->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\351\224\256\347\233\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_keyboard->setIcon(icon);
        pushButton_keyboard->setIconSize(QSize(57, 39));
        pushButton_calendar = new QPushButton(widget_inputSetting);
        pushButton_calendar->setObjectName(QString::fromUtf8("pushButton_calendar"));
        pushButton_calendar->setGeometry(QRect(610, 735, 51, 51));
        pushButton_calendar->setFocusPolicy(Qt::TabFocus);
        pushButton_calendar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\227\245\346\234\237.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_calendar->setIcon(icon1);
        pushButton_calendar->setIconSize(QSize(51, 51));
        splitter_1 = new QSplitter(widget_inputSetting);
        splitter_1->setObjectName(QString::fromUtf8("splitter_1"));
        splitter_1->setGeometry(QRect(100, 130, 630, 50));
        splitter_1->setFocusPolicy(Qt::NoFocus);
        splitter_1->setOrientation(Qt::Horizontal);
        splitter_1->setHandleWidth(0);
        radioButton_suspendColecting = new QRadioButton(splitter_1);
        radioButton_suspendColecting->setObjectName(QString::fromUtf8("radioButton_suspendColecting"));
        radioButton_suspendColecting->setFont(font);
        radioButton_suspendColecting->setFocusPolicy(Qt::NoFocus);
        radioButton_suspendColecting->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  34px;\n"
"    height:                 34px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
" 	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\213\276\351\200\211.png);\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\234\252\345\213\276\351\200\211.png);\n"
"}\n"
""));
        radioButton_suspendColecting->setChecked(true);
        splitter_1->addWidget(radioButton_suspendColecting);
        radioButton_landedColecting = new QRadioButton(splitter_1);
        radioButton_landedColecting->setObjectName(QString::fromUtf8("radioButton_landedColecting"));
        radioButton_landedColecting->setFont(font);
        radioButton_landedColecting->setFocusPolicy(Qt::NoFocus);
        radioButton_landedColecting->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  34px;\n"
"    height:                 34px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    \n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\213\276\351\200\211.png);\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\234\252\345\213\276\351\200\211.png);\n"
"}\n"
"\n"
""));
        splitter_1->addWidget(radioButton_landedColecting);
        splitter = new QSplitter(widget_inputSetting);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(100, 330, 630, 50));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        radioButton_faceColecting = new QRadioButton(splitter);
        radioButton_faceColecting->setObjectName(QString::fromUtf8("radioButton_faceColecting"));
        radioButton_faceColecting->setFont(font);
        radioButton_faceColecting->setFocusPolicy(Qt::NoFocus);
        radioButton_faceColecting->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  34px;\n"
"    height:                 34px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    \n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\213\276\351\200\211.png);\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\234\252\345\213\276\351\200\211.png);\n"
"}\n"
"\n"
""));
        radioButton_faceColecting->setChecked(true);
        splitter->addWidget(radioButton_faceColecting);
        radioButton_quickColecting = new QRadioButton(splitter);
        radioButton_quickColecting->setObjectName(QString::fromUtf8("radioButton_quickColecting"));
        radioButton_quickColecting->setFont(font);
        radioButton_quickColecting->setFocusPolicy(Qt::NoFocus);
        radioButton_quickColecting->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QRadioButton::indicator {\n"
"    width:                  34px;\n"
"    height:                 34px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    \n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\345\213\276\351\200\211.png);\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/5\344\272\272\345\203\217\351\207\207\351\233\206/Images/5\344\272\272\345\203\217\351\207\207\351\233\206/\346\234\252\345\213\276\351\200\211.png);\n"
"}\n"
"\n"
""));
        splitter->addWidget(radioButton_quickColecting);
        calendarWidget_background = new QWidget(widget_inputSetting);
        calendarWidget_background->setObjectName(QString::fromUtf8("calendarWidget_background"));
        calendarWidget_background->setGeometry(QRect(0, 0, 770, 956));
        calendarWidget_background->setFocusPolicy(Qt::NoFocus);
        calendarWidget_background->setStyleSheet(QString::fromUtf8(""));
        calendarWidget = new QCalendarWidget(calendarWidget_background);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(140, 420, 500, 300));
        calendarWidget->setFocusPolicy(Qt::NoFocus);
        calendarWidget->setStyleSheet(QString::fromUtf8("QCalendarWidget QWidget#qt_calendar_navigationbar{\n"
"background-color: #00649c;\n"
"}\n"
"QCalendarWidget QTableView \n"
"{\n"
"    alternate-background-color: #cccccc;\n"
"}\n"
"QAbstractItemView {\n"
"    selection-color: white;\n"
"    selection-background-color:cyan ;\n"
"    font: 14px;\n"
"}"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        splitter->raise();
        splitter_1->raise();
        pushButton_commit->raise();
        label_1tt->raise();
        label_3tt->raise();
        label_2tt->raise();
        label_4tt->raise();
        lineEdit_flightNO_->raise();
        lineEdit_flightDate->raise();
        pushButton_keyboard->raise();
        pushButton_calendar->raise();
        calendarWidget_background->raise();

        retranslateUi(PortraitCollection);

        QMetaObject::connectSlotsByName(PortraitCollection);
    } // setupUi

    void retranslateUi(QWidget *PortraitCollection)
    {
        PortraitCollection->setWindowTitle(QApplication::translate("PortraitCollection", "\344\272\272\345\203\217\351\207\207\351\233\206", nullptr));
        pushButton_start_Colecting->setText(QString());
        label_1text->setText(QApplication::translate("PortraitCollection", "\345\267\262\351\207\207\351\233\206\344\272\272\346\225\260\357\274\232", nullptr));
        label_countColected->setText(QApplication::translate("PortraitCollection", "0", nullptr));
        label_faceImage_R->setText(QString());
        label_8t->setText(QApplication::translate("PortraitCollection", "| 2\345\217\267\351\200\232\351\201\223", nullptr));
        pushButton_release_R->setText(QString());
        label_colectResult_R->setText(QString());
        toolButton_childMode_R->setText(QString());
        label_4t->setText(QApplication::translate("PortraitCollection", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_flightNO_R->setText(QString());
        label_5t->setText(QApplication::translate("PortraitCollection", "\345\272\217\345\217\267\357\274\232", nullptr));
        label_boardingNO_R->setText(QString());
        label_6t->setText(QApplication::translate("PortraitCollection", "\345\272\247\344\275\215\345\217\267\357\274\232", nullptr));
        label_seatNO_R->setText(QString());
        label_frontGround_R->setText(QString());
        label_3t_3->setText(QApplication::translate("PortraitCollection", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        label_cardID_R->setText(QString());
        pushButton_prevent_R->setText(QString());
        label_faceImage_L->setText(QString());
        label_9t->setText(QApplication::translate("PortraitCollection", "| 1\345\217\267\351\200\232\351\201\223", nullptr));
        pushButton_release_L->setText(QString());
        label_colectResult_L->setText(QString());
        toolButton_childMode_L->setText(QString());
        label_1t->setText(QApplication::translate("PortraitCollection", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_flightNO_L->setText(QString());
        label_3t->setText(QApplication::translate("PortraitCollection", "\345\272\247\344\275\215\345\217\267\357\274\232", nullptr));
        label_seatNO_L->setText(QString());
        label_2t->setText(QApplication::translate("PortraitCollection", "\345\272\217\345\217\267\357\274\232", nullptr));
        label_boardingNO_L->setText(QString());
        label_frontGround_L->setText(QString());
        label_cardID_L->setText(QString());
        label_3t_4->setText(QApplication::translate("PortraitCollection", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        pushButton_prevent_L->setText(QString());
        pushButton_end_Colecting->setText(QString());
        pushButton_manualInputInfo->setText(QString());
        pushButton_cancel_Colecting->setText(QString());
        label_midPlace->setText(QString());
        label_picture_plane->setText(QString());
        label_mainFlightNO_->setText(QApplication::translate("PortraitCollection", "- - - - - -", nullptr));
        label_fromPlace->setText(QApplication::translate("PortraitCollection", "- - - -", nullptr));
        label_picture_pointTo->setText(QString());
        label_arrivalPlace->setText(QApplication::translate("PortraitCollection", "- - - -", nullptr));
        label_text_shareFlight->setText(QApplication::translate("PortraitCollection", "\345\205\261\344\272\253\350\210\252\347\217\255\357\274\232\n"
"", nullptr));
        pushButton_commit->setText(QString());
        label_1tt->setText(QApplication::translate("PortraitCollection", "\350\257\267\351\200\211\346\213\251\351\207\207\351\233\206\347\261\273\345\236\213\357\274\232", nullptr));
        label_3tt->setText(QApplication::translate("PortraitCollection", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        label_2tt->setText(QApplication::translate("PortraitCollection", "\350\257\267\351\200\211\346\213\251\351\207\207\351\233\206\346\226\271\345\274\217\357\274\232", nullptr));
        label_4tt->setText(QApplication::translate("PortraitCollection", "\350\257\267\351\200\211\346\213\251\350\210\252\347\217\255\346\227\245\346\234\237\357\274\232", nullptr));
        lineEdit_flightNO_->setText(QString());
        lineEdit_flightNO_->setPlaceholderText(QApplication::translate("PortraitCollection", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267", nullptr));
        lineEdit_flightDate->setInputMask(QString());
        lineEdit_flightDate->setText(QString());
        lineEdit_flightDate->setPlaceholderText(QApplication::translate("PortraitCollection", "\350\257\267\351\200\211\346\213\251\350\210\252\347\217\255\346\227\245\346\234\237", nullptr));
        pushButton_keyboard->setText(QString());
        pushButton_calendar->setText(QString());
        radioButton_suspendColecting->setText(QApplication::translate("PortraitCollection", "\350\277\207\347\253\231\345\200\222\345\210\267", nullptr));
        radioButton_landedColecting->setText(QApplication::translate("PortraitCollection", "\345\244\207\351\231\215\345\200\222\345\210\267", nullptr));
        radioButton_faceColecting->setText(QApplication::translate("PortraitCollection", "\344\272\272\350\204\270\351\207\207\351\233\206", nullptr));
        radioButton_quickColecting->setText(QApplication::translate("PortraitCollection", "\345\210\267\347\211\214\351\207\207\351\233\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortraitCollection: public Ui_PortraitCollection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTRAITCOLLECTION_H
