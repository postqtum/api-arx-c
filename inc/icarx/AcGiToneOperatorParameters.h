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
***     Description: Declaration of AcGiToneOperatorParameters class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"
#include "AcCmColor.h"

#include "IcArxPackPush.h"

class AcGiToneOperatorParameters : public AcRxObject
{
public:
	enum ExteriorDaylightMode
	{
		kDaylightOff = 0,
		kDaylightOn,
		kDaylightAuto
	};

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiToneOperatorParameters, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcGiToneOperatorParameters() = default;
	ACDBCORE2D_PORT AcGiToneOperatorParameters(const AcGiToneOperatorParameters&);
	ACDBCORE2D_PORT ~AcGiToneOperatorParameters() = default;
	ACDBCORE2D_PORT AcGiToneOperatorParameters& operator=(const AcGiToneOperatorParameters&);
	ACDBCORE2D_PORT bool operator==(const AcGiToneOperatorParameters&) const;

	ACDBCORE2D_PORT virtual double brightness() const;
	ACDBCORE2D_PORT virtual bool chromaticAdaptation() const;
	ACDBCORE2D_PORT virtual bool colorDifferentiation() const;
	ACDBCORE2D_PORT virtual double contrast() const;
	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	ACDBCORE2D_PORT virtual ExteriorDaylightMode exteriorDaylight() const;
	ACDBCORE2D_PORT virtual bool isActive() const;
	ACDBCORE2D_PORT virtual double midTones() const;
	ACDBCORE2D_PORT virtual bool processBackground() const;
	ACDBCORE2D_PORT virtual bool setBrightness(double brightness);
	ACDBCORE2D_PORT virtual void setChromaticAdaptation(bool enable);
	ACDBCORE2D_PORT virtual void setColorDifferentiation(bool enable);
	ACDBCORE2D_PORT virtual bool setContrast(double contrast);
	ACDBCORE2D_PORT virtual bool setExteriorDaylight(ExteriorDaylightMode mode);
	ACDBCORE2D_PORT virtual void setIsActive(bool active);
	ACDBCORE2D_PORT virtual bool setMidTones(double midTones);
	ACDBCORE2D_PORT virtual void setProcessBackground(bool processBG);
	ACDBCORE2D_PORT virtual void setWhiteColor(const AcCmColor& color);
	ACDBCORE2D_PORT virtual AcCmColor whiteColor() const;
};

#include "IcArxPackPop.h"
