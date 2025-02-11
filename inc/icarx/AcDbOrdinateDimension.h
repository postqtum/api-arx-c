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
***     Description: Declaration of AcDbOrdinateDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbOrdinateDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbOrdinateDimension();
	AcDbOrdinateDimension(bool useXAxis, const AcGePoint3d& definingPoint,
						  const AcGePoint3d& leaderEndPoint, const ACHAR* dimText = nullptr,
						  AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbOrdinateDimension();

	ACDB_DECLARE_MEMBERS(AcDbOrdinateDimension);

	AcGePoint3d definingPoint() const;
	bool isUsingXAxis() const;
	bool isUsingYAxis() const;
	AcGePoint3d leaderEndPoint() const;
	AcGePoint3d origin() const;
	Acad::ErrorStatus setDefiningPoint(const AcGePoint3d&);
	Acad::ErrorStatus setLeaderEndPoint(const AcGePoint3d&);
	Acad::ErrorStatus setOrigin(const AcGePoint3d&);
	ACDBCORE2D_PORT Acad::ErrorStatus setUsingXAxis(bool value);
	ACDBCORE2D_PORT Acad::ErrorStatus setUsingYAxis(bool value);
	Acad::ErrorStatus useXAxis();
	Acad::ErrorStatus useYAxis();
};

#include "IcArxPackPop.h"
