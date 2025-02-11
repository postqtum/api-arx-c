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
***     Description: Declaration of AcDbCustomOsnapMode class
***
*****************************************************************************/
#pragma once

#include "AcGiGlyph.h"

#include "IcArxPackPush.h"

class AcDbCustomOsnapMode
{
public:
	virtual ~AcDbCustomOsnapMode() = default;

	virtual const AcRxClass* entityOsnapClass() const = 0;
	virtual const ACHAR* globalModeString() const = 0;
	virtual AcGiGlyph* glyph() const = 0;
	virtual const ACHAR* localModeString() const = 0;
	virtual const ACHAR* tooltipString() const = 0;
};

#include "IcArxPackPop.h"
