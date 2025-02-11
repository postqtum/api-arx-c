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
***     Description: Declaration of OPMDWORD struct
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

typedef struct tagOPMDWORD
{
	ULONG cElems;
	/* [size_is] */ DWORD __RPC_FAR* pElems;
} OPMDWORD;

#include "IcArxPackPop.h"

typedef struct tagOPMDWORD __RPC_FAR* LPOPMDWORD;
