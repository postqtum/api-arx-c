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
***     Description: Declaration of IOPMPropertyExpanderExpression interface
***
*****************************************************************************/
#pragma once

DEFINE_GUID(IID_IOPMPropertyExpanderExpression, 0x4837d325, 0x6921, 0x46b9, 0xae, 0x26, 0x52, 0x63,
			0x97, 0xdb, 0x95, 0x7b);

interface DECLSPEC_UUID("4837D325-6921-46B9-AE26-526397DB957B") IOPMPropertyExpanderExpression
		: public IUnknown
{
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE ExpressionAllowed(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [in] */ DWORD dwCookie,
			/* [out] */ BOOL* pAllowed) = 0;
	virtual HRESULT STDMETHODCALLTYPE get_Expression(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [in] */ DWORD dwCookie,
			/* [out] */ BSTR* expression) = 0;
	virtual HRESULT STDMETHODCALLTYPE put_Expression(
			/* [in] */ DISPID dispID,
			/* [in] */ IUnknown* pUnk,
			/* [in] */ DWORD dwCookie,
			/* [in] */ BSTR expression) = 0;
};
