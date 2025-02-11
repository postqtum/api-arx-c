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
***     Description: Declaration of AcDbRegAppTableRecord, AcDbRegAppTable, AcDbRegAppTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTableIterator.h"
#include "AcDbSymbolTableRecord.h"
#include "AcDbEnumType.h"
#include "AcDbSymbolTable.h"

class AcDbRegAppTable;
class AcDbRegAppTableIterator;

#include "IcArxPackPush.h"

class AcDbRegAppTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbRegAppTable;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbRegAppTableRecord);

	AcDbRegAppTableRecord();
	~AcDbRegAppTableRecord();
};

class AcDbRegAppTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbRegAppTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbRegAppTable);

	AcDbRegAppTable();
	~AcDbRegAppTable();

	Acad::ErrorStatus add(AcDbRegAppTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbRegAppTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbRegAppTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbRegAppTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbRegAppTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbRegAppTable;

protected:
	AcDbRegAppTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbRegAppTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
