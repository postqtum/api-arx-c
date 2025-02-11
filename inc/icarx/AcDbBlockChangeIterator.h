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
***     Description: Declaration of AcDbBlockChangeIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbIndexUpdateDataIterator.h"

class AcDbIndexUpdateData;

#include "IcArxPackPush.h"

class AcDbBlockChangeIterator
{
	friend class AcDbImpDatabase;

private:
	AcDbIndexUpdateData* mpIds;
	AcDbObjectId mBTRId;
	AcDbIndexUpdateDataIterator* mpIter;

private:
	AcDbBlockChangeIterator();
	AcDbBlockChangeIterator(AcDbObjectId btrId, AcDbIndexUpdateData* pIdxUpdData);
	~AcDbBlockChangeIterator();

	AcDbBlockChangeIterator(const AcDbBlockChangeIterator&) = delete;
	AcDbBlockChangeIterator& operator=(const AcDbBlockChangeIterator&) = delete;

public:
	void clearProcessedFlags();
	Acad::ErrorStatus curIdInfo(AcDbObjectId& id, uint8_t& flags,
								IcArx::Integers::ULongPtr& data) const;
	bool done();
	AcDbObjectId id() const;
	void next();
	Acad::ErrorStatus setCurIdInfo(uint8_t flags, IcArx::Integers::ULongPtr data);
	void start();
	AcDbIndexUpdateData* updateData() const;
};

#include "IcArxPackPop.h"
