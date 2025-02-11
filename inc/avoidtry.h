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

#define ASITRYSET             \
	IncreaseGlobalAccount(0); \
	try
#define ASICATCHALL catch (int ASITRYCODE)
#define ASITRYDEL DecreaseGlobalAccount(0);
#define ASITHROW(x)            \
	if (CheckGlobalAccount(0)) \
	throw((int)(x))

DLLScope int CheckGlobalAccount(int ind);
DLLScope int DecreaseGlobalAccount(int ind);
DLLScope int IncreaseGlobalAccount(int ind);
