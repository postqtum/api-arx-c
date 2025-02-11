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
***     Description: Declaration of AcDbDataColumn class
***
*****************************************************************************/
#pragma once

#include "AcDbDataCell.h"

class AcDbImpDataColumn;

#include "IcArxPackPush.h"
#pragma warning(disable : 4275 4251)

class AcDbDataColumn : public AcRxObject
{
	friend class AcDbSystemInternals;
	friend class AcDbImpDataColumn;

private:
	AcDbImpDataColumn* mpImpDataColumn;

public:
	AcDbDataColumn();
	AcDbDataColumn(const AcDbDataColumn& rCol);
	AcDbDataColumn(const AcDbDataCell::CellType type, const ACHAR* pColName = nullptr);
	~AcDbDataColumn();
	virtual AcDbDataColumn& operator=(const AcDbDataColumn& col);

	ACRX_DECLARE_MEMBERS(AcDbDataColumn);

	virtual Acad::ErrorStatus appendCell(const AcDbDataCell& cell);
	virtual const ACHAR* columnName() const;
	virtual AcDbDataCell::CellType columnType() const;
	virtual Acad::ErrorStatus getCellAt(uint32_t index, AcDbDataCell& outCell) const;
	virtual Acad::ErrorStatus getIndexAtCell(const AcDbDataCell& cell, uint32_t& index) const;
	virtual uint32_t growLength() const;
	virtual Acad::ErrorStatus insertCellAt(uint32_t index, const AcDbDataCell& cell);
	virtual uint32_t numCells() const;
	virtual uint32_t physicalLength() const;
	virtual Acad::ErrorStatus removeCellAt(uint32_t index);
	virtual Acad::ErrorStatus setCellAt(uint32_t index, const AcDbDataCell& cell);
	virtual Acad::ErrorStatus setColumnName(const ACHAR* pName);
	virtual Acad::ErrorStatus setColumnType(AcDbDataCell::CellType type);
	virtual Acad::ErrorStatus setGrowLength(uint32_t n);
	virtual Acad::ErrorStatus setPhysicalLength(uint32_t n);
};

#include "IcArxPackPop.h"
