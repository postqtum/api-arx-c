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
***     Description: Declaration of IAcPiPropCommandButtonsImpl class
***
*****************************************************************************/
#pragma once

#include <atldef.h>
#include "acpi.h"
#include "../opmimp.h"

#include "IcArxPackPush.h"

template<class T>
class ATL_NO_VTABLE IAcPiPropCommandButtonsImpl : public IAcPiPropCommandButtons
{
public:
	CMDBTN_VECTOR m_CmdBtnVector;

public:
	IAcPiPropCommandButtonsImpl()
	{
		m_CmdBtnVector.clear();
		int i = 0;
		while (!IsDefaultCmdBtnEntry(T::GetPropCmdBtnArray()[i]))
		{
			m_CmdBtnVector.push_back(T::GetPropCmdBtnArray()[i]);
			i++;
		}
	}
	virtual ~IAcPiPropCommandButtonsImpl() = default;

	STDMETHODIMP GetButtons(VARIANT* pCmdBtns)
	{
		return AcOpmGetCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(),
									  GetCmdBtnVector(), pCmdBtns);
	}
	CMDBTN_VECTOR& GetCmdBtnVector() { return m_CmdBtnVector; }
	virtual HINSTANCE GetResourceInstance() = 0;
	bool IsDefaultCmdBtnEntry(CMDBTN_ENTRY in)
	{
		if (in.m_lpEnBtnBmpRes != NULL)
			return false;
		if (in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_lpDisBtnBmpRes != NULL)
			return false;
		if (in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
			return false;
		if (in.m_pfnBtnProc != NULL)
			return false;
		if (in.m_nBtnNameId != NULL)
			return false;
		if (in.m_nStyle != NULL)
			return false;
		return true;
	}
};

#include "IcArxPackPop.h"

#define IPropCommandButtonsImpl IAcPiPropCommandButtonsImpl
