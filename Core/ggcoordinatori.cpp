#include "ggcoordinatori.h"
#include "monitorcallbacki.h"
#include "connectasynccallback.h"

#include <./generated/GGConfig.h>
#include <./generated/GGSmart.h>
#include <./generated/GGMonitorSession.h>

#include <./Views/util/jnhelper.h>



using namespace GGSmart;

GGCoordinatorI::GGCoordinatorI(LoginView* loginView, int argc, char** argv)
    : _exit(false),
      _loginView(loginView)
{
    Ice::InitializationData initData;
    initData.properties = Ice::createProperties(argc, argv);

    _dispatcher = new GGDispatcher(this);
    initData.dispatcher = _dispatcher;

    if(initData.properties->getProperty("Ice.Default.Router").empty())
    {
        initData.properties->setProperty("Ice.Default.Router", GLACIER2SERVER);
    }

    _factory = new Glacier2::SessionFactoryHelper(initData, this);
    setState(Disconnected);
}


//-------------------------------------private functions

void GGCoordinatorI::destroySession()
{
    if(_session)
    {
        setState(Disconnecting);
        _session->destroy();
    }
}

void GGCoordinatorI::destroySession(const Ice::Exception&)
{
    //_chatView->setEnabled(false);
    if(_session)
    {
        _session->destroy();
    }
}

//-------------------------------------virtual slot functions

void GGCoordinatorI::login(const LoginInfoPtr& info)
{
    qDebug("GGCoordinatorI::login begin");
    setState(Connecting);
    _info = info;
    _session = _factory->connect(info->username(), info->password());
    qInfo("GGCoordinatorI::login end");
}

void GGCoordinatorI::login()
{
    setState(Disconnected);
}

void GGCoordinatorI::logout()
{
    destroySession();
}

void GGCoordinatorI::setError(const std::string& err)
{
    qWarning(err.c_str());
}

//-------------------------------------Comm virtual functions

void GGCoordinatorI::setState(Glacier2ClientState state)
{
    //此处处理ICE状态改变的逻辑
    _state = state;
    if(state == Connecting)
    {
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

    }
    else if(state == Connected)
    {
        QApplication::restoreOverrideCursor();

    }
}

void GGCoordinatorI::exit()
{
    _exit = true;
    _dispatcher->exit();
    Ice::CommunicatorPtr communicator = _session ? _session->communicator() : static_cast<Ice::CommunicatorPtr>(0);

    logout();

    if(communicator)
    {
        communicator->waitForShutdown();
    }

    _factory->destroy();
}
//-------------------------------------

//-------------------------------------Glacier2 virtual functions
void GGCoordinatorI::createdCommunicator(const SessionHelperPtr& session)
{
    if(session != _session)
    {
        return;
    }
}

void GGCoordinatorI::connected(const SessionHelperPtr& session)
{
    qInfo("GGCoordinatorI::connected");

    if(_exit)
    {
        return;
    }
    if(_session != session)
    {
        return;
    }

    _info->save();
    _id = _info->username();

    GGSmart::MonitorCallbackPrx callback = GGSmart::MonitorCallbackPrx::uncheckedCast(
                _session->addWithUUID(new MonitorCallbackI(this, _id)));
    GGSmart::MonitorSessionPrx monitor = GGSmart::MonitorSessionPrx::uncheckedCast(_session->session());

    try
    {
        GGSmart::Callback_MonitorSession_SetCallbackPtr cb = GGSmart::newCallback_MonitorSession_SetCallback(
                    new ConnectAsyncCallback(this),
                    &ConnectAsyncCallback::response, &ConnectAsyncCallback::exception);
        monitor->begin_SetCallback(callback, _id, cb);

        qInfo("GGCoordinatorI begin_SetCallback success");
    }
    catch(const Ice::CommunicatorDestroyedException&)
    {
        // Ignored the application is being shutdown.
        qInfo("GGCoordinatorI begin_SetCallback faulure");
    }
}

void GGCoordinatorI::disconnected(const SessionHelperPtr& session)
{
    if(_exit)
    {
        return;
    }
    if(session != _session)
    {
        return;
    }
    _session = 0;
    setState(Disconnected);
}

void GGCoordinatorI::connectFailed(const SessionHelperPtr& session, const Ice::Exception& ex)
{
    if(_exit)
    {
        return;
    }
    if(session != _session)
    {
        return;
    }
    _session = 0;
    setState(Disconnected);
    try
    {
        ex.ice_throw();
    }
    catch(const Glacier2::CannotCreateSessionException& ex)
    {
        ostringstream os;
        os << "Login failed (Glacier2::CannotCreateSessionException):\n" << ex.reason;
        setError(os.str());
    }
    catch(const Glacier2::PermissionDeniedException& ex)
    {
        ostringstream os;
        os << "Login failed (Glacier2::PermissionDeniedException):\n" << ex.reason;

        setError(os.str());
    }
    catch(const Ice::Exception& ex)
    {
        ostringstream os;
        os << "Login failed ("<< ex.ice_name() << ").\n"
           << "Please check your configuration.";

        setError(os.str());
    }
}
//-------------------------------------
