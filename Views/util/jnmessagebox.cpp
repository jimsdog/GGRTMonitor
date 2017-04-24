#include "jnmessagebox.h"
#include "ui_jnmessagebox.h"

#include "jnhelper.h"
#include "jniconhelper.h"

JNMessageBox::JNMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JNMessageBox)
{
    ui->setupUi(this);
    this->InitStyle();
    JNHelper::FormInCenter(this);
}

JNMessageBox::~JNMessageBox()
{
    delete ui;
}

void JNMessageBox::SetMessage(QString msg, int type)
{
    if (type == 0) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/util/image/msg_info.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText(QString::fromLocal8Bit("提示"));
    } else if (type == 1) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/util/image/msg_question.png);");
        ui->lab_Title->setText(QString::fromLocal8Bit("询问"));
    } else if (type == 2) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/util/image/msg_error.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText(QString::fromLocal8Bit("错误"));
    }

    ui->labInfo->setText(msg);
    this->setWindowTitle(ui->lab_Title->text());
}

void JNMessageBox::InitStyle()
{
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图形字体
    JNIconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015));
    JNIconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d));
    //关联关闭按钮
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void JNMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}
