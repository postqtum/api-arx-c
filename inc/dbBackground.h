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

#include "icarx/AcDbBackground.h"
#include "icarx/AcDbSolidBackground.h"
#include "icarx/AcDbGradientBackground.h"
#include "icarx/AcDbImageBackground.h"
#include "icarx/AcDbGroundPlaneBackground.h"
#include "icarx/AcDbSkyBackground.h"
#include "icarx/AcDbIBLBackground.h"

#include "dbmain.h"
#include "AcGiEnvironment.h"
#include "dbcolor.h"
#include "AdAChar.h"

const ACHAR ACDB_BACKGROUND_DICTIONARY[] = /*MSG0*/ ACRX_T("ACAD_BACKGROUND");

Acad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary(AcDbDatabase* pDb, AcDbDictionary*& pDict,
														 AcDb::OpenMode mode);
Acad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary(AcDbDatabase* pDb, AcDbDictionary*& pDict,
														 AcDb::OpenMode mode,
														 bool createIfNonExist);
