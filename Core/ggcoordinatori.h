#ifndef GGCOORDINATORI_H
#define GGCOORDINATORI_H


#include <QObject>

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <Glacier2/Glacier2.h>
#include <Glacier2/SessionHelper.h>

#include "ggcoordinator.h"
#include "ggdispatcher.h"
#include "ggcommdefine.h"
#include "connectasynccallback.h"
#include "Views/loginview.h"


using namespace Glacier2;
using namespace Ice;
using namespace std;



class GGCoordinatorI : public GGCoordinator
{
public:
    GGCoordinatorI(LoginView* loginView, int argc, char** argv);




public:
    virtual void setState(Glacier2ClientState);
    virtual void exit();

public:
    virtual void createdCommunicator(const SessionHelperPtr& session);
    virtual void connected(const SessionHelperPtr&);
    virtual void disconnected(const SessionHelperPtr&);
    virtual void connectFailed(const SessionHelperPtr&, const Ice::Exception&);

signals:


public slots:

    virtual void login(const LoginInfoPtr& info);
    virtual void login();
    virtual void logout();
    virtual void setError(const std::string&);

private:

    virtual void destroySession();

    virtual void destroySession(const Ice::Exception&);


private:

    Glacier2::SessionHelperPtr _session;
    Glacier2::SessionFactoryHelperPtr _factory;

    //----------------ui
    LoginView* _loginView;
    //----------------

    std::string _id;
    LoginInfoPtr _info;

    GGDispatcherPtr _dispatcher;
    Glacier2ClientState _state;
    bool _exit;

};

#endif // GGCOORDINATORI_H
