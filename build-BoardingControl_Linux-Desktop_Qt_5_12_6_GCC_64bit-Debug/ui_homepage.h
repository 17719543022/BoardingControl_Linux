/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *centralWidget;
    QWidget *widget_ALL;
    QWidget *widget_gateCtrl;
    QWidget *wg_2;
    QToolButton *Button_A1;
    QToolButton *Button_B1;
    QWidget *wg_3;
    QToolButton *Button_A2;
    QToolButton *Button_B2;
    QWidget *wg_4;
    QToolButton *Button_stop1;
    QToolButton *Button_stop2;
    QWidget *wg_5;
    QToolButton *Button_keepClose1;
    QToolButton *Button_keepClose2;
    QWidget *wg_6;
    QToolButton *Button_SideDoor1;
    QToolButton *Button_SideDoor2;
    QWidget *widget_logo;
    QLabel *label_boardingGateNo_;
    QLabel *label_netStat;
    QLabel *label_currentTime;
    QLabel *label_Version;
    QWidget *widget_menuUp;
    QPushButton *Button_menu;
    QPushButton *Button_return;
    QToolButton *Button_changeBoardingMode_face;
    ScrollText_Horizontal *label_statTips;
    QToolButton *Button_changeBoardingMode_quick;
    QWidget *widget_menuBelow;
    QPushButton *Button_FlightEnquires;
    QPushButton *Button_PortraitCollection;
    QPushButton *Button_WorkflowRecording;
    QPushButton *Button_RealtimeBoarding;
    QPushButton *Button_SignOut;
    QPushButton *Button_HomePage;
    QWidget *widget_workForeground;
    QWidget *widget_work;
    QWidget *widget_home;
    QWidget *wg_homeOptions;
    QPushButton *Button_WorkflowRecording_2;
    QPushButton *Button_RealtimeBoarding_2;
    QPushButton *Button_PortraitCollection_2;
    QPushButton *Button_FlightEnquires_2;

    void setupUi(QMainWindow *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QString::fromUtf8("HomePage"));
        HomePage->resize(800, 1280);
        centralWidget = new QWidget(HomePage);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget_ALL = new QWidget(centralWidget);
        widget_ALL->setObjectName(QString::fromUtf8("widget_ALL"));
        widget_ALL->setGeometry(QRect(0, 0, 800, 1280));
        widget_ALL->setFocusPolicy(Qt::NoFocus);
        widget_gateCtrl = new QWidget(widget_ALL);
        widget_gateCtrl->setObjectName(QString::fromUtf8("widget_gateCtrl"));
        widget_gateCtrl->setGeometry(QRect(0, 1088, 800, 192));
        widget_gateCtrl->setFocusPolicy(Qt::NoFocus);
        widget_gateCtrl->setStyleSheet(QString::fromUtf8("#widget_gateCtrl{background-color: rgb(1, 64, 109);}"));
        wg_2 = new QWidget(widget_gateCtrl);
        wg_2->setObjectName(QString::fromUtf8("wg_2"));
        wg_2->setGeometry(QRect(16, 8, 144, 174));
        wg_2->setFocusPolicy(Qt::NoFocus);
        wg_2->setStyleSheet(QString::fromUtf8("#wg_2{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\214\211\351\222\256\345\272\225\346\241\206.png);}"));
        Button_A1 = new QToolButton(wg_2);
        Button_A1->setObjectName(QString::fromUtf8("Button_A1"));
        Button_A1->setGeometry(QRect(4, 14, 134, 70));
        Button_A1->setFocusPolicy(Qt::NoFocus);
        Button_A1->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/A1\351\227\250.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/A1\351\227\2502.png);}\n"
""));
        Button_A1->setIconSize(QSize(165, 66));
        Button_B1 = new QToolButton(wg_2);
        Button_B1->setObjectName(QString::fromUtf8("Button_B1"));
        Button_B1->setEnabled(false);
        Button_B1->setGeometry(QRect(4, 92, 134, 70));
        Button_B1->setFocusPolicy(Qt::NoFocus);
        Button_B1->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/B1\351\227\250.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/B1\351\227\2502.png);}"));
        Button_B1->setIconSize(QSize(165, 66));
        wg_3 = new QWidget(widget_gateCtrl);
        wg_3->setObjectName(QString::fromUtf8("wg_3"));
        wg_3->setGeometry(QRect(172, 8, 144, 174));
        wg_3->setFocusPolicy(Qt::NoFocus);
        wg_3->setStyleSheet(QString::fromUtf8("#wg_3{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\214\211\351\222\256\345\272\225\346\241\206.png);}"));
        Button_A2 = new QToolButton(wg_3);
        Button_A2->setObjectName(QString::fromUtf8("Button_A2"));
        Button_A2->setGeometry(QRect(4, 14, 134, 70));
        Button_A2->setFocusPolicy(Qt::NoFocus);
        Button_A2->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/A2\351\227\250.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/A2\351\227\2502.png);}"));
        Button_A2->setIconSize(QSize(165, 66));
        Button_B2 = new QToolButton(wg_3);
        Button_B2->setObjectName(QString::fromUtf8("Button_B2"));
        Button_B2->setEnabled(false);
        Button_B2->setGeometry(QRect(4, 92, 134, 70));
        Button_B2->setFocusPolicy(Qt::NoFocus);
        Button_B2->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/B2\351\227\250.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/B2\351\227\2502.png);}"));
        Button_B2->setIconSize(QSize(165, 66));
        wg_4 = new QWidget(widget_gateCtrl);
        wg_4->setObjectName(QString::fromUtf8("wg_4"));
        wg_4->setGeometry(QRect(484, 8, 144, 174));
        wg_4->setFocusPolicy(Qt::NoFocus);
        wg_4->setStyleSheet(QString::fromUtf8("#wg_4{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\214\211\351\222\256\345\272\225\346\241\206.png);}"));
        Button_stop1 = new QToolButton(wg_4);
        Button_stop1->setObjectName(QString::fromUtf8("Button_stop1"));
        Button_stop1->setGeometry(QRect(4, 14, 134, 70));
        Button_stop1->setFocusPolicy(Qt::NoFocus);
        Button_stop1->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\232\202\345\201\234\357\274\2101\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\232\202\345\201\234\357\274\2101\345\217\267\357\274\2112.png);}\n"
""));
        Button_stop1->setIconSize(QSize(165, 66));
        Button_stop2 = new QToolButton(wg_4);
        Button_stop2->setObjectName(QString::fromUtf8("Button_stop2"));
        Button_stop2->setGeometry(QRect(4, 92, 134, 70));
        Button_stop2->setFocusPolicy(Qt::NoFocus);
        Button_stop2->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\232\202\345\201\234\357\274\2102\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\232\202\345\201\234\357\274\2102\345\217\267\357\274\2112.png);}\n"
""));
        Button_stop2->setIconSize(QSize(165, 66));
        wg_5 = new QWidget(widget_gateCtrl);
        wg_5->setObjectName(QString::fromUtf8("wg_5"));
        wg_5->setGeometry(QRect(640, 8, 144, 174));
        wg_5->setFocusPolicy(Qt::NoFocus);
        wg_5->setStyleSheet(QString::fromUtf8("#wg_5{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\214\211\351\222\256\345\272\225\346\241\206.png);}"));
        Button_keepClose1 = new QToolButton(wg_5);
        Button_keepClose1->setObjectName(QString::fromUtf8("Button_keepClose1"));
        Button_keepClose1->setGeometry(QRect(4, 14, 134, 70));
        Button_keepClose1->setFocusPolicy(Qt::NoFocus);
        Button_keepClose1->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\270\270\351\227\255\357\274\2101\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\270\270\351\227\255\357\274\2101\345\217\267\357\274\2112.png);}"));
        Button_keepClose1->setIconSize(QSize(165, 66));
        Button_keepClose2 = new QToolButton(wg_5);
        Button_keepClose2->setObjectName(QString::fromUtf8("Button_keepClose2"));
        Button_keepClose2->setGeometry(QRect(4, 92, 134, 70));
        Button_keepClose2->setFocusPolicy(Qt::NoFocus);
        Button_keepClose2->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\270\270\351\227\255\357\274\2102\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\270\270\351\227\255\357\274\2102\345\217\267\357\274\2112.png);}"));
        Button_keepClose2->setIconSize(QSize(165, 66));
        wg_6 = new QWidget(widget_gateCtrl);
        wg_6->setObjectName(QString::fromUtf8("wg_6"));
        wg_6->setGeometry(QRect(328, 10, 144, 174));
        wg_6->setFocusPolicy(Qt::NoFocus);
        wg_6->setStyleSheet(QString::fromUtf8("#wg_6{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\346\214\211\351\222\256\345\272\225\346\241\206.png);}"));
        Button_SideDoor1 = new QToolButton(wg_6);
        Button_SideDoor1->setObjectName(QString::fromUtf8("Button_SideDoor1"));
        Button_SideDoor1->setGeometry(QRect(4, 14, 134, 70));
        Button_SideDoor1->setFocusPolicy(Qt::NoFocus);
        Button_SideDoor1->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\276\247\351\227\250\357\274\2101\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\276\247\351\227\250\357\274\2101\345\217\267\357\274\2112.png);}"));
        Button_SideDoor1->setIconSize(QSize(165, 66));
        Button_SideDoor2 = new QToolButton(wg_6);
        Button_SideDoor2->setObjectName(QString::fromUtf8("Button_SideDoor2"));
        Button_SideDoor2->setGeometry(QRect(4, 92, 134, 70));
        Button_SideDoor2->setFocusPolicy(Qt::NoFocus);
        Button_SideDoor2->setStyleSheet(QString::fromUtf8("QToolButton{border:none;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\276\247\351\227\250\357\274\2102\345\217\267\357\274\211.png);}\n"
"QToolButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\276\247\351\227\250\357\274\2102\345\217\267\357\274\2112.png);}"));
        Button_SideDoor2->setIconSize(QSize(165, 66));
        widget_logo = new QWidget(widget_ALL);
        widget_logo->setObjectName(QString::fromUtf8("widget_logo"));
        widget_logo->setGeometry(QRect(0, 0, 800, 50));
        widget_logo->setFocusPolicy(Qt::NoFocus);
        widget_logo->setStyleSheet(QString::fromUtf8("#widget_logo{image: url(Images/logo.png);}"));
        label_boardingGateNo_ = new QLabel(widget_logo);
        label_boardingGateNo_->setObjectName(QString::fromUtf8("label_boardingGateNo_"));
        label_boardingGateNo_->setGeometry(QRect(0, 0, 85, 50));
        QFont font;
        font.setPointSize(30);
        label_boardingGateNo_->setFont(font);
        label_boardingGateNo_->setFocusPolicy(Qt::NoFocus);
        label_boardingGateNo_->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_boardingGateNo_->setAlignment(Qt::AlignCenter);
        label_netStat = new QLabel(widget_logo);
        label_netStat->setObjectName(QString::fromUtf8("label_netStat"));
        label_netStat->setGeometry(QRect(750, 0, 50, 50));
        QFont font1;
        font1.setPointSize(14);
        label_netStat->setFont(font1);
        label_netStat->setFocusPolicy(Qt::NoFocus);
        label_netStat->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_netStat->setPixmap(QPixmap(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/wifi/\346\234\211.png")));
        label_netStat->setAlignment(Qt::AlignCenter);
        label_currentTime = new QLabel(widget_logo);
        label_currentTime->setObjectName(QString::fromUtf8("label_currentTime"));
        label_currentTime->setGeometry(QRect(660, 4, 80, 46));
        label_currentTime->setFont(font1);
        label_currentTime->setFocusPolicy(Qt::NoFocus);
        label_currentTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_currentTime->setAlignment(Qt::AlignCenter);
        label_Version = new QLabel(widget_logo);
        label_Version->setObjectName(QString::fromUtf8("label_Version"));
        label_Version->setGeometry(QRect(580, 4, 80, 46));
        label_Version->setFont(font1);
        label_Version->setFocusPolicy(Qt::NoFocus);
        label_Version->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Version->setAlignment(Qt::AlignCenter);
        widget_menuUp = new QWidget(widget_ALL);
        widget_menuUp->setObjectName(QString::fromUtf8("widget_menuUp"));
        widget_menuUp->setGeometry(QRect(0, 50, 800, 60));
        widget_menuUp->setFocusPolicy(Qt::NoFocus);
        widget_menuUp->setStyleSheet(QString::fromUtf8("#widget_menuUp{background-color: rgb(0, 130, 180);}"));
        Button_menu = new QPushButton(widget_menuUp);
        Button_menu->setObjectName(QString::fromUtf8("Button_menu"));
        Button_menu->setGeometry(QRect(360, 5, 80, 50));
        Button_menu->setFocusPolicy(Qt::NoFocus);
        Button_menu->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\350\256\276\347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_menu->setIcon(icon);
        Button_menu->setIconSize(QSize(46, 42));
        Button_menu->setCheckable(true);
        Button_return = new QPushButton(widget_menuUp);
        Button_return->setObjectName(QString::fromUtf8("Button_return"));
        Button_return->setGeometry(QRect(10, 5, 46, 50));
        Button_return->setFocusPolicy(Qt::NoFocus);
        Button_return->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\350\277\224\345\233\236.png"), QSize(), QIcon::Normal, QIcon::Off);
        Button_return->setIcon(icon1);
        Button_return->setIconSize(QSize(22, 36));
        Button_return->setChecked(false);
        Button_changeBoardingMode_face = new QToolButton(widget_menuUp);
        Button_changeBoardingMode_face->setObjectName(QString::fromUtf8("Button_changeBoardingMode_face"));
        Button_changeBoardingMode_face->setGeometry(QRect(600, 12, 88, 34));
        Button_changeBoardingMode_face->setFocusPolicy(Qt::NoFocus);
        Button_changeBoardingMode_face->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"border:none; \n"
"image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\210\207\346\215\242\347\231\273\346\234\272\346\250\241\345\274\217/\344\272\272\350\204\270\346\250\241\345\274\217-\346\213\267\350\264\235.png);\n"
"}\n"
"QToolButton:checked{\n"
" image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\210\207\346\215\242\347\231\273\346\234\272\346\250\241\345\274\217/\344\272\272\350\204\270\346\250\241\345\274\217.png);\n"
"}\n"
""));
        Button_changeBoardingMode_face->setIconSize(QSize(276, 47));
        Button_changeBoardingMode_face->setCheckable(true);
        Button_changeBoardingMode_face->setChecked(false);
        label_statTips = new ScrollText_Horizontal(widget_menuUp);
        label_statTips->setObjectName(QString::fromUtf8("label_statTips"));
        label_statTips->setGeometry(QRect(62, 10, 300, 40));
        label_statTips->setStyleSheet(QString::fromUtf8(""));
        label_statTips->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Button_changeBoardingMode_quick = new QToolButton(widget_menuUp);
        Button_changeBoardingMode_quick->setObjectName(QString::fromUtf8("Button_changeBoardingMode_quick"));
        Button_changeBoardingMode_quick->setGeometry(QRect(688, 12, 88, 34));
        Button_changeBoardingMode_quick->setFocusPolicy(Qt::NoFocus);
        Button_changeBoardingMode_quick->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"border:none; \n"
"image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\210\207\346\215\242\347\231\273\346\234\272\346\250\241\345\274\217/\345\277\253\351\200\237\346\250\241\345\274\217-\346\213\267\350\264\235.png);\n"
"}\n"
"QToolButton:checked{\n"
" image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\210\207\346\215\242\347\231\273\346\234\272\346\250\241\345\274\217/\345\277\253\351\200\237\346\250\241\345\274\217.png);\n"
"}"));
        Button_changeBoardingMode_quick->setIconSize(QSize(276, 47));
        Button_changeBoardingMode_quick->setCheckable(true);
        Button_changeBoardingMode_quick->setChecked(false);
        widget_menuBelow = new QWidget(widget_ALL);
        widget_menuBelow->setObjectName(QString::fromUtf8("widget_menuBelow"));
        widget_menuBelow->setGeometry(QRect(0, -96, 800, 196));
        widget_menuBelow->setFocusPolicy(Qt::NoFocus);
        widget_menuBelow->setStyleSheet(QString::fromUtf8("#widget_menuBelow{background-color: rgb(0, 130, 180);}"));
        Button_FlightEnquires = new QPushButton(widget_menuBelow);
        Button_FlightEnquires->setObjectName(QString::fromUtf8("Button_FlightEnquires"));
        Button_FlightEnquires->setGeometry(QRect(60, 110, 180, 60));
        QFont font2;
        font2.setPointSize(20);
        Button_FlightEnquires->setFont(font2);
        Button_FlightEnquires->setFocusPolicy(Qt::NoFocus);
        Button_FlightEnquires->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\350\210\252\347\217\255\345\233\236\346\237\245.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\350\210\252\347\217\255\345\233\236\346\237\245-\346\213\267\350\264\235.png);}"));
        Button_FlightEnquires->setIconSize(QSize(180, 60));
        Button_PortraitCollection = new QPushButton(widget_menuBelow);
        Button_PortraitCollection->setObjectName(QString::fromUtf8("Button_PortraitCollection"));
        Button_PortraitCollection->setGeometry(QRect(300, 110, 180, 60));
        Button_PortraitCollection->setFont(font2);
        Button_PortraitCollection->setFocusPolicy(Qt::NoFocus);
        Button_PortraitCollection->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\344\272\272\345\203\217\351\207\207\351\233\206.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\344\272\272\345\203\217\351\207\207\351\233\206-\346\213\267\350\264\235.png);}"));
        Button_PortraitCollection->setIconSize(QSize(180, 60));
        Button_WorkflowRecording = new QPushButton(widget_menuBelow);
        Button_WorkflowRecording->setObjectName(QString::fromUtf8("Button_WorkflowRecording"));
        Button_WorkflowRecording->setGeometry(QRect(550, 30, 180, 60));
        Button_WorkflowRecording->setFont(font2);
        Button_WorkflowRecording->setFocusPolicy(Qt::NoFocus);
        Button_WorkflowRecording->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\345\205\250\346\265\201\347\250\213\350\256\260\345\275\225.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\345\205\250\346\265\201\347\250\213\350\256\260\345\275\225-\346\213\267\350\264\235.png);}\n"
"\n"
"\n"
""));
        Button_WorkflowRecording->setIconSize(QSize(180, 60));
        Button_WorkflowRecording->setCheckable(false);
        Button_RealtimeBoarding = new QPushButton(widget_menuBelow);
        Button_RealtimeBoarding->setObjectName(QString::fromUtf8("Button_RealtimeBoarding"));
        Button_RealtimeBoarding->setGeometry(QRect(300, 30, 180, 60));
        Button_RealtimeBoarding->setFont(font2);
        Button_RealtimeBoarding->setFocusPolicy(Qt::NoFocus);
        Button_RealtimeBoarding->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\345\256\236\346\227\266\347\231\273\346\234\272.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\345\256\236\346\227\266\347\231\273\346\234\272-\346\213\267\350\264\235.png);}"));
        Button_RealtimeBoarding->setIconSize(QSize(180, 60));
        Button_RealtimeBoarding->setAutoRepeatInterval(100);
        Button_SignOut = new QPushButton(widget_menuBelow);
        Button_SignOut->setObjectName(QString::fromUtf8("Button_SignOut"));
        Button_SignOut->setGeometry(QRect(550, 110, 180, 60));
        Button_SignOut->setFont(font2);
        Button_SignOut->setFocusPolicy(Qt::NoFocus);
        Button_SignOut->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:10;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\351\200\200\345\207\272\347\231\273\345\275\225.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\351\200\200\345\207\272\347\231\273\345\275\225-\346\213\267\350\264\235.png);}"));
        Button_SignOut->setIconSize(QSize(180, 60));
        Button_HomePage = new QPushButton(widget_menuBelow);
        Button_HomePage->setObjectName(QString::fromUtf8("Button_HomePage"));
        Button_HomePage->setGeometry(QRect(60, 30, 180, 60));
        Button_HomePage->setFont(font2);
        Button_HomePage->setFocusPolicy(Qt::NoFocus);
        Button_HomePage->setStyleSheet(QString::fromUtf8("QPushButton{border:0;image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\347\263\273\347\273\237\351\246\226\351\241\265.png);}\n"
"QPushButton:pressed{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\270\213\346\213\211\347\252\227\345\217\243/\347\263\273\347\273\237\351\246\226\351\241\265-\346\213\267\350\264\235.png);}"));
        Button_HomePage->setIconSize(QSize(180, 60));
        Button_HomePage->setAutoRepeatInterval(100);
        widget_workForeground = new QWidget(widget_ALL);
        widget_workForeground->setObjectName(QString::fromUtf8("widget_workForeground"));
        widget_workForeground->setGeometry(QRect(0, 110, 800, 978));
        widget_workForeground->setFocusPolicy(Qt::NoFocus);
        widget_workForeground->setStyleSheet(QString::fromUtf8(""));
        widget_work = new QWidget(widget_ALL);
        widget_work->setObjectName(QString::fromUtf8("widget_work"));
        widget_work->setGeometry(QRect(0, 110, 800, 978));
        widget_work->setFocusPolicy(Qt::NoFocus);
        widget_work->setStyleSheet(QString::fromUtf8(""));
        widget_home = new QWidget(widget_work);
        widget_home->setObjectName(QString::fromUtf8("widget_home"));
        widget_home->setGeometry(QRect(0, 0, 800, 978));
        widget_home->setFocusPolicy(Qt::NoFocus);
        widget_home->setStyleSheet(QString::fromUtf8("#widget_home{background-color: rgb(1, 64, 109);}"));
        wg_homeOptions = new QWidget(widget_home);
        wg_homeOptions->setObjectName(QString::fromUtf8("wg_homeOptions"));
        wg_homeOptions->setGeometry(QRect(15, 10, 770, 958));
        wg_homeOptions->setFocusPolicy(Qt::NoFocus);
        wg_homeOptions->setStyleSheet(QString::fromUtf8("#wg_homeOptions{image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/bg-\346\213\267\350\264\235.png);}"));
        Button_WorkflowRecording_2 = new QPushButton(wg_homeOptions);
        Button_WorkflowRecording_2->setObjectName(QString::fromUtf8("Button_WorkflowRecording_2"));
        Button_WorkflowRecording_2->setGeometry(QRect(97, 270, 576, 188));
        Button_WorkflowRecording_2->setFont(font2);
        Button_WorkflowRecording_2->setFocusPolicy(Qt::NoFocus);
        Button_WorkflowRecording_2->setStyleSheet(QString::fromUtf8("border-radius:10;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\205\250\346\265\201\347\250\213\350\256\260\345\275\2251.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\205\250\346\265\201\347\250\213\350\256\260\345\275\2251.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\205\250\346\265\201\347\250\213\350\256\260\345\275\2251.png"), QSize(), QIcon::Disabled, QIcon::On);
        Button_WorkflowRecording_2->setIcon(icon2);
        Button_WorkflowRecording_2->setIconSize(QSize(576, 188));
        Button_RealtimeBoarding_2 = new QPushButton(wg_homeOptions);
        Button_RealtimeBoarding_2->setObjectName(QString::fromUtf8("Button_RealtimeBoarding_2"));
        Button_RealtimeBoarding_2->setGeometry(QRect(97, 41, 576, 188));
        Button_RealtimeBoarding_2->setFont(font2);
        Button_RealtimeBoarding_2->setFocusPolicy(Qt::NoFocus);
        Button_RealtimeBoarding_2->setStyleSheet(QString::fromUtf8("border-radius:10;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\256\236\346\227\266\347\231\273\346\234\2721.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\256\236\346\227\266\347\231\273\346\234\2721.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\256\236\346\227\266\347\231\273\346\234\2721.png"), QSize(), QIcon::Disabled, QIcon::On);
        Button_RealtimeBoarding_2->setIcon(icon3);
        Button_RealtimeBoarding_2->setIconSize(QSize(576, 188));
        Button_RealtimeBoarding_2->setAutoRepeatInterval(100);
        Button_PortraitCollection_2 = new QPushButton(wg_homeOptions);
        Button_PortraitCollection_2->setObjectName(QString::fromUtf8("Button_PortraitCollection_2"));
        Button_PortraitCollection_2->setGeometry(QRect(97, 728, 576, 188));
        Button_PortraitCollection_2->setFont(font2);
        Button_PortraitCollection_2->setFocusPolicy(Qt::NoFocus);
        Button_PortraitCollection_2->setStyleSheet(QString::fromUtf8("border-radius:10;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\272\272\345\203\217\351\207\207\351\233\2061.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\272\272\345\203\217\351\207\207\351\233\2061.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\344\272\272\345\203\217\351\207\207\351\233\2061.png"), QSize(), QIcon::Disabled, QIcon::On);
        Button_PortraitCollection_2->setIcon(icon4);
        Button_PortraitCollection_2->setIconSize(QSize(576, 188));
        Button_FlightEnquires_2 = new QPushButton(wg_homeOptions);
        Button_FlightEnquires_2->setObjectName(QString::fromUtf8("Button_FlightEnquires_2"));
        Button_FlightEnquires_2->setGeometry(QRect(97, 499, 576, 188));
        Button_FlightEnquires_2->setFont(font2);
        Button_FlightEnquires_2->setFocusPolicy(Qt::NoFocus);
        Button_FlightEnquires_2->setStyleSheet(QString::fromUtf8("border-radius:10;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\350\210\252\347\217\255\345\233\236\346\237\2451.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\350\210\252\347\217\255\345\233\236\346\237\2451.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\350\210\252\347\217\255\345\233\236\346\237\2451.png"), QSize(), QIcon::Disabled, QIcon::On);
        Button_FlightEnquires_2->setIcon(icon5);
        Button_FlightEnquires_2->setIconSize(QSize(576, 188));
        widget_work->raise();
        widget_gateCtrl->raise();
        widget_workForeground->raise();
        widget_menuBelow->raise();
        widget_logo->raise();
        widget_menuUp->raise();
        HomePage->setCentralWidget(centralWidget);
        QWidget::setTabOrder(Button_A1, Button_B1);
        QWidget::setTabOrder(Button_B1, Button_A2);
        QWidget::setTabOrder(Button_A2, Button_B2);
        QWidget::setTabOrder(Button_B2, Button_stop1);
        QWidget::setTabOrder(Button_stop1, Button_stop2);
        QWidget::setTabOrder(Button_stop2, Button_keepClose1);
        QWidget::setTabOrder(Button_keepClose1, Button_keepClose2);
        QWidget::setTabOrder(Button_keepClose2, Button_menu);
        QWidget::setTabOrder(Button_menu, Button_return);
        QWidget::setTabOrder(Button_return, Button_FlightEnquires);
        QWidget::setTabOrder(Button_FlightEnquires, Button_PortraitCollection);
        QWidget::setTabOrder(Button_PortraitCollection, Button_RealtimeBoarding);
        QWidget::setTabOrder(Button_RealtimeBoarding, Button_WorkflowRecording);
        QWidget::setTabOrder(Button_WorkflowRecording, Button_SignOut);
        QWidget::setTabOrder(Button_SignOut, Button_HomePage);

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QMainWindow *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "BoardingControl", nullptr));
        Button_A1->setText(QString());
        Button_B1->setText(QString());
        Button_A2->setText(QString());
        Button_B2->setText(QString());
        Button_stop1->setText(QString());
        Button_stop2->setText(QString());
        Button_keepClose1->setText(QString());
        Button_keepClose2->setText(QString());
        Button_SideDoor1->setText(QString());
        Button_SideDoor2->setText(QString());
        label_boardingGateNo_->setText(QApplication::translate("HomePage", "---", nullptr));
        label_netStat->setText(QString());
        label_currentTime->setText(QApplication::translate("HomePage", "00:00:00", nullptr));
        label_Version->setText(QApplication::translate("HomePage", "V2.0.0", nullptr));
        Button_changeBoardingMode_face->setText(QString());
        label_statTips->setText(QString());
        Button_changeBoardingMode_quick->setText(QString());
        Button_FlightEnquires->setText(QString());
        Button_PortraitCollection->setText(QString());
        Button_WorkflowRecording->setText(QString());
        Button_RealtimeBoarding->setText(QString());
        Button_SignOut->setText(QString());
        Button_HomePage->setText(QString());
        Button_WorkflowRecording_2->setText(QString());
        Button_RealtimeBoarding_2->setText(QString());
        Button_PortraitCollection_2->setText(QString());
        Button_FlightEnquires_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
