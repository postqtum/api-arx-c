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
***     Description: Declaration of CAdUiRichEditCtrl class
***
*****************************************************************************/
#pragma once

#include <afxcmn.h>

#include "AdAChar.h"
#include "aduiTheme.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class CAdUiRichEditCtrl;

class CAdUiRichEditThemeModReactor;

class ADUI_PORT CAdUiRichEditCtrl : public CRichEditCtrl
{
	friend class CAdUiRichEditThemeModReactor;

	DECLARE_DYNAMIC(CAdUiRichEditCtrl)

public:
	static bool m_bInitOnce;

protected:
	CWnd* m_aduiParent = nullptr;

private:
	CString m_csTitle;
	CString m_csText;
	int m_horizontalMargin = 0;
	int m_verticalMargin = 0;
	bool m_bIsThemed = false;
	CAdUiRichEditThemeModReactor* m_pThemeModReactor = nullptr;
	CAdUiTheme* m_pTheme = nullptr;
	COLORREF mBackgroundColor = 0xffffff;
	COLORREF mTextColor = 0;

protected:
	virtual void ThemeModified(AdUiThemeElement element);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEnLink(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
public:
	CAdUiRichEditCtrl(bool bIsThemed = false);
	~CAdUiRichEditCtrl();
	void AppendString(CString& str, bool bBoldFormat);
	int GetHorizontalMargin();
	int GetVerticalMargin();
	bool IsThemed() { return m_bIsThemed; }
	BOOL PreTranslateMessage(MSG* pMsg);
	void SetBackgroundAndTextColor(COLORREF bgColor, COLORREF textColor);
	void SetIsThemed(bool isThemed);
	void SetMargins(int horizontal, int vertical);
	void SetTitle(LPCTSTR pszTitle) { m_csTitle = pszTitle; }
	void clear();
	void streamIn();
};

#include "icarx/IcArxPackPop.h"
