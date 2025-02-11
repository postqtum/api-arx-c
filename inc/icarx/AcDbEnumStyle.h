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
***     Description: Declaration of AcDbEnumEndStyle
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::JoinStyle
{
	kJnStylNone = 0,
	kJnStylRound = 1,
	kJnStylAngle = 2,
	kJnStylFlat = 3
};

enum AcDb::PlotStyleNameType
{
	kPlotStyleNameByLayer = 0,
	kPlotStyleNameByBlock = 1,
	kPlotStyleNameIsDictDefault = 2,
	kPlotStyleNameById = 3
};
