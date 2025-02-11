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
***     Description: Declaration of CAdUiPaletteSetDockFrame class
***
*****************************************************************************/
#pragma once

#include <afxpriv.h>
#include "../AdAChar.h"
#include "../aduiButton.h"
#include "../aduiTheme.h"

class CPaletteSetTooltip;
class CAdUiDropTarget;
class CAdUiPaletteSet;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiPaletteSetDockFrame : public CMiniDockFrameWnd
{
	friend class CAdUiImpPaletteSet;
	friend class CAdUiDockDragContext;
	friend class CAdUiDockBarMutator;
	friend class CAdUiAnchorBar;

	DECLARE_DYNCREATE(CAdUiPaletteSetDockFrame)

public:
	enum ContainedBarType
	{
		Unknown,
		Standard,
		AdskBar
	};
	enum AdUiTitleBarLocation
	{
		kLeft = 0,
		kRight
	};

protected:
	enum ContainedBarType m_nContainedBarType = ContainedBarType::Unknown;
	bool m_bZOrderChanged = false;

private:
	enum AdUiSkBtnItems
	{
		kBtnUnknown = -1,
		kBtnPushPin = 0,
		kBtnOptionMenu = 1,
		kBtnClose = 2,
		kBtnIcon = 3
	};
	enum AdUiSkIds
	{
		kRollupTimerId = 12305,
		kRolloutTimerId = 12306,
		kCursorCheckTimerId = 12307
	};
	enum AdUiSkUiFlags
	{
		kImgListUnpinnedLeft = 0,
		kImgListUnpinnedRight = 1,
		kImgListPinnedLeft = 2,
		kImgListPinnedRight = 3,
		kImgListOptionMenuLeft = 4,
		kImgListOptionMenuRight = 5,
		kImgListClose = 6,
		kImgList_Count = 7
	};
	CRect m_rectSize;
	CSize m_sizeShadow;
	CRect m_rectCaptionText;
	CImageList m_imgListGui;
	CImageList m_imgListIcon;
	DWORD m_dwUiTransientFlags =0;
	bool m_bRolloutTimerSet = false;
	bool m_bRollupTimerSet = false;
	CPaletteSetTooltip* m_pToolTip = nullptr;
	BOOL m_bAllowSnapping = false;
	CAdUiDropTarget* m_pDropTarget = nullptr;
	AdUiTitleBarLocation m_orphanTitleBarLoc = AdUiTitleBarLocation::kLeft;
	bool m_bUserEnteredAutoHideMode = false;
	CRect m_rectWorkArea;
	bool m_bDelayRolledOut = false;

	static DWORD m_nRollupDelay;
	static DWORD m_nRolloutDelay;
	static DWORD m_nHoldopenDelay;


private:
	void GetNonClientSize(CSize& size);
	DWORD GetRolloutDelay() { return m_nRolloutDelay; }
	DWORD GetRollupDelay() { return m_bDelayRolledOut ? m_nHoldopenDelay : m_nRollupDelay; }
	int GetTopGrabbableHeight();
	void InitFonts();
	void OnOptionsMenu();
	void OnSystemMenu(CPoint pos);
	void RollOut(CPoint* pPt, bool bDelay = false);
	BOOL RolledUp() { return (!m_rectSize.IsRectEmpty()); }
	void SetRolloutDelay();
	void SetRolloutTimer();
	void SetRollupDelay();
	void SetRollupTimer();
	void SnapToRect(CRect& rect, WINDOWPOS* pWndpos, int nPaletteWidth, int nPaletteHeight,
					bool bSnapInside, bool bSnapOutside);
	bool btnPress(CAdUiPaletteSetDockFrame::AdUiSkBtnItems eBtn, LPPOINT pt);
	void btnPressClose();
	void btnPressOptionMenu();
	void btnPressPushPin();
	void displayTip(LPPOINT pt);
	void doButtonBlt(CDC* pDC, int nImage, CRect& rcBtn);
	void doDrawBorder(CDC* pDC);
	void doDrawButton(CDC* pDC, CAdUiPaletteSetDockFrame::AdUiSkBtnItems btnItem,
					  BOOL bErase = false);
	void doDrawCaption(CDC* pDC);
	void doDrawStatus(CDC* pDC);
	void doEraseBackground(CDC* pDC, const CRect& rect, BOOL bErase);
	void getBorderRects(CRect& rectTop, CRect& rectBottom, CRect& rectSide);
	void getButtonItemRect(CAdUiPaletteSetDockFrame::AdUiSkBtnItems eBtn, CRect& rect);
	int getMetrics(UINT nItem);
	void getRegion(CRgn& rgn);
	void getWndCaptionRect(CRect& rect);
	void getWndSizerRect(CRect& rect);
	void getWndStatusRect(CRect& rect);
	BOOL isImgListItemValid(int nItem);
	void ncPaint(UINT nPtFlags);
	void nonclientToWindow(CRect& rect);
	void rollupDlg(BOOL bRollup = 1);
	void setWindowRgn();
	bool shouldWindowBeRolledUp(CWnd* pWndUnderCursor, CAdUiPaletteSet& ps) const;
	void windowToNonClient(CRect& rect);

protected:
	bool CanAutoCADTakeFocus();
	bool CanFrameworkTakeFocus();
	void ForceChildRepaint();
	CAdUiPaletteSet* GetPaletteSet();
	BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);
	virtual LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnDragScroll(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL PreTranslateMessage(MSG* msg);
	void UpdateThemeElements();

	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnClose();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pos);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnDisplayChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEnterSizeMove(WPARAM, LPARAM);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnExitSizeMove(WPARAM, LPARAM);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnLButtonDown(UINT nHitTest, CPoint pt);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nHitTest, CPoint pt);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg LRESULT OnNcCalcSize(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint pt);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint pt);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint pt);
	afx_msg void OnNcPaint();
	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint pt);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint pt);
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pwnd, UINT nHitTest, UINT msg);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT nSide, LPRECT pRect);
	afx_msg void OnTimer(UINT_PTR nIdEvent);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiPaletteSetDockFrame();
	~CAdUiPaletteSetDockFrame();
	void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	BOOL Create(CWnd* pParent, DWORD dwBarStyle);
	enum ContainedBarType GetContainedBarType();
	static bool HidePalettes();
	void SetAutoRollup(BOOL bSet);
	void SetTitleBarLocation(CAdUiPaletteSetDockFrame::AdUiTitleBarLocation);
	static bool ShowPalettes();
	CAdUiPaletteSetDockFrame::AdUiTitleBarLocation TitleBarLocation();
};


#include "IcArxPackPop.h"
