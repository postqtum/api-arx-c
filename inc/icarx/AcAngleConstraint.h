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
***     Description: Declaration of AcAngleConstraint class
***
*****************************************************************************/
#pragma once

#include "AcExplicitConstraint.h"

#include "IcArxPackPush.h"

class AcAngleConstraint : public AcExplicitConstraint
{
public:
	enum SectorType
	{
		kParallelAntiClockwise = 0,
		kAntiParallelClockwise = 1,
		kParallelClockwise = 2,
		kAntiParallelAntiClockwise = 3,
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcAngleConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcAngleConstraint(bool bCreateImp = true);
	ACDBCORE2D_PORT AcAngleConstraint(AcAngleConstraint::SectorType type);

	ACDBCORE2D_PORT static double angleMultiplier();
	ACDBCORE2D_PORT SectorType sectorType() const;
	ACDBCORE2D_PORT static void setAngleMultiplier(double multiplier);
};

#include "IcArxPackPop.h"
