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
***     Description:
***
*****************************************************************************/
#pragma once

#include "icarx/AxAutoExp.h"
#include "opmimp.h"

HRESULT AXAUTOEXP AcOpmEditable(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID,
								BOOL __RPC_FAR* bEditable);
HRESULT AXAUTOEXP AcOpmGetCategoryCommandButtons(IUnknown* pUnk, HINSTANCE hResInstance,
												 CATCMDBTN_VECTOR& arr, PROPCAT propcat,
												 VARIANT* pCatCmdBtns);
HRESULT AXAUTOEXP AcOpmGetCategoryDescription(IUnknown* pUnk, HINSTANCE hResInstance,
											  CATEGORY_VECTOR& arr, PROPCAT propcat, LCID lcid,
											  BSTR* pbstrDesc);
HRESULT AXAUTOEXP AcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance,
									   ACAD_OPMPROPMAP_ENTRY* pMap, PROPCAT propcat, LCID lcid,
									   BSTR* pbstrName);
HRESULT AXAUTOEXP AcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR& arr,
									   PROPCAT propcat, LCID lcid, BSTR* pbstrName);
HRESULT AXAUTOEXP AcOpmGetCategoryWeight(IUnknown* pUnk, CATEGORY_VECTOR& arr, PROPCAT propcat,
										 long* pCategoryWeight);
HRESULT AXAUTOEXP AcOpmGetCommandButtons(IUnknown* pUnk, HINSTANCE hResInstance, CMDBTN_VECTOR& arr,
										 VARIANT* pCmdBtns);
HRESULT AXAUTOEXP AcOpmGetCustomPropertyCtrl(IUnknown* pUnk, PROP_DISP_VECTOR& arr, VARIANT Id,
											 LCID lcid, BSTR* psProdId);
HRESULT AXAUTOEXP AcOpmGetDisplayName(IUnknown* pUnk, HINSTANCE hResInstance,
									  ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR* pBstr);
HRESULT AXAUTOEXP AcOpmGetDisplayString(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID,
										BSTR* pBstr);
HRESULT AXAUTOEXP AcOpmGetParentCategory(IUnknown* pUnk, CATEGORY_VECTOR& arr, PROPCAT propcat,
										 PROPCAT* pParentCatID);
HRESULT AXAUTOEXP AcOpmGetPredefinedStrings(IUnknown* pUnk, HINSTANCE hResInstance,
											ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID,
											CALPOLESTR* pCaStringsOut, CADWORD* pCaCookiesOut);
HRESULT AXAUTOEXP AcOpmGetPredefinedValue(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap,
										  DISPID dispID, DWORD dwCookie, VARIANT* pVarOut);
HRESULT AXAUTOEXP AcOpmGetPropTextColor(IUnknown* pUnk, PROP_DISP_VECTOR& arr, VARIANT Id,
										OLE_COLOR* pTextColor);
HRESULT AXAUTOEXP AcOpmGetPropertyIcon(IUnknown* pUnk, HINSTANCE hResInstance,
									   PROP_DISP_VECTOR& arr, VARIANT Id, IUnknown** ppIcon);
HRESULT AXAUTOEXP AcOpmGetPropertyWeight(IUnknown* pUnk, PROP_DISP_VECTOR& arr, VARIANT Id,
										 long* pPropertyWeight);
HRESULT AXAUTOEXP AcOpmIsPropFullView(IUnknown* pUnk, PROP_DISP_VECTOR& arr, VARIANT Id,
									  VARIANT_BOOL* pbVisible, DWORD* pIntegralHeight);
HRESULT AXAUTOEXP AcOpmMapPropertyToCategory(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap,
											 DISPID dispid, PROPCAT* ppropcat);
HRESULT AXAUTOEXP AcOpmMapPropertyToPage(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID,
										 CLSID* pClsid);
HRESULT AXAUTOEXP AcOpmShowProperty(IUnknown* pUnk, ACAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID,
									BOOL* pShow);
