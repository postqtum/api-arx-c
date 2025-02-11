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
***     Description: Declaration of AcDb3PointAngularDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDb3PointAngularDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDb3PointAngularDimension();
	AcDb3PointAngularDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point,
							   const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint,
							   const ACHAR* dimText = nullptr,
							   AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDb3PointAngularDimension();

	ACDB_DECLARE_MEMBERS(AcDb3PointAngularDimension);

	AcGePoint3d arcPoint() const;
	AcGePoint3d centerPoint() const;
	bool extArcOn() const;
	Acad::ErrorStatus setArcPoint(const AcGePoint3d&);
	Acad::ErrorStatus setCenterPoint(const AcGePoint3d&);
	Acad::ErrorStatus setExtArcOn(bool value);
	Acad::ErrorStatus setXLine1Point(const AcGePoint3d&);
	Acad::ErrorStatus setXLine2Point(const AcGePoint3d&);
	AcGePoint3d xLine1Point() const;
	AcGePoint3d xLine2Point() const;
};

#include "IcArxPackPop.h"
