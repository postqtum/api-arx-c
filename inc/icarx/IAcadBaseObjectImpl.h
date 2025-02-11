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
***     Description: Declaration of IAcadBaseObjectImpl class
***
*****************************************************************************/
#pragma once

#include "CProxy_AcadObjectEvents.h"
#include "CProxy_PropertyNotifySink.h"
#include "../AdAChar.h"
#include "../oleaprot.h"
#include "IcArxAssert.h"

class AcDbObjectId;

#include "IcArxPackPush.h"

template<class T, const CLSID* pclsid>
class ATL_NO_VTABLE IAcadBaseObjectImpl
		: public IAcadBaseObject
		, public IConnectionPointContainerImpl<T>
		, public CProxy_AcadObjectEvents<T>
		, public CProxy_PropertyNotifySink<T>
{
protected:
	AcDbObjectId m_objId;

protected:
	virtual void ObjectIdModified(){};

public:
	IAcadBaseObjectImpl() = default;
	virtual ~IAcadBaseObjectImpl()
	{
		if (!m_objId.isValid())
			return;

		AcDbObjectPointer<AcDbObject> pObject(m_objId, AcDb::kForRead, true);
		if (pObject.openStatus() != Acad::eOk)
		{
			AcDbObject* pTemp;
			if (Acad::eOk != acdbOpenObject(pTemp, m_objId, AcDb::kForNotify, true))
			{
				return;
			}
			pObject.acquire(pTemp);
		}

		AcAxOleLinkManager* pOleLinkManager = AcAxGetOleLinkManager();
		ICARX_ASSERT(pOleLinkManager != NULL);

		pOleLinkManager->SetIUnknown(pObject.object(), NULL);
	}

	virtual HRESULT CreateNewObject(AcDbObjectId& objId, AcDbObjectId& ownerId, ACHAR* keyName) = 0;
	STDMETHOD(Clone)(AcDbObjectId /*ownerId*/, LPUNKNOWN* /*pUnkClone*/) { return E_NOTIMPL; }
	STDMETHOD(GetClassID)(CLSID& clsid)
	{
		clsid = *pclsid;
		return S_OK;
	}
	STDMETHOD(GetObjectId)(AcDbObjectId* objId)
	{
		*objId = m_objId;
		return S_OK;
	}
	STDMETHOD(NullObjectId)()
	{
		m_objId = AcDbObjectId::kNull;
		ObjectIdModified();
		return S_OK;
	}
	STDMETHOD(OnModified)()
	{
		this->Fire_Modified();
		this->Fire_OnChanged();
		return S_OK;
	}
	STDMETHOD(SetObjectId)
	(AcDbObjectId& objId, AcDbObjectId ownerId = AcDbObjectId::kNull, ACHAR* keyName = nullptr)
	{
		if (!m_objId.isNull())
			return E_FAIL;

		if (objId == AcDbObjectId::kNull)
		{
			HRESULT hr;
			if (FAILED(hr = CreateNewObject(objId, ownerId, keyName)))
				return hr;
		}

		m_objId = objId;
		ICARX_ASSERT(m_objId != AcDbObjectId::kNull);
		ObjectIdModified();

		return S_OK;
	}

	BEGIN_CONNECTION_POINT_MAP(T)
		CONNECTION_POINT_ENTRY(IID_IAcadObjectEvents)
		CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
		END_CONNECTION_POINT_MAP()
};

#include "IcArxPackPop.h"
