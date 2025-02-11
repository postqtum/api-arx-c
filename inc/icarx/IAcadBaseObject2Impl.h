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
***     Description: Declaration of IAcadBaseObject2Impl class
***
*****************************************************************************/
#pragma once

#include "IAcadBaseObjectImpl.h"
#include "AcAxObjectRef.h"
#include "IcArxAssert.h"

class AcDbObjectId;
class AcDbObject;

#define ACAX_VARIANT_TRUE (VARIANT_BOOL)-1
#define ACAX_VARIANT_FALSE (VARIANT_BOOL)0

#include "IcArxPackPush.h"
#pragma warning(disable : 4100)

template<class T, const CLSID* pclsid>
class ATL_NO_VTABLE IAcadBaseObject2Impl
		: public IAcadBaseObject2
		, public IAcadBaseObjectImpl<T, pclsid>
{
protected:
	AcAxObjectRef m_objRef;

protected:
	void Fire_Notification(DISPID dispId = DISPID_UNKNOWN)
	{
		if (m_objRef.objectId().isNull())
		{
			this->Fire_Modified();
			this->Fire_OnChanged(dispId);
		}
	}
	virtual void ObjectIdModified()
	{
		releaseReference();
		m_objRef.acquire(this->m_objId);
	}
	STDMETHOD(releaseReference)()
	{
		AcDbObjectId tmpId;
		AcDbObject* pTmp = NULL;
		m_objRef.release(tmpId, pTmp);
		if (NULL != pTmp && pTmp->objectId().isNull())
			delete pTmp;
		return S_OK;
	}

public:
	IAcadBaseObject2Impl() = default;
	virtual ~IAcadBaseObject2Impl() = default;

	STDMETHOD(AddToDb)
	(AcDbObjectId& objId, AcDbObjectId ownerId = AcDbObjectId::kNull, ACHAR* keyName = nullptr)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(CreateObject)(AcDbObjectId ownerId = AcDbObjectId::kNull, ACHAR* keyName = nullptr)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(GetObject)(AcDbObject*& pObj)
	{
		pObj = NULL;
		if (!m_objRef.objectId().isNull())
			return E_FAIL;

		AcDbObjectId tmpId;
		m_objRef.release(tmpId, pObj);
		ICARX_ASSERT(this->m_objId.isNull());
		ICARX_ASSERT(tmpId.isNull());
		return S_OK;
	}
	STDMETHOD(ForceDbResident)(VARIANT_BOOL* forceDbResident)
	{
		if (NULL == forceDbResident)
			return E_POINTER;

		*forceDbResident = ACAX_VARIANT_TRUE;
		return S_OK;
	}
	STDMETHOD(ObjectExists)(VARIANT_BOOL* objectExists)
	{
		if (NULL == objectExists)
			return E_POINTER;

		*objectExists = m_objRef.isNull() ? ACAX_VARIANT_FALSE : ACAX_VARIANT_TRUE;
		return S_OK;
	}
	STDMETHOD(OnModified)(DISPID dispId = DISPID_UNKNOWN)
	{
		this->Fire_Modified();
		this->Fire_OnChanged(dispId);
		return S_OK;
	}
	STDMETHOD(SetObject)(AcDbObject*& pObj)
	{
		if (pObj->objectId().isNull())
		{
			this->NullObjectId();
			m_objRef.acquire(pObj);
			return S_OK;
		}
		else
		{
			AcDbObjectId tmpId = pObj->objectId();
			return this->SetObjectId(tmpId);
		}
	}
};

#include "IcArxPackPop.h"
