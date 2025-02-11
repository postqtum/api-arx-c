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
***     Description: Declaration of IOPMPropertyDialog interface
***
*****************************************************************************/
#pragma once

#include "../dbidar.h"

DEFINE_GUID(IID_IOPMPropertyDialog, 0x5ea5f922, 0xc78, 0x4d5a, 0x8f, 0xab, 0xc4, 0x72, 0x4e, 0x29,
			0x65, 0x6b);

interface DECLSPEC_UUID("5EA5F922-0C78-4D5A-8FAB-C4724E29656B") IOPMPropertyDialog
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(DoModal)
	(THIS_ /*[in/out]*/ BSTR* propValueString, /*[in]*/ AcDbObjectIdArray* ObjectIdArray) PURE;
};

typedef IOPMPropertyDialog FAR* LPPROPERTYDIALOG;
