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
***     Description: Declaration of AcGiRapidRTRenderSettingsTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

enum AcGiFilterType
{
	krEBox = 0,
	krETriangle,
	krEGaussian,
	krELanczos,
	krEMitchell
};

enum AcGiLightingMode
{
	krESimplistic = 0,
	krEBasic,
	krEAdvanced
};

enum AcGiQuitCondition
{
	krEQuitByRenderLevel = 0,
	krEQuitByRenderTime
};

#include "IcArxPackPush.h"

class AcGiRapidRTRenderSettingsTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiRapidRTRenderSettingsTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual int desiredRenderLevel() const = 0;
	ACDBCORE2D_PORT virtual int desiredRenderTime() const = 0;
	ACDBCORE2D_PORT virtual float filterHeight() const = 0;
	ACDBCORE2D_PORT virtual AcGiFilterType filterType() const = 0;
	ACDBCORE2D_PORT virtual float filterWidth() const = 0;
	ACDBCORE2D_PORT virtual AcGiLightingMode lightingMode() const = 0;
	ACDBCORE2D_PORT virtual AcGiQuitCondition quitCondition() const = 0;
	ACDBCORE2D_PORT virtual void setDesiredRenderLevel(int renderLevel) = 0;
	ACDBCORE2D_PORT virtual void setDesiredRenderTime(int renderTime) = 0;
	ACDBCORE2D_PORT virtual void setFilterHeight(float height) = 0;
	ACDBCORE2D_PORT virtual void setFilterType(AcGiFilterType filterInfo) = 0;
	ACDBCORE2D_PORT virtual void setFilterWidth(float width) = 0;
	ACDBCORE2D_PORT virtual void setLightingMode(AcGiLightingMode mode) = 0;
	ACDBCORE2D_PORT virtual void setQuitCondition(AcGiQuitCondition quitCondition) = 0;
};

#include "IcArxPackPop.h"
