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
***     Description: Declaration of AcGeEntity2d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geintrvl.h"
#include "geponc3d.h"
#include "geplane.h"

class AcGeEllipArc2d;
class AcGeCircArc3d;
class AcGeLineEnt3d;
class AcGePlanarEnt;

#include "icarx/IcArxPackPush.h"

class AcGeEllipArc3d : public AcGeCurve3d
{
public:
	GE_DLLEXPIMPORT AcGeEllipArc3d();
	GE_DLLEXPIMPORT AcGeEllipArc3d(const AcGeCircArc3d& arc);
	GE_DLLEXPIMPORT AcGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis,
								   const AcGeVector3d& minorAxis, double majorRadius,
								   double minorRadius);
	GE_DLLEXPIMPORT AcGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis,
								   const AcGeVector3d& minorAxis, double majorRadius,
								   double minorRadius, double ang1, double ang2);
	GE_DLLEXPIMPORT AcGeEllipArc3d(const AcGeEllipArc3d&);
	~AcGeEllipArc3d() = default;
	GE_DLLEXPIMPORT AcGeEllipArc3d& operator=(const AcGeEllipArc3d&);

	GE_DLLEXPIMPORT AcGePoint3d center() const;
	GE_DLLEXPIMPORT AcGePoint3d closestPointToPlane(const AcGePlanarEnt& plane,
													AcGePoint3d& pointOnPlane,
													const AcGeTol& = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double endAng() const;
	GE_DLLEXPIMPORT AcGePoint3d endPoint() const;
	GE_DLLEXPIMPORT void getPlane(AcGePlane& plane) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& line, int& intn, AcGePoint3d& p1,
									   AcGePoint3d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGePlanarEnt& plane, int& numOfIntersect,
									   AcGePoint3d& p1, AcGePoint3d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isCircular(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isInside(const AcGePoint3d& pnt,
								  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeVector3d majorAxis() const;
	GE_DLLEXPIMPORT double majorRadius() const;
	GE_DLLEXPIMPORT AcGeVector3d minorAxis() const;
	GE_DLLEXPIMPORT double minorRadius() const;
	GE_DLLEXPIMPORT AcGeVector3d normal() const;
	GE_DLLEXPIMPORT bool projIntersectWith(
			const AcGeLinearEnt3d& line, const AcGeVector3d& projDir, int& numInt,
			AcGePoint3d& pntOnEllipse1, AcGePoint3d& pntOnEllipse2, AcGePoint3d& pntOnLine1,
			AcGePoint3d& pntOnLine2, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeEllipArc3d& set(const AcGePoint3d& cent, const AcGeVector3d& majorAxis,
										const AcGeVector3d& minorAxis, double majorRadius,
										double minorRadius);
	GE_DLLEXPIMPORT AcGeEllipArc3d& set(const AcGePoint3d& cent, const AcGeVector3d& majorAxis,
										const AcGeVector3d& minorAxis, double majorRadius,
										double minorRadius, double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeEllipArc3d& set(const AcGeCircArc3d&);
	GE_DLLEXPIMPORT AcGeEllipArc3d& setAngles(double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeEllipArc3d& setAxes(const AcGeVector3d& majorAxis,
											const AcGeVector3d& minorAxis);
	GE_DLLEXPIMPORT AcGeEllipArc3d& setCenter(const AcGePoint3d& cent);
	GE_DLLEXPIMPORT AcGeEllipArc3d& setMajorRadius(double rad);
	GE_DLLEXPIMPORT AcGeEllipArc3d& setMinorRadius(double rad);
	GE_DLLEXPIMPORT double startAng() const;
	GE_DLLEXPIMPORT AcGePoint3d startPoint() const;
};

#include "icarx/IcArxPackPop.h"
