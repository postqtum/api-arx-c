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
***     Description: Declaration of AcRxDictionary class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "AdAChar.h"

class AcRxDictionaryIterator;

#include "icarx/IcArxPackPush.h"

class AcRxDictionary : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDictionary, ACBASE_PORT);

	virtual AcRxObject* at(const ACHAR* key) const = 0;
	virtual AcRxObject* at(uint32_t id) const = 0;
	virtual bool atKeyAndIdPut(const ACHAR* newKey, uint32_t id, AcRxObject* pObject) = 0;
	AcRxObject* atPut(const ACHAR* key, AcRxObject* pObject);
	virtual AcRxObject* atPut(const ACHAR* key, AcRxObject* pObject, uint32_t& retId) = 0;
	virtual AcRxObject* atPut(uint32_t id, AcRxObject* pObject) = 0;
	virtual bool deletesObjects() const = 0;
	virtual bool has(const ACHAR* entryName) const = 0;
	virtual bool has(uint32_t id) const = 0;
	virtual uint32_t idAt(const ACHAR* key) const = 0;
	virtual bool isCaseSensitive() const = 0;
	virtual bool isSorted() const = 0;
	virtual const ACHAR* keyAt(uint32_t id) const = 0;
	virtual AcRxDictionaryIterator* newIterator(AcRx::DictIterType type = AcRx::kDictSorted) = 0;
	virtual uint32_t numEntries() const = 0;
	virtual AcRxObject* remove(const ACHAR* key) = 0;
	virtual AcRxObject* remove(uint32_t id) = 0;
	virtual bool resetKey(const ACHAR* oldKey, const ACHAR* newKey) = 0;
	virtual bool resetKey(uint32_t id, const ACHAR* newKey) = 0;
};

#include "icarx/IcArxPackPop.h"

inline AcRxObject* AcRxDictionary::atPut(const ACHAR* key, AcRxObject* pObj)
{
	uint32_t temp;
	return atPut(key, pObj, temp);
}

extern "C" ACBASE_PORT AcRxDictionary* acrxSysRegistry();

#define acrxClassDictionary AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_CLASS_DICTIONARY))

#define acrxServiceDictionary AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_SERVICE_DICTIONARY))
