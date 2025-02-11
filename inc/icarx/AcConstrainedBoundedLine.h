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
***     Description: Declaration of AcConstrainedBoundedLine class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedLine.h"

#include "IcArxPackPush.h"

class AcConstrainedBoundedLine : public AcConstrainedLine
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedBoundedLine, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedBoundedLine(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedBoundedLine(AcDbObjectId geomDependencyId, bool bRay);

	ACDBCORE2D_PORT AcGePoint3d endPoint() const;
	ACDBCORE2D_PORT bool isRay() const;
	ACDBCORE2D_PORT AcGePoint3d midPoint() const;
	ACDBCORE2D_PORT AcGePoint3d startPoint() const;
};

#include "IcArxPackPop.h"
