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
***     Description: Declaration of IFilterableSubtypePropertySource interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IFilterableSubtypePropertySource, 0xe2f9373, 0xdb26, 0x453a, 0xb4, 0x2b, 0x58, 0x8c,
			0x9f, 0x3f, 0x73, 0x30);

interface DECLSPEC_UUID("0E2F9373-DB26-453A-B42B-588C9F3F7330") IFilterableSubtypePropertySource
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetObjectSubtype)
	(THIS_ /*[in]*/ IUnknown* pObject,
	 /*[out]*/ BSTR* bstrSubtypeGUID) PURE;
	STDMETHOD(GetSubtypeName)
	(THIS_ /*[in]*/ BSTR bstrSubtypeGUID,
	 /*[out]*/ BSTR* bstrSubtypeName) PURE;
	STDMETHOD(GetSubtypeProperties)
	(THIS_ /*[in]*/ BSTR bstrSubtypeGUID,
	 /*[out]*/ VARIANT* pPropertyArray) PURE;
	STDMETHOD(GetSubtypes)(THIS_ /*[out]*/ VARIANT* pSubtypeGUIDsArray) PURE;
};

typedef IFilterableSubtypePropertySource FAR* LPFILTERABLESUBTYPEPROPERTYSOURCE;
