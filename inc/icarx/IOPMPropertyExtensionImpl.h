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
***     Description: Declaration of IOPMPropertyExtensionImpl class
***
*****************************************************************************/
#pragma once

#include <atldef.h>

#include "../opmimp.h"
#include "IOPMPropertyExtension.h"

#include "IcArxPackPush.h"

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl
		: public ICategorizeProperties
		, public IPerPropertyBrowsing
		, public IOPMPropertyExtension
{
public:
	IOPMPropertyExtensionImpl() = default;
	virtual ~IOPMPropertyExtensionImpl() = default;

	virtual HINSTANCE GetResourceInstance() = 0;

	STDMETHODIMP Editable(
			/* [in] */ DISPID dispID,
			/* [out] */ BOOL __RPC_FAR* bEditable)
	{
		return AcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID,
							 bEditable);
	}
	STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
	{
		return AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
									T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
	}
	STDMETHODIMP GetDisplayName(DISPID dispID, BSTR* pBstr)
	{
		return AcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
								   T::GetOPMPropertyMap(), dispID, pBstr);
	}
	STDMETHODIMP GetDisplayString(DISPID dispID, BSTR* pBstr)
	{
		return AcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(),
									 dispID, pBstr);
	}
	STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR* pCaStringsOut,
									  CADWORD* pCaCookiesOut)
	{
		return AcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
										 T::GetOPMPropertyMap(), dispID, pCaStringsOut,
										 pCaCookiesOut);
	}
	STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT* pVarOut)
	{
		return AcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(),
									   dispID, dwCookie, pVarOut);
	}
	STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
	{
		return AcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(),
										  dispid, ppropcat);
	}
	STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID* pClsid)
	{
		return AcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(),
									  dispID, pClsid);
	}
	STDMETHODIMP ShowProperty(
			/* [in] */ DISPID dispID,
			/* [out] */ BOOL* pShow)
	{
		return AcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID,
								 pShow);
	}
};

#include "IcArxPackPop.h"
