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
***     Description: Declaration of AcDbCustomOsnapManager class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"
#include "../acadstrc.h"

#include "AcDbCustomOsnapMode.h"

#include "IcArxPackPush.h"

class AcDbCustomOsnapManager
{
public:
	virtual ~AcDbCustomOsnapManager() = default;

	virtual Acad::ErrorStatus activateOsnapMode(const ACHAR* modeStr) = 0;
	virtual Acad::ErrorStatus addCustomOsnapMode(AcDbCustomOsnapMode* pMode) = 0;
	virtual Acad::ErrorStatus deactivateOsnapMode(const ACHAR* modeStr) = 0;
	virtual bool modeIsActive(const ACHAR* modeStr) = 0;
	virtual int osnapGlyphSize() const = 0;
	virtual Acad::ErrorStatus removeCustomOsnapMode(AcDbCustomOsnapMode* pMode) = 0;
};

#include "IcArxPackPop.h"
