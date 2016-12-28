#include "ggiceevent.h"

GGICEEvent::GGICEEvent(const Ice::DispatcherCallPtr& call, const Ice::ConnectionPtr& connection)
    : QEvent(QEvent::Type(GGICE_EVENT_TYPE)),
      _call(call),
      _connection(connection)
{

}


Ice::DispatcherCallPtr GGICEEvent::call() const
{
    return _call;
}

Ice::ConnectionPtr GGICEEvent::connection() const
{
    return _connection;
}
