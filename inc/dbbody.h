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
***     Description:
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"

#include "icarx/IcArxPackPush.h"

class AcDbBody : public AcDbEntity
{
public:
	ACDB_DECLARE_MEMBERS(AcDbBody);

	AcDbBody();
	~AcDbBody();

	virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
	static Acad::ErrorStatus acisIn(const ACHAR* fileName, AcDbVoidPtrArray&);
	static Acad::ErrorStatus acisOut(const ACHAR* fileName, const AcDbVoidPtrArray&);
	virtual void commitWritableASMBody();
	virtual void const* getLockedASMBody();
	virtual void* getLockedWritableASMBody();
	ACDB_PORT void dragStatus(const AcDb::DragStat) override;
	virtual AcDbSubentId internalSubentId(void*) const;
	virtual void* internalSubentPtr(const AcDbSubentId& id) const;
	void invalidateCachedBodySubentIds();
	virtual bool isNull() const;
	virtual uint32_t numChanges() const;
	virtual Acad::ErrorStatus setASMBody(const void* modelerBody);
	virtual void unlockASMBody();
	ACDB_PORT virtual bool usesGraphicsCache();
};

#include "icarx/IcArxPackPop.h"
