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
***     Description: Declaration of AcDbCompositeFilteredBlockIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbFilter;

#include "IcArxPackPush.h"

class AcDbCompositeFilteredBlockIterator
{
private:
	AcDbCompositeFilteredBlockIterator(const AcDbCompositeFilteredBlockIterator& copyFrom);

protected:
	AcDbCompositeFilteredBlockIterator() = default;

public:
	virtual ~AcDbCompositeFilteredBlockIterator() = default;

	virtual AcDbObjectId id() const = 0;
	virtual Acad::ErrorStatus init(AcDbFilter* const* ppFilters, int numFilters,
								   const AcDbBlockTableRecord* pBtr) = 0;
	static AcDbCompositeFilteredBlockIterator* newIterator();
	virtual AcDbObjectId next() = 0;
	virtual Acad::ErrorStatus seek(AcDbObjectId id) = 0;
	virtual Acad::ErrorStatus start() = 0;
};

#include "IcArxPackPop.h"
