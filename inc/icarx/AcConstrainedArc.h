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
***     Description: Declaration of AcConstrainedArc class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedCircle.h"

#include "IcArxPackPush.h"

class AcConstrainedArc : public AcConstrainedCircle
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedArc, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedArc(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedArc(AcDbObjectId geomDependencyId);

	ACDBCORE2D_PORT AcGePoint3d endPoint() const;
	ACDBCORE2D_PORT AcGePoint3d midPoint() const;
	ACDBCORE2D_PORT AcGePoint3d startPoint() const;
};

#include "IcArxPackPop.h"
