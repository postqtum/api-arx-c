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
***     Description: Declaration of AcConstrainedCurve class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedImplicitPoint.h"

#include "IcArxPackPush.h"

class AcConstrainedCurve : public AcConstrainedGeometry
{
protected:
	ACDBCORE2D_PORT explicit AcConstrainedCurve() = default;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedCurve, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual void getConstrainedImplicitPoints(
			AcArray<AcConstrainedImplicitPoint*>& apImplicitPoints) const;
	ACDBCORE2D_PORT virtual bool isBounded() const;
};

#include "IcArxPackPop.h"

