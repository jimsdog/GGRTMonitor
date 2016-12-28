#include "ggmain.h"
#include <QApplication>
#include "ggapp.h"
#include <./Util/jnqtlogger.h>

int main(int argc, char *argv[])
{
    JNQTLogger::SetUpLogger();
    GGApp app(argc, argv);
    app.setStyleSheet("QStatusBar::item{ border: 0px solid black; }");

    return app.exec();
}
