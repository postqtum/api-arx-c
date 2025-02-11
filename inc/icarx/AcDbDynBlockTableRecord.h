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
***     Description: Declaration of AcDbDynBlockTableRecord class
***
*****************************************************************************/
#pragma once

#include "../dbeval.h"

class AcDbImpDynBlockTableRecord;

#include "IcArxPackPush.h"

class AcDbDynBlockTableRecord : public AcHeapOperators
{
private:
	AcDbImpDynBlockTableRecord* mpImp;

private:
	AcDbDynBlockTableRecord();

	AcDbDynBlockTableRecord(const AcDbDynBlockTableRecord&) = delete;
	AcDbDynBlockTableRecord& operator=(const AcDbDynBlockTableRecord&) = delete;

public:
	ACDBCORE2D_PORT AcDbDynBlockTableRecord(AcDbObjectId blockTableRecordId);
	ACDBCORE2D_PORT virtual ~AcDbDynBlockTableRecord();

	ACDBCORE2D_PORT AcDbObjectId blockTableRecordId() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getAnonymousBlockIds(AcDbObjectIdArray& anonymousIds) const;
	ACDBCORE2D_PORT bool isDynamicBlock() const;
	ACDBCORE2D_PORT Acad::ErrorStatus updateAnonymousBlocks() const;
};

#include "IcArxPackPop.h"
