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
***     Description: Declaration of AcEqualHelpParameterConstraint class
***
*****************************************************************************/
#pragma once

#include "AcGeomConstraint.h"

#include "IcArxPackPush.h"

class AcEqualHelpParameterConstraint : public AcGeomConstraint
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcEqualHelpParameterConstraint, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT AcEqualHelpParameterConstraint(bool bCreateImp = true);

	ACDBCORE2D_PORT Acad::ErrorStatus getEqualHelpParameters(
			AcHelpParameter*& pHelpParameter1, AcHelpParameter*& pHelpParameter2) const;
};

#include "IcArxPackPop.h"
