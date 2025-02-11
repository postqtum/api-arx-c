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
***     Description: Declaration of AcDbExtents class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"
#include "../AcHeapOpers.h"
#include "../gepnt3d.h"

class AcDbBlockTableRecord;

#include "IcArxPackPush.h"

class AcDbExtents : public AcHeapOperators
{
private:
	AcGePoint3d mMinPoint;
	AcGePoint3d mMaxPoint;

public:
	ACDBCORE2D_PORT AcDbExtents();
	ACDBCORE2D_PORT AcDbExtents(const AcDbExtents& src);
	AcDbExtents(const AcGePoint3d& min, const AcGePoint3d& max);
	bool operator==(const AcDbExtents& other);

	Acad::ErrorStatus addBlockExt(AcDbBlockTableRecord* pBTR);
	ACDBCORE2D_PORT void addExt(const AcDbExtents& src);
	ACDBCORE2D_PORT void addPoint(const AcGePoint3d& pt);
	void expandBy(const AcGeVector3d& vec);
	AcGePoint3d minPoint() const { return mMinPoint; }
	AcGePoint3d maxPoint() const { return mMaxPoint; }
	ACDBCORE2D_PORT Acad::ErrorStatus set(const AcGePoint3d& min, const AcGePoint3d& max);
	void transformBy(const AcGeMatrix3d& mat);
};

#include "IcArxPackPop.h"
