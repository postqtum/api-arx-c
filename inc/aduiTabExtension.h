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
***     Description: Declaration of CAdUiTabExtensionManager class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "adui_port.h"

class CAdUiTab;
class CAdUiTabChildDialog;
class CAdUiTabMainDialog;

#include "icarx/IcArxPackPush.h"

class ADUI_PORT CAdUiTabExtensionManager
{
private:
	CString m_dlgName;
	CAdUiTabMainDialog* m_pDlg = nullptr;
	CAdUiTab* m_pTabCtrl = nullptr;

public:
	CAdUiTabExtensionManager();
	virtual ~CAdUiTabExtensionManager();
	int AddExtendedTabs();
	virtual BOOL AddTab(HINSTANCE hInstRes, UINT uTemplateID, LPCTSTR pszTabName,
						CAdUiTabChildDialog* pDialog);
	virtual LPCTSTR GetDialogName();
	CAdUiTab* GetTabControl() const { return m_pTabCtrl; }
	void Initialize(CAdUiTab* pTabCtrl, CAdUiTabMainDialog* pDlg);
};


#include "icarx/IcArxPackPop.h"
