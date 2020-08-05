#include "workanotherthread.h"
#include "homepage.h"
#include "settings.h"
#include "ServerInterface/httpAPI.h"
#include "ticketScancer/serialportser.h"
#include <QMessageBox>
#include <QDebug>

WorkAnotherThread::WorkAnotherThread()
{
}
WorkAnotherThread::~WorkAnotherThread()
{
}

void WorkAnotherThread::on_getFlightPlane()
{
    QString boardingGateNo = LocalSettings::instance()->value("Device/boardingGateNo").toString();

    Return_Flight_Plan_Param ret = HttpAPI::instance()->getFlightPlan(boardingGateNo);
    if (ret.serverStatus == 0){
        m_flightPlan = ret.flightPlan;

        emit results_flightPlane(FLIGHT_PALNE, &m_flightPlan);

        if (HomePage::s_mode == 0){
            HomePage::s_type = HomePage::global_instance->m_RealtimeBoarding->m_boardingMode;
            HomePage::s_status = m_flightPlan.status;
            HttpAPI::instance()->pushPlan(1, m_flightPlan, HomePage::s_mode, HomePage::s_type,  HomePage::s_collectType, m_flightPlan.status);
            HttpAPI::instance()->pushPlan(2, m_flightPlan, HomePage::s_mode, HomePage::s_type,  HomePage::s_collectType, m_flightPlan.status);
        }
    }
}

void WorkAnotherThread::on_GateCtrl(const int GateChannelNO, gateWorkStatus workStat, gateDoorStatus doorStat)
{
    HttpAPI::instance()->GateCtrl(GateChannelNO, workStat, doorStat);
}
