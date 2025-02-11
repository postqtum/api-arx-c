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
***     Description: Declaration of PointCloudBinaryOperatorFilter class
***
*****************************************************************************/
#pragma once

#include "../AcPointCloudEngineAPI.h"

#include "IcArxPackPush.h"

class ACDB_PORT PointCloudBinaryOperatorFilter : public IPointCloudFilter
{
protected:
	IPointCloudFilter* mpLeftFilter = nullptr;
	IPointCloudFilter* mpRightFilter = nullptr;

private:
	bool mbIsInverted = false;

protected:
	PointCloudBinaryOperatorFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
	PointCloudBinaryOperatorFilter(const PointCloudBinaryOperatorFilter& other);

public:
	virtual ~PointCloudBinaryOperatorFilter();
	PointCloudBinaryOperatorFilter& operator=(const PointCloudBinaryOperatorFilter&) = delete;

	IPointCloudFilter* clone() const override = 0;
	void freeObject() override = 0;
	bool isInverted() const override;
	void setIsInverted(bool bInverted) override;
	int testCell(double minX, double minY, double minZ, double maxX, double maxY,
				 double maxZ) const override = 0;
	bool testPoint(float x, float y, float z) const override = 0;
};

#include "IcArxPackPop.h"
