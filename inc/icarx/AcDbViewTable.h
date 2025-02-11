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
***     Description: Declaration of AcDbViewTable, AcDbViewTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbAbstractViewTable.h"
#include "AcDbViewTableRecord.h"

class AcDbViewTableIterator;

#include "IcArxPackPush.h"

class AcDbViewTable : public AcDbAbstractViewTable
{
public:
	using RecordType = AcDbViewTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbViewTable);

	AcDbViewTable();
	~AcDbViewTable();

	Acad::ErrorStatus add(AcDbViewTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbViewTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbViewTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbViewTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbViewTableIterator : public AcDbAbstractViewTableIterator
{
	friend class AcDbViewTable;

protected:
	AcDbViewTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbViewTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
