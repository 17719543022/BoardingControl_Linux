/********************************************************************************
** Form generated from reading UI file 'workflowrecording.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKFLOWRECORDING_H
#define UI_WORKFLOWRECORDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkflowRecording
{
public:
    QWidget *allWidget;
    QWidget *flowQueryWidget;
    QWidget *flowqueryWidget;
    QPushButton *flowQueryPushButton;
    QWidget *flowQueryLineWidget;
    QLineEdit *flowQueryLineEdit;
    QWidget *userInfoWidget;
    QLabel *passengerNameLabel_1;
    QLabel *passengerCodeLabel_1;
    QLabel *passengerFlightLabel_1;
    QLabel *boardingNumberLabel_1;
    QLabel *passengerNameLabel_2;
    QLabel *passengerCodeLabel_2;
    QLabel *boardingNumberLabel_2;
    QLabel *passengerFlightLabel_2;
    QLabel *seatIdLabel_2;
    QLabel *seatIdLabel_1;
    QLabel *gateNoLabel_1;
    QLabel *gateNoLabel_2;
    QTableWidget *flowTableWidget;

    void setupUi(QWidget *WorkflowRecording)
    {
        if (WorkflowRecording->objectName().isEmpty())
            WorkflowRecording->setObjectName(QString::fromUtf8("WorkflowRecording"));
        WorkflowRecording->resize(800, 978);
        QFont font;
        font.setPointSize(15);
        WorkflowRecording->setFont(font);
        WorkflowRecording->setStyleSheet(QString::fromUtf8(""));
        allWidget = new QWidget(WorkflowRecording);
        allWidget->setObjectName(QString::fromUtf8("allWidget"));
        allWidget->setGeometry(QRect(0, 0, 800, 978));
        allWidget->setFocusPolicy(Qt::NoFocus);
        allWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 65, 109);"));
        flowQueryWidget = new QWidget(allWidget);
        flowQueryWidget->setObjectName(QString::fromUtf8("flowQueryWidget"));
        flowQueryWidget->setGeometry(QRect(15, 15, 770, 978));
        flowQueryWidget->setFocusPolicy(Qt::NoFocus);
        flowQueryWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/4\345\205\250\346\265\201\347\250\213\350\256\260\345\275\225/Images/4\345\205\250\346\265\201\347\250\213\350\256\260\345\275\225/bg.png);"));
        flowqueryWidget = new QWidget(flowQueryWidget);
        flowqueryWidget->setObjectName(QString::fromUtf8("flowqueryWidget"));
        flowqueryWidget->setGeometry(QRect(0, 0, 770, 92));
        flowqueryWidget->setFocusPolicy(Qt::NoFocus);
        flowqueryWidget->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: 0;"));
        flowQueryPushButton = new QPushButton(flowqueryWidget);
        flowQueryPushButton->setObjectName(QString::fromUtf8("flowQueryPushButton"));
        flowQueryPushButton->setGeometry(QRect(588, 30, 122, 40));
        flowQueryPushButton->setFocusPolicy(Qt::NoFocus);
        flowQueryPushButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/\346\237\245\350\257\242.png);}\n"
"QPushButton:pressed{border-image: url(:/6\350\210\252\347\217\255\345\233\236\346\237\245/Images/6\350\210\252\347\217\255\345\233\236\346\237\245/\346\237\245\350\257\242-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        flowQueryLineWidget = new QWidget(flowqueryWidget);
        flowQueryLineWidget->setObjectName(QString::fromUtf8("flowQueryLineWidget"));
        flowQueryLineWidget->setGeometry(QRect(150, 30, 359, 40));
        flowQueryLineWidget->setFocusPolicy(Qt::NoFocus);
        flowQueryLineWidget->setStyleSheet(QString::fromUtf8("border: 0;\n"
"image: 0;\n"
"background: rgb(63, 95, 120);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        flowQueryLineEdit = new QLineEdit(flowQueryLineWidget);
        flowQueryLineEdit->setObjectName(QString::fromUtf8("flowQueryLineEdit"));
        flowQueryLineEdit->setGeometry(QRect(4, 1, 351, 38));
        QFont font1;
        font1.setPointSize(18);
        flowQueryLineEdit->setFont(font1);
        flowQueryLineEdit->setFocusPolicy(Qt::StrongFocus);
        flowQueryLineEdit->setInputMethodHints(Qt::ImhPreferUppercase);
        flowQueryLineEdit->setMaxLength(18);
        userInfoWidget = new QWidget(flowQueryWidget);
        userInfoWidget->setObjectName(QString::fromUtf8("userInfoWidget"));
        userInfoWidget->setGeometry(QRect(0, 107, 770, 158));
        userInfoWidget->setFocusPolicy(Qt::NoFocus);
        userInfoWidget->setStyleSheet(QString::fromUtf8("image: 0;\n"
"border: 0;\n"
"background: 0;"));
        passengerNameLabel_1 = new QLabel(userInfoWidget);
        passengerNameLabel_1->setObjectName(QString::fromUtf8("passengerNameLabel_1"));
        passengerNameLabel_1->setGeometry(QRect(35, 0, 120, 38));
        QFont font2;
        font2.setPointSize(19);
        passengerNameLabel_1->setFont(font2);
        passengerNameLabel_1->setFocusPolicy(Qt::NoFocus);
        passengerNameLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerCodeLabel_1 = new QLabel(userInfoWidget);
        passengerCodeLabel_1->setObjectName(QString::fromUtf8("passengerCodeLabel_1"));
        passengerCodeLabel_1->setGeometry(QRect(35, 60, 101, 38));
        passengerCodeLabel_1->setFont(font2);
        passengerCodeLabel_1->setFocusPolicy(Qt::NoFocus);
        passengerCodeLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerCodeLabel_1->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        passengerFlightLabel_1 = new QLabel(userInfoWidget);
        passengerFlightLabel_1->setObjectName(QString::fromUtf8("passengerFlightLabel_1"));
        passengerFlightLabel_1->setGeometry(QRect(35, 120, 101, 38));
        passengerFlightLabel_1->setFont(font2);
        passengerFlightLabel_1->setFocusPolicy(Qt::NoFocus);
        passengerFlightLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        passengerFlightLabel_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        boardingNumberLabel_1 = new QLabel(userInfoWidget);
        boardingNumberLabel_1->setObjectName(QString::fromUtf8("boardingNumberLabel_1"));
        boardingNumberLabel_1->setGeometry(QRect(330, 120, 71, 38));
        boardingNumberLabel_1->setFont(font2);
        boardingNumberLabel_1->setFocusPolicy(Qt::NoFocus);
        boardingNumberLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        boardingNumberLabel_1->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        passengerNameLabel_2 = new QLabel(userInfoWidget);
        passengerNameLabel_2->setObjectName(QString::fromUtf8("passengerNameLabel_2"));
        passengerNameLabel_2->setGeometry(QRect(160, 0, 161, 38));
        QFont font3;
        font3.setPointSize(19);
        font3.setBold(true);
        font3.setWeight(75);
        passengerNameLabel_2->setFont(font3);
        passengerNameLabel_2->setFocusPolicy(Qt::NoFocus);
        passengerNameLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        passengerCodeLabel_2 = new QLabel(userInfoWidget);
        passengerCodeLabel_2->setObjectName(QString::fromUtf8("passengerCodeLabel_2"));
        passengerCodeLabel_2->setGeometry(QRect(140, 60, 350, 38));
        passengerCodeLabel_2->setFont(font3);
        passengerCodeLabel_2->setFocusPolicy(Qt::NoFocus);
        passengerCodeLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        boardingNumberLabel_2 = new QLabel(userInfoWidget);
        boardingNumberLabel_2->setObjectName(QString::fromUtf8("boardingNumberLabel_2"));
        boardingNumberLabel_2->setGeometry(QRect(405, 120, 125, 38));
        boardingNumberLabel_2->setFont(font3);
        boardingNumberLabel_2->setFocusPolicy(Qt::NoFocus);
        boardingNumberLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        passengerFlightLabel_2 = new QLabel(userInfoWidget);
        passengerFlightLabel_2->setObjectName(QString::fromUtf8("passengerFlightLabel_2"));
        passengerFlightLabel_2->setGeometry(QRect(140, 120, 181, 38));
        passengerFlightLabel_2->setFont(font3);
        passengerFlightLabel_2->setFocusPolicy(Qt::NoFocus);
        passengerFlightLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        seatIdLabel_2 = new QLabel(userInfoWidget);
        seatIdLabel_2->setObjectName(QString::fromUtf8("seatIdLabel_2"));
        seatIdLabel_2->setGeometry(QRect(640, 120, 121, 38));
        seatIdLabel_2->setFont(font3);
        seatIdLabel_2->setFocusPolicy(Qt::NoFocus);
        seatIdLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        seatIdLabel_1 = new QLabel(userInfoWidget);
        seatIdLabel_1->setObjectName(QString::fromUtf8("seatIdLabel_1"));
        seatIdLabel_1->setGeometry(QRect(540, 120, 95, 38));
        seatIdLabel_1->setFont(font2);
        seatIdLabel_1->setFocusPolicy(Qt::NoFocus);
        seatIdLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        seatIdLabel_1->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        gateNoLabel_1 = new QLabel(userInfoWidget);
        gateNoLabel_1->setObjectName(QString::fromUtf8("gateNoLabel_1"));
        gateNoLabel_1->setGeometry(QRect(330, 0, 121, 38));
        gateNoLabel_1->setFont(font2);
        gateNoLabel_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gateNoLabel_2 = new QLabel(userInfoWidget);
        gateNoLabel_2->setObjectName(QString::fromUtf8("gateNoLabel_2"));
        gateNoLabel_2->setGeometry(QRect(454, 0, 301, 38));
        gateNoLabel_2->setFont(font3);
        gateNoLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 228, 255);"));
        flowTableWidget = new QTableWidget(flowQueryWidget);
        if (flowTableWidget->columnCount() < 1)
            flowTableWidget->setColumnCount(1);
        flowTableWidget->setObjectName(QString::fromUtf8("flowTableWidget"));
        flowTableWidget->setGeometry(QRect(2, 280, 766, 681));
        flowTableWidget->setFocusPolicy(Qt::NoFocus);
        flowTableWidget->setColumnCount(1);

        retranslateUi(WorkflowRecording);

        QMetaObject::connectSlotsByName(WorkflowRecording);
    } // setupUi

    void retranslateUi(QWidget *WorkflowRecording)
    {
        WorkflowRecording->setWindowTitle(QApplication::translate("WorkflowRecording", "\345\205\250\346\265\201\347\250\213\350\256\260\345\275\225", nullptr));
        flowQueryPushButton->setText(QString());
        flowQueryLineEdit->setText(QString());
        flowQueryLineEdit->setPlaceholderText(QApplication::translate("WorkflowRecording", "\350\257\267\350\276\223\345\205\245\350\257\201\344\273\266\345\217\267\346\210\226\350\210\252\347\217\255\345\217\267#\345\272\217\345\217\267", nullptr));
        passengerNameLabel_1->setText(QApplication::translate("WorkflowRecording", "\346\227\205\345\256\242\345\247\223\345\220\215\357\274\232", nullptr));
        passengerCodeLabel_1->setText(QApplication::translate("WorkflowRecording", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        passengerFlightLabel_1->setText(QApplication::translate("WorkflowRecording", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        boardingNumberLabel_1->setText(QApplication::translate("WorkflowRecording", "\345\272\217\345\217\267\357\274\232", nullptr));
        passengerNameLabel_2->setText(QString());
        passengerCodeLabel_2->setText(QString());
        boardingNumberLabel_2->setText(QString());
        passengerFlightLabel_2->setText(QString());
        seatIdLabel_2->setText(QString());
        seatIdLabel_1->setText(QApplication::translate("WorkflowRecording", "\345\272\247\344\275\215\345\217\267\357\274\232", nullptr));
        gateNoLabel_1->setText(QApplication::translate("WorkflowRecording", "\347\231\273\346\234\272\345\217\243\345\217\267\357\274\232", nullptr));
        gateNoLabel_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WorkflowRecording: public Ui_WorkflowRecording {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKFLOWRECORDING_H
