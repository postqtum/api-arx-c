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
***     Description: Declaration of AcDmUtil namespace
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../acadstrc.h"
#include "AcDbObjectId.h"

namespace AcDmUtil
{

const ACHAR* arrowName(const ACHAR* pName);
const ACHAR* arrowName(AcDbObjectId blockId);
int dimatfit(int dimfit);
int dimfit(int dimatfit, int dimtmove);
int dimfrac(int dimunit);
int dimlunit(int dimunit);
int dimtmove(int dimfit);
int dimunit(int dimlunit, int dimfrac);
Acad::ErrorStatus findArrowId(const ACHAR* pName, AcDbObjectId& blockId, AcDbDatabase* pDb = 0);
Acad::ErrorStatus getArrowId(const ACHAR* pName, AcDbObjectId& blockId, AcDbDatabase* pDb = 0);
const ACHAR* globalArrowName(const ACHAR* pName);
const ACHAR* globalArrowName(AcDbObjectId blockId);
bool isBuiltInArrow(const ACHAR* pName);
bool isZeroLengthArrow(const ACHAR* pName);

};	// namespace AcDmUtil
