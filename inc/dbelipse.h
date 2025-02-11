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
***     Description: Declaration of AcDbEllipse class
***
*****************************************************************************/
#pragma once

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"

#include "icarx/IcArxPackPush.h"

class AcDbEllipse : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	ACDBCORE2D_PORT virtual bool subWorldDraw(AcGiWorldDraw* pWd) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform) override;

public:
	AcDbEllipse();
	AcDbEllipse(int val) {}
	ACDBCORE2D_PORT AcDbEllipse(const AcGePoint3d& center, const AcGeVector3d& unitNormal,
				const AcGeVector3d& majorAxis, double radiusRatio, double startAngle = 0.0,
				double endAngle = 6.28318530717958647692);
	~AcDbEllipse();

	ACDB_DECLARE_MEMBERS(AcDbEllipse);
	DBCURVE_METHODS

	double angleAtParam(double param) const;
	AcGePoint3d center() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	double endAngle() const;
	Acad::ErrorStatus get(AcGePoint3d& center, AcGeVector3d& unitNormal, AcGeVector3d& majorAxis,
						  double& radiusRatio, double& startAngle, double& endAngle) const;
	bool isNull() const;
	AcGeVector3d majorAxis() const;
	ACDBCORE2D_PORT double majorRadius() const;
	AcGeVector3d minorAxis() const;
	ACDBCORE2D_PORT double minorRadius() const;
	AcGeVector3d normal() const;
	double paramAtAngle(double angle) const;
	double radiusRatio() const;
	Acad::ErrorStatus set(const AcGePoint3d& center, const AcGeVector3d& unitNormal,
						  const AcGeVector3d& majorAxis, double radiusRatio,
						  double startAngle = 0.0, double endAngle = 6.28318530717958647692);
	Acad::ErrorStatus setCenter(const AcGePoint3d& center);
	Acad::ErrorStatus setEndAngle(double endAngle);
	Acad::ErrorStatus setEndParam(double endParam);
	ACDBCORE2D_PORT Acad::ErrorStatus setMajorRadius(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setMinorRadius(double);
	Acad::ErrorStatus setRadiusRatio(double ratio);
	Acad::ErrorStatus setStartAngle(double startAngle);
	Acad::ErrorStatus setStartParam(double startParam);
	double startAngle() const;
};

#include "icarx/IcArxPackPop.h"
