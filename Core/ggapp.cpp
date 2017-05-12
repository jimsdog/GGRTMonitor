#include "ggapp.h"
#include "ggcommdefine.h"

#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QMessageLogger>

#include "ggcoordinatori.h"
#include "loginview.h"

#include "ectestframe.h"

#include "mainwindow.h"



GGApp::GGApp(int argc, char** argv)
    : QApplication(argc, argv)
{
    /*QCoreApplication::setOrganizationName(ORGANIZATION);
    QCoreApplication::setOrganizationDomain(ORGANIZATIONDOMAIN);
    QCoreApplication::setApplicationName(APPLICATION);*/

    QApplication::setOrganizationName(ORGANIZATION);
    QApplication::setOrganizationDomain(ORGANIZATIONDOMAIN);
    QApplication::setApplicationName(QString::fromLocal8Bit(APPLICATION));

    /*LoginView* loginView = new LoginView(0);
    _coordinator = new GGCoordinatorI(loginView, argc, argv);

    connect(this, SIGNAL(aboutToQuit()), this, SLOT(shutdown()));

    connect(loginView, SIGNAL(login(const LoginInfoPtr&)),
            _coordinator.get(), SLOT(login(const LoginInfoPtr&)));
    connect(loginView, SIGNAL(exit()), this, SLOT(shutdown()));

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
    loginView->show();*/

    //ECTestFrame *ectestframe = new ECTestFrame(0);
    //ectestframe->show();

    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

}

void GGApp::shutdown()
{
    _coordinator->exit();
}
