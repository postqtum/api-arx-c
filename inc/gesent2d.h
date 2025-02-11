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
***     Description: Declaration of AcGeSplineEnt2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gept2dar.h"

class AcGeKnotVector;

#include "icarx/IcArxPackPush.h"

class AcGeSplineEnt2d : public AcGeCurve2d
{
protected:
	GE_DLLEXPIMPORT AcGeSplineEnt2d();
	GE_DLLEXPIMPORT AcGeSplineEnt2d(const AcGeSplineEnt2d&);

public:
	~AcGeSplineEnt2d() = default;
	GE_DLLEXPIMPORT AcGeSplineEnt2d& operator=(const AcGeSplineEnt2d&);

	GE_DLLEXPIMPORT int continuityAtKnot(int idx, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint2d controlPointAt(int idx) const;
	GE_DLLEXPIMPORT int degree() const;
	GE_DLLEXPIMPORT double endParam() const;
	GE_DLLEXPIMPORT AcGePoint2d endPoint() const;
	GE_DLLEXPIMPORT bool hasFitData() const;
	GE_DLLEXPIMPORT bool isRational() const;
	GE_DLLEXPIMPORT double knotAt(int idx) const;
	GE_DLLEXPIMPORT const AcGeKnotVector& knots() const;
	GE_DLLEXPIMPORT int numControlPoints() const;
	GE_DLLEXPIMPORT int numKnots() const;
	GE_DLLEXPIMPORT int order() const;
	GE_DLLEXPIMPORT AcGeSplineEnt2d& setControlPointAt(int idx, const AcGePoint2d& pnt);
	GE_DLLEXPIMPORT AcGeSplineEnt2d& setKnotAt(int idx, double val);
	GE_DLLEXPIMPORT double startParam() const;
	GE_DLLEXPIMPORT AcGePoint2d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
