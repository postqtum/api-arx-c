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

#include "dbid.h"
#include "AdAChar.h"
#include "acgi.h"

Acad::ErrorStatus fromAcDbTextStyle(AcGiTextStyle&, const AcDbObjectId& AcDbStyleId);
Acad::ErrorStatus fromAcDbTextStyle(AcGiTextStyle&, const ACHAR* AcDbStyleName);
Acad::ErrorStatus toAcDbTextStyle(const AcDbObjectId AcDbStyleId, AcGiTextStyle&);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&, const ACHAR* AcDbStyleName);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&, const ACHAR* AcDbStyleName,
								  AcDbObjectId& AcDbStyleId);
Acad::ErrorStatus toAcDbTextStyle(AcGiTextStyle&, AcDbObjectId& AcDbStyleId);
