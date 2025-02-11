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
***     Description: Declaration of AcDbUnderlayDrawContext struct
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "AcUnderlayLayer.h"

#include "IcArxPackPush.h"

struct AcDbUnderlayDrawContext
{
	uint8_t contrast;
	uint8_t fade;
	bool monochrome;
	bool adjustColorForBackground;
	AcUnderlayLayer** pLayers;
};

#include "IcArxPackPop.h"
