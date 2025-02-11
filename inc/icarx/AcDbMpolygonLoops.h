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
***     Description: Declaration of AcDbMpolygonLoops class
***
*****************************************************************************/
#pragma once

#include "../gept2dar.h"

#include "IcArxPackPush.h"

class AcDbMpolygonLoops
{
public:
	int mLoopIndex;
	bool mIsText;
	int mGripIndex;
	int mGripCount;
	AcGePoint2dArray mVertexPoints;
	AcGeDoubleArray mVertexBulges;

public:
	AcDbMpolygonLoops(int lindex, int gindex = 0, int gcnt = 0);
};

#include "IcArxPackPop.h"

inline AcDbMpolygonLoops::AcDbMpolygonLoops(int lindex, int gindex, int gcnt)
{
	mLoopIndex = lindex;
	mGripIndex = gindex;
	mGripCount = gcnt;
}
