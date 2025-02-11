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
***     Description: Declaration of IFilterableProperty interface
***
*****************************************************************************/
#pragma once

enum AcFilterablePropertyContext;

DEFINE_GUID(IID_IFilterableProperty, 0xbbdf0fd7, 0xeff7, 0x4b00, 0x9c, 0x6, 0xcd, 0x68, 0x68, 0xd2,
			0x89, 0xc1);

interface DECLSPEC_UUID("BBDF0FD7-EFF7-4B00-9C06-CD6868D289C1") IFilterableProperty
		: public IUnknown
{
	BEGIN_INTERFACE

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(ShowFilterableProperty)
	(THIS_ /*[in]*/ DISPID dispID,
	 /*[in]*/ AcFilterablePropertyContext context,
	 /*[out]*/ BOOL* pbShow) PURE;
};

typedef IFilterableProperty FAR* LPFILTERABLEPROPERTY;
