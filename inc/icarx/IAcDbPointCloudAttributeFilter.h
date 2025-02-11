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
***     Description: Declaration of IAcDbPointCloudAttributeFilter interface
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "../gevec3d.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcDbPointCloudAttributeFilter
{
public:
	virtual ~IAcDbPointCloudAttributeFilter() = 0 {};

	virtual IAcDbPointCloudAttributeFilter* clone() const = 0;
	virtual void freeObject() = 0;
	virtual bool testPoint(const uint8_t rgba[4], uint8_t intensity, const float normal[3],
						   uint8_t classification) const = 0;
	virtual IAcDbPointCloudAttributeFilter* transformFilter(const AcGeMatrix3d& mat) const = 0;
};

#include "IcArxPackPop.h"
