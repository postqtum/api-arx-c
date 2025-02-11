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
***     Description: Declaration of AcGeNurbCurve2d class
***
*****************************************************************************/
#pragma once

#include "gecurv2d.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gesent2d.h"
#include "geplin2d.h"
#include "gedblar.h"
#include "gept2dar.h"
#include "gevc2dar.h"

class AcGeEllipArc2d;
class AcGeLineSeg2d;

#include "icarx/IcArxPackPush.h"

class AcGeNurbCurve2d : public AcGeSplineEnt2d
{
public:
	GE_DLLEXPIMPORT AcGeNurbCurve2d();
	GE_DLLEXPIMPORT AcGeNurbCurve2d(int degree, const AcGeKnotVector& knots,
									const AcGePoint2dArray& cntrlPnts,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(int degree, const AcGeKnotVector& knots,
									const AcGePoint2dArray& cntrlPnts,
									const AcGeDoubleArray& weights,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(int degree, const AcGePolyline2d& fitPolyline,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGePoint2dArray& fitPoints,
									const AcGeVector2d& startTangent,
									const AcGeVector2d& endTangent,
									bool startTangentDefined = true,
									bool endTangentDefined = true,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGePoint2dArray& fitPoints,
									const AcGeVector2d& startTangent,
									const AcGeVector2d& endTangent,
									bool startTangentDefined,
									bool endTangentDefined,
									AcGe::KnotParameterization knotParam,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGePoint2dArray& fitPoints,
									const AcGeTol& fitTolerance = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGePoint2dArray& fitPoints,
									const AcGeVector2dArray& fitTangents,
									const AcGeTol& fitTolerance = AcGeContext::gTol,
									bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGeEllipArc2d& ellipse);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGeLineSeg2d& linSeg);
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGeCurve2d& curve,
									double epsilon = AcGeContext::gTol.equalPoint());
	GE_DLLEXPIMPORT AcGeNurbCurve2d(const AcGeNurbCurve2d&);
	~AcGeNurbCurve2d() = default;
	GE_DLLEXPIMPORT AcGeNurbCurve2d& operator=(const AcGeNurbCurve2d&);

	GE_DLLEXPIMPORT bool addControlPointAt(double newKnot, const AcGePoint2d& point,
										   double weight = 1.0);
	GE_DLLEXPIMPORT bool addFitPointAt(int index, const AcGePoint2d& point);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& addKnot(double newKnot);
	GE_DLLEXPIMPORT bool buildFitData();
	GE_DLLEXPIMPORT bool buildFitData(KnotParameterization kp);
	GE_DLLEXPIMPORT bool deleteControlPointAt(int index);
	GE_DLLEXPIMPORT bool deleteFitPointAt(int index);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& elevateDegree(int plusDegree);
	GE_DLLEXPIMPORT bool evalMode() const;
	GE_DLLEXPIMPORT void getDefinitionData(int& degree, bool& rational, bool& periodic,
										   AcGeKnotVector& knots, AcGePoint2dArray& controlPoints,
										   AcGeDoubleArray& weights) const;
	GE_DLLEXPIMPORT bool getFitData(AcGePoint2dArray& fitPoints, AcGeTol& fitTolerance,
									bool& tangentsExist, AcGeVector2d& startTangent,
									AcGeVector2d& endTangent) const;
	GE_DLLEXPIMPORT bool getFitData(AcGePoint2dArray& fitPoints, AcGeTol& fitTolerance,
									bool& tangentsExist, AcGeVector2d& startTangent,
									AcGeVector2d& endTangent,
									KnotParameterization& knotParam) const;
	GE_DLLEXPIMPORT bool getFitKnotParameterization(KnotParameterization& knotParam) const;
	GE_DLLEXPIMPORT bool getFitPointAt(int index, AcGePoint2d& point) const;
	GE_DLLEXPIMPORT bool getFitTangents(AcGeVector2d& startTangent, AcGeVector2d& endTangent) const;
	GE_DLLEXPIMPORT bool getFitTolerance(AcGeTol& fitTolerance) const;
	GE_DLLEXPIMPORT bool getParamsOfC1Discontinuity(AcGeDoubleArray& params,
													const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT bool getParamsOfG1Discontinuity(AcGeDoubleArray& params,
													const AcGeTol& tol = AcGeContext::gTol) const;
	GE_DLLEXPIMPORT AcGeNurbCurve2d& hardTrimByParams(double newStartParam, double newEndParam);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& insertKnot(double newKnot);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& joinWith(const AcGeNurbCurve2d& curve);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& makeClosed();
	GE_DLLEXPIMPORT AcGeNurbCurve2d& makeNonPeriodic();
	GE_DLLEXPIMPORT AcGeNurbCurve2d& makeOpen();
	GE_DLLEXPIMPORT AcGeNurbCurve2d& makePeriodic();
	GE_DLLEXPIMPORT AcGeNurbCurve2d& makeRational(double weight = 1.0);
	GE_DLLEXPIMPORT int numFitPoints() const;
	GE_DLLEXPIMPORT int numWeights() const;
	GE_DLLEXPIMPORT bool purgeFitData();
	GE_DLLEXPIMPORT AcGeNurbCurve2d& setEvalMode(bool evalMode = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& setFitData(const AcGePoint2dArray& fitPoints,
												const AcGeVector2d& startTangent,
												const AcGeVector2d& endTangent,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& setFitData(const AcGePoint2dArray& fitPoints,
												const AcGeVector2d& startTangent,
												const AcGeVector2d& endTangent,
												KnotParameterization knotParam,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& setFitData(const AcGeKnotVector& fitKnots,
												const AcGePoint2dArray& fitPoints,
												const AcGeVector2d& startTangent,
												const AcGeVector2d& endTangent,
												const AcGeTol& fitTol = AcGeContext::gTol,
												bool isPeriodic = false);
	GE_DLLEXPIMPORT AcGeNurbCurve2d& setFitData(int degree, const AcGePoint2dArray& fitPoints,
												const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT bool setFitKnotParameterization(KnotParameterization knotParam);
	GE_DLLEXPIMPORT bool setFitPointAt(int index, const AcGePoint2d& point);
	GE_DLLEXPIMPORT bool setFitTangents(const AcGeVector2d& startTangent,
										const AcGeVector2d& endTangent);
	GE_DLLEXPIMPORT bool setFitTolerance(const AcGeTol& fitTol = AcGeContext::gTol);
	GE_DLLEXPIMPORT AcGeSplineEnt2d& setWeightAt(int idx, double val);
	GE_DLLEXPIMPORT double weightAt(int idx) const;
};

#include "icarx/IcArxPackPop.h"
