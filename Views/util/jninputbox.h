#ifndef JNINPUTBOX_H
#define JNINPUTBOX_H

#include <QDialog>

namespace Ui {
class JNInputBox;
}

class JNInputBox : public QDialog
{
    Q_OBJECT

public:
    explicit JNInputBox(QWidget *parent = 0);
    ~JNInputBox();

public:
    void SetMessage(QString title);
    QString GetValue() const;

private:
    void InitStyle();   //初始化无边框窗体
    QString value;

private slots:
    void on_btnOk_clicked();

private:
    Ui::JNInputBox *ui;
};

#endif // JNINPUTBOX_H
