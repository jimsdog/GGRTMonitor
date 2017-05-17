/****************************************************************************
**
** Copyright (C) 2017 JIMSDOG
**
** ECFramework is a frameworke based on Qt5.3, you will be more efficient with it.
**
** Version	: 0.0.1.0
** Author	: Jimsdog
** Website	: https://github.com/jimsdog
** Project	: https://github.com/jimsdog/GGRTMonitor
** Blog		: http://www.jimsdog.com
** Wiki		: https://github.com/jimsdog/GGRTMonitor/wiki
** Lincence: LGPL V2
** QQ: 363280425
** Email: jims@jimsdog.com  mr.oldbig@gmail.com  jims.007007@163.com
**
****************************************************************************/

#include <QtCore>

#include <sapi.h>
#include <sphelper.h>
#include <comdef.h>


#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "ECSpeech.h"

namespace ECFramework
{

#define Where QString("%1:%2:").arg(__FILE__).arg(__LINE__)
#define SysCall(x,e) {\
    HRESULT hr = x;\
    if (FAILED(hr)) {\
        QString msg = #e;\
        msg += ":"+QString(__FILE__);\
        msg += ":"+QString::number(__LINE__)+":"+#x+":";\
        msg += QString::fromWCharArray(_com_error(hr).ErrorMessage());\
        throw e(msg);\
    }\
}

class ECSpeech::Private {
public:
    Private()
        :onFinishSlot(0L),waitingFinish(false) {}

    VoiceName name;

    static const QString VoiceId;
    typedef QPointer<ECSpeech> Ptr;
    static QList<Ptr> ptrs;

    CComPtr<ISpVoice> voice;

    const char * onFinishSlot;
    QPointer<QObject> onFinishObj;
    bool waitingFinish;

    class WCHAR_Holder {
    public:
        WCHAR * w;
        WCHAR_Holder(QString s)
            :w(0) {
            w = new WCHAR[s.length()+1];
            s.toWCharArray(w);
            w[s.length()] =0;
        }

        ~WCHAR_Holder() { delete[] w; }
    };
};
const QString ECSpeech::Private::VoiceId = QString("win:%1");
QList<ECSpeech::Private::Ptr> ECSpeech::Private::ptrs = QList<ECSpeech::Private::Ptr>();

ECSpeech::ECSpeech(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
    CoInitialize(NULL);
    SysCall( d->voice.CoCreateInstance( CLSID_SpVoice ), InitError);

    VoiceName n;
    WCHAR * w_id = 0L;
    WCHAR * w_name = 0L;
    CComPtr<ISpObjectToken> voice;
    SysCall( d->voice->GetVoice(&voice), InitError);
    SysCall( SpGetDescription(voice, &w_name), InitError);
    SysCall( voice->GetId(&w_id), InitError);
    n.name = QString::fromWCharArray(w_name);
    n.id = QString::fromWCharArray(w_id);
    voice.Release();

    if (n.id.isEmpty())
        throw InitError(Where+"No default voice in system");

    d->name = n;
    d->ptrs << this;
}

ECSpeech::ECSpeech(VoiceName n, QObject * parent)
    :QObject(parent), d(new Private)
{
    ULONG count = 0;
    CComPtr<IEnumSpObjectTokens> voices;

    CoInitialize(NULL);
    SysCall( d->voice.CoCreateInstance( CLSID_SpVoice ), InitError);

    if (n.id.isEmpty()) {
        WCHAR * w_id = 0L;
        WCHAR * w_name = 0L;
        CComPtr<ISpObjectToken> voice;
        SysCall( d->voice->GetVoice(&voice), InitError);
        SysCall( SpGetDescription(voice, &w_name), InitError);
        SysCall( voice->GetId(&w_id), InitError);
        n.name = QString::fromWCharArray(w_name);
        n.id = QString::fromWCharArray(w_id);
        voice.Release();
    }
    else {
        SysCall( SpEnumTokens(SPCAT_VOICES, NULL, NULL, &voices), InitError);
        SysCall( voices->GetCount(&count), InitError);
        for (ULONG i =0; i< count; i++) {
            WCHAR * w_id = 0L;
            CComPtr<ISpObjectToken> voice;
            SysCall( voices->Next( 1, &voice, NULL ), InitError);
            SysCall( voice->GetId(&w_id), InitError);
            QString id = QString::fromWCharArray(w_id);
            if (id == n.id) d->voice->SetVoice(voice);
            voice.Release();
        }
    }

    if (n.id.isEmpty())
        throw InitError(Where+"No default voice in system");

    d->name = n;
    d->ptrs << this;
}

ECSpeech::~ECSpeech()
{
    d->ptrs.removeAll(this);
    delete d;
}

const ECSpeech::VoiceName & ECSpeech::name() const {
    return d->name;
}

ECSpeech::VoiceNames ECSpeech::voices()
{
    VoiceNames vs;
    ULONG count = 0;
    CComPtr<IEnumSpObjectTokens> voices;

    CoInitialize(NULL);
    SysCall( SpEnumTokens(SPCAT_VOICES, NULL, NULL, &voices), LogicError);
    SysCall( voices->GetCount(&count), LogicError);

    for(ULONG i=0; i< count; i++) {
        WCHAR * w_id = 0L;
        WCHAR * w_name = 0L;
        CComPtr<ISpObjectToken> voice;
        SysCall( voices->Next( 1, &voice, NULL ), LogicError);
        SysCall( SpGetDescription(voice, &w_name), LogicError);
        SysCall( voice->GetId(&w_id), LogicError);

        QString id = QString::fromWCharArray(w_id);
        QString name = QString::fromWCharArray(w_name);
        VoiceName n = { id, name };
        vs << n;

        voice.Release();
    }
    return vs;
}

void ECSpeech::tell(QString text) const {
    tell(text, 0L,0L);
}

void ECSpeech::tell(QString text, QObject * obj, const char * slot) const
{
    if (d->waitingFinish) {
        //throw LogicError(Where+"Already waiting to finish speech");
        //win api to stop any existing speech going
        HRESULT hr = d->voice->Speak( NULL, SPF_PURGEBEFORESPEAK, 0 );
            if (FAILED( hr )) qDebug() << "sapi51: stop is not completed";
    }

    d->onFinishObj = obj;
    d->onFinishSlot = slot;
    if (obj && slot)
        connect(const_cast<ECSpeech *>(this), SIGNAL(finished()), obj, slot);

    d->waitingFinish = true;
    const_cast<ECSpeech *>(this)->startTimer(100);

    Private::WCHAR_Holder w_text(text);
    SysCall( d->voice->Speak( w_text.w, SPF_ASYNC | SPF_IS_NOT_XML, 0), LogicError);
}

void ECSpeech::say(QString text) const
{
    Private::WCHAR_Holder w_text(text);
    SysCall( d->voice->Speak( w_text.w, SPF_IS_NOT_XML, 0), LogicError);
}

void ECSpeech::timerEvent(QTimerEvent * te)
{
    QObject::timerEvent(te);

    if (d->waitingFinish) {
        SPVOICESTATUS es;
        d->voice->GetStatus( &es, NULL );
        if (es.dwRunningState == SPRS_DONE) {
            d->waitingFinish = false;
            killTimer(te->timerId());
            finished();
        }
    }
}

}   //namespace ECFramework
