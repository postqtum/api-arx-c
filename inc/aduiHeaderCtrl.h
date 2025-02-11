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
***     Description: Declaration of CAdUiHeaderCtrl class
***
*****************************************************************************/
#pragma once

#include <afxcmn.h>

#include "aduiMessage.h"

#include "icarx/IcArxPackPush.h"

class CAdUiDrawTipText;

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiHeaderCtrl : public CHeaderCtrl
{
	DECLARE_DYNAMIC(CAdUiHeaderCtrl)

protected:
	CPoint m_lastMousePoint;
	int m_tipItem = -1;
	CRect m_tipRect;

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

	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	CAdUiHeaderCtrl();
	~CAdUiHeaderCtrl() noexcept;
	CWnd* GetAdUiParent();
	virtual void GetContentExtent(int item, LPCTSTR text, int& width, int& height);
	int GetItemAtPoint(CPoint & p);
	BOOL GetItemRect(int idx, CRect& rItem);
	BOOL GetText(int idx, CString& text);
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	BOOL IsOwnerDraw(int idx);
	void SetAdUiParent(CWnd * w);
};

#include "icarx/IcArxPackPop.h"
