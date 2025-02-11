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
***     Description: Declaration of AcConstrainedCircle class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedCurve.h"

#include "IcArxPackPush.h"

class AcConstrainedCircle : public AcConstrainedCurve
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedCircle, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedCircle(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedCircle(AcDbObjectId geomDependencyId);

	ACDBCORE2D_PORT AcGePoint3d centerPoint() const;
	ACDBCORE2D_PORT double radius() const;
};

#include "IcArxPackPop.h"
