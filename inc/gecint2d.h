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
***     Description: Declaration of AcGeCurveCurveInt2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "gegbl.h"
#include "geent2d.h"
#include "geponc2d.h"
#include "geintrvl.h"

class AcGeCurve2d;

#include "icarx/IcArxPackPush.h"

class AcGeCurveCurveInt2d : public AcGeEntity2d
{
public:
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d();
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
										const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
										const AcGeInterval& range1, const AcGeInterval& range2,
										const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d(const AcGeCurveCurveInt2d&);
	~AcGeCurveCurveInt2d() = default;
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d& operator=(const AcGeCurveCurveInt2d&);

	GE_DLLEXPIMPORT void changeCurveOrder();
	GE_DLLEXPIMPORT const AcGeCurve2d* curve1() const;
	GE_DLLEXPIMPORT const AcGeCurve2d* curve2() const;
	GE_DLLEXPIMPORT void getIntConfigs(int intNum, AcGe::AcGeXConfig& config1wrt2,
									   AcGe::AcGeXConfig& config2wrt1) const;
	GE_DLLEXPIMPORT void getIntParams(int intNum, double& param1, double& param2) const;
	GE_DLLEXPIMPORT void getIntRanges(AcGeInterval& range1, AcGeInterval& range2) const;
	GE_DLLEXPIMPORT void getOverlapRanges(int overlapNum, AcGeInterval& range1,
										  AcGeInterval& range2) const;
	GE_DLLEXPIMPORT void getPointOnCurve1(int intNum, AcGePointOnCurve2d&) const;
	GE_DLLEXPIMPORT void getPointOnCurve2(int intNum, AcGePointOnCurve2d&) const;
	GE_DLLEXPIMPORT AcGePoint2d intPoint(int intNum) const;
	GE_DLLEXPIMPORT double intPointTol(int intNum) const;
	GE_DLLEXPIMPORT bool isTangential(int intNum) const;
	GE_DLLEXPIMPORT bool isTransversal(int intNum) const;
	GE_DLLEXPIMPORT int numIntPoints() const;
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d& orderWrt1();
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d& orderWrt2();
	GE_DLLEXPIMPORT int overlapCount() const;
	GE_DLLEXPIMPORT bool overlapDirection() const;
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d& set(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
											 const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeCurveCurveInt2d& set(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
											 const AcGeInterval& range1, const AcGeInterval& range2,
											 const AcGeTol& tol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeTol tolerance() const;
};

#include "icarx/IcArxPackPop.h"
