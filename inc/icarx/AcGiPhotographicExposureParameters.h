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
***     Description: Declaration of AcGiPhotographicExposureParameters class
***
*****************************************************************************/
#pragma once

#include "AcGiToneOperatorParameters.h"

#include "IcArxPackPush.h"

class AcGiPhotographicExposureParameters : public AcGiToneOperatorParameters
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiPhotographicExposureParameters, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiPhotographicExposureParameters() = default;
	ACDBCORE2D_PORT AcGiPhotographicExposureParameters(const AcGiPhotographicExposureParameters&);
	ACDBCORE2D_PORT ~AcGiPhotographicExposureParameters() = default;
	ACDBCORE2D_PORT AcGiPhotographicExposureParameters& operator=(
			const AcGiPhotographicExposureParameters&);
	ACDBCORE2D_PORT bool operator==(const AcGiPhotographicExposureParameters&) const;

	ACDBCORE2D_PORT static double convertBrightnessToExposure(double brt);
	ACDBCORE2D_PORT static double convertExposureToBrightness(double exp);
	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject*) override;
	ACDBCORE2D_PORT double exposure() const;
	ACDBCORE2D_PORT double whitePoint() const;
	ACDBCORE2D_PORT bool setBrightness(double) override;
	ACDBCORE2D_PORT bool setExposure(double exposure);
	ACDBCORE2D_PORT bool setWhitePoint(double whitePoint);
};

#include "IcArxPackPop.h"
