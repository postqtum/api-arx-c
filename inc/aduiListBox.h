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
***     Description: Declaration of CAdUiListBox class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "aduiMessage.h"

#include "icarx/IcArxPackPush.h"

class CAdUiComboBox;
class CAdUiDrawTipText;

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiListBox : public CListBox
{
	DECLARE_DYNAMIC(CAdUiListBox);

protected:
	CPoint m_lastMousePoint;
	int m_tipItem = 0;
	CRect m_tipRect;

protected:
	CWnd* m_aduiParent = nullptr;

protected:
	BOOL m_bComboBoxDraw = FALSE;
	CAdUiComboBox* m_pComboBox = nullptr;

protected:
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	virtual void OnDrawTip(CDC& dc);
	virtual BOOL OnDrawTipText(CAdUiDrawTipText& dtt);
	virtual BOOL OnGetTipRect(CRect& r);
	virtual ADUI_REPLY OnGetTipSupport(CPoint& p);
	virtual BOOL OnGetTipText(CString& text);
	virtual BOOL OnHitTipRect(CPoint& p);


	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiListBox() = default;
	~CAdUiListBox() = default;
	int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	CWnd* GetAdUiParent();
	CAdUiComboBox* GetComboBox();
	BOOL GetComboBoxDraw();
	virtual void GetContentExtent(int item, LPCTSTR text, int& width, int& height);
	int GetItemAtPoint(CPoint& p);
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	BOOL IsOwnerDraw();
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void SetAdUiParent(CWnd* w);
	void SetComboBox(CAdUiComboBox* control);
	void SetComboBoxDraw(BOOL comboBoxDraw);
};

#include "icarx/IcArxPackPop.h"
