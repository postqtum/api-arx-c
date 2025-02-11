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
***     Description: Declaration of CAdUiTextTip class
***
*****************************************************************************/
#pragma once

#include "CAdUiTipWindow.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiTextTip : public CAdUiTipWindow
{
	DECLARE_DYNAMIC(CAdUiTextTip)

protected:
	void DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior);
	void DrawContent(CDC& dc, CRect& rInterior);
	DECLARE_MESSAGE_MAP()
public:
	CAdUiTextTip();
	~CAdUiTextTip() noexcept;
	void Hide();
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	void Update(CWnd* control, BOOL useText);
	void UpdateIfNecessary(CWnd* control, BOOL useText);
};


#include "IcArxPackPop.h"
