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
***     Description: Declaration of AcDbCircle classes
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"

#include "AcDb3dPolylineVertex.h"

#include "IcArxPackPush.h"

class AcDbCircle : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbCircle();
	AcDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius);
	~AcDbCircle();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbCircle);

	DBCURVE_METHODS

	AcGePoint3d center() const;
	double circumference() const;
	double diameter() const;
	ACDBCORE2D_PORT AcGeVector3d normal() const;
	double radius() const;
	Acad::ErrorStatus setCenter(const AcGePoint3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setCircumference(double);
	ACDBCORE2D_PORT Acad::ErrorStatus setDiameter(double);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setRadius(double);
	Acad::ErrorStatus setThickness(double);
	double thickness() const;
};

#include "IcArxPackPop.h"
