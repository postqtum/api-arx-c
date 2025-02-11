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
***     Description: Declaration of AcGePolyline2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gesent2d.h"

#include "icarx/IcArxPackPush.h"

class AcGePolyline2d : public AcGeSplineEnt2d
{
public:
	GE_DLLEXPIMPORT AcGePolyline2d();
	GE_DLLEXPIMPORT AcGePolyline2d(const AcGePoint2dArray&);
	GE_DLLEXPIMPORT AcGePolyline2d(const AcGeKnotVector& knots, const AcGePoint2dArray& points);
	GE_DLLEXPIMPORT AcGePolyline2d(const AcGeCurve2d& crv, double apprEps);
	GE_DLLEXPIMPORT AcGePolyline2d(const AcGePolyline2d&);
	~AcGePolyline2d() = default;
	GE_DLLEXPIMPORT AcGePolyline2d& operator=(const AcGePolyline2d&);

	GE_DLLEXPIMPORT AcGePoint2d fitPointAt(int idx) const;
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT AcGeSplineEnt2d& setFitPointAt(int idx, const AcGePoint2d& point);
};

#include "icarx/IcArxPackPop.h"
