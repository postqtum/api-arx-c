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
***     Description: Top header files used by acedads.h
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../adsdef.h"

#ifdef AdInt32
#	undef AdInt32
#endif
#ifdef __cplusplus
#	define AdInt32 int32_t
#else
#	define AdInt32 long
#endif

const ACHAR* acedGetAppName();
int acedUpdate(int vport, ads_point p1, ads_point p2);

#if defined(_WINDEF_)
HWND adsw_acadMainWnd();
#	ifndef adsw_hwndAcad
#		define adsw_hwndAcad adsw_acadMainWnd()
#	endif

ACCORE_PORT HWND adsw_acadDocWnd();
#endif	// _WINDOWS_
