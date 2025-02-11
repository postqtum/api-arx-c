/***************************************************************************
***
***     Copyright (C) 2022-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Declaration of AcDbSmartObjectPointer class
***
*****************************************************************************/
#pragma once

#include "ReadableAcDbObject.h"
#include "WritableAcDbObject.h"

#include "IcArxAssert.h"

#include "IcArxPackPush.h"

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC = ACDB_CLASS::desc>
class AcDbSmartObjectPointer
{
protected:
	ReadableAcDbObject<ACDB_CLASS, ACDB_GET_CLASS_DESC> mReadable;
	WritableAcDbObject mWritable;

private:
	ACDB_CLASS* mpObj{nullptr};

private:
	Acad::ErrorStatus closeInternal();

public:
	AcDbSmartObjectPointer();
	AcDbSmartObjectPointer(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
						   bool openErased = false, bool openOnLockedLayer = false);
	~AcDbSmartObjectPointer();
	AcDbSmartObjectPointer(const AcDbSmartObjectPointer&) = delete;
	AcDbSmartObjectPointer& operator=(const AcDbSmartObjectPointer&) = delete;
	const ACDB_CLASS* operator->() const;
	ACDB_CLASS* operator->();
	operator const ACDB_CLASS*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
	AcDbSmartObjectPointer(ACDB_CLASS* pObject);
	operator ACDB_CLASS*&();
	void operator=(ACDB_CLASS* pObject);
#else
	operator ACDB_CLASS*();
#endif

	Acad::ErrorStatus acquire(ACDB_CLASS*& pObjToAcquire);
	Acad::ErrorStatus close();
	Acad::ErrorStatus create();
	const ACDB_CLASS* object() const;
	ACDB_CLASS* object();
	Acad::ErrorStatus open(AcDbObjectId objId, AcDb::OpenMode mode = AcDb::kForRead,
						   bool openErased = false, bool openOnLockedLayer = false);
	Acad::ErrorStatus openStatus() const;
	Acad::ErrorStatus release(ACDB_CLASS*& pReleasedObj);
};

#include "IcArxPackPop.h"

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::AcDbSmartObjectPointer()
		: mReadable(), mWritable()
{
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::AcDbSmartObjectPointer(
		AcDbObjectId objId, AcDb::OpenMode mode, bool openErased, bool openOnLockedLayer)
		: mReadable(objId, openErased)
		, mWritable(mReadable.object(), AcDb::kForWrite == mode, openOnLockedLayer)
{
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::~AcDbSmartObjectPointer()
{
	mpObj = nullptr;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline const ACDB_CLASS* AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator->() const
{
	return object();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline ACDB_CLASS* AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator->()
{
	return object();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator const ACDB_CLASS*() const
{
	return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::AcDbSmartObjectPointer(
		ACDB_CLASS* pObject)
{
	acquire(pObject);
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator ACDB_CLASS*&()
{
	mWritable.forget();
	mReadable.forgetCurrentAndAcceptNewAsIs(mReadable.object());
	return mReadable.mpObj;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline void AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator=(ACDB_CLASS* pObject)
{
	acquire(pObject);
}

#else

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::operator ACDB_CLASS*()
{
	return object();
}

#endif

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::acquire(
		ACDB_CLASS*& pObjToAcquire)
{
	closeInternal();
	mReadable.forgetCurrentAndAcceptNewAsIs(pObjToAcquire);
	pObjToAcquire = nullptr;
	return Acad::eOk;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::close()
{
	closeInternal();
	return Acad::eOk;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::closeInternal()
{
	mWritable.revertWrite();
	mReadable.revertRead();

	return Acad::eOk;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::create()
{
	ACDB_CLASS* pObject = new ACDB_CLASS;
	if (pObject == nullptr)
		return Acad::eNullObjectPointer;
	closeInternal();
	mReadable.forgetCurrentAndAcceptNewAsIs(pObject);
	return Acad::eOk;
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline const ACDB_CLASS* AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::object() const
{
	ICARX_ASSERT(mReadable.object() == nullptr || mReadable.isReadable());
	return mReadable.object();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline ACDB_CLASS* AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::object()
{
	ICARX_ASSERT(mReadable.object() == nullptr || mReadable.isReadable());
	return mReadable.object();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::open(
		AcDbObjectId objId, AcDb::OpenMode mode, bool openErased, bool openOnLockedLayer)
{
	if (mReadable.isReadable())
	{
		Acad::ErrorStatus closeStatus = closeInternal();
		if (closeStatus != Acad::eOk)
			return closeStatus;
	}
	mReadable.enableRead(mReadable.mpObj, objId, openErased);
	if (mReadable.isReadable())
	{
		mWritable.setOpenOnLockedLayer(openOnLockedLayer);
		mWritable.replaceObject(mReadable.object(), (AcDb::kForWrite == mode));
	}
	return openStatus();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::openStatus() const
{
	return (mWritable.isWritable() || ((mWritable.statusCode() != Acad::eNullObjectPointer) &&
									   (mWritable.statusCode() != Acad::eNotOpenForWrite)))
				   ? mWritable.statusCode()
				   : mReadable.statusCode();
}

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC>
inline Acad::ErrorStatus AcDbSmartObjectPointer<ACDB_CLASS, ACDB_GET_CLASS_DESC>::release(
		ACDB_CLASS*& pReleasedObj)
{
	pReleasedObj = mReadable.object();
	mWritable.forget();
	mReadable.forgetCurrentAndAcceptNewAsIs(nullptr);
	return Acad::eOk;
}
