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
***     Description: Declaration of AcDbCustomOsnapInfo class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"
#include "../rxobject.h"
#include "../dbintar.h"
#include "../adesk.h"

class AcDbEntity;
class AcGeCurve3d;

#include "IcArxPackPush.h"

class AcDbCustomOsnapInfo : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbCustomOsnapInfo);

	virtual Acad::ErrorStatus getOsnapInfo(
			AcDbEntity* pickedObject, IcArx::Integers::GsMarker gsSelectionMark, const AcGePoint3d& pickPoint,
			const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform,
			AcArray<AcGePoint3d>& snapPoints, AcDbIntArray& geomIdsForPts,
			AcArray<AcGeCurve3d*>& snapCurves, AcDbIntArray& geomIdsForLines) = 0;
};

#include "IcArxPackPop.h"
