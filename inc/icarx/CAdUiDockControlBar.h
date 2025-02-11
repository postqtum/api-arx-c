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
***     Description: Declaration of CAdUiDockControlBar class
***
*****************************************************************************/
#pragma once

#include <afxpriv.h>
#include "../AdAChar.h"
#include "../aduiButton.h"
#include "../aduiTheme.h"

#define ADUI_DOCK_CS_DESTROY_ON_CLOSE 0x01
#define ADUI_DOCK_CS_STDMOUSECLICKS 0x02

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiDockControlBar : public CControlBar
{
	DECLARE_DYNAMIC(CAdUiDockControlBar)

	friend class CAdUiDockFrame;
	friend class CAdUiPaletteSetDockFrame;
	friend class CAdUiDockDragContext;
	friend class CAdUiDockBar;
	friend class CAdUiImpPaletteSet;
	friend class CAdUiDockBarMutator;
	friend class CAdUiDockControlBarThemeModReactor;

private:
	static CObArray* m_paBars;
	CSize m_FloatSize;
	CSize m_HorzDockSize;
	CSize m_VertDockSize;
	CPoint m_FloatingPosition;
	bool m_bAllowDockingMenuItemState;
	int m_Style;
	CSize m_PrevSize;
	BOOL m_bPrevFloating;
	CAdUiBitmapButton m_closeBtn;
	CAdUiBitmapButton m_pinBtn;
	CLSID m_ID;
	bool m_bShowCloseButton;
	static int m_nLastBarID;
	static bool m_bToolsRestartMode;
	CRect m_PersistedDockRect;
	CRect m_PersistedFloatRect;

protected:
	enum
	{
		btnWidth = 12,
		btnHeight = 12,
		idCloseBtn = 10001,
		idPinBtn = 10002
	};

private:
	LRESULT AddMenuItems(WPARAM wParam, LPARAM lParam);
	void Draw3DRect(CDC* pDC, LPRECT lpRect, CPen* pPenGray);
	void LoadDefaultLocation(UINT nOrientation, RECT* pSizeFloating);
	void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	void PaintBar(CDC* pDC);
	static void RemoveBars();
	void Resized(int cx, int cy, BOOL bFloating, int flags);
	void SetDockFlag(DWORD dwStyle);
	LRESULT WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);

protected:
	virtual BOOL AddCustomMenuItems(LPARAM hMenu);
	bool CloseButtonVisible() { return m_bShowCloseButton; }
	virtual BOOL CreateControlBar(LPCREATESTRUCT lpCreateStruct);
	virtual void GetFloatingMinSize(long* pnMinWidth, long* pnMinHeight);
	void GetUsedRect(CRect& rect);
	static LRESULT MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
	virtual bool OnClosing();
	BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnUserSizing(UINT, LPRECT) {}
	virtual void PaintControlBar(CDC* pDC);
	void RepositionOrHideButtons();
	void ShowCloseButton(bool bShow) { m_bShowCloseButton = bShow; }
	virtual void SizeChanged(CRect*, BOOL, int) {}


	afx_msg void OnAllowDock();
	afx_msg void OnAnchor();
	afx_msg void OnAnchorLeft();
	afx_msg void OnAnchorRight();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHideBar();
	afx_msg void OnPaint();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiDockControlBar(int nStyle = 2);
	~CAdUiDockControlBar();
	bool AdjustVertDockedBarHeight(int nHeight);
	bool AllowDockingMenuItemState() { return m_bAllowDockingMenuItemState; }
	bool Anchored(bool bHiddenReturnsLastState);
	bool Anchored();
//#ifdef _DEBUG //<progesoft comment="Removed preprocessor directive" />
	void AssertValid() const;
//#endif //<progesoft comment="Removed preprocessor directive" />
	CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);
	virtual bool CanFrameworkTakeFocus() { return false; }
	BOOL Create(CWnd * pParent, LPCTSTR lpszTitle, UINT nID,
				DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
				const RECT& rect = CFrameWnd::rectDefault);
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect,
				CWnd* pParentWnd, UINT nID, CCreateContext* pContext = nullptr);
	void DockControlBar(UINT nOrientation, RECT * pRect);
	void EnableDocking(DWORD dwDockStyle);
	DWORD GetDockStyle() { return m_dwDockStyle; }
	void GetFloatingRect(CRect * pFloatingPos);
	const CSize& GetHorzDockSize() { return m_HorzDockSize; }
	void GetPersistedDockingRect(CRect * pDockRect);
	void GetPersistedFloatingRect(CRect * pFloatRect);
	CAdUiTheme* GetTheme();
	LONG GetTitleBarSize();
	CLSID* GetToolID() { return &m_ID; }
	static bool GetToolsRestartMode();
	const CSize& GetVertDockSize() { return m_VertDockSize; }
	static bool HidePalettes();
	void InitFloatingPosition(CRect * pSizeFloating);
	BOOL IsFloating();
	virtual BOOL Load(IUnknown * pUnk);
	void RestoreControlBar(UINT nPreferredOrientation = 59420, CRect* pSizeFloating = nullptr);
	virtual BOOL Save(IUnknown * pUnk);
	void SetAllowDockingMenuItemState(bool bState) { m_bAllowDockingMenuItemState = bState; }
	void SetHorzDockSize(const CSize& size) { m_HorzDockSize = size; }
	CAdUiTheme* SetTheme(CAdUiTheme * pTheme);
	void SetToolID(LPCGUID pCLSID);
	static void SetToolsRestartMode(bool bMode);
	void SetVertDockSize(const CSize& size) { m_VertDockSize = size; }
	static bool ShowPalettes();
	virtual void ThemeModified(AdUiThemeElement element);
	void TileInRow();
};


#include "IcArxPackPop.h"
