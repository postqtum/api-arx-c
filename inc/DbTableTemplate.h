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
***     Description: Declaration of AcDbTableTemplate class
***
*****************************************************************************/
#pragma once

#include "DbTableContent.h"

class AcDbTable;

#include "icarx/IcArxPackPush.h"

class AcDbTableTemplate : public AcDbTableContent
{
public:
	ACDB_DECLARE_MEMBERS(AcDbTableTemplate);

	AcDbTableTemplate();
	AcDbTableTemplate(const AcDbTable* pTable, AcDb::TableCopyOption nCopyOption);
	~AcDbTableTemplate();

	virtual Acad::ErrorStatus capture(const AcDbTable* pTable, AcDb::TableCopyOption nCopyOption);
	virtual Acad::ErrorStatus createTable(AcDbTable*& pTable, AcDb::TableCopyOption nCopyOption);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
};

#include "icarx/IcArxPackPop.h"
