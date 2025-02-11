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
***     Description: Declaration of CAdUiDialogBar class
***
*****************************************************************************/
#pragma once

#include <afxext.h>

#include "aduiMessage.h"

#include "icarx/IcArxPackPush.h"

class CAdUiTextTip;

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiDialogBar : public CDialogBar
{
	DECLARE_DYNAMIC(CAdUiDialogBar);

protected:
	BOOL m_bUseTips = false;
	CAdUiTextTip* m_pTextTip = nullptr;
	CToolTipCtrl* m_pToolTip = nullptr;
	CString m_rootKey;

public:
	enum
	{
		IDD = 0
	};

protected:
	virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam);
	void DoDataExchange(CDataExchange* pDX);
	virtual ADUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
	virtual ADUI_REPLY OnNotifyControlValid(UINT controlId, BOOL isValid);
	virtual ADUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);
	virtual ADUI_REPLY OnNotifyUpdateTip(CWnd* control);
	void PostNcDestroy();

	afx_msg LRESULT OnAdUiMessage(WPARAM wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiDialogBar();
	~CAdUiDialogBar();
	virtual CWnd* AppMainWindow();
	virtual HINSTANCE AppResourceInstance();
	virtual LPCTSTR AppRootKey();
	BOOL GetUseTips();
	BOOL PreTranslateMessage(MSG* pMsg);
	void SetUseTips(BOOL useTips);
};


#include "icarx/IcArxPackPop.h"
