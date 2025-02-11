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

typedef int PROPCAT;

#include "IcArxPackPush.h"

struct PER_PROP_DISP_ENTRY
{
	DISPID m_dispid;
	const ACHAR* m_ProgID;
	const ACHAR* m_lpLeftIconRes;
	UINT m_nLeftIconType;
	const ACHAR* m_lpEllipsisBmpRes;
	UINT m_nEllipsisBmpType;
	COLORREF m_TextColor;
	bool m_bFullView;
	DWORD m_dwIntegralHeight;
	long m_nWeight;
};

#include "IcArxPackPop.h"

#ifndef PROP_TEXTCOLOR_DEFAULT
#	define PROP_TEXTCOLOR_DEFAULT 0x80000008
#endif	// PROP_TEXTCOLOR_DEFAULT

#define BEGIN_PERPROPDISPLAY_MAP()                       \
	static PER_PROP_DISP_ENTRY* GetPerPropDisplayArray() \
	{                                                    \
		static PER_PROP_DISP_ENTRY pPerPropDisplayArray[] = {

#define PROP_DISP_ENTRY(dispid, progid, lpLeftIconRes, lpLeftIconType, lpEllipsisBmpRes,          \
						lpEllipsisBmpType, textcolor, bFullView, dwIntegralHeight, nWeight)       \
	{dispid,	progid,	   lpLeftIconRes,	 lpLeftIconType, lpEllipsisBmpRes, lpEllipsisBmpType, \
	 textcolor, bFullView, dwIntegralHeight, nWeight},

#define END_PERPROPDISPLAY_MAP()                                                        \
	{                                                                                   \
		-1, NULL, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, (UINT)PICTYPE_UNINITIALIZED, \
				PROP_TEXTCOLOR_DEFAULT, false, (DWORD)-1, -1                            \
	}                                                                                   \
	}                                                                                   \
	;                                                                                   \
	return pPerPropDisplayArray;                                                        \
	}

typedef std::vector<PER_PROP_DISP_ENTRY> PROP_DISP_VECTOR;
