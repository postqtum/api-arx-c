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
***     Description: Declaration of IOPMPropertyDialog2 interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IOPMPropertyDialog2, 0xa5cf48c6, 0x35d0, 0x44ae, 0xbf, 0xf8, 0xd7, 0x4, 0x1a, 0xf,
			0x87, 0x3d);

interface DECLSPEC_UUID("A5CF48C6-35D0-44AE-BFF8-D7041A0F873D") IOPMPropertyDialog2
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(DoModal)
	(THIS_ /*[in/out]*/ BSTR* propValueString, /*[in]*/ VARIANT ObjectUnknownArray) PURE;
};

typedef IOPMPropertyDialog2 FAR* LPPROPERTYDIALOG2;
