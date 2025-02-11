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
***     Description: Declaration of IAcadBaseObject interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

#include "AcDbObjectId.h"

DEFINE_GUID(IID_IAcadBaseObject, 0xc64ed518, 0x76fb, 0x4b70, 0x90, 0x8, 0x38, 0xb0, 0x3c, 0x2a,
			0x40, 0xe);

#undef INTERFACE
#define INTERFACE IAcadBaseObject

interface DECLSPEC_UUID("C64ED518-76FB-4B70-9008-38B03C2A400E") IAcadBaseObject
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(Clone)(THIS_ AcDbObjectId ownerId, LPUNKNOWN* pUnkClone) PURE;
	STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
	STDMETHOD(GetObjectId)(THIS_ AcDbObjectId* objId) PURE;
	STDMETHOD(OnModified)(THIS) PURE;
	STDMETHOD(NullObjectId)(THIS) PURE;
	STDMETHOD(SetObjectId)
	(THIS_ AcDbObjectId& objId, AcDbObjectId ownerId = AcDbObjectId::kNull,
	 ACHAR* keyName = NULL) PURE;
};

typedef IAcadBaseObject* LPACADBASEOBJECT;
