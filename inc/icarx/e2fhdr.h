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
***     Description: Declaration of e2f_hdr struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

struct e2f_hdr
{
	char id;
	short flags;
	short version;
	long nents;
	long npoly;
	long nlayers;
	unsigned long bgcolor;
	short cmaplen;
	char* cmap;
};

extern struct e2f_hdr e2fheader;

#include "IcArxPackPop.h"
