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
***     Description: Declaration of AcDbLinetypeTable, AcDbLinetypeTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbLinetypeTableRecord.h"
#include "AcDbSymbolTableIterator.h"

class AcDbLinetypeTableIterator;

#include "IcArxPackPush.h"

class AcDbLinetypeTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbLinetypeTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLinetypeTable);

	AcDbLinetypeTable();
	~AcDbLinetypeTable();

	Acad::ErrorStatus add(AcDbLinetypeTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbLinetypeTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbLinetypeTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbLinetypeTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbLinetypeTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbLinetypeTable;

protected:
	AcDbLinetypeTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbLinetypeTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
