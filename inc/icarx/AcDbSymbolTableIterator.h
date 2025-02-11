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
***     Description: Declaration of AcDbSymbolTableIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbObject.h"
#include "AcDbSymbolTableRecord.h"
#include "AcDbEnumMode.h"

class AcDbImpSymbolTableIterator;

#include "IcArxPackPush.h"

class AcDbSymbolTableIterator
{
	friend class AcDbSymbolTable;

protected:
	AcDbImpSymbolTableIterator* mpImp;

protected:
	template<class RecordType>
	Acad::ErrorStatus openRecord(RecordType*& pRec, AcDb::OpenMode nMode, bool bOpenErased) const
	{
		pRec = nullptr;
		AcDbObjectId id;
		Acad::ErrorStatus es = this->getRecordId(id);
		if (es == Acad::eOk)
			es = ::acdbOpenObject(pRec, id, nMode, bOpenErased);
		return es;
	}

	AcDbSymbolTableIterator();

public:
	virtual ~AcDbSymbolTableIterator();

	bool done() const;
	Acad::ErrorStatus getRecord(AcDbSymbolTableRecord*& pRecord,
								AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedRec = false) const
	{
		return this->openRecord(pRecord, openMode, openErasedRec);
	}
	Acad::ErrorStatus getRecordId(AcDbObjectId& id) const;
	ACDBCORE2D_PORT Acad::ErrorStatus seek(AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus seek(const AcDbSymbolTableRecord* pRecord);
	void start(bool atBeginning = true, bool skipDeleted = true);
	void step(bool forward = true, bool skipDeleted = true);
};

#include "IcArxPackPop.h"
