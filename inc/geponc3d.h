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
***     Description: Declaration of AcGePointOnCurve3d class
***
*****************************************************************************/
#pragma once

#include "gepent3d.h"

class AcGeCurve3d;

#include "icarx/IcArxPackPush.h"

class AcGePointOnCurve3d : public AcGePointEnt3d
{
public:
	GE_DLLEXPIMPORT AcGePointOnCurve3d();
	GE_DLLEXPIMPORT AcGePointOnCurve3d(const AcGeCurve3d& crv);
	GE_DLLEXPIMPORT AcGePointOnCurve3d(const AcGeCurve3d& crv, double param);
	GE_DLLEXPIMPORT AcGePointOnCurve3d(const AcGePointOnCurve3d&);
	~AcGePointOnCurve3d() = default;
	GE_DLLEXPIMPORT AcGePointOnCurve3d& operator=(const AcGePointOnCurve3d&);

	GE_DLLEXPIMPORT bool curvature(double& res);
	GE_DLLEXPIMPORT bool curvature(double param, double& res);
	GE_DLLEXPIMPORT const AcGeCurve3d* curve() const;
	GE_DLLEXPIMPORT AcGeVector3d deriv(int order) const;
	GE_DLLEXPIMPORT AcGeVector3d deriv(int order, double param);
	GE_DLLEXPIMPORT AcGeVector3d deriv(int order, const AcGeCurve3d& crv, double param);
	GE_DLLEXPIMPORT bool isSingular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double parameter() const;
	GE_DLLEXPIMPORT AcGePoint3d point() const;
	GE_DLLEXPIMPORT AcGePoint3d point(double param);
	GE_DLLEXPIMPORT AcGePoint3d point(const AcGeCurve3d& crv, double param);
	GE_DLLEXPIMPORT AcGePointOnCurve3d& setCurve(const AcGeCurve3d& crv);
	GE_DLLEXPIMPORT AcGePointOnCurve3d& setParameter(double param);
};

#include "icarx/IcArxPackPop.h"
