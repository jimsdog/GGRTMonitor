#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "ECMainWindow.h"

using namespace ECFramework;

class MainWindow : public ECMainWindow
{
    Q_OBJECT
private:
protected:
    /*void resizeEvent(QResizeEvent * event);
    void mouseDoubleClickEvent(QMouseEvent *event);*/
public:
    explicit MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
