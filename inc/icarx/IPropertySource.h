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
***     Description: Declaration of IPropertySource interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IPropertySource, 0x6a358852, 0x95f0, 0x4b07, 0xb5, 0x5a, 0xbb, 0xf8, 0x8e, 0x51,
			0x4, 0xbc);

interface DECLSPEC_UUID("6A358852-95F0-4B07-B55A-BBF88E5104BC") IPropertySource
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetProperties)
	(THIS_ /*[in]*/ IUnknown* pObject, /*[out, retval]*/ VARIANT* pPropertyArray) PURE;
	STDMETHOD(get_Name)(THIS_ /*[out, retval]*/ BSTR* pName) PURE;
};

typedef IPropertySource FAR* LPPROPERTYSOURCE;
