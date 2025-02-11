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
***     Description: Declaration of CAdUiDialogWorksheet class
***
*****************************************************************************/
#pragma once

#include "aduiDialog.h"

#include "icarx/AdUiThemeElement.h"

class CAdUiTheme;
class CAdUiWorksheetDraw;

class ADUI_PORT CAdUiDialogWorksheet : public CAdUiDialog
{
	friend class CAdUiWorksheetThemeModReactor;

	DECLARE_DYNAMIC(CAdUiDialogWorksheet);

protected:
	HICON m_hIcon;

private:
	static CAdUiWorksheetDraw* s_pDefaultDraw;
	static CAdUiWorksheetDraw* s_PlatformDefaultDraw;
	CAdUiWorksheetDraw* m_pDraw;

protected:
	CAdUiDialogWorksheet(UINT ID, CWnd* pParent = nullptr, HINSTANCE hResInst = nullptr);
	CAdUiDialogWorksheet(UINT ID, const CAdUiWorksheetDraw& draw, CWnd* pParent = nullptr,
						 HINSTANCE hResInst = nullptr);

	void DoDataExchange(CDataExchange* pDX) override;
	void PostNcDestroy() override;


	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMoving(UINT nSide, LPRECT lpRect);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcDestroy();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnNcRButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);

	DECLARE_MESSAGE_MAP()

public:
	~CAdUiDialogWorksheet();
	BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
				  int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu,
				  LPVOID lpParam = nullptr) override;
	BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
				  const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam = nullptr) override;
	BOOL DestroyWindow() override;
	CAdUiTheme* GetTheme() const;
	BOOL OnInitDialog() override;
	BOOL PreCreateWindow(CREATESTRUCT & cs) override;
	BOOL PreTranslateMessage(MSG * pMsg) override;
	static CAdUiWorksheetDraw* SetDefaultDraw(CAdUiWorksheetDraw* pDraw);
	void SetDraw(const CAdUiWorksheetDraw* pDraw);
	CAdUiTheme* SetTheme(CAdUiTheme* pTheme);
	virtual void ThemeModified(AdUiThemeElement element);
};
