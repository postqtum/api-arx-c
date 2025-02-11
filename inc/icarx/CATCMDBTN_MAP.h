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

typedef int PROPCAT;
typedef BOOL (*BUTTONPROC)(IAcPiCommandButton* pButton, VARIANT Objects);

#include "IcArxPackPush.h"

struct CATCMDBTN_ENTRY
{
	PROPCAT m_CatID;
	UINT m_nBtnNameId;
	const ACHAR* m_lpEnBtnBmpRes;
	UINT m_nEnBtnBmpType;
	const ACHAR* m_lpDisBtnBmpRes;
	UINT m_nDisBtnBmpType;
	long m_nStyle;
	BUTTONPROC m_pfnBtnProc;
};

#include "IcArxPackPop.h"

#define BEGIN_CATCMDBTN_MAP()                \
	static CATCMDBTN_ENTRY* GetCmdBtnArray() \
	{                                        \
		static CATCMDBTN_ENTRY pCatCmdBtnArray[] = {

#define CATCMDBTN_MAP_ENTRY(nId, NameId, lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, \
							lpDisBtnBmpType, nStyle, pfnBtnProc)                        \
	{nId,                                                                               \
	 static_cast<UINT>(NameId),                                                         \
	 lpEnBtnBmpRes,                                                                     \
	 static_cast<UINT>(lpEnBtnBmpType),                                                 \
	 lpDisBtnBmpRes,                                                                    \
	 static_cast<UINT>(lpDisBtnBmpType),                                                \
	 nStyle,                                                                            \
	 pfnBtnProc},

#define END_CATCMDBTN_MAP()                                           \
	{                                                                 \
		-1, 0u, NULL, static_cast<UINT>(PICTYPE_UNINITIALIZED), NULL, \
				static_cast<UINT>(PICTYPE_UNINITIALIZED), NULL, NULL  \
	}                                                                 \
	}                                                                 \
	;                                                                 \
	return pCatCmdBtnArray;                                           \
	}

typedef std::vector<CATCMDBTN_ENTRY> CATCMDBTN_VECTOR;
