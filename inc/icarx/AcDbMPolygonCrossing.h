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
***     Description: Declaration of AcDbMPolygonCrossing class
***
*****************************************************************************/
#pragma once

#include "../gept2dar.h"

#include "AcMPolygonPort.h"

#include "IcArxPackPush.h"

class AcDbMPolygonCrossing
{
private:
	void* pImp;

public:
	ACMPOLYGON_PORT AcDbMPolygonCrossing();
	ACMPOLYGON_PORT ~AcDbMPolygonCrossing();

	ACMPOLYGON_PORT AcGePoint2d getCrossingPoint() const;
	ACMPOLYGON_PORT int getEdgeIndex() const;
	ACMPOLYGON_PORT int getLoopIndex() const;
	ACMPOLYGON_PORT void setCrossingPoint(const AcGePoint2d& pt);
	ACMPOLYGON_PORT void setEdgeIndex(int index);
	ACMPOLYGON_PORT void setLoopIndex(int index);
};

#include "IcArxPackPop.h"
