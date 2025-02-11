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
***     Description: Conversion routines
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

int acdbAngToS(ads_real v, int unit, int prec, ACHAR* str, size_t nBufLen);
int acdbRawAngToS(ads_real v, int unit, int prec, ACHAR* str, size_t nBufLen);
int acdbRToS(ads_real val, int unit, int prec, ACHAR* str, size_t nBufLen);
int acdbAngToF(const ACHAR* str, int unit, ads_real* v);
int acdbRawAngToF(const ACHAR* str, int unit, ads_real* v);
int acdbDisToF(const ACHAR* str, int unit, ads_real* v);

#ifdef __cplusplus

#	include "acadstrc.h"
#	include "AcString.h"

template<size_t nBufLen>
inline int acdbAngToS(ads_real v, int unit, int prec, wchar_t (&buf)[nBufLen])
{
	return ::acdbAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen>
inline int acdbRawAngToS(ads_real v, int unit, int prec, wchar_t (&buf)[nBufLen])
{
	return ::acdbRawAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen>
inline int acdbRToS(ads_real v, int unit, int prec, wchar_t (&buf)[nBufLen])
{
	return ::acdbRToS(v, unit, prec, buf, nBufLen);
}

#endif /* __cplusplus */
