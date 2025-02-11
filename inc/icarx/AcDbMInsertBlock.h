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
***     Description: Declaration of AcDbMInsertBlock class
***
*****************************************************************************/
#pragma once

#include "AcDbBlockReference.h"

#include "IcArxPackPush.h"

class AcDbMInsertBlock : public AcDbBlockReference
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	AcDbMInsertBlock();
	AcDbMInsertBlock(const AcGePoint3d& position, AcDbObjectId blockTableRec, uint16_t columns,
					 uint16_t rows, double colSpacing, double rowSpacing);
	~AcDbMInsertBlock();

	ACDB_DECLARE_MEMBERS(AcDbMInsertBlock);

	double columnSpacing() const;
	uint16_t columns() const;
	double rowSpacing() const;
	uint16_t rows() const;
	Acad::ErrorStatus setColumnSpacing(double);
	Acad::ErrorStatus setColumns(uint16_t);
	Acad::ErrorStatus setRowSpacing(double);
	Acad::ErrorStatus setRows(uint16_t);
};

#include "IcArxPackPop.h"
