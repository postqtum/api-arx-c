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
***     Description: Declaration of AcGeCurve2d class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "geent2d.h"
#include "geponc2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"

class AcGePoint2d;
class AcGeVector2d;
class AcGePointOnCurve2d;
class AcGeInterval;
class AcGeMatrix2d;
class AcGeLine2d;
class AcGePointOnCurve2dData;
class AcGeBoundBlock2d;

#include "icarx/IcArxPackPush.h"

class AcGeCurve2d : public AcGeEntity2d
{
protected:
	GE_DLLEXPIMPORT AcGeCurve2d();
	GE_DLLEXPIMPORT AcGeCurve2d(const AcGeCurve2d&);

public:
	~AcGeCurve2d() = default;
	GE_DLLEXPIMPORT AcGeCurve2d& operator=(const AcGeCurve2d&);

	GE_DLLEXPIMPORT bool area(double startParam, double endParam, double& value,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d boundBlock() const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d boundBlock(const AcGeInterval& range) const;
	GE_DLLEXPIMPORT AcGePoint2d closestPointTo(const AcGePoint2d& pnt,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint2d closestPointTo(const AcGeCurve2d& curve2d,
											   AcGePoint2d& pntOnOtherCrv,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGePoint2d& pnt,
									  const AcGeTol& = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT double distanceTo(const AcGeCurve2d&,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGePoint2d evalPoint(double param) const;
	GE_DLLEXPIMPORT AcGePoint2d evalPoint(double param, int numDeriv,
										  AcGeVector2dArray& derivArray) const;
	GE_DLLEXPIMPORT bool explode(AcGeVoidPointerArray& explodedCurves,
								 AcGeIntArray& newExplodedCurve,
								 const AcGeInterval* intrvl = nullptr) const;
	GE_DLLEXPIMPORT void getClosestPointTo(const AcGePoint2d& pnt, AcGePointOnCurve2d& pntOnCrv,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getClosestPointTo(const AcGeCurve2d& curve2d,
										   AcGePointOnCurve2d& pntOnThisCrv,
										   AcGePointOnCurve2d& pntOnOtherCrv,
										   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getInterval(AcGeInterval& intrvl) const;
	GE_DLLEXPIMPORT void getInterval(AcGeInterval& intrvl, AcGePoint2d& start,
									 AcGePoint2d& end) const;
	GE_DLLEXPIMPORT void getLocalClosestPoints(const AcGePoint2d& point,
											   AcGePointOnCurve2d& approxPnt,
											   const AcGeInterval* nbhd = 0,
											   const AcGeTol& = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getLocalClosestPoints(const AcGeCurve2d& otherCurve,
											   AcGePointOnCurve2d& approxPntOnThisCrv,
											   AcGePointOnCurve2d& approxPntOnOtherCrv,
											   const AcGeInterval* nbhd1 = 0,
											   const AcGeInterval* nbhd2 = 0,
											   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool getNormalPoint(const AcGePoint2d& pnt, AcGePointOnCurve2d& pntOnCrv,
										const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT void getSamplePoints(double fromParam, double toParam, double approxEps,
										 AcGePoint2dArray& pointArray,
										 AcGeDoubleArray& paramArray) const;
	GE_DLLEXPIMPORT void getSamplePoints(int numSample, AcGePoint2dArray&) const;
	GE_DLLEXPIMPORT void getSplitCurves(double param, AcGeCurve2d*& piece1,
										AcGeCurve2d*& piece2) const;
	GE_DLLEXPIMPORT void getTrimmedOffset(double distance, AcGeVoidPointerArray& offsetCurveList,
										  AcGe::OffsetCrvExtType extensionType = AcGe::kFillet,
										  const AcGeTol& = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool hasEndPoint(AcGePoint2d& endPoint) const;
	GE_DLLEXPIMPORT bool hasStartPoint(AcGePoint2d& startPoint) const;
	GE_DLLEXPIMPORT bool isClosed(const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isDegenerate(AcGe::EntityId& degenerateType,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isDegenerate(AcGeEntity2d*& pConvertedEntity,
									  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isLinear(AcGeLine2d& line, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint2d& pnt, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(const AcGePoint2d& pnt, double& param,
							  const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isOn(double param, const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool isPeriodic(double& period) const;
	GE_DLLEXPIMPORT double length(double fromParam, double toParam,
								  double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d orthoBoundBlock() const;
	GE_DLLEXPIMPORT AcGeBoundBlock2d orthoBoundBlock(const AcGeInterval& range) const;
	GE_DLLEXPIMPORT double paramAtLength(double datumParam, double length, bool posParamDir = true,
										 double tol = AcGeContext::gTol.equalPoint()) const;
	GE_DLLEXPIMPORT double paramOf(const AcGePoint2d& pnt,
								   const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool setInterval(const AcGeInterval& intrvl);
	GE_DLLEXPIMPORT AcGeCurve2d& reverseParam();
	GE_DLLEXPIMPORT AcGeCurve2d& setInterval();
};

#include "icarx/IcArxPackPop.h"
