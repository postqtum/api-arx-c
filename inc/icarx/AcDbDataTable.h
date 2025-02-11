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
***     Description: Declaration of AcDbDataTable class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "AcDbDataColumn.h"
#include "../AcString.h"
#include "acut_str_util.h"

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class AcDbDataTable : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbDataTable);

	AcDbDataTable();
	AcDbDataTable(const AcDbDataTable&);
	~AcDbDataTable();
	virtual AcDbDataTable& operator=(const AcDbDataTable& table);

	virtual Acad::ErrorStatus appendColumn(AcDbDataCell::CellType type,
										   const ACHAR* pColName = nullptr);
	virtual Acad::ErrorStatus appendRow(const AcDbDataCellArray& row, bool bValidate = true);
	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	virtual Acad::ErrorStatus getCellAt(uint32_t row, uint32_t col, AcDbDataCell& outCell) const;
	virtual Acad::ErrorStatus getColumnAt(uint32_t index, const AcDbDataColumn*& pCol) const;
	virtual Acad::ErrorStatus getColumnIndexAtName(const ACHAR* pName, uint32_t& index) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getColumnNameAt(uint32_t index,
															  AcString& sName) const;
	virtual Acad::ErrorStatus getColumnNameAt(uint32_t index, ACHAR*& pName) const final;
	virtual Acad::ErrorStatus getColumnTypeAt(uint32_t index, AcDbDataCell::CellType& type) const;
	virtual Acad::ErrorStatus getRowAt(uint32_t index, AcDbDataCellArray& outRow) const;
	virtual Acad::ErrorStatus insertColumnAt(uint32_t index, AcDbDataCell::CellType type,
											 const ACHAR* pColName = nullptr);
	virtual Acad::ErrorStatus insertRowAt(uint32_t index, const AcDbDataCellArray& row,
										  bool bValidate = true);
	virtual uint32_t numColsGrowSize() const;
	virtual uint32_t numColsPhysicalSize() const;
	virtual uint32_t numColumns() const;
	virtual uint32_t numRows() const;
	virtual uint32_t numRowsGrowSize() const;
	virtual uint32_t numRowsPhysicalSize() const;
	virtual Acad::ErrorStatus removeColumnAt(uint32_t index);
	virtual Acad::ErrorStatus removeRowAt(uint32_t index);
	virtual Acad::ErrorStatus setCellAt(uint32_t row, uint32_t col, const AcDbDataCell& cell);
	virtual Acad::ErrorStatus setNumColsGrowSize(uint32_t n);
	virtual Acad::ErrorStatus setNumColsPhysicalSize(uint32_t n);
	virtual Acad::ErrorStatus setNumRowsGrowSize(uint32_t n);
	virtual Acad::ErrorStatus setNumRowsPhysicalSize(uint32_t n);
	virtual Acad::ErrorStatus setRowAt(uint32_t index, const AcDbDataCellArray& row,
									   bool bValidate = true);
	virtual Acad::ErrorStatus setTableName(const ACHAR* pName);
	virtual const ACHAR* tableName() const;
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbDataTable::getColumnNameAt(uint32_t index, ACHAR*& pName) const
{
	AcString sName;
	return ::acutAcStringToAChar(sName, pName, this->getColumnNameAt(index, sName));
}
