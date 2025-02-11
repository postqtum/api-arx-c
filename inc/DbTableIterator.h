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
***     Description: Declaration of AcDbTableIterator class
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbEnumTable.h"

struct AcCell;
struct AcCellRange;
class AcDbTable;
class AcDbLinkedTableData;

#include "icarx/IcArxPackPush.h"

class AcDbTableIterator
{
protected:
	void* mpImpObj;

protected:
	AcDbTableIterator();

	AcDbTableIterator(const AcDbTableIterator&) = delete;
	AcDbTableIterator& operator=(const AcDbTableIterator&) = delete;

public:
	AcDbTableIterator(const AcDbTable* pTable);
	AcDbTableIterator(const AcDbTable* pTable, const AcCellRange* pRange,
					  AcDb::TableIteratorOption nOption);
	AcDbTableIterator(const AcDbLinkedTableData* pTable);
	AcDbTableIterator(const AcDbLinkedTableData* pTable, const AcCellRange* pRange,
					  AcDb::TableIteratorOption nOption);
	AcDbTableIterator(const AcCellRange& range);
	AcDbTableIterator(const AcCellRange& range, AcDb::TableIteratorOption nOption);
	~AcDbTableIterator();

	bool done();
	const AcCell& getCell() const;
	int getColumn() const;
	int getRow() const;
	bool seek(const AcCell& cell);
	void start();
	void step();
};

#include "icarx/IcArxPackPop.h"
