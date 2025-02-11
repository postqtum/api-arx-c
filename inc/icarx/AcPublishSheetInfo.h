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
***     Description: Declaration of AcPublishSheetInfo class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

class AcPlDSDEntry;
class AcPlPlotLogger;

#include "IcArxPackPush.h"

class AcPublishSheetInfo
{
public:
	AcPublishSheetInfo() = default;
	virtual ~AcPublishSheetInfo() = default;

	virtual const AcPlDSDEntry* GetDSDEntry() = 0;
	virtual AcPlPlotLogger* GetPlotLogger() = 0;
	virtual const ACHAR* GetUniqueId() = 0;
};

#include "IcArxPackPop.h"
