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
***     Description: Declaration of AcDbGeometryOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbGeometryOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbGeometryOverrule);

	ACDBCORE2D_PORT AcDbGeometryOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGeomExtents(const AcDbEntity* pSubject,
															 AcDbExtents& extents);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus intersectWith(const AcDbEntity* pSubject,
															const AcDbEntity* pEnt,
															AcDb::Intersect intType,
															AcGePoint3dArray& points,
															IcArx::Integers::GsMarker thisGsMarker = 0,
															IcArx::Integers::GsMarker otherGsMarker = 0);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus intersectWith(
			const AcDbEntity* pSubject, const AcDbEntity* pEnt, AcDb::Intersect intType,
			const AcGePlane& projPlane, AcGePoint3dArray& points, IcArx::Integers::GsMarker thisGsMarker = 0,
			IcArx::Integers::GsMarker otherGsMarker = 0);
};

#include "IcArxPackPop.h"
