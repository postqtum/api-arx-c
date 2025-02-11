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

#include "icarx/AcDbHostApplicationProgressMeter.h"
#include "icarx/AcDbHostApplicationServices.h"
#include "icarx/AcDbPasswordedFile.h"

#include "adesk.h"
#include "acdb.h"
#include "acarray.h"
#include "AcString.h"
#include "PAL/api/codepgid.h"
#include "acdlflagbits.h"
#include "inetstrc.h"
#include "rxdlinkr.h"
#include "PAL/api/product_flavors.h"
#include "PAL/api/AcLocale.h"

#ifndef OBJARX_EXCLUDE_CONFLICTS
enum AcSDIValues
{
	kMDIEnabled = 0,
	kSDIUserEnforced,
	kSDIAppEnforced,
	kSDIUserAndAppEnforced
};
#endif	// OBJARX_EXCLUDE_CONFLICTS
