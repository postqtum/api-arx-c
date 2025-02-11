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
***     Description: Declaration of CAdUiDockFrame class
***
*****************************************************************************/
#pragma once

#include <afxpriv.h>
#include "../AdAChar.h"
#include "../aduiButton.h"
#include "../aduiTheme.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiDockFrame : public CMiniDockFrameWnd
{
	DECLARE_DYNCREATE(CAdUiDockFrame)

public:
	enum ContainedBarType
	{
		Unknown,
		Standard,
		AdskBar
	};

protected:
	enum ContainedBarType m_nContainedBarType = ContainedBarType::Unknown;
	bool m_bZOrderChanged = false;

protected:
	bool CanAutoCADTakeFocus();
	bool CanFrameworkTakeFocus();
	void ForceChildRepaint();
	BOOL PreCreateWindow(CREATESTRUCT& cs);

	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint pt);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT nSide, LPRECT pRect);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);

	DECLARE_MESSAGE_MAP()
public:
	CAdUiDockFrame();
	enum ContainedBarType GetContainedBarType();
};


#include "IcArxPackPop.h"
