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
***     Description: Declaration of AcDbIndexUpdateData class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcDbIndexUpdateData
{
	friend class AcDbIndexUpdateDataIterator;
	friend class AcDbHandleTable;

public:
	enum UpdateFlags
	{
		kModified = 1,
		kDeleted = 2,
		kProcessed = 4,
		kUnknownKey = 8
	};

private:
	AcDbHandleTable* mpTable;

private:
	AcDbIndexUpdateData();
	~AcDbIndexUpdateData();
	AcDbIndexUpdateData(const AcDbIndexUpdateData&) = delete;
	AcDbIndexUpdateData& operator=(const AcDbIndexUpdateData&) = delete;

public:
	Acad::ErrorStatus addId(AcDbObjectId id);
	Acad::ErrorStatus getFlagsAndData(AcDbObjectId id, uint8_t& flags,
									  IcArx::Integers::ULongPtr& data) const;
	Acad::ErrorStatus getIdData(AcDbObjectId id, IcArx::Integers::ULongPtr& data) const;
	Acad::ErrorStatus getIdFlags(AcDbObjectId id, uint8_t& flags) const;
	Acad::ErrorStatus setIdData(AcDbObjectId id, IcArx::Integers::ULongPtr data);
	Acad::ErrorStatus setIdFlags(AcDbObjectId id, uint8_t flags);
};

#include "IcArxPackPop.h"
