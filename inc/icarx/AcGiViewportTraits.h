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
***     Description: Declaration of AcGiViewportTraits classes
***
*****************************************************************************/
#pragma once

#include "AcGiDrawableTraits.h"

class AcGiToneOperatorParameters;

#include "IcArxPackPush.h"

class AcGiViewportTraits : public AcGiDrawableTraits
{
public:
	enum DefaultLightingType
	{
		kOneDistantLight = 0,
		kTwoDistantLights,
		kBackLighting,
		kUserDefinedLight // ODA added
	};

	ACRX_DECLARE_MEMBERS(AcGiViewportTraits);

	virtual AcCmColor ambientLightColor() const = 0;
	virtual AcDbObjectId background() const = 0;
	virtual double brightness() const = 0;
	virtual double contrast() const = 0;
	virtual DefaultLightingType defaultLightingType() const = 0;
	virtual bool isDefaultLightingOn() const = 0;
	virtual AcDbObjectId renderEnvironment() const = 0;
	virtual AcDbObjectId renderSettings() const = 0;
	virtual void setAmbientLightColor(const AcCmColor& clr) = 0;
	virtual void setBackground(const AcDbObjectId backgroundId) = 0;
	virtual void setBrightness(double brightness) = 0;
	virtual void setContrast(double contrast) = 0;
	virtual void setDefaultLightingOn(bool on) = 0;
	virtual void setDefaultLightingType(DefaultLightingType typ) = 0;
	virtual void setRenderEnvironment(const AcDbObjectId renderEnvId) = 0;
	virtual void setRenderSettings(const AcDbObjectId renderSettingsId) = 0;
	virtual void setToneOperatorParameters(const AcGiToneOperatorParameters& params) = 0;
	virtual void toneOperatorParameters(AcGiToneOperatorParameters& params) const = 0;
};

#include "IcArxPackPop.h"
