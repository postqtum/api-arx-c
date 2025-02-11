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
***     Description: Declaration of AcDbExtents2d class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"
#include "../AcHeapOpers.h"
#include "../gepnt2d.h"

#include "IcArxPackPush.h"

class AcDbExtents2d : public AcHeapOperators
{
private:
	AcGePoint2d mMinPoint;
	AcGePoint2d mMaxPoint;

public:
	AcDbExtents2d();
	AcDbExtents2d(const AcDbExtents2d& src);
	AcDbExtents2d(const AcGePoint2d& min, const AcGePoint2d& max);
	bool operator==(const AcDbExtents2d& other);

	void addExt(const AcDbExtents2d& src);
	void addPoint(const AcGePoint2d& pt);
	void expandBy(const AcGeVector2d& vec);
	AcGePoint2d minPoint() const { return mMinPoint; }
	AcGePoint2d maxPoint() const { return mMaxPoint; }
	void transformBy(const AcGeMatrix2d& mat);
	Acad::ErrorStatus set(const AcGePoint2d& min, const AcGePoint2d& max);
};

#include "IcArxPackPop.h"
