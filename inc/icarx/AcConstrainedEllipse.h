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
***     Description: Declaration of AcConstrainedEllipse class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedCurve.h"

#include "IcArxPackPush.h"

class AcConstrainedEllipse : public AcConstrainedCurve
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedEllipse, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedEllipse(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedEllipse(AcDbObjectId geomDependencyId);

	ACDBCORE2D_PORT AcGePoint3d centerPoint() const;
	ACDBCORE2D_PORT AcGeVector3d direction() const;
	ACDBCORE2D_PORT double majorRadius() const;
	ACDBCORE2D_PORT double minorRadius() const;
};

#include "IcArxPackPop.h"
