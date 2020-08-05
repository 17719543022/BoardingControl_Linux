#-------------------------------------------------
#
# Project created by QtCreator 2019-12-19T11:29:47
#
#-------------------------------------------------

QT += core gui
QT += serialport
QT += network
QT+= multimedia
CONFIG+=C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BoardingControl_Linux
TEMPLATE = app

SOURCES += main.cpp\
    ServerInterface/IDCardRead_Recog.cpp \
    UI_Classes/flightenquires.cpp \
    UI_Classes/photoButton.cpp \
    UI_Classes/portraitcollection.cpp \
    UI_Classes/realtimeboarding.cpp \
    UI_Classes/workflowrecording.cpp \
    homepage.cpp \
    LogTrace/loghandler.cpp \
    myeventfilter.cpp \
    rabbitmq_c/amqpImp.cpp \
    rabbitmq_c/amqpmanager.cpp \
    rabbitmq_c/utils.cpp \
    rabbitmq_c/amqp_time.cpp \
    settings.cpp \
    ServerInterface/httpAPI.cpp \
    ServerInterface/mqmsg_parse.cpp \
    logindialog.cpp \
    ticketScancer/serialportser.cpp \
    translationwidget.cpp \
    UI_Classes/messagedialog.cpp \
    ServerInterface/workanotherthread.cpp \
    ScrollText.cpp \
    ServerInterface/httpServer.cpp \
    UI_Classes/inquiryWidget.cpp \
    UI_Classes/lineEditDialog.cpp

HEADERS  += \
    ServerInterface/IDCardRead_Recog.h \
    UI_Classes/UI_include_all.h \
    UI_Classes/flightenquires.h \
    UI_Classes/photoButton.h \
    UI_Classes/portraitcollection.h \
    UI_Classes/realtimeboarding.h \
    UI_Classes/workflowrecording.h \
    homepage.h \
    LogTrace/loghandler.h \
    LogTrace/singleton.h \
    myeventfilter.h \
    rabbitmq_c/amqpImp.h \
    rabbitmq_c/amqpmanager.h \
    rabbitmq_c/utils.h \
    rabbitmq_c/amqp_time.h \
    settings.h \
    ServerInterface/api_param_def.h \
    ServerInterface/httpAPI.h \
    ServerInterface/mqmsg_parse.h \
    logindialog.h \
    ticketScancer/paramdef.h \
    ticketScancer/serialportser.h \
    translationwidget.h \
    UI_Classes/messagedialog.h \
    ServerInterface/workanotherthread.h \
    ScrollText.h \
    ServerInterface/httpServer.h \
    UI_Classes/inquiryWidget.h \
    UI_Classes/lineEditDialog.h

FORMS    += \
    UI_Classes/photoButton.ui \
    UI_Classes/workflowrecording.ui \
    UI_Classes/realtimeboarding.ui \
    UI_Classes/portraitcollection.ui \
    UI_Classes/flightenquires.ui \
    homepage.ui \
    logindialog.ui \
    UI_Classes/messagedialog.ui \
    UI_Classes/inquiryWidget.ui \
    UI_Classes/lineEditDialog.ui

RESOURCES += \
    bordingcontrol_linux.qrc

INCLUDEPATH += $$PWD/../SDK/include
DEPENDPATH += $$PWD/../SDK/include

LIBS += -L$$PWD/../SDK/bin -lrabbitmq -lHTTP -lHTTPServer -ljsoncpp -lPocoNet -lPocoFoundation -lIDCardRead_RecogSDK \
                            -Wl,--no-as-needed -lPcscTiny -lwlt -Wl,--as-needed


QMAKE_LFLAGS += -Wl,-rpath=\'\$\$ORIGIN:\$\$ORIGIN/../SDK/bin\':\'\$\$ORIGIN:\$\$ORIGIN/lib\'
