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
***     Description: Declaration of AcExplicitConstraint class
***
*****************************************************************************/
#pragma once

#include "AcGeomConstraint.h"

#include "IcArxPackPush.h"

class AcExplicitConstraint : public AcGeomConstraint
{
protected:
	ACDBCORE2D_PORT AcExplicitConstraint() = default;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcExplicitConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcDbObjectId dimDependencyId() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getMeasuredValue(double&) const;
	ACDBCORE2D_PORT Acad::ErrorStatus setDimDependencyId(const AcDbObjectId& dimDependencyId);
	ACDBCORE2D_PORT AcDbObjectId valueDependencyId() const;
};

#include "IcArxPackPop.h"
