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

#include "IcArxPackPush.h"

class AcGiIBLBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiIBLBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual AcString IBLImageName() const = 0;
	ACDBCORE2D_PORT virtual bool enable() const = 0;
	ACDBCORE2D_PORT virtual bool displayImage() const = 0;
	ACDBCORE2D_PORT virtual double rotation() const = 0;
	ACDBCORE2D_PORT virtual AcDbObjectId secondaryBackground() const = 0;
	ACDBCORE2D_PORT virtual void setDisplayImage(const bool bdisplay) = 0;
	ACDBCORE2D_PORT virtual void setEnable(const bool bEnable) = 0;
	ACDBCORE2D_PORT virtual void setIBLImageName(const AcString& name) = 0;
	ACDBCORE2D_PORT virtual void setRotation(const double rotation) = 0;
	ACDBCORE2D_PORT virtual void setSecondaryBackground(const AcDbObjectId bg) = 0;
};

#include "IcArxPackPop.h"
