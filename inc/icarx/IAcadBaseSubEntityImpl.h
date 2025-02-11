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
***     Description: Declaration of IAcadBaseSubEntityImpl class
***
*****************************************************************************/
#pragma once

#include "../axboiler.h"
#include "CProxy_AcadObjectEvents.h"
#include "CProxy_PropertyNotifySink.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

template<class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
		 WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadBaseSubEntityImpl
		: public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>
		, public IAcadBaseSubEntity
		, public IRetrieveApplicationImpl
		, public IConnectionPointContainerImpl<C>
		, public CProxy_AcadObjectEvents<C>
		, public CProxy_PropertyNotifySink<C>
{
protected:
	AcDbFullSubentPath m_subentPath;
	AcDbObjectId m_objId;

protected:
	STDMETHODIMP parentObjectId(AcDbObjectId & objID)
	{
		AcDbObjectIdArray objectIds = m_subentPath.objectIds();
		if (0 != objectIds.length())
		{
			objID = objectIds[objectIds.length() - 1];
			return S_OK;
		}
		return E_FAIL;
	}
public:
	IAcadBaseSubEntityImpl() = default;
	virtual ~IAcadBaseSubEntityImpl()
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

		pOleLinkManager->SetIUnknown(pObject.object(), m_subentPath.subentId(), NULL);
	}

	STDMETHOD(GetClassID)(CLSID& clsid)
	{
		clsid = *pclsid;
		return S_OK;
	}
	STDMETHOD(GetFullSubEntPath)(AcDbFullSubentPath* subentPath)
	{
		*subentPath = m_subentPath;
		return S_OK;
	}
	STDMETHOD(OnModified)()
	{
		Fire_Modified();
		Fire_OnChanged();
		return S_OK;
	}
	STDMETHOD(SetFullSubEntPath)(AcDbFullSubentPath& subentPath)
	{
		m_subentPath = subentPath;
		AcDbObjectIdArray objectIds = m_subentPath.objectIds();
		if (0 != objectIds.length())
			m_objId = objectIds[objectIds.length() - 1];
		return S_OK;
	}
	STDMETHODIMP get_Color(IAcadAcCmColor** pColor) { return AcAxGetTrueColor(m_objId, pColor); }
	STDMETHODIMP get_Hyperlinks(IAcadHyperlinks** pHyperlinks)
	{
		return AcAxGetHyperlinks(m_objId, m_App, pHyperlinks);
	}
	STDMETHODIMP get_Layer(BSTR* pVal) { return AcAxGetLayer(m_objId, pVal); }
	STDMETHODIMP get_Linetype(BSTR* pVal) { return AcAxGetLinetype(m_objId, pVal); }
	STDMETHODIMP get_LinetypeScale(double* pVal) { return AcAxGetLinetypeScale(m_objId, pVal); }
	STDMETHODIMP get_Lineweight(ACAD_LWEIGHT* lineweight)
	{
		return AcAxGetLineWeight(m_objId, lineweight);
	}
	STDMETHOD(get_ObjectName)(BSTR* pVal) { return AcAxGetObjectName(m_objId, pVal); }
	STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
	{
		return AcAxGetPlotStyleName(m_objId, plotStyleName);
	}

	BEGIN_CONNECTION_POINT_MAP(C)
		CONNECTION_POINT_ENTRY(IID_IAcadObjectEvents)
		CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
		END_CONNECTION_POINT_MAP()
};

#include "IcArxPackPop.h"
