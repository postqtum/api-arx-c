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
***     Description: Declaration of AcDbTrace class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "../gept3dar.h"

#include "IcArxPackPush.h"

class AcDbTrace : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbTrace();
	AcDbTrace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2,
			  const AcGePoint3d& pt3);
	~AcDbTrace();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbTrace);

	double elevation() const;
	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus getPointAt(uint16_t idx, AcGePoint3d& PntRes) const;
	bool isPlanar() const override { return true; }
	AcGeVector3d normal() const;
	void setElevation(double);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setPointAt(uint16_t idx, const AcGePoint3d&);
	Acad::ErrorStatus setThickness(double);
	double thickness() const;
};

#include "IcArxPackPop.h"
