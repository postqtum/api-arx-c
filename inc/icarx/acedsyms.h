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
***     Description: Symbol manipulation routines
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"
#include "../adsdef.h"

int acedSetVar(const ACHAR* sym, const struct resbuf* val);
int acedInitGet(int val, const ACHAR* kwl);

int acedGetSym(const ACHAR* sname, struct resbuf** value);
int acedPutSym(const ACHAR* sname, struct resbuf* value);

int acedGetVar(const ACHAR* sym, struct resbuf* result);
int acedFindFile(const ACHAR* fname, ACHAR* result, size_t nBufLen);
int acedFindTrustedFile(const ACHAR* fname, ACHAR* result, size_t nBufLen);

int acedGetEnv(const ACHAR* sym, ACHAR* var, size_t nBufLen);
int acedSetEnv(const ACHAR* sym, const ACHAR* val);

int acedGetCfg(const ACHAR* sym, ACHAR* var, size_t len);
int acedSetCfg(const ACHAR* sym, const ACHAR* val);

#ifdef __cplusplus

#	include "../acadstrc.h"
#	include "../AcString.h"

template<size_t nBufLen>
inline int acedGetEnv(const wchar_t* pszName, wchar_t (&buf)[nBufLen])
{
	return ::acedGetEnv(pszName, buf, nBufLen);
}

template<size_t nBufLen>
inline int acedGetInput(wchar_t (&buf)[nBufLen])
{
	return ::acedGetInput(buf, nBufLen);
}

template<size_t nBufLen>
inline int acedGetString(int cronly, const wchar_t* prompt, wchar_t (&buf)[nBufLen])
{
	return ::acedGetString(cronly, prompt, buf, nBufLen);
}

template<size_t nBufLen>
inline int acedFindFile(const wchar_t* pszName, wchar_t (&buf)[nBufLen])
{
	return ::acedFindFile(pszName, buf, nBufLen);
}

template<size_t nBufLen>
inline int acedFindTrustedFile(const wchar_t* pszName, wchar_t (&buf)[nBufLen])
{
	return ::acedFindTrustedFile(pszName, buf, nBufLen);
}

#endif /* __cplusplus */
