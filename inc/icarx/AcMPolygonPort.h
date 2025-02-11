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
***     Description: Declaration of ACMPOLYGON_PORT macro
***
*****************************************************************************/
#pragma once

#ifndef ACMPOLYGON_PORT
#	ifdef ACMPOLYGON_API
#		define ACMPOLYGON_PORT _declspec(dllexport)
#	else
#		define ACMPOLYGON_PORT _declspec(dllimport)
#	endif
#endif
