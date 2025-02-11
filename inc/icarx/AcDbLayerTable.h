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
***     Description: Declaration of AcDbLayerTable and AcDbLayerTableIterator classes
***
*****************************************************************************/
#pragma once

#include "AcDbSymbolTable.h"
#include "AcDbSymbolTableIterator.h"
#include "AcDbLayerTableRecord.h"

class AcDbLayerTableIterator;

#include "IcArxPackPush.h"

class AcDbLayerTable : public AcDbSymbolTable
{
public:
	using RecordType = AcDbLayerTableRecord;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLayerTable);

	AcDbLayerTable();
	~AcDbLayerTable();

	Acad::ErrorStatus add(AcDbLayerTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(pRecord);
	}
	Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbLayerTableRecord* pRecord)
	{
		return this->AcDbSymbolTable::add(recordId, pRecord);
	}
	void generateUsageData();
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbLayerTableRecord*& pRec,
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
	Acad::ErrorStatus getUnreconciledLayers(AcDbObjectIdArray& idArray) const;
	bool hasUnreconciledLayers() const;
	Acad::ErrorStatus newIterator(AcDbLayerTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

class AcDbLayerTableIterator : public AcDbSymbolTableIterator
{
	friend class AcDbLayerTable;

protected:
	AcDbLayerTableIterator();

public:
	Acad::ErrorStatus getRecord(AcDbLayerTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
	bool getSkipHidden() const;
	bool getSkipReconciled() const;
	void setSkipHidden(bool value);
	void setSkipReconciled(bool value);
};

#include "IcArxPackPop.h"
