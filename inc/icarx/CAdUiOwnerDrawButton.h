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
***     Description: Declaration of CAdUiOwnerDrawButton class
***
*****************************************************************************/
#pragma once

#include "../aduiMessage.h"
#include "CAdUiTheme.h"
#include "CAdUiDrawTipText.h"

class CAdUiODButtonThemeModReactor;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiOwnerDrawButton : public CButton
{
	friend class CAdUiODButtonThemeModReactor;

	DECLARE_DYNAMIC(CAdUiOwnerDrawButton)

protected:
	CPoint m_lastMousePoint;
	CRect m_tipRect;
	CAdUiTheme* m_pTheme = nullptr;

protected:
	CWnd* m_aduiParent = nullptr;

protected:
	static const UINT_PTR m_timerEvent;
	bool m_bEnableDragDrop : 1;
	bool m_bEnableFastDraw : 1;
	bool m_bEnablePointedAt : 1;
	bool m_bIsPointedAt : 1;
	bool m_bIsStatic : 1;
	bool m_bIsToolButton : 1;
	bool m_bIsTrackButton : 1;
	UINT_PTR m_timerId = -1;
	int m_nPartId = -1;
	int m_nStateId = -1;
	UINT m_uEdge = -1;
	BOOL m_bMouseHover = false;

private:
	CAdUiODButtonThemeModReactor* m_pThemeModReactor = nullptr;
	HANDLE m_hVS = nullptr;

protected:
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	virtual void DrawBorder(CDC* pDC, CRect& r, COLORREF cr);
	virtual void DrawButton(CDC& dc, int w, int h, BOOL isDefault, BOOL isDisabled, BOOL isSelected,
							BOOL isFocused);
	void DrawContentText(CDC& dc, CString sText, CRect& rcText, BOOL isDisabled);
	virtual void DrawHotBorder();
	virtual void DrawPushButtonBorder(CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected);
	virtual void DrawToolButtonBorder(CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused);
	void DrawTransparentBitmap(CDC& dc, CBitmap& bmp, int x, int y, int w, int h, BOOL isDisabled);
	BOOL GetIsPointedAt();
	HANDLE GetVisualStylesTheme() { return m_hVS; }
	virtual BOOL OnAutoLoad();
	virtual void OnDragDrop(HDROP hDropInfo);
	virtual void OnDrawTip(CDC& dc);
	virtual BOOL OnDrawTipText(CAdUiDrawTipText& dtt);
	virtual BOOL OnGetTipRect(CRect& r);
	virtual ADUI_REPLY OnGetTipSupport(CPoint& p);
	virtual BOOL OnGetTipText(CString& text);
	virtual BOOL OnHitTipRect(CPoint& p);
	virtual void OnPointedAt(BOOL isPointedAt);
	virtual BOOL OnReload(LPCTSTR strResId);
	void SetIsPointedAt(BOOL isPointedAt);
	void StartTimer(DWORD ms = 50);
	void StopTimer();
	virtual void ThemeModified(AdUiThemeElement element);

	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnThemeChanged(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()


public:
	CAdUiOwnerDrawButton();
	~CAdUiOwnerDrawButton();
	BOOL AutoLoad();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	CWnd* GetAdUiParent();
	BOOL GetEnableDragDrop();
	BOOL GetEnableFastDraw();
	BOOL GetEnablePointedAt();
	BOOL GetIsStatic();
	BOOL GetIsToolButton();
	void PreSubclassWindow();
	BOOL Reload(LPCTSTR strResId);
	void SetAdUiParent(CWnd* w);
	void SetEnableDragDrop(BOOL allow);
	void SetEnableFastDraw(BOOL allow);
	void SetEnablePointedAt(BOOL allow);
	void SetIsStatic(BOOL isStatic);
	void SetIsToolButton(BOOL isToolButton);
	virtual CAdUiTheme* SetTheme(CAdUiTheme* pTheme);
	virtual void SetTracking(BOOL b) { m_bIsTrackButton = !!b; }
};


#include "IcArxPackPop.h"
