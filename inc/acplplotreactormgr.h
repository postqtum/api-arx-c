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

#include "AcPl.h"
#include "adesk.h"

class AcPlPlotReactor;

#include "icarx/IcArxPackPush.h"

class AcPlPlotReactorMgr
{
public:
	ACPL_PORT void addReactor(AcPlPlotReactor* pReactor);
	ACPL_PORT void removeReactor(AcPlPlotReactor* pReactor);
};

#include "icarx/IcArxPackPop.h"

ACPL_PORT AcPlPlotReactorMgr* __stdcall acplPlotReactorMgrPtr();
#define acplPlotReactorMgr acplPlotReactorMgrPtr()
