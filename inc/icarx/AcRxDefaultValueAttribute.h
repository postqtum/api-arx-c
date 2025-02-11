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
***     Description: Declaration of AcRxDefaultValueAttribute class
***
*****************************************************************************/
#pragma once

#include "../rxvalue.h"
#include "AcRxAttribute.h"

#include "IcArxPackPush.h"

class AcRxDefaultValueAttribute : public AcRxAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDefaultValueAttribute, ACBASE_PORT);
	ACBASE_PORT AcRxDefaultValueAttribute(const AcRxValue& value);
	ACBASE_PORT const AcRxValue& value() const;
};

#include "IcArxPackPop.h"
