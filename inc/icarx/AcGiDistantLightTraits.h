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
***     Description: Declaration of AcGiDistantLightTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiStandardLightTraits.h"

class AcGeVector3d;
class AcGiColorRGB;

#include "IcArxPackPush.h"

class AcGiDistantLightTraits : public AcGiStandardLightTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiDistantLightTraits);

	virtual bool isSunlight() const = 0;
	virtual void lampColor(AcGiColorRGB& rgbColor) const = 0;
	virtual AcGeVector3d lightDirection() const = 0;
	virtual double physicalIntensity() const = 0;
	virtual void setIsSunlight(bool isSunlight) = 0;
	virtual void setLampColor(const AcGiColorRGB& rgbColor) = 0;
	virtual void setLightDirection(const AcGeVector3d& vec) = 0;
	virtual void setPhysicalIntensity(double physicalIntensity) = 0;
	virtual void setSkyParameters(const AcGiSkyParameters& params) = 0;
	virtual void skyParameters(AcGiSkyParameters& params) const = 0;
};

#include "IcArxPackPop.h"
