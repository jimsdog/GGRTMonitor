#ifndef MONITORCALLBACKI_H
#define MONITORCALLBACKI_H

#include <string>
#include <IceUtil/IceUtil.h>
#include <GGMonitorSession.h>
#include <ggcoordinator.h>

using namespace GGSmart;

class MonitorCallbackI : public GGSmart::MonitorCallback
{
public:
    MonitorCallbackI(const GGCoordinatorPtr& coordinator, const std::string& id);
public:

    virtual void updateRobotInfo(const ::GGSmart::RobotPtr&, const ::Ice::Current& = ::Ice::Current());

    virtual void robotJoin(const ::GGSmart::RobotPtr&, const ::Ice::Current& = ::Ice::Current());

    virtual void robotLeave(const ::std::string&, const ::Ice::Current& = ::Ice::Current());

    virtual void pushAllOnlineRobots(const ::GGSmart::RobotSeq&, const ::Ice::Current& = ::Ice::Current());

private:

    const GGCoordinatorPtr _coordinator;
    const std::string _id;
};

typedef IceUtil::Handle<MonitorCallbackI> MonitorCallbackIPtr;

#endif // MONITORCALLBACKI_H
