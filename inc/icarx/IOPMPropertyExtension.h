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
***     Description: Declaration of IOPMPropertyExtension interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IOPMPropertyExtension, 0xb0ab6bfb, 0x9029, 0x4fb3, 0xb1, 0x10, 0xca, 0xbc, 0x96,
			0x81, 0x95, 0xf4);

interface DECLSPEC_UUID("B0AB6BFB-9029-4FB3-B110-CABC968195F4") IOPMPropertyExtension
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE Editable(
			/* [in] */ DISPID dispID,
			/* [out] */ BOOL __RPC_FAR* bEditable) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDisplayName(
			/* [in] */ DISPID dispID,
			/* [out] */ BSTR* propName) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowProperty(
			/* [in] */ DISPID dispID,
			/* [out] */ BOOL* pShow) = 0;
};
