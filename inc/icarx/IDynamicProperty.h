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
***     Description: Declaration of IDynamicProperty interface
***
*****************************************************************************/
#pragma once

interface IDynamicPropertyNotify;

DEFINE_GUID(IID_IDynamicProperty, 0x2104e3b7, 0xff8f, 0x4766, 0xba, 0x5, 0xfa, 0x15, 0xf3, 0x5e,
			0x96, 0x9d);

interface DECLSPEC_UUID("2104E3B7-FF8F-4766-BA05-FA15F35E969D") IDynamicProperty
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(Connect)(THIS_ /*[in]*/ IDynamicPropertyNotify* pSink) PURE;
	STDMETHOD(Disconnect)(THIS_) PURE;
	STDMETHOD(GetCurrentValueData)
	(THIS_ /*in*/ LONG_PTR objectID,
	 /*[out]*/ VARIANT* pvarData) PURE;
	STDMETHOD(GetCurrentValueName)(THIS_ /*[out]*/ BSTR* pbstrName) PURE;
	STDMETHOD(GetCurrentValueType)(THIS_ /*[out]*/ VARTYPE* pVarType) PURE;
	STDMETHOD(GetDescription)(THIS_ /*[out]*/ BSTR* bstrName) PURE;
	STDMETHOD(GetDisplayName)(THIS_ /*[out]*/ BSTR* bstrName) PURE;
	STDMETHOD(GetGUID)(THIS_ /*[out]*/ GUID* propGUID) PURE;
	STDMETHOD(IsPropertyEnabled)
	(THIS_ /*[in]*/ LONG_PTR objectID,
	 /*[out]*/ BOOL* pbEnabled) PURE;
	STDMETHOD(IsPropertyReadOnly)(THIS_ /*[out]*/ BOOL* pbReadonly) PURE;
	STDMETHOD(SetCurrentValueData)
	(THIS_ /*[in]*/ LONG_PTR objectID,
	 /*[in]*/ const VARIANT varData) PURE;
};

typedef IDynamicProperty FAR* LPDYNAMICPROPERTY;
