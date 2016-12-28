#ifndef GGAPP_H
#define GGAPP_H

#include <QApplication>
#include "ggcoordinator.h"


class GGApp : public QApplication
{
    Q_OBJECT
public:

    GGApp(int argc, char** argv);

public slots:

    void shutdown();

private:

    GGCoordinatorPtr _coordinator;

};

#endif // GGAPP_H
