#ifndef GGDISPATCHER_H
#define GGDISPATCHER_H

#include <QObject>

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>

class GGDispatcher : public Ice::Dispatcher
{
public:
    GGDispatcher(QObject* receiver);

    virtual ~GGDispatcher();

public:

    virtual void dispatch(const Ice::DispatcherCallPtr&, const Ice::ConnectionPtr&);

    void exit();

private:

    QObject* _receiver;
    bool _exit;
};

typedef IceUtil::Handle<GGDispatcher> GGDispatcherPtr;

#endif // GGDISPATCHER_H
