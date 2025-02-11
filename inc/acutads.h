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

#include "adsdef.h"
#include "AdAChar.h"
#include "acdbport.h"
#include <stdarg.h>
#include "AcDbCore2dDefs.h"

void acad__assert(const ACHAR*, const ACHAR*, int);

ads_real acutAngle(const ads_point pt1, const ads_point pt2);
struct resbuf* acutBuildList(int rtype, ...);
int acutCvUnit(ads_real value, const ACHAR* oldunit, const ACHAR* newunit, ads_real* result);
ads_real acutDistance(const ads_point pt1, const ads_point pt2);
int acutIsAlpha(int c);
int acutIsAlNum(int c);
int acutIsCntrl(int c);
int acutIsDigit(int c);
int acutIsGraph(int c);
int acutIsLower(int c);
int acutIsPrint(int c);
int acutIsPunct(int c);
int acutIsSpace(int c);
int acutIsUpper(int c);
int acutIsXDigit(int c);
struct resbuf* acutNewRb(int v);
void acutPolar(const ads_point pt, ads_real angle, ads_real dist, ads_point ptres);
ACDBCORE2D_PORT int acutPrintf(const ACHAR* format, ...);
int acutRbDup(const struct resbuf* source, struct resbuf** result);
int acutRelRb(struct resbuf* rb);
int acutSPrintf(ACHAR* buffer, size_t nBufLen, const ACHAR* format, ...);
int acutToLower(int c);
int acutToUpper(int c);
int acutWcMatch(const ACHAR* string, const ACHAR* pattern);

#ifdef __cplusplus

int acutVSPrintf(wchar_t* buf, size_t nBufLen, const wchar_t* fmt, va_list va);

template<size_t nBufLen>
inline int acutVSPrintf(wchar_t (&buf)[nBufLen], const ACHAR* format, va_list va)
{
	return ::acutVSPrintf(buf, nBufLen, format, va);
}

template<size_t nBufLen>
inline int acutSPrintf(wchar_t (&buf)[nBufLen], const ACHAR* format, ...)
{
	va_list va;
	va_start(va, format);
	const int nRet = ::acutVSPrintf(buf, nBufLen, format, va);
	va_end(va);
	return nRet;
}

#endif
