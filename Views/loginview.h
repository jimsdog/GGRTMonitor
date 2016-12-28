#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include "logininfo.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = 0);
    ~LoginView();

public:

    bool eventFilter(QObject* target, QEvent* event);

    void setFocus();

private slots:

    void login();

signals:

    void login(const LoginInfoPtr&);

private:

    LoginInfoPtr _info;

    Ui::LoginView *ui;
};

#endif // LOGINVIEW_H
