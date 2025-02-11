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
***     Description: Declaration of AcConstrainedPoint class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"

#include "AcConstrainedGeometry.h"

#include "IcArxPackPush.h"

class AcConstrainedPoint : public AcConstrainedGeometry
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedPoint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedPoint(bool bCreateImp = true);
	ACDBCORE2D_PORT AcConstrainedPoint(AcDbObjectId geomDependencyId);

	ACDBCORE2D_PORT virtual AcGePoint3d point() const;
};

#include "IcArxPackPop.h"
