#include "loginview.h"
#include "ui_loginview.h"

#include <QKeyEvent>

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);

    this->ui->userName->installEventFilter(this);
    this->ui->passWord->installEventFilter(this);
    this->ui->passWord->setEchoMode(QLineEdit::Password);

    this->ui->pbLogin->setDefault(true);

    connect(this->ui->pbLogin, SIGNAL(clicked()), this, SLOT(login()));
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::setFocus()
{
    this->ui->userName->setFocus();
}

void LoginView::login()
{
    _info->setUsername(this->ui->userName->text().toUtf8().data());
    _info->setPassword(this->ui->passWord->text().toUtf8().data());
    emit login(_info);
}

bool LoginView::eventFilter(QObject* target, QEvent* event)
{
    if(target == this->ui->userName || target == this->ui->passWord)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            assert(keyEvent);
            if(keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
            {
                if(target == this->ui->userName)
                {
                    this->ui->passWord->setFocus();
                }
                else if(target == this->ui->passWord)
                {
                    this->ui->pbLogin->setFocus();
                }
                return true;
            }
        }
    }
    return QWidget::eventFilter(target, event);
}
