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
***     Description: Declaration of AcRxUiPlacementAttribute class
***
*****************************************************************************/
#pragma once

#include "AcRxAttribute.h"

#include "IcArxPackPush.h"

class AcRxUiPlacementAttribute : public AcRxAttribute
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxUiPlacementAttribute, ACBASE_PORT);

	ACBASE_PORT AcRxUiPlacementAttribute(const ACHAR* category, unsigned int weight);

	ACBASE_PORT static const ACHAR* getCategory(const AcRxObject* member);
	ACBASE_PORT static float getWeight(const AcRxObject* member);
};

#include "IcArxPackPop.h"
