#include "monitorcallbacki.h"

MonitorCallbackI::MonitorCallbackI(const GGCoordinatorPtr& coordinator, const std::string& id)
    : _coordinator(coordinator),
      _id(id)
{
}

void MonitorCallbackI::updateRobotInfo(const ::GGSmart::RobotPtr&, const ::Ice::Current&)
{
    qDebug("MonitorCallbackI::updateRobotInfo");
}

void MonitorCallbackI::robotJoin(const ::GGSmart::RobotPtr&, const ::Ice::Current&)
{
    qDebug("MonitorCallbackI::robotJoin");
}

void MonitorCallbackI::robotLeave(const ::std::string&, const ::Ice::Current&)
{
    qDebug("MonitorCallbackI::robotLeave");
}

void MonitorCallbackI::pushAllOnlineRobots(const ::GGSmart::RobotSeq&, const ::Ice::Current&)
{
    qDebug("MonitorCallbackI::pushAllOnlineRobots");
}
