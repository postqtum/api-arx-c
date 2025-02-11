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
***     Description:
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"
#include "gekvec.h"

#ifndef ODDB_DBSPLINE_H
static const unsigned int kPlineVerticesThrehold = 10000;
#endif

class AcDb2dPolyline;

enum SplineType
{
	kFitPoints = 0,
	kControlPoints = 1
};

#include "icarx/IcArxPackPush.h"

class AcDbSpline : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbSpline);

public:
	ACDBCORE2D_PORT AcDbSpline();
	ACDBCORE2D_PORT ~AcDbSpline();
	AcDbSpline(const AcGePoint3d& center, const AcGeVector3d& unitNormal,
			   const AcGeVector3d& majorAxis, double radiusRatio, double startAngle = 0.0,
			   double endAngle = 6.28318530717958647692);
	ACDBCORE2D_PORT AcDbSpline(const AcGePoint3dArray& fitPoints, const AcGeVector3d& startTangent,
							   const AcGeVector3d& endTangent, AcGe::KnotParameterization knotParam,
							   int degree = 3, double fitTolerance = 0.0);
	ACDBCORE2D_PORT AcDbSpline(const AcGePoint3dArray& fitPoints,
							   AcGe::KnotParameterization knotParam, int degree = 3,
							   double fitTolerance = 0.0);
	ACDBCORE2D_PORT AcDbSpline(const AcGePoint3dArray& fitPoints, bool periodic,
							   AcGe::KnotParameterization knotParam = AcGe::kUniform,
							   int degree = 3, double fitTolerance = 0.0);
	AcDbSpline(const AcGePoint3dArray& fitPoints, const AcGeVector3d& startTangent,
			   const AcGeVector3d& endTangent, int order = 4, double fitTolerance = 0.0);
	AcDbSpline(const AcGePoint3dArray& fitPoints, int order = 4, double fitTolerance = 0.0);
	AcDbSpline(int degree, bool rational, bool closed, bool periodic,
			   const AcGePoint3dArray& controlPoints, const AcGeDoubleArray& knots,
			   const AcGeDoubleArray& weights, double controlPtTol = 0.0,
			   double knotTol = AcGeKnotVector::globalKnotTolerance);

	DBCURVE_METHODS

	int degree() const;
	Acad::ErrorStatus elevateDegree(int newDegree);
	double fitTolerance() const;
	Acad::ErrorStatus getControlPointAt(int index, AcGePoint3d& point) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFitData(AcGePoint3dArray& fitPoints, bool& tangentsExist,
												 AcGeVector3d& startTangent,
												 AcGeVector3d& endTangent,
												 AcGe::KnotParameterization& knotParam, int& degree,
												 double& fitTolerance) const;
	Acad::ErrorStatus getFitData(AcGePoint3dArray& fitPoints, int& degree, double& fitTolerance,
								 bool& tangentsExist, AcGeVector3d& startTangent,
								 AcGeVector3d& endTangent) const;
	Acad::ErrorStatus getFitPointAt(int index, AcGePoint3d& point) const;
	Acad::ErrorStatus getFitTangents(AcGeVector3d& startTangent, AcGeVector3d& endTangent) const;
	Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
			const AcGeVector3d& normal, double offsetDist,
			AcDbVoidPtrArray& offsetCurves) const override;
	Acad::ErrorStatus getNurbsData(int& degree, bool& rational, bool& closed,
								   bool& periodic, AcGePoint3dArray& controlPoints,
								   AcGeDoubleArray& knots, AcGeDoubleArray& weights,
								   double& controlPtTol, double& knotTol) const;
	bool hasFitData() const;
	ACDBCORE2D_PORT Acad::ErrorStatus insertControlPointAt(double knotParam,
														   const AcGePoint3d& ctrlPt,
														   double weight = 1.0);
	Acad::ErrorStatus insertFitPointAt(int index, const AcGePoint3d& point);
	Acad::ErrorStatus insertKnot(double param);
	bool isNull() const;
	bool isRational() const;
	ACDBCORE2D_PORT Acad::ErrorStatus modifyPositionAndTangent(double param,
															   const AcGePoint3d& point,
															   const AcGeVector3d* deriv);
	int numControlPoints() const;
	int numFitPoints() const;
	Acad::ErrorStatus purgeFitData();
	ACDBCORE2D_PORT Acad::ErrorStatus rebuild(int degree, int numCtrlPts);
	ACDBCORE2D_PORT Acad::ErrorStatus removeControlPointAt(int index);
	Acad::ErrorStatus removeFitPointAt(int index);
	Acad::ErrorStatus setControlPointAt(int index, const AcGePoint3d& point);
	ACDBCORE2D_PORT Acad::ErrorStatus setFitData(const AcGePoint3dArray& fitPoints,
												 const AcGeVector3d& startTangent,
												 const AcGeVector3d& endTangent,
												 AcGe::KnotParameterization knotParam,
												 int degree = 3, double fitTolerance = 0.0);
	ACDBCORE2D_PORT Acad::ErrorStatus setFitData(const AcGePoint3dArray& fitPoints, bool isPeriodic,
												 AcGe::KnotParameterization knotParam,
												 int degree = 3, double fitTolerance = 0.0);
	Acad::ErrorStatus setFitData(const AcGePoint3dArray& fitPoints, int degree, double fitTolerance,
								 const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
	Acad::ErrorStatus setFitPointAt(int index, const AcGePoint3d& point);
	Acad::ErrorStatus setFitTangents(const AcGeVector3d& startTangent,
									 const AcGeVector3d& endTangent);
	Acad::ErrorStatus setFitTol(double tol);
	ACDBCORE2D_PORT Acad::ErrorStatus setNurbsData(int degree, bool rational, bool closed,
												   bool periodic,
												   const AcGePoint3dArray& controlPoints,
												   const AcGeDoubleArray& knots,
												   const AcGeDoubleArray& weights,
												   double controlPtTol = 0.0, double knotTol = 0.0);
	ACDBCORE2D_PORT Acad::ErrorStatus setType(SplineType type);
	Acad::ErrorStatus setWeightAt(int index, double weight);
	ACDBCORE2D_PORT Acad::ErrorStatus toPolyline(
			AcDbCurve*& pCurve, bool bConvertAsArcs, bool bToLWPolyline, int precision = 10,
			int* maxSuggestedPrecision = nullptr,
			unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;
	Acad::ErrorStatus toPolyline(
			AcDbCurve*& pCurve, int precision = 10, int* maxSuggestedPrecision = nullptr,
			unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;
	ACDBCORE2D_PORT SplineType type() const;
	Acad::ErrorStatus updateFitData();
	double weightAt(int index) const;
};

#include "icarx/IcArxPackPop.h"
