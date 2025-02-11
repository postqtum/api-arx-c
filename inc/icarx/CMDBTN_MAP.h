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

#include <vector>
#include "../AdAChar.h"
#include "Acpi.h"

typedef BOOL (*BUTTONPROC)(IAcPiCommandButton* pButton, VARIANT Objects);

#include "IcArxPackPush.h"

struct CMDBTN_ENTRY
{
	UINT m_nBtnNameId;
	const ACHAR* m_lpEnBtnBmpRes;
	UINT m_nEnBtnBmpType;
	const ACHAR* m_lpDisBtnBmpRes;
	UINT m_nDisBtnBmpType;
	long m_nStyle;
	BUTTONPROC m_pfnBtnProc;
};

#include "IcArxPackPop.h"

#define BEGIN_CMDBTN_MAP()                    \
	static CMDBTN_ENTRY* GetPropCmdBtnArray() \
	{                                         \
		static CMDBTN_ENTRY pCmdBtnArray[] = {

#define CMDBTN_MAP_ENTRY(NameId, lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, lpDisBtnBmpType, \
						 nStyle, pfnBtnProc)                                                     \
	{NameId, lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, lpDisBtnBmpType, nStyle, pfnBtnProc},

#define END_CMDBTN_MAP()                                                                    \
	{                                                                                       \
		0, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, NULL \
	}                                                                                       \
	}                                                                                       \
	;                                                                                       \
	return pCmdBtnArray;                                                                    \
	}

typedef std::vector<CMDBTN_ENTRY> CMDBTN_VECTOR;
