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
***     Description: Declaration of AcDbAlignedDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbAlignedDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbAlignedDimension();
	AcDbAlignedDimension(const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point,
						 const AcGePoint3d& dimLinePoint, const ACHAR* dimText = nullptr,
						 AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbAlignedDimension();

	ACDB_DECLARE_MEMBERS(AcDbAlignedDimension);

	AcGePoint3d dimLinePoint() const;
	bool jogSymbolOn() const;
	AcGePoint3d jogSymbolPosition() const;
	double oblique() const;
	Acad::ErrorStatus setDimLinePoint(const AcGePoint3d&);
	Acad::ErrorStatus setJogSymbolOn(bool value);
	Acad::ErrorStatus setJogSymbolPosition(const AcGePoint3d& pt);
	Acad::ErrorStatus setOblique(double);
	Acad::ErrorStatus setXLine1Point(const AcGePoint3d&);
	Acad::ErrorStatus setXLine2Point(const AcGePoint3d&);
	AcGePoint3d xLine1Point() const;
	AcGePoint3d xLine2Point() const;
};

#include "IcArxPackPop.h"
