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
***     Description: Declaration of IDynamicPropertyNotify2 interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IDynamicPropertyNotify2, 0x7c681ef8, 0xb11a, 0x46c8, 0x88, 0x6f, 0xf8, 0xcb, 0x79,
			0xdf, 0xef, 0x4b);

interface DECLSPEC_UUID("7C681EF8-B11A-46C8-886F-F8CB79DFEF4B") IDynamicPropertyNotify2
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetCurrentSelectionSet)(THIS_ /*[out*/ VARIANT* pSelection) PURE;
	STDMETHOD(OnChanged)(THIS_ /*[in]*/ IUnknown* pDynamicProperty) PURE;
};

typedef IDynamicPropertyNotify2 FAR* LPDYNAMICPROPERTYNOTIFY2;
