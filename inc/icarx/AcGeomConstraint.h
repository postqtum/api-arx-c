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
***     Description: Declaration of AcGeomConstraint class
***
*****************************************************************************/
#pragma once

#include "../AcConstraintGroupNode.h"

class AcConstrainedGeometry;
class AcHelpParameter;
class AcCompositeConstraint;

#include "IcArxPackPush.h"

class AcGeomConstraint : public AcConstraintGroupNode
{
public:
	enum GeomConstraintType
	{
		kHorizontal = 0,
		kVertical,
		kParallel,
		kPerpendicular,
		kNormal,
		kColinear,
		kCoincident,
		kConcentric,
		kTangent,
		kEqualRadius,
		kEqualLength,
		kSymmetric,
		kG2Smooth,
		kFix
	};

protected:
	ACDBCORE2D_PORT AcGeomConstraint();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGeomConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT Acad::ErrorStatus deactivate();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getConnectedGeometries(
			AcArray<AcConstrainedGeometry*>& apConsGeoms) const;
	ACDBCORE2D_PORT virtual AcHelpParameter* getConnectedHelpParameterFor(
			const AcConstrainedGeometry* pConsGeom) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getConnectedHelpParameters(
			AcArray<AcHelpParameter*>& apHelpParameters) const;
	ACDBCORE2D_PORT AcCompositeConstraint* getOwningCompositeConstraint() const;
	ACDBCORE2D_PORT bool isActive() const;
	ACDBCORE2D_PORT bool isEnabled() const;
	ACDBCORE2D_PORT bool isImplied() const;
	ACDBCORE2D_PORT bool isInternal() const;
	ACDBCORE2D_PORT Acad::ErrorStatus reactivate();
	ACDBCORE2D_PORT void setIsImplied(bool yesNo);
};

#include "IcArxPackPop.h"
