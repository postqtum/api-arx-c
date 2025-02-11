/***************************************************************************
***
***     Copyright (C) 2023 IntelliCAD Technology Consortium. All Rights Reserved.
***
***     Use of the information contained herein, in part or in whole,
***     in/as source code and/or in/as object code, in any way by anyone
***     other than authorized employees of The IntelliCAD Technology Consortium,
***     or by anyone to whom The IntelliCAD Technology Consortium  has not
***     granted use is illegal.
***
***     Description: Precompiled header file
***
*****************************************************************************/
#pragma once
#define TABEXT_MODULE

#ifndef _ALLOW_RTCc_IN_STL
#	define _ALLOW_RTCc_IN_STL
#endif

#define STRICT

#ifndef VC_EXTRALEAN
#	define VC_EXTRALEAN
#endif

#ifndef WINVER
#	define WINVER 0x0601
#endif

#ifndef _WIN32_WINNT
#	define _WIN32_WINNT 0x0601
#endif

#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>

#include "arxHeaders.h"

AC_DECLARE_EXTENSION_MODULE(TabExtDLL)
