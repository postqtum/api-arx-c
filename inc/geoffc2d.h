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
***     Description: Declaration of AcGeOffsetCurve2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"

#include "icarx/IcArxPackPush.h"

class AcGeOffsetCurve2d : public AcGeCurve2d
{
public:
	GE_DLLEXPIMPORT AcGeOffsetCurve2d(const AcGeCurve2d& baseCurve, double offsetDistance);
	GE_DLLEXPIMPORT AcGeOffsetCurve2d(const AcGeOffsetCurve2d&);
	~AcGeOffsetCurve2d() = default;
	GE_DLLEXPIMPORT AcGeOffsetCurve2d& operator=(const AcGeOffsetCurve2d&);

	GE_DLLEXPIMPORT const AcGeCurve2d* curve() const;
	GE_DLLEXPIMPORT double offsetDistance() const;
	GE_DLLEXPIMPORT bool paramDirection() const;
	GE_DLLEXPIMPORT AcGeOffsetCurve2d& setCurve(const AcGeCurve2d& baseCurve);
	GE_DLLEXPIMPORT AcGeOffsetCurve2d& setOffsetDistance(double distance);
	GE_DLLEXPIMPORT AcGeMatrix2d transformation() const;
};

#include "icarx/IcArxPackPop.h"
