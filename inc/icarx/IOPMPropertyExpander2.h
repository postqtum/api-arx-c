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
***     Description: Declaration of IOPMPropertyExpander2 interface
***
*****************************************************************************/
#pragma once

#include "OPMLPOLESTR.h"
#include "OPMDWORD.h"

DEFINE_GUID(IID_IOPMPropertyExpander2, 0x58116a62, 0x3cfd, 0x4ec2, 0xb4, 0x8c, 0x3b, 0x20, 0xea,
			0xa7, 0xc, 0xf0);

interface DECLSPEC_UUID("58116A62-3CFD-4EC2-B48C-3B20EAA70CF0") IOPMPropertyExpander2
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [out] */ short* groupingNumber) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementStrings(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [out] */ OPMLPOLESTR __RPC_FAR* pCaStringsOut,
			/* [out] */ OPMDWORD __RPC_FAR* pCaCookiesOut) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [in] */ DWORD dwCookie,
			/* [out] */ VARIANT* pVarOut) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [out] */ long* nGroupCnt) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [in] */ DWORD dwCookie,
			/* [in] */ VARIANT VarIn) = 0;
};
