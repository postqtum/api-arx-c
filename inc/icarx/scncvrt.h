/***************************************************************************
***
***     Copyright (C) 2021-2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Declaration of scn_cvrt struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

struct scn_cvrt
{
	char id;
	long index;
};

extern struct scn_cvrt cvrtr;

#include "IcArxPackPop.h"
