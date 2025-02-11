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
***     Description: Declaration of AcDbAbstractViewTable, AcDbAbstractViewTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbAbstractViewTableRecord.h"
#include "AcDbSymbolTableIterator.h"

class AcDbAbstractViewTableIterator;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbAbstractViewTable : public AcDbSymbolTable
{
public:
	ACDB_DECLARE_MEMBERS(AcDbAbstractViewTable);

	AcDbAbstractViewTable();
	~AcDbAbstractViewTable();

	Acad::ErrorStatus add(AcDbAbstractViewTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbAbstractViewTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbAbstractViewTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbAbstractViewTableIterator*& pIterator,
								  bool atBeginning = true, bool skipDeleted = true) const;
};

class AcDbAbstractViewTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbAbstractViewTable;

protected:
	AcDbAbstractViewTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbAbstractViewTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
