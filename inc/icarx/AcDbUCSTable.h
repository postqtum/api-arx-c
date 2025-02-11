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
***     Description: Declaration of AcDbUCSTable, AcDbUCSTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbUCSTableRecord.h"
#include "AcDbSymbolTableIterator.h"

class AcDbUCSTableIterator;

#include "IcArxPackPush.h"

class AcDbUCSTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbUCSTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbUCSTable);

	AcDbUCSTable();
	~AcDbUCSTable();

	Acad::ErrorStatus add(AcDbUCSTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbUCSTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbUCSTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbUCSTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbUCSTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbUCSTable;

protected:
	AcDbUCSTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbUCSTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
