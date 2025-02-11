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

#include "icarx/AcDbUnderlayHost.h"
#include "icarx/AcDbUnderlayFile.h"
#include "icarx/AcDbUnderlayItem.h"
#include "icarx/AcDbUnderlayDrawContext.h"
#include "icarx/AcUnderlayLayer.h"

#include "AcString.h"

const int kItemVersionNumber = 1;

ACDBCORE2D_PORT void acdbConvertHslToRgb(const AcGeVector3d& hsl, AcGeVector3d& rgb);
ACDBCORE2D_PORT void acdbConvertRgbToHsl(const AcGeVector3d& rgb, AcGeVector3d& hsl);
ACDBCORE2D_PORT AcDbUnderlayHost* acdbGetCurrentDgnDocHost();
ACDBCORE2D_PORT AcDbUnderlayHost* acdbGetCurrentDgnHost();
ACDBCORE2D_PORT AcDbUnderlayHost* acdbGetCurrentDwfHost();
ACDBCORE2D_PORT AcDbUnderlayHost* acdbGetCurrentPdfHost();
bool acdbIsDgnToDwgInProgress();
ACDBCORE2D_PORT AcDbUnderlayHost* acdbSetCurrentDgnDocHost(AcDbUnderlayHost* pHost);
ACDBCORE2D_PORT AcDbUnderlayHost* acdbSetCurrentDgnHost(AcDbUnderlayHost* pHost);
ACDBCORE2D_PORT AcDbUnderlayHost* acdbSetCurrentDwfHost(AcDbUnderlayHost* pHost);
ACDBCORE2D_PORT AcDbUnderlayHost* acdbSetCurrentPdfHost(AcDbUnderlayHost* pHost);
