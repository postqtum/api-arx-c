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
***     Description: Declaration of AcDbShape class
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"
#include "../gept3dar.h"

#include "IcArxPackPush.h"

class AcDbShape : public AcDbEntity
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbShape();
	AcDbShape(const AcGePoint3d& position, double size, double rotation = 0,
			  double widthFactor = 0);
	~AcDbShape();

	ACDB_DECLARE_MEMBERS(AcDbShape);

	Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const override;
	bool isPlanar() const override { return true; }
	ACDBCORE2D_PORT Acad::ErrorStatus name(AcString& sName) const;
	ACHAR* name() const;
	AcGeVector3d normal() const;
	double oblique() const;
	AcGePoint3d position() const;
	double rotation() const;
	Acad::ErrorStatus setName(const ACHAR*);
	Acad::ErrorStatus setNormal(const AcGeVector3d&);
	Acad::ErrorStatus setOblique(double);
	Acad::ErrorStatus setPosition(const AcGePoint3d&);
	Acad::ErrorStatus setRotation(double);
	Acad::ErrorStatus setShapeIndex(AcDbObjectId id) { return this->setStyleId(id); }
	Acad::ErrorStatus setShapeNumber(int16_t);
	Acad::ErrorStatus setSize(double);
	Acad::ErrorStatus setStyleId(AcDbObjectId id);
	Acad::ErrorStatus setThickness(double);
	Acad::ErrorStatus setWidthFactor(double);
	AcDbObjectId shapeIndex() const { return this->styleId(); }
	int16_t shapeNumber() const;
	double size() const;
	AcDbObjectId styleId() const;
	double thickness() const;
	double widthFactor() const;
};

#include "IcArxPackPop.h"

inline ACHAR* AcDbShape::name() const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbShape::name);
}
