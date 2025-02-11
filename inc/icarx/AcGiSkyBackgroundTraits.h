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
***     Description: Declaration of AcGiSkyBackgroundTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

class AcGiSkyParameters;

#include "IcArxPackPush.h"

class AcGiSkyBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiSkyBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual void setSkyParameters(const AcGiSkyParameters& params) = 0;
	ACDBCORE2D_PORT virtual void skyParameters(AcGiSkyParameters& params) const = 0;
};

#include "IcArxPackPop.h"
