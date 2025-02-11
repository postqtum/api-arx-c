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
***     Description: Declaration of AcDbTableContent class
***
*****************************************************************************/
#pragma once

#include "DbFormattedTableData.h"

#include "icarx/IcArxPackPush.h"

class AcDbTableContent : public AcDbFormattedTableData
{
public:
	ACDB_DECLARE_MEMBERS(AcDbTableContent);

	ACDB_PORT AcDbTableContent();
	ACDB_PORT ~AcDbTableContent();

	ACDB_PORT virtual const ACHAR* cellStyle(int nRow, int nCol) const;
	ACDB_PORT virtual double columnWidth(int nCol) const;
	ACDB_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDB_PORT virtual double rowHeight(int nRow) const;
	ACDB_PORT virtual Acad::ErrorStatus setCellStyle(int nRow, int nCol, const ACHAR* pszCellStyle);
	ACDB_PORT virtual Acad::ErrorStatus setColumnWidth(int nCol, double fWidth);
	ACDB_PORT virtual Acad::ErrorStatus setRowHeight(int nRow, double fWidth);
	ACDB_PORT virtual Acad::ErrorStatus setTableStyleId(const AcDbObjectId& idTableStyle);
	ACDB_PORT virtual AcDbObjectId tableStyleId() const;
};

#include "icarx/IcArxPackPop.h"
