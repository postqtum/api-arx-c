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
***     Description: Declaration of AcRxAlternateLocalizedNameAttribute class
***
*****************************************************************************/
#pragma once

#include "AcRxLocalizedNameAttribute.h"

#include "IcArxPackPush.h"

class AcRxAlternateLocalizedNameAttribute : public AcRxLocalizedNameAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxAlternateLocalizedNameAttribute, ACBASE_PORT);

	ACBASE_PORT AcRxAlternateLocalizedNameAttribute(unsigned int id);
	ACBASE_PORT AcRxAlternateLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);
};

#include "IcArxPackPop.h"
