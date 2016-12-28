#include "jnhelper.h"
#include <QTextCodec>

#include "jninputbox.h"
#include "jnmessagebox.h"

JNHelper::JNHelper(QObject *parent) : QObject(parent)
{

}

//设置为开机启动
void JNHelper::AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath) {
    QSettings *reg = new QSettings(
        "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
        QSettings::NativeFormat);

    if (IsAutoRun) {
        reg->setValue(AppName, AppPath);
    } else {
        reg->setValue(AppName, "");
    }
}

//设置编码为UTF8
void JNHelper::SetUTF8Code()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#endif
}

//设置指定样式
void JNHelper::SetStyle(const QString &qssFile) {
    QFile file(qssFile);
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        QString PaletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(PaletteColor)));
        file.close();
    }
}

//加载中文字符
void JNHelper::SetChinese() {
    QTranslator *translator = new QTranslator(qApp);
    translator->load(":/image/qt_zh_CN.qm");
    qApp->installTranslator(translator);
}

//判断是否是IP地址
bool JNHelper::IsIP(QString IP) {
    QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    return RegExp.exactMatch(IP);
}

//显示输入框
QString JNHelper::ShowInputBox(QString info, bool &ok) {
    JNInputBox input;
    input.SetMessage(info);
    ok = input.exec();
    return input.GetValue();
}

//显示信息框,仅确定按钮
void JNHelper::ShowMessageBoxInfo(QString info) {
    JNMessageBox msg;
    msg.SetMessage(info, 0);
    msg.exec();
}

//显示错误框,仅确定按钮
void JNHelper::ShowMessageBoxError(QString info) {
    JNMessageBox msg;
    msg.SetMessage(info, 2);
    msg.exec();
}

//显示询问框,确定和取消按钮
int JNHelper::ShowMessageBoxQuesion(QString info) {
    JNMessageBox msg;
    msg.SetMessage(info, 1);
    return msg.exec();
}

//延时
void JNHelper::Sleep(int sec) {
    /*QTime dieTime = QTime::currentTime().addMSecs(sec);
    while ( QTime::currentTime() < dieTime ) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }*/
    QEventLoop eventloop;
    QTimer::singleShot(sec, &eventloop, SLOT(quit())); //wait 2s
    eventloop.exec();
}

//窗体居中显示
void JNHelper::FormInCenter(QWidget *frm) {
    int frmX = frm->width();
    int frmY = frm->height();
    QDesktopWidget w;
    int deskWidth = w.availableGeometry().width();
    int deskHeight = w.availableGeometry().height();
    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    frm->move(movePoint);
}









