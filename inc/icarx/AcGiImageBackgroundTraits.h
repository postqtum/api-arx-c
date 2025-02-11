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
***     Description: Declaration of AcGiImageBackgroundTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiImageBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiImageBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual bool fitToScreen() const = 0;
	ACDBCORE2D_PORT virtual const ACHAR* imageFilename() const = 0;
	ACDBCORE2D_PORT virtual bool maintainAspectRatio() const = 0;
	ACDBCORE2D_PORT virtual void setFitToScreen(bool bFitToScreen) = 0;
	ACDBCORE2D_PORT virtual void setImageFilename(const ACHAR* filename) = 0;
	ACDBCORE2D_PORT virtual void setMaintainAspectRatio(bool bMaintainAspectRatio) = 0;
	ACDBCORE2D_PORT virtual void setUseTiling(bool bUseTiling) = 0;
	ACDBCORE2D_PORT virtual void setXOffset(double xOffset) = 0;
	ACDBCORE2D_PORT virtual void setXScale(double xScale) = 0;
	ACDBCORE2D_PORT virtual void setYOffset(double yOffset) = 0;
	ACDBCORE2D_PORT virtual void setYScale(double yScale) = 0;
	ACDBCORE2D_PORT virtual bool useTiling() const = 0;
	ACDBCORE2D_PORT virtual double xOffset() const = 0;
	ACDBCORE2D_PORT virtual double xScale() const = 0;
	ACDBCORE2D_PORT virtual double yOffset() const = 0;
	ACDBCORE2D_PORT virtual double yScale() const = 0;
};

#include "IcArxPackPop.h"
