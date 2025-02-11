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
***     Description: Declaration of AcDbRegion class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbcurve.h"

class AcGePoint3d;
class AcGeVector3d;

#include "icarx/IcArxPackPush.h"

class AcDbRay : public AcDbCurve
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbRay);

public:
	AcDbRay();
	~AcDbRay();

	DBCURVE_METHODS

	AcGePoint3d basePoint() const;
	Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
			const AcGeVector3d& normal, double offsetDist,
			AcDbVoidPtrArray& offsetCurves) const override;
	ACDBCORE2D_PORT AcGePoint3d secondPoint() const;
	void setBasePoint(const AcGePoint3d& pt);
	ACDBCORE2D_PORT Acad::ErrorStatus setSecondPoint(AcGePoint3d const& pt);
	void setUnitDir(const AcGeVector3d& vec);
	AcGeVector3d unitDir() const;
};

#include "icarx/IcArxPackPop.h"
