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
***     Description: Declaration of IDynamicPropertyGetDispId interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IDynamicPropertyGetDispId, 0x6af7f8aa, 0x85bf, 0x420b, 0xaa, 0x9c, 0xb5, 0x92, 0xee,
			0xad, 0x1b, 0x3);

interface DECLSPEC_UUID("6AF7F8AA-85BF-420B-AA9C-B592EEAD1B03") IDynamicPropertyGetDispId
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetDispId)(THIS_ /*[out]*/ DISPID* dispId) PURE;
};

typedef IDynamicPropertyGetDispId FAR* LPDYNAMICPROPERTYGETDISPID;
