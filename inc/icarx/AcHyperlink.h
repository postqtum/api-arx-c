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
***     Description: Declaration of AcHyperlink struct
***
*****************************************************************************/
#pragma once

#include "../AcString.h"

#include "IcArxPackPush.h"

struct AcHyperlink
{
	AcString msUrl;
	AcString msSubLocation;
	AcString msDescription;
	int32_t mlFlag;
};

#include "IcArxPackPop.h"
