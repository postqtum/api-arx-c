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
***     Description: Declaration of IDynamicEnumProperty interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IDynamicEnumProperty, 0x80353f0b, 0xd4bd, 0x44d8, 0x93, 0x26, 0xb5, 0x41, 0x50,
			0xf9, 0xff, 0x25);

interface DECLSPEC_UUID("80353F0B-D4BD-44D8-9326-B54150F9FF25") IDynamicEnumProperty
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetNumPropertyValues)(THIS_ /*[out]*/ LONG* numValues) PURE;
	STDMETHOD(GetPropValueData)
	(THIS_ /*in*/ LONG index,
	 /*[out]*/ VARIANT* valueName) PURE;
	STDMETHOD(GetPropValueName)
	(THIS_ /*in*/ LONG index,
	 /*[out]*/ BSTR* valueName) PURE;
};

typedef IDynamicEnumProperty FAR* LPDYNAMICENUMPROPERTY;
