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
***     Description: Declaration of AcGePlane class
***
*****************************************************************************/
#pragma once

#include "geplanar.h"

class AcGeBoundedPlane;
class AcGeLine3d;

#include "icarx/IcArxPackPush.h"

class AcGePlane : public AcGePlanarEnt
{
public:
	GE_DLLDATAEXIMP static const AcGePlane kXYPlane;
	GE_DLLDATAEXIMP static const AcGePlane kYZPlane;
	GE_DLLDATAEXIMP static const AcGePlane kZXPlane;

public:
	GE_DLLEXPIMPORT AcGePlane();
	GE_DLLEXPIMPORT AcGePlane(const AcGePoint3d& origin, const AcGeVector3d& normal);
	GE_DLLEXPIMPORT AcGePlane(const AcGePoint3d& pntU, const AcGePoint3d& org,
							  const AcGePoint3d& pntV);
	GE_DLLEXPIMPORT AcGePlane(const AcGePoint3d& org, const AcGeVector3d& uAxis,
							  const AcGeVector3d& vAxis);
	GE_DLLEXPIMPORT AcGePlane(double a, double b, double c, double d);
	GE_DLLEXPIMPORT AcGePlane(const AcGePlane&);
	~AcGePlane() = default;
	GE_DLLEXPIMPORT AcGePlane& operator=(const AcGePlane&);

	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& linEnt, AcGePoint3d& resultPnt,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGePlane& otherPln, AcGeLine3d& resultLine,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeBoundedPlane& bndPln, AcGeLineSeg3d& resultLineSeg,
									   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePlane& set(const AcGePoint3d& pnt, const AcGeVector3d& normal);
	GE_DLLEXPIMPORT AcGePlane& set(const AcGePoint3d& pntU, const AcGePoint3d& org,
								   const AcGePoint3d& pntV);
	GE_DLLEXPIMPORT AcGePlane& set(double a, double b, double c, double d);
	GE_DLLEXPIMPORT AcGePlane& set(const AcGePoint3d& org, const AcGeVector3d& uAxis,
								   const AcGeVector3d& vAxis);
	GE_DLLEXPIMPORT double signedDistanceTo(const AcGePoint3d& pnt) const;
};

#include "icarx/IcArxPackPop.h"
