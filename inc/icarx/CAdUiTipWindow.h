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
***     Description: Declaration of CAdUiTipWindow class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "../adui_port.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiTipWindow : public CWnd
{
	DECLARE_DYNAMIC(CAdUiTipWindow)

protected:
	static LPCTSTR m_className;
	static const UINT_PTR m_timerEvent;
	BOOL m_bUseText = FALSE;
	CWnd* m_control = nullptr;
	CWnd* m_owner = nullptr;
	UINT_PTR m_timerId = -1;

private:
	void ForwardClickMessage(UINT msg, UINT nFlags, CPoint& point, BOOL focus);

protected:
	virtual void DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior);
	virtual void DrawContent(CDC& dc, CRect& rInterior);
	void StartTimer(DWORD ms = 50);
	void StopTimer();

	afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNcDestroy();
	afx_msg void OnPaint();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiTipWindow();
	~CAdUiTipWindow() noexcept;
	virtual BOOL Create(CWnd* owner);
	CWnd* GetControl();
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	BOOL GetUseText();
	virtual void Hide();
	CWnd* Owner();
	void SetControl(CWnd* control);
	void SetUseText(BOOL useText);
	virtual void Show();
};


#include "IcArxPackPop.h"
