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
***     Description: Declaration of CAdUiGroupCtrl class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "../acarray.h"
#include "../aduiMessage.h"
#include "CAdUiGroupCtrl.h"

#include "CAdToolTipCtrl.h"

class CAdUiTheme;

typedef void (*AdUiBmpBtnFcnPtr)(CWnd*);

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

struct AdUiGroupCtrlData
{
	int nWndIndex = 0;
	CString title;
	CWnd* pWnd = nullptr;
	DWORD dwBtnCookie = DWORD_MAX;
}
;
using groupData = AdUiGroupCtrlData;
typedef AcArray<groupData> ADUIGROUPCTRLDATALIST;

struct AdUiBmpBtnData
{
	CString strResId;
	CBitmap* pBmp = nullptr;
	AdUiBmpBtnFcnPtr fcnPtr = nullptr;
	CString tooltip;
	DWORD dwCookie = 0;
};

using bmpBtnData = AdUiBmpBtnData;
typedef AcArray<bmpBtnData> ADUIHEADERBTNLIST;

class CAdUiGroupCtrlImp;
class ADUI_PORT CAdUiGroupCtrl : public CStatic
{
	DECLARE_DYNAMIC(CAdUiGroupCtrl);

protected:
	CAdUiTheme* m_pTheme = nullptr;

protected:
	CString m_csTitle;
	bool m_bMinimized = false;
	bool m_bUseDialogTheme = false;
	bool m_bActive = false;
	bool m_bHideGroupHeader = false;
	int m_nHeaderHeight = false;
	int m_nRestoreHeight = false;
	int m_nSelIndex = -1;
	DWORD m_nStyle = 0;
	DWORD m_dwBtnId = -1;
	ADUIHEADERBTNLIST m_bmpBtnList;
	ADUIGROUPCTRLDATALIST m_groupList;

private:
	static LOGFONT m_lf;
	CAdUiGroupCtrlImp* m_imp;

protected:
	virtual void DeselectGroupHeader()
	{
		CDC* pDC = GetWindowDC();
		DrawGroupHeader(pDC);
		ReleaseDC(pDC);
	}
	virtual void DrawGroupContent(CDC* pDC);
	virtual void DrawGroupHeader(CDC* pDC);
	void DrawHeaderBorder(CDC* pDC, CRect& rect);
	static CAdToolTipCtrl* GetToolTipControl();
	void OnChevronClicked();
	BOOL PreTranslateMessage(MSG* pMsg);
	static LOGFONT& font();

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC*, CWnd*, UINT);
	afx_msg BOOL OnEraseBkgnd(CDC*) { return 1; }
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS*);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint);
	afx_msg void OnNcPaint();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

public:
	CAdUiGroupCtrl();
	~CAdUiGroupCtrl() throw();
	virtual bool AddBmpBtnToHeader(LPCTSTR pszResName, AdUiBmpBtnFcnPtr fcnPtr, DWORD& dwCookie,
								   LPCTSTR pszToolTip);
	virtual bool AddBmpBtnToHeader(CBitmap* pBmp, AdUiBmpBtnFcnPtr fcnPtr, DWORD& dwCookie,
								   LPCTSTR pszToolTip);
	virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, CBitmap* pBMP = nullptr);
	virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszToolTip, CBitmap* pBMP);
	virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszResName);
	virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszToolTip, LPCTSTR pszResName);
	bool GetActive() { return m_bActive; }
	int GetHeaderHeight() { return m_nHeaderHeight; }
	bool GetHideGroupHeader() { return m_bHideGroupHeader; }
	bool GetMinimized() const { return m_bMinimized; }
	int GetSelIndex();
	DWORD GetStyle() { return m_nStyle; }
	CAdUiTheme* GetTheme() const { return m_pTheme; }
	CString GetTitle() { return m_csTitle; }
	virtual void ModGroupStyle(DWORD styleRemove, DWORD styleAdd);
	virtual bool RemoveBmpBtnFromHeader(DWORD dwCookie);
	void SetActive(bool bActive);
	virtual void SetFont(CFont* pFont, BOOL bRedraw);
	virtual void SetFont(CFont* pFont);
	void SetHeaderHeight(int nHeight) { m_nHeaderHeight = nHeight; }
	void SetHideGroupHeader(bool bHide) { m_bHideGroupHeader = bHide; }
	virtual void SetMinimized(bool bMinimized) { m_bMinimized = bMinimized; }
	void SetSelIndex(int nSelIndex);
	void SetStyle(DWORD nStyle) { m_nStyle = nStyle; }
	virtual void SetTheme(CAdUiTheme* pTheme);
	void SetTitle(LPCTSTR pszTitle) { m_csTitle = pszTitle; }
	void SetUseDialogTheme(bool bUseDialogTheme);
	virtual bool ShowWnd(CWnd* pWnd);
	bool UseDialogTheme() const { return m_bUseDialogTheme; }
};

#include "IcArxPackPop.h"
