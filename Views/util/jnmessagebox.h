#ifndef JNMESSAGEBOX_H
#define JNMESSAGEBOX_H

#include <QDialog>

namespace Ui {
class JNMessageBox;
}

class JNMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit JNMessageBox(QWidget *parent = 0);
    ~JNMessageBox();

public:

    void SetMessage(QString msg, int type);

private slots:
    void on_btnOk_clicked();

private:

    //初始化无边框窗体
    void InitStyle();

private:
    Ui::JNMessageBox *ui;
};

#endif // JNMESSAGEBOX_H
