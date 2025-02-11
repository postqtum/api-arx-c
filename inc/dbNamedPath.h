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
***     Description: Declaration of AcDbNamedPath, AcDbCurvePath, AcDbPointPath classes
***
*****************************************************************************/
#pragma once

#include "icarx/AcDbPointPath.h"
#include "icarx/AcDbCurvePath.h"
#include "icarx/AcDbNamedPath.h"

#include "dbmain.h"

const ACHAR ACDB_NAMEDPATH_DICTIONARY[] = /*MSG0*/ ACRX_T("ACAD_NAMEDPATH");

Acad::ErrorStatus SCENEDLLIMPEXP acdbGetNamedPathDictionary(AcDbDatabase* pDb,
															AcDbDictionary*& pDict,
															AcDb::OpenMode mode,
															bool createIfNonExist);
Acad::ErrorStatus SCENEDLLIMPEXP acdbGetNamedPathDictionary(AcDbDatabase* pDb,
															AcDbDictionary*& pDict,
															AcDb::OpenMode mode);
