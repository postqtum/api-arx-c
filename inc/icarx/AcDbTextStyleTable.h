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
***     Description: Declaration of AcDbBlockTable, AcDbBlockTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbTextStyleTableRecord.h"
#include "AcDbSymbolTableIterator.h"

class AcDbTextStyleTableIterator;

#include "IcArxPackPush.h"

class AcDbTextStyleTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbTextStyleTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbTextStyleTable);

	AcDbTextStyleTable();
	~AcDbTextStyleTable();

	Acad::ErrorStatus add(AcDbTextStyleTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbTextStyleTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbTextStyleTableRecord*& pRec,
							AcDb::OpenMode openMode = AcDb::kForRead,
							bool openErasedRec = false) const
	{
		return this->openAt(entryName, pRec, openMode, openErasedRec);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbObjectId& recordId,
							bool getErasedRecord = false) const
	{
		return this->getIdAt(entryName, recordId, getErasedRecord);
	}
	Acad::ErrorStatus newIterator(AcDbTextStyleTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbTextStyleTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbTextStyleTable;

protected:
	AcDbTextStyleTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbTextStyleTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
