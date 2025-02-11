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
***     Description: Declaration of AcGiGradientBackgroundTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiGradientBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiGradientBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual AcCmEntityColor colorBottom() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorMiddle() const = 0;
	ACDBCORE2D_PORT virtual AcCmEntityColor colorTop() const = 0;
	ACDBCORE2D_PORT virtual double height() const = 0;
	ACDBCORE2D_PORT virtual double horizon() const = 0;
	ACDBCORE2D_PORT virtual double rotation() const = 0;
	ACDBCORE2D_PORT virtual void setColorBottom(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorMiddle(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setColorTop(const AcCmEntityColor& color) = 0;
	ACDBCORE2D_PORT virtual void setHeight(double height) = 0;
	ACDBCORE2D_PORT virtual void setHorizon(double horizon) = 0;
	ACDBCORE2D_PORT virtual void setRotation(double rotation) = 0;
};

#include "IcArxPackPop.h"
