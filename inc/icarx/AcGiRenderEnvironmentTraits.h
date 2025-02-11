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
***     Description: Declaration of AcGiRenderEnvironmentTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

class AcGiMaterialTexture;

#include "IcArxPackPush.h"

class AcGiRenderEnvironmentTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiRenderEnvironmentTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual bool enable() const = 0;
	ACDBCORE2D_PORT virtual AcGiMaterialTexture* environmentMap() const = 0;
	ACDBCORE2D_PORT virtual double farDistance() const = 0;
	ACDBCORE2D_PORT virtual double farPercentage() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor fogColor() const = 0;
	ACDBCORE2D_PORT virtual bool isBackground() const = 0;
	ACDBCORE2D_PORT virtual double nearDistance() const = 0;
	ACDBCORE2D_PORT virtual double nearPercentage() const = 0;
	ACDBCORE2D_PORT virtual void setEnable(const bool bEnable) = 0;
	ACDBCORE2D_PORT virtual void setEnvironmentMap(const AcGiMaterialTexture* map) = 0;
	ACDBCORE2D_PORT virtual void setFarDistance(const double farDist) = 0;
	ACDBCORE2D_PORT virtual void setFarPercentage(const double farPct) = 0;
	ACDBCORE2D_PORT virtual void setFogColor(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setIsBackground(const bool bEnable) = 0;
	ACDBCORE2D_PORT virtual void setNearDistance(const double nearDist) = 0;
	ACDBCORE2D_PORT virtual void setNearPercentage(const double nearPct) = 0;
};

#include "IcArxPackPop.h"
