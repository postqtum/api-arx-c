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
***     Description: Declaration of AcDbSolid class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class AcDbSolid : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbSolid();
	AcDbSolid(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2,
			  const AcGePoint3d& pt3);
	AcDbSolid(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	~AcDbSolid();

	ACDBCORE2D_DECLARE_MEMBERS(AcDbSolid);

	double elevation() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getPointAt(uint16_t idx, AcGePoint3d& pntRes) const;
	AcGeVector3d normal() const;
	void setElevation(double);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setPointAt(uint16_t idx, const AcGePoint3d&);
	Acad::ErrorStatus setThickness(double);
	double thickness() const;
};

#include "IcArxPackPop.h"
