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

#include "adesk.h"
#include "acadstrc.h"
#include "acestext.h"
#include "acutasrt.h"

#ifdef NDEBUG

#	define eOkCheck(x) (x)
#	define eOkTest(x) ((x) == Acad::eOk)
#	define eOkVerify(x) ((x) == Acad::eOk)

#else

inline Acad::ErrorStatus eOkCheck_imp(const ACHAR* condition, const ACHAR* fname, int lineno,
									  Acad::ErrorStatus es)
{
	if (es != Acad::eOk)
	{
		acutAssertMessage(condition, fname, lineno, acadErrorStatusText(es));
	}
	return es;
}

#	define eOkCheck(x) eOkCheck_imp(ACRX_T(#	x), ACRX_T(__FILE__), __LINE__, (x))

#	define eOkTest(x) ((x) == Acad::eOk)

#	define eOkVerify(x) (eOkCheck(x) == Acad::eOk)

#endif
