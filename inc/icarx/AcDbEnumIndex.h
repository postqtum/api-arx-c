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
***     Description: Declaration of AcDbEnumIndex
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::PointIndex
{
	kMPoint1 = 0,
	kMPoint2 = 1,
	kMPoint3 = 2,
	kMPoint4 = 3
};

enum AcDb::EdgeIndex
{
	kMEdge1 = 0,
	kMEdge2 = 1,
	kMEdge3 = 2,
	kMEdge4 = 3
};
