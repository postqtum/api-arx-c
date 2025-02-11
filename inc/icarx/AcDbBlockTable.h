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
#include "AcDbBlockTableRecord.h"
#include "AcDbSymbolTableIterator.h"

class AcDbBlockTableIterator;

#include "IcArxPackPush.h"

class AcDbBlockTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbBlockTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbBlockTable);

	AcDbBlockTable();
	~AcDbBlockTable();

	Acad::ErrorStatus add(AcDbBlockTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbBlockTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbBlockTableRecord*& pRec,
							AcDb::OpenMode openMode = AcDb::kForRead,
							bool openErasedRec = false) const
	{
		return this->openAt(entryName, pRec, openMode, openErasedRec);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbObjectId& recordId,
							bool getErasedRec = false) const
	{
		return this->getIdAt(entryName, recordId, getErasedRec);
	}
	Acad::ErrorStatus newIterator(AcDbBlockTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbBlockTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbBlockTable;

protected:
	AcDbBlockTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbBlockTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
