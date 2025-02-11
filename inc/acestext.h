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
***     Description: Routine to get error description by its code
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "AdAChar.h"
#include "AcDbCore2dDefs.h"

ACDBCORE2D_PORT
const ACHAR* acadErrorStatusText(Acad::ErrorStatus);
