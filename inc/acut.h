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

#include "icarx/IcArxPackPush.h"

struct AcUt
{
	enum QFormatBitFlags
	{
		kSuppressZeroFeet = 0x100,
		kSuppressZeroInches = 0x200,
		kSuppressLeadingZero = 0x400,
		kSuppressTrailingZero = 0x800,
		kIgnoreUnitMode = 0x1000,
		kUseAltUnits = 0x2000
	};
};

#include "icarx/IcArxPackPop.h"
