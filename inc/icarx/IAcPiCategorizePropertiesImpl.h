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
***     Description: Declaration of IAcPiCategorizePropertiesImpl class
***
*****************************************************************************/
#pragma once

#include <atldef.h>
#include "acpi.h"
#include "../opmimp.h"

#include "IcArxPackPush.h"

template<class T>
class ATL_NO_VTABLE IAcPiCategorizePropertiesImpl : public IAcPiCategorizeProperties
{
public:
	CATEGORY_VECTOR m_CategoryVector;
	CATCMDBTN_VECTOR m_CatCmdBtnVector;

public:
	IAcPiCategorizePropertiesImpl()
	{
		m_CatCmdBtnVector.clear();
		m_CategoryVector.clear();
		int i = 0;
		while (!IsDefaultCmdBtnEntry(T::GetCmdBtnArray()[i]))
		{
			m_CatCmdBtnVector.push_back(T::GetCmdBtnArray()[i]);
			i++;
		}

		i = 0;
		while (!IsDefaultCategoryEntry(T::GetCatArray()[i]))
		{
			m_CategoryVector.push_back(T::GetCatArray()[i]);
			i++;
		}
	}
	virtual ~IAcPiCategorizePropertiesImpl() = default;

	virtual HINSTANCE GetResourceInstance() = 0;

	STDMETHODIMP GetCategoryDescription(PROPCAT propcat, LCID lcid, BSTR* pbstrDesc)
	{
		return AcOpmGetCategoryDescription(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
										   GetCategoryVector(), propcat, lcid, pbstrDesc);
	}
	STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
	{
		HRESULT hr;
		hr = AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
								  T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
		if (hr == S_FALSE)
		{
			hr = AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
									  GetCategoryVector(), propcat, lcid, pbstrName);
		}
		return hr;
	}
	CATEGORY_VECTOR& GetCategoryVector() { return m_CategoryVector; }
	STDMETHODIMP GetCategoryWeight(PROPCAT CatID, long* pCategoryWeight)
	{
		return AcOpmGetCategoryWeight(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID,
									  pCategoryWeight);
	}
	CATCMDBTN_VECTOR& GetCmdBtnVector() { return m_CatCmdBtnVector; }
	STDMETHODIMP GetCommandButtons(PROPCAT CatID, VARIANT* pCatCmdBtns)
	{
		return AcOpmGetCategoryCommandButtons(reinterpret_cast<IUnknown*>(this),
											  GetResourceInstance(), GetCmdBtnVector(), CatID,
											  pCatCmdBtns);
	}
	STDMETHODIMP GetParentCategory(PROPCAT CatID, PROPCAT* pParentCatID)
	{
		return AcOpmGetParentCategory(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID,
									  pParentCatID);
	}
	bool IsDefaultCategoryEntry(CATEGORY_ENTRY in)
	{
		if (in.m_CatID != -1)
			return false;
		if (in.m_nWeight != -1)
			return false;
		if (in.m_ParentCatID != -1)
			return false;
		if (in.m_nDescId != 0)
			return false;
		if (in.m_nNameId != 0)
			return false;
		return true;
	}
	bool IsDefaultCmdBtnEntry(CATCMDBTN_ENTRY in)
	{
		if (in.m_CatID != -1)
			return false;
		if (in.m_lpEnBtnBmpRes != NULL)
			return false;
		if (in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_lpDisBtnBmpRes != NULL)
			return false;
		if (in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_nStyle != NULL)
			return false;
		if (in.m_pfnBtnProc != NULL)
			return false;
		if (in.m_nBtnNameId != 0)
			return false;
		return true;
	}
	STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
	{
		return AcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(),
										  dispid, ppropcat);
	}
};

#include "IcArxPackPop.h"

#define ICategorizeProperties2Impl IAcPiCategorizePropertiesImpl
