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
***     Description: Declaration of init/uninit functions
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"
#include "../AcDbCore2dDefs.h"

class AcDbDatabase;
class AcGiContext;
class AcLocale;

Acad::ErrorStatus acdbCleanUp();
ACDB_PORT void acdbInitialize();
const ACHAR* acdbOriginalXrefFullPathFor(const AcDbDatabase*);
AcGiContext* acdbSetDefaultAcGiContext(AcGiContext*);
ACDB_PORT void acdbTerminate();
ACDBCORE2D_PORT Acad::ErrorStatus acdbValidateSetup(const AcLocale& loc);
