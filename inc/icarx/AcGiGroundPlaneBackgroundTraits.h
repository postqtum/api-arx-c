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
***     Description: Declaration of AcGiGroundPlaneBackgroundTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiGroundPlaneBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiGroundPlaneBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual AcCmEntityColor colorGroundPlaneFar() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorGroundPlaneNear() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorSkyHorizon() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorSkyZenith() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorUndergroundAzimuth() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorUndergroundHorizon() const = 0;
	ACDBCORE2D_PORT virtual void setColorGroundPlaneFar(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorGroundPlaneNear(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorSkyHorizon(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorSkyZenith(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorUndergroundAzimuth(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorUndergroundHorizon(const AcCmEntityColor& color) = 0;
};

#include "IcArxPackPop.h"
