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
***     Description: Declaration of AcConstrainedConstructionLine class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedLine.h"

#include "IcArxPackPush.h"

class AcConstrainedConstructionLine : public AcConstrainedLine
{
protected:
	ACDBCORE2D_PORT explicit AcConstrainedConstructionLine();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedConstructionLine, ACDBCORE2D_PORT);
};

#include "IcArxPackPop.h"
