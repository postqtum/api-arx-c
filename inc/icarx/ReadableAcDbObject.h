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
***     Description: Declaration of ReadableAcDbObject class
***
*****************************************************************************/
#pragma once

#include "../dbobjptr.h"

#include "IcArxAssert.h"

using getClassDescFuncType = decltype(AcRxClass::desc);

template<class, getClassDescFuncType>
class AcDbSmartObjectPointer;

ACDBCORE2D_PORT Acad::ErrorStatus accessAcDbObjectForRead(AcDbObject*& pObj, AcDbObjectId id,
														  AcRxClass* (*pfDesc)(), bool& bWasOpened,
														  bool bOpenErased);

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC = ACDB_CLASS::desc>
inline Acad::ErrorStatus accessAcDbObjectForRead(ACDB_CLASS*& pObj, AcDbObjectId id,
												 bool& bWasOpened, bool bOpenErased = false)
{
	constexpr auto pGetClassDescFunc = ACDB_GET_CLASS_DESC;
	ICARX_ASSERT(pGetClassDescFunc);
	if (!pGetClassDescFunc)
		return Acad::eInvalidInput;
	return ::accessAcDbObjectForRead((AcDbObject*&)pObj, id, pGetClassDescFunc, bWasOpened,
									 bOpenErased);
};

template<>
inline Acad::ErrorStatus accessAcDbObjectForRead<AcDbObject, nullptr>(AcDbObject*& pObj,
																	  AcDbObjectId id,
																	  bool& bWasOpened,
																	  bool bOpenErased)
{
	return ::accessAcDbObjectForRead(pObj, id, /*pfDesc*/ nullptr, bWasOpened, bOpenErased);
}

#include "IcArxPackPush.h"

template<class ACDB_CLASS, getClassDescFuncType ACDB_GET_CLASS_DESC = ACDB_CLASS::desc>
class ReadableAcDbObject
{
	template<class, getClassDescFuncType>
	friend class AcDbSmartObjectPointer;

private:
	ACDB_CLASS* mpObj{nullptr};
	Acad::ErrorStatus mEs{Acad::eNotOpenForRead};
	bool mbWasOpened{false};

public:
	ReadableAcDbObject() = default;
	ReadableAcDbObject(ACDB_CLASS*& pObj, AcDbObjectId id, bool bOpenErased, bool enableNow = true)
	{
		if (enableNow)
			enableRead(pObj, id, bOpenErased);
	}
	ReadableAcDbObject(const ReadableAcDbObject&) = delete;
	ReadableAcDbObject& operator=(const ReadableAcDbObject&) = delete;
	~ReadableAcDbObject() { revertRead(); }

	void enableRead(ACDB_CLASS*& pObj, AcDbObjectId id, bool bOpenErased)
	{
		revertRead();
		pObj = nullptr;
		if (Acad::eNotOpenForRead == mEs)
		{
			mEs = accessAcDbObjectForRead<ACDB_CLASS, ACDB_GET_CLASS_DESC>(pObj, id, mbWasOpened,
																		   bOpenErased);
			ICARX_ASSERT((Acad::eOk == mEs) == (nullptr != pObj));
			ICARX_ASSERT((nullptr != pObj) ? pObj->isReadEnabled() : true);
			mpObj = pObj;
		}
	}
	bool isReadable() const { return ((nullptr != mpObj) && mpObj->isReadEnabled()); }
	const ACDB_CLASS* object() const
	{
		return Acad::eOk == mEs ? mpObj : nullptr;
	}
	ACDB_CLASS* object()
	{
		return Acad::eOk == mEs ? mpObj : nullptr;
	}
	void revertRead()
	{
		if (mpObj)
		{
			if (mpObj->objectId().isNull())
			{
				delete mpObj;
			}
			else if ((Acad::eOk == mEs) && mbWasOpened)
			{
				mEs = mpObj->close();
			}
			mpObj = nullptr;
		}
		mEs = Acad::eNotOpenForRead;
	}
	Acad::ErrorStatus statusCode() const { return mEs; }

private:
	ReadableAcDbObject(AcDbObjectId id, bool bOpenErased, bool enableNow = true)
			: mpObj(nullptr), mEs(Acad::eNotOpenForRead)
	{
		if (enableNow)
			enableRead(mpObj, id, bOpenErased);
	}

	void forgetCurrentAndAcceptNewAsIs(ACDB_CLASS* pNewObj)
	{
		if (mpObj != pNewObj)
		{
			mpObj = pNewObj;
			mEs = (nullptr == mpObj) ? Acad::eNotOpenForRead : Acad::eOk;
			mbWasOpened = (nullptr != mpObj);
		}
	}
};

#include "IcArxPackPop.h"
