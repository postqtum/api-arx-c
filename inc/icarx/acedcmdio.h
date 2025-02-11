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
***     Description: AcEd Command input/output support routines
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../AdAChar.h"
#include "../adsdef.h"

int acedGetString(int cronly, const ACHAR* prompt, ACHAR* result, size_t bufsize);

int acedMenuCmd(const ACHAR* str);
int acedPrompt(const ACHAR* str);
int acedAlert(const ACHAR* str);

int acedGetAngle(const ads_point pt, const ACHAR* prompt, ads_real* result);
int acedGetCorner(const ads_point pt, const ACHAR* prompt, ads_point result);
int acedGetDist(const ads_point pt, const ACHAR* prompt, ads_real* result);
int acedGetOrient(const ads_point pt, const ACHAR* prompt, ads_real* result);
int acedGetPoint(const ads_point pt, const ACHAR* prompt, ads_point result);
int acedGetInt(const ACHAR* prompt, int* result);
int acedGetKword(const ACHAR* prompt, ACHAR* result, size_t nBufLen);
int acedGetReal(const ACHAR* prompt, ads_real* result);
int acedGetInput(ACHAR* str, size_t nBufLen);
int acedVports(struct resbuf** vlist);

int acedTextScr(void);
int acedGraphScr(void);
int acedTextPage(void);

int acedGetCName(const ACHAR* cmd, ACHAR** result);
int acedEatCommandThroat(void);

int ads_queueexpr(const ACHAR* expr);

#ifdef __cplusplus

#	include "../acadstrc.h"
#	include "../AcString.h"
#	include "acut_str_util.h"

ACCORE_PORT int acedGetString(int cronly, const ACHAR* prompt, AcString& sResult);
ACCORE_PORT int acedGetKword(const ACHAR* prompt, AcString& sResult);
ACCORE_PORT int acedGetInput(AcString& sOut);

inline int acedGetFullInput(ACHAR*& pStr)
{
	AcString sOut;
	const int nRet = ::acedGetInput(sOut);
	::acutNewString(sOut.constPtr(), pStr);
	return nRet;
}

inline int acedGetFullKword(const ACHAR* pString, ACHAR*& pStr)
{
	AcString sOut;
	const int nRet = ::acedGetKword(pString, sOut);
	::acutNewString(sOut.constPtr(), pStr);
	return nRet;
}

inline int acedGetFullString(int cronly, const ACHAR* pString, ACHAR*& pResult)
{
	AcString sResult;
	const int nRet = ::acedGetString(cronly, pString, sResult);
	::acutNewString(sResult.constPtr(), pResult);
	return nRet;
}

template<size_t nBufLen>
inline int acedGetKword(const wchar_t* pszPrompt, wchar_t (&buf)[nBufLen])
{
	return ::acedGetKword(pszPrompt, buf, nBufLen);
}

#endif // __cplusplus
