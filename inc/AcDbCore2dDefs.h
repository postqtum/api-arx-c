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
***     Description: Common macro definitions for Core-2 headers
***
*****************************************************************************/
#pragma once

#if defined(ACDBCORE2D_API)
#	include "adesk.h"
#	define ACDBCORE2D_PORT ADESK_EXPORT
#	define ACDBCORE2D_DATA_PORT _declspec(dllexport)
#else
#	if defined(ACDBCORE2D_STATIC)
#		define ACDBCORE2D_PORT
#		define ACDBCORE2D_DATA_PORT
#	else
#		define ACDBCORE2D_PORT
#		define ACDBCORE2D_DATA_PORT _declspec(dllimport)
#	endif
#endif
