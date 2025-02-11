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
***     Description: Declaration of AcGiGradientFill class
***
*****************************************************************************/
#pragma once

#include "AcGiFill.h"
#include "AcCmColor.h"
#include "../AcArray.h"

class AcGiImpGradientFill;

#include "IcArxPackPush.h"

class AcGiGradientFill : public AcGiFill
{
private:
	AcGiImpGradientFill* mpImp = nullptr;

public:
	enum GradientType
	{
		kLinear,
		kCylinder,
		kInvCylinder,
		kSpherical,
		kHemispherical,
		kCurved,
		kInvSpherical,
		kInvHemispherical,
		kInvCurved
	};

	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiGradientFill, ACDBCORE2D_PORT);

	AcGiGradientFill();
	ACDBCORE2D_PORT AcGiGradientFill(double gradientAngle, double gradientShift, bool bAdjustAspect,
									 AcArray<AcCmColor>& gradientColors,
									 AcGiGradientFill::GradientType type);
	ACDBCORE2D_PORT AcGiGradientFill(const AcGiGradientFill&);
	ACDBCORE2D_PORT ~AcGiGradientFill();

	ACDBCORE2D_PORT double gradientAngle() const;
	ACDBCORE2D_PORT const AcArray<AcCmColor>& gradientColors() const;
	ACDBCORE2D_PORT double gradientShift() const;
	ACDBCORE2D_PORT const AcGiGradientFill::GradientType gradientType() const;
	ACDBCORE2D_PORT bool isAdjustAspect() const;
	ACDBCORE2D_PORT void setGradientAngle(double val);
	ACDBCORE2D_PORT void setGradientColors(const AcArray<AcCmColor>& val);
	ACDBCORE2D_PORT void setGradientShift(double val);
	ACDBCORE2D_PORT void setGradientType(AcGiGradientFill::GradientType type);
	ACDBCORE2D_PORT void setIsAdjustAspect(bool val);
};

#include "IcArxPackPop.h"
