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
***     Description: Declaration of IOPMPropertyExpander interface
***
*****************************************************************************/
#pragma once

#include "OPMLPOLESTR.h"
#include "OPMDWORD.h"

DEFINE_GUID(IID_IOPMPropertyExpander, 0x791ea0d3, 0xf63d, 0x40d1, 0x93, 0x80, 0x4, 0xb, 0xeb, 0xd3,
			0x95, 0xa);

interface DECLSPEC_UUID("791EA0D3-F63D-40D1-9380-040BEBD3950A") IOPMPropertyExpander
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
			/* [in] */ DISPID dispID,
			/* [out] */ short* groupingNumber) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementStrings(
			/* [in] */ DISPID dispID,
			/* [out] */ OPMLPOLESTR __RPC_FAR* pCaStringsOut,
			/* [out] */ OPMDWORD __RPC_FAR* pCaCookiesOut) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ DWORD dwCookie,
			/* [out] */ VARIANT* pVarOut) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
			/* [in] */ DISPID dispID,
			/* [out] */ long* nGroupCnt) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ DWORD dwCookie,
			/* [in] */ VARIANT VarIn) = 0;
};
