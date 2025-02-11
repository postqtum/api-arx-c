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
***     Description: Declaration of CAcUiDialog class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../aduiDialog.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiDialog : public CAdUiDialog
{
	DECLARE_DYNAMIC(CAcUiDialog);

public:
	CAcUiDialog(UINT idd, CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CAcUiDialog();

protected:
	BOOL FindContextHelpFullPath(LPCTSTR fileName, CString& fullPath) override;

public:
	CWnd* AppMainWindow() override;
	HINSTANCE AppResourceInstance() override;
	LPCTSTR AppRootKey() override;
	void EnableFloatingWindows(BOOL allow) override;
	int IsMultiDocumentActivationEnabled() override;
	int EnableMultiDocumentActivation(BOOL bEnable) override;

	void OnDialogHelp() override;

	BOOL OnInitDialog() override;

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
