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
***     Description: Declaration of AcDbVisibilityOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"
#include "AcDbEnumType.h"

#include "IcArxPackPush.h"

class AcDbVisibilityOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbVisibilityOverrule);

	ACDBCORE2D_PORT AcDbVisibilityOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus setVisibility(AcDbEntity* pSubject,
															AcDb::Visibility newVal,
															bool doSubents = true);
	ACDBCORE2D_PORT virtual AcDb::Visibility visibility(const AcDbEntity* pSubject);
};

#include "IcArxPackPop.h"
