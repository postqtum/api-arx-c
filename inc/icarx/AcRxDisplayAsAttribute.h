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
***     Description: Declaration of AcRxDisplayAsAttribute class
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "AcRxAttribute.h"
#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcRxDisplayAsAttribute : public AcRxAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDisplayAsAttribute, ACBASE_PORT);

	ACBASE_PORT AcRxDisplayAsAttribute(const ACHAR* name);

	ACDBCORE2D_PORT static AcString getDisplayValue(const AcRxDisplayAsAttribute* pAttr,
													const AcDbObjectId& id);
	ACBASE_PORT const ACHAR* path() const;
};

#include "IcArxPackPop.h"
