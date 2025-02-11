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
***     Description: Declaration of IAcPiPropertyDisplayImpl class
***
*****************************************************************************/
#pragma once

#include <atldef.h>
#include "acpi.h"
#include "../opmimp.h"

#include "IcArxPackPush.h"

template<class T>
class ATL_NO_VTABLE IAcPiPropertyDisplayImpl : public IAcPiPropertyDisplay
{
public:
	PROP_DISP_VECTOR m_PropDispVector;

public:
	IAcPiPropertyDisplayImpl()
	{
		m_PropDispVector.clear();
		int i = 0;
		while (!IsDefaultPerPropDispEntry(T::GetPerPropDisplayArray()[i]))
		{
			m_PropDispVector.push_back(T::GetPerPropDisplayArray()[i]);
			i++;
		}
	}
	virtual ~IAcPiPropertyDisplayImpl() = default;

	STDMETHODIMP GetCustomPropertyCtrl(VARIANT Id, LCID lcid, BSTR* psProgId)
	{
		return AcOpmGetCustomPropertyCtrl(reinterpret_cast<IUnknown*>(this),
										  GetPerPropDisplayVector(), Id, lcid, psProgId);
	}
	PROP_DISP_VECTOR& GetPerPropDisplayVector() { return m_PropDispVector; }
	STDMETHODIMP GetPropTextColor(VARIANT Id, OLE_COLOR* pTextColor)
	{
		return AcOpmGetPropTextColor(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(),
									 Id, pTextColor);
	}
	STDMETHODIMP GetPropertyIcon(VARIANT Id, IUnknown** ppIcon)
	{
		return AcOpmGetPropertyIcon(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
									GetPerPropDisplayVector(), Id, ppIcon);
	}
	STDMETHODIMP GetPropertyWeight(VARIANT Id, long* pPropertyWeight)
	{
		return AcOpmGetPropertyWeight(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(),
									  Id, pPropertyWeight);
	}
	virtual HINSTANCE GetResourceInstance() = 0;
	bool IsDefaultPerPropDispEntry(PER_PROP_DISP_ENTRY in)
	{
		if (in.m_bFullView != false)
			return false;
		if (in.m_ProgID != NULL)
			return false;
		if (in.m_dispid != -1)
			return false;
		if (in.m_dwIntegralHeight != -1)
			return false;
		if (in.m_lpEllipsisBmpRes != NULL)
			return false;
		if (in.m_nEllipsisBmpType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_lpLeftIconRes != NULL)
			return false;
		if (in.m_nLeftIconType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_nWeight != -1)
			return false;
		if (in.m_TextColor != 0x80000008)
			return false;
		return true;
	}
	STDMETHODIMP IsFullView(VARIANT Id, VARIANT_BOOL* pbVisible, DWORD* pIntegralHeight)
	{
		return AcOpmIsPropFullView(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id,
								   pbVisible, pIntegralHeight);
	}
};

#include "IcArxPackPop.h"

#define IPerPropertyDisplayImpl IAcPiPropertyDisplayImpl
