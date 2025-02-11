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
***     Description: Declaration of e2f_ent struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

struct e2f_ent
{
	char id;
	short flags;
	short type;
	__int64 adr1;
	__int64 adr2;
	long npoly;
	long nverts;
	short color;
	long truecolor;
	long layerindex;
	__int64 materialId;
};

extern struct e2f_ent e2fentity;

#include "IcArxPackPop.h"
