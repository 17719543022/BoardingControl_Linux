#include "serialportser.h"
#include "settings.h"
#include <QDate>
#include <QDateTime>
#include <QThread>
#include <QTimer>
#include <QDebug>


int SerialPortSer::instance_count = 0;

SerialPortSer* SerialPortSer::instance(SerialPort_ID id)
{
    SerialPortSer *p = nullptr;

    switch (id) {
    case TicketScanner:
    {
        static SerialPortSer singleton(id);
        p = &singleton;
    }
        break;
    case DepartureInfoSender:
    {
        static SerialPortSer singleton(id);
        p = &singleton;
    }
        break;
    }
    return p;
}

SerialPortSer::SerialPortSer(SerialPort_ID id, QObject *parent) : QObject(parent)
{
    switch (id) {
    case TicketScanner:
    {
        m_instanceName = "ReadTicketInfo";
        m_portName = LocalSettings::instance()->value(QString("SerialPort_%1/port").arg(m_instanceName), QString("ttyUSB%1").arg(static_cast<int>(id))).toString();
        m_baudRate = LocalSettings::instance()->value(QString("SerialPort_%1/baudRate").arg(m_instanceName), QSerialPort::Baud115200).toInt();
    }
        break;
    case DepartureInfoSender:
    {
        m_instanceName = "SendDepartureInfo";
        m_portName = LocalSettings::instance()->value(QString("SerialPort_%1/port").arg(m_instanceName), QString("ttyUSB%1").arg(static_cast<int>(id))).toString();
        m_baudRate = LocalSettings::instance()->value(QString("SerialPort_%1/baudRate").arg(m_instanceName), QSerialPort::Baud9600).toInt();

    }
        break;
    }

}

SerialPortSer::~SerialPortSer()
{
}

int SerialPortSer::Init()
{
    int res=-1;
    try {
        m_sp=new QSerialPort;        //QT += serialport
        m_sp->setPortName(m_portName);
        m_sp->setBaudRate(m_baudRate,QSerialPort::AllDirections);
        m_sp->setDataBits(QSerialPort::Data8);
        m_sp->setParity(QSerialPort::NoParity);
        m_sp->setStopBits(QSerialPort::OneStop);
        m_sp->setFlowControl(QSerialPort::NoFlowControl);
        m_sp->close();

        if(m_sp->open(QIODevice::ReadWrite))
        {
            m_isOpen=true;
            m_readConnection=connect(m_sp,&QSerialPort::readyRead,this,&SerialPortSer::readBoardingTicket);
            m_testTimer=new QTimer(this);
            m_timerConnection=connect(m_testTimer,&QTimer::timeout,this,&SerialPortSer::testOnline);
            m_testTimer->start(15000);

            SerialPortSer::instance_count++;
            qInfo() << QString("SerialPortSer[%1] init success! port = %2, bautRate = %3, opened_total_count = %4").arg(m_instanceName).arg(m_portName).arg(m_baudRate).arg(SerialPortSer::instance_count);
            res = 0;
        }else{
            qWarning() << QString("SerialPortSer[%1] init FAILED! port(%2), bautRate(%3), opened_total_count = %4").arg(m_instanceName).arg(m_portName).arg(m_baudRate).arg(SerialPortSer::instance_count);
            m_isOpen=false;
            if(m_sp!=nullptr)
            {
                m_sp->close();
                m_sp=nullptr;
            }
            res = -1;
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
    emit spStat(m_isOpen);
    return res;
}

int SerialPortSer::UnInit()
{
    int res=-1;
    try {
        if(m_testTimer!=nullptr){
            m_testTimer->stop();
            m_testTimer=nullptr;
        }
        if(m_isOpen){
            m_isOpen=false;
            if(m_sp!=nullptr){
                m_sp->clear();
                m_sp->close();
                m_sp=nullptr;
            }
        }
        if(m_readConnection!=nullptr){
            disconnect(m_readConnection);
        }
        if(m_timerConnection!=nullptr){
            disconnect(m_timerConnection);
        }
        res=0;
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
    SerialPortSer::instance_count--;
    emit spStat(m_isOpen);
    return res;
}

void SerialPortSer::testOnline()
{
    try {
        {
            m_mutex.lock();
            if(m_isOpen && m_sp!=nullptr)
            {
                if(!m_sp->isOpen())
                {
                    m_isOpen=false;
                    SerialPortSer::instance_count--;
                    emit spStat(m_isOpen);
                }
            }
            if(!m_isOpen && m_sp!=nullptr)
            {
                m_sp->close();
                QThread::msleep(20);
                if(m_sp->open(QIODevice::ReadWrite))
                {
                    m_isOpen=true;
                    SerialPortSer::instance_count++;
                    emit spStat(m_isOpen);
                }
            }
            m_mutex.unlock();
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}

void SerialPortSer::readBoardingTicket()
{
    try {
        QThread::msleep(40);
        QByteArray buffer;
        {
            m_mutex.lock();
            if(m_isOpen)
            {
                buffer=m_sp->readAll();
                while (true) {
                    if(!m_sp->waitForReadyRead(10)){
                        break;
                    }
                    buffer.append(m_sp->readAll());
                }
            }
            m_mutex.unlock();
        }
        buffer=buffer.replace('\r',"").replace('\t',"").replace('\n',"");
        if (LocalSettings::instance()->value("Debug/isLogData", false).toBool())
            qInfo()<<QString("[%1]readData:%2").arg(m_instanceName).arg(QString(buffer));

        if(!buffer.isEmpty() && buffer.size()>15){
            if(buffer.size()>=60){
                QByteArray startPortBytes=buffer.mid(30,3);
                QByteArray endPortBytes=buffer.mid(33,3);
                QByteArray flightNoBytes=buffer.mid(36,7);
                QByteArray flightDayBytes=buffer.mid(44,3);
                QByteArray seatIdBytes=buffer.mid(49,3);
                QByteArray boardingNumberBytes=buffer.mid(53,3);

                QDate date(QDate::currentDate().year(),1,1);
                QDate ndate=date.addDays(QString(flightDayBytes).toInt()-1);

                BoardingTicketInfo bti;
                bti.flightNo=QString(flightNoBytes).replace(" ","");
                bti.flightDay=QString("%1").arg(ndate.day(), 2, 10, QLatin1Char('0')).replace(" ","");
                bti.seatId=QString(seatIdBytes).replace(" ","");
                bti.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                bti.startPort=QString(startPortBytes).replace(" ","");
                bti.endPort=QString(endPortBytes).replace(" ","");

                emit readBoardingTicketResult(bti);

            }else if(buffer.size()==18){
                QByteArray flightNoBytes=buffer.mid(0,6);
                QByteArray flightDayBytes=buffer.mid(7,2);
                QByteArray seatIdBytes=buffer.mid(9,3);
                QByteArray startPortBytes=buffer.mid(12,3);
                QByteArray boardingNumberBytes=buffer.mid(15,3);

                BoardingTicketInfo bti;
                bti.flightNo=QString(flightNoBytes).replace(" ","");
                bti.flightDay=QString(flightDayBytes).replace(" ","");
                bti.seatId=QString(seatIdBytes).replace(" ","");
                bti.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                bti.startPort=QString(startPortBytes).replace(" ","");
                bti.endPort="";

                emit readBoardingTicketResult(bti);
            }
            else if(buffer.size()==16){
                QByteArray flightNoBytes=buffer.mid(0,6);
                QByteArray flightDayBytes=buffer.mid(7,2);
                QByteArray startPortBytes=buffer.mid(10,3);
                QByteArray boardingNumberBytes=buffer.mid(13,3);

                BoardingTicketInfo bti;
                bti.flightNo=QString(flightNoBytes).replace(" ","");
                bti.flightDay=QString(flightDayBytes).replace(" ","");
                bti.seatId="";
                bti.boardingNumber=QString(boardingNumberBytes).replace(" ","");
                bti.startPort=QString(startPortBytes).replace(" ","");
                bti.endPort="";

                emit readBoardingTicketResult(bti);
            }
        }
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
    }
}


void SerialPortSer::sendDepartureInfo(BoardingTicketInfo TicketInfo)
{
    m_sendDepaturResult = false;
    try {
        QThread::msleep(40);

        QByteArray buffer;
        /*3.	扫描结果等于18位字符的
        例：GS6595 15 8BHET157
        解析如下：
        ①	航班号6位：GS6595
        ②	空格1位
        ③	日期2位：15
        ④	座位编号3位（如果前面有空格，则需要将空格去掉，再做为服务端参数）：8B
        ⑤	始发站3位：HET
        ⑥	登机号3位：157

        4.	扫描结果等于16位字符的
        例：G52716 06 HET021
        解析如下：
        ①	航班号6位：GS6595
        ②	空格1位
        ③	日期2位：06
        ④	空格1位
        ⑤	始发站3位：HET
        ⑥	登机号3位：021 */

        //①	航班号6位：GS6595
        if (TicketInfo.flightNo.length() >= 6){
            buffer.append(TicketInfo.flightNo.left(6));
        }
        else /*if (TicketInfo.flightNo.length() < 6)*/
        {
            buffer.append(TicketInfo.flightNo);
            for (int i=TicketInfo.flightNo.length(); i<6; i++){
                buffer.append(" ");
            }
        }

        //②	空格1位
        buffer.append(" ");

        //③	日期2位：15
        if (TicketInfo.flightDay.length() >= 2){
            buffer.append(TicketInfo.flightDay.right(2));
        }
        else /*if (TicketInfo.flightDay.length() < 2)*/
        {
            buffer.append(TicketInfo.flightDay);
            for (int i=TicketInfo.flightDay.length(); i<2; i++){
                buffer.append(" ");
            }
        }

        //④	座位编号3位（如果前面有空格，则需要将空格去掉，再做为服务端参数）：8B
        // ***attention:扫描结果等于16位字符的
        if (TicketInfo.seatId.isEmpty()){
            buffer.append(" ");
        }
        else if (TicketInfo.seatId.length() >= 3){
            buffer.append(TicketInfo.seatId.right(3));
        }
        else /*if (TicketInfo.seatId.length() < 3 && !TicketInfo.seatId.isEmpty())*/
        {
            buffer.append(TicketInfo.seatId);
            for (int i=TicketInfo.seatId.length(); i<3; i++){
                buffer.append(" ");
            }
        }

        //⑤	始发站3位：HET
        if (TicketInfo.startPort.length() >= 3){
            buffer.append(TicketInfo.startPort.left(3));
        }
        else /*if (TicketInfo.flightDay.length() < 3)*/
        {
            buffer.append(TicketInfo.startPort);
            for (int i=TicketInfo.startPort.length(); i<3; i++){
                buffer.append(" ");
            }
        }

        //⑥	登机号3位：157
        if (TicketInfo.boardingNumber.length() >= 3){
            buffer.append(TicketInfo.boardingNumber.left(3));
        }
        else /*if (TicketInfo.flightDay.length() < 3)*/
        {
            buffer.append(TicketInfo.boardingNumber);
            for (int i=TicketInfo.boardingNumber.length(); i<3; i++){
                buffer.append(" ");
            }
        }

        //appened "\n\r" at last;
        buffer.append("\n\r");

        //send Message:
        {
            m_mutex.lock();
            if(m_isOpen)
            {
                if (-1 == m_sp->write(buffer))
                    m_sendDepaturResult = false;
            }
            m_mutex.unlock();
        }
        if (LocalSettings::instance()->value("Debug/isLogData", false).toBool())
            qInfo()<<QString("[%1]writeData:%2").arg(m_instanceName).arg(QString(buffer));
    } catch (std::exception &ex) {
        qCritical()<<ex.what();
        return;
    }

    m_sendDepaturResult = true;
    emit sendDepartureInfoResult();
}

