#ifndef PARAMDEF_H
#define PARAMDEF_H

#include <QString>

/*登机牌消息结构体*/
typedef struct BoardingTicketInfo_S
{
    QString         flightNo;       //航班号
    QString         flightDay;      //航班日（dd）
    QString         boardingNumber; //登机序列号
    QString         seatId;         //座位号
    QString         startPort;      //出发港(三字母)
    QString         endPort;        //目的站(三字母)

    BoardingTicketInfo_S(){
        flightNo="";
        flightDay="";
        boardingNumber="";
        seatId="";
        startPort="";
        endPort="";
    }
    BoardingTicketInfo_S& operator= (const BoardingTicketInfo_S& other){
        if (this == &other)
            return *this;
        this->flightNo=other.flightNo;
        this->flightDay=other.flightDay;
        this->boardingNumber=other.boardingNumber;
        this->seatId=other.seatId;
        this->startPort=other.startPort;
        this->endPort=other.endPort;
        return *this;
    }
    void clear(){
        flightNo.clear();
        flightDay.clear();
        boardingNumber.clear();
        seatId.clear();
        startPort.clear();
        endPort.clear();
    }
}BoardingTicketInfo;

#endif // PARAMDEF_H
