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
***     Description: Declaration of IDynamicPropertyNotify interface
***
*****************************************************************************/
#pragma once

interface IDynamicProperty;

DEFINE_GUID(IID_IDynamicPropertyNotify, 0x77a8f53b, 0x3c55, 0x4918, 0x9a, 0x26, 0x25, 0x67, 0xde,
			0xc4, 0x86, 0x1f);

interface DECLSPEC_UUID("77A8F53B-3C55-4918-9A26-2567DEC4861F") IDynamicPropertyNotify
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetCurrentSelectionSet)(THIS_ /*[out*/ VARIANT* pSelection) PURE;
	STDMETHOD(OnChanged)(THIS_ /*[in]*/ IDynamicProperty* pDynamicProperty) PURE;
};

typedef IDynamicPropertyNotify FAR* LPDYNAMICPROPERTYNOTIFY;
