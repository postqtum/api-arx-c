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
***     Description: Declaration of AcDbGroupIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbGroupIterator : public AcRxObject
{
protected:
	AcDbGroupIterator() = default;

public:
	ACRX_DECLARE_MEMBERS(AcDbGroupIterator);
	~AcDbGroupIterator() = default;

	virtual bool done() const = 0;
	virtual Acad::ErrorStatus getObject(AcDbObject*& pObject, AcDb::OpenMode) = 0;
	virtual bool next() = 0;
	virtual AcDbObjectId objectId() const = 0;
};

#include "IcArxPackPop.h"
