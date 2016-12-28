#ifndef GGMAIN_H
#define GGMAIN_H

#include <QDialog>

namespace Ui {
class GGMain;
}

class GGMain : public QDialog
{
    Q_OBJECT

public:
    explicit GGMain(QWidget *parent = 0);
    ~GGMain();

private:
    Ui::GGMain *ui;
};

#endif // GGMAIN_H
