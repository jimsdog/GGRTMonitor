#include "ggdispatcher.h"
#include "ggiceevent.h"
#include <QApplication>

GGDispatcher::GGDispatcher(QObject* receiver)
    : _receiver(receiver),
      _exit(false)
{

}

GGDispatcher::~GGDispatcher()
{

}

void GGDispatcher::exit()
{
    _exit = true;
}

void GGDispatcher::dispatch(const Ice::DispatcherCallPtr& call, const Ice::ConnectionPtr& conn)
{
    assert(_receiver);
    if(_exit) // The GUI is being destroyed, don't use the GUI thread any more
    {
        call->run();
    }
    else
    {
        QCoreApplication::postEvent(_receiver, new GGICEEvent(call, conn));
    }
}
