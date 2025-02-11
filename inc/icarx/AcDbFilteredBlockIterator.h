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
***     Description: Declaration of AcDbFilteredBlockIterator class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcDbFilteredBlockIterator
{
public:
	AcDbFilteredBlockIterator() = default;
	virtual ~AcDbFilteredBlockIterator() = default;

	virtual Acad::ErrorStatus accepts(AcDbObjectId id, bool& idPassesFilter) const = 0;
	virtual Acad::ErrorStatus addToBuffer(AcDbObjectId id);
	virtual bool buffersForComposition() const;
	virtual double estimatedHitFraction() const = 0;
	virtual AcDbObjectId id() const = 0;
	virtual AcDbObjectId next() = 0;
	virtual Acad::ErrorStatus seek(AcDbObjectId id) = 0;
	virtual Acad::ErrorStatus start() = 0;
};

#include "IcArxPackPop.h"
