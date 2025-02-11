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
***     Description: Declaration of AcGiHatchPatternDefinition class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../gedblar.h"

class AcGiImpHatchPatternDefinition;

#include "IcArxPackPush.h"

class AcGiHatchPatternDefinition
{
	friend class AcGiImpHatchPatternDefinition;

private:
	AcGiImpHatchPatternDefinition* mpImp = nullptr;

public:
	ACDBCORE2D_PORT AcGiHatchPatternDefinition();
	ACDBCORE2D_PORT AcGiHatchPatternDefinition(const AcGiHatchPatternDefinition& def);
	ACDBCORE2D_PORT AcGiHatchPatternDefinition(double angle, double baseX, double baseY,
											   double offsetX, double offsetY,
											   const AcGeDoubleArray& dashList);
	ACDBCORE2D_PORT ~AcGiHatchPatternDefinition();
	ACDBCORE2D_PORT AcGiHatchPatternDefinition& operator=(const AcGiHatchPatternDefinition& def);

	ACDBCORE2D_PORT double angle() const;
	ACDBCORE2D_PORT double baseX() const;
	ACDBCORE2D_PORT double baseY() const;
	ACDBCORE2D_PORT const AcGeDoubleArray& dashList() const;
	ACDBCORE2D_PORT double offsetX() const;
	ACDBCORE2D_PORT double offsetY() const;
};

#include "IcArxPackPop.h"
