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
***     Description: Declaration of AcG2SmoothConstraint class
***
*****************************************************************************/
#pragma once

#include "AcCompositeConstraint.h"

#include "IcArxPackPush.h"

class AcG2SmoothConstraint : public AcCompositeConstraint
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcG2SmoothConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcG2SmoothConstraint(bool bCreateImp = true);
};

#include "IcArxPackPop.h"
