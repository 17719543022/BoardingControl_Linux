#ifndef SERIALPORTSER_H
#define SERIALPORTSER_H

#include "paramdef.h"
#include "settings.h"
#include <QObject>
#include <QMutex>
#include <QtSerialPort>

enum SerialPort_ID{
    TicketScanner = 0,
    DepartureInfoSender
};

class QSerialPort;
class QTimer;
class SerialPortSer : public QObject
{
    Q_OBJECT
public:
    virtual ~SerialPortSer();
    static SerialPortSer* instance(SerialPort_ID id);
    static int instance_count;

public:
    int Init();
    int UnInit();

    inline bool is_sendDepartureOk(){
        return m_sendDepaturResult;
    }
    inline QString getInstanceName(){
        return m_instanceName;
    }
signals:
    void readBoardingTicketResult(const BoardingTicketInfo& btInfo);
    void spStat(bool stat);
    void sendDepartureInfoResult();

public slots:
    void sendDepartureInfo(BoardingTicketInfo TicketInfo);

private slots:
    void testOnline();
    void readBoardingTicket();

private:
    explicit SerialPortSer(SerialPort_ID id, QObject *parent = nullptr);

private:
    QTimer *m_testTimer{nullptr};

    QMutex m_mutex;
    QString m_instanceName;

    QMetaObject::Connection m_readConnection;
    QMetaObject::Connection m_timerConnection;

    QSerialPort *m_sp{nullptr};
    bool m_isOpen;

    QString m_portName;
    int m_baudRate{115200};

    bool m_sendDepaturResult{false};
}; 

//Q_DECLARE_METATYPE(BoardingTicketInfo)

#endif // SERIALPORTSER_H
