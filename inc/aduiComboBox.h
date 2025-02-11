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
***     Description: Declaration of CAdUiComboBox class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"
#include "aduiMessage.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class CAdUiComboBoxDraw;
class CAdUiDrawTipText;
class CAdUiEdit;
class CAdUiListBox;
class CAdUiTheme;

class ADUI_PORT CAdUiComboBox : public CComboBox
{
	DECLARE_DYNAMIC(CAdUiComboBox)

protected:
	CPoint m_lastMousePoint;
	CRect m_tipRect;
	CString m_sToolTipText;
	CAdUiComboBoxDraw* m_pDraw = nullptr;
	CAdUiTheme* m_pTheme = nullptr;
	CWnd* m_aduiParent = nullptr;
	bool m_bAutoDeleteEBox : 1;
	bool m_bAutoDeleteLBox : 1;
	bool m_bSubclassedControls : 1;
	CAdUiEdit* m_pComboEBox = nullptr;
	CAdUiListBox* m_pComboLBox = nullptr;

protected:
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	virtual void OnDrawTip(CDC& dc);
	virtual BOOL OnDrawTipText(CAdUiDrawTipText& dtt);
	virtual BOOL OnGetTipRect(CRect& r);
	virtual ADUI_REPLY OnGetTipSupport(CPoint& p);
	virtual BOOL OnGetTipText(CString& text);
	virtual BOOL OnHitTipRect(CPoint& p);
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	afx_msg void OnPaint();
	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnGetToolTipText(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	CAdUiComboBox();
	~CAdUiComboBox();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	CWnd* GetAdUiParent();
	virtual void GetContentExtent(LPCTSTR text, int& width, int& height);
	CAdUiEdit* GetEditBox();
	void GetLBString(int nIndex, CString& rString);
	CAdUiListBox* GetListBox();
	DWORD GetStyleMask();
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	CAdUiTheme* GetTheme() const { return m_pTheme; }
	CString GetToolTipText() const;
	static bool IsInEdit(UINT nItemState);
	BOOL IsOwnerDraw();
	BOOL IsStatic();
	BOOL IsStyleMaskSet(DWORD mask);
	bool IsThemed() const;
	static bool IsVistaTheme();
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
	void PreSubclassWindow();
	void SetAdUiParent(CWnd* w);
	void SetDraw(CAdUiComboBoxDraw * pDraw) { m_pDraw = pDraw; }
	void SetEditBox(CAdUiEdit* control, BOOL autoDelete);
	void SetIsThemed(bool bValue);
	void SetListBox(CAdUiListBox* control, BOOL autoDelete);
	void SetStyleMask(DWORD mask);
	void SetTheme(CAdUiTheme* pTheme);
	BOOL SetToolTipText(const CString& sText);
};

#include "icarx/IcArxPackPop.h"
