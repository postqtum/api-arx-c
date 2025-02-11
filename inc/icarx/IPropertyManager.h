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
***     Description: Declaration of IPropertyManager interface
***
*****************************************************************************/
#pragma once

interface IDynamicProperty;

DEFINE_GUID(IID_IPropertyManager, 0x93689352, 0xac4d, 0x4a9b, 0x82, 0x2b, 0x96, 0x43, 0x59, 0xba,
			0x70, 0x75);

interface DECLSPEC_UUID("93689352-AC4D-4A9B-822B-964359BA7075") IPropertyManager
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(AddProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
	STDMETHOD(GetDynamicClassInfo)
	(THIS_ /*[in]*/ IUnknown* pObj,
	 /*[out]*/ ITypeInfo** pptiDynamic,
	 /*[out]*/ DWORD* dwCookie) PURE;
	STDMETHOD(GetDynamicProperty)
	(THIS_ /*[in]*/ LONG index,
	 /*[out]*/ IDynamicProperty** pProperty) PURE;
	STDMETHOD(GetDynamicPropertyByName)
	(THIS_ /*[in]*/ BSTR propName,
	 /*[out]*/ IDynamicProperty** pProperty) PURE;
	STDMETHOD(GetDynamicPropertyCount)(THIS_ /*[out]*/ LONG* count) PURE;
	STDMETHOD(RemoveProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
};

typedef IPropertyManager FAR* LPPROPERTYMANAGER;
