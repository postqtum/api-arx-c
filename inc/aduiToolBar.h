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
***     Description: Declaration of CAdUiToolBar class
***
*****************************************************************************/
#pragma once

#include <afxext.h>

#include "adui_port.h"
#include "aduiToolBarCtrl.h"

class ADUI_PORT CAdUiToolBar : public CToolBar
{
	DECLARE_DYNAMIC(CAdUiToolBar)
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiToolBar();
	~CAdUiToolBar();
	BOOL LoadToolBar(LPCTSTR lpszResourceName);
	BOOL LoadToolBar(UINT nIDResource);
};
