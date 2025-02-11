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
***     Description: Declaration of AcDbSortentsTable class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbSortentsTable : public AcDbObject
{
	friend class AcDbSystemInternals;

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACRX_DECLARE_MEMBERS(AcDbSortentsTable);

	AcDbSortentsTable();
	~AcDbSortentsTable();

	Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*, AcRxClass*);
	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo);
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
	Acad::ErrorStatus firstEntityIsDrawnBeforeSecond(AcDbObjectId first, AcDbObjectId second,
													 bool& result) const;
	Acad::ErrorStatus getFullDrawOrder(AcDbObjectIdArray& ents,
									   uint8_t honorSortentsMask = 0) const;
	Acad::ErrorStatus getRelativeDrawOrder(AcDbObjectIdArray& ar,
										   uint8_t honorSortentsMask = 0) const;
	Acad::ErrorStatus moveAbove(const AcDbObjectIdArray& ar, AcDbObjectId target);
	Acad::ErrorStatus moveBelow(const AcDbObjectIdArray& ar, AcDbObjectId target);
	Acad::ErrorStatus moveToBottom(const AcDbObjectIdArray& ar);
	Acad::ErrorStatus moveToTop(const AcDbObjectIdArray& ar);
	Acad::ErrorStatus remove(AcDbObjectId);
	Acad::ErrorStatus setBlockId(AcDbObjectId);
	Acad::ErrorStatus setRelativeDrawOrder(const AcDbObjectIdArray& ar);
	Acad::ErrorStatus swapOrder(AcDbObjectId, AcDbObjectId);
	AcDbObjectId blockId() const;
	bool sortAs(AcDbObjectId, AcDbHandle&) const;
	void getSortHandle(AcDbObjectId id, AcDbHandle& h) const;
};

#include "icarx/IcArxPackPop.h"
