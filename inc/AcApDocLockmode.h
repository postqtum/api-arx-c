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
***     Description: AcAp::DocLockMode enum declaration
***
*****************************************************************************/
#pragma once

#include "icarx/IcArxPackPush.h"
struct AcAp
{
	enum DocLockMode
	{
		kNone = 0x00,
		kAutoWrite = 0x01,
		kNotLocked = 0x02,
		kWrite = 0x04,
		kProtectedAutoWrite = 0x14,
		kRead = 0x20,
		kXWrite = 0x40
	};
};
#include "icarx/IcArxPackPop.h"

