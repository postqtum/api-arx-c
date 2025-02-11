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
***     Description: Declaration of IAcDbPointCloudSpatialFilter interface
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "../gevec3d.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcDbPointCloudSpatialFilter
{
public:
	enum FilterResult
	{
		FILTER_INSIDE = 0,
		FILTER_OUTSIDE,
		FILTER_INTERSECTS
	};

public:
	virtual ~IAcDbPointCloudSpatialFilter() = 0 {}

	virtual IAcDbPointCloudSpatialFilter* clone() const = 0;
	virtual void freeObject() = 0;
	virtual IAcDbPointCloudSpatialFilter::FilterResult testCell(const AcGePoint3d& min,
																const AcGePoint3d& max) const = 0;
	virtual IAcDbPointCloudSpatialFilter::FilterResult testPoint(
			const AcGePoint3d& point) const = 0;
	virtual IAcDbPointCloudSpatialFilter* transformFilter(const AcGeMatrix3d& mat) const = 0;
};

#include "IcArxPackPop.h"
