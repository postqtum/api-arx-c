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
***     Description: Declaration of AcDbDictionary class
***
*****************************************************************************/
#pragma once

#include "AcDbDictionaryIterator.h"

#include "IcArxPackPush.h"

class AcDbDictionary : public AcDbObject
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbDictionary);

	AcDbDictionary();
	~AcDbDictionary();
	AcDbDictionary(const AcDbDictionary&) = delete;

	Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion ver, AcDbObject*& replaceObj,
									   AcDbObjectId& replaceId, bool& exchangeXData) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	void erased(const AcDbObject* pObject, bool bErasing) override;
	template<class ObjType>
	Acad::ErrorStatus getAt(const ACHAR* entryName, ObjType*& entryObj,
							AcDb::OpenMode mode = AcDb::kForRead) const
	{
		entryObj = nullptr;
		AcDbObjectId id;
		Acad::ErrorStatus es = this->getAt(entryName, id);
		if (es == Acad::eOk)
			es = ::acdbOpenObject(entryObj, id, mode, /*openErased*/ false);
		return es;
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbObject*& entryObj,
							AcDb::OpenMode mode = AcDb::kForRead)
	{
		return this->getAt<AcDbObject>(entryName, entryObj, mode);
	}
	Acad::ErrorStatus getAt(const ACHAR* entryName, AcDbObjectId& entryId) const;
	void goodbye(const AcDbObject* pObject) override;
	bool has(const ACHAR* entryName) const;
	bool has(AcDbObjectId objId) const;
	bool isTreatElementsAsHard() const;
	AcDb::DuplicateRecordCloning mergeStyle() const override;
	ACDBCORE2D_PORT Acad::ErrorStatus nameAt(AcDbObjectId objId, ACHAR*& name) const;
	ACDBCORE2D_PORT Acad::ErrorStatus nameAt(AcDbObjectId objId, AcString& sName) const;
	AcDbDictionaryIterator* newIterator() const;
	uint32_t numEntries() const;
	AcDbDictionary& operator=(const AcDbDictionary&) = delete;
	Acad::ErrorStatus remove(const ACHAR* key);
	Acad::ErrorStatus remove(const ACHAR* key, AcDbObjectId& returnId);
	Acad::ErrorStatus remove(AcDbObjectId objId);
	Acad::ErrorStatus setAt(const ACHAR* srchKey, AcDbObject* newValue, AcDbObjectId& retObjId);
	virtual void setMergeStyle(AcDb::DuplicateRecordCloning style);
	bool setName(const ACHAR* oldName, const ACHAR* newName);
	void setTreatElementsAsHard(bool doIt);
	Acad::ErrorStatus subErase(bool pErasing = true) override;
};

#include "IcArxPackPop.h"
