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
***     Description: Declaration of CAdUiPaletteSet class
***
*****************************************************************************/
#pragma once

#include <afxtempl.h>

#include "AcColorThemeEnum.h"
#include "aduiTheme.h"

#include "icarx/CAdUiDockControlBar.h"

class CAdUiImpPaletteSet;
class CAdUiPalette;
class CAdUiTheme;

#define PSS_AUTO_ROLLUP 0x00000002
#define PSS_PROPERTIES_MENU 0x00000004
#define PSS_CLOSE_BUTTON 0x00000008
#define PSS_EDIT_NAME 0x00000010
#define PSS_SNAP 0x00000020
#define PSS_SINGLE_PALETTE_TAB 0x00000040
#define PSS_USE_SINGLE_PALETTE_TAB_NAME 0x00000080
#define PSS_SINGLE_ROW_HORZ_DOCK 0x00000200
#define PSS_NOTIFY 0x00000400
#define PSS_SINGLE_ROW_NOVERTRESIZE 0x00000800
#define PSS_SINGLE_COL_VERT_DOCK 0x00001000
#define PSS_NO_ROLLUP_BUTTON 0x00002000
#define PSS_NO_ICON 0x00004000
#define PSS_NO_TITLEBAR 0x00008000
#define PSS_AUTO_ROLLUP_PAUSE_ON_MODAL_DIALOG 0x00010000

#define ADUI_HT_CAPTION 1
#define ADUI_HT_OPTION_BUTTON 2
#define ADUI_HT_ROLLUP_BUTTON 3
#define ADUI_HT_CLOSE_BUTTON 4
#define ADUI_HT_GRIP 5
#define ADUI_HT_TABS 6
#define ADUI_HT_PALETTE 7
#define ADUI_HT_TAB_OVERFLOW 8
#define ADUI_HT_PALETTESET 9

#include "icarx/IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiPaletteSet : public CAdUiDockControlBar
{
	friend class CAdUiImpPaletteSet;
	friend class CAdUiPaletteSetDockFrame;
	friend class CAdUiAnchorBar;
	friend class CAdUiPalette;
	friend class CAdUiDockDragContext;
	DECLARE_DYNCREATE(CAdUiPaletteSet);

public:
	enum AdUiTitleBarLocation
	{
		kLeft = 0,
		kRight
	};

protected:
	CAdUiImpPaletteSet* m_pImpPS;

protected:
	virtual BOOL AddContextMenuItems(CMenu* pMenu, int nHitFlag, int nRightClkTab = 0);
	virtual void AutoRollupChanged(BOOL) {}
	bool CanFrameworkTakeFocus();
	virtual void EditName();
	void GetAdjustedClientRect(CRect& rect);
	virtual int GetBottomReservedHeight();
	virtual void GetMaximumSize(CSize& size);
	virtual void GetMinimumSize(CSize& size);
	virtual int GetTopReservedHeight();
	BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);
	virtual void OnContextMenu(CWnd* pWnd, CPoint pos);
	virtual void OnTabDrag(CPtrArray& arrayPalettes);
	virtual void PaletteActivated(CAdUiPalette*, CAdUiPalette*) {}
	virtual void PaletteAdded(CAdUiPalette*) {}
	virtual void PaletteRemoved(CAdUiPalette*) {}
	void SendThemeModifiedToPalettes();
	void ThemeModified(AdUiThemeElement element);

	afx_msg void EditPaletteName();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);
	afx_msg int OnCreate(LPCREATESTRUCT lpCs);
	afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);
	afx_msg BOOL OnEraseBkgnd(CDC* pdc);
	afx_msg LRESULT OnFloatStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetPaletteCount(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetPaletteName(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint pt);
	afx_msg void OnMenuClose();
	afx_msg void OnMenuMove();
	afx_msg void OnMenuSize();
	afx_msg void OnMouseMove(UINT nFlags, CPoint pt);
	afx_msg LRESULT OnNcCalcSize(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnOptionTranslucency();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnSetPaletteActive(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiPaletteSet(int nStyle = 0);
	~CAdUiPaletteSet() throw();
	int AddPalette(CAdUiPalette* pPalette);
	static void ApplyGlobalOpacities(BOOL bApply);
	BOOL AutoRollupStyle();
	BOOL CloseButtonStyle();
	BOOL Create(LPCTSTR strTitle, DWORD dwStyle, const RECT& rect, CWnd* pwndParent,
				DWORD dwPaletteSetStyle = 4 | 2 | 8 | 32);
	BOOL EditNameStyle();
	void EnableDocking(DWORD dwDockStyle);
	CAdUiPalette* GetActivePalette();
	int GetActivePaletteTabIndex();
	BOOL GetAutoRollup();
	void GetFullRect(CRect& rect);
	static int GetGlobalOpacity();
	static int GetGlobalRolloverOpacity();
	static UINT GetGlobalTransparency();
	CString GetName();
	BOOL GetNonClientSize(CSize& size);
	int GetOpacity() const;
	CAdUiPalette* GetPalette(int nIndex);
	int GetPaletteCount();
	DWORD GetPaletteSetStyle();
	int GetRolloverOpacity() const;
	int GetTabIndex(CAdUiPalette* pPalette);
	CAdUiTheme* GetTheme();
	HICON GetThemedIcon(bool bBigIcon = false) const;
	CFont* GetWindowFont();
	int InsertPalette(int iIndex, CAdUiPalette* pPalette);
	static BOOL IsGlobalOpacitiesApplied();
	BOOL Load(IUnknown* pUnk);
	virtual BOOL NameEditValidation(CEdit* pEdit);
	void OnTogglePin();
	BOOL PreTranslateMessage(MSG* msg);
	BOOL PropertiesMenuStyle();
	BOOL RemovePalette(int nPaletteIndex);
	BOOL RemovePalette(CAdUiPalette* pPalette);
	void RollOut(bool bDelay = false);
	void RollUp();
	BOOL RolledUp();
	BOOL Save(IUnknown* pUnk);
	BOOL SetActivePalette(CAdUiPalette* pPalette);
	BOOL SetActivePalette(int nPaletteIndex);
	bool SetAllowTransparency(CString key, bool bDefault);
	BOOL SetAutoRollup(BOOL bSet = 1);
	static BOOL SetGlobalOpacity(int nOpacity);
	static BOOL SetGlobalRolloverOpacity(int nOpacity);
	static bool SetGlobalTransparency(UINT flag);
	BOOL SetName(LPCTSTR pszName);
	BOOL SetOpacity(int nOpacity);
	void SetPaletteSetStyle(DWORD dwStyle);
	BOOL SetRolloverOpacity(int nOpacity);
	CAdUiTheme* SetTheme(CAdUiTheme* pTheme);
	HICON SetThemedIcon(HICON hIcon, AcColorThemeEnum theme = eAcadLightTheme,
						bool bBigIcon = false);
	void SetTitleBarLocation(CAdUiPaletteSet::AdUiTitleBarLocation loc);
	BOOL ShowIconStyle();
	BOOL ShowRollupButtonStyle();
	BOOL SinglePaletteTabStyle();
	BOOL SnapStyle();
	CAdUiPaletteSet::AdUiTitleBarLocation TitleBarLocation();
	virtual void TitleBarLocationUpdated(CAdUiPaletteSet::AdUiTitleBarLocation) {}
	void UpdateTabs();
	BOOL UseSinglePaletteTabNameStyle();
};


#include "icarx/IcArxPackPop.h"
