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
***     Description: Declaration of AcDbDictionaryIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDictionaryIterator : public AcRxObject
{
protected:
	AcDbDictionaryIterator() = default;

public:
	ACRX_DECLARE_MEMBERS(AcDbDictionaryIterator);
	AcDbDictionaryIterator(const AcDbDictionaryIterator&) = delete;
	~AcDbDictionaryIterator() = default;
	AcDbDictionaryIterator& operator=(const AcDbDictionaryIterator&) = delete;

	virtual bool done() const = 0;
	template<class ObjType>
	Acad::ErrorStatus getObject(ObjType*& pObject, AcDb::OpenMode mode = AcDb::kForRead)
	{
		const AcDbObjectId id = this->objectId();
		return ::acdbOpenObject(pObject, id, mode, /*openErased*/ false);
	}
	Acad::ErrorStatus getObject(AcDbObject*& pObject, AcDb::OpenMode mode = AcDb::kForRead)
	{
		return this->getObject<AcDbObject>(pObject, mode);
	}
	virtual const ACHAR* name() const = 0;
	virtual bool name(AcString& sName) const = 0;
	virtual bool next() = 0;
	virtual AcDbObjectId objectId() const = 0;
	virtual bool setPosition(AcDbObjectId objId) = 0;
};

#include "IcArxPackPop.h"
