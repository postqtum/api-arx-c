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
***     Description: Declaration of AcGiSolidBackgroundTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiSolidBackgroundTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGiSolidBackgroundTraits, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual AcCmEntityColor colorSolid() const = 0;
	ACDBCORE2D_PORT virtual void setColorSolid(const AcCmEntityColor& color) = 0;
};

#include "IcArxPackPop.h"
