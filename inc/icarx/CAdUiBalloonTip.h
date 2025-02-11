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
***     Description: Declaration of CAdUiBalloonTip class
***
*****************************************************************************/
#pragma once

#include "CAdUiTipWindow.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiBalloonTip : public CAdUiTipWindow
{
	DECLARE_DYNAMIC(CAdUiBalloonTip)

protected:
	CPoint m_initialCursorPos;

protected:
	void DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior);
	void DrawContent(CDC& dc, CRect& rInterior);

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()

public:
	CAdUiBalloonTip();
	~CAdUiBalloonTip();
	void Hide();
	void Show();
};


#include "IcArxPackPop.h"
