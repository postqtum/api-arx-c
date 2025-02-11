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
***     Description: Declaration of IFilterableMultiplePropertySource interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IFilterableMultiplePropertySource, 0x56749101, 0x3535, 0x48bf, 0x8a, 0x28, 0xfe,
			0x4b, 0xd4, 0xec, 0x9b, 0x3);

interface DECLSPEC_UUID("56749101-3535-48BF-8A28-FE4BD4EC9B03") IFilterableMultiplePropertySource
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetMultipleProperties)(THIS_ /*[out]*/ VARIANT* pPropertyArray) PURE;
};

typedef IFilterableMultiplePropertySource FAR* LPFILTERABLEMULTIPLEPROPERTYSOURCE;
