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
***     Description: Declaration of AcDistanceConstraint class
***
*****************************************************************************/
#pragma once

#include "AcExplicitConstraint.h"

class AcGeVector3d;

#include "IcArxPackPush.h"

class AcDistanceConstraint : public AcExplicitConstraint
{
public:
	enum DirectionType
	{
		kNotDirected = 0,
		kFixedDirection,
		kPerpendicularToLine,
		kParallelToLine
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDistanceConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDistanceConstraint(bool bCreateImp = true);
	ACDBCORE2D_PORT AcDistanceConstraint(const AcGeVector3d& direction);
	ACDBCORE2D_PORT AcDistanceConstraint(const AcGraphNode::Id consLineId,
										 DirectionType type = kPerpendicularToLine);

	ACDBCORE2D_PORT AcGraphNode::Id constrainedLineId() const;
	ACDBCORE2D_PORT AcGeVector3d direction() const;
	ACDBCORE2D_PORT DirectionType directionType() const;
};

#include "IcArxPackPop.h"
