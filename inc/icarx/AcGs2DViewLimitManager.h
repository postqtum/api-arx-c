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
***     Description: Declaration of AcGs2DViewLimitManager class
***
*****************************************************************************/

#pragma once

class AcGePoint3d;

#include "IcArxPackPush.h"

class AcGs2DViewLimitManager
{
public:
	virtual ~AcGs2DViewLimitManager() = default;

	virtual bool testView(AcGePoint3d const& target, double dFieldHeight) = 0;
};

#include "IcArxPackPop.h"

AcGs2DViewLimitManager* acgsCreate2DViewLimitManager(int viewportNumber);
void acgsDestroy2DViewLimitManager(AcGs2DViewLimitManager* pLimitManager);
