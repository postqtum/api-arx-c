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
***     Description: Declaration of AcDbLine class
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"
#include "AcDb3dPolylineVertex.h"

#include "IcArxPackPush.h"

class AcDbLine : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_PORT AcDbLine();
	AcDbLine(const AcGePoint3d& start, const AcGePoint3d& end);
	~AcDbLine();

	ACDB_DECLARE_MEMBERS(AcDbLine);

	DBCURVE_METHODS

	AcGePoint3d endPoint() const;
	Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
			const AcGeVector3d& normal, double offsetDist,
			AcDbVoidPtrArray& offsetCurves) const override;
	AcGeVector3d normal() const;
	ACDBCORE2D_PORT Acad::ErrorStatus setEndPoint(const AcGePoint3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setNormal(const AcGeVector3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setStartPoint(const AcGePoint3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setThickness(double);
	AcGePoint3d startPoint() const;
	double thickness() const;
};

#include "IcArxPackPop.h"
