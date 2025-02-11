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
***     Description: Declaration of IAcadBaseDatabase interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

class AcDbDatabase;

DEFINE_GUID(IID_IAcadBaseDatabase, 0x7c31a5ef, 0x2e7, 0x4bec, 0xb2, 0x46, 0x87, 0x62, 0xa, 0xd0,
			0x3b, 0x5d);

interface DECLSPEC_UUID("7C31A5EF-02E7-4BEC-B246-87620AD03B5D") IAcadBaseDatabase
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
	STDMETHOD(GetDatabase)(THIS_ AcDbDatabase** pDb) PURE;
	STDMETHOD(SetDatabase)(THIS_ AcDbDatabase*& pDb) PURE;
};

typedef IAcadBaseDatabase* LPACADBASEDATABASE;
