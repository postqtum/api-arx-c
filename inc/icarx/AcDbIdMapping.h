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
***     Description: Declaration of AcDbIdMapping class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "AcDbIdPair.h"
#include "AcDbEnumClone.h"

class AcDbImpIdMapping;

#include "IcArxPackPush.h"

class AcDbIdMapping : public AcRxObject
{
	friend class AcDbSystemInternals;
	friend class AcDbImpIdMappingIter;

private:
	AcDbImpIdMapping* mpImp = nullptr;

public:
	AcDbIdMapping();
	~AcDbIdMapping();
	AcDbIdMapping(const AcDbIdMapping&) = delete;
	AcDbIdMapping& operator=(const AcDbIdMapping&) = delete;

	ACRX_DECLARE_MEMBERS(AcDbIdMapping);

	virtual Acad::ErrorStatus assign(const AcDbIdPair&);
	virtual bool change(const AcDbIdPair&);
	virtual bool compute(AcDbIdPair&) const;
	Acad::ErrorStatus copyFrom(const AcRxObject* other) override;
	AcDb::DeepCloneType deepCloneContext() const;
	virtual bool del(AcDbObjectId key);
	Acad::ErrorStatus destDb(AcDbDatabase*& db) const;
	AcDb::DuplicateRecordCloning duplicateRecordCloning() const;
	Acad::ErrorStatus origDb(AcDbDatabase*& db) const;
	Acad::ErrorStatus setDestDb(AcDbDatabase* db);
};

#include "IcArxPackPop.h"
