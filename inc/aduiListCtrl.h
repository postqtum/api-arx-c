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
***     Description: Declaration of CAdUiListCtrl class
***
*****************************************************************************/
#pragma once

#include "adui_port.h"
#include "aduiHeaderCtrl.h"

#include "icarx/IcArxPackPush.h"

class CAdUiDrawTipText;

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CAdUiListCtrl);

protected:
	CPoint m_lastMousePoint;
	int m_tipIndex = -1;
	int m_tipItem = -1;
	CRect m_tipRect;

public:
	CAdUiHeaderCtrl m_headerCtrl;

protected:
	CWnd* m_aduiParent = nullptr;

protected:
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	virtual void OnDrawTip(CDC& dc);
	virtual BOOL OnDrawTipText(CAdUiDrawTipText& dtt);
	virtual BOOL OnGetTipRect(CRect& r);
	virtual ADUI_REPLY OnGetTipSupport(CPoint& p);
	virtual BOOL OnGetTipText(CString& text);
	virtual BOOL OnHitTipRect(CPoint& p);
	void PreSubclassWindow();

	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	CAdUiListCtrl();
	~CAdUiListCtrl() noexcept;
	int ColumnCount();
	CWnd* GetAdUiParent();
	virtual void GetContentExtent(int item, int index, LPCTSTR text, int& width, int& height);
	BOOL GetItemAtPoint(CPoint & p, int& item, int& index);
	BOOL GetSubItemRect(int item, int index, CRect& rect);
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	BOOL IsOwnerDraw();
	void SetAdUiParent(CWnd * w);
};


#include "icarx/IcArxPackPop.h"
