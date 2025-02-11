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
***     Description: Declaration of CAdUiTabMainDialog class
***
*****************************************************************************/
#pragma once

#include "aduiDialog.h"
#include "aduiTabExtension.h"

#include "icarx/IcArxPackPush.h"

class ADUI_PORT CAdUiTabMainDialog : public CAdUiDialog
{
	friend class CAdUiTab;

	DECLARE_DYNAMIC(CAdUiTabMainDialog);

private:
	int m_idDefaultButton = -1;
	CAdUiTab* m_pAcadTab = nullptr;
	CString m_strTabIndex;

protected:
	CAdUiTabExtensionManager m_xtabManager;

public:
	enum
	{
		IDD = 0
	};

private:
	BOOL TranslateTabKey();

protected:
	void DoDataExchange(CDataExchange* pDX);
	void OnCancel();
	void OnInitDialogBegin();
	void OnInitDialogFinish();
	void OnOK();
	void RaiseApplyEvent();
	void SetAcadTabPointer(CAdUiTab* pAcadTab);

	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiTabMainDialog(UINT idd, CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	virtual BOOL AddApplicationTabs(LPCTSTR pszAppName);
	int AddExtendedTabs();
	BOOL AddTab(int iPos, LPCTSTR tabName, UINT uTemplateID, CAdUiTabChildDialog* pDialog);
	BOOL AddTab(int iPos, UINT uTabStringID, UINT uTemplateID, CAdUiTabChildDialog* pDialog);
	int GetDefaultButton();
	int GetInitialRequestedTabIndex();
	LPCTSTR GetInitialTabIndex() { return m_strTabIndex; }
	CAdUiTab* GetTabControl();
	int GetTabIndex(CAdUiTabChildDialog* pDialog);
	CAdUiTabExtensionManager* GetXtabPointer();
	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL RemoveTab(int iPos);
	void SetDefaultButton(int nIdDefaultButton);
	void SetInitialTabIndex(LPCTSTR strTabIndex) { m_strTabIndex = strTabIndex; }
	void UpdateDefaultButton(HWND hFocusBefore, HWND hFocusAfter);
};


#include "icarx/IcArxPackPop.h"
