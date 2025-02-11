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
***     Description: Declaration of IDynamicDialogProperty interface
***
*****************************************************************************/
#pragma once

typedef BOOL (*OPMDIALOGPROC)(void);

DEFINE_GUID(IID_IDynamicDialogProperty, 0x75d36224, 0xec58, 0x439d, 0x97, 0x53, 0xbc, 0xca, 0x70,
			0x6b, 0xa8, 0xc1);

interface DECLSPEC_UUID("75D36224-EC58-439D-9753-BCCA706BA8C1") IDynamicDialogProperty
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetCustomDialogProc)(THIS_ /*[out]*/ OPMDIALOGPROC* pDialogProc) PURE;
	STDMETHOD(GetMacroName)(THIS_ /*[out]*/ BSTR* bstrName) PURE;
};

typedef IDynamicDialogProperty FAR* LPDYNAMICDIALOGPROPERTY;
