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
***     Description: Declaration of AcGeOffsetCurve3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"

#include "icarx/IcArxPackPush.h"

class AcGeOffsetCurve3d : public AcGeCurve3d
{
public:
	GE_DLLEXPIMPORT AcGeOffsetCurve3d(const AcGeCurve3d& baseCurve, const AcGeVector3d& planeNormal,
									  double offsetDistance);
	GE_DLLEXPIMPORT AcGeOffsetCurve3d(const AcGeOffsetCurve3d&);
	~AcGeOffsetCurve3d() = default;
	GE_DLLEXPIMPORT AcGeOffsetCurve3d& operator=(const AcGeOffsetCurve3d&);

	GE_DLLEXPIMPORT const AcGeCurve3d* curve() const;
	GE_DLLEXPIMPORT AcGeVector3d normal() const;
	GE_DLLEXPIMPORT double offsetDistance() const;
	GE_DLLEXPIMPORT bool paramDirection() const;
	GE_DLLEXPIMPORT AcGeOffsetCurve3d& setCurve(const AcGeCurve3d& baseCurve);
	GE_DLLEXPIMPORT AcGeOffsetCurve3d& setNormal(const AcGeVector3d& planeNormal);
	GE_DLLEXPIMPORT AcGeOffsetCurve3d& setOffsetDistance(double offsetDistance);
	GE_DLLEXPIMPORT AcGeMatrix3d transformation() const;
};

#include "icarx/IcArxPackPop.h"
