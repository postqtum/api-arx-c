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
***     Description: Declaration of AcDbBlockTableRecord, AcDbBlockTableRecordIterator classes
***
*****************************************************************************/
#pragma once

#include "acut_str_util.h"
#include "AcDbSymbolTableRecord.h"
#include "../gepnt3d.h"

class AcDbBlockTable;
class AcDbBlockTableRecordIterator;
class AcDbBlockReferenceIdIterator;
class AcDbSortentsTable;
class AcDbBlockBegin;
class AcDbBlockEnd;

#include "IcArxPackPush.h"

class AcDbBlockTableRecord : public AcDbSymbolTableRecord
{
public:
	using TableType = AcDbBlockTable;
	using PreviewIcon = AcArray<uint8_t>;

	enum BlockScaling
	{
		kAny,
		kUniform
	};

protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDBCORE2D_DECLARE_MEMBERS(AcDbBlockTableRecord);

	ACDBCORE2D_PORT AcDbBlockTableRecord();
	~AcDbBlockTableRecord();

	Acad::ErrorStatus addAnnoScalestoBlkRefs(bool bScale = false);
	Acad::ErrorStatus appendAcDbEntity(AcDbEntity* pEntity)
	{
		AcDbObjectId id;
		return this->appendAcDbEntity(id, pEntity);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus appendAcDbEntity(AcDbObjectId& pOutputId,
													   AcDbEntity* pEntity);
	virtual Acad::ErrorStatus assumeOwnershipOf(const AcDbObjectIdArray& entitiesToMove);
	AcDb::UnitsValue blockInsertUnits() const;
	AcDbBlockTableRecord::BlockScaling blockScaling() const;
	Acad::ErrorStatus comments(ACHAR*& pString) const;
	Acad::ErrorStatus comments(const ACHAR*& pString) const;
	ACDBCORE2D_PORT Acad::ErrorStatus comments(AcString& sComments) const;
	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	AcGiDrawable* drawable() override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const override;
	bool explodable() const;
	Acad::ErrorStatus getBlockReferenceIds(AcDbObjectIdArray& ids, bool bDirectOnly = true,
										   bool bForceValidity = false) const;
	Acad::ErrorStatus getErasedBlockReferenceIds(AcDbObjectIdArray&);
	AcDbObjectId getLayoutId() const;
	Acad::ErrorStatus getPreviewIcon(PreviewIcon& previewIcon) const;
	Acad::ErrorStatus getSortentsTable(AcDbSortentsTable*& pSortents,
									   AcDb::OpenMode openMode = AcDb::kForRead,
									   bool createIfNecessary = false);
	bool hasAttributeDefinitions() const;
	bool hasPreviewIcon() const;
	bool isAnonymous() const;
	bool isFromExternalReference() const;
	bool isFromOverlayReference() const;
	bool isLayout() const;
	bool isUnloaded() const;
	Acad::ErrorStatus newBlockReferenceIdIterator(AcDbBlockReferenceIdIterator*& pIter) const;
	Acad::ErrorStatus newIterator(AcDbBlockTableRecordIterator*& pIterator, bool atBeginning = true,
								  bool skipDeleted = true) const;
	Acad::ErrorStatus openBlockBegin(AcDbBlockBegin*& pBlockBegin,
									 AcDb::OpenMode openMode = AcDb::kForRead);
	Acad::ErrorStatus openBlockEnd(AcDbBlockEnd*& pBlockEnd,
								   AcDb::OpenMode openMode = AcDb::kForRead);
	AcGePoint3d origin() const;
	Acad::ErrorStatus pathName(ACHAR*& pPath) const;
	Acad::ErrorStatus pathName(const ACHAR*& pPath) const;
	ACDBCORE2D_PORT Acad::ErrorStatus pathName(AcString& sPath) const;
	Acad::ErrorStatus postProcessAnnotativeBTR(int& stripCnt, bool bqueryOnly = false,
											   bool bScale = true);
	Acad::ErrorStatus setBlockInsertUnits(AcDb::UnitsValue insunits);
	Acad::ErrorStatus setBlockScaling(AcDbBlockTableRecord::BlockScaling blockScaling);
	Acad::ErrorStatus setComments(const ACHAR* pString);
	Acad::ErrorStatus setExplodable(bool bExplodable);
	Acad::ErrorStatus setIsFromOverlayReference(bool bIsOverlay);
	Acad::ErrorStatus setIsUnloaded(bool isUnloaded);
	Acad::ErrorStatus setLayoutId(AcDbObjectId);
	Acad::ErrorStatus setOrigin(const AcGePoint3d& pt);
	Acad::ErrorStatus setPathName(const ACHAR* pathStr);
	Acad::ErrorStatus setPreviewIcon(const PreviewIcon& previewIcon);
	AcDbDatabase* xrefDatabase(bool incUnres = false) const;
	AcDb::XrefStatus xrefStatus() const;
};

class AcDbImpBlockTableRecordIterator;

class AcDbBlockTableRecordIterator
{
	friend class AcDbImpBlockTableRecord;

protected:
	AcDbImpBlockTableRecordIterator* mpImp = nullptr;

private:
	AcDbBlockTableRecordIterator();

	AcDbBlockTableRecordIterator(const AcDbBlockTableRecordIterator&) = delete;
	AcDbBlockTableRecordIterator& operator=(const AcDbBlockTableRecordIterator&) = delete;

public:
	virtual ~AcDbBlockTableRecordIterator();

	AcDbBlockTableRecord* blockTableRecord() const;
	bool done() const;
	Acad::ErrorStatus getEntity(AcDbEntity*& pEntity, AcDb::OpenMode openMode = AcDb::kForRead,
								bool openErasedEntity = false) const;
	Acad::ErrorStatus getEntityId(AcDbObjectId& entityId) const;
	ACDBCORE2D_PORT Acad::ErrorStatus seek(AcDbObjectId id);
	ACDBCORE2D_PORT Acad::ErrorStatus seek(const AcDbEntity* pEntity);
	void start(bool atBeginning = true, bool skipDeleted = true);
	void step(bool forward = true, bool skipDeleted = true);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcDbBlockTableRecord::comments(ACHAR*& pComments) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbBlockTableRecord::comments, pComments);
}
inline Acad::ErrorStatus AcDbBlockTableRecord::pathName(ACHAR*& pPath) const
{
	return ::acutGetAcStringConvertToAChar(this, &AcDbBlockTableRecord::pathName, pPath);
}
