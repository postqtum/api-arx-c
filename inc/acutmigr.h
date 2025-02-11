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

#include "acutmem.h"

inline void delBuffer(char*& pString)
{
	::acutDelString(pString);
}
inline void delString(ACHAR*& pString)
{
	::acutDelString(pString);
}
inline Acad::ErrorStatus newBuffer(char*& pOutput, size_t size)
{
	return ::acutNewBuffer(pOutput, size);
}
inline Acad::ErrorStatus newString(const ACHAR* pInput, ACHAR*& pOutput)
{
	return ::acutNewString(pInput, pOutput);
}
inline Acad::ErrorStatus newString(ACHAR*& pOutput, int nNumChars)
{
	return ::acutNewString(pOutput, nNumChars);
}
inline Acad::ErrorStatus updString(const ACHAR* pInput, ACHAR*& pOutput)
{
	return ::acutUpdString(pInput, pOutput);
}
