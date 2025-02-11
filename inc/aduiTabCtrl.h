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
***     Description: Declaration of CAdUiTab class
***
*****************************************************************************/
#pragma once

#include <afxcmn.h>

#include "adui_port.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class ADUI_PORT CAdUiTab : public CTabCtrl
{
	friend class CAdUiTabMainDialog;
	friend class CAdUiTabChildDialog;

	DECLARE_DYNAMIC(CAdUiTab);

private:
	BOOL m_bDirty = FALSE;
	HWND m_hwndFocus = nullptr;
	int m_iActiveTab = -1;
	UINT m_uApplyButtonID = 0;

private:
	BOOL BringTabToFront(int iPos);
	void PositionTabDialog(CAdUiTabChildDialog* pDialog);

protected:
	void PreSubclassWindow();

	afx_msg BOOL OnSelChange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnSelChanging(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiTab();
	~CAdUiTab() noexcept;
	BOOL AddTab(int iPos, const CString& sTabname, UINT uTemplateID, CAdUiTabChildDialog* pDialog);
	BOOL AddTab(int iPos, UINT uTabStringID, UINT uTemplateID, CAdUiTabChildDialog* pDialog);
	BOOL DeleteItem(int iPos);
	BOOL DestroyTab(int iPos, BOOL bUpdateData = FALSE);
	BOOL DisplayData();
	BOOL ExchangeData(BOOL bSaveAndValidate);
	int GetActiveTab();
	CAdUiTabChildDialog* GetDialogPointer(int iPos);
	CAdUiTabMainDialog* GetMainDialog();
	int GetTabIndex(CAdUiTabChildDialog* pDialog);
	BOOL IsDirty();
	BOOL RemoveTab(int iPos);
	int SetActiveTab(int iPos);
	void SetApplyButtonID(UINT uID);
	void SetChildFocus();
	void SetDirty(BOOL bDirty = TRUE);
	void SetValidationInfo(CDataExchange* pDX);
	BOOL ValidateData();
};


#include "icarx/IcArxPackPop.h"
