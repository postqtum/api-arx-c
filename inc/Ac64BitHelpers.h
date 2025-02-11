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
***     Description: Various 64-bit helpers
***
*****************************************************************************/
#pragma once

#include "ac_tcslen.h"
#include "adesk.h"
#include <cwchar>

#define Ac64Assert AcTcsLen_Assert

#ifdef HIBYTE
#	undef HIBYTE
#endif
#define HIBYTE(w) LOBYTE((IcArx::Integers::UIntPtr)(w) >> 8)

#pragma warning(push)
#pragma warning(disable : 4100)
inline int AcIntPtrToInt(IcArx::Integers::LongPtr nVal, IcArx::Integers::LongPtr nLimit = /*16M*/ 0x1000000)
{
	ICARX_ASSERT(nVal < nLimit);
	ICARX_ASSERT(nVal > -nLimit);
	const int nRet = static_cast<int>(nVal);
	ICARX_ASSERT(nRet == nVal);
	return nRet;
}

inline unsigned int AcUIntPtrToUInt(IcArx::Integers::ULongPtr nVal,
									IcArx::Integers::ULongPtr nLimit = /*16M*/ 0x1000000)
{
	ICARX_ASSERT(nVal < nLimit);
	const unsigned int nRet = static_cast<unsigned int>(nVal);
	ICARX_ASSERT(nRet == nVal);
	return nRet;
}
#pragma warning(pop)


inline IcArx::Integers::LongPtr ADESK_STDCALL AcStrToIntPtr(const wchar_t* s)
{
	return std::wcstoll(s, nullptr, 10);
}
