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
***     Description: Declaration of AcDbViewportTable, AcDbAbstractViewTable classes
***
*****************************************************************************/
#pragma once

#include "AcDbAbstractViewTable.h"
#include "AcDbViewportTableRecord.h"

class AcDbViewportTableIterator;

#include "IcArxPackPush.h"

class AcDbViewportTable : public AcDbAbstractViewTable
{
public:
	using RecordType = AcDbViewportTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbViewportTable);

	AcDbViewportTable();
	~AcDbViewportTable();

	Acad::ErrorStatus add(AcDbViewportTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbViewportTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbViewportTableRecord*& pRec,
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
	Acad::ErrorStatus newIterator(AcDbViewportTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbViewportTableIterator : public AcDbAbstractViewTableIterator
{
	friend class AcDbViewportTable;

protected:
	AcDbViewportTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbViewportTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
};

#include "IcArxPackPop.h"
