#ifndef WORKANOTHERTHREAD_H
#define WORKANOTHERTHREAD_H

#include <QObject>
#include <ServerInterface/api_param_def.h>

class WorkAnotherThread: public QObject
{
    Q_OBJECT
public:
    WorkAnotherThread();
    virtual ~WorkAnotherThread();

public slots:
    void on_getFlightPlane();
    void on_GateCtrl(const int GateChannelNO, gateWorkStatus workStat, gateDoorStatus doorStat);
signals:
    void results_flightPlane(API_PARAM_TYPE type, void *userData);

private:
    FlightPlan m_flightPlan;
};


#endif // WORKANOTHERTHREAD_H
