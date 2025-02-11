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
***     Description: Declaration of AcDbDimStyleTable, AcDbDimStyleTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbSymbolTableIterator.h"
#include "AcDbDimStyleTableRecord.h"

class AcDbDimStyleTableIterator;

#include "IcArxPackPush.h"

class AcDbDimStyleTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbDimStyleTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbDimStyleTable);

	AcDbDimStyleTable();
	~AcDbDimStyleTable();

	Acad::ErrorStatus add(AcDbDimStyleTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbDimStyleTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbDimStyleTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbDimStyleTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbDimStyleTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbDimStyleTable;

protected:
	AcDbDimStyleTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbDimStyleTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
