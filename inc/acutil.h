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

#include "acadstrc.h"

bool acutSplitString(size_t& numLeftBytes, const ACHAR*& pRight, const ACHAR* source,
					 unsigned int delimiter);
void acutTrimWhiteSpace(ACHAR* pStr);
bool acutWcMatchEx(const ACHAR* string, const ACHAR* pattern, bool ignoreCase);
size_t acutXStrLength(const ACHAR* str);
Acad::ErrorStatus acutXStrNormalize(ACHAR*& pStr, bool preserveCase);
inline Acad::ErrorStatus acutXStrUppercase(ACHAR*& pStr)
{
	return acutXStrNormalize(pStr, false);
}
