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
***     Description: Declaration of CAcUiTabChildDialog class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "../aduiTabChildDialog.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiTabChildDialog : public CAdUiTabChildDialog
{
	DECLARE_DYNAMIC(CAcUiTabChildDialog);

public:
	CAcUiTabChildDialog(CWnd* pParent = nullptr, HINSTANCE hDialogResource = nullptr);
	~CAcUiTabChildDialog();

public:
	CWnd* AppMainWindow() override;
	HINSTANCE AppResourceInstance() override;
	LPCTSTR AppRootKey() override;
	void EnableFloatingWindows(BOOL allow) override;
	BOOL OnMainDialogHelp() override;
	void OnDialogHelp() override;

public:
	enum
	{
		IDD = 0
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override;

protected:
	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
