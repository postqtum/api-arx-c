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
***     Description: Declaration of AcRadiusDiameterConstraint class
***
*****************************************************************************/
#pragma once

#include "AcExplicitConstraint.h"

#include "IcArxPackPush.h"

class AcRadiusDiameterConstraint : public AcExplicitConstraint
{
public:
	enum RadiusDiameterConstrType
	{
		kCircleRadius = 0,
		kCircleDiameter,
		kMinorRadius,
		kMajorRadius
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRadiusDiameterConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcRadiusDiameterConstraint(bool bCreateImp = true);
	ACDBCORE2D_PORT AcRadiusDiameterConstraint(RadiusDiameterConstrType type);

	ACDBCORE2D_PORT RadiusDiameterConstrType constrType() const;
};

#include "IcArxPackPop.h"
