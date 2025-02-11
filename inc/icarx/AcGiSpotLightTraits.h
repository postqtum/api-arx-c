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
***     Description: Declaration of AcGiSpotLightTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiStandardLightTraits.h"

class AcGePoint3d;
class AcGiLightAttenuation;
class AcGiColorRGB;

#include "IcArxPackPush.h"

class AcGiSpotLightTraits : public AcGiStandardLightTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiSpotLightTraits);

	virtual double falloff() const = 0;
	virtual double hotspot() const = 0;
	virtual void lampColor(AcGiColorRGB& rgbColor) const = 0;
	virtual void lightAttenuation(AcGiLightAttenuation& atten) const = 0;
	virtual double physicalIntensity() const = 0;
	virtual AcGePoint3d position() const = 0;
	virtual void setAttenuation(const AcGiLightAttenuation& atten) = 0;
	virtual bool setHotspotAndFalloff(double hotspot, double falloff) = 0;
	virtual void setLampColor(const AcGiColorRGB& rgbColor) = 0;
	virtual void setPhysicalIntensity(double physicalIntensity) = 0;
	virtual void setPosition(const AcGePoint3d& pos) = 0;
	virtual void setTargetLocation(const AcGePoint3d& loc) = 0;
	virtual AcGePoint3d targetLocation() const = 0;
};

#include "IcArxPackPop.h"
