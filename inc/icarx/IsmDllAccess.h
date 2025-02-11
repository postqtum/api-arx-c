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
***     Description: Declaration of ISMDLLACCESS macro
***
*****************************************************************************/
#pragma once

#ifdef ISMDLLACCESS
#	undef ISMDLLACCESS
#endif
#ifdef ISMDLLACCESSDATA
#	undef ISMDLLACCESSDATA
#endif
#ifdef ISM_OBJ
#	define ISMDLLACCESS __declspec(dllexport)
#	define ISMDLLACCESSDATA
#else
#	define ISMDLLACCESS
#	define ISMDLLACCESSDATA __declspec(dllimport)
#endif
