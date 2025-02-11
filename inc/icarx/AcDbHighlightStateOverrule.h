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
***     Description: Declaration of AcDbHighlightStateOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbHighlightStateOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbHighlightStateOverrule);

	ACDBCORE2D_PORT AcDbHighlightStateOverrule();

	ACDBCORE2D_PORT virtual AcGiHighlightStyle highlightState(AcDbEntity* pSubject,
															  const AcDbFullSubentPath& subId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus popHighlight(AcDbEntity* pSubject,
														   const AcDbFullSubentPath& subId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus pushHighlight(AcDbEntity* pSubject,
															const AcDbFullSubentPath& subId,
															AcGiHighlightStyle highlightStyle);
};

#include "IcArxPackPop.h"
