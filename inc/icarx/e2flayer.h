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
***     Description: Declaration of e2f_layer struct
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

#include "IcArxPackPush.h"

struct e2f_layer
{
	char id;
	short layernamelen;
	ACHAR* lname;
};

extern struct e2f_layer e2flayer;

#include "IcArxPackPop.h"
