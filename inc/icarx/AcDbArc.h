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
***     Description: Declaration of AcDbArc classes
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"
#include "AcDb3dPolylineVertex.h"

#include "IcArxPackPush.h"

class AcDbArc : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_PORT AcDbArc();
	AcDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle);
	AcDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle,
			double endAngle);
	~AcDbArc();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbArc);

	DBCURVE_METHODS

	AcGePoint3d center() const;
	double endAngle() const;
	ACDBCORE2D_PORT double length() const;
	ACDBCORE2D_PORT AcGeVector3d normal() const;
	double radius() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setCenter(const AcGePoint3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setEndAngle(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setNormal(const AcGeVector3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setRadius(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setStartAngle(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setThickness(double);
	double startAngle() const;
	double thickness() const;
	ACDBCORE2D_PORT double totalAngle() const;
};

#include "IcArxPackPop.h"
