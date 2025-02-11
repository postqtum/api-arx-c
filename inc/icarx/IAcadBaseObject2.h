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
***     Description: Declaration of IAcadBaseObject2 interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

#include "AcDbObjectId.h"

class AcDbObject;

DEFINE_GUID(IID_IAcadBaseObject2, 0x76664492, 0x2aa0, 0x4493, 0x9b, 0x9, 0xbe, 0x4, 0x23, 0xd8,
			0xee, 0x13);

interface DECLSPEC_UUID("76664492-2AA0-4493-9B09-BE0423D8EE13") IAcadBaseObject2
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(AddToDb)
	(THIS_ AcDbObjectId& objId, AcDbObjectId ownerId = AcDbObjectId::kNull,
	 ACHAR* keyName = NULL) PURE;
	STDMETHOD(CreateObject)
	(THIS_ AcDbObjectId ownerId = AcDbObjectId::kNull, ACHAR* keyName = NULL) PURE;
	STDMETHOD(ForceDbResident)(THIS_ VARIANT_BOOL* forceDbResident) PURE;
	STDMETHOD(GetObject)(THIS_ AcDbObject*& pObj) PURE;
	STDMETHOD(ObjectExists)(THIS_ VARIANT_BOOL* objectExists) PURE;
	STDMETHOD(OnModified)(THIS_ DISPID = DISPID_UNKNOWN) PURE;
	STDMETHOD(SetObject)(THIS_ AcDbObject*& pObj) PURE;
};

typedef IAcadBaseObject2* LPACADBASEOBJECT2;
