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
***     Description: Declaration of AcGiLightTraits class
***
*****************************************************************************/
#pragma once

#include "AcGiNonEntityTraits.h"

#include "IcArxPackPush.h"

class AcGiLightTraits : public AcGiNonEntityTraits
{
public:
	ACRX_DECLARE_MEMBERS(AcGiLightTraits);

	virtual bool isOn() const = 0;
	virtual void setOn(bool on) = 0;
};

#include "IcArxPackPop.h"
