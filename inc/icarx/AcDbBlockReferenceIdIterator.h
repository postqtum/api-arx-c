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
***     Description: Declaration of AcDbBlockReferenceIdIterator class
***
*****************************************************************************/
#pragma once

#include "../dbid.h"
#include "../dbidar.h"
#include "../acadstrc.h"
#include "AcDbEnumMode.h"

class AcDbBlockReference;

#include "IcArxPackPush.h"

class AcDbBlockReferenceIdIterator
{
	friend class AcDbBlockTableRecord;

private:
	int mPos = 0;
	AcDbObjectIdArray mAry;

private:
	AcDbBlockReferenceIdIterator() = default;

public:
	~AcDbBlockReferenceIdIterator() = default;

	bool done() const { return mPos >= mAry.length(); }
	Acad::ErrorStatus getBlockReference(AcDbBlockReference*& pBlkRef,
										AcDb::OpenMode openMode = AcDb::kForRead,
										bool openErasedEntity = false) const;
	Acad::ErrorStatus getBlockReferenceId(AcDbObjectId& id) const;
	Acad::ErrorStatus getDatabase(AcDbDatabase*& pDb) const;
	ACDBCORE2D_PORT Acad::ErrorStatus seek(AcDbObjectId id);
	void start() { mPos = 0; }
	void step() { mPos++; }
};

#include "IcArxPackPop.h"
