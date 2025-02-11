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
***     Description: Declaration of AcDbObjectContext class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbObjectContext : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbObjectContext);

	AcDbObjectContext();
	~AcDbObjectContext();

	virtual AcString collectionName() const = 0;
	virtual Acad::ErrorStatus getName(AcString& name) const = 0;
	virtual Acad::ErrorStatus setName(const AcString& name) = 0;
	virtual IcArx::Integers::LongPtr uniqueIdentifier() const = 0;
};

#include "icarx/IcArxPackPop.h"
