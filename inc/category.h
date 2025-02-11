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
***     Description:
***
*****************************************************************************/
#pragma once

#include "category-properties.h"

DEFINE_GUID(IID_ICategorizeProperties, 0xee6d2a09, 0xb543, 0x4b53, 0xb3, 0x21, 0x9e, 0x65, 0x5a,
			0x10, 0xee, 0x6d);

typedef int PROPCAT;

#	undef INTERFACE
#	define INTERFACE ICategorizeProperties
interface DECLSPEC_UUID("EE6D2A09-B543-4B53-B321-9E655A10EE6D") ICategorizeProperties
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetCategoryName)
	(THIS_
			 /* [in]  */ PROPCAT propcat,
	 /* [in]  */ LCID lcid,
	 /* [out] */ BSTR* pbstrName) PURE;
	STDMETHOD(MapPropertyToCategory)
	(THIS_
			 /* [in]  */ DISPID dispid,
	 /* [out] */ PROPCAT* ppropcat) PURE;
};

typedef ICategorizeProperties FAR* LPCATEGORIZEPROPERTIES;
