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
***     Description: Declaration of AcDbBlockBegin, AcDbBlockEnd classes
***
*****************************************************************************/
#pragma once

#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbBlockBegin : public AcDbEntity
{
public:
	AcDbBlockBegin();
	~AcDbBlockBegin();
	ACDB_DECLARE_MEMBERS(AcDbBlockBegin);
};

class AcDbBlockEnd : public AcDbEntity
{
public:
	AcDbBlockEnd();
	~AcDbBlockEnd();
	ACDB_DECLARE_MEMBERS(AcDbBlockEnd);
};

#include "IcArxPackPop.h"
