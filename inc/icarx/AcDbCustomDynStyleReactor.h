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
***     Description: Declaration of AcDbCustomDynStyleReactor class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"

class AcDbObjectId;
class AcDbDatabase;

#include "IcArxPackPush.h"

class AcDbCustomDynStyleReactor
{
public:
	ACDBCORE2D_PORT AcDbCustomDynStyleReactor();
	ACDBCORE2D_PORT virtual ~AcDbCustomDynStyleReactor();

	ACDBCORE2D_PORT virtual AcDbObjectId getCustomDynArrowTypeId(AcDbDatabase* = nullptr);
	ACDBCORE2D_PORT virtual AcDbObjectId getCustomDynDimStyleId(AcDbDatabase* = nullptr);
	ACDBCORE2D_PORT virtual AcDbObjectId getCustomDynDimTextStyleId(AcDbDatabase* = nullptr);
	ACDBCORE2D_PORT virtual AcDbObjectId getCustomDynLineTypeId(AcDbDatabase* = nullptr);
};

#include "IcArxPackPop.h"
