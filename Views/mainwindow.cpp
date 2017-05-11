

#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :ECMainWindow(parent)
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());

    resize(desktopWidget->availableGeometry().size()* 0.6);
}
/*
void MainWindow::resizeEvent(QResizeEvent *event)
{
    ECMainWindow::resizeEvent(event);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    ECMainWindow::mouseDoubleClickEvent(event);
}*/
