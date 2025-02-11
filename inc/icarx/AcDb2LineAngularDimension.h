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
***     Description: Declaration of AcDb2LineAngularDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDb2LineAngularDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDb2LineAngularDimension();
	AcDb2LineAngularDimension(const AcGePoint3d& xLine1Start, const AcGePoint3d& xLine1End,
							  const AcGePoint3d& xLine2Start, const AcGePoint3d& xLine2End,
							  const AcGePoint3d& arcPoint, const ACHAR* dimText = nullptr,
							  AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDb2LineAngularDimension();

	ACDB_DECLARE_MEMBERS(AcDb2LineAngularDimension);

	AcGePoint3d arcPoint() const;
	bool extArcOn() const;
	Acad::ErrorStatus setArcPoint(const AcGePoint3d&);
	Acad::ErrorStatus setExtArcOn(bool value);
	Acad::ErrorStatus setXLine1End(const AcGePoint3d&);
	Acad::ErrorStatus setXLine2End(const AcGePoint3d&);
	Acad::ErrorStatus setXLine1Start(const AcGePoint3d&);
	Acad::ErrorStatus setXLine2Start(const AcGePoint3d&);
	AcGePoint3d xLine1End() const;
	AcGePoint3d xLine2End() const;
	AcGePoint3d xLine1Start() const;
	AcGePoint3d xLine2Start() const;
};

#include "IcArxPackPop.h"
