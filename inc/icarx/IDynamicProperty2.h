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
***     Description: Declaration of IDynamicProperty2 interface
***
*****************************************************************************/
#pragma once

interface IDynamicPropertyNotify2;

DEFINE_GUID(IID_IDynamicProperty2, 0xbfbd88d2, 0x40c9, 0x4748, 0x80, 0x90, 0xcc, 0xf4, 0x80, 0xc,
			0xa1, 0x60);

interface DECLSPEC_UUID("BFBD88D2-40C9-4748-8090-CCF4800CA160") IDynamicProperty2
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(Connect)(THIS_ /*[in]*/ IDynamicPropertyNotify2* pSink) PURE;
	STDMETHOD(Disconnect)(THIS_) PURE;
	STDMETHOD(GetCurrentValueData)
	(THIS_ /*in*/ IUnknown* pUnk,
	 /*[out]*/ VARIANT* pvarData) PURE;
	STDMETHOD(GetCurrentValueName)(THIS_ /*[out]*/ BSTR* pbstrName) PURE;
	STDMETHOD(GetCurrentValueType)(THIS_ /*[out]*/ VARTYPE* pVarType) PURE;
	STDMETHOD(GetDescription)(THIS_ /*[out]*/ BSTR* bstrName) PURE;
	STDMETHOD(GetDisplayName)(THIS_ /*[out]*/ BSTR* bstrName) PURE;
	STDMETHOD(GetGUID)(THIS_ /*[out]*/ GUID* propGUID) PURE;
	STDMETHOD(IsPropertyEnabled)
	(THIS_ /*[in]*/ IUnknown* pUnk,
	 /*[out]*/ BOOL* pbEnabled) PURE;
	STDMETHOD(IsPropertyReadOnly)(THIS_ /*[out]*/ BOOL* pbReadonly) PURE;
	STDMETHOD(SetCurrentValueData)
	(THIS_ /*[in]*/ IUnknown* pUnk,
	 /*[in]*/ const VARIANT varData) PURE;
};

typedef IDynamicProperty2 FAR* LPDYNAMICPROPERTY2;
