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
***     Description: Declaration of AcDbLinkedData class
***
*****************************************************************************/
#pragma once

#include "AcValue.h"
#include "DbDataLink.h"

#include "icarx/IcArxPackPush.h"

class AcDbLinkedData : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbLinkedData);

	ACDB_PORT AcDbLinkedData();
	ACDB_PORT ~AcDbLinkedData();

	ACDB_PORT virtual Acad::ErrorStatus clear();
	ACDB_PORT virtual const ACHAR* description() const;
	ACDB_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDB_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDB_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDB_PORT virtual bool isEmpty() const;
	ACDB_PORT virtual const ACHAR* name() const;
	ACDB_PORT virtual Acad::ErrorStatus setDescription(const ACHAR* pszDescription);
	ACDB_PORT virtual Acad::ErrorStatus setName(const ACHAR* pszName);
};

#include "icarx/IcArxPackPop.h"

typedef AcArray<AcDbLinkedData*> AcDbDataArray;
