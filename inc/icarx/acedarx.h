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
***     Description: ARX support routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

struct resbuf* acedArxLoaded(void);
int acedArxLoad(const ACHAR* app);
int acedArxUnload(const ACHAR* app);

int acdbRegApp(const ACHAR* appname);
