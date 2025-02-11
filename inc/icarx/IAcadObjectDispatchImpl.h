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
***     Description: Declaration of IAcadObjectDispatchImpl class
***
*****************************************************************************/
#pragma once

#include "IAcadBaseObject2Impl.h"
#include "IRetrieveApplicationImpl.h"
#include "../PAL/api/AcLocale.h"
#include "../rxregsvc.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

template<class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
		 WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadObjectDispatchImpl
		: public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>
		, public IAcadBaseObject2Impl<C, pclsid>
		, public IRetrieveApplicationImpl
{
public:
	IAcadObjectDispatchImpl()
	{
		auto locale = acrxProductLocale();

		AcLocale::LocaleId lcid = locale;

		this->_tih.EnsureTI(lcid);
	}
	virtual ~IAcadObjectDispatchImpl() = default;

	STDMETHOD(get_Application)(LPDISPATCH* pVal) { return GetApplicationObject(pVal); }
	STDMETHOD(get_Database)(IAcadDatabase** pDatabase)
	{
		if (this->m_objRef.objectId() == AcDbObjectId::kNull || this->m_objRef.objectId().database() == NULL)
		{
			return RaiseArxException(*piid, 0, Acad::eNoDatabase);
		}

		CComPtr<IDispatch> pDispatch;
		HRESULT hr = AcAxGetDatabase(this->m_objRef.objectId().database(), m_App, &pDispatch);

		if (SUCCEEDED(hr))
		{
			hr = pDispatch->QueryInterface(IID_IAcadDatabase, reinterpret_cast<LPVOID*>(pDatabase));
		}

		return hr;
	}
	STDMETHOD(get_Document)(LPDISPATCH* pDocument)
	{
		if (this->m_objRef.objectId() == AcDbObjectId::kNull || this->m_objRef.objectId().database() == NULL)
		{
			return RaiseArxException(*piid, 0, Acad::eNoDatabase);
		}

		AcAxOleLinkManager* pOleLinkManager = AcAxGetOleLinkManager();
		ICARX_ASSERT(pOleLinkManager != NULL);

		*pDocument = pOleLinkManager->GetDocIDispatch(this->m_objRef.objectId().database());
		if (*pDocument == NULL)
		{
			return RaiseArxException(*piid, 0, Acad::eNoDocument);
		}

		(*pDocument)->AddRef();

		return S_OK;
	}
	STDMETHOD(get_Handle)(BSTR* pVal) { return AcAxGetHandle(this->m_objRef, pVal); }
	STDMETHOD(get_HasExtensionDictionary)(VARIANT_BOOL* bHasDictionary)
	{
		return AcAxHasExtensionDictionary(this->m_objRef, bHasDictionary);
	}
	STDMETHOD(get_ObjectID)(LONG_PTR* pVal)
	{
		*pVal = this->m_objRef.objectId().asOldId();
		return S_OK;
	}
	STDMETHOD(get_ObjectName)(BSTR* pVal) { return AcAxGetObjectName(this->m_objRef, pVal); }
	STDMETHOD(get_OwnerID)(LONG_PTR* pVal)
	{
		IcArx::Integers::IntDbId val;
		auto hr = AcAxGetOwnerId(this->m_objRef, &val);
		*pVal = val;
		return hr;
	}
	STDMETHOD(Delete)() { return AcAxErase(this->m_objRef); }
	STDMETHOD(GetXData)(BSTR bstrName, VARIANT* type, VARIANT* data)
	{
		return AcAxGetXData(this->m_objRef, bstrName, type, data);
	}
	STDMETHOD(SetXData)(VARIANT type, VARIANT data) { return AcAxSetXData(this->m_objRef, type, data); }
	STDMETHOD(GetExtensionDictionary)(IAcadDictionary** pExtDictionary)
	{
		return AcAxGetExtensionDictionary(this->m_objRef, m_App, pExtDictionary);
	}
	STDMETHOD(Erase)() { return Delete(); }
	STDMETHOD(Invoke)
	(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pdispparams,
	 VARIANT* pvarResult, EXCEPINFO* pexcepinfo, UINT* puArgErr)
	{
		HRESULT hr = this->_tih.Invoke((IDispatch*)this, dispidMember, riid, lcid, wFlags, pdispparams,
								 pvarResult, pexcepinfo, puArgErr);
		if (hr == DISP_E_MEMBERNOTFOUND && wFlags == DISPATCH_PROPERTYPUTREF)
		{
			HRESULT hr2 =
					this->_tih.Invoke((IDispatch*)this, dispidMember, riid, lcid, DISPATCH_PROPERTYPUT,
								pdispparams, pvarResult, pexcepinfo, puArgErr);

			if (SUCCEEDED(hr2))
				return hr2;
		}
		return hr;
	}
};

#include "IcArxPackPop.h"
