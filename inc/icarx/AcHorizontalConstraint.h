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
***     Description: Declaration of AcHorizontalConstraint class
***
*****************************************************************************/
#pragma once

#include "AcParallelConstraint.h"

#include "IcArxPackPush.h"

class AcHorizontalConstraint : public AcParallelConstraint
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcHorizontalConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcHorizontalConstraint(bool bCreateImp = true);
};

#include "IcArxPackPop.h"
