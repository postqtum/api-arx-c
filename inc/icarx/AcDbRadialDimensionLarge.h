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
***     Description: Declaration of AcDbRadialDimensionLarge class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbRadialDimensionLarge : public AcDbDimension
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbRadialDimensionLarge();
	AcDbRadialDimensionLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint,
							 const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint,
							 double jogAngle, const ACHAR* dimText = nullptr,
							 AcDbObjectId dimStyle = AcDbObjectId::kNull);
	~AcDbRadialDimensionLarge();

	ACDB_DECLARE_MEMBERS(AcDbRadialDimensionLarge);

	AcGePoint3d center() const;
	AcGePoint3d chordPoint() const;
	double extArcEndAngle() const;
	double extArcStartAngle() const;
	double jogAngle() const;
	AcGePoint3d jogPoint() const;
	AcGePoint3d overrideCenter() const;
	Acad::ErrorStatus setCenter(const AcGePoint3d& centerPoint);
	Acad::ErrorStatus setChordPoint(const AcGePoint3d& chordPoint);
	Acad::ErrorStatus setExtArcEndAngle(double newAngle);
	Acad::ErrorStatus setExtArcStartAngle(double newAngle);
	Acad::ErrorStatus setJogAngle(double jogAngle);
	Acad::ErrorStatus setJogPoint(const AcGePoint3d& jogPoint);
	Acad::ErrorStatus setJogPointPP(const AcGePoint3d& jogPointPP);
	Acad::ErrorStatus setOverrideCenter(const AcGePoint3d& overrideCenterPoint);
	Acad::ErrorStatus setOverrideCenterPP(const AcGePoint3d& overrideCenterPointPP);
	Acad::ErrorStatus setTextPositionPP(const AcGePoint3d& textPointPP);
};

#include "IcArxPackPop.h"
