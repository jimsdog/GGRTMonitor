#include "jniconhelper.h"

#include "jnappconfig.h"


JNIconHelper *JNIconHelper::_instance = 0;
JNIconHelper::JNIconHelper(QObject *parent) : QObject(parent)
{
    int fontId = QFontDatabase::addApplicationFont(":/image/util/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}

JNIconHelper *JNIconHelper::Instance() {
    static QMutex mutex;
    if (!_instance) {
        QMutexLocker locker(&mutex);
        if (!_instance) {
            _instance = new JNIconHelper;
        }
    }
    return _instance;
}

void JNIconHelper::SetIcon(QLabel *lab, QChar c)
{
    iconFont.setPointSize(JNAppConfig::AppFontSize);
    lab->setFont(iconFont);
    lab->setText(c);
}

void JNIconHelper::SetIcon(QPushButton *btn, QChar c)
{
    iconFont.setPointSize(JNAppConfig::AppFontSize);
    btn->setFont(iconFont);
    btn->setText(c);
}
