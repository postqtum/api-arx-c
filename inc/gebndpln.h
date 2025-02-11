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
***     Description: Declaration of AcGeBoundedPlane class
***
*****************************************************************************/
#pragma once

#include "geplanar.h"
#include "geplane.h"

class AcGePlane;
class AcGeVector3d;
class AcGePoint3d;
class AcGePoint2d;
class AcGeLineSeg3d;

#include "icarx/IcArxPackPush.h"

class AcGeBoundedPlane : public AcGePlanarEnt
{
public:
	GE_DLLEXPIMPORT AcGeBoundedPlane();
	GE_DLLEXPIMPORT AcGeBoundedPlane(const AcGePoint3d& origin, const AcGeVector3d& uVec,
									 const AcGeVector3d& vVec);
	GE_DLLEXPIMPORT AcGeBoundedPlane(const AcGePoint3d& p1, const AcGePoint3d& origin,
									 const AcGePoint3d& p2);
	GE_DLLEXPIMPORT AcGeBoundedPlane(const AcGeBoundedPlane&);
	~AcGeBoundedPlane() = default;
	GE_DLLEXPIMPORT AcGeBoundedPlane& operator=(const AcGeBoundedPlane&);

	GE_DLLEXPIMPORT bool intersectWith(const AcGeLinearEnt3d& linEnt, AcGePoint3d& point,
												 const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGePlane& plane, AcGeLineSeg3d& results,
												 const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool intersectWith(const AcGeBoundedPlane& plane,
												 AcGeLineSeg3d& result,
												 const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeBoundedPlane& set(const AcGePoint3d& origin, const AcGeVector3d& uVec,
										  const AcGeVector3d& vVec);
	GE_DLLEXPIMPORT AcGeBoundedPlane& set(const AcGePoint3d& p1, const AcGePoint3d& origin,
										  const AcGePoint3d& p2);
};

#include "icarx/IcArxPackPop.h"
