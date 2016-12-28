#include "connectasynccallback.h"

ConnectAsyncCallback::ConnectAsyncCallback(const GGCoordinatorPtr& coordinator)
    : _coordinator(coordinator)
{

}


void ConnectAsyncCallback::response()
{
    _coordinator->setState(Connected);
}


void ConnectAsyncCallback::exception(const Ice::Exception& ex)
{
    _coordinator->destroySession(ex);
}
