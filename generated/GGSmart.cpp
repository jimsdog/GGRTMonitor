// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.3
//
// <auto-generated>
//
// Generated from file `GGSmart.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <GGSmart.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/BasicStream.h>
#include <Ice/SlicedData.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/PopDisableWarnings.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 3
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

}

namespace
{

const ::IceInternal::DefaultUserExceptionFactoryInit< ::GGSmart::InvokeFailException> __GGSmart__InvokeFailException_init("::GGSmart::InvokeFailException");

}

GGSmart::InvokeFailException::InvokeFailException(const ::std::string& __ice_reason) :
    ::Ice::UserException(),
    reason(__ice_reason)
{
}

GGSmart::InvokeFailException::~InvokeFailException() throw()
{
}

::std::string
GGSmart::InvokeFailException::ice_name() const
{
    return "GGSmart::InvokeFailException";
}

GGSmart::InvokeFailException*
GGSmart::InvokeFailException::ice_clone() const
{
    return new InvokeFailException(*this);
}

void
GGSmart::InvokeFailException::ice_throw() const
{
    throw *this;
}

void
GGSmart::InvokeFailException::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice("::GGSmart::InvokeFailException", -1, true);
    __os->write(reason);
    __os->endWriteSlice();
}

void
GGSmart::InvokeFailException::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->read(reason);
    __is->endReadSlice();
}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::GGSmart::upCast(::IceProxy::GGSmart::GGOrderMsg* p) { return p; }

void
::IceProxy::GGSmart::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::GGSmart::GGOrderMsg>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::GGSmart::GGOrderMsg;
        v->__copyFrom(proxy);
    }
}

const ::std::string&
IceProxy::GGSmart::GGOrderMsg::ice_staticId()
{
    return ::GGSmart::GGOrderMsg::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::GGSmart::GGOrderMsg::__newInstance() const
{
    return new GGOrderMsg;
}
::IceProxy::Ice::Object* ::IceProxy::GGSmart::upCast(::IceProxy::GGSmart::Robot* p) { return p; }

void
::IceProxy::GGSmart::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::GGSmart::Robot>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::GGSmart::Robot;
        v->__copyFrom(proxy);
    }
}

const ::std::string&
IceProxy::GGSmart::Robot::ice_staticId()
{
    return ::GGSmart::Robot::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::GGSmart::Robot::__newInstance() const
{
    return new Robot;
}
::IceProxy::Ice::Object* ::IceProxy::GGSmart::upCast(::IceProxy::GGSmart::SubStation* p) { return p; }

void
::IceProxy::GGSmart::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::GGSmart::SubStation>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::GGSmart::SubStation;
        v->__copyFrom(proxy);
    }
}

const ::std::string&
IceProxy::GGSmart::SubStation::ice_staticId()
{
    return ::GGSmart::SubStation::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::GGSmart::SubStation::__newInstance() const
{
    return new SubStation;
}

::Ice::Object* GGSmart::upCast(::GGSmart::GGOrderMsg* p) { return p; }
::Ice::ObjectPtr
GGSmart::GGOrderMsg::ice_clone() const
{
    ::Ice::Object* __p = new GGOrderMsg(*this);
    return __p;
}

namespace
{
const ::std::string __GGSmart__GGOrderMsg_ids[2] =
{
    "::GGSmart::GGOrderMsg",
    "::Ice::Object"
};

}

bool
GGSmart::GGOrderMsg::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__GGSmart__GGOrderMsg_ids, __GGSmart__GGOrderMsg_ids + 2, _s);
}

::std::vector< ::std::string>
GGSmart::GGOrderMsg::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__GGSmart__GGOrderMsg_ids[0], &__GGSmart__GGOrderMsg_ids[2]);
}

const ::std::string&
GGSmart::GGOrderMsg::ice_id(const ::Ice::Current&) const
{
    return __GGSmart__GGOrderMsg_ids[0];
}

const ::std::string&
GGSmart::GGOrderMsg::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::GGSmart::GGOrderMsg";
    return typeId;
#else
    return __GGSmart__GGOrderMsg_ids[0];
#endif
}

void
GGSmart::GGOrderMsg::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->write(OderProperty);
    __os->write(OderID);
    __os->write(OderType);
    __os->write(RunData);
    __os->write(ExData);
    __os->endWriteSlice();
}

void
GGSmart::GGOrderMsg::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->read(OderProperty);
    __is->read(OderID);
    __is->read(OderType);
    __is->read(RunData);
    __is->read(ExData);
    __is->endReadSlice();
}

namespace
{

const ::IceInternal::DefaultObjectFactoryInit< ::GGSmart::GGOrderMsg> __GGSmart__GGOrderMsg_init("::GGSmart::GGOrderMsg");
}

::Ice::ObjectFactoryPtr
GGSmart::GGOrderMsg::ice_factory()
{
    return ::IceInternal::factoryTable->getObjectFactory(::GGSmart::GGOrderMsg::ice_staticId());
}

void 
GGSmart::__patch(GGOrderMsgPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::GGSmart::GGOrderMsgPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::GGSmart::GGOrderMsg::ice_staticId(), v);
    }
}

::Ice::Object* GGSmart::upCast(::GGSmart::Robot* p) { return p; }

#if defined(_MSC_VER) && (_MSC_VER >= 1900)
#   pragma warning(push)
#   pragma warning(disable:4589)
#endif
::Ice::ObjectPtr
GGSmart::Robot::ice_clone() const
{
    ::Ice::Object* __p = new Robot(*this);
    return __p;
}
#if defined(_MSC_VER) && (_MSC_VER >= 1900)
#   pragma warning(pop)
#endif

namespace
{
const ::std::string __GGSmart__Robot_ids[2] =
{
    "::GGSmart::Robot",
    "::Ice::Object"
};

}

bool
GGSmart::Robot::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__GGSmart__Robot_ids, __GGSmart__Robot_ids + 2, _s);
}

::std::vector< ::std::string>
GGSmart::Robot::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__GGSmart__Robot_ids[0], &__GGSmart__Robot_ids[2]);
}

const ::std::string&
GGSmart::Robot::ice_id(const ::Ice::Current&) const
{
    return __GGSmart__Robot_ids[0];
}

const ::std::string&
GGSmart::Robot::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::GGSmart::Robot";
    return typeId;
#else
    return __GGSmart__Robot_ids[0];
#endif
}

void
GGSmart::Robot::__gcVisitMembers(::IceInternal::GCVisitor& _v)
{
    if(CurOrder)
    {
        if((::GGSmart::upCast(CurOrder.get())->__gcVisit(_v)))
        {
            CurOrder = 0;
        }
    }
}

void
GGSmart::Robot::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->write(Id);
    __os->write(Property);
    __os->write(CurOrder);
    __os->write(Warnings);
    __os->write(RunData);
    __os->write(CurPlace);
    __os->endWriteSlice();
}

void
GGSmart::Robot::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->read(Id);
    __is->read(Property);
    __is->read(CurOrder);
    __is->read(Warnings);
    __is->read(RunData);
    __is->read(CurPlace);
    __is->endReadSlice();
}

namespace
{

const ::IceInternal::DefaultObjectFactoryInit< ::GGSmart::Robot> __GGSmart__Robot_init("::GGSmart::Robot");
}

::Ice::ObjectFactoryPtr
GGSmart::Robot::ice_factory()
{
    return ::IceInternal::factoryTable->getObjectFactory(::GGSmart::Robot::ice_staticId());
}

void 
GGSmart::__patch(RobotPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::GGSmart::RobotPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::GGSmart::Robot::ice_staticId(), v);
    }
}

::Ice::Object* GGSmart::upCast(::GGSmart::SubStation* p) { return p; }

#if defined(_MSC_VER) && (_MSC_VER >= 1900)
#   pragma warning(push)
#   pragma warning(disable:4589)
#endif
::Ice::ObjectPtr
GGSmart::SubStation::ice_clone() const
{
    ::Ice::Object* __p = new SubStation(*this);
    return __p;
}
#if defined(_MSC_VER) && (_MSC_VER >= 1900)
#   pragma warning(pop)
#endif

namespace
{
const ::std::string __GGSmart__SubStation_ids[2] =
{
    "::GGSmart::SubStation",
    "::Ice::Object"
};

}

bool
GGSmart::SubStation::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__GGSmart__SubStation_ids, __GGSmart__SubStation_ids + 2, _s);
}

::std::vector< ::std::string>
GGSmart::SubStation::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__GGSmart__SubStation_ids[0], &__GGSmart__SubStation_ids[2]);
}

const ::std::string&
GGSmart::SubStation::ice_id(const ::Ice::Current&) const
{
    return __GGSmart__SubStation_ids[0];
}

const ::std::string&
GGSmart::SubStation::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::GGSmart::SubStation";
    return typeId;
#else
    return __GGSmart__SubStation_ids[0];
#endif
}

void
GGSmart::SubStation::__gcVisitMembers(::IceInternal::GCVisitor& _v)
{
    {
        for(::GGSmart::RobotSeq::iterator _i0 = Robots.begin(); _i0 != Robots.end(); ++_i0)
        {
            if((*_i0))
            {
                if((::GGSmart::upCast((*_i0).get())->__gcVisit(_v)))
                {
                    (*_i0) = 0;
                }
            }
        }
    }
}

void
GGSmart::SubStation::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->write(Id);
    __os->write(Name);
    __os->write(Description);
    __os->write(Robots);
    __os->endWriteSlice();
}

void
GGSmart::SubStation::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->read(Id);
    __is->read(Name);
    __is->read(Description);
    __is->read(Robots);
    __is->endReadSlice();
}

namespace
{

const ::IceInternal::DefaultObjectFactoryInit< ::GGSmart::SubStation> __GGSmart__SubStation_init("::GGSmart::SubStation");
}

::Ice::ObjectFactoryPtr
GGSmart::SubStation::ice_factory()
{
    return ::IceInternal::factoryTable->getObjectFactory(::GGSmart::SubStation::ice_staticId());
}

void 
GGSmart::__patch(SubStationPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::GGSmart::SubStationPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::GGSmart::SubStation::ice_staticId(), v);
    }
}
