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
***     Description: File name split routine
***
*****************************************************************************/
#pragma once

#include "../adsdef.h"

int acedFNSplit(const ACHAR* pathToSplit, ACHAR* prebuf, size_t nPreBufLen, ACHAR* namebuf,
				size_t nNameBufLen, ACHAR* extbuf, size_t nExtBufLen);

#ifdef __cplusplus

#	include "../acadstrc.h"
#	include "../AcString.h"

template<size_t nPreBufLen, size_t nNameBufLen, size_t nExtBufLen>
inline int acedFNSplit(const wchar_t* pathToSplit, wchar_t (&prebuf)[nPreBufLen],
					   wchar_t (&namebuf)[nNameBufLen], wchar_t (&extbuf)[nExtBufLen])
{
	return ::acedFNSplit(pathToSplit, prebuf, nPreBufLen, namebuf, nNameBufLen, extbuf, nExtBufLen);
}


template<size_t nNameBufLen>
inline int acedFNSplit(const wchar_t* pathToSplit, size_t nPre, wchar_t (&namebuf)[nNameBufLen],
					   size_t nExt)
{
	return ::acedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, nullptr, nExt);
}

template<size_t nExtBufLen>
inline int acedFNSplit(const wchar_t* pathToSplit, size_t nPre, size_t nName,
					   wchar_t (&extbuf)[nExtBufLen])
{
	return ::acedFNSplit(pathToSplit, nullptr, nPre, nullptr, nName, extbuf, nExtBufLen);
}

template<size_t nNameBufLen, size_t nExtBufLen>
inline int acedFNSplit(const wchar_t* pathToSplit, size_t nPre, wchar_t (&namebuf)[nNameBufLen],
					   wchar_t (&extbuf)[nExtBufLen])
{
	return ::acedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, extbuf, nExtBufLen);
}

template<size_t nPreBufLen>
inline int acedFNSplit(const wchar_t* pathToSplit, wchar_t (&prebuf)[nPreBufLen], size_t nName,
					   size_t nExt)
{
	return ::acedFNSplit(pathToSplit, prebuf, nPreBufLen, nullptr, nName, nullptr, nExt);
}

#endif /* __cplusplus */
