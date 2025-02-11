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
***     Description: Declaration of AcDbGripOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbGripOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbGripOverrule);

	ACDBCORE2D_PORT AcDbGripOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPoints(const AcDbEntity* pSubject,
															AcGePoint3dArray& gripPoints,
															AcDbIntArray& osnapModes,
															AcDbIntArray& geomIds);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getGripPoints(
			const AcDbEntity* pSubject, AcDbGripDataPtrArray& grips, const double curViewUnitSize,
			const int gripSize, const AcGeVector3d& curViewDir, const int bitflags);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getStretchPoints(const AcDbEntity* pSubject,
															   AcGePoint3dArray& stretchPoints);
	ACDBCORE2D_PORT virtual void gripStatus(AcDbEntity* pSubject, const AcDb::GripStat status);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAt(AcDbEntity* pSubject,
															   const AcDbIntArray& indices,
															   const AcGeVector3d& offset);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveGripPointsAt(AcDbEntity* pSubject,
															   const AcDbVoidPtrArray& gripAppData,
															   const AcGeVector3d& offset,
															   const int bitflags);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus moveStretchPointsAt(AcDbEntity* pSubject,
																  const AcDbIntArray& indices,
																  const AcGeVector3d& offset);
};

#include "IcArxPackPop.h"
