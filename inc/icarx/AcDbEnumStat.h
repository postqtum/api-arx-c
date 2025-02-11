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
***     Description: Declaration of AcDbEnumStat
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::DragStat
{
	kDragStart = 0,
	kDragEnd = 1,
	kDragAbort = 2
};

enum AcDb::GripStat
{
	kGripsDone = 0,
	kGripsToBeDeleted = 1,
	kDimDataToBeDeleted = 2
};
