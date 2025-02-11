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
***     Description: Declaration of AcDbSummaryInfoManager class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../AcDbCore2dDefs.h"

class AcDbSummaryInfoReactor;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbSummaryInfoManager
{
public:
	virtual void addReactor(AcDbSummaryInfoReactor* pReact) = 0;
	virtual void removeReactor(AcDbSummaryInfoReactor* pReact) = 0;
};

#include "IcArxPackPop.h"

ACDBCORE2D_PORT AcDbSummaryInfoManager* acdbSummaryInfoManager();
