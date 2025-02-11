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
***     Description: Declaration of AcDbFilter class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

class AcDbFilteredBlockIterator;

#include "icarx/IcArxPackPush.h"

class AcDbFilter : public AcDbObject
{
public:
	ACDB_DECLARE_MEMBERS(AcDbFilter);
	AcDbFilter();
	~AcDbFilter();

	virtual AcRxClass* indexClass() const;
};

#include "icarx/IcArxPackPop.h"
