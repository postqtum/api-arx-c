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
***     Description: Declaration of AcDbEnumView
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::OrthographicView
{
	kNonOrthoView = 0,
	kTopView = 1,
	kBottomView = 2,
	kFrontView = 3,
	kBackView = 4,
	kLeftView = 5,
	kRightView = 6
};

enum AcDb::VpFreezeOps
{
	kFreeze = 0,
	kThaw,
	kReset
};

enum AcDb::Visibility
{
	kInvisible = 1,
	kVisible = 0
};
