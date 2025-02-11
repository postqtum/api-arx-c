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
***     Description: Declaration of AcDbMPolygonCrossingArray class
***
*****************************************************************************/
#pragma once

#include "AcDbMPolygonCrossing.h"

#include "IcArxPackPush.h"

class AcDbMPolygonCrossingArray
{
public:
	AcArray<AcDbMPolygonCrossing*> mCrossingArray;

public:
	~AcDbMPolygonCrossingArray();
};

#include "IcArxPackPop.h"

inline AcDbMPolygonCrossingArray::~AcDbMPolygonCrossingArray()
{
	AcDbMPolygonCrossing* pCrossing;
	int numCross = mCrossingArray.length();
	for (int i = numCross - 1; i >= 0; i--)
	{
		pCrossing = mCrossingArray[i];
		mCrossingArray.removeAt(i);
		if (pCrossing)
			delete pCrossing;
	}
}
