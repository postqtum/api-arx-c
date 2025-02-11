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
***     Description: Declaration of AcEdSubSelectFilterService class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"

struct resbuf;
class AcDbFullSubentPath;

#include "IcArxPackPush.h"

class AcEdSubSelectFilterService
{
public:
	virtual Acad::ErrorStatus add(resbuf* ssnameXList, const AcDbFullSubentPath& path) = 0;
	virtual Acad::ErrorStatus ssNameX(bool bIsSubSelectionIndex, int index, resbuf*& result) = 0;
	virtual Acad::ErrorStatus remove(bool bIsSubSelectionIndex, int index) = 0;
};

#include "IcArxPackPop.h"
