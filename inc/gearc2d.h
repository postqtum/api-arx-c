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
***     Description: Declaration of AcGeCircArc2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gepnt2d.h"
#include "gevec2d.h"

class AcGeLine2d;
class AcGeLinearEnt2d;

#include "icarx/IcArxPackPush.h"

class AcGeCircArc2d : public AcGeCurve2d
{
public:
	GE_DLLEXPIMPORT AcGeCircArc2d();
	GE_DLLEXPIMPORT AcGeCircArc2d(const AcGePoint2d& cent, double radius);
	GE_DLLEXPIMPORT AcGeCircArc2d(const AcGePoint2d& cent, double radius, double startAngle,
								  double endAngle,
								  const AcGeVector2d& refVec = AcGeVector2d::kXAxis,
								  bool isClockWise = false);
	GE_DLLEXPIMPORT AcGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& point,
								  const AcGePoint2d& endPoint);
	GE_DLLEXPIMPORT AcGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint,
								  double bulge, bool bulgeFlag = true);
	GE_DLLEXPIMPORT AcGeCircArc2d(const AcGeCircArc2d&);
	~AcGeCircArc2d() = default;
	GE_DLLEXPIMPORT AcGeCircArc2d& operator=(const AcGeCircArc2d&);

	GE_DLLEXPIMPORT AcGePoint2d center() const;
	GE_DLLEXPIMPORT double endAng() const;
	GE_DLLEXPIMPORT AcGePoint2d endPoint() const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt2d& line, int& intn, AcGePoint2d& p1,
									   AcGePoint2d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeCircArc2d& arc, int& intn, AcGePoint2d& p1,
									   AcGePoint2d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isClockWise() const;
	GE_DLLEXPIMPORT bool isInside(const AcGePoint2d& pnt,
								  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double radius() const;
	GE_DLLEXPIMPORT AcGeVector2d refVec() const;
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGePoint2d& cent, double radius);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGePoint2d& cent, double radius, double ang1,
									   double ang2,
									   const AcGeVector2d& refVec = AcGeVector2d::kXAxis,
									   bool isClockWise = false);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGePoint2d& startPoint, const AcGePoint2d& pnt,
									   const AcGePoint2d& endPoint);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGePoint2d& startPoint, const AcGePoint2d& pnt,
									   const AcGePoint2d& endPoint, AcGeError& error);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint,
									   double bulge, bool bulgeFlag = true);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
									   double radius, double& param1, double& param2,
									   bool& success);
	GE_DLLEXPIMPORT AcGeCircArc2d& set(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2,
									   const AcGeCurve2d& curve3, double& param1, double& param2,
									   double& param3, bool& success);
	GE_DLLEXPIMPORT AcGeCircArc2d& setAngles(double startAng, double endAng);
	GE_DLLEXPIMPORT AcGeCircArc2d& setCenter(const AcGePoint2d& cent);
	GE_DLLEXPIMPORT AcGeCircArc2d& setRadius(double radius);
	GE_DLLEXPIMPORT AcGeCircArc2d& setRefVec(const AcGeVector2d& vec);
	GE_DLLEXPIMPORT AcGeCircArc2d& setToComplement();
	GE_DLLEXPIMPORT double startAng() const;
	GE_DLLEXPIMPORT AcGePoint2d startPoint() const;
	GE_DLLEXPIMPORT bool tangent(const AcGePoint2d& pnt, AcGeLine2d& line,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool tangent(const AcGePoint2d& pnt, AcGeLine2d& line,
										   const AcGeTol& tol, AcGeError& error) const;
};

#include "icarx/IcArxPackPop.h"
