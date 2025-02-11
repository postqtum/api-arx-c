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
***     Description: Declaration of AcDbRadialDimension class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbRadialDimension : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbRadialDimension();
	AcDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint,
						double leaderLength, const ACHAR* dimText = nullptr,
						AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbRadialDimension();

	ACDB_DECLARE_MEMBERS(AcDbRadialDimension);

	AcGePoint3d center() const;
	AcGePoint3d chordPoint() const;
	double extArcEndAngle() const;
	double extArcStartAngle() const;
	double leaderLength() const;
	Acad::ErrorStatus setCenter(const AcGePoint3d&);
	Acad::ErrorStatus setChordPoint(const AcGePoint3d&);
	Acad::ErrorStatus setExtArcEndAngle(double newAngle);
	Acad::ErrorStatus setExtArcStartAngle(double newAngle);
	Acad::ErrorStatus setLeaderLength(double);
};

#include "IcArxPackPop.h"
