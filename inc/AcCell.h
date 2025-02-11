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
***     Description: AcCell related declarations
***
*****************************************************************************/
#pragma once

#include "acarray.h"

#include "icarx/IcArxPackPush.h"

struct AcCell
{
	int mnRow;
	int mnColumn;
};

struct AcCellRange
{
	int mnTopRow;
	int mnLeftColumn;
	int mnBottomRow;
	int mnRightColumn;

	bool operator==(const AcCellRange& other) const;
};

#include "icarx/IcArxPackPop.h"

typedef AcArray<AcCell> AcCellArray;
typedef AcArray<AcCellRange> AcCellRangeArray;
