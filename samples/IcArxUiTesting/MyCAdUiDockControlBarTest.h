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
#pragma once

#include <inc/aduiDock.h>

class MyCAdUiDockControlBar : public CAdUiDockControlBar
{
	DECLARE_DYNAMIC(MyCAdUiDockControlBar)
	DECLARE_MESSAGE_MAP()
public:
	~MyCAdUiDockControlBar()
	{
		OnClosing();
	}
	virtual BOOL Create(CWnd* pParent, LPCTSTR lpszTitle, UINT nID = 0,
	        DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
	        const RECT& rect = CFrameWnd::rectDefault);
};
