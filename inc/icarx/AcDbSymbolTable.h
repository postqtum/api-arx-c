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
***     Description: Declaration of AcDbSymbolTable class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbObject.h"
#include "AcDbSymbolTableRecord.h"
#include "AcDbEnumMode.h"

class AcDbSymbolTableIterator;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbSymbolTable : public AcDbObject
{
public:
	using RecordType = AcDbSymbolTableRecord;

protected:
	template<class RecordType>
	Acad::ErrorStatus openAt(const ACHAR* entryName, RecordType*& pRec, AcDb::OpenMode nMode,
							 bool bOpenErased) const
	{
		pRec = nullptr;
		AcDbObjectId id;
		Acad::ErrorStatus es = this->getIdAt(entryName, id, bOpenErased);
		if (es == Acad::eOk)
			es = ::acdbOpenObject(pRec, id, nMode, bOpenErased);
		return es;
	}

public:
	ACDB_DECLARE_MEMBERS(AcDbSymbolTable);

	AcDbSymbolTable();
	~AcDbSymbolTable();

	Acad::ErrorStatus add(AcDbSymbolTableRecord* pRecord);
	ACDBCORE2D_PORT Acad::ErrorStatus add(AcDbObjectId& recordId, AcDbSymbolTableRecord* pRecord);
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbSymbolTableRecord*& pRec,
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
	ACDBCORE2D_PORT Acad::ErrorStatus getIdAt(const ACHAR* entryName, AcDbObjectId& recordId,
											  bool getErasedRecord = false) const;
	bool has(const ACHAR* name) const
	{
		AcDbObjectId id;
		this->assertReadEnabled();
		return this->getIdAt(name, id) == Acad::eOk;
	}
	ACDBCORE2D_PORT bool has(AcDbObjectId id) const;
	Acad::ErrorStatus newIterator(AcDbSymbolTableIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
};

#include "IcArxPackPop.h"
