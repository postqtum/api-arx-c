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
***     Description: Declaration of AcConstrained2PointsConstructionLin class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedConstructionLine.h"

#include "IcArxPackPush.h"

class AcConstrained2PointsConstructionLine : public AcConstrainedConstructionLine
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrained2PointsConstructionLine, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrained2PointsConstructionLine(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrained2PointsConstructionLine(const AcGePoint3d& point1,
																  const AcGePoint3d& point2);
};

#include "IcArxPackPop.h"
