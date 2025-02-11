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
***     Description: Declaration of CAcUiDockFrame class
***
*****************************************************************************/
#pragma once

#include "../acui_port.h"
#include "CAdUiDockFrame.h"

#include "IcArxPackPush.h"

class ACUI_PORT CAcUiDockFrame : public CAdUiDockFrame
{
	DECLARE_DYNCREATE(CAcUiDockFrame);

public:
	CAcUiDockFrame();
	~CAcUiDockFrame();

protected:
	afx_msg LRESULT OnACADKeepFocus(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

#include "IcArxPackPop.h"
