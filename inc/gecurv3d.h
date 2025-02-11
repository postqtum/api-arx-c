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
***     Description: Declaration of AcGeCurve3d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"

class AcGeCurve2d;
class AcGeSurface;
class AcGePoint3d;
class AcGePlane;
class AcGeVector3d;
class AcGeLinearEnt3d;
class AcGeLine3d;
class AcGePointOnCurve3d;
class AcGePointOnSurface;
class AcGeInterval;
class AcGeMatrix3d;
class AcGePointOnCurve3dData;
class AcGeBoundBlock3d;

#include "icarx/IcArxPackPush.h"

class AcGeCurve3d : public AcGeEntity3d
{
protected:
	GE_DLLEXPIMPORT AcGeCurve3d();
	GE_DLLEXPIMPORT AcGeCurve3d(const AcGeCurve3d&);

public:
	~AcGeCurve3d() = default;
	GE_DLLEXPIMPORT AcGeCurve3d& operator=(const AcGeCurve3d&);

	GE_DLLEXPIMPORT bool area(double startParam, double endParam, double& value,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d boundBlock() const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d boundBlock(const AcGeInterval& range) const;
	GE_DLLEXPIMPORT AcGePoint3d closestPointTo(const AcGePoint3d& pnt,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d closestPointTo(const AcGeCurve3d& curve3d,
											   AcGePoint3d& pntOnOtherCrv,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGePoint3d& pnt,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGeCurve3d& curve,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d evalPoint(double param) const;
	GE_DLLEXPIMPORT AcGePoint3d evalPoint(double param, int numDeriv,
										  AcGeVector3dArray& derivArray) const;
	GE_DLLEXPIMPORT bool explode(AcGeVoidPointerArray& explodedCurves,
								 AcGeIntArray& newExplodedCurves,
								 const AcGeInterval* intrvl = nullptr) const;
	GE_DLLEXPIMPORT void getClosestPointTo(const AcGePoint3d& pnt, AcGePointOnCurve3d& pntOnCrv,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getClosestPointTo(const AcGeCurve3d& curve3d,
										   AcGePointOnCurve3d& pntOnThisCrv,
										   AcGePointOnCurve3d& pntOnOtherCrv,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getInterval(AcGeInterval& intrvl) const;
	GE_DLLEXPIMPORT void getInterval(AcGeInterval& intrvl, AcGePoint3d& start,
									 AcGePoint3d& end) const;
	GE_DLLEXPIMPORT void getLocalClosestPoints(const AcGePoint3d& point,
											   AcGePointOnCurve3d& approxPnt,
											   const AcGeInterval* nbhd = 0,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getLocalClosestPoints(const AcGeCurve3d& otherCurve,
											   AcGePointOnCurve3d& approxPntOnThisCrv,
											   AcGePointOnCurve3d& approxPntOnOtherCrv,
											   const AcGeInterval* nbhd1 = 0,
											   const AcGeInterval* nbhd2 = 0,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool getNormalPoint(const AcGePoint3d& pnt, AcGePointOnCurve3d& pntOnCrv,
										const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getProjClosestPointTo(const AcGePoint3d& pnt,
											   const AcGeVector3d& projectDirection,
											   AcGePointOnCurve3d& pntOnCrv,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getProjClosestPointTo(const AcGeCurve3d& curve3d,
											   const AcGeVector3d& projectDirection,
											   AcGePointOnCurve3d& pntOnThisCrv,
											   AcGePointOnCurve3d& pntOnOtherCrv,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getSamplePoints(double fromParam, double toParam, double approxEps,
										 AcGePoint3dArray& pointArray, AcGeDoubleArray& paramArray,
										 bool forceResampling = false) const;
	GE_DLLEXPIMPORT void getSamplePoints(int numSample, AcGePoint3dArray& pointArray) const;
	GE_DLLEXPIMPORT void getSamplePoints(int numSample, AcGePoint3dArray& pointArray,
										 AcGeDoubleArray& paramArray) const;
	GE_DLLEXPIMPORT void getSplitCurves(double param, AcGeCurve3d*& piece1,
										AcGeCurve3d*& piece2) const;
	GE_DLLEXPIMPORT void getTrimmedOffset(double distance, const AcGeVector3d& planeNormal,
										  AcGeVoidPointerArray& offsetCurveList,
										  AcGe::OffsetCrvExtType extensionType = AcGe::kFillet,
										  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool hasEndPoint(AcGePoint3d& endPnt) const;
	GE_DLLEXPIMPORT bool hasStartPoint(AcGePoint3d& startPnt) const;
	GE_DLLEXPIMPORT bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isCoplanarWith(const AcGeCurve3d& curve3d, AcGePlane& plane,
										const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isDegenerate(AcGe::EntityId& degenerateType,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isDegenerate(AcGeEntity3d*& pConvertedEntity,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isLinear(AcGeLine3d& line, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint3d& pnt, double& param,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(double param, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPeriodic(double& period) const;
	GE_DLLEXPIMPORT bool isPlanar(AcGePlane& plane, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double length(double fromParam, double toParam,
								  double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d orthoBoundBlock() const;
	GE_DLLEXPIMPORT AcGeBoundBlock3d orthoBoundBlock(const AcGeInterval& range) const;
	GE_DLLEXPIMPORT AcGeEntity3d* orthoProject(const AcGePlane& projectionPlane,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double paramAtLength(double datumParam, double length, bool posParamDir = true,
										 double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT double paramOf(const AcGePoint3d& pnt,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d projClosestPointTo(const AcGePoint3d& pnt,
												   const AcGeVector3d& projectDirection,
												   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint3d projClosestPointTo(const AcGeCurve3d& curve3d,
												   const AcGeVector3d& projectDirection,
												   AcGePoint3d& pntOnOtherCrv,
												   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeEntity3d* project(const AcGePlane& projectionPlane,
										  const AcGeVector3d& projectDirection,
										  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeCurve3d& reverseParam();
	GE_DLLEXPIMPORT AcGeCurve3d& setInterval();
	GE_DLLEXPIMPORT bool setInterval(const AcGeInterval& intrvl);
};

#include "icarx/IcArxPackPop.h"
