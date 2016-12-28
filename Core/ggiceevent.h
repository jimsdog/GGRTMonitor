#ifndef GGICEEVENT_H
#define GGICEEVENT_H

#include <Ice/Ice.h>

#include <QObject>
#include <QEvent>

const int GGICE_EVENT_TYPE = QEvent::User + 1000;

class GGICEEvent : public QEvent
{
public:
    GGICEEvent(const Ice::DispatcherCallPtr&, const Ice::ConnectionPtr&);

    Ice::DispatcherCallPtr call() const;

    Ice::ConnectionPtr connection() const;


private:
    const Ice::DispatcherCallPtr    _call;
    const Ice::ConnectionPtr        _connection;
};

#endif // GGICEEVENT_H
