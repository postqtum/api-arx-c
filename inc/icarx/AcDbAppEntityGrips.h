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
***     Description: Declaration of AcDbAppEntityGrips class
***
*****************************************************************************/
#pragma once

#include "AcRxProtocolReactor.h"
#include "AcDbFullSubentPathArray.h"
#include "../dbptrar.h"

class AcGeVector3d;
class AcDbEntity;

#include "IcArxPackPush.h"

class AcDbAppEntityGrips : public AcRxProtocolReactor
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAppEntityGrips);

	virtual Acad::ErrorStatus getGripPoints(AcDbGripDataPtrArray& grips,
											const double curViewUnitSize, const int gripSize,
											const AcGeVector3d& curViewDir, const int bitflags,
											AcDbEntity* pEntity) = 0;
	virtual void gripStatus(const AcDb::GripStat status, AcDbEntity* pEntity) = 0;
	virtual Acad::ErrorStatus moveGripPointsAt(const AcDbVoidPtrArray& gripAppData,
											   const AcGeVector3d& offset, const int bitflags,
											   AcDbEntity* pEntity) = 0;
};

#include "IcArxPackPop.h"
