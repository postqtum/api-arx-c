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

#include "adsmigr.h"
#include "acutmigr.h"

#define acdbCurDwg acdbHostApplicationServices()->workingDatabase
#define acdbGetCurViewportObjectId acedGetCurViewportObjectId
#define acdbGetCurrentSelectionSet acedGetCurrentSelectionSet
#define acdbSetCurrentVPort acedSetCurrentVPort
#define getCurDwgXrefGraph acedGetCurDwgXrefGraph
