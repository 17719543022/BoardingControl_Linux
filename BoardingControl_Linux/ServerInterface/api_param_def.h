#ifndef API_PARAM_DEF_H
#define API_PARAM_DEF_H

#include "ticketScancer/paramdef.h"
#include <QMetaType>
#include <QString>
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>


typedef struct{
    QString     channelCode;        //区域编码
    QString     deviceId;           //设备ID
}DeviceInfo;


typedef struct
{
    int curl_err_code{-1};     //调用服务器接口返回的URL错误码                                                                                                            /**/
    int serverStatus{-1};     //0表示成功，具体见后面的详细的错误码
    QString reqId;      //返回请求端传递的reqId
    QString msg;        //对当前结果的描述
}Return_MSG;

/*2.3.14 调度系统开始登机接口     接口路径：/api/v1/face/boarding/start*******************************************************************/
typedef struct{
    QString reqId;
    QString flightNo;       //航班号
    QString gateNo;     //登机口编码
    QString boardingGate;       //登机口
    QString deviceCode;     //设备编码
    QString flightDay;	//航班日期，yyyy-MM-dd
}Request_Start_Bording;
/*******************************************************************************************************/

/*2.3.15 调度系统结束登机接口      接口路径：/api/v1/face/boarding/finish*******************************************************************/
typedef struct{
    QString reqId;
    QString flightNo;
    QString gateNo;
    QString boardingGate;
    QString deviceCode;
    QString flightDay;	//航班日期，yyyy-MM-dd
}Request_End_Bording;
/*******************************************************************************************************/

/*2.3.16 调度系统其余航班登机      接口路径：/api/v1/face/boarding/strange*******************************************************************/
typedef struct{
    QString reqId;
    QString flightNo;
    QString gateNo;
    QString boardingGate;
    QString deviceCode;
    QString flightDay;	//航班日期，yyyy-MM-dd
}Request_Other_Flight_Bording;
/*******************************************************************************************************/

/*2.3.27 调度系统异常航班激活       接口路径：/api/v1/face/boarding/active*******************************************************************/
typedef struct{
    QString reqId;
    QString flightNo;       //航班号
    QString gateNo;     //登机口编码
    QString boardingGate;       //登机口
    QString deviceCode;     //设备编码
    QString flightDay;	//航班日期，yyyy-MM-dd
}Request_Exception_Flight_Bording;
/*******************************************************************************************************/

/*2.3.29 调度系统人工取消航班  接口路径：/api/v1/face/boarding/cancel*******************************************************************/
typedef struct{
    QString reqId;
    QString flightNo;
    QString gateNo;
    QString boardingGate;
    QString deviceCode;
    QString flightDay;	//航班日期，yyyy-MM-dd
}Request_Manual_Cancel_Bording;
/*******************************************************************************************************/


/*2.3.17 调度系统拉取航班计划   接口路径：/api/v1/face/boarding/flightplan*******************************************************************/
/*100-发布航班计划 paramList******************************************************************************/
typedef struct FlightPlan_s{                                                                                                                                                                    /**/
    QString threeFlightNo;        //非必须    航班3字码                                                                                                                /**/
    QString twoFlightNo;      //非必须    航班2字码                                                                                                                     /**/
    QString depTimeJ;         //非必须    预计起飞时间                                                                                                                 /**/
    QString depTimeS;         //非必须    起飞时间                                                                                                                 /**/
    QString boardingTime;        //非必须    登机时间                                                                                                                  /**/
    QString flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int status{-1};                  //非必须    航班状态  0-等待，1-建库，2-开始登机，3-结束登机，4-起飞                                            /**/
    QString midwayCode;       //非必须    中转机场3字码                                                                                                           /**/
    QString midwayName;       //非必须    中转机场名称                                                                                                            /**/
    QString arrAirportCode;	    //非必须    到达机场3字码                                                                                                        /**/
    QString arrAirportName;	    //非必须    到达机场名                                                                                                              /**/
    QString depAirportCode;	    //非必须    起飞机场3字码                                                                                                        /**/
    QString depAirportName;	//非必须    起飞机场名称                                                                                                           /**/
    int boardingNum{0};     //已登机人数
    int orgDepNum{0};     //始发人数
    int transferNum{0};       //中转人数
    int midwayNum{0};     //经停人数
    int faceNums{0};      //航班建库总数
    QStringList shareFltno;          //共享航班                                                                                                                                             /**/
    int  kindType{-1};       //非必须    航班类型  0-原始，1-增加航班，2-删除航班，3-备降航班，4-二次返航航班                            /**/
    bool manulOpt{false};      //非必须    true-人工拉取的航班，false-非人工拉取的航班                                                                   /**/
    QString boardingGate;     //非必须    登机口                                                                                                                          /**/

     FlightPlan_s &operator=(const FlightPlan_s& other){
        if (this == &other)
            return *this;
        this->arrAirportCode = other.arrAirportCode;
        this->arrAirportName = other.arrAirportName;
        this->boardingGate = other.boardingGate;
        this->boardingTime = other.boardingTime;
        this->depAirportCode = other.depAirportCode;
        this->depAirportName = other.depAirportName;
        this->depTimeJ = other.depTimeJ;
        this->depTimeS = other.depTimeS;
        this->flightDate = other.flightDate;
        this->kindType = other.kindType;
        this->manulOpt = other.manulOpt;
        this->midwayCode = other.midwayCode;
        this->midwayName = other.midwayName;
        this->shareFltno.clear();
        this->shareFltno = other.shareFltno;
        this->status = other.status;
        this->threeFlightNo = other.threeFlightNo;
        this->twoFlightNo = other.twoFlightNo;
        this->boardingNum = other.boardingNum;
        this->orgDepNum = other.orgDepNum;
        this->transferNum = other.transferNum;
        this->midwayNum = other.midwayNum;
        this->faceNums = other.faceNums;
        return *this;
    }
}FlightPlan;                                                                                                                                                                                                 /**/
                                                                                                                                                                                                                    /**/
typedef struct Return_Flight_Plan_Param_s{                                                                                                                                                                                          /**/
    int curl_err_code{-1};     //调用服务器接口返回的URL错误码                                                                                                            /**/
    int serverStatus{-1};           //0表示成功，具体见后面的详细的错误码                                                                                             /**/
    QString reqId;              //返回客户端传递的reqId                                                                                                                   /**/
    QString msg;                //对当前结果的描述                                                                                                                             /**/
    FlightPlan flightPlan;  //航班计划                                                                                                                                                          /**/
    Return_Flight_Plan_Param_s& operator =(Return_Flight_Plan_Param_s& other){
        if (this == &other)
            return *this;
        this->curl_err_code = other.curl_err_code;
        this->serverStatus = other.serverStatus;
        this->reqId = other.reqId;
        this->msg = other.msg;
        this->flightPlan = other.flightPlan;
        return *this;
    }
}Return_Flight_Plan_Param;                                                                                                                                                                       /**/
/*******************************************************************************************************/

typedef struct {                                                                                                                                                                                         /**/
    QString boardingGate;                                                                                                                                                             /**/
    FlightPlan content;                                                                                                                                                                                /**/
}Msg;

typedef struct
{
    int optType;        //100-发布航班计划, 101-建库消息, 102-开始登机消息, 103-结束登机消息, 109-删库消息, 300-识别结果推送, 301-航班的登机人数
    Msg msg;
}MqQueueMsg_Style;

/*101-建库消息 paramList**********************************************************************************/
typedef struct content101_s{                                                                                                                                                                 /**/
    QString threeFlightNo;        //非必须    航班3字码                                                                                                                /**/
    QString twoFlightNo;      //非必须    航班2字码                                                                                                                     /**/
    QString depTimeJ{""};         //非必须    预计起飞时间                                                                                                                 /**/
    QString flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int status{-1};                  //非必须    航班状态  0-等待，1-建库，2-开始登机，3-结束登机，4-起飞                                            /**/
    QString midwayCode;       //非必须    中转机场3字码                                                                                                           /**/
    QString midwayName;       //非必须    中转机场名称                                                                                                            /**/
    QString arrAirportCode;	    //非必须    到达机场3字码                                                                                                        /**/
    QString arrAirportName;	    //非必须    到达机场名                                                                                                              /**/
    QString depAirportCode;	    //非必须    起飞机场3字码                                                                                                        /**/
    QString depAirportName;	//非必须    起飞机场名称                                                                                                          /**/
    QStringList shareFltno;                                                                                                                                                                         /**/
    int  kindType{-1};       //非必须    航班类型  0-原始，1-增加航班，2-删除航班，3-备降航班，4-二次返航航班                           /**/
    bool manulOpt{false};      //非必须    true-人工拉取的航班，false-非人工拉取的航班                                                                  /**/
    QString boardingGate;     //非必须    登机口

    content101_s &operator=(const content101_s& other){
        if (this == &other)
            return *this;
        this->arrAirportCode = other.arrAirportCode;
        this->arrAirportName = other.arrAirportName;
        this->boardingGate = other.boardingGate;
        this->depAirportCode = other.depAirportCode;
        this->depAirportName = other.depAirportName;
        this->depTimeJ = other.depTimeJ;
        this->flightDate = other.flightDate;
        this->kindType = other.kindType;
        this->manulOpt = other.manulOpt;
        this->midwayCode = other.midwayCode;
        this->midwayName = other.midwayName;
        shareFltno.clear();
        this->shareFltno = other.shareFltno;
        this->status = other.status;
        this->threeFlightNo = other.threeFlightNo;
        this->twoFlightNo = other.twoFlightNo;
        return *this;
    }                                                                                                                                                                                                             /**/
}content101;                                                                                                                                                                                             /**/
/*******************************************************************************************************/

/*102-开始登机消息 paramList******************************************************************************/
typedef struct content102_s{                                                                                                                                                                  /**/
    QString threeFlightNo;        //非必须    航班3字码                                                                                                                /**/
    QString twoFlightNo;      //非必须    航班2字码                                                                                                                     /**/
    QString depTimeJ{""};         //非必须    预计起飞时间                                                                                                                 /**/
    QString boardingTime{""};       //登机时间
    QString flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int status{-1};                  //非必须    航班状态  0-等待，1-建库，2-开始登机，3-结束登机，4-起飞                                            /**/
    QString midwayCode;       //非必须    中转机场3字码                                                                                                           /**/
    QString midwayName;       //非必须    中转机场名称                                                                                                            /**/
    QString arrAirportCode;	    //非必须    到达机场3字码                                                                                                        /**/
    QString arrAirportName;	    //非必须    到达机场名                                                                                                              /**/
    QString depAirportCode;	    //非必须    起飞机场3字码                                                                                                        /**/
    QString depAirportName;	//非必须    起飞机场名称                                                                                                          /**/
    QStringList shareFltno;                                                                                                                                                                        /**/
    int  kindType{-1};       //非必须    航班类型  0-原始，1-增加航班，2-删除航班，3-备降航班，4-二次返航航班                           /**/
    bool manulOpt{false};      //非必须    true-人工拉取的航班，false-非人工拉取的航班                                                                  /**/
    QString boardingGate;     //非必须    登机口                                                                                                                          /**/

     content102_s &operator=(const content102_s& other){
        if (this == &other)
            return *this;
        this->arrAirportCode = other.arrAirportCode;
        this->arrAirportName = other.arrAirportName;
        this->boardingGate = other.boardingGate;
        this->boardingTime = other.boardingTime;
        this->depAirportCode = other.depAirportCode;
        this->depAirportName = other.depAirportName;
        this->depTimeJ = other.depTimeJ;
        this->flightDate = other.flightDate;
        this->kindType = other.kindType;
        this->manulOpt = other.manulOpt;
        this->midwayCode = other.midwayCode;
        this->midwayName = other.midwayName;
        shareFltno.clear();
        this->shareFltno = other.shareFltno;
        this->status = other.status;
        this->threeFlightNo = other.threeFlightNo;
        this->twoFlightNo = other.twoFlightNo;
        return *this;
    }
}content102;                                                                                                                                                                                             /**/
/*******************************************************************************************************/

/*103-结束登机消息 paramList******************************************************************************/
typedef struct content103_s{                                                                                                                                                                   /**/
    QString  threeFlightNo;        //非必须    航班3字码                                                                                                                /**/
    QString twoFlightNo;      //非必须    航班2字码                                                                                                                     /**/
    QString  depTimeJ{""};         //非必须    预计起飞时间                                                                                                                 /**/
    QString  boardingTime{""};   //非必须   登机时间                                                                                                                        /**/
    QString  flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int  status{-1};                  //非必须    航班状态  0-等待，1-建库，2-开始登机，3-结束登机，4-起飞                                            /**/
    QString  midwayCode;       //非必须    中转机场3字码                                                                                                           /**/
    QString  midwayName;       //非必须    中转机场名称                                                                                                            /**/
    QString arrAirportCode;	    //非必须    到达机场3字码                                                                                                        /**/
    QString  arrAirportName;	    //非必须    到达机场名                                                                                                              /**/
    QString  depAirportCode;	    //非必须    起飞机场3字码                                                                                                        /**/
    QString  depAirportName;	//非必须    起飞机场名称                                                                                                          /**/
    int  boardingNum;
    int  orgDepNum;
    int  transferNum;
    int  midwayNum;
    int  faceNums;
    QString lastRecogTime{""};
    QStringList shareFltno;          //共享航班                                                                                                                                              /**/
    int   kindType{-1};       //非必须    航班类型  0-原始，1-增加航班，2-删除航班，3-备降航班，4-二次返航航班                           /**/
    bool  manulOpt{false};      //非必须    true-人工拉取的航班，false-非人工拉取的航班                                                                  /**/
    QString  boardingGate;     //非必须    登机口                                                                                                                          /**/

     content103_s &operator=(const content103_s& other){
        if (this == &other)
            return *this;
        this->arrAirportCode = other.arrAirportCode;
        this->arrAirportName = other.arrAirportName;
        this->boardingGate = other.boardingGate;
        this->boardingTime = other.boardingTime;
        this->depAirportCode = other.depAirportCode;
        this->depAirportName = other.depAirportName;
        this->depTimeJ = other.depTimeJ;
        this->flightDate = other.flightDate;
        this->kindType = other.kindType;
        this->manulOpt = other.manulOpt;
        this->midwayCode = other.midwayCode;
        this->midwayName = other.midwayName;
        shareFltno.clear();
        this->shareFltno = other.shareFltno;
        this->status = other.status;
        this->threeFlightNo = other.threeFlightNo;
        this->twoFlightNo = other.twoFlightNo;
        this->boardingNum = other.boardingNum;
        this->orgDepNum = other.orgDepNum;
        this->transferNum = other.transferNum;
        this->midwayNum = other.midwayNum;
        this->faceNums = other.faceNums;
        this->lastRecogTime = other.lastRecogTime;
        return *this;
    }
}content103;                                                                                                                                                                                             /**/
/*******************************************************************************************************/

/*109-删库消息 paramList**********************************************************************************/
typedef struct content109_s{                                                                                                                                                                  /**/
    QString threeFlightNo;        //非必须    航班3字码                                                                                                                /**/
    QString twoFlightNo;      //非必须    航班2字码                                                                                                                     /**/
    QString depTimeJ{""};         //非必须    预计起飞时间                                                                                                                 /**/
    QString boardingTime{""};   //非必须   登机时间                                                                                                                        /**/
    QString flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int status{-1};                  //非必须    航班状态  0-等待，1-建库，2-开始登机，3-结束登机，4-起飞                                            /**/
    QString midwayCode;       //非必须    中转机场3字码                                                                                                           /**/
    QString midwayName;       //非必须    中转机场名称                                                                                                            /**/
    QString arrAirportCode;	    //非必须    到达机场3字码                                                                                                        /**/
    QString arrAirportName;	    //非必须    到达机场名                                                                                                              /**/
    QString depAirportCode;	    //非必须    起飞机场3字码                                                                                                        /**/
    QString depAirportName;	//非必须    起飞机场名称                                                                                                          /**/
    QStringList shareFltno;          //共享航班                                                                                                                                            /**/
    int  kindType{-1};       //非必须    航班类型  0-原始，1-增加航班，2-删除航班，3-备降航班，4-二次返航航班                           /**/
    bool manulOpt{false};      //非必须    true-人工拉取的航班，false-非人工拉取的航班                                                                  /**/
    QString boardingGate;     //非必须    登机口                                                                                                                          /**/

     content109_s &operator=(const content109_s& other){
        if (this == &other)
            return *this;
        this->arrAirportCode = other.arrAirportCode;
        this->arrAirportName = other.arrAirportName;
        this->boardingGate = other.boardingGate;
        this->boardingTime = other.boardingTime;
        this->depAirportCode = other.depAirportCode;
        this->depAirportName = other.depAirportName;
        this->depTimeJ = other.depTimeJ;
        this->flightDate = other.flightDate;
        this->kindType = other.kindType;
        this->manulOpt = other.manulOpt;
        this->midwayCode = other.midwayCode;
        this->midwayName = other.midwayName;
        shareFltno.clear();
        this->shareFltno = other.shareFltno;
        this->status = other.status;
        this->threeFlightNo = other.threeFlightNo;
        this->twoFlightNo = other.twoFlightNo;
        return *this;
    }
}content109;                                                                                                                                                                                             /**/
/*******************************************************************************************************/

/*300-识别结果推送 paramList******************************************************************************/
typedef struct content300_s{                                                                                                                                                                   /**/
    QString startPort;      //:null,                                                                                                                                                     /**/
    QString endPort;        //:null,                                                                                                                                                     /**/
    QString seatNumber;     //:null,                                                                                                                                                 /**/
    QByteArray faceImage;      //image",                                                                                                                                         /**/
    QString isVipChannel;       //:0,                                                                                                                                                   /**/
    int recognizeType{-1};      //:-1,                                                                                                                                                                /**/
    int boardingStatus{0};        //:0,                                                                                                                                                               /**/
    int cardType{0};       //:0,                                                                                                                                                                           /**/
    QString cardNo;     //:null,                                                                                                                                                            /**/
    QString nameZh;     //:null,                                                                                                                                                           /**/
    QString nameEn;     //:null,                                                                                                                                                           /**/
    int sex{0};        //:0,                                                                                                                                                                                     /**/
    QString recognizeTime{""};      //:1576031373382,                                                                                                                          /**/
    float threshold{0.0};        //:0.0                                                                                                                                                                 /**/
    float score{0.0};        //:0.0,                                                                                                                                                                       /**/
    QByteArray basePhoto;      //:null,                                                                                                                                               /**/
    QString flightNumber;       //:null,                                                                                                                                                /**/
    QString boardingNumber;     //:null,                                                                                                                                            /**/
    QString flightDay;      //:null,                                                                                                                                                         /**/
    QString fId;        //:"3fb6c5f90fe24290b5396c619d8685df",                                                                                                     /**/
    QString sourceType;     //:null,                                                                                                                                                      /**/
    QString transferInfo;       //:null,                                                                                                                                                   /**/
    QString reviewInfo;     //:null,                                                                                                                                                      /**/
    QString securityInfo;       //:null                                                                                                                                                   /**/

     content300_s &operator =(const content300_s &other){
        if (this == &other)
            return *this;
        this->startPort = other.startPort;
        this->endPort = other.endPort;
        this->seatNumber = other.seatNumber;
        this->faceImage = other.faceImage;
        this->isVipChannel = other.isVipChannel;
        this->recognizeType = other.recognizeType;
        this->boardingStatus = other.boardingStatus;
        this->cardType = other.cardType;
        this->cardNo = other.cardNo;
        this->nameZh = other.nameZh;
        this->nameEn = other.nameEn;
        this->sex = other.sex;
        this->recognizeTime = other.recognizeTime;
        this->threshold = other.threshold;
        this->score = other.score;
        this->basePhoto = other.basePhoto;
        this->flightNumber = other.flightNumber;
        this->boardingNumber = other.boardingNumber;
        this->flightDay = other.flightDay;
        this->fId = other.fId;
        this->sourceType = other.sourceType;
        this->transferInfo = other.transferInfo;
        this->reviewInfo = other.reviewInfo;
        this->securityInfo = other.securityInfo;
        return *this;
    }
}content300;                                                                                                                                                                                                 /**/
                                                                                                                                                                                                                       /**/
typedef struct {                                                                                                                                                                                            /**/
    QString boardingGate;                                                                                                                                                                /**/
    content300 content;                                                                                                                                                                               /**/
}msg300;                                                                                                                                                                                                      /**/
/*******************************************************************************************************/

/*301-航班的登机人数 paramList****************************************************************************/
typedef struct content301{                                                                                                                                                                  /**/
    QString flightNo;         //非必须    航班号                                                                                                                               /**/
    QString flightDate;       //非必须    航班日期yyyy-MM-dd                                                                                                     /**/
    int boardingNum{0};        //非必须    登机人数                                                                                                                                 /**/
    int faceNums{0};       //total
    int transferNum{0};
    int orgDepNum{0};      //lib
    int midwayNum{0};
    int babyNum{0};

     content301& operator=(const content301 &other){
        if (this == &other)
            return *this;
        this->flightNo = other.flightNo;
        this->flightDate = other.flightDate;
        this->boardingNum = other.boardingNum;
        this->faceNums = other.faceNums;
        this->transferNum = other.transferNum;
        this->orgDepNum = other.orgDepNum;
        this->midwayNum = other.midwayNum;
        this->babyNum = other.babyNum;

        return *this;
    }
}content301;                                                                                                                                                                                             /**/
/*******************************************************************************************************/


/*Gate Control Param List*/
//闸机工作状态,0无状态、1正常、2暂停、3常闭、4常开
enum gateWorkStatus{
    NoneWorkStat = 0,
    Normal = 1,
    Pause = 2,
    KeepClose = 3,
    KeepOpen = 4
};
//闸机门状态，0无状态、1开A门、2关A门、3、开B门、4、关B门、5开C门、6关C门（保留不用）
enum gateDoorStatus{
    NoneDoorStat = 0,
    Open_A_Door = 1,
    Close_A_Door = 2,
    Open_B_Door = 3,
    Close_B_Door = 4,
    Open_C_Door = 5,
    Close_C_Door = 6
};

typedef struct
{
    QString reqId;
    QString flightNo;       //航班号 （航班信息和身份证号至少传一个，航班信息包括航班号和登机序列号）	否
    QString date;           //日期yyyyMMdd	是
    QString boardingGate;   //String	登机口编号	是
    QString cardId;         //String	身份证  （航班信息和身份证号至少传一个，航班信息包括航班号和登机序列号）	否
    QByteArray scenePhoto{nullptr};      //String	Base64现场照，有就传入	是
    int sourceType{-1};     //Int	0-放行，1-报警	是
    QString passengerName;  //String	旅客姓名	否
    QString boardingNumber;	//String	登机序列号 （航班信息和身份证号至少传一个，航班信息包括航班号和登机序列号）	否
    QString seatId;         //String	座位号	否
    QString startPort;      //String	 出发岗（三字码）
    QString endPort;        //String	目的站（三字码）
    int transferSourceType{-1};      //  -1, 非过站旅客，其他值为过站旅客；详细参数为：0,中转；1，经停；2、备降采集；3、中转人工放行；4、经停人工放行；5、备降人工放行；6、经停证件采集（新增）
    int controlType{-1};    //	Int	是否控制闸机门 0-控制闸机门；1-不控制闸机门，直接透传

    //TIP:add at ２０２０年０７月０９日１８：０１：２１
    int isFocus{0};         //是否布控人员
    int hasBaby{0};         //0-无小孩，1-有小孩
    int moreTicket{0};      //0-无多张票，1-有多张票
    int isSpecialChannel{0}; //0-正常，1-特殊通道
    int hasSecurityInfo{0};  //中转时判断是否出过安检区域：0-没有安检信息，1-有安检信息
    int secondBoardingPass{0}; //二次登机

    void init(){
        reqId = "";
        flightNo = "";
        date = "";
        boardingGate = "";
        cardId = "";
        scenePhoto.clear();
        sourceType = -1;
        passengerName = "";
        boardingNumber = "";
        seatId = "";
        startPort = "";
        endPort = "";
        controlType = -1;
        transferSourceType = -1;

        isFocus = 0;
        hasBaby = 0;
        moreTicket = 0;
        isSpecialChannel = 0;
        hasSecurityInfo = 0;
        secondBoardingPass = 0;
    }
}BoardingMode_ManualPass_Send;

typedef struct Collect_Info_Current_s{
    QString flightNo;
    QString flightDay;
    QString boardingNumber;
    QString seatId;
    QString startPort;
    QString endPort;
    QString cardId;
    QString nameZh;
    QByteArray cardPhoto;
    QByteArray faceImage;
    QByteArray largePhoto;
    int sourceType{-1};
    QString mainFlightNo;
    int isBaby{0};
    QString babyFlightNo;
    QString babyFlightDay;
    QString babyBoardingNumber;
    QString babySeatId;
    QString babyStartPort;
    QString babyEndPort;
    QString babyCardId;
    QString babyNameZh;
    int babySourceType{-1};

    Collect_Info_Current_s& operator= (const Collect_Info_Current_s& other){
        if (this == &other)
            return *this;
        this->flightNo = other.flightNo;
        this->flightDay = other.flightDay;
        this->boardingNumber = other.boardingNumber;
        this->seatId = other.seatId;
        this->startPort = other.startPort;
        this->endPort = other.endPort;
        this->cardId = other.cardId;
        this->nameZh = other.nameZh;
        this->cardPhoto = other.cardPhoto;
        this->faceImage = other.faceImage;
        this->largePhoto = other.largePhoto;
        this->sourceType = other.sourceType;
        this->mainFlightNo = other.mainFlightNo;
        this->isBaby = other.isBaby;
        this->babyFlightNo = other.babyFlightNo;
        this->babyFlightDay = other.babyFlightDay;
        this->babyBoardingNumber = other.babyBoardingNumber;
        this->babySeatId = other.babySeatId;
        this->babyStartPort = other.babyStartPort;
        this->babyEndPort = other.babyEndPort;
        this->babyCardId = other.babyCardId;
        this->babyNameZh = other.babyNameZh;
        this->babySourceType = other.babySourceType;
        return *this;
    }
}Collect_Info;

enum PostUrlType{
    Start_Boarding_Clicked,
    End_Boarding_Clicked,
    Other_Flight_Clicked,
    Exception_Flight_Clicked,
    Cancel_Flight_Clicked,
};

enum API_PARAM_TYPE{
    FLIGHT_PALNE = 100,
    CREAT_RESPONSITORY = 101,
    START_BOARDING = 102,
    END_BOARDING = 103,
    DELETE_LIBRARY = 109,
    IDENTIFY_RESULT= 300,
    BOARDING_PPL_COUNT = 301,

    GateControl = 901,
    BoardingMode_ManualPass = 902,
    CollectingMode_Cmd = 903,
    CollectingMode_ManualCPass = 904
};

#define REGIST_QMetaType
// If putting these params on signals and slots, you should use this function before that;
 inline REGIST_QMetaType  void regist_params(){
     qRegisterMetaType<gateWorkStatus>("gateWorkStatus");
     qRegisterMetaType<gateDoorStatus>("gateDoorStatus");
     qRegisterMetaType<FlightPlan>("FlightPlan");
     qRegisterMetaType<content101>("content101");
     qRegisterMetaType<content102>("content102");
     qRegisterMetaType<content103>("content103");
     qRegisterMetaType<content109>("content109");
     qRegisterMetaType<content300>("content300");
     qRegisterMetaType<content301>("content301");
     qRegisterMetaType<PostUrlType>("PostUrlTsype");
     qRegisterMetaType<API_PARAM_TYPE>("API_PARAM_TYPE");
     qRegisterMetaType<BoardingTicketInfo>("BoardingTicketInfo"); //Q_DECLARE_METATYPE(BoardingTicketInfo)

}



 ////
 ////LiuYong
/* 2.3.13登机口建库、已登机、未登机旅客查询接口**************************************************************/

 struct DataInfo_FlightReview {
     int boardingNum;
     int faceNums;
     int manualNum;
     int midwayNum;
     int orgDepNum;
     int recognizeNum;
     int transferNum;

     DataInfo_FlightReview() {
         boardingNum = 0;
         faceNums = 0;
         manualNum = 0;
         midwayNum = 0;
         orgDepNum = 0;
         recognizeNum = 0;
         transferNum = 0;
     }
 };

 struct FlightReviewResult {
     QString boardingNumber;
     QString cardNo;
     QString flightNumber;
     QString flightDate;    //yyyy-MM-dd
     QString id;
     QString passengerName;
     QString photoPath;
     QByteArray basePhoto;
     QString seatNumber;
     QString updateTime;
     QString boardingTime;
     int repeatFlag;
     int boardingStatus;
     int sourceType;
     int isInterceptLabel;
     bool isSameBoardingNumber;

//     FlightReviewResult &operator= (const FlightReviewResult &other){
//         if (this == &other)
//             return *this;
//         this->boardingNumber = other.boardingNumber;
//         this->cardNo = other.cardNo;
//         this->flightNumber = other.flightNumber;
//         this->id = other.id;
//         this->passengerName = other.passengerName;
//         this->photoPath = other.photoPath;
//         this->seatNumber = other.seatNumber;
//         this->updateTime = other.updateTime;
//         this->boardingTime = other.boardingTime;
//         return *this;
//     }

     FlightReviewResult() {
         boardingNumber = QString();
         boardingStatus = -1;
         cardNo = QString();
         flightNumber = QString();
         flightDate = QString();
         id = QString();
         passengerName = QString();
         photoPath = QString();
         basePhoto = QByteArray();
         repeatFlag = -1;
         seatNumber = QString();
         updateTime = QString();
         boardingTime = QString();
         sourceType = 255;
         isInterceptLabel = 0;
         isSameBoardingNumber = true;
     }
 };

 struct FlightReviewInterface {
     int status;
     QString reqId;
     QString msg;
     int num;
     int total;
     DataInfo_FlightReview dataInfo;
     int validSize;
     FlightReviewResult results[1000];
     FlightReviewResult boarded[1000];
     FlightReviewResult unboard[1000];

     FlightReviewInterface() {
         status = -1;
         reqId = QString();
         msg = QString();
         num = 0;
         total = 0;
         validSize = 0;
     }

     void doUpdate(QJsonDocument &doc) {
         QJsonObject docObj = doc.object();

         if (docObj.contains("status")) {
             status = docObj.value("status").toInt();
         }
         if (docObj.contains("reqId")) {
             reqId = docObj.value("reqId").toString();
         }
         if (docObj.contains("msg")) {
             msg = docObj.value("msg").toString();
         }
         if (docObj.contains("num")) {
             num = docObj.value("num").toInt();
         }
         if (docObj.contains("total")) {
             total = docObj.value("total").toInt();
         }

         if (docObj.contains("dataInfo")) {
             QJsonValue dataInfoJson = docObj.value("dataInfo");
             if (!dataInfoJson.isNull() && dataInfoJson.isObject()) {
                 QJsonObject dataInfoObj = dataInfoJson.toObject();
                 dataInfo.boardingNum = dataInfoObj.value("boardingNum").toInt();
                 dataInfo.faceNums = dataInfoObj.value("faceNums").toInt();
                 dataInfo.manualNum = dataInfoObj.value("manualNum").toInt();
                 dataInfo.midwayNum = dataInfoObj.value("midwayNum").toInt();
                 dataInfo.orgDepNum = dataInfoObj.value("orgDepNum").toInt();
                 dataInfo.recognizeNum = dataInfoObj.value("recognizeNum").toInt();
                 dataInfo.transferNum = dataInfoObj.value("transferNum").toInt();
             }
         }

         if (docObj.contains("results")) {
             updateResults(docObj);
             updateBoarded(docObj);
             updateUnBoard(docObj);
         }
     }

     void updateResults(QJsonObject &docObj) {
         FlightReviewResult sortings[1000];

         QJsonValue resultsJson = docObj.value("results");
         if (!resultsJson.isNull() && resultsJson.isArray()) {
             QJsonArray array = resultsJson.toArray();
             validSize = (array.size()) > 1000 ? 1000 : array.size();
             for (int i = 0; i < validSize && i < 1000; i++) {
                 QString time = array.at(i).toObject().value("updateTime").toString();
                 QString boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                 QString id = array.at(i).toObject().value("id").toString();
                 if (i == 0) {
                     sortings[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                     sortings[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                     sortings[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                     sortings[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                     sortings[i].id = array.at(i).toObject().value("id").toString();
                     sortings[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                     sortings[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                     sortings[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                     sortings[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                     sortings[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                     sortings[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                     sortings[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                     sortings[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                     sortings[i].isSameBoardingNumber = false;
                 } else {
                     bool isSameboardingNumber = false;
                     int sameBoardingNumber = 0;
                     for (int j = 0; j < i; j++) {
                         if ((boardingNumber == sortings[j].boardingNumber) && (boardingNumber != "") && (id != "")) {
                             isSameboardingNumber = true;
                             sameBoardingNumber = j;
                             break;
                         }
                     }

                     if (isSameboardingNumber) {
                         QString tempBoardingNumber = sortings[sameBoardingNumber].boardingNumber;
                         int tempBoardingStatus = sortings[sameBoardingNumber].boardingStatus;
                         QString tempCardNo = sortings[sameBoardingNumber].cardNo;
                         QString tempFlightNumber = sortings[sameBoardingNumber].flightNumber;
                         QString tempId = sortings[sameBoardingNumber].id;
                         QString tempPassengerName = sortings[sameBoardingNumber].passengerName;
                         QString tempPhotoPath = sortings[sameBoardingNumber].photoPath;
                         int tempRepeatFlag = sortings[sameBoardingNumber].repeatFlag;
                         QString tempSeatNumber = sortings[sameBoardingNumber].seatNumber;
                         QString tempUpdateTime = sortings[sameBoardingNumber].updateTime;
                         QString tempBoardingTime = sortings[sameBoardingNumber].boardingTime;
                         int tempSourceType = sortings[sameBoardingNumber].sourceType;
                         int tempIsInterceptLabel = sortings[sameBoardingNumber].isInterceptLabel;

                         for (int k = i; k > 0; k--) {
                             if (k > sameBoardingNumber + 1) {
                                 sortings[k].boardingNumber = sortings[k - 1].boardingNumber;
                                 sortings[k].boardingStatus = sortings[k - 1].boardingStatus;
                                 sortings[k].cardNo = sortings[k - 1].cardNo;
                                 sortings[k].flightNumber = sortings[k - 1].flightNumber;
                                 sortings[k].id = sortings[k - 1].id;
                                 sortings[k].passengerName = sortings[k - 1].passengerName;
                                 sortings[k].photoPath = sortings[k - 1].photoPath;
                                 sortings[k].repeatFlag = sortings[k - 1].repeatFlag;
                                 sortings[k].seatNumber = sortings[k - 1].seatNumber;
                                 sortings[k].updateTime = sortings[k - 1].updateTime;
                                 sortings[k].boardingTime = sortings[k - 1].boardingTime;
                                 sortings[k].sourceType = sortings[k - 1].sourceType;
                                 sortings[k].isInterceptLabel = sortings[k - 1].isInterceptLabel;
                                 sortings[k].isSameBoardingNumber = sortings[k - 1].isSameBoardingNumber;
                             } else if (k >= 2) {
                                 sortings[k].boardingNumber = sortings[k - 2].boardingNumber;
                                 sortings[k].boardingStatus = sortings[k - 2].boardingStatus;
                                 sortings[k].cardNo = sortings[k - 2].cardNo;
                                 sortings[k].flightNumber = sortings[k - 2].flightNumber;
                                 sortings[k].id = sortings[k - 2].id;
                                 sortings[k].passengerName = sortings[k - 2].passengerName;
                                 sortings[k].photoPath = sortings[k - 2].photoPath;
                                 sortings[k].repeatFlag = sortings[k - 2].repeatFlag;
                                 sortings[k].seatNumber = sortings[k - 2].seatNumber;
                                 sortings[k].updateTime = sortings[k - 2].updateTime;
                                 sortings[k].boardingTime = sortings[k - 2].boardingTime;
                                 sortings[k].sourceType = sortings[k - 2].sourceType;
                                 sortings[k].isInterceptLabel = sortings[k - 2].isInterceptLabel;
                                 sortings[k].isSameBoardingNumber = sortings[k - 2].isSameBoardingNumber;
                             }
                         }

                         sortings[1].boardingNumber = tempBoardingNumber;
                         sortings[1].boardingStatus = tempBoardingStatus;
                         sortings[1].cardNo = tempCardNo;
                         sortings[1].flightNumber = tempFlightNumber;
                         sortings[1].id = tempId;
                         sortings[1].passengerName = tempPassengerName;
                         sortings[1].photoPath = tempPhotoPath;
                         sortings[1].repeatFlag = tempRepeatFlag;
                         sortings[1].seatNumber = tempSeatNumber;
                         sortings[1].updateTime = tempUpdateTime;
                         sortings[1].boardingTime = tempBoardingTime;
                         sortings[1].sourceType = tempSourceType;
                         sortings[1].isInterceptLabel = tempIsInterceptLabel;
                         sortings[1].isSameBoardingNumber = true;

                         sortings[0].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                         sortings[0].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                         sortings[0].cardNo = array.at(i).toObject().value("cardNo").toString();
                         sortings[0].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                         sortings[0].id = array.at(i).toObject().value("id").toString();
                         sortings[0].passengerName = array.at(i).toObject().value("passengerName").toString();
                         sortings[0].photoPath = array.at(i).toObject().value("photoPath").toString();
                         sortings[0].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                         sortings[0].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                         sortings[0].updateTime = array.at(i).toObject().value("updateTime").toString();
                         sortings[0].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                         sortings[0].sourceType = array.at(i).toObject().value("sourceType").toInt();
                         sortings[0].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                         sortings[0].isSameBoardingNumber = true;
                     } else {
                         for (int j = 0; j < i; j++) {
                             if (time > sortings[j].updateTime && !sortings[j].isSameBoardingNumber) {
                                 for (int k = i - 1; k >= j; k--) {
                                     sortings[k + 1].boardingNumber = sortings[k].boardingNumber;
                                     sortings[k + 1].boardingStatus = sortings[k].boardingStatus;
                                     sortings[k + 1].cardNo = sortings[k].cardNo;
                                     sortings[k + 1].flightNumber = sortings[k].flightNumber;
                                     sortings[k + 1].id = sortings[k].id;
                                     sortings[k + 1].passengerName = sortings[k].passengerName;
                                     sortings[k + 1].photoPath = sortings[k].photoPath;
                                     sortings[k + 1].repeatFlag = sortings[k].repeatFlag;
                                     sortings[k + 1].seatNumber = sortings[k].seatNumber;
                                     sortings[k + 1].updateTime = sortings[k].updateTime;
                                     sortings[k + 1].boardingTime = sortings[k].boardingTime;
                                     sortings[k + 1].sourceType = sortings[k].sourceType;
                                     sortings[k + 1].isInterceptLabel = sortings[k].isInterceptLabel;
                                     sortings[k + 1].isSameBoardingNumber = sortings[k].isSameBoardingNumber;
                                 }
                                 sortings[j].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                                 sortings[j].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                                 sortings[j].cardNo = array.at(i).toObject().value("cardNo").toString();
                                 sortings[j].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                                 sortings[j].id = array.at(i).toObject().value("id").toString();
                                 sortings[j].passengerName = array.at(i).toObject().value("passengerName").toString();
                                 sortings[j].photoPath = array.at(i).toObject().value("photoPath").toString();
                                 sortings[j].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                                 sortings[j].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                                 sortings[j].updateTime = array.at(i).toObject().value("updateTime").toString();
                                 sortings[j].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                                 sortings[j].sourceType = array.at(i).toObject().value("sourceType").toInt();
                                 sortings[j].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                                 sortings[j].isSameBoardingNumber = false;
                                 break;
                             }
                             if (j == i - 1) {
                                 sortings[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                                 sortings[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                                 sortings[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                                 sortings[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                                 sortings[i].id = array.at(i).toObject().value("id").toString();
                                 sortings[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                                 sortings[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                                 sortings[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                                 sortings[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                                 sortings[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                                 sortings[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                                 sortings[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                                 sortings[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                                 sortings[i].isSameBoardingNumber = false;
                             }
                         }
                     }
                 }
             }

             // 对isSameBoardingNumber记录再排序，
             // 一是为了让相同序列号（考虑三个或者更多记录具有相同序列号的情况）的排在一起，
             // 二是为了让有特征（0/4/5/7）的居于这些重复序列号记录的前部位置。
             int firstNotSameNumber = validSize;
             for (int i = 0; i < validSize && i < 1000; i++) {
                 if (!sortings[i].isSameBoardingNumber) {
                     firstNotSameNumber = i;
                     break;
                 }
             }

             QList<QString> diffBoardingNoList;
             for (int i = 0; i < firstNotSameNumber; i++) {
                 bool isAlreadyInList = false;
                 for (int j = 0; j < diffBoardingNoList.size(); j++) {
                     if (diffBoardingNoList.at(j) == sortings[i].boardingNumber) {
                         isAlreadyInList = true;
                         break;
                     }
                 }
                 if (!isAlreadyInList) {
                     diffBoardingNoList << sortings[i].boardingNumber;
                 }
             }

             int r = 0;
             for (int i = 0; i < diffBoardingNoList.size(); i++) {
                 for (int j = 0; j < firstNotSameNumber; j++) {
                     if ((sortings[j].boardingNumber == diffBoardingNoList.at(i))
                             && ((sortings[j].sourceType == 0)
                                 || (sortings[j].sourceType == 4)
                                 || (sortings[j].sourceType == 5)
                                 || (sortings[j].sourceType == 7))) {
                         results[r].boardingNumber = sortings[j].boardingNumber;
                         results[r].boardingStatus = sortings[j].boardingStatus;
                         results[r].cardNo = sortings[j].cardNo;
                         results[r].flightNumber = sortings[j].flightNumber;
                         results[r].id = sortings[j].id;
                         results[r].passengerName = sortings[j].passengerName;
                         results[r].photoPath = sortings[j].photoPath;
                         results[r].repeatFlag = sortings[j].repeatFlag;
                         results[r].seatNumber = sortings[j].seatNumber;
                         results[r].updateTime = sortings[j].updateTime;
                         results[r].boardingTime = sortings[j].boardingTime;
                         results[r].sourceType = sortings[j].sourceType;
                         results[r].isInterceptLabel = sortings[j].isInterceptLabel;
                         results[r].isSameBoardingNumber = sortings[j].isSameBoardingNumber;
                         r++;
                     }
                 }
                 for (int j = 0; j < firstNotSameNumber; j++) {
                     if ((sortings[j].boardingNumber == diffBoardingNoList.at(i))
                             && (sortings[j].sourceType != 0)
                             && (sortings[j].sourceType != 4)
                             && (sortings[j].sourceType != 5)
                             && (sortings[j].sourceType != 7)) {
                         results[r].boardingNumber = sortings[j].boardingNumber;
                         results[r].boardingStatus = sortings[j].boardingStatus;
                         results[r].cardNo = sortings[j].cardNo;
                         results[r].flightNumber = sortings[j].flightNumber;
                         results[r].id = sortings[j].id;
                         results[r].passengerName = sortings[j].passengerName;
                         results[r].photoPath = sortings[j].photoPath;
                         results[r].repeatFlag = sortings[j].repeatFlag;
                         results[r].seatNumber = sortings[j].seatNumber;
                         results[r].updateTime = sortings[j].updateTime;
                         results[r].boardingTime = sortings[j].boardingTime;
                         results[r].sourceType = sortings[j].sourceType;
                         results[r].isInterceptLabel = sortings[j].isInterceptLabel;
                         results[r].isSameBoardingNumber = sortings[j].isSameBoardingNumber;
                         r++;
                     }
                 }
             }

             for (int i = 0; i < validSize && i < 1000; i++) {
                 if (!sortings[i].isSameBoardingNumber) {
                     results[i].boardingNumber = sortings[i].boardingNumber;
                     results[i].boardingStatus = sortings[i].boardingStatus;
                     results[i].cardNo = sortings[i].cardNo;
                     results[i].flightNumber = sortings[i].flightNumber;
                     results[i].id = sortings[i].id;
                     results[i].passengerName = sortings[i].passengerName;
                     results[i].photoPath = sortings[i].photoPath;
                     results[i].repeatFlag = sortings[i].repeatFlag;
                     results[i].seatNumber = sortings[i].seatNumber;
                     results[i].updateTime = sortings[i].updateTime;
                     results[i].boardingTime = sortings[i].boardingTime;
                     results[i].sourceType = sortings[i].sourceType;
                     results[i].isInterceptLabel = sortings[i].isInterceptLabel;
                     results[i].isSameBoardingNumber = sortings[i].isSameBoardingNumber;
                 }
             }
         }
     }

     void updateBoarded(QJsonObject &docObj) {
         QJsonValue resultsJson = docObj.value("results");
         if (!resultsJson.isNull() && resultsJson.isArray()) {
             QJsonArray array = resultsJson.toArray();
             validSize = (array.size()) > 1000 ? 1000 : array.size();
             for (int i = 0; i < validSize && i < 1000; i++) {
                 QString boardingTime = array.at(i).toObject().value("boardingTime").toString();
                 if (i == 0) {
                     boarded[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                     boarded[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                     boarded[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                     boarded[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                     boarded[i].id = array.at(i).toObject().value("id").toString();
                     boarded[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                     boarded[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                     boarded[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                     boarded[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                     boarded[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                     boarded[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                     boarded[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                     boarded[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                     boarded[i].isSameBoardingNumber = false;
                 } else {
                     for (int j = 0; j < i; j++) {
                         if (boardingTime > boarded[j].boardingTime) {
                             for (int k = i - 1; k >= j; k--) {
                                 boarded[k + 1].boardingNumber = boarded[k].boardingNumber;
                                 boarded[k + 1].boardingStatus = boarded[k].boardingStatus;
                                 boarded[k + 1].cardNo = boarded[k].cardNo;
                                 boarded[k + 1].flightNumber = boarded[k].flightNumber;
                                 boarded[k + 1].id = boarded[k].id;
                                 boarded[k + 1].passengerName = boarded[k].passengerName;
                                 boarded[k + 1].photoPath = boarded[k].photoPath;
                                 boarded[k + 1].repeatFlag = boarded[k].repeatFlag;
                                 boarded[k + 1].seatNumber = boarded[k].seatNumber;
                                 boarded[k + 1].updateTime = boarded[k].updateTime;
                                 boarded[k + 1].boardingTime = boarded[k].boardingTime;
                                 boarded[k + 1].sourceType = boarded[k].sourceType;
                                 boarded[k + 1].isInterceptLabel = boarded[k].isInterceptLabel;
                                 boarded[k + 1].isSameBoardingNumber = boarded[k].isSameBoardingNumber;
                             }
                             boarded[j].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                             boarded[j].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                             boarded[j].cardNo = array.at(i).toObject().value("cardNo").toString();
                             boarded[j].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                             boarded[j].id = array.at(i).toObject().value("id").toString();
                             boarded[j].passengerName = array.at(i).toObject().value("passengerName").toString();
                             boarded[j].photoPath = array.at(i).toObject().value("photoPath").toString();
                             boarded[j].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                             boarded[j].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                             boarded[j].updateTime = array.at(i).toObject().value("updateTime").toString();
                             boarded[j].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                             boarded[j].sourceType = array.at(i).toObject().value("sourceType").toInt();
                             boarded[j].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                             boarded[j].isSameBoardingNumber = false;
                             break;
                         }
                         if (j == i - 1) {
                             boarded[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                             boarded[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                             boarded[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                             boarded[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                             boarded[i].id = array.at(i).toObject().value("id").toString();
                             boarded[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                             boarded[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                             boarded[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                             boarded[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                             boarded[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                             boarded[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                             boarded[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                             boarded[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                             boarded[i].isSameBoardingNumber = false;
                         }
                     }
                 }
             }
         }
     }

     void updateUnBoard(QJsonObject &docObj) {
         QJsonValue resultsJson = docObj.value("results");
         if (!resultsJson.isNull() && resultsJson.isArray()) {
             QJsonArray array = resultsJson.toArray();
             validSize = (array.size()) > 1000 ? 1000 : array.size();
             for (int i = 0; i < validSize && i < 1000; i++) {
                 QString seatNumber = array.at(i).toObject().value("seatNumber").toString();
                 if (i == 0) {
                     unboard[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                     unboard[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                     unboard[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                     unboard[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                     unboard[i].id = array.at(i).toObject().value("id").toString();
                     unboard[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                     unboard[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                     unboard[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                     unboard[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                     unboard[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                     unboard[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                     unboard[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                     unboard[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                     unboard[i].isSameBoardingNumber = false;
                 } else {
                     for (int j = 0; j < i; j++) {
                         if (seatNumber < unboard[j].seatNumber) {
                             for (int k = i - 1; k >= j; k--) {
                                 unboard[k + 1].boardingNumber = unboard[k].boardingNumber;
                                 unboard[k + 1].boardingStatus = unboard[k].boardingStatus;
                                 unboard[k + 1].cardNo = unboard[k].cardNo;
                                 unboard[k + 1].flightNumber = unboard[k].flightNumber;
                                 unboard[k + 1].id = unboard[k].id;
                                 unboard[k + 1].passengerName = unboard[k].passengerName;
                                 unboard[k + 1].photoPath = unboard[k].photoPath;
                                 unboard[k + 1].repeatFlag = unboard[k].repeatFlag;
                                 unboard[k + 1].seatNumber = unboard[k].seatNumber;
                                 unboard[k + 1].updateTime = unboard[k].updateTime;
                                 unboard[k + 1].boardingTime = unboard[k].boardingTime;
                                 unboard[k + 1].sourceType = unboard[k].sourceType;
                                 unboard[k + 1].isInterceptLabel = unboard[k].isInterceptLabel;
                                 unboard[k + 1].isSameBoardingNumber = unboard[k].isSameBoardingNumber;
                             }
                             unboard[j].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                             unboard[j].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                             unboard[j].cardNo = array.at(i).toObject().value("cardNo").toString();
                             unboard[j].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                             unboard[j].id = array.at(i).toObject().value("id").toString();
                             unboard[j].passengerName = array.at(i).toObject().value("passengerName").toString();
                             unboard[j].photoPath = array.at(i).toObject().value("photoPath").toString();
                             unboard[j].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                             unboard[j].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                             unboard[j].updateTime = array.at(i).toObject().value("updateTime").toString();
                             unboard[j].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                             unboard[j].sourceType = array.at(i).toObject().value("sourceType").toInt();
                             unboard[j].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                             unboard[j].isSameBoardingNumber = false;
                             break;
                         }
                         if (j == i - 1) {
                             unboard[i].boardingNumber = array.at(i).toObject().value("boardingNumber").toString();
                             unboard[i].boardingStatus = array.at(i).toObject().value("boardingStatus").toInt();
                             unboard[i].cardNo = array.at(i).toObject().value("cardNo").toString();
                             unboard[i].flightNumber = array.at(i).toObject().value("flightNumber").toString();
                             unboard[i].id = array.at(i).toObject().value("id").toString();
                             unboard[i].passengerName = array.at(i).toObject().value("passengerName").toString();
                             unboard[i].photoPath = array.at(i).toObject().value("photoPath").toString();
                             unboard[i].repeatFlag = array.at(i).toObject().value("repeatFlag").toInt();
                             unboard[i].seatNumber = array.at(i).toObject().value("seatNumber").toString();
                             unboard[i].updateTime = array.at(i).toObject().value("updateTime").toString();
                             unboard[i].boardingTime = array.at(i).toObject().value("boardingTime").toString();
                             unboard[i].sourceType = array.at(i).toObject().value("sourceType").toInt();
                             unboard[i].isInterceptLabel = array.at(i).toObject().value("isInterceptLabel").toInt();
                             unboard[i].isSameBoardingNumber = false;
                         }
                     }
                 }
             }
         }
     }
};

 struct FlightReviewRequest {
     int queryType{3};  // queryType写死为3,以后0/1/2都不用了
     QString flightDtae; //yyyy-MM-dd
     QString input;
 };

 struct FlightReviewResponse {
     QJsonDocument doc;
     int queryType;
     int errorCode;
     bool founded;
     FlightReviewInterface parsedResult;

     void update(QJsonDocument &doc) {
         this->doc = doc;

         QJsonObject docObj = doc.object();

         QJsonValue dataInfoJson, resultsJson;
         if (docObj.contains("dataInfo")) {
             dataInfoJson = docObj.value("dataInfo");
         }

         if (docObj.contains("results")) {
             resultsJson = docObj.value("results");
         }
         if (dataInfoJson == QJsonValue() || resultsJson == QJsonValue()) {
             founded = false;
         }

         parsedResult.doUpdate(doc);
     }

     FlightReviewResponse() {
         doc = QJsonDocument();
         queryType = -1;
         errorCode = -1;
         founded = true;
     }
 };

 struct LibDeleteRequest {
     QString reqId;
     QString flightNo;
     QString flightDate; //yyyy-MM-dd
     QString gateNo;
     QString boardingGate;
     QString deviceCode;
     QString id;

     LibDeleteRequest() {
         reqId = QString();
         flightNo = QString();
         flightDate = QString();
         gateNo = QString();
         boardingGate = QString();
         deviceCode = QString();
         id = QString();
     }
 };

 struct LibDeleteResponse {
     int status;
     QString reqId;
     QString msg;

     LibDeleteResponse() {
         status = -1;
         reqId = QString();
         msg = QString();
     }
 };

 /******************************************************************************************************/

 /* 2.3.24 人员回查-安检、登机口接口************************************************************************/

 struct BoardingInfo {
     int passType;
     int passStatus;
     QString passTime;
     QString gateNo;
     QString deviceId;
     QString channelName;
     QString photoPath;

     BoardingInfo() {
         passType = -1;
         passStatus = -1;
         passTime = QString();
         gateNo = QString();
         deviceId = QString();
         channelName = QString();
         photoPath = QString();
     }
 };

 struct ReviewInfo {
     int passType;
     int passStatus;
     QString passTime;
     QString gateNo;
     QString deviceId;
     QString channelName;
     QString photoPath;

     ReviewInfo() {
         passType = -1;
         passStatus = -1;
         passTime = QString();
         gateNo = QString();
         deviceId = QString();
         channelName = QString();
         photoPath = QString();
     }
 };

 struct SecurityInfo {
     int passType;
     int passStatus;
     QString passTime;
     QString gateNo;
     QString deviceId;
     QString channelName;
     QString photoPath;

     SecurityInfo() {
         passType = -1;
         passStatus = -1;
         passTime = QString();
         gateNo = QString();
         deviceId = QString();
         channelName = QString();
         photoPath = QString();
     }
 };

 struct TransferInfo {
     int sourceType;
     QString photoPath;
     QString collectTime;
     QString gateNo;
     QString deviceId;
     QString channelName;
     QString flightNo;
     TransferInfo() {
         sourceType = -1;
         photoPath = QString();
         collectTime = QString();
         gateNo = QString();
         deviceId = QString();
         channelName = QString();
         flightNo = QString();
     }
 };

 struct UserInfo {
     QString certificateNumber;
     QString passengerName;
     QString passengerEnglishName;
     QString flightNo;
     QString boardingNumber;
     QString flightDay;
     QString seatId;
     QString gateNo;
     int isDelete;
     int isFocus;

     UserInfo() {
         certificateNumber = QString();
         passengerName = QString();
         passengerEnglishName = QString();
         flightNo = QString();
         boardingNumber = QString();
         flightDay = QString();
         seatId = QString();
         gateNo = QString();
         isDelete = -1;
         isFocus = -1;
     }
 };

 struct FlowReviewResult {
     bool hasUserInfo;
     UserInfo userInfo;
     bool hasSecurityInfo;
     SecurityInfo securityInfo;
     bool hasReviewInfo;
     ReviewInfo reviewInfo;
     bool hasTransferInfo;
     TransferInfo transferInfo;
     bool hasBoardingInfo;
     BoardingInfo boardingInfo;

     FlowReviewResult() {
         hasUserInfo = false;
         hasSecurityInfo = false;
         hasReviewInfo = false;
         hasTransferInfo = false;
         hasBoardingInfo = false;
     }
 };

 struct FlowReviewInterface {
     int status;
     QString reqId;
     QString msg;
     int flowNum;
     FlowReviewResult result[10];
     int isBaby;

     FlowReviewInterface() {
         status = -1;
         reqId = QString();
         msg = QString();
         flowNum = 0;
         isBaby = -1;
     }

     void update(QJsonDocument &doc) {
         QJsonObject docObj = doc.object();

         if (docObj.contains("status")) {
             status = docObj.value("status").toInt();
         }
         if (docObj.contains("reqId")) {
             reqId = docObj.value("reqId").toString();
         }
         if (docObj.contains("msg")) {
             msg = docObj.value("msg").toString();
         }
         if (docObj.contains("result")) {
             QJsonValue resultObj = docObj.value("result");
             if (!resultObj.isNull() && resultObj.isArray()) {
                 QJsonArray array = resultObj.toArray();
                 flowNum = array.size();
                 for (int i = 0; i < array.size() && i < 10; i++) {
                     QJsonValue userInfo = array.at(i).toObject().value("userInfo");
                     if (!userInfo.isNull() && !userInfo.isUndefined()) {
                         result[i].hasUserInfo = true;
                         result[i].userInfo.certificateNumber = userInfo.toObject().value("certificateNumber").toString();
                         result[i].userInfo.passengerName = userInfo.toObject().value("passengerName").toString();
                         result[i].userInfo.passengerEnglishName = userInfo.toObject().value("passengerEnglishName").toString();
                         result[i].userInfo.flightNo = userInfo.toObject().value("flightNo").toString();
                         result[i].userInfo.boardingNumber = userInfo.toObject().value("boardingNumber").toString();
                         result[i].userInfo.flightDay = userInfo.toObject().value("flightDay").toString();
                         result[i].userInfo.seatId = userInfo.toObject().value("seatId").toString();
                         result[i].userInfo.gateNo = userInfo.toObject().value("gateNo").toString();
                         result[i].userInfo.isDelete = userInfo.toObject().value("isDelete").toInt();
                         result[i].userInfo.isFocus = userInfo.toObject().value("isFocus").toInt();
                     } else {
                         result[i].hasUserInfo = false;
                     }
                     QJsonValue securityInfo = array.at(i).toObject().value("securityInfo");
                     if (!securityInfo.isNull() && !securityInfo.isUndefined()) {
                         result[i].hasSecurityInfo = true;
                         result[i].securityInfo.passType = securityInfo.toObject().value("passType").toInt();
                         result[i].securityInfo.passStatus = securityInfo.toObject().value("passStatus").toInt();
                         result[i].securityInfo.passTime = securityInfo.toObject().value("passTime").toString();
                         result[i].securityInfo.gateNo = securityInfo.toObject().value("gateNo").toString();
                         result[i].securityInfo.deviceId = securityInfo.toObject().value("deviceId").toString();
                         result[i].securityInfo.channelName = securityInfo.toObject().value("channelName").toString();
                         result[i].securityInfo.photoPath = securityInfo.toObject().value("photoPath").toString();
                     } else {
                         result[i].hasSecurityInfo = false;
                     }
                     QJsonValue reviewInfo = array.at(i).toObject().value("reviewInfo");
                     if (!reviewInfo.isNull() && !reviewInfo.isUndefined()) {
                         result[i].hasReviewInfo = true;
                         result[i].reviewInfo.passType = reviewInfo.toObject().value("passType").toInt();
                         result[i].reviewInfo.passStatus = reviewInfo.toObject().value("passStatus").toInt();
                         result[i].reviewInfo.passTime = reviewInfo.toObject().value("passTime").toString();
                         result[i].reviewInfo.gateNo = reviewInfo.toObject().value("gateNo").toString();
                         result[i].reviewInfo.deviceId = reviewInfo.toObject().value("deviceId").toString();
                         result[i].reviewInfo.channelName = reviewInfo.toObject().value("channelName").toString();
                         result[i].reviewInfo.photoPath = reviewInfo.toObject().value("photoPath").toString();
                     } else {
                         result[i].hasReviewInfo = false;
                     }
                     QJsonValue transferInfo = array.at(i).toObject().value("transferInfo");
                     if (!transferInfo.isNull() && !transferInfo.isUndefined()) {
                         result[i].hasTransferInfo = true;
                         result[i].transferInfo.sourceType = transferInfo.toObject().value("sourceType").toInt();
                         result[i].transferInfo.photoPath = transferInfo.toObject().value("photoPath").toString();
                         result[i].transferInfo.collectTime = transferInfo.toObject().value("collectTime").toString();
                         result[i].transferInfo.gateNo = transferInfo.toObject().value("gateNo").toString();
                         result[i].transferInfo.deviceId = transferInfo.toObject().value("deviceId").toString();
                         result[i].transferInfo.channelName = transferInfo.toObject().value("channelName").toString();
                         result[i].transferInfo.flightNo = transferInfo.toObject().value("flightNo").toString();
                     } else {
                         result[i].hasTransferInfo = false;
                     }
                     QJsonValue boardingInfo = array.at(i).toObject().value("boardingInfo");
                     if (!boardingInfo.isNull() && !boardingInfo.isUndefined()) {
                         result[i].hasBoardingInfo = true;
                         result[i].boardingInfo.passType = boardingInfo.toObject().value("passType").toInt();
                         result[i].boardingInfo.passStatus = boardingInfo.toObject().value("passStatus").toInt();
                         result[i].boardingInfo.passTime = boardingInfo.toObject().value("passTime").toString();
                         result[i].boardingInfo.gateNo = boardingInfo.toObject().value("gateNo").toString();
                         result[i].boardingInfo.deviceId = boardingInfo.toObject().value("deviceId").toString();
                         result[i].boardingInfo.channelName = boardingInfo.toObject().value("channelName").toString();
                         result[i].boardingInfo.photoPath = boardingInfo.toObject().value("photoPath").toString();
                     } else {
                         result[i].hasBoardingInfo = false;
                     }
                 }
             }
         }
         if (docObj.contains("isBaby")) {
             isBaby = docObj.value("isBaby").toInt();
         }
     }
 };


 struct FlowReviewRequest {
     QString input;
 } ;

 struct FlowReviewResponse {
     QJsonDocument doc;
     int errorCode;
     bool founded;
     FlowReviewInterface interface;

     void update(QJsonDocument &doc_tmp) {
         this->doc = doc_tmp;

         QJsonObject docObj = doc_tmp.object();

         QJsonValue resultJson;
         if (docObj.contains("result")) {
             resultJson = docObj.value("result");
         }

         if (resultJson == QJsonValue()) {
             founded = false;
         }

         interface.update(doc_tmp);
     }

     FlowReviewResponse () {
         doc = QJsonDocument();
         errorCode = -1;
         founded = true;
     }
 };

 /******************************************************************************************************/



#endif // API_PARAM_DEF_H
