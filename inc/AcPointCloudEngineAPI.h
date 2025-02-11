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
***     Description:
***
*****************************************************************************/
#pragma once

#include "acdbport.h"

#include "icarx/IcArxPackPush.h"

class ACDB_PORT IPointCloudFilter
{
public:
	virtual IPointCloudFilter* clone() const = 0;
	virtual void freeObject() = 0;
	virtual bool isInverted() const { return false; }
	virtual void prepareForCell(double& minX, double& minY, double& minZ, double& maxX,
								double& maxY, double& maxZ, long numTests)
	{
		(void)(minX);
		(void)(minY);
		(void)(minZ);
		(void)(maxX);
		(void)(maxY);
		(void)(maxZ);
		(void)(numTests);
	};
	virtual void setIsInverted(bool bInverted) { (void)(bInverted); }
	virtual int testCell(double minX, double minY, double minZ, double maxX, double maxY,
						 double maxZ) const = 0;
	virtual bool testPoint(float x, float y, float z) const = 0;
};

class ACDB_PORT IPointCloudFilter2 : public IPointCloudFilter
{
public:
	virtual ~IPointCloudFilter2() = default;

	virtual int testPoint(const double* pointData) const = 0;
	virtual IPointCloudFilter2* transformFilter(const double* transform4x4) const = 0;
};

#include "icarx/IcArxPackPop.h"
