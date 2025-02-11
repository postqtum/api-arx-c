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
***     Description: Declaration of AcDbEnumCoord
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::CoordAxis
{
	kX = 0,
	kY = 1,
	kZ = 2
};

enum AcDb::CoordSystem
{
	kWorldCS = 0,
	kUserCS = 1,
	kCurDisplayCS = 2,
	kPaperDisplayCS = 3,
	kEntityCS = 4
};
