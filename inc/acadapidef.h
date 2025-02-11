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
***     Description: Macro definitions for ACAD_PORT
***
*****************************************************************************/
#pragma once

#ifndef ACAD_PORT
#	ifdef ACAD_API
#		include "adesk.h"
#		define ACAD_PORT ADESK_EXPORT
#	else
#		define ACAD_PORT _declspec(dllimport)
#	endif
#endif
