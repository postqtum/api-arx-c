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
***     Description: Declaration of AcDbGroup class
***
*****************************************************************************/
#pragma once

#include "AcDbGroupIterator.h"

#include "IcArxPackPush.h"

class AcDbGroup : public AcDbObject
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbGroup);

	AcDbGroup();
	AcDbGroup(const ACHAR* grpDesc, bool selectable = true);
	~AcDbGroup();

	uint32_t allEntityIds(AcDbObjectIdArray& ids) const;
	Acad::ErrorStatus append(AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus append(const AcDbObjectIdArray& ids);
	Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* undoFiler, AcRxClass* classObj) override;
	Acad::ErrorStatus clear();
	const ACHAR* description() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	void erased(const AcDbObject* dbObj, bool erasing) override;
	Acad::ErrorStatus getIndex(AcDbObjectId id, uint32_t& idx) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getName(ACHAR*& pName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getName(const ACHAR*& pName) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getName(AcString& sName) const;
	void goodbye(const AcDbObject* dbObj) override;
	bool has(const AcDbEntity* pEntity) const;
	Acad::ErrorStatus insertAt(uint32_t idx, AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus insertAt(uint32_t idx, const AcDbObjectIdArray& ids);
	bool isAnonymous() const;
	bool isNotAccessible() const;
	bool isSelectable() const;
	const wchar_t* name() const
	{
		const wchar_t* pName;
		if (this->getName(pName) != Acad::eOk)
			pName = nullptr;
		return pName;
	}
	AcDbGroupIterator* newIterator();
	uint32_t numEntities() const;
	Acad::ErrorStatus prepend(AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus prepend(const AcDbObjectIdArray& ids);
	Acad::ErrorStatus remove(AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus remove(const AcDbObjectIdArray& ids);
	Acad::ErrorStatus removeAt(uint32_t idx);
	ACDBCORE2D_PORT Acad::ErrorStatus removeAt(uint32_t idx, const AcDbObjectIdArray& ids);
	Acad::ErrorStatus replace(AcDbObjectId oldId, AcDbObjectId newId);
	Acad::ErrorStatus reverse();
	Acad::ErrorStatus setAnonymous();
	Acad::ErrorStatus setColor(const AcCmColor& color);
	Acad::ErrorStatus setColorIndex(uint16_t color);
	Acad::ErrorStatus setDescription(const ACHAR* grpDesc);
	Acad::ErrorStatus setHighlight(bool newVal);
	Acad::ErrorStatus setLayer(const ACHAR* newVal);
	Acad::ErrorStatus setLayer(AcDbObjectId newVal);
	Acad::ErrorStatus setLinetype(const ACHAR* newVal);
	Acad::ErrorStatus setLinetype(AcDbObjectId newVal);
	Acad::ErrorStatus setLinetypeScale(double newval);
	Acad::ErrorStatus setMaterial(const ACHAR* newVal);
	Acad::ErrorStatus setMaterial(AcDbObjectId newVal);
	Acad::ErrorStatus setName(const ACHAR* newName);
	Acad::ErrorStatus setSelectable(bool selectable);
	Acad::ErrorStatus setVisibility(AcDb::Visibility newVal);
	Acad::ErrorStatus subClose() override;
	Acad::ErrorStatus subErase(bool erasing) override;
	Acad::ErrorStatus transfer(uint32_t fromIndex, uint32_t toIndex,
							   uint32_t numItems);
};

#include "IcArxPackPop.h"
