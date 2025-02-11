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
***     Description: Declaration of AcGeCubicSplineCurve3d class
***
*****************************************************************************/
#pragma once

#include "gesent3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gevec3d.h"
#include "gekvec.h"

class AcGePointOnCurve3d;
class AcGeCurve3dIntersection;
class AcGeInterval;
class AcGePlane;

#include "icarx/IcArxPackPush.h"

class AcGeCubicSplineCurve3d : public AcGeSplineEnt3d
{
public:
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d();
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d(const AcGePoint3dArray& fitPnts,
										   const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d(const AcGePoint3dArray& fitPnts,
										   const AcGeVector3d& startDeriv,
										   const AcGeVector3d& endDeriv,
										   const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d(const AcGeCurve3d& curve,
										   double epsilon = AcGeContext::gTol.equalPoint());
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d(const AcGeKnotVector& knots,
										   const AcGePoint3dArray& fitPnts,
										   const AcGeVector3dArray& firstDerivs,
										   bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d(const AcGeCubicSplineCurve3d&);
	~AcGeCubicSplineCurve3d() = default;
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d& operator=(const AcGeCubicSplineCurve3d&);

	GE_DLLEXPIMPORT AcGeVector3d firstDerivAt(int idx) const;
	GE_DLLEXPIMPORT AcGePoint3d fitPointAt(int idx) const;
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d& setFirstDerivAt(int idx, const AcGeVector3d& deriv);
	GE_DLLEXPIMPORT AcGeCubicSplineCurve3d& setFitPointAt(int idx, const AcGePoint3d& point);
};

#include "icarx/IcArxPackPop.h"
