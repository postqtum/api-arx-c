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
***     Description:
***
*****************************************************************************/
#pragma once

#include "aduiDialog.h"

class CAdUiTabMainDialog;

#include "icarx/IcArxPackPush.h"

class ADUI_PORT CAdUiTabChildDialog : public CAdUiDialog
{
	friend class CAdUiTab;

	DECLARE_DYNAMIC(CAdUiTabChildDialog);

private:
	BOOL m_bDirty = FALSE;
	HWND m_hWndFocus = nullptr;
	CAdUiTab* m_pAcadTab = nullptr;

public:
	enum
	{
		IDD = 0
	};

private:
	void SetAcadTabPointer(CAdUiTab* pAcadTab);
	BOOL TranslateTabKey();

protected:
	void DoDataExchange(CDataExchange* pDX);
	void OnCancel();
	void OnInitDialogBegin();
	void OnInitDialogFinish();
	void OnOK();

	afx_msg LRESULT OnResizePage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
public:
	CAdUiTabChildDialog(CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	CAdUiTab* GetAcadTabPointer();
	CAdUiTabMainDialog* GetMainDialog();
	int GetTabIndex();
	BOOL IsDirty();
	virtual void OnMainDialogApply();
	virtual void OnMainDialogCancel();
	virtual BOOL OnMainDialogHelp();
	virtual void OnMainDialogOK();
	virtual void OnTabActivation(BOOL bActivate);
	virtual BOOL OnTabChanging();
	BOOL PreTranslateMessage(MSG* pMsg);
	void SetAcadTabChildFocus(HWND hWndFocus);
	void SetDirty(BOOL bDirty = TRUE);
	void SetValidationInfo(CDataExchange* pDX);
};


#include "icarx/IcArxPackPop.h"
