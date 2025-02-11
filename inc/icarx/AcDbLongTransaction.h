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
***     Description: Declaration of AcDbLongTransaction class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbLongTransWorkSetIterator.h"

#include "IcArxPackPush.h"

class AcDbLongTransaction : public AcDbObject
{
public:
	enum
	{
		kSameDb = 0,
		kXrefDb = 1,
		kUnrelatedDb = 2
	};

public:
	AcDbLongTransaction();
	~AcDbLongTransaction();

	ACDB_DECLARE_MEMBERS(AcDbLongTransaction);

	AcDbIdMapping* activeIdMap();
	Acad::ErrorStatus addToWorkSet(AcDbObjectId id);
	AcDbObjectId destinationBlock() const;
	bool disallowDrawOrder();
	Acad::ErrorStatus getLongTransactionName(ACHAR*&) const;
	Acad::ErrorStatus newWorkSetIterator(AcDbLongTransWorkSetIterator*& pNewIter,
										 bool incRemovedObjs = false,
										 bool incSecondaryObjs = false) const;
	AcDbObjectId originBlock() const;
	AcDbObjectId originObject(AcDbObjectId id) const;
	void regenWorkSetWithDrawOrder();
	Acad::ErrorStatus removeFromWorkSet(AcDbObjectId id);
	Acad::ErrorStatus syncWorkSet();
	int type() const;
	bool workSetHas(AcDbObjectId id, bool bIncErased = false) const;
};

#include "IcArxPackPop.h"
