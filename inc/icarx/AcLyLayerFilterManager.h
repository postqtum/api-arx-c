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
***     Description: Declaration of AcLyLayerFilterManager class
***
*****************************************************************************/
#pragma once

#include "../acadstrc.h"

class AcLyLayerFilter;
class AcDbDatabase;

#include "IcArxPackPush.h"

class AcLyLayerFilterManager
{
public:
	virtual ~AcLyLayerFilterManager() = default;

	virtual Acad::ErrorStatus getFilters(AcLyLayerFilter*& pRoot, AcLyLayerFilter*& pCurrent) = 0;
	virtual Acad::ErrorStatus setFilters(const AcLyLayerFilter* pRoot,
										 const AcLyLayerFilter* pCurrent) = 0;
};

#include "IcArxPackPop.h"

AcLyLayerFilterManager* aclyGetLayerFilterManager(AcDbDatabase* pDb);
