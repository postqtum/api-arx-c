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
***     Description: Declaration of AcGeNurbCurve3d class
***
*****************************************************************************/
#pragma once

#include "gecurv3d.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gesent3d.h"
#include "geplin3d.h"
#include "gedblar.h"
#include "gept3dar.h"
#include "gevc3dar.h"

class AcGeEllipArc3d;
class AcGeLineSeg3d;

#include "icarx/IcArxPackPush.h"

class AcGeNurbCurve3d : public AcGeSplineEnt3d
{
public:
	GE_DLLEXPIMPORT AcGeNurbCurve3d();
	GE_DLLEXPIMPORT AcGeNurbCurve3d(int degree, const AcGeKnotVector& knots,
									const AcGePoint3dArray& cntrlPnts,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(int degree, const AcGeKnotVector& knots,
									const AcGePoint3dArray& cntrlPnts,
									const AcGeDoubleArray& weights,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(int degree, const AcGePolyline3d& fitPolyline,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGePoint3dArray& fitPoints,
									const AcGeVector3d& startTangent,
									const AcGeVector3d& endTangent,
									bool startTangentDefined = true,
									bool endTangentDefined = true,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGePoint3dArray& fitPoints,
									const AcGeVector3d& startTangent,
									const AcGeVector3d& endTangent,
									bool startTangentDefined,
									bool endTangentDefined,
									AcGe::KnotParameterization knotParam,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGePoint3dArray& fitPoints,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGePoint3dArray& fitPoints,
									const AcGeVector3dArray& fitTangents,
									const AcGeTol& fitTolerance = AcGeContext::gTol,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGeCurve3d& curve,
									double epsilon = AcGeContext::gTol.equalPoint());
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGeEllipArc3d& ellipse);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGeLineSeg3d& linSeg);
	GE_DLLEXPIMPORT AcGeNurbCurve3d(const AcGeNurbCurve3d&);
	~AcGeNurbCurve3d() = default;
	GE_DLLEXPIMPORT AcGeNurbCurve3d& operator=(const AcGeNurbCurve3d&);

	GE_DLLEXPIMPORT bool addControlPointAt(double newKnot, const AcGePoint3d& point,
										   double weight = 1.0);
	GE_DLLEXPIMPORT bool addFitPointAt(int index, const AcGePoint3d& point);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& addKnot(double newKnot);
	GE_DLLEXPIMPORT bool buildFitData();
	GE_DLLEXPIMPORT bool buildFitData(KnotParameterization kp);
	GE_DLLEXPIMPORT bool deleteControlPointAt(int index);
	GE_DLLEXPIMPORT bool deleteFitPointAt(int index);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& elevateDegree(int plusDegree);
	GE_DLLEXPIMPORT bool evalMode() const;
	GE_DLLEXPIMPORT void getDefinitionData(int& degree, bool& rational, bool& periodic,
										   AcGeKnotVector& knots, AcGePoint3dArray& controlPoints,
										   AcGeDoubleArray& weights) const;
	GE_DLLEXPIMPORT bool getFitData(AcGePoint3dArray& fitPoints, AcGeTol& fitTolerance,
									bool& tangentsExist, AcGeVector3d& startTangent,
									AcGeVector3d& endTangent) const;
	GE_DLLEXPIMPORT bool getFitData(AcGePoint3dArray& fitPoints, AcGeTol& fitTolerance,
									bool& tangentsExist, AcGeVector3d& startTangent,
									AcGeVector3d& endTangent,
									KnotParameterization& knotParam) const;
	GE_DLLEXPIMPORT bool getFitKnotParameterization(KnotParameterization& knotParam) const;
	GE_DLLEXPIMPORT bool getFitPointAt(int index, AcGePoint3d& point) const;
	GE_DLLEXPIMPORT bool getFitTangents(AcGeVector3d& startTangent, AcGeVector3d& endTangent) const;
	GE_DLLEXPIMPORT bool getFitTangents(AcGeVector3d& startTangent, AcGeVector3d& endTangent,
										bool& startTangentDefined, bool& endTangentDefined) const;
	GE_DLLEXPIMPORT bool getFitTolerance(AcGeTol& fitTolerance) const;
	GE_DLLEXPIMPORT bool getParamsOfC1Discontinuity(AcGeDoubleArray& params,
													const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool getParamsOfG1Discontinuity(AcGeDoubleArray& params,
													const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeNurbCurve3d& hardTrimByParams(double newStartParam, double newEndParam);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& insertKnot(double newKnot);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& joinWith(const AcGeNurbCurve3d& curve);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& makeClosed();
	GE_DLLEXPIMPORT AcGeNurbCurve3d& makeNonPeriodic();
	GE_DLLEXPIMPORT AcGeNurbCurve3d& makeOpen();
	GE_DLLEXPIMPORT AcGeNurbCurve3d& makePeriodic();
	GE_DLLEXPIMPORT AcGeNurbCurve3d& makeRational(double weight = 1.0);
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT int numWeights() const;
	GE_DLLEXPIMPORT bool purgeFitData();
	GE_DLLEXPIMPORT AcGeNurbCurve3d& setEvalMode(bool evalMode = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& setFitData(const AcGePoint3dArray& fitPoints,
												const AcGeVector3d& startTangent,
												const AcGeVector3d& endTangent,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& setFitData(const AcGePoint3dArray& fitPoints,
												const AcGeVector3d& startTangent,
												const AcGeVector3d& endTangent,
												KnotParameterization knotParam,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& setFitData(const AcGeKnotVector& fitKnots,
												const AcGePoint3dArray& fitPoints,
												const AcGeVector3d& startTangent,
												const AcGeVector3d& endTangent,
												const AcGeTol& fitTol = AcGeContext::gTol,
												bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve3d& setFitData(int degree, const AcGePoint3dArray& fitPoints,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT bool setFitKnotParameterization(KnotParameterization knotParam);
	GE_DLLEXPIMPORT bool setFitPointAt(int index, const AcGePoint3d& point);
	GE_DLLEXPIMPORT bool setFitTangents(const AcGeVector3d& startTangent,
										const AcGeVector3d& endTangent);
	GE_DLLEXPIMPORT bool setFitTangents(const AcGeVector3d& startTangent,
										const AcGeVector3d& endTangent, bool startTangentDefined,
										bool endTangentDefined) const;
	GE_DLLEXPIMPORT bool setFitTolerance(const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeSplineEnt3d& setWeightAt(int idx, double val);
	GE_DLLEXPIMPORT double weightAt(int idx) const;
};

#include "icarx/IcArxPackPop.h"
