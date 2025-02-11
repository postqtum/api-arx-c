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

#include "IcArxPackPush.h"

struct AcGs
{
	enum LinePattern
	{
		eSolid = 0,
		eDashed = 1,
		eDotted = 2,
		eDashDot = 3,
		eShortDash = 4,
		eMediumDash = 5,
		eLongDash = 6,
		eDoubleShortDash = 7,
		eDoubleMediumDash = 8,
		eDoubleLongDash = 9,
		eMediumLongDash = 10,
		eMediumDashShortDashShortDash = 11,
		eLongDashShortDash = 12,
		eLongDashDotDot = 13,
		eLongDashDot = 14,
		eMediumDashDotShortDashDot = 15,
		eSparseDot = 16,
		eDefaultLinePattern = eDotted
	};
};

#include "IcArxPackPop.h"
