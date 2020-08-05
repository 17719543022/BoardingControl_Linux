/********************************************************************************
** Form generated from reading UI file 'inquiryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRYWIDGET_H
#define UI_INQUIRYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ScrollText.h"

QT_BEGIN_NAMESPACE

class Ui_inquiryWidget
{
public:
    QWidget *widget_inquiry;
    QPushButton *pushButton_enquiry;
    QLineEdit *lineEdit_enquiry;
    QPushButton *pushButton_return;
    QWidget *widget_choice_channel;
    QLabel *label_16;
    QPushButton *pushButton_cancelPass;
    QPushButton *pushButton_specialPassenger;
    QPushButton *pushButton_channel_1;
    QPushButton *pushButton_channel_2;
    QWidget *widget_pass_or_prevent;
    QWidget *layoutWidget;
    QGridLayout *Layout_result;
    QWidget *layoutWidget_1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_pass;
    QPushButton *pushButton_prevent;
    QWidget *widget_choice_ppl;
    QPushButton *pushButton_choice_ppl_commit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_selectPPL;
    QWidget *widget_pssngrInfo;
    QLabel *label_4;
    QLabel *label_idNo_;
    QLabel *label_seatNo_;
    QLabel *label_boardingGateNo_;
    QLabel *label_3;
    ScrollText_Horizontal *label_name;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_orderNo_;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_flightNo_;

    void setupUi(QWidget *inquiryWidget)
    {
        if (inquiryWidget->objectName().isEmpty())
            inquiryWidget->setObjectName(QString::fromUtf8("inquiryWidget"));
        inquiryWidget->resize(800, 505);
        widget_inquiry = new QWidget(inquiryWidget);
        widget_inquiry->setObjectName(QString::fromUtf8("widget_inquiry"));
        widget_inquiry->setGeometry(QRect(15, 15, 770, 475));
        widget_inquiry->setStyleSheet(QString::fromUtf8("#widget_inquiry{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\227\205\345\256\242\350\257\246\346\203\205\345\274\271\347\252\227.png);}"));
        pushButton_enquiry = new QPushButton(widget_inquiry);
        pushButton_enquiry->setObjectName(QString::fromUtf8("pushButton_enquiry"));
        pushButton_enquiry->setGeometry(QRect(330, 20, 90, 38));
        pushButton_enquiry->setFocusPolicy(Qt::NoFocus);
        pushButton_enquiry->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\237\245\350\257\2422.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\237\245\350\257\242-2-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        lineEdit_enquiry = new QLineEdit(widget_inquiry);
        lineEdit_enquiry->setObjectName(QString::fromUtf8("lineEdit_enquiry"));
        lineEdit_enquiry->setGeometry(QRect(20, 20, 300, 38));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lineEdit_enquiry->setFont(font);
        lineEdit_enquiry->setFocusPolicy(Qt::StrongFocus);
        lineEdit_enquiry->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\347\237\251\345\275\242-4363.png);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"font: 16pt;\n"
"}"));
        lineEdit_enquiry->setInputMethodHints(Qt::ImhPreferUppercase);
        lineEdit_enquiry->setMaxLength(18);
        pushButton_return = new QPushButton(widget_inquiry);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(700, 20, 30, 39));
        pushButton_return->setFocusPolicy(Qt::NoFocus);
        pushButton_return->setStyleSheet(QString::fromUtf8("QPushButton{border:none;}\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\350\277\224\345\233\2362.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_return->setIcon(icon);
        pushButton_return->setIconSize(QSize(30, 39));
        widget_choice_channel = new QWidget(widget_inquiry);
        widget_choice_channel->setObjectName(QString::fromUtf8("widget_choice_channel"));
        widget_choice_channel->setGeometry(QRect(0, 160, 770, 300));
        label_16 = new QLabel(widget_choice_channel);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(133, 85, 261, 53));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(false);
        label_16->setMargin(0);
        pushButton_cancelPass = new QPushButton(widget_choice_channel);
        pushButton_cancelPass->setObjectName(QString::fromUtf8("pushButton_cancelPass"));
        pushButton_cancelPass->setGeometry(QRect(680, 10, 39, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_cancelPass->sizePolicy().hasHeightForWidth());
        pushButton_cancelPass->setSizePolicy(sizePolicy);
        pushButton_cancelPass->setMinimumSize(QSize(29, 30));
        pushButton_cancelPass->setFocusPolicy(Qt::NoFocus);
        pushButton_cancelPass->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235.png);}\n"
"QPushButton:pressed{border-image: url(:/2\347\263\273\347\273\237\351\246\226\351\241\265/Images/2\347\263\273\347\273\237\351\246\226\351\241\265/\345\274\271\347\252\227/\345\205\263--\351\227\255-\346\213\267\350\264\235-\346\214\211\344\270\213.png);}"));
        pushButton_cancelPass->setIconSize(QSize(29, 30));
        pushButton_specialPassenger = new QPushButton(widget_choice_channel);
        pushButton_specialPassenger->setObjectName(QString::fromUtf8("pushButton_specialPassenger"));
        pushButton_specialPassenger->setGeometry(QRect(430, 90, 170, 54));
        sizePolicy.setHeightForWidth(pushButton_specialPassenger->sizePolicy().hasHeightForWidth());
        pushButton_specialPassenger->setSizePolicy(sizePolicy);
        pushButton_specialPassenger->setMinimumSize(QSize(138, 45));
        pushButton_specialPassenger->setFocusPolicy(Qt::NoFocus);
        pushButton_specialPassenger->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\347\211\271\346\256\212\346\227\205\345\256\242.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\347\211\271\346\256\212\346\227\205\345\256\242-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_specialPassenger->setIconSize(QSize(170, 54));
        pushButton_channel_1 = new QPushButton(widget_choice_channel);
        pushButton_channel_1->setObjectName(QString::fromUtf8("pushButton_channel_1"));
        pushButton_channel_1->setGeometry(QRect(130, 220, 170, 54));
        sizePolicy.setHeightForWidth(pushButton_channel_1->sizePolicy().hasHeightForWidth());
        pushButton_channel_1->setSizePolicy(sizePolicy);
        pushButton_channel_1->setMinimumSize(QSize(170, 54));
        pushButton_channel_1->setFocusPolicy(Qt::NoFocus);
        pushButton_channel_1->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/1\345\217\267\351\200\232\351\201\223.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/1\345\217\267\351\200\232\351\201\223-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_channel_1->setIconSize(QSize(170, 54));
        pushButton_channel_2 = new QPushButton(widget_choice_channel);
        pushButton_channel_2->setObjectName(QString::fromUtf8("pushButton_channel_2"));
        pushButton_channel_2->setGeometry(QRect(459, 220, 170, 54));
        sizePolicy.setHeightForWidth(pushButton_channel_2->sizePolicy().hasHeightForWidth());
        pushButton_channel_2->setSizePolicy(sizePolicy);
        pushButton_channel_2->setMinimumSize(QSize(170, 54));
        pushButton_channel_2->setFocusPolicy(Qt::NoFocus);
        pushButton_channel_2->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/2\345\217\267\351\200\232\351\201\223.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/2\345\217\267\351\200\232\351\201\223-\346\213\267\350\264\235.png);}\n"
""));
        pushButton_channel_2->setIconSize(QSize(170, 54));
        widget_pass_or_prevent = new QWidget(widget_inquiry);
        widget_pass_or_prevent->setObjectName(QString::fromUtf8("widget_pass_or_prevent"));
        widget_pass_or_prevent->setGeometry(QRect(0, 160, 770, 300));
        layoutWidget = new QWidget(widget_pass_or_prevent);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 0, 601, 291));
        Layout_result = new QGridLayout(layoutWidget);
        Layout_result->setObjectName(QString::fromUtf8("Layout_result"));
        Layout_result->setHorizontalSpacing(16);
        Layout_result->setVerticalSpacing(10);
        Layout_result->setContentsMargins(0, 0, 0, 0);
        layoutWidget_1 = new QWidget(widget_pass_or_prevent);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(660, 160, 101, 131));
        verticalLayout = new QVBoxLayout(layoutWidget_1);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_pass = new QPushButton(layoutWidget_1);
        pushButton_pass->setObjectName(QString::fromUtf8("pushButton_pass"));
        sizePolicy.setHeightForWidth(pushButton_pass->sizePolicy().hasHeightForWidth());
        pushButton_pass->setSizePolicy(sizePolicy);
        pushButton_pass->setMinimumSize(QSize(98, 47));
        pushButton_pass->setFocusPolicy(Qt::NoFocus);
        pushButton_pass->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\224\276---\350\241\214.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\224\276---\350\241\214-\346\213\267\350\264\235.png);}\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_pass);

        pushButton_prevent = new QPushButton(layoutWidget_1);
        pushButton_prevent->setObjectName(QString::fromUtf8("pushButton_prevent"));
        sizePolicy.setHeightForWidth(pushButton_prevent->sizePolicy().hasHeightForWidth());
        pushButton_prevent->setSizePolicy(sizePolicy);
        pushButton_prevent->setMinimumSize(QSize(98, 47));
        pushButton_prevent->setFocusPolicy(Qt::NoFocus);
        pushButton_prevent->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\213\246---\346\210\252.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/3.2.1/\346\213\246---\346\210\252-\346\213\267\350\264\235.png);}\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_prevent);

        widget_choice_ppl = new QWidget(widget_inquiry);
        widget_choice_ppl->setObjectName(QString::fromUtf8("widget_choice_ppl"));
        widget_choice_ppl->setGeometry(QRect(0, 110, 770, 380));
        pushButton_choice_ppl_commit = new QPushButton(widget_choice_ppl);
        pushButton_choice_ppl_commit->setObjectName(QString::fromUtf8("pushButton_choice_ppl_commit"));
        pushButton_choice_ppl_commit->setGeometry(QRect(240, 300, 276, 47));
        sizePolicy.setHeightForWidth(pushButton_choice_ppl_commit->sizePolicy().hasHeightForWidth());
        pushButton_choice_ppl_commit->setSizePolicy(sizePolicy);
        pushButton_choice_ppl_commit->setMinimumSize(QSize(276, 47));
        pushButton_choice_ppl_commit->setMaximumSize(QSize(276, 47));
        pushButton_choice_ppl_commit->setFocusPolicy(Qt::NoFocus);
        pushButton_choice_ppl_commit->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\346\217\220\344\272\244.png);}\n"
"QPushButton:pressed{border-image: url(:/3\345\256\236\346\227\266\347\231\273\346\234\272/Images/3\345\256\236\346\227\266\347\231\273\346\234\272/\345\274\271\347\252\227/\346\217\220\344\272\244-\346\213\267\350\264\235.png);}\n"
"\n"
""));
        horizontalLayoutWidget = new QWidget(widget_choice_ppl);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 9, 731, 281));
        layout_selectPPL = new QHBoxLayout(horizontalLayoutWidget);
        layout_selectPPL->setObjectName(QString::fromUtf8("layout_selectPPL"));
        layout_selectPPL->setContentsMargins(0, 0, 0, 0);
        widget_pssngrInfo = new QWidget(widget_inquiry);
        widget_pssngrInfo->setObjectName(QString::fromUtf8("widget_pssngrInfo"));
        widget_pssngrInfo->setGeometry(QRect(0, 70, 770, 100));
        label_4 = new QLabel(widget_pssngrInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 10, 90, 30));
        QFont font2;
        font2.setPointSize(14);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setWordWrap(false);
        label_4->setMargin(0);
        label_idNo_ = new QLabel(widget_pssngrInfo);
        label_idNo_->setObjectName(QString::fromUtf8("label_idNo_"));
        label_idNo_->setGeometry(QRect(350, 10, 220, 30));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label_idNo_->setFont(font3);
        label_idNo_->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_idNo_->setScaledContents(true);
        label_seatNo_ = new QLabel(widget_pssngrInfo);
        label_seatNo_->setObjectName(QString::fromUtf8("label_seatNo_"));
        label_seatNo_->setGeometry(QRect(660, 45, 100, 30));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_seatNo_->setFont(font4);
        label_seatNo_->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_seatNo_->setScaledContents(true);
        label_boardingGateNo_ = new QLabel(widget_pssngrInfo);
        label_boardingGateNo_->setObjectName(QString::fromUtf8("label_boardingGateNo_"));
        label_boardingGateNo_->setGeometry(QRect(660, 10, 100, 30));
        label_boardingGateNo_->setFont(font4);
        label_boardingGateNo_->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_boardingGateNo_->setScaledContents(true);
        label_3 = new QLabel(widget_pssngrInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 45, 90, 30));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setWordWrap(false);
        label_3->setMargin(0);
        label_name = new ScrollText_Horizontal(widget_pssngrInfo);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(110, 10, 150, 30));
        label_name->setFont(font4);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_name->setScaledContents(true);
        label_13 = new QLabel(widget_pssngrInfo);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 70, 730, 20));
        QFont font5;
        font5.setPointSize(6);
        label_13->setFont(font5);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 100, 150);"));
        label_5 = new QLabel(widget_pssngrInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 45, 90, 30));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setWordWrap(false);
        label_5->setMargin(0);
        label_6 = new QLabel(widget_pssngrInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(570, 45, 90, 30));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6->setWordWrap(false);
        label_6->setMargin(0);
        label_orderNo_ = new QLabel(widget_pssngrInfo);
        label_orderNo_->setObjectName(QString::fromUtf8("label_orderNo_"));
        label_orderNo_->setGeometry(QRect(350, 45, 220, 30));
        label_orderNo_->setFont(font4);
        label_orderNo_->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_orderNo_->setScaledContents(true);
        label_7 = new QLabel(widget_pssngrInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 90, 30));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7->setScaledContents(false);
        label_7->setWordWrap(false);
        label_7->setMargin(0);
        label_8 = new QLabel(widget_pssngrInfo);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(570, 10, 90, 30));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8->setWordWrap(false);
        label_8->setMargin(0);
        label_flightNo_ = new QLabel(widget_pssngrInfo);
        label_flightNo_->setObjectName(QString::fromUtf8("label_flightNo_"));
        label_flightNo_->setGeometry(QRect(110, 45, 150, 30));
        label_flightNo_->setFont(font4);
        label_flightNo_->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 246);"));
        label_flightNo_->setScaledContents(true);
        widget_pssngrInfo->raise();
        pushButton_enquiry->raise();
        lineEdit_enquiry->raise();
        pushButton_return->raise();
        widget_pass_or_prevent->raise();
        widget_choice_channel->raise();
        widget_choice_ppl->raise();
        QWidget::setTabOrder(pushButton_cancelPass, pushButton_return);
        QWidget::setTabOrder(pushButton_return, pushButton_enquiry);
        QWidget::setTabOrder(pushButton_enquiry, lineEdit_enquiry);
        QWidget::setTabOrder(lineEdit_enquiry, pushButton_specialPassenger);
        QWidget::setTabOrder(pushButton_specialPassenger, pushButton_channel_1);
        QWidget::setTabOrder(pushButton_channel_1, pushButton_channel_2);
        QWidget::setTabOrder(pushButton_channel_2, pushButton_prevent);

        retranslateUi(inquiryWidget);

        QMetaObject::connectSlotsByName(inquiryWidget);
    } // setupUi

    void retranslateUi(QWidget *inquiryWidget)
    {
        inquiryWidget->setWindowTitle(QApplication::translate("inquiryWidget", "Form", nullptr));
        pushButton_enquiry->setText(QString());
        lineEdit_enquiry->setInputMask(QString());
        lineEdit_enquiry->setText(QString());
        lineEdit_enquiry->setPlaceholderText(QApplication::translate("inquiryWidget", "\350\257\267\350\276\223\345\205\245\350\257\201\344\273\266\345\217\267 \346\210\226 \350\210\252\347\217\255\345\217\267#\345\272\217\345\217\267", nullptr));
        pushButton_return->setText(QString());
        label_16->setText(QApplication::translate("inquiryWidget", "\350\257\267\351\200\211\346\213\251\351\200\232\351\201\223\357\274\232", nullptr));
        pushButton_cancelPass->setText(QString());
        pushButton_specialPassenger->setText(QString());
        pushButton_channel_1->setText(QString());
        pushButton_channel_2->setText(QString());
        pushButton_pass->setText(QString());
        pushButton_prevent->setText(QString());
        pushButton_choice_ppl_commit->setText(QString());
        label_4->setText(QApplication::translate("inquiryWidget", "\350\257\201  \344\273\266  \345\217\267\357\274\232", nullptr));
        label_idNo_->setText(QString());
        label_seatNo_->setText(QString());
        label_boardingGateNo_->setText(QString());
        label_3->setText(QApplication::translate("inquiryWidget", "\350\210\252  \347\217\255  \345\217\267\357\274\232", nullptr));
        label_name->setText(QString());
        label_13->setText(QApplication::translate("inquiryWidget", "\342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224 \342\200\224", nullptr));
        label_5->setText(QApplication::translate("inquiryWidget", "\345\272\217        \345\217\267\357\274\232", nullptr));
        label_6->setText(QApplication::translate("inquiryWidget", "\345\272\247  \344\275\215  \345\217\267\357\274\232", nullptr));
        label_orderNo_->setText(QString());
        label_7->setText(QApplication::translate("inquiryWidget", "\346\227\205\345\256\242\345\247\223\345\220\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("inquiryWidget", "\347\231\273  \346\234\272  \345\217\243\357\274\232", nullptr));
        label_flightNo_->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inquiryWidget: public Ui_inquiryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRYWIDGET_H
