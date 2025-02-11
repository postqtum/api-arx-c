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
***     Description: Declaration of AcGiGlyph class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "AcGiDrawable.h"

#include "IcArxPackPush.h"

class AcGiGlyph : public AcGiDrawable
{
protected:
	uint32_t subSetAttributes(AcGiDrawableTraits*) override { return 0; }
	void subViewportDraw(AcGiViewportDraw* vportDrawContext) override = 0;
	bool subWorldDraw(AcGiWorldDraw*) override { return false; };

public:
	ACRX_DECLARE_MEMBERS(AcGiGlyph);

	AcDbObjectId id() const override { return 0; }
	bool isPersistent() const override { return false; }
	virtual Acad::ErrorStatus setLocation(const AcGePoint3d& dcsPoint) = 0;
};

#include "IcArxPackPop.h"
