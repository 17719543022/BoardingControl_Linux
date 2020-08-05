/********************************************************************************
** Form generated from reading UI file 'flightenquires.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTENQUIRES_H
#define UI_FLIGHTENQUIRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <ScrollText.h>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_FlightEnquires
{
public:
    QWidget *flightQueryWidget;
    QWidget *passengersWidget;
    QTableWidget *orgDepTableWidget;
    QTableWidget *boardingTableWidget;
    QTableWidget *notboardingTableWidget;
    QWidget *inputWidget;
    QPushButton *queryPushButton;
    QWidget *queryLineWidget;
    QLineEdit *queryLineEdit;
    QWidget *tabWidget;
    QPushButton *orgDepPushButton;
    QPushButton *boardingPushButton;
    QPushButton *notboardingPushButton;
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
    QWidget *filterWidget;
    QWidget *filterLineWidget;
    QLineEdit *filterLineEdit;
    QPushButton *filterPushButton;

    void setupUi(QWidget *FlightEnquires)
    {
        if (FlightEnquires->objectName().isEmpty())
            FlightEnquires->setObjectName(QString::fromUtf8("FlightEnquires"));
        FlightEnquires->resize(800, 978);
        FlightEnquires->setStyleSheet(QString::fromUtf8(""));
        flightQueryWidget = new QWidget(FlightEnquires);
        flightQueryWidget->setObjectName(QString::fromUtf8("flightQueryWidget"));
        flightQueryWidget->setGeometry(QRect(0, 0, 800, 978));
        flightQueryWidget->setFocusPolicy(Qt::NoFocus);
        flightQueryWidget->setStyleSheet(QString::fromUtf8("#flightQueryWidget{background-color: rgb(1, 65, 109);}"));
        passengersWidget = new QWidget(flightQueryWidget);
        passengersWidget->setObjectName(QString::fromUtf8("passengersWidget"));
        passengersWidget->setGeometry(QRect(15, 400, 770, 564));
        passengersWidget->setFocusPolicy(Qt::NoFocus);
        passengersWidget->setStyleSheet(QString::fromUtf8("#passengersWidget{image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/bg.png);}"));
        orgDepTableWidget = new QTableWidget(passengersWidget);
        orgDepTableWidget->setObjectName(QString::fromUtf8("orgDepTableWidget"));
        orgDepTableWidget->setGeometry(QRect(2, 2, 766, 560));
        orgDepTableWidget->setFocusPolicy(Qt::NoFocus);
        orgDepTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 65, 109);"));
        orgDepTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        orgDepTableWidget->horizontalHeader()->setVisible(false);
        boardingTableWidget = new QTableWidget(passengersWidget);
        boardingTableWidget->setObjectName(QString::fromUtf8("boardingTableWidget"));
        boardingTableWidget->setGeometry(QRect(2, 2, 766, 560));
        boardingTableWidget->setFocusPolicy(Qt::NoFocus);
        boardingTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 65, 109)"));
        boardingTableWidget->horizontalHeader()->setVisible(false);
        notboardingTableWidget = new QTableWidget(passengersWidget);
        notboardingTableWidget->setObjectName(QString::fromUtf8("notboardingTableWidget"));
        notboardingTableWidget->setGeometry(QRect(2, 2, 766, 560));
        notboardingTableWidget->setFocusPolicy(Qt::NoFocus);
        notboardingTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 65, 109)"));
        notboardingTableWidget->horizontalHeader()->setVisible(false);
        boardingTableWidget->raise();
        notboardingTableWidget->raise();
        orgDepTableWidget->raise();
        inputWidget = new QWidget(flightQueryWidget);
        inputWidget->setObjectName(QString::fromUtf8("inputWidget"));
        inputWidget->setGeometry(QRect(0, 7, 800, 40));
        inputWidget->setFocusPolicy(Qt::NoFocus);
        inputWidget->setStyleSheet(QString::fromUtf8(""));
        queryPushButton = new QPushButton(inputWidget);
        queryPushButton->setObjectName(QString::fromUtf8("queryPushButton"));
        queryPushButton->setGeometry(QRect(660, 0, 122, 40));
        queryPushButton->setFocusPolicy(Qt::NoFocus);
        queryPushButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/\346\237\245\350\257\242.png);}\n"
"QPushButton:pressed{border-image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/\346\237\245\350\257\242-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        queryLineWidget = new QWidget(inputWidget);
        queryLineWidget->setObjectName(QString::fromUtf8("queryLineWidget"));
        queryLineWidget->setGeometry(QRect(188, 0, 363, 40));
        queryLineWidget->setFocusPolicy(Qt::NoFocus);
        queryLineWidget->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: rgb(63, 95, 120);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        queryLineEdit = new QLineEdit(queryLineWidget);
        queryLineEdit->setObjectName(QString::fromUtf8("queryLineEdit"));
        queryLineEdit->setGeometry(QRect(0, 0, 355, 38));
        QFont font;
        font.setPointSize(20);
        queryLineEdit->setFont(font);
        queryLineEdit->setFocusPolicy(Qt::StrongFocus);
        queryLineEdit->setInputMethodHints(Qt::ImhPreferUppercase);
        queryLineEdit->setMaxLength(18);
        queryLineEdit->setAlignment(Qt::AlignCenter);
        tabWidget = new QWidget(flightQueryWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(15, 361, 770, 39));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setStyleSheet(QString::fromUtf8("#abWidget{background-color: rgb(1, 65, 109);}"));
        orgDepPushButton = new QPushButton(tabWidget);
        orgDepPushButton->setObjectName(QString::fromUtf8("orgDepPushButton"));
        orgDepPushButton->setGeometry(QRect(2, 0, 250, 39));
        QFont font1;
        font1.setPointSize(18);
        orgDepPushButton->setFont(font1);
        orgDepPushButton->setFocusPolicy(Qt::NoFocus);
        orgDepPushButton->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: 0;\n"
"border-radius: 4;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(88, 129, 157);"));
        boardingPushButton = new QPushButton(tabWidget);
        boardingPushButton->setObjectName(QString::fromUtf8("boardingPushButton"));
        boardingPushButton->setGeometry(QRect(260, 0, 250, 39));
        boardingPushButton->setFont(font1);
        boardingPushButton->setFocusPolicy(Qt::NoFocus);
        boardingPushButton->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: 0;\n"
"border-radius: 4;\n"
"color: rgb(0, 228, 255);\n"
"background-color: rgb(0, 36, 60);"));
        notboardingPushButton = new QPushButton(tabWidget);
        notboardingPushButton->setObjectName(QString::fromUtf8("notboardingPushButton"));
        notboardingPushButton->setGeometry(QRect(518, 0, 250, 39));
        notboardingPushButton->setFont(font1);
        notboardingPushButton->setFocusPolicy(Qt::NoFocus);
        notboardingPushButton->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: 0;\n"
"border-radius: 4;\n"
"color: rgb(0, 228, 255);\n"
"background-color: rgb(0, 36, 60);"));
        widget_flight = new QWidget(flightQueryWidget);
        widget_flight->setObjectName(QString::fromUtf8("widget_flight"));
        widget_flight->setGeometry(QRect(15, 53, 770, 308));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(50);
        widget_flight->setFont(font2);
        widget_flight->setFocusPolicy(Qt::NoFocus);
        widget_flight->setStyleSheet(QString::fromUtf8("#widget_flight{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\350\210\252\347\217\255\345\217\267bg.png);}"));
        label_midPlace = new ScrollText_Horizontal(widget_flight);
        label_midPlace->setObjectName(QString::fromUtf8("label_midPlace"));
        label_midPlace->setGeometry(QRect(270, 208, 200, 31));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_midPlace->setFont(font3);
        label_midPlace->setFocusPolicy(Qt::NoFocus);
        label_midPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_midPlace->setTextFormat(Qt::AutoText);
        label_midPlace->setScaledContents(true);
        label_midPlace->setAlignment(Qt::AlignCenter);
        layoutWidget_1 = new QWidget(widget_flight);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(6, 1, 766, 142));
        layoutWidget_1->setFocusPolicy(Qt::NoFocus);
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_11->setContentsMargins(30, 0, 0, 0);
        label_picture_plane = new QLabel(layoutWidget_1);
        label_picture_plane->setObjectName(QString::fromUtf8("label_picture_plane"));
        label_picture_plane->setMinimumSize(QSize(155, 120));
        label_picture_plane->setMaximumSize(QSize(155, 110));
        label_picture_plane->setFocusPolicy(Qt::NoFocus);
        label_picture_plane->setStyleSheet(QString::fromUtf8("image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\347\237\242\351\207\217\345\211\252\345\275\261\351\243\236\346\234\272.png);"));

        horizontalLayout_11->addWidget(label_picture_plane);

        label_mainFlightNO_ = new QLabel(layoutWidget_1);
        label_mainFlightNO_->setObjectName(QString::fromUtf8("label_mainFlightNO_"));
        label_mainFlightNO_->setMinimumSize(QSize(580, 140));
        label_mainFlightNO_->setMaximumSize(QSize(580, 140));
        QFont font4;
        font4.setPointSize(90);
        font4.setBold(true);
        font4.setWeight(75);
        label_mainFlightNO_->setFont(font4);
        label_mainFlightNO_->setFocusPolicy(Qt::NoFocus);
        label_mainFlightNO_->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));

        horizontalLayout_11->addWidget(label_mainFlightNO_);

        layoutWidget_2 = new QWidget(widget_flight);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 221, 751, 71));
        layoutWidget_2->setFocusPolicy(Qt::NoFocus);
        horizontalLayout_22 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_22->setSpacing(10);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(20, 0, 0, 0);
        label_fromPlace = new ScrollText_Horizontal(layoutWidget_2);
        label_fromPlace->setObjectName(QString::fromUtf8("label_fromPlace"));
        label_fromPlace->setMinimumSize(QSize(220, 0));
        label_fromPlace->setMaximumSize(QSize(220, 60));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu"));
        font5.setPointSize(40);
        font5.setBold(true);
        font5.setWeight(75);
        label_fromPlace->setFont(font5);
        label_fromPlace->setFocusPolicy(Qt::NoFocus);
        label_fromPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_fromPlace->setScaledContents(true);
        label_fromPlace->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_fromPlace);

        label_picture_pointTo = new QLabel(layoutWidget_2);
        label_picture_pointTo->setObjectName(QString::fromUtf8("label_picture_pointTo"));
        label_picture_pointTo->setMinimumSize(QSize(237, 21));
        label_picture_pointTo->setMaximumSize(QSize(237, 21));
        label_picture_pointTo->setFocusPolicy(Qt::NoFocus);
        label_picture_pointTo->setStyleSheet(QString::fromUtf8("image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.0-3.2/\345\275\242\347\212\266-2.png);"));

        horizontalLayout_22->addWidget(label_picture_pointTo);

        label_arrivalPlace = new ScrollText_Horizontal(layoutWidget_2);
        label_arrivalPlace->setObjectName(QString::fromUtf8("label_arrivalPlace"));
        label_arrivalPlace->setMinimumSize(QSize(220, 60));
        label_arrivalPlace->setMaximumSize(QSize(250, 60));
        label_arrivalPlace->setFont(font5);
        label_arrivalPlace->setFocusPolicy(Qt::NoFocus);
        label_arrivalPlace->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_arrivalPlace->setScaledContents(true);
        label_arrivalPlace->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_arrivalPlace);

        widget_3 = new QWidget(widget_flight);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(200, 140, 371, 61));
        widget_3->setFocusPolicy(Qt::NoFocus);
        horizontalLayout_33 = new QHBoxLayout(widget_3);
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(-1, 0, -1, 0);
        label_text_shareFlight = new QLabel(widget_3);
        label_text_shareFlight->setObjectName(QString::fromUtf8("label_text_shareFlight"));
        QFont font6;
        font6.setPointSize(26);
        label_text_shareFlight->setFont(font6);
        label_text_shareFlight->setFocusPolicy(Qt::NoFocus);
        label_text_shareFlight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_text_shareFlight->setTextFormat(Qt::RichText);

        horizontalLayout_33->addWidget(label_text_shareFlight);

        ScrollText_shareFlight = new ScrollText_Vertical(widget_3);
        ScrollText_shareFlight->setObjectName(QString::fromUtf8("ScrollText_shareFlight"));
        ScrollText_shareFlight->setMaximumSize(QSize(16777215, 16777215));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu"));
        font7.setPointSize(26);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        ScrollText_shareFlight->setFont(font7);
        ScrollText_shareFlight->setFocusPolicy(Qt::NoFocus);
        ScrollText_shareFlight->setStyleSheet(QString::fromUtf8("color: #0fff7a;\n"
"font: bold 26pt \"Ubuntu\";"));

        horizontalLayout_33->addWidget(ScrollText_shareFlight);

        filterWidget = new QWidget(flightQueryWidget);
        filterWidget->setObjectName(QString::fromUtf8("filterWidget"));
        filterWidget->setGeometry(QRect(15, 361, 770, 39));
        filterLineWidget = new QWidget(filterWidget);
        filterLineWidget->setObjectName(QString::fromUtf8("filterLineWidget"));
        filterLineWidget->setGeometry(QRect(2, 0, 666, 39));
        filterLineWidget->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: rgb(63, 95, 120);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        filterLineEdit = new QLineEdit(filterLineWidget);
        filterLineEdit->setObjectName(QString::fromUtf8("filterLineEdit"));
        filterLineEdit->setGeometry(QRect(4, 0, 658, 39));
        filterLineEdit->setFont(font1);
        filterPushButton = new QPushButton(filterWidget);
        filterPushButton->setObjectName(QString::fromUtf8("filterPushButton"));
        filterPushButton->setGeometry(QRect(677, 0, 91, 39));
        filterPushButton->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: 0;\n"
"border-image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/\350\277\207\346\273\244.png);"));
        passengersWidget->raise();
        inputWidget->raise();
        widget_flight->raise();
        filterWidget->raise();
        tabWidget->raise();

        retranslateUi(FlightEnquires);

        QMetaObject::connectSlotsByName(FlightEnquires);
    } // setupUi

    void retranslateUi(QWidget *FlightEnquires)
    {
        FlightEnquires->setWindowTitle(QApplication::translate("FlightEnquires", "\350\210\252\347\217\255\345\233\236\346\237\245", nullptr));
        queryPushButton->setText(QString());
        queryLineEdit->setPlaceholderText(QApplication::translate("FlightEnquires", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267", nullptr));
        orgDepPushButton->setText(QApplication::translate("FlightEnquires", "\345\273\272\345\272\223\344\272\272\346\225\260\357\274\2320", nullptr));
        boardingPushButton->setText(QApplication::translate("FlightEnquires", "\345\267\262\347\231\273\346\234\272\344\272\272\346\225\260\357\274\2320", nullptr));
        notboardingPushButton->setText(QApplication::translate("FlightEnquires", "\346\234\252\347\231\273\346\234\272\344\272\272\346\225\260\357\274\2320", nullptr));
        label_midPlace->setText(QString());
        label_picture_plane->setText(QString());
        label_mainFlightNO_->setText(QApplication::translate("FlightEnquires", "- - - - - -", nullptr));
        label_fromPlace->setText(QApplication::translate("FlightEnquires", "- - - -", nullptr));
        label_picture_pointTo->setText(QString());
        label_arrivalPlace->setText(QApplication::translate("FlightEnquires", "- - - -", nullptr));
        label_text_shareFlight->setText(QApplication::translate("FlightEnquires", "\345\205\261\344\272\253\350\210\252\347\217\255\357\274\232\n"
"", nullptr));
        filterLineEdit->setPlaceholderText(QApplication::translate("FlightEnquires", "\350\257\267\350\276\223\345\205\245\346\227\205\345\256\242\345\272\217\345\210\227\345\217\267", nullptr));
        filterPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FlightEnquires: public Ui_FlightEnquires {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTENQUIRES_H
