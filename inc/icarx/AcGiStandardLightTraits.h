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
***     Description: Declaration of AcGiStandardLightTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiLightTraits.h"

class AcGiShadowParameters;

#include "IcArxPackPush.h"

class AcGiStandardLightTraits : public AcGiLightTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiStandardLightTraits);

	virtual double intensity() const = 0;
	virtual AcCmColor lightColor() const = 0;
	virtual void setIntensity(double inten) = 0;
	virtual void setLightColor(const AcCmColor& color) = 0;
	virtual void setShadowParameters(const AcGiShadowParameters& params) = 0;
	virtual void shadowParameters(AcGiShadowParameters& params) const = 0;
};

#include "IcArxPackPop.h"
