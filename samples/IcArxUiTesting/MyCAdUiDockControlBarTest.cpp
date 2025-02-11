/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
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
#include "stdafx.h"
#include "MyCAdUiDockControlBarTest.h"

IMPLEMENT_DYNAMIC(MyCAdUiDockControlBar, CAdUiDockControlBar)
BEGIN_MESSAGE_MAP(MyCAdUiDockControlBar, CAdUiDockControlBar)

END_MESSAGE_MAP()

static const GUID nameClassId{
        0x47703403, 0xd4de, 0x4b80, {0xb9, 0xc7, 0x23, 0xeb, 0xa1, 0x40, 0x14, 0xd8}};

BOOL MyCAdUiDockControlBar::Create(
        CWnd* pParent, LPCTSTR lpszTitle, UINT nID, DWORD dwStyle, const RECT& rect)
{
	if (!__super::Create(pParent, lpszTitle, nID, dwStyle, rect))
	{
		return FALSE;
	}
	SetToolID(&nameClassId);
	return TRUE;
}
