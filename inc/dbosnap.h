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
***     Description:
***
*****************************************************************************/
#pragma once

#include "adesk.h"

#pragma warning(disable : 4786)

#include "icarx/AcDbCustomOsnapManager.h"
#include "icarx/AcDbCustomOsnapMode.h"
#include "icarx/AcGiGlyph.h"
#include "icarx/AcDbCustomOsnapInfo.h"

AcDbCustomOsnapManager* acdbCustomOsnapManager();

extern "C" __declspec(dllexport) bool acedIsOsnapOverride();

