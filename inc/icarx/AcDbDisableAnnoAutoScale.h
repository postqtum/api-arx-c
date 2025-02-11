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
***     Description: Declaration of AcDbDisableAnnoAutoScale class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

#include "IcArxPackPush.h"

class AcDbDisableAnnoAutoScale
{
private:
	short mSaveAnnoAutoScale;
	short mSaveAnnoAutoScaleLayout;

public:
	AcDbDisableAnnoAutoScale();
	ACDBCORE2D_PORT ~AcDbDisableAnnoAutoScale();

	AcDbDisableAnnoAutoScale(const AcDbDisableAnnoAutoScale&) = delete;
	AcDbDisableAnnoAutoScale& operator=(const AcDbDisableAnnoAutoScale&) = delete;
};

#include "IcArxPackPop.h"
