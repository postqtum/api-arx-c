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
***     Description: Declaration of AcDbSymbolTableRecord class
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbObject.h"
#include "../AcString.h"

class AcDbSymbolTable;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbSymbolTableRecord : public AcDbObject
{
public:
	using TableType = AcDbSymbolTable;

public:
	ACDB_DECLARE_MEMBERS(AcDbSymbolTableRecord);

	AcDbSymbolTableRecord();
	~AcDbSymbolTableRecord();

	Acad::ErrorStatus getName(ACHAR*& pName) const;
	Acad::ErrorStatus getName(AcString& sName) const;
	Acad::ErrorStatus getName(const ACHAR*& pName) const;
	ACDBCORE2D_PORT bool isDependent() const;
	ACDBCORE2D_PORT bool isRenamable() const;
	bool isResolved() const;
	ACDBCORE2D_PORT	Acad::ErrorStatus setName(const ACHAR* pName);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbSymbolTableRecord::getName(ACHAR*& pName) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbSymbolTableRecord::getName, pName);
}
