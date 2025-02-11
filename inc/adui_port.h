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

#ifdef _ADUI_BUILD
#	define ADUI_PORT __declspec(dllexport)
#else
#	define ADUI_PORT
#endif

#ifdef ADESK_NO_VTABLE
#	define ADUI_NO_VTABLE ADESK_NO_VTABLE
#else
#	ifdef _MSC_VER
#		define ADUI_NO_VTABLE __declspec(novtable)
#	else
#		define ADUI_NO_VTABLE
#	endif	// _MSC_VER
#endif		// ADESK_NO_VTABLE
