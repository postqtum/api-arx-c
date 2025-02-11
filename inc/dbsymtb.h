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

#include "icarx/AcDbDimStyleTable.h"
#include "icarx/AcDbBlockReferenceIdIterator.h"
#include "icarx/AcDbSymbolTable.h"
#include "icarx/AcDbViewportTable.h"
#include "icarx/AcDbUCSTable.h"
#include "icarx/AcDbViewTable.h"
#include "icarx/AcDbAbstractViewTable.h"
#include "icarx/AcDbLinetypeTable.h"
#include "icarx/AcDbTextStyleTable.h"
#include "icarx/AcDbLayerTable.h"
#include "icarx/AcDbBlockTable.h"
#include "icarx/AcDbDimStyleTableRecord.h"
#include "icarx/AcDbSymbolTable.h"
#include "icarx/AcDbSymbolTableIterator.h"
#include "icarx/AcDbReg.h"
#include "icarx/AcDbViewportTableRecord.h"
#include "icarx/AcDbUCSTableRecord.h"
#include "icarx/AcDbViewTableRecord.h"
#include "icarx/AcDbAbstractViewTableRecord.h"
#include "icarx/AcDbLinetypeTableRecord.h"
#include "icarx/AcDbTextStyleTableRecord.h"
#include "icarx/AcDbLayerTableRecord.h"
#include "icarx/AcDbBlockTableRecord.h"
#include "icarx/AcDbSymbolTableRecord.h"

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbBackground.h"
#include "gevec2d.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"
#include "AcDbCore2dDefs.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"

#include "icarx/acut_str_util.h"

#ifdef target
#	undef target
#endif

namespace Atil
{
class Image;
}

#ifndef OBJARX_EXCLUDE_CONFLICTS
Acad::ErrorStatus applyCurDwgLayerTableChanges();
#endif

typedef struct tagBITMAPINFO BITMAPINFO;
