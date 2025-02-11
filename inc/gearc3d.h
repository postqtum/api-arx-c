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
***     Description: Declaration of AcGeCircArc3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geplane.h"
#include "gegblabb.h"

class AcGeLine3d;
class AcGeCircArc2d;
class AcGePlanarEnt;

#include "icarx/IcArxPackPush.h"

class AcGeCircArc3d : public AcGeCurve3d
{
public:
	GE_DLLEXPIMPORT AcGeCircArc3d();
	GE_DLLEXPIMPORT AcGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius);
	GE_DLLEXPIMPORT AcGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm,
								  const AcGeVector3d& refVec, double radius, double startAngle,
								  double endAngle);
	GE_DLLEXPIMPORT AcGeCircArc3d(const AcGePoint3d& startPoint, const AcGePoint3d& pnt,
								  const AcGePoint3d& endPoint);
	GE_DLLEXPIMPORT AcGeCircArc3d(const AcGeCircArc3d&);
	~AcGeCircArc3d() = default;
	GE_DLLEXPIMPORT AcGeCircArc3d& operator=(const AcGeCircArc3d&);

	GE_DLLEXPIMPORT AcGePoint3d center() const;
	GE_DLLEXPIMPORT AcGePoint3d closestPointToPlane(const AcGePlanarEnt& plane,
													AcGePoint3d& pointOnPlane,
													const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double endAng() const;
	GE_DLLEXPIMPORT AcGePoint3d endPoint() const;
	GE_DLLEXPIMPORT void getPlane(AcGePlane& plane) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& line, int& intn, AcGePoint3d& p1,
									   AcGePoint3d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeCircArc3d& arc, int& intn, AcGePoint3d& p1,
									   AcGePoint3d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGePlanarEnt& plane, int& numOfIntersect,
									   AcGePoint3d& p1, AcGePoint3d& p2,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isInside(const AcGePoint3d& pnt,
								  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeVector3d normal() const;
	GE_DLLEXPIMPORT bool projIntersectWith(const AcGeLinearEnt3d& line, const AcGeVector3d& projDir,
										   int& numInt, AcGePoint3d& pntOnArc1,
										   AcGePoint3d& pntOnArc2, AcGePoint3d& pntOnLine1,
										   AcGePoint3d& pntOnLine2,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double radius() const;
	GE_DLLEXPIMPORT AcGeVector3d refVec() const;
	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGePoint3d& cent, const AcGeVector3d& nrm,
									   double radius);
	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGePoint3d& cent, const AcGeVector3d& nrm,
									   const AcGeVector3d& refVec, double radius, double startAngle,
									   double endAngle);
	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGePoint3d& startPoint, const AcGePoint3d& pnt,
									   const AcGePoint3d& endPoint);
	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGePoint3d& startPoint, const AcGePoint3d& pnt,
									   const AcGePoint3d& endPoint, AcGeError& error);

	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGeCurve3d& curve1, const AcGeCurve3d& curve2,
									   double radius, double& param1, double& param2,
									   bool& success);
	GE_DLLEXPIMPORT AcGeCircArc3d& set(const AcGeCurve3d& curve1, const AcGeCurve3d& curve2,
									   const AcGeCurve3d& curve3, double& param1, double& param2,
									   double& param3, bool& success);
	GE_DLLEXPIMPORT AcGeCircArc3d& setAngles(double startAngle, double endAngle);
	GE_DLLEXPIMPORT AcGeCircArc3d& setAxes(const AcGeVector3d& normal, const AcGeVector3d& refVec);
	GE_DLLEXPIMPORT AcGeCircArc3d& setCenter(const AcGePoint3d&);
	GE_DLLEXPIMPORT AcGeCircArc3d& setRadius(double);
	GE_DLLEXPIMPORT double startAng() const;
	GE_DLLEXPIMPORT AcGePoint3d startPoint() const;
	GE_DLLEXPIMPORT bool tangent(const AcGePoint3d& pnt, AcGeLine3d& line,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool tangent(const AcGePoint3d& pnt, AcGeLine3d& line,
										   const AcGeTol& tol, AcGeError& error) const;
};

#include "icarx/IcArxPackPop.h"
