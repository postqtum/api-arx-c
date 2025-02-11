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
***     Description:
***
*****************************************************************************/
#pragma once

#include "AcPl.h"
#include "AcPlObject.h"

#include "icarx/IcArxPackPush.h"

class AcPlPrecisionEntry : public AcPlObject
{
private:
	ACPL_DECLARE_MEMBERS(AcPlPrecisionEntry)

public:
	ACPL_PORT AcPlPrecisionEntry();
	ACPL_PORT AcPlPrecisionEntry(const AcPlPrecisionEntry& src);
	ACPL_PORT ~AcPlPrecisionEntry();
	ACPL_PORT AcPlPrecisionEntry& operator=(const AcPlPrecisionEntry& src);

	ACPL_PORT const int colorResolution() const;
	ACPL_PORT const ACHAR* description() const;
	ACPL_PORT const double desiredPrecision() const;
	ACPL_PORT const int gradientResolution() const;
	ACPL_PORT const int monoResolution() const;
	ACPL_PORT void setColorResolution(int nColorResolution);
	ACPL_PORT void setDescription(const ACHAR* pDescription);
	ACPL_PORT void setDesiredPrecision(double dDesiredPrecision);
	ACPL_PORT void setGradientResolution(int nGradientResolution);
	ACPL_PORT void setMonoResolution(int nMonoResolution);
	ACPL_PORT void setTitle(const ACHAR* pTitle);
	ACPL_PORT void setUnitScale(const ACHAR* pUnitScale);
	ACPL_PORT void setUnitType(const ACHAR* pUnitType);
	ACPL_PORT const ACHAR* title() const;
	ACPL_PORT const ACHAR* unitScale() const;
	ACPL_PORT const ACHAR* unitType() const;
};

#include "icarx/IcArxPackPop.h"
