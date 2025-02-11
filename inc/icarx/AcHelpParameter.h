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
***     Description: Declaration of AcHelpParameter class
***
*****************************************************************************/
#pragma once

#include "../AcConstraintGroupNode.h"

class AcConstrainedGeometry;
class AcGeomConstraint;
class AcEqualHelpParameterConstraint;

#include "IcArxPackPush.h"

class AcHelpParameter : public AcConstraintGroupNode
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcHelpParameter, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcHelpParameter(bool bCreateImp = true);

	ACDBCORE2D_PORT Acad::ErrorStatus getConnectedConstraint(AcGeomConstraint*& pConstraint) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConnectedEqualparamConstraints(
			AcArray<AcEqualHelpParameterConstraint*>& apEqualParamConstrs) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getConnectedGeometry(AcConstrainedGeometry*& pGeometry) const;
	ACDBCORE2D_PORT double getValue() const;
};

#include "IcArxPackPop.h"
