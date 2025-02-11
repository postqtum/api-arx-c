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
***     Description: Declaration of AcGeSurface class
***
*****************************************************************************/
#pragma once

#include "geent3d.h"
#include "gevc3dar.h"

class AcGePoint2d;
class AcGeCurve3d;
class AcGePointOnCurve3d;
class AcGePointOnSurface;
class AcGePointOnSurfaceData;
class AcGeInterval;

#include "icarx/IcArxPackPush.h"

class AcGeSurface : public AcGeEntity3d
{
protected:
	GE_DLLEXPIMPORT AcGeSurface();
	GE_DLLEXPIMPORT AcGeSurface(const AcGeSurface&);

public:
	~AcGeSurface() = default;
	GE_DLLEXPIMPORT AcGeSurface& operator=(const AcGeSurface&);

	GE_DLLEXPIMPORT AcGePoint3d closestPointTo(const AcGePoint3d& pnt,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGePoint3d& pnt,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d evalPoint(const AcGePoint2d& param) const;
	GE_DLLEXPIMPORT AcGePoint3d evalPoint(const AcGePoint2d& param, int derivOrd,
										  AcGeVector3dArray& derivatives) const;
	GE_DLLEXPIMPORT AcGePoint3d evalPoint(const AcGePoint2d& param, int derivOrd,
										  AcGeVector3dArray& derivatives,
										  AcGeVector3d& normal) const;
	GE_DLLEXPIMPORT void getClosestPointTo(const AcGePoint3d& pnt, AcGePointOnSurface& result,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getEnvelope(AcGeInterval& intrvlX, AcGeInterval& intrvlY) const;
	GE_DLLEXPIMPORT bool isClosedInU(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isClosedInV(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isNormalReversed() const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, AcGePoint2d& paramPoint,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint2d paramOf(const AcGePoint3d& pnt,
										const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeSurface& reverseNormal();
};

#include "icarx/IcArxPackPop.h"
