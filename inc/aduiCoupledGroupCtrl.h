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
***     Description: Declaration of CAdUiCoupledGroupCtrl class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class CAdUiGroupCtrl;
class CAdUiTheme;

#define ADUI_DEFAULT_TREE_TO_DETAILS_RATIO 0.4

class ADUI_PORT CAdUiCoupledGroupCtrl : public CWnd
{
	DECLARE_DYNAMIC(CAdUiCoupledGroupCtrl);

protected:
	COLORREF m_crNCBackground = 0;
	COLORREF m_crSplitter = 0;
	CBrush m_bkBrush;

protected:
	CAdUiGroupCtrl* m_pAdUiTopWnd = nullptr;
	CAdUiGroupCtrl* m_pAdUiBottomWnd = nullptr;
	CWnd* m_pTopWnd = nullptr;
	CWnd* m_pBottomWnd = nullptr;
	double m_topToWholeRatio = 0.0;
	bool m_bDragging = false;
	bool m_bSplitterEnabled = false;
	CPoint m_ptLast;
	CRect m_rtSpace;
	CAdUiTheme* m_pTheme = nullptr;

protected:
	bool IsAnyCtrlMinimizedOrIconic();
	void ResizeChildren(int cx, int cy);
	bool ValidateCtrls();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint);
	afx_msg void OnMouseMove(UINT nFlags, CPoint);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiCoupledGroupCtrl();
	~CAdUiCoupledGroupCtrl() noexcept;
	virtual void AddCouple(CAdUiGroupCtrl* pAdUiTopWnd, CAdUiGroupCtrl* pAdUiBottomWnd);
	virtual void AddCouple(CWnd* pWndTop, CWnd* pWndBottom);
	virtual void AddCouple(CAdUiGroupCtrl* pAdUiTopWnd, CWnd* pWndBottom);
	virtual void AddCouple(CWnd* pWndTop, CAdUiGroupCtrl* pAdUiBottomWnd);
	bool GetSplitterEnabled() { return this->m_bSplitterEnabled; }
	CAdUiTheme* GetTheme() const;
	double GetTopToWholeRatio() const { return this->m_topToWholeRatio; }
	virtual void MinMaxOneChild(CWnd* pWnd, bool bMinimized);
	void SetSplitterEnabled(bool bSplitterEnabled) { this->m_bSplitterEnabled = bSplitterEnabled; }
	void SetTheme(CAdUiTheme* pTheme);
	void SetTopToWholeRatio(double topToWholeRatio);
};


#include "icarx/IcArxPackPop.h"
