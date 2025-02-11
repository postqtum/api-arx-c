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
***     Description: Declaration of AcCompositeConstraint class
***
*****************************************************************************/
#pragma once

#include "AcGeomConstraint.h"

#include "IcArxPackPush.h"

class AcCompositeConstraint : public AcGeomConstraint
{
protected:
	ACDBCORE2D_PORT AcCompositeConstraint() = default;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcCompositeConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT Acad::ErrorStatus getOwnedConstraints(
			AcArray<AcGeomConstraint*>& apSubConstraints) const;
};

#include "IcArxPackPop.h"
