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
***     Description: Declaration of ACGIMAT_IMPEXP macro
***
*****************************************************************************/
#pragma once

#ifdef ACGIMATERIAL_IMPL
#	define ACGIMAT_IMPEXP __declspec(dllexport)
#else
#	define ACGIMAT_IMPEXP __declspec(dllimport)
#endif
