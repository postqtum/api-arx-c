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
***     Description: Declaration of AcDbCustomOsnapMode2 class
***
*****************************************************************************/
#pragma once

#include <wtypes.h>

#include "dbosnap.h"

#include "icarx/IcArxPackPush.h"

class AcDbCustomOsnapMode2 : public AcDbCustomOsnapMode
{
public:
	virtual const ACHAR* displayString() { return localModeString(); }
	virtual HICON menuIcon() { return nullptr; }
	virtual HICON menuIconForDarkTheme() { return nullptr; }
};

#include "icarx/IcArxPackPop.h"
