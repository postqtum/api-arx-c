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

#include "icarx/AcDbSoftPointerId.h"
#include "icarx/AcDbHardPointerId.h"
#include "icarx/AcDbSoftOwnershipId.h"
#include "icarx/AcDbHardOwnershipId.h"
#include "icarx/AcDbObjectId.h"

#include "adesk.h"
#include "dbhandle.h"
#include "AcDbCore2dDefs.h"

__declspec(selectany) const AcDbObjectId  AcDbObjectId::kNull;

#define ADSK_ACDBOBJECTID_DEFINED
#include "acarrayhelper.h"
