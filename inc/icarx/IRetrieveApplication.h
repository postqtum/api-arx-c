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
***     Description: Declaration of IRetrieveApplication interface
***
*****************************************************************************/
#pragma once

#include <atlbase.h>

DEFINE_GUID(IID_IRetrieveApplication, 0xed053f46, 0xaa38, 0x494e, 0x88, 0x53, 0xa9, 0xdf, 0x20,
			0x7d, 0x53, 0xb1);

interface DECLSPEC_UUID("ED053F46-AA38-494E-8853-A9DF207D53B1") IRetrieveApplication
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetApplicationObject)(THIS_ LPDISPATCH* pAppDisp) PURE;
	STDMETHOD(SetApplicationObject)(THIS_ LPDISPATCH pAppDisp) PURE;
};

typedef IRetrieveApplication* LPRETRIEVEAPPLICATION;
