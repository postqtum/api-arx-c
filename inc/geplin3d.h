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
***     Description: Declaration of AcGePolyline3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gesent3d.h"

#include "icarx/IcArxPackPush.h"

class AcGePolyline3d : public AcGeSplineEnt3d
{
public:
	GE_DLLEXPIMPORT AcGePolyline3d();
	GE_DLLEXPIMPORT AcGePolyline3d(const AcGePoint3dArray& points);
	GE_DLLEXPIMPORT AcGePolyline3d(const AcGeKnotVector& knots, const AcGePoint3dArray& cntrlPnts);
	GE_DLLEXPIMPORT AcGePolyline3d(const AcGeCurve3d& crv, double apprEps);
	GE_DLLEXPIMPORT AcGePolyline3d(const AcGePolyline3d&);
	~AcGePolyline3d() = default;
	GE_DLLEXPIMPORT AcGePolyline3d& operator=(const AcGePolyline3d&);

	GE_DLLEXPIMPORT AcGePoint3d fitPointAt(int idx) const;
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT AcGeSplineEnt3d& setFitPointAt(int idx, const AcGePoint3d& point);

protected:
	explicit AcGePolyline3d(std::nullptr_t);
};

#include "icarx/IcArxPackPop.h"
