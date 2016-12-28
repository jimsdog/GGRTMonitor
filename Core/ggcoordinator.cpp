#include "ggcoordinator.h"
#include "ggiceevent.h"
#include <QTextStream>

using namespace std;

GGCoordinator::GGCoordinator(QObject *parent) : QObject(parent)
{

}

bool GGCoordinator::event(QEvent* event)
{
    if(event->type() != GGICE_EVENT_TYPE)
    {
        return QObject::event(event);
    }

    GGICEEvent* iceEvent = dynamic_cast<GGICEEvent*>(event);
    assert(iceEvent);
    Ice::DispatcherCallPtr call = iceEvent->call();
    assert(call);
    try
    {
        call->run();
    }
    catch(const Ice::Exception& ex)
    {
        ostringstream error;
        error << "Ice::DispatcherCall (Ice::Exception):\n" << ex;
        setError(error.str());
    }
    catch(const exception& ex)
    {
        ostringstream error;
        error << "Ice::DispatcherCall (std::exception):\n" << ex.what();
        setError(error.str());
    }
    catch(const string& ex)
    {
        ostringstream error;
        error << "Ice::DispatcherCall (std::string):\n" << ex;
        setError(error.str());
    }
    catch(const char* ex)
    {
        ostringstream error;
        error << "Ice::DispatcherCall (const char*):\n" << ex;
        setError(error.str());
    }
    catch(...)
    {
        ostringstream error;
        error << "Ice::DispatcherCall (unknown C++ exception).";
        setError(error.str());
    }
    return true;
}
