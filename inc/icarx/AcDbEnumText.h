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
***     Description: Declaration of AcDbEnumText
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::TextHorzMode
{
	kTextLeft = 0,
	kTextCenter = 1,
	kTextRight = 2,
	kTextAlign = 3,
	kTextMid = 4,
	kTextFit = 5
};

enum AcDb::TextVertMode
{
	kTextBase = 0,
	kTextBottom = 1,
	kTextVertMid = 2,
	kTextTop = 3
};
