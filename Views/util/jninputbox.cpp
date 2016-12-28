#include "jninputbox.h"
#include "ui_jninputbox.h"

#include "jnhelper.h"
#include "jniconhelper.h"

JNInputBox::JNInputBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JNInputBox)
{
    ui->setupUi(this);

    this->InitStyle();
    JNHelper::FormInCenter(this);
}

JNInputBox::~JNInputBox()
{
    delete ui;
}

QString JNInputBox::GetValue()const {
    return value;
}

void JNInputBox::InitStyle()
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

void JNInputBox::SetMessage(QString title)
{
    ui->labInfo->setText(title);
}

void JNInputBox::on_btnOk_clicked()
{
    value = ui->txtValue->text();
    done(1);
    this->close();
}
