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
***     Description: Declaration of AcDbCurve class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "gept3dar.h"
#include "gedblar.h"
#include "geplane.h"
#include "dbptrar.h"

class AcDbSpline;

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbCurve : public AcDbEntity
{
protected:
	AcDbCurve();

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbCurve);

	~AcDbCurve();

	ACDBCORE2D_PORT static Acad::ErrorStatus createFromAcGeCurve(
			const AcGeCurve3d& geCurve, AcDbCurve*& pDbCurve, AcGeVector3d* normal = nullptr,
			const AcGeTol& tol = AcGeContext::gTol);
	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(bool extendStart, const AcGePoint3d& toPoint);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getAcGeCurve(
			AcGeCurve3d*& pGeCurve, const AcGeTol& tol = AcGeContext::gTol) const;
	virtual Acad::ErrorStatus getArea(double&) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt,
												AcGePoint3d& pointOnCurve,
												bool extend = false) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt,
												const AcGeVector3d& direction,
												AcGePoint3d& pointOnCurve,
												bool extend = false) const;
	virtual Acad::ErrorStatus getDistAtParam(double param, double& dist) const;
	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d&, double&) const;
	virtual Acad::ErrorStatus getEndParam(double&) const;
	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d&) const;
	virtual Acad::ErrorStatus getFirstDeriv(double param, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d&, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getOffsetCurves(double offsetDist,
											  AcDbVoidPtrArray& offsetCurves) const;
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal,
															  double offsetDist,
															  AcDbVoidPtrArray& offsetCurves) const;
	virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane&, AcDbCurve*& projCrv) const;
	virtual Acad::ErrorStatus getParamAtDist(double dist, double& param) const;
	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d&, double&) const;
	virtual Acad::ErrorStatus getPointAtDist(double, AcGePoint3d&) const;
	virtual Acad::ErrorStatus getPointAtParam(double, AcGePoint3d&) const;
	virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane&, const AcGeVector3d& projDir,
												AcDbCurve*& projCrv) const;
	virtual Acad::ErrorStatus getSecondDeriv(double param, AcGeVector3d& secDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d&, AcGeVector3d& secDeriv) const;
	virtual Acad::ErrorStatus getSpline(AcDbSpline*& spline) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray& params,
											 AcDbVoidPtrArray& curveSegments) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray& points,
											 AcDbVoidPtrArray& curveSegments) const;
	virtual Acad::ErrorStatus getStartParam(double&) const;
	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d&) const;
	virtual bool isClosed() const;
	virtual bool isPeriodic() const;
	virtual Acad::ErrorStatus reverseCurve();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setFromAcGeCurve(
			const AcGeCurve3d& geCurve, AcGeVector3d* normal = nullptr,
			const AcGeTol& tol = AcGeContext::gTol);
};

#include "icarx/IcArxPackPop.h"

#define DBCURVE_METHODS                                                                            \
	ACDBCORE2D_PORT bool isClosed() const override;                                                \
	ACDBCORE2D_PORT bool isPeriodic() const override;                                              \
	ACDBCORE2D_PORT bool isPlanar() const override;                                                \
	ACDBCORE2D_PORT Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;       \
	ACDBCORE2D_PORT Acad::ErrorStatus getStartParam(double&) const override;                       \
	ACDBCORE2D_PORT Acad::ErrorStatus getEndParam(double&) const override;                         \
	ACDBCORE2D_PORT Acad::ErrorStatus getStartPoint(AcGePoint3d&) const override;                  \
	ACDBCORE2D_PORT Acad::ErrorStatus getEndPoint(AcGePoint3d&) const override;                    \
	ACDBCORE2D_PORT Acad::ErrorStatus getPointAtParam(double, AcGePoint3d&) const override;        \
	ACDBCORE2D_PORT Acad::ErrorStatus getParamAtPoint(const AcGePoint3d&, double&) const override; \
	ACDBCORE2D_PORT Acad::ErrorStatus getDistAtParam(double, double&) const override;              \
	ACDBCORE2D_PORT Acad::ErrorStatus getParamAtDist(double, double&) const override;              \
	ACDBCORE2D_PORT Acad::ErrorStatus getDistAtPoint(const AcGePoint3d&, double&) const override;  \
	ACDBCORE2D_PORT Acad::ErrorStatus getPointAtDist(double, AcGePoint3d&) const override;         \
	ACDBCORE2D_PORT Acad::ErrorStatus getFirstDeriv(double, AcGeVector3d&) const override;         \
	ACDBCORE2D_PORT Acad::ErrorStatus getFirstDeriv(const AcGePoint3d&, AcGeVector3d&)             \
			const override;                                                                        \
	ACDBCORE2D_PORT Acad::ErrorStatus getSecondDeriv(double, AcGeVector3d&) const override;        \
	ACDBCORE2D_PORT Acad::ErrorStatus getSecondDeriv(const AcGePoint3d&, AcGeVector3d&)            \
			const override;                                                                        \
	ACDBCORE2D_PORT Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&, AcGePoint3d&,          \
														bool = false) const override;              \
	ACDBCORE2D_PORT Acad::ErrorStatus getClosestPointTo(                                           \
			const AcGePoint3d&, const AcGeVector3d&, AcGePoint3d&, bool = false) const override;   \
	ACDBCORE2D_PORT Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane&, AcDbCurve*&)        \
			const override;                                                                        \
	ACDBCORE2D_PORT Acad::ErrorStatus getProjectedCurve(const AcGePlane&, const AcGeVector3d&,     \
														AcDbCurve*&) const override;               \
	ACDBCORE2D_PORT Acad::ErrorStatus getOffsetCurves(double, AcDbVoidPtrArray&) const override;   \
	ACDBCORE2D_PORT Acad::ErrorStatus getSpline(AcDbSpline*&) const override;                      \
	ACDBCORE2D_PORT Acad::ErrorStatus getSplitCurves(                                              \
			const AcGeDoubleArray&, AcDbVoidPtrArray& curveSegments) const override;               \
	ACDBCORE2D_PORT Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray&, AcDbVoidPtrArray&)   \
			const override;                                                                        \
	ACDBCORE2D_PORT Acad::ErrorStatus extend(double) override;                                     \
	ACDBCORE2D_PORT Acad::ErrorStatus extend(bool, const AcGePoint3d&) override;                   \
	ACDBCORE2D_PORT Acad::ErrorStatus getArea(double&) const override;                             \
	ACDBCORE2D_PORT Acad::ErrorStatus reverseCurve() override;                                     \
	ACDBCORE2D_PORT Acad::ErrorStatus getAcGeCurve(                                                \
			AcGeCurve3d*& pGeCurve, const AcGeTol& tol = AcGeContext::gTol) const override;        \
	ACDBCORE2D_PORT Acad::ErrorStatus setFromAcGeCurve(                                            \
			const AcGeCurve3d& geCurve, AcGeVector3d* normal = nullptr,                            \
			const AcGeTol& tol = AcGeContext::gTol) override;
