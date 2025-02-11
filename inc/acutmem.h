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
#include "adesk.h"
#include "AdAChar.h"
#include "AcDbCore2dDefs.h"

ACDBCORE2D_PORT Acad::ErrorStatus acutCopyStringToBuffer(const ACHAR* pInput, ACHAR* pOutput,
														 size_t nOutputSize);
void acutDelBuffer(void*& pBuffer);
Acad::ErrorStatus acutNewBuffer(void*& pOutput, size_t size);
Acad::ErrorStatus acutNewString(const ACHAR* pInput, ACHAR*& pOutput);
Acad::ErrorStatus acutNewString(ACHAR*& pOutput, int32_t nNumChars);
Acad::ErrorStatus acutUpdString(const ACHAR* pInput, ACHAR*& pOutput);

inline void acutDelBuffer(char*& pString)
{
	::acutDelBuffer((void*&)pString);
}
inline void acutDelString(char*& pString)
{
	::acutDelBuffer((void*&)pString);
}
inline void acutDelString(wchar_t*& pString)
{
	::acutDelBuffer((void*&)pString);
}
inline Acad::ErrorStatus acutNewBuffer(char*& pOutput, size_t size)
{
	return ::acutNewBuffer((void*&)pOutput, size);
}
