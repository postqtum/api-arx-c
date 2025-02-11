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
***     Description: Declaration of AcDbEnumSortEntsFlags
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::SortEntsFlags
{
	kSortEntsSelection = 0x01,
	kSortEntsOsnap = 0x02,
	kSortEntsRedraw = 0x04,
	kSortEntsSlide = 0x08,
	kSortEntsRegen = 0x10,
	kSortEntsPlot = 0x20,
	kSortEntsPsout = 0x40
};
