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
***     Description: Declaration of AcDbDiametricDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbDiametricDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbDiametricDimension();
	AcDbDiametricDimension(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint,
						   double leaderLength, const ACHAR* dimText = nullptr,
						   AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbDiametricDimension();

	ACDB_DECLARE_MEMBERS(AcDbDiametricDimension);

	AcGePoint3d chordPoint() const;
	double extArcEndAngle() const;
	double extArcStartAngle() const;
	AcGePoint3d farChordPoint() const;
	double leaderLength() const;
	Acad::ErrorStatus setChordPoint(const AcGePoint3d&);
	Acad::ErrorStatus setExtArcEndAngle(double newAngle);
	Acad::ErrorStatus setExtArcStartAngle(double newAngle);
	Acad::ErrorStatus setFarChordPoint(const AcGePoint3d&);
	Acad::ErrorStatus setLeaderLength(double);
};

#include "IcArxPackPop.h"
