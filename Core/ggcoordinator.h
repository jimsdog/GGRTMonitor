#ifndef GGCOORDINATOR_H
#define GGCOORDINATOR_H

#include <QObject>

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <Glacier2/Glacier2.h>
#include <Glacier2/SessionHelper.h>

#include "logininfo.h"



using namespace Glacier2;

enum Glacier2ClientState
{
    Disconnected,   //断开状态
    Connecting,     //连接中状态
    Connected,      //连接成功
    Disconnecting
};

class GGCoordinator : public QObject, public Glacier2::SessionCallback
{
    Q_OBJECT
public:
    explicit GGCoordinator(QObject *parent = 0);

    bool event(QEvent*);

public:

    virtual void setState(Glacier2ClientState) = 0;
    virtual void exit() = 0;

public:
    virtual void createdCommunicator(const SessionHelperPtr& session) = 0;
    virtual void connected(const SessionHelperPtr&) = 0;
    virtual void disconnected(const SessionHelperPtr&) = 0;
    virtual void connectFailed(const SessionHelperPtr&, const Ice::Exception&) = 0;

private:
    virtual void destroySession() = 0;

    virtual void destroySession(const Ice::Exception&) = 0;

signals:

public slots:

    virtual void login(const LoginInfoPtr& info) = 0;
    virtual void login() = 0;
    virtual void logout() = 0;
    virtual void setError(const std::string&) = 0;



    friend class ConnectAsyncCallback;
};

typedef IceUtil::Handle<GGCoordinator> GGCoordinatorPtr;

#endif // GGCOORDINATOR_H
