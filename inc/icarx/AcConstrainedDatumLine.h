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
***     Description: Declaration of AcConstrainedDatumLine class
***
*****************************************************************************/
#pragma once

#include "AcConstrainedConstructionLine.h"

#include "IcArxPackPush.h"

class AcConstrainedDatumLine : public AcConstrainedConstructionLine
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcConstrainedDatumLine, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcConstrainedDatumLine(bool bCreateImp = true);
	ACDBCORE2D_PORT explicit AcConstrainedDatumLine(const AcGePoint3d& pointOnLine,
													const AcGeVector3d& direction);
};

#include "IcArxPackPop.h"
