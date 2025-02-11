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
***     Description: Declaration of IPropertyManager2 interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IPropertyManager2, 0x4ea0e7cc, 0x7a27, 0x408a, 0xa9, 0x5d, 0xef, 0xd7, 0xc2, 0x2c,
			0xe7, 0x2);

interface DECLSPEC_UUID("4EA0E7CC-7A27-408A-A95D-EFD7C22CE702") IPropertyManager2
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(AddProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
	STDMETHOD(GetDynamicClassInfo)
	(THIS_ /*[in]*/ IUnknown* pObj,
	 /*[out]*/ ITypeInfo** pptiDynamic,
	 /*[out]*/ DWORD* dwCookie) PURE;
	STDMETHOD(GetDynamicProperty)
	(THIS_ /*[in]*/ LONG index,
	 /*[out]*/ IUnknown** pDynPropObj) PURE;
	STDMETHOD(GetDynamicPropertyByName)
	(THIS_ /*[in]*/ BSTR propName,
	 /*[out]*/ IUnknown** pDynPropObj) PURE;
	STDMETHOD(GetDynamicPropertyCountEx)(THIS_ /*[out]*/ LONG* count) PURE;
	STDMETHOD(RemoveProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
};

typedef IPropertyManager2 FAR* LPPROPERTYMANAGER2;
