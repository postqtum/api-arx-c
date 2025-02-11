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
***     Description: Declaration of AcGiHatchPattern class
***
*****************************************************************************/
#pragma once

#include "AcGiFill.h"
#include "AcGiHatchPatternDefinition.h"
#include "../AcArray.h"

class AcGiImpHatchPattern;

#include "IcArxPackPush.h"

class AcGiHatchPattern : public AcGiFill
{
private:
	AcGiImpHatchPattern* mpImp = nullptr;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiHatchPattern, ACDBCORE2D_PORT);

	AcGiHatchPattern();
	ACDBCORE2D_PORT AcGiHatchPattern(const AcArray<AcGiHatchPatternDefinition>&);
	ACDBCORE2D_PORT AcGiHatchPattern(const AcGiHatchPattern&);
	ACDBCORE2D_PORT ~AcGiHatchPattern();

	ACDBCORE2D_PORT const AcArray<AcGiHatchPatternDefinition>& patternLines() const;
};

#include "IcArxPackPop.h"
