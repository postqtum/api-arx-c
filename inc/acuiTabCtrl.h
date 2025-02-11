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
***     Description:
***
*****************************************************************************/
#pragma once

#include "acui_port.h"
#include "aduiTabCtrl.h"

#include "icarx/IcArxPackPush.h"

class ACUI_PORT CAcUiTab : public CAdUiTab
{
	DECLARE_DYNAMIC(CAcUiTab);

public:
	CAcUiTab();
	~CAcUiTab();

protected:
	DECLARE_MESSAGE_MAP()
};

#include "icarx/IcArxPackPop.h"
