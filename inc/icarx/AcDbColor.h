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
***     Description: Declaration of AcDbColor class
***
*****************************************************************************/
#pragma once

#include "AcCmEntityColor.h"
#include "AcCmColor.h"
#include "AcDbObject.h"

#include "IcArxPackPush.h"


class AcDbColor : public AcDbObject
{
private:
	AcCmColor m_color;
	AcCmEntityColor m_ecol;

protected:
	Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject, AcDbObject*& pClonedObject,
									 AcDbIdMapping& idMap, bool isPrimary = true) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbColor);

	AcDbColor();
	~AcDbColor();

	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	const AcCmEntityColor& entityColor(void) const;
	void getColor(AcCmColor& color) const;
	void setColor(const AcCmColor& color);
};

#include "IcArxPackPop.h"
