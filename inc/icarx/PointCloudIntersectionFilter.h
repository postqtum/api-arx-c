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
***     Description: Declaration of PointCloudIntersectionFilter class
***
*****************************************************************************/
#pragma once

#include "PointCloudBinaryOperatorFilter.h"

#include "IcArxPackPush.h"

class ACDB_PORT PointCloudIntersectionFilter : public PointCloudBinaryOperatorFilter
{
public:
	PointCloudIntersectionFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
	~PointCloudIntersectionFilter();

	IPointCloudFilter* clone() const override;
	void freeObject() override;
	int testCell(double minX, double minY, double minZ, double maxX, double maxY,
				 double maxZ) const override;
	bool testPoint(float x, float y, float z) const override;
};

#include "IcArxPackPop.h"
