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
***     Description: Declaration of AcDbBreakData class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"

class AcDbBreakPointRef;

#include "IcArxPackPush.h"

class AcDbBreakData : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbBreakData);

	AcDbBreakData();
	~AcDbBreakData();

	Acad::ErrorStatus addBreakPointRef(AcDbBreakPointRef* ptRef);
	Acad::ErrorStatus deleteAllBreakPointRefs();
	AcDbObjectId dimObjId() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
	Acad::ErrorStatus eraseFromDb();
	Acad::ErrorStatus getBreakPointRef(int lineIndex, AcArray<AcDbBreakPointRef*>& ptRefs) const;
	Acad::ErrorStatus getBreakPointRef(AcArray<AcDbBreakPointRef*>& ptRefs) const;
	void modifiedGraphics(const AcDbEntity* pEnt) override;
	Acad::ErrorStatus postToDb(AcDbObjectId& breakObjId);
	Acad::ErrorStatus removeAssociativity(bool force = true);
	Acad::ErrorStatus setDimObjId(const AcDbObjectId& dimId);
	Acad::ErrorStatus updateAssociativity(const AcDbObjectIdArray& ids, int cmdType);
};

#include "IcArxPackPop.h"
