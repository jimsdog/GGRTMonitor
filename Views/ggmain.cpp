#include "ggmain.h"
#include "ui_ggmain.h"

GGMain::GGMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GGMain)
{
    ui->setupUi(this);
}

GGMain::~GGMain()
{
    delete ui;
}
