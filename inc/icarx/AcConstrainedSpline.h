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
***     Description: Declaration of AcConstrainedSpline class
***
*****************************************************************************/
#pragma once

#include "../genurb3d.h"

#include "AcConstrainedCurve.h"

#include "IcArxPackPush.h"

class AcConstrainedSpline : public AcConstrainedCurve
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedSpline, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedSpline(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedSpline(AcDbObjectId geomDependencyId,
												 const AcGeNurbCurve3d& spline);

	ACDBCORE2D_PORT AcGePoint3d definePointAt(int index) const;
	ACDBCORE2D_PORT int numOfDefinePoints() const;
	ACDBCORE2D_PORT const AcGeNurbCurve3d nurbSpline() const;
};

#include "IcArxPackPop.h"
