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
***     Description: Declaration of AcDbEnumDim
***
*****************************************************************************/
#pragma once

#include "AcDb.h"

enum AcDb::DimArrowFlags
{
	kFirstArrow = 0x00,
	kSecondArrow = 0x01
};

enum AcDb::DimblkFlags
{
	kDimblk = 0,
	kDimblk1,
	kDimblk2,
	kDimLdrBlk
};
