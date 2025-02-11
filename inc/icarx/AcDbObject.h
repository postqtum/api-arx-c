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
***     Description: Declaration of AcDbObject class
***
*****************************************************************************/
#pragma once

#include <guiddef.h>

#include "../AcDbCore2dDefs.h"
#include "../dbboiler.h"
#include "../drawable.h"
#include "../AcHeapOpers.h"
#include "../dbidar.h"
#include "../dbptrar.h"

#include "AcDbEnumMode.h"

class AcDbIdMapping;
class AcDbAuditInfo;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcGeMatrix3d;
class AcDbObjectReactor;
class AcDbEntity;
class AcDbField;
class AcDbDictionary;
class AcDbImpObject;
struct resbuf;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbObject
		: public AcGiDrawable
		, public AcHeapOperators
{
	friend class AcDbPropertiesOverrule;
	friend class AcDbObjectOverrule;

protected:
	AcDbImpObject* mpImpObject = nullptr;

protected:
	AcDbObject();
	AcDbObject(const AcDbObject&) = delete;
	AcDbObject& operator=(const AcDbObject&) = delete;

	ACDBCORE2D_PORT virtual Acad::ErrorStatus subDeepClone(AcDbObject* pOwnerObject,
														   AcDbObject*& pClonedObject,
														   AcDbIdMapping& idMap,
														   bool isPrimary = true) const;
	virtual Acad::ErrorStatus subGetClassID(CLSID* pClsid) const;
	ACDBCORE2D_PORT uint32_t subSetAttributes(AcGiDrawableTraits* pTraits) override;
	ACDBCORE2D_PORT void subViewportDraw(AcGiViewportDraw* pVd) override;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subWblockClone(AcRxObject* pOwnerObject,
															 AcDbObject*& pClonedObject,
															 AcDbIdMapping& idMap,
															 bool isPrimary = true) const;
	ACDBCORE2D_PORT bool subWorldDraw(AcGiWorldDraw* pWd) override;

public:
	ACDB_DECLARE_MEMBERS(AcDbObject);

	~AcDbObject();

	ACDBCORE2D_PORT Acad::ErrorStatus addPersistentReactor(AcDbObjectId objId);
	ACDBCORE2D_PORT Acad::ErrorStatus addReactor(AcDbObjectReactor* pReactor) const;
	virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* undoFiler, AcRxClass* classObj);
	void assertNotifyEnabled() const;
	void assertReadEnabled() const;
	void assertWriteEnabled(bool autoUndo = true, bool recordModified = true);
	virtual Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo);
	Acad::ErrorStatus cancel();
	ACDBCORE2D_PORT virtual void cancelled(const AcDbObject* dbObj);
	ACDBCORE2D_PORT AcRxObject* clone() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus close();
	Acad::ErrorStatus closeAndPage(bool onlyWhenClean = true);
	ACDBCORE2D_PORT virtual void copied(const AcDbObject* dbObj, const AcDbObject* newObj);
	ACDBCORE2D_PORT Acad::ErrorStatus copyFrom(const AcRxObject* pSrc) override;
	Acad::ErrorStatus createExtensionDictionary();
	ACDBCORE2D_PORT AcDbDatabase* database() const;
	AcDbDatabase* databaseToUse() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver,
															   AcDbObject*& replaceObj,
															   AcDbObjectId& replaceId,
															   bool& exchangeXData);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus deepClone(AcDbObject* pOwnerObject,
														AcDbObject*& pClonedObject,
														AcDbIdMapping& idMap,
														bool isPrimary = true) const final;
	template<typename CloneType>
	Acad::ErrorStatus deepClone(AcDbObject* pOwner, CloneType*& pClone, AcDbIdMapping& idMap,
								bool isPrimary = true) const
	{
		pClone = nullptr;
		AcDbObject* pNewObj = nullptr;
		const Acad::ErrorStatus es = this->deepClone(pOwner, pNewObj, idMap, isPrimary);
		if (es == Acad::eOk)
			pClone = CloneType::cast(pNewObj);
		return es;
	}
	void disableUndoRecording(bool disable);
	Acad::ErrorStatus downgradeOpen();
	Acad::ErrorStatus downgradeToNotify(bool wasWritable);
	virtual AcGiDrawable* drawable();
	Acad::ErrorStatus dwgIn(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	Acad::ErrorStatus dwgOut(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	Acad::ErrorStatus dxfIn(AcDbDxfFiler* pFiler);
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOut(AcDbDxfFiler* pFiler, bool bAllXdata,
											 const AcDbObjectIdArray* pRegAppIds) const;
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	Acad::ErrorStatus erase(bool erasing = true);
	ACDBCORE2D_PORT virtual void erased(const AcDbObject* dbObj, bool bErasing);
	AcDbObjectId extensionDictionary() const;
	void getAcDbHandle(AcDbHandle& handle) const;
	Acad::ErrorStatus getBinaryData(const ACHAR* key, int32_t& size, char*& data) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const final;
	Acad::ErrorStatus getField(const ACHAR* pszPropName, AcDbObjectId& fieldId) const;
	Acad::ErrorStatus getField(const ACHAR* pszPropName, AcDbField*& pField,
							   AcDb::OpenMode mode = AcDb::kForRead) const;
	AcDbObjectId getFieldDictionary(void) const;
	Acad::ErrorStatus getFieldDictionary(AcDbDictionary*& pFieldDict,
										 AcDb::OpenMode mode = AcDb::kForRead) const;
	Acad::ErrorStatus getObjectBirthVersion(AcDb::AcDbDwgVersion& ver,
											AcDb::MaintenanceReleaseVersion& maintVer);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getObjectSaveVersion(
			const AcDbDwgFiler* pFiler, AcDb::AcDbDwgVersion& ver,
			AcDb::MaintenanceReleaseVersion& maintVer);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getObjectSaveVersion(
			const AcDbDxfFiler* pFiler, AcDb::AcDbDwgVersion& ver,
			AcDb::MaintenanceReleaseVersion& maintVer);
	ACDBCORE2D_PORT virtual void goodbye(const AcDbObject* dbObj);
	Acad::ErrorStatus handOverTo(AcDbObject* newObject, bool keepXData = true,
								 bool keepExtDict = true);
	bool hasFields(void) const;
	ACDBCORE2D_PORT bool hasPersistentReactor(AcDbObjectId objId) const;
	ACDBCORE2D_PORT bool hasReactor(const AcDbObjectReactor* pReactor) const;
	bool hasSaveVersionOverride();
	ACDBCORE2D_PORT AcDbObjectId id() const override;
	AcDbDatabase* intendedDatabase() const;
	bool isAProxy() const;
	bool isAcDbObjectIdsInFlux() const;
	bool isCancelling() const;
	bool isEraseStatusToggled() const;
	bool isErased() const;
	bool isModified() const;
	bool isModifiedGraphics() const;
	bool isModifiedXData() const;
	bool isNewObject() const;
	bool isNotifyEnabled() const;
	bool isNotifying() const;
	ACDBCORE2D_PORT bool isPersistent() const override;
	ACDBCORE2D_PORT bool isReadEnabled() const;
	bool isReallyClosing() const;
	bool isTransactionResident() const;
	bool isUndoRecordingDisabled() const;
	bool isUndoing() const;
	bool isWriteEnabled() const;
	ACDBCORE2D_PORT virtual AcDb::DuplicateRecordCloning mergeStyle() const;
	ACDBCORE2D_PORT virtual void modified(const AcDbObject* dbObj);
	ACDBCORE2D_PORT virtual void modifiedGraphics(const AcDbEntity* dbEnt);
	ACDBCORE2D_PORT virtual void modifiedXData(const AcDbObject* dbObj);
	ACDBCORE2D_PORT virtual void modifyUndone(const AcDbObject* dbObj);
	ACDBCORE2D_PORT virtual void objectClosed(const AcDbObjectId objId);
	ACDBCORE2D_PORT AcDbObjectId objectId() const;
	ACDBCORE2D_PORT virtual void openedForModify(const AcDbObject* dbObj);
	ACDBCORE2D_PORT AcDbObjectId ownerId() const;
	ACDBCORE2D_PORT const AcDbVoidPtrArray* reactors() const;
	ACDBCORE2D_PORT virtual void reappended(const AcDbObject* dbObj);
	ACDBCORE2D_PORT virtual void recvPropagateModify(const AcDbObject* subObj);
	Acad::ErrorStatus releaseExtensionDictionary();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeField(AcDbObjectId fieldId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeField(const ACHAR* pszPropName,
														  AcDbObjectId& returnId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus removeField(const ACHAR* pszPropName);
	ACDBCORE2D_PORT Acad::ErrorStatus removePersistentReactor(AcDbObjectId objId);
	ACDBCORE2D_PORT Acad::ErrorStatus removeReactor(AcDbObjectReactor* pReactor) const;
	void setAcDbObjectIdsInFlux();
	Acad::ErrorStatus setBinaryData(const ACHAR* key, int32_t size, const char* data);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setField(const ACHAR* pszPropName, AcDbField* pField,
													   AcDbObjectId& fieldId);
	void setHasSaveVersionOverride(bool bSetIt);
	Acad::ErrorStatus setIntendedDatabase(AcDbDatabase* pDb);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setOwnerId(AcDbObjectId objId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setXData(const resbuf* xdata);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subCancel();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subClose();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subErase(bool erasing);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subHandOverTo(AcDbObject* newObject);
	ACDBCORE2D_PORT virtual void subObjModified(const AcDbObject* dbObj, const AcDbObject* subObj);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subOpen(AcDb::OpenMode mode);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus subSwapIdWith(AcDbObjectId otherId,
															bool swapXdata = false,
															bool swapExtDict = false);
	Acad::ErrorStatus swapIdWith(AcDbObjectId otherId, bool swapXdata = false,
								 bool swapExtDict = false);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus swapReferences(const AcDbIdMapping& idMap);
	ACDBCORE2D_PORT virtual void unappended(const AcDbObject* dbObj);
	AcDbDwgFiler* undoFiler();
	Acad::ErrorStatus upgradeFromNotify(bool& wasWritable);
	Acad::ErrorStatus upgradeOpen();
	ACDBCORE2D_PORT virtual Acad::ErrorStatus wblockClone(AcRxObject* pOwnerObject,
														  AcDbObject*& pClonedObject,
														  AcDbIdMapping& idMap,
														  bool isPrimary = true) const final;
	template<typename CloneType>
	Acad::ErrorStatus wblockClone(AcRxObject* pOwner, CloneType*& pClone, AcDbIdMapping& idMap,
								  bool isPrimary = true) const
	{
		pClone = nullptr;
		AcDbObject* pNewObj = nullptr;
		const Acad::ErrorStatus es = this->wblockClone(pOwner, pNewObj, idMap, isPrimary);
		if (es == Acad::eOk)
			pClone = CloneType::cast(pNewObj);
		return es;
	}
	ACDBCORE2D_PORT virtual resbuf* xData(const ACHAR* regappName = nullptr) const;
	Acad::ErrorStatus xDataTransformBy(const AcGeMatrix3d& xform);
	ACDBCORE2D_PORT virtual void xmitPropagateModify() const;
};

#include "IcArxPackPop.h"
