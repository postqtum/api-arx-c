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
***     Description: Implementation of AcConstrainedGeometry class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../AcConstraintGroupNode.h"

#include "AcDbObjectId.h"
#include "AcDbFullSubentPathArray.h"

class AcGeomConstraint;
class AcConstrainedRigidSet;

#include "IcArxPackPush.h"

class AcConstrainedGeometry : public AcConstraintGroupNode
{
protected:
	ACDBCORE2D_PORT AcConstrainedGeometry();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedGeometry, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbObjectId geomDependencyId() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getCommonConstraints(
			AcConstrainedGeometry* pOtherConsGeom, AcArray<AcGeomConstraint*>& apConstraints) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConnectedConstraints(
			AcArray<AcGeomConstraint*>& apConstraints) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConnectedGeometries(
			AcArray<AcConstrainedGeometry*>& apConsGeoms) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFullSubentPaths(
			AcDbFullSubentPathArray& subentPaths) const;
	ACDBCORE2D_PORT AcConstrainedRigidSet* getOwningRigidSet() const;
	ACDBCORE2D_PORT virtual bool isReadOnly() const;
};

#include "IcArxPackPop.h"
