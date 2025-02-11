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

#ifndef ACCORE_PORT
#	ifdef ACCORE_API
#		include "adesk.h"
#		define ACCORE_PORT ADESK_EXPORT
#		define ACCORE_DATA_PORT _declspec(dllexport)
#		define ACCORE_STATIC_DATA_PORT _declspec(dllexport) static
#	else
#		define ACCORE_PORT
#		define ACCORE_DATA_PORT _declspec(dllimport)
#		define ACCORE_STATIC_DATA_PORT _declspec(dllimport) static
#	endif
#endif
