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
***     Description: Declaration of CAcUiFileDialog class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../aduiFileDialog.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiFileDialog : public CAdUiFileDialog
{
	DECLARE_DYNAMIC(CAcUiFileDialog);

public:
	CAcUiFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt = nullptr, LPCTSTR lpszFileName = nullptr,
					DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
					LPCTSTR lpszFilter = nullptr, CWnd* pParentWnd = nullptr);
	~CAcUiFileDialog();

public:
	CWnd* AppMainWindow() override;
	HINSTANCE AppResourceInstance() override;
	LPCTSTR AppRootKey() override;
	void EnableFloatingWindows(BOOL allow) override;
	void OnDialogHelp() override;

public:
	enum
	{
		IDD = 0
	};

protected:
	void OnOK() override;
	void OnCancel() override;
	void DoDataExchange(CDataExchange* pDX) override;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
