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

#ifdef _WINDOWS
#	define WIN 1
#endif

#ifdef WINVER
#	define WIN 1
#endif

#define MICROSOFT 1

#include "ads.h"
#include "adscodes.h"

#ifdef __cplusplus

bool acrxApplicationIsLocked(const ACHAR* modulename);
bool acrxLockApplication(void* appId);
bool acrxUnlockApplication(void* appId);

#endif	// __cplusplus
