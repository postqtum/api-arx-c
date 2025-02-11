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
***     Description: Declaration of CAdUiEdit class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "../aduiMessage.h"

class CAdUiDrawTipText;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275)

class ADUI_PORT CAdUiEdit : public CEdit
{
	DECLARE_DYNAMIC(CAdUiEdit)

protected:
	CPoint m_lastMousePoint;
	CRect m_tipRect;

public:
	DWORD m_styleMask = 0;

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
	CAdUiEdit();
	~CAdUiEdit() noexcept;
	CWnd* GetAdUiParent();
	virtual void GetContentExtent(LPCTSTR text, int& width, int& height);
	DWORD GetStyleMask();
	void GetTextExtent(LPCTSTR text, int& width, int& height);
	BOOL IsStyleMaskSet(DWORD);
	void SetAdUiParent(CWnd* w);
	virtual void SetStyleMask(DWORD);
};


#include "IcArxPackPop.h"
