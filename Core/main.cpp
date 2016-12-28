#include "ggmain.h"
#include <QApplication>
#include "ggapp.h"

int main(int argc, char *argv[])
{
    GGApp app(argc, argv);
    app.setStyleSheet("QStatusBar::item{ border: 0px solid black; }");

    return app.exec();
}
