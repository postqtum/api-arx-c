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
***     Description: Declaration of AcRxUnitTypeAttribute class
***
*****************************************************************************/
#pragma once

#include "AcRxAttribute.h"

#include "IcArxPackPush.h"

class AcRxUnitTypeAttribute : public AcRxAttribute
{
public:
	enum UnitType
	{
		kUnitless = 0,
		kDistance = (0x1 << 0),
		kAngle = (0x1 << 1),
		kArea = (0x1 << 2),
		kVolume = (0x1 << 3),
		kCurrency = (0x1 << 4),
		kPercentage = (0x1 << 5),
		kAngleNotTransformed = (0x1 << 16),
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxUnitTypeAttribute, ACBASE_PORT);
	ACBASE_PORT AcRxUnitTypeAttribute(UnitType unitType);
	ACBASE_PORT UnitType unitType() const;
};

#include "IcArxPackPop.h"
