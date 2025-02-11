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
***     Description: Implementation of AcConstrainedImplicitPoint class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedPoint.h"

#include "IcArxPackPush.h"

class AcConstrainedImplicitPoint : public AcConstrainedPoint
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedImplicitPoint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedImplicitPoint(bool bCreateImp = true);
	ACDBCORE2D_PORT AcConstrainedImplicitPoint(AcGraphNode::Id constrCurvId,
											   AcDb::ImplicitPointType ptype, int index = -1);

	ACDBCORE2D_PORT AcGraphNode::Id constrainedCurveId() const;
	ACDBCORE2D_PORT AcGePoint3d point() const override;
	ACDBCORE2D_PORT int pointIndex() const;
	ACDBCORE2D_PORT AcDb::ImplicitPointType pointType() const;
};

#include "IcArxPackPop.h"
