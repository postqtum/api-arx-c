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
***     Description: Declaration of AcDbSummaryInfoReactor class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

class AcDbDatabase;
class AcDbDatabaseSummaryInfo;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbSummaryInfoReactor
{
public:
	virtual ~AcDbSummaryInfoReactor() = default;

	virtual void summaryInfoHasChanged(const AcDbDatabase*, const AcDbDatabaseSummaryInfo*) {}
};

#include "IcArxPackPop.h"
