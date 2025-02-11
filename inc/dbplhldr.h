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
***     Description: Declaration of AcDbPlaceHolder class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbPlaceHolder : public AcDbObject
{
protected:
	Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									 AcDbIdMapping& idMap, bool isPrimary = true) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbPlaceHolder);

	AcDbPlaceHolder();
	~AcDbPlaceHolder();

	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
};

#include "icarx/IcArxPackPop.h"
