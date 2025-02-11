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
***     Description: Declaration of Ac3PointAngleConstraint class
***
*****************************************************************************/
#pragma once

#include "AcAngleConstraint.h"

#include "IcArxPackPush.h"

class Ac3PointAngleConstraint : public AcAngleConstraint
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(Ac3PointAngleConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT Ac3PointAngleConstraint(bool bCreateImp = true);
	ACDBCORE2D_PORT Ac3PointAngleConstraint(AcAngleConstraint::SectorType type);
};

#include "IcArxPackPop.h"
