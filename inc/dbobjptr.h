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

#include "icarx/AcDbSymbolTableRecordPointer.h"
#include "icarx/AcDbSymbolTablePointer.h"
#include "icarx/AcDbObjectPointer.h"
#include "icarx/AcDbObjectPointerBase.h"

#include "icarx/IcArxAssert.h"
#define DbObjPtr_Assert ICARX_ASSERT

typedef AcDbObjectPointer<AcDbDictionary> AcDbDictionaryPointer;
typedef AcDbObjectPointer<AcDbEntity> AcDbEntityPointer;

typedef AcDbSymbolTablePointer<AcDbBlockTable> AcDbBlockTablePointer;
typedef AcDbSymbolTablePointer<AcDbDimStyleTable> AcDbDimStyleTablePointer;
typedef AcDbSymbolTablePointer<AcDbLayerTable> AcDbLayerTablePointer;
typedef AcDbSymbolTablePointer<AcDbLinetypeTable> AcDbLinetypeTablePointer;
typedef AcDbSymbolTablePointer<AcDbRegAppTable> AcDbRegAppTablePointer;
typedef AcDbSymbolTablePointer<AcDbTextStyleTable> AcDbTextStyleTablePointer;
typedef AcDbSymbolTablePointer<AcDbUCSTable> AcDbUCSTablePointer;
typedef AcDbSymbolTablePointer<AcDbViewTable> AcDbViewTablePointer;
typedef AcDbSymbolTablePointer<AcDbViewportTable> AcDbViewportTablePointer;

typedef AcDbSymbolTableRecordPointer<AcDbBlockTableRecord> AcDbBlockTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbDimStyleTableRecord> AcDbDimStyleTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbLayerTableRecord> AcDbLayerTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbLinetypeTableRecord> AcDbLinetypeTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbRegAppTableRecord> AcDbRegAppTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbTextStyleTableRecord> AcDbTextStyleTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbUCSTableRecord> AcDbUCSTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbViewTableRecord> AcDbViewTableRecordPointer;
typedef AcDbSymbolTableRecordPointer<AcDbViewportTableRecord> AcDbViewportTableRecordPointer;
