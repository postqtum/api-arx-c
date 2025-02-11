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
***     Description: Declaration of AcGeCubicSplineCurve2d class
***
*****************************************************************************/
#pragma once

#include "gesent2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gevec2d.h"
#include "gekvec.h"

class AcGePointOnCurve2d;
class AcGeCurve2dIntersection;
class AcGeInterval;
class AcGePlane;

#include "icarx/IcArxPackPush.h"

class AcGeCubicSplineCurve2d : public AcGeSplineEnt2d
{
public:
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d();
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d(const AcGePoint2dArray& fitPnts,
										   const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d(const AcGePoint2dArray& fitPnts,
										   const AcGeVector2d& startDeriv,
										   const AcGeVector2d& endDeriv,
										   const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d(const AcGeCurve2d& curve,
										   double epsilon = AcGeContext::gTol.equalPoint());
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d(const AcGeKnotVector& knots,
										   const AcGePoint2dArray& fitPnts,
										   const AcGeVector2dArray& firstDerivs,
										   bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d(const AcGeCubicSplineCurve2d&);
	~AcGeCubicSplineCurve2d() = default;
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d& operator=(const AcGeCubicSplineCurve2d&);

	GE_DLLEXPIMPORT AcGeVector2d firstDerivAt(int idx) const;
	GE_DLLEXPIMPORT AcGePoint2d fitPointAt(int idx) const;
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d& setFirstDerivAt(int idx, const AcGeVector2d& deriv);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve2d& setFitPointAt(int idx, const AcGePoint2d& point);
};

#include "icarx/IcArxPackPop.h"
