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
***     Description: Declaration of AcGiRenderSettingsTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiRenderSettingsTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiRenderSettingsTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual bool backFacesEnabled() const = 0;
	ACDBCORE2D_PORT virtual bool diagnosticBackgroundEnabled() const = 0;
	ACDBCORE2D_PORT virtual bool materialEnabled() const = 0;
	ACDBCORE2D_PORT virtual double modelScaleFactor(void) const = 0;
	ACDBCORE2D_PORT virtual bool shadowsEnabled() const = 0;
	ACDBCORE2D_PORT virtual bool textureSampling() const = 0;
	ACDBCORE2D_PORT virtual void setBackFacesEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setDiagnosticBackgroundEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setMaterialEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setModelScaleFactor(double scaleFactor) = 0;
	ACDBCORE2D_PORT virtual void setShadowsEnabled(bool enabled) = 0;
	ACDBCORE2D_PORT virtual void setTextureSampling(bool enabled) = 0;
};

#include "IcArxPackPop.h"
