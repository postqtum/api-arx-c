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
***     Description: Declaration of AcGeEllipArc2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "geponc2d.h"
#include "geintrvl.h"

class AcGeCircArc2d;
class AcGePlanarEnt;
class AcGeEllipArc2d;
class AcGeLinearEnt2d;

#include "icarx/IcArxPackPush.h"

class AcGeEllipArc2d : public AcGeCurve2d
{
public:
	GE_DLLEXPIMPORT AcGeEllipArc2d();
	GE_DLLEXPIMPORT AcGeEllipArc2d(const AcGeCircArc2d& arc);
	GE_DLLEXPIMPORT AcGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis,
								   const AcGeVector2d& minorAxis, double majorRadius,
								   double minorRadius);
	GE_DLLEXPIMPORT AcGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis,
								   const AcGeVector2d& minorAxis, double majorRadius,
								   double minorRadius, double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeEllipArc2d(const AcGeEllipArc2d&);
	~AcGeEllipArc2d() = default;
	GE_DLLEXPIMPORT AcGeEllipArc2d& operator=(const AcGeEllipArc2d&);

	GE_DLLEXPIMPORT AcGePoint2d center() const;
	GE_DLLEXPIMPORT double endAng() const;
	GE_DLLEXPIMPORT AcGePoint2d endPoint() const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt2d& line, int& intn, AcGePoint2d& p1,
									   AcGePoint2d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isCircular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isClockWise() const;
	GE_DLLEXPIMPORT bool isInside(const AcGePoint2d& pnt,
								  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeVector2d majorAxis() const;
	GE_DLLEXPIMPORT double majorRadius() const;
	GE_DLLEXPIMPORT AcGeVector2d minorAxis() const;
	GE_DLLEXPIMPORT double minorRadius() const;
	GE_DLLEXPIMPORT AcGeEllipArc2d& set(const AcGePoint2d& cent, const AcGeVector2d& majorAxis,
										const AcGeVector2d& minorAxis, double majorRadius,
										double minorRadius);
	GE_DLLEXPIMPORT AcGeEllipArc2d& set(const AcGePoint2d& cent, const AcGeVector2d& majorAxis,
										const AcGeVector2d& minorAxis, double majorRadius,
										double minorRadius, double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeEllipArc2d& set(const AcGeCircArc2d& arc);
	GE_DLLEXPIMPORT AcGeEllipArc2d& setAngles(double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeEllipArc2d& setAxes(const AcGeVector2d& majorAxis,
											const AcGeVector2d& minorAxis);
	GE_DLLEXPIMPORT AcGeEllipArc2d& setCenter(const AcGePoint2d& cent);
	GE_DLLEXPIMPORT AcGeEllipArc2d& setMajorRadius(double rad);
	GE_DLLEXPIMPORT AcGeEllipArc2d& setMinorRadius(double rad);
	GE_DLLEXPIMPORT double startAng() const;
	GE_DLLEXPIMPORT AcGePoint2d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
