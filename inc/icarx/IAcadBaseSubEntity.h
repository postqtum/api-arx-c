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
***     Description: Declaration of IAcadBaseSubEntity interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

class AcDbFullSubentPath;

DEFINE_GUID(IID_IAcadBaseSubEntity, 0xfd0c4f6a, 0x16a3, 0x4dc8, 0x84, 0x72, 0xb0, 0xde, 0xd6, 0xf6,
			0x30, 0xc0);

#undef INTERFACE
#define INTERFACE IAcadBaseSubEntity

interface DECLSPEC_UUID("FD0C4F6A-16A3-4DC8-8472-B0DED6F630C0") IAcadBaseSubEntity
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
	STDMETHOD(GetFullSubEntPath)(THIS_ AcDbFullSubentPath* subentPath) PURE;
	STDMETHOD(OnModified)() PURE;
	STDMETHOD(SetFullSubEntPath)(THIS_ AcDbFullSubentPath& subentPath) PURE;
};

typedef IAcadBaseSubEntity* LPACADSUBENTITY;
