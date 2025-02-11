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
***     Description: Declaration of AcDbItemLocator class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

#include "IcArxPackPush.h"

class AcDbItemLocator
{
public:
	enum IndexType
	{
		kItemIndex,
		kRowIndex,
		kLevelIndex,
	};

private:
	int mIndices[3];

public:
	ACDBCORE2D_PORT AcDbItemLocator();
	ACDBCORE2D_PORT AcDbItemLocator(int itemIndex, int rowIndex, int levelIndex);
	ACDBCORE2D_PORT AcDbItemLocator(const AcDbItemLocator& other);
	ACDBCORE2D_PORT AcDbItemLocator& operator=(const AcDbItemLocator& other);
	ACDBCORE2D_PORT bool operator==(const AcDbItemLocator& other) const;
	ACDBCORE2D_PORT bool operator!=(const AcDbItemLocator& other) const;
	ACDBCORE2D_PORT bool operator<(const AcDbItemLocator& other) const;
	ACDBCORE2D_PORT bool operator>(const AcDbItemLocator& other) const
	{
		return this->compareWith(other) > 0;
	}
	ACDBCORE2D_PORT AcDbItemLocator operator+(const AcDbItemLocator& other) const;
	ACDBCORE2D_PORT AcDbItemLocator operator-(const AcDbItemLocator& other) const;
	ACDBCORE2D_PORT int operator[](AcDbItemLocator::IndexType i) const { return this->mIndices[i]; }

	ACDBCORE2D_PORT int compareWith(const AcDbItemLocator& other) const;
};

#include "IcArxPackPop.h"
