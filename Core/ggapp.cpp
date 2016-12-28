#include "ggapp.h"
#include "ggcommdefine.h"

#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>

#include "ggcoordinatori.h"
#include "loginview.h"



GGApp::GGApp(int argc, char** argv)
    : QApplication(argc, argv)
{
    QCoreApplication::setOrganizationName(ORGANIZATION);
    QCoreApplication::setOrganizationDomain(ORGANIZATIONDOMAIN);
    QCoreApplication::setApplicationName(APPLICATION);

    LoginView* loginView = new LoginView(0);
    _coordinator = new GGCoordinatorI(loginView, argc, argv);

    connect(loginView, SIGNAL(login(const LoginInfoPtr&)),
            _coordinator.get(), SLOT(login(const LoginInfoPtr&)));

    //----------
    QPixmap pixmap(":/image/ui/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();

    //----------
    QEventLoop eventloop;
    QTimer::singleShot(2000, &eventloop, SLOT(quit())); //wait 2s
    eventloop.exec();
    //----------end added code

    splash.finish(loginView);
    loginView->show();

}

void GGApp::shutdown()
{

}
