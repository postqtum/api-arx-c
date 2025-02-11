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
***     Description: Declaration of AcGiDrawableOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"

#include "AcGiDrawable.h"

#include "IcArxPackPush.h"

class AcGiDrawableOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcGiDrawableOverrule);

	ACDBCORE2D_PORT AcGiDrawableOverrule();
	ACDBCORE2D_PORT virtual uint32_t setAttributes(AcGiDrawable* pSubject,
												   AcGiDrawableTraits* traits);
	ACDBCORE2D_PORT virtual void viewportDraw(AcGiDrawable* pSubject, AcGiViewportDraw* vd);
	ACDBCORE2D_PORT virtual uint32_t viewportDrawLogicalFlags(AcGiDrawable* pSubject,
															  AcGiViewportDraw* vd);
	ACDBCORE2D_PORT virtual bool worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd);
};

#include "IcArxPackPop.h"
