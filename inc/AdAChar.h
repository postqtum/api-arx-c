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
***     Description: ACHAR related macro definitions
***
*****************************************************************************/
#pragma once

#define AD_UNICODE 1

#if defined(__cplusplus) && !defined(_NATIVE_WCHAR_T_DEFINED)
#	error Please use /Zc:wchar_t
#endif

typedef wchar_t ACHAR;

#define _ACRX_T(x) L##x
#define ACRX_T(x) _ACRX_T(x)
