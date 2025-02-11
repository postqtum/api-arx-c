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
***     Description: Declaration of AcDbArcDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbArcDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbArcDimension();
	AcDbArcDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point,
					 const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint,
					 const ACHAR* dimText = nullptr, AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbArcDimension();

	ACDB_DECLARE_MEMBERS(AcDbArcDimension);

	double arcEndParam() const;
	AcGePoint3d arcPoint() const;
	double arcStartParam() const;
	int arcSymbolType() const;
	AcGePoint3d centerPoint() const;
	bool hasLeader() const;
	bool isPartial() const;
	AcGePoint3d leader1Point() const;
	AcGePoint3d leader2Point() const;
	Acad::ErrorStatus setArcEndParam(const double& arcParam);
	Acad::ErrorStatus setArcPoint(const AcGePoint3d& arcPt);
	Acad::ErrorStatus setArcStartParam(const double& arcParam);
	Acad::ErrorStatus setArcSymbolType(const int symbol);
	Acad::ErrorStatus setCenterPoint(const AcGePoint3d& ctrPt);
	Acad::ErrorStatus setHasLeader(const bool& leaderVal);
	Acad::ErrorStatus setIsPartial(const bool& partial);
	Acad::ErrorStatus setLeader1Point(const AcGePoint3d& ldr1Pt);
	Acad::ErrorStatus setLeader2Point(const AcGePoint3d& ldr2Pt);
	Acad::ErrorStatus setXLine1Point(const AcGePoint3d& xLine1Pt);
	Acad::ErrorStatus setXLine2Point(const AcGePoint3d& xLine2Pt);
	AcGePoint3d xLine1Point() const;
	AcGePoint3d xLine2Point() const;
};

#include "IcArxPackPop.h"
