#include "loginview.h"
#include "ui_loginview.h"

#include <QKeyEvent>

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    _info(new LoginInfo()),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);

    _info->load();

    setWindowTitle(tr("Googol Monitor"));
    setWindowIcon(QIcon(":/image/ui/logo.png"));

    this->ui->userName->installEventFilter(this);
    this->ui->passWord->installEventFilter(this);
    this->ui->passWord->setEchoMode(QLineEdit::Password);

    this->ui->pbLogin->setDefault(true);

    connect(this->ui->pbLogin, SIGNAL(clicked()), this, SLOT(login()));
    connect(this->ui->pbExit, SIGNAL(clicked()), this, SLOT(close()));
    //connect(this->ui->passWord,SIGNAL(returnPressed()),ui->pbLogin,SLOT(setChecked(bool)));
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
                    //this->ui->pbLogin->setFocus();
                    login();
                }
                return true;
            }
        }
    }
    return QWidget::eventFilter(target, event);
}
