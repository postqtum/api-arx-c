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

#include "AdAChar.h"
#include "icarx/IcArxIntegers.h"

#include "icarx/IcArxPackPush.h"

typedef struct fchnd
{
	struct fchnd* next;
	int fcode;
	int (*fhdl)();
} FunHandList;

class AcRxGenHand;

class RxADSAppTableEntryType
{
public:
	int lflag;
	ACHAR* appname;
	IcArx::Integers::LongPtr apphandle;
	int ads_fcode;
	int ads_invkcnt;
	struct resbuf* ads_argl;
	FunHandList* ads_fhdl;
	AcRxGenHand* modhandle;
	resbuf* ads_ret;
	int ads_rettype;
};

#include "icarx/IcArxPackPop.h"
