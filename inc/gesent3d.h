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
***     Description: Declaration of AcGeSplineEnt3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gept3dar.h"

class AcGeKnotVector;

#include "icarx/IcArxPackPush.h"

class AcGeSplineEnt3d : public AcGeCurve3d
{
protected:
	GE_DLLEXPIMPORT AcGeSplineEnt3d();
	GE_DLLEXPIMPORT AcGeSplineEnt3d(const AcGeSplineEnt3d&);

public:
	~AcGeSplineEnt3d() = default;
	GE_DLLEXPIMPORT AcGeSplineEnt3d& operator=(const AcGeSplineEnt3d&);

	GE_DLLEXPIMPORT int continuityAtKnot(int idx, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d controlPointAt(int idx) const;
	GE_DLLEXPIMPORT int degree() const;
	GE_DLLEXPIMPORT double endParam() const;
	GE_DLLEXPIMPORT AcGePoint3d endPoint() const;
	GE_DLLEXPIMPORT bool hasFitData() const;
	GE_DLLEXPIMPORT bool isRational() const;
	GE_DLLEXPIMPORT double knotAt(int idx) const;
	GE_DLLEXPIMPORT const AcGeKnotVector& knots() const;
	GE_DLLEXPIMPORT int numControlPoints() const;
	GE_DLLEXPIMPORT int numKnots() const;
	GE_DLLEXPIMPORT int order() const;
	GE_DLLEXPIMPORT AcGeSplineEnt3d& setControlPointAt(int idx, const AcGePoint3d& pnt);
	GE_DLLEXPIMPORT AcGeSplineEnt3d& setKnotAt(int idx, double val);
	GE_DLLEXPIMPORT double startParam() const;
	GE_DLLEXPIMPORT AcGePoint3d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
