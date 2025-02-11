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
***     Description: Declaration of AcDbNurbSurface class
***
*****************************************************************************/
#pragma once

#include "gevc3dar.h"
#include "dbsurf.h"

class AcGeKnotVector;
class AcGeNurbSurface;
class AcDbCurve;

#include "icarx/IcArxPackPush.h"

class AcDbNurbSurface : public AcDbSurface
{
protected:
	ACDB_PORT Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbNurbSurface);

	ACDB_PORT AcDbNurbSurface();
	ACDB_PORT AcDbNurbSurface(int uDegree, int vDegree, bool rational, int uNumControlPoints,
							  int vNumControlPoints, const AcGePoint3dArray& ctrlPts,
							  const AcGeDoubleArray& weights, const AcGeKnotVector& uKnots,
							  const AcGeKnotVector& vKnots);
	ACDB_PORT ~AcDbNurbSurface();

	ACDB_PORT Acad::ErrorStatus InsertControlPointsAtU(double u, const AcGePoint3dArray& vCtrlPts,
													   const AcGeDoubleArray& vWeights);
	ACDB_PORT Acad::ErrorStatus InsertControlPointsAtV(double v, const AcGePoint3dArray& uCtrlPts,
													   const AcGeDoubleArray& uWeights);
	ACDB_PORT Acad::ErrorStatus InsertKnotAtU(double u);
	ACDB_PORT Acad::ErrorStatus InsertKnotAtV(double v);
	ACDB_PORT Acad::ErrorStatus RemoveControlPointsAtU(int uIndex);
	ACDB_PORT Acad::ErrorStatus RemoveControlPointsAtV(int vIndex);
	ACDB_PORT void dragStatus(const AcDb::DragStat status) override;
	ACDB_PORT Acad::ErrorStatus evaluate(double u, double v, AcGePoint3d& pos) const;
	ACDB_PORT Acad::ErrorStatus evaluate(double u, double v, AcGePoint3d& pos, AcGeVector3d& uDeriv,
										 AcGeVector3d& vDeriv) const;
	ACDB_PORT Acad::ErrorStatus evaluate(double u, double v, AcGePoint3d& pos, AcGeVector3d& uDeriv,
										 AcGeVector3d& vDeriv, AcGeVector3d& uuDeriv,
										 AcGeVector3d& uvDeriv, AcGeVector3d& vvDeriv) const;
	ACDB_PORT Acad::ErrorStatus evaluate(double u, double v, int derivDegree, AcGePoint3d& point,
										 AcGeVector3dArray& derivatives) const;
	ACDB_PORT Acad::ErrorStatus get(int& uDegree, int& vDegree, bool& rational,
									int& uNumControlPoints, int& vNumControlPoints,
									AcGePoint3dArray& ctrlPts, AcGeDoubleArray& weights,
									AcGeKnotVector& uKnots, AcGeKnotVector& vKnots) const;
	ACDB_PORT Acad::ErrorStatus getControlPointAt(int uIndex, int vIndex, AcGePoint3d& point) const;
	ACDB_PORT Acad::ErrorStatus getControlPoints(int& uCount, int& vCount,
												 AcGePoint3dArray& points) const;
	ACDB_PORT Acad::ErrorStatus getDegreeInU(int& degree) const;
	ACDB_PORT Acad::ErrorStatus getDegreeInV(int& degree) const;
	ACDB_PORT Acad::ErrorStatus getIsolineAtU(double u, AcArray<AcDbCurve*>& lineSegments) const;
	ACDB_PORT Acad::ErrorStatus getIsolineAtV(double v, AcArray<AcDbCurve*>& lineSegments) const;
	ACDB_PORT Acad::ErrorStatus getNormal(double u, double v, AcGeVector3d& normal) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfControlPointsInU(int& count) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfControlPointsInV(int& count) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfKnotsInU(int& count) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfKnotsInV(int& count) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfSpansInU(int& span) const;
	ACDB_PORT Acad::ErrorStatus getNumberOfSpansInV(int& span) const;
	ACDB_PORT Acad::ErrorStatus getParameterOfPoint(const AcGePoint3d& point, double& u,
													double& v) const;
	ACDB_PORT Acad::ErrorStatus getPeriodInU(double& period) const;
	ACDB_PORT Acad::ErrorStatus getPeriodInV(double& period) const;
	ACDB_PORT Acad::ErrorStatus getUKnots(AcGeKnotVector& knots) const;
	ACDB_PORT Acad::ErrorStatus getVKnots(AcGeKnotVector& knots) const;
	ACDB_PORT Acad::ErrorStatus getWeight(int uIndex, int vIndex, double& weight) const;
	ACDB_PORT Acad::ErrorStatus isClosedInU(bool& isClosed) const;
	ACDB_PORT Acad::ErrorStatus isClosedInV(bool& isClosed) const;
	ACDB_PORT Acad::ErrorStatus isPeriodicInU(bool& isPeriodic) const;
	ACDB_PORT Acad::ErrorStatus isPeriodicInV(bool& isPeriodic) const;
	ACDB_PORT Acad::ErrorStatus isPlanar(bool& isPlanar, AcGePoint3d& ptOnSurface,
										 AcGeVector3d& normal) const;
	ACDB_PORT Acad::ErrorStatus isPointOnSurface(const AcGePoint3d& point, bool& onSurface) const;
	ACDB_PORT Acad::ErrorStatus isRational(bool& isRational) const;
	ACDB_PORT Acad::ErrorStatus modifyPositionAndTangent(double u, double v,
														 const AcGePoint3d& point,
														 const AcGeVector3d* uDeriv = nullptr,
														 const AcGeVector3d* vDeriv = nullptr);
	ACDB_PORT Acad::ErrorStatus rebuild(int uDegree, int vDegree, int numUCtrlPts, int numVCtrlPts,
										bool bRestore = false);
	ACDB_PORT Acad::ErrorStatus set(int uDegree, int vDegree, bool rational, int uNumControlPoints,
									int vNumControlPoints, const AcGePoint3dArray& ctrlPts,
									const AcGeDoubleArray& weights, const AcGeKnotVector& uKnots,
									const AcGeKnotVector& vKnots);
	ACDB_PORT Acad::ErrorStatus setControlPointAt(int uIndex, int vIndex, const AcGePoint3d& point);
	ACDB_PORT Acad::ErrorStatus setControlPoints(int uCount, int vCount,
												 const AcGePoint3dArray& points);
	ACDB_PORT Acad::ErrorStatus setWeight(int uIndex, int vIndex, double weight);
};

#include "icarx/IcArxPackPop.h"
