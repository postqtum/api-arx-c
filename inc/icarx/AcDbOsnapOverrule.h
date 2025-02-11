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
***     Description: Declaration of AcDbOsnapOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbOsnapOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbOsnapOverrule);

	ACDBCORE2D_PORT AcDbOsnapOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus getOsnapPoints(
			const AcDbEntity* pSubject, AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getOsnapPoints(
			const AcDbEntity* pSubject, AcDb::OsnapMode osnapMode, IcArx::Integers::GsMarker gsSelectionMark,
			const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
			const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds,
			const AcGeMatrix3d& insertionMat);
	ACDBCORE2D_PORT virtual bool isContentSnappable(const AcDbEntity* pSubject);
};

#include "IcArxPackPop.h"
