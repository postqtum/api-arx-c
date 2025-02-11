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
***     Description: Declaration of AcDbMPolygonNode class
***
*****************************************************************************/
#pragma once

#include "../acarray.h"

#include "IcArxPackPush.h"

class AcDbMPolygonNode
{
public:
	AcDbMPolygonNode* mParent = nullptr;
	AcArray<AcDbMPolygonNode*> mChildren;
	int mLoopIndex = -1;
};

#include "IcArxPackPop.h"
