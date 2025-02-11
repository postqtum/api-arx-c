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
***     Description: Declaration of AcDbHostApplicationProgressMeter class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

#include "IcArxPackPush.h"

class AcDbHostApplicationProgressMeter
{
public:
	AcDbHostApplicationProgressMeter();
	virtual ~AcDbHostApplicationProgressMeter();

	virtual void meterProgress();
	virtual void setLimit(int max);
	virtual void start(const ACHAR* displayString = nullptr);
	virtual void stop();
};

#include "IcArxPackPop.h"
