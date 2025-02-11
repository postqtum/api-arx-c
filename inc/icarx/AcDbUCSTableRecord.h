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
***     Description: Declaration of AcDbUCSTableRecord class
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTableRecord.h"
#include "../gepnt3d.h"

class AcDbUCSTable;

#include "IcArxPackPush.h"

class AcDbUCSTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbUCSTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbUCSTableRecord);

	AcDbUCSTableRecord();
	~AcDbUCSTableRecord();

	AcGePoint3d origin() const;
	void setOrigin(const AcGePoint3d& newOrigin);
	Acad::ErrorStatus setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view);
	void setXAxis(const AcGeVector3d& xAxis);
	void setYAxis(const AcGeVector3d& yAxis);
	AcGePoint3d ucsBaseOrigin(AcDb::OrthographicView view) const;
	AcGeVector3d xAxis() const;
	AcGeVector3d yAxis() const;
};

#include "IcArxPackPop.h"
