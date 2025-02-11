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
***     Description: Declaration of CAcUiTabMainDialog class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../aduiTabMainDialog.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiTabMainDialog : public CAdUiTabMainDialog
{
	DECLARE_DYNAMIC(CAcUiTabMainDialog);

public:
	CAcUiTabMainDialog(UINT idd, CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CAcUiTabMainDialog();

public:
	CWnd* AppMainWindow() override;
	HINSTANCE AppResourceInstance() override;
	LPCTSTR AppRootKey() override;
	void EnableFloatingWindows(BOOL allow) override;
	void OnDialogHelp() override;
	int IsMultiDocumentActivationEnabled() override;
	int EnableMultiDocumentActivation(BOOL bEnable) override;

public:
	BOOL AddApplicationTabs(LPCTSTR pszAppName) override;

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
