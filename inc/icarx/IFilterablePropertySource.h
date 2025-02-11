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
***     Description: Declaration of IFilterablePropertySource interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IFilterablePropertySource, 0xaeb9eacd, 0x421a, 0x4944, 0xb2, 0x42, 0xb1, 0x89, 0x5c,
			0x4f, 0x82, 0x75);

interface DECLSPEC_UUID("AEB9EACD-421A-4944-B242-B1895C4F8275") IFilterablePropertySource
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetFilterableProperties)(THIS_ /*[out, retval]*/ VARIANT* pPropertyArray) PURE;
};

typedef IFilterablePropertySource FAR* LPFILTERABLEPROPERTYSOURCE;
