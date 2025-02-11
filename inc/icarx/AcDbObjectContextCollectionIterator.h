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
***     Description: Declaration of AcDbObjectContextCollectionIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "../dbObjContext.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbObjectContextCollectionIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbObjectContextCollectionIterator);

	virtual Acad::ErrorStatus getContext(AcDbObjectContext*& pObjectContext) const = 0;
	virtual bool next() = 0;
	virtual Acad::ErrorStatus start() = 0;
	virtual bool done() const = 0;
};

#include "IcArxPackPop.h"
