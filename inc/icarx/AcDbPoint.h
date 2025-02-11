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
***     Description: Declaration of AcDbPoint class
***
*****************************************************************************/
#pragma once

#include "../dbcurve.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbPoint : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbPoint();
	AcDbPoint(const AcGePoint3d& position);
	~AcDbPoint();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbPoint);

	double ecsRotation() const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	bool isPlanar() const override { return true; }
	AcGeVector3d normal() const;
	ACDBCORE2D_PORT AcGePoint3d position() const;
	Acad::ErrorStatus setEcsRotation(double);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	Acad::ErrorStatus setThickness(double);
	double thickness() const;
};

#include "IcArxPackPop.h"
