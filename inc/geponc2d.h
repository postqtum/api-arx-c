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
***     Description: Declaration of AcGePointOnCurve2d class
***
*****************************************************************************/
#pragma once

#include "gepent2d.h"

class AcGeCurve2d;

#include "icarx/IcArxPackPush.h"

class AcGePointOnCurve2d : public AcGePointEnt2d
{
public:
	GE_DLLEXPIMPORT AcGePointOnCurve2d();
	GE_DLLEXPIMPORT AcGePointOnCurve2d(const AcGeCurve2d& crv);
	GE_DLLEXPIMPORT AcGePointOnCurve2d(const AcGeCurve2d& crv, double param);
	GE_DLLEXPIMPORT AcGePointOnCurve2d(const AcGePointOnCurve2d&);
	~AcGePointOnCurve2d() = default;
	GE_DLLEXPIMPORT AcGePointOnCurve2d& operator=(const AcGePointOnCurve2d&);

	GE_DLLEXPIMPORT bool curvature(double& res);
	GE_DLLEXPIMPORT bool curvature(double param, double& res);
	GE_DLLEXPIMPORT const AcGeCurve2d* curve() const;
	GE_DLLEXPIMPORT AcGeVector2d deriv(int order) const;
	GE_DLLEXPIMPORT AcGeVector2d deriv(int order, double param);
	GE_DLLEXPIMPORT AcGeVector2d deriv(int order, const AcGeCurve2d& crv, double param);
	GE_DLLEXPIMPORT bool isSingular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double parameter() const;
	GE_DLLEXPIMPORT AcGePoint2d point() const;
	GE_DLLEXPIMPORT AcGePoint2d point(double param);
	GE_DLLEXPIMPORT AcGePoint2d point(const AcGeCurve2d& crv, double param);
	GE_DLLEXPIMPORT AcGePointOnCurve2d& setCurve(const AcGeCurve2d& crv);
	GE_DLLEXPIMPORT AcGePointOnCurve2d& setParameter(double param);
};

#include "icarx/IcArxPackPop.h"
