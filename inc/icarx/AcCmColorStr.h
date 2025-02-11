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
***     Description: Conversion functions from string to AcCmColor
***
*****************************************************************************/
#pragma once

#include "AcCmColor.h"
#include "AcCmHSB.h"

Acad::ErrorStatus accmGetColorFromACIName(AcCmColor& clr, const ACHAR* pInput);
Acad::ErrorStatus accmGetColorFromRGBName(AcCmColor& clr, const ACHAR* pInput);
Acad::ErrorStatus ACDBCORE2D_PORT accmGetFromHSBName(AcCmHSB& hsb, const ACHAR* pInput);
Acad::ErrorStatus accmGetColorFromColorBookName(AcCmColor& clr, const ACHAR* pBookName,
												const ACHAR* pColorName);
void accmGetLocalizedColorNames(const ACHAR* colors[9]);
