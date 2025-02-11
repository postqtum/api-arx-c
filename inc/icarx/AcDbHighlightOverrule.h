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
***     Description: Declaration of AcDbHighlightOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbHighlightOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbHighlightOverrule);

	ACDBCORE2D_PORT AcDbHighlightOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus highlight(
			const AcDbEntity* pSubject, const AcDbFullSubentPath& subId = kNullSubent,
			const bool highlightAll = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus unhighlight(
			const AcDbEntity* pSubject, const AcDbFullSubentPath& subId = kNullSubent,
			const bool highlightAll = false);
};

#include "IcArxPackPop.h"
