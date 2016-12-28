#ifndef CONNECTASYNCCALLBACK_H
#define CONNECTASYNCCALLBACK_H


#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>

#include "ggcoordinator.h"

using namespace Ice;

class ConnectAsyncCallback : public IceUtil::Shared
{
public:
    ConnectAsyncCallback(const GGCoordinatorPtr& coordinator);

public:

    void response();

    void exception(const Ice::Exception& ex);

private:

    const GGCoordinatorPtr _coordinator;
};

#endif // CONNECTASYNCCALLBACK_H
