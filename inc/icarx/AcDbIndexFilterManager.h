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
***     Description: Declaration of AcDbIndexFilterManager namespace
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "AcDbIndex.h"

class AcDbBlockReference;

namespace AcDbIndexFilterManager
{

Acad::ErrorStatus addIndex(AcDbBlockTableRecord* pBTR, AcDbIndex* pIndex);
Acad::ErrorStatus addFilter(AcDbBlockReference* pBlkRef, AcDbFilter* pFilter);
Acad::ErrorStatus getFilter(const AcDbBlockReference* pRef, const AcRxClass* key,
							AcDb::OpenMode readOrWrite, AcDbFilter*& pFilter);
Acad::ErrorStatus getFilter(const AcDbBlockReference* pRef, int index, AcDb::OpenMode readOrWrite,
							AcDbFilter*& pFilter);
Acad::ErrorStatus getIndex(const AcDbBlockTableRecord* pBTR, const AcRxClass* key,
						   AcDb::OpenMode readOrWrite, AcDbIndex*& pIndex);
Acad::ErrorStatus getIndex(const AcDbBlockTableRecord* pBTR, int index, AcDb::OpenMode readOrWrite,
						   AcDbIndex*& pIndex);
int numFilters(const AcDbBlockReference* pBlkRef);
int numIndexes(const AcDbBlockTableRecord* pBtr);
Acad::ErrorStatus removeFilter(AcDbBlockReference* pBlkRef, const AcRxClass* key);
Acad::ErrorStatus removeIndex(AcDbBlockTableRecord* pBTR, const AcRxClass* key);
Acad::ErrorStatus updateIndexes(AcDbDatabase* pDb);

};	// namespace AcDbIndexFilterManager
