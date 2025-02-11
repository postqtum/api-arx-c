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
***     Description: Declaration of AcRxLocalizedNameAttribute class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "AcRxAttribute.h"

#include "IcArxPackPush.h"

class AcRxLocalizedNameAttribute : public AcRxAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxLocalizedNameAttribute, ACBASE_PORT);

	ACBASE_PORT AcRxLocalizedNameAttribute(unsigned int id);
	ACBASE_PORT AcRxLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);

	ACBASE_PORT static AcString getLocalizedName(const AcRxObject* pO);
	ACBASE_PORT unsigned int id() const;
	ACBASE_PORT unsigned int sourceHint() const;
};

#include "IcArxPackPop.h"
