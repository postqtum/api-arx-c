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
***     Description: String length calculation function related declarations
***
*****************************************************************************/
#pragma once

#include "adesk.h"

#include "icarx/IcArxAssert.h"
#define AcTcsLen_Assert ICARX_ASSERT

#ifndef USEINTRINSTRLEN

#	ifdef _tcslen
#		undef _tcslen
#	endif

#	ifdef UNICODE
#		define _tcslen ac_wcslen
#	else
#		define _tcslen ac_strlen
#	endif

#	ifdef wcslen
#		undef wcslen
#	endif
#	define wcslen ac_wcslen
#	ifdef strlen
#		undef strlen
#	endif
#	define strlen ac_strlen

#	ifdef __cplusplus
extern "C"
{
#	endif

	__declspec(noinline) inline unsigned ac_wcslen(const wchar_t* s)
	{
		unsigned n = 0;
		while (*s != L'\0')
		{
			s++;
			n++;
			ICARX_ASSERT(n < 0x7FFFFFFE);
		}
		return n;
	}

	__declspec(noinline) inline unsigned ac_strlen(const char* s)
	{
		unsigned n = 0;
		while (*s != '\0')
		{
			s++;
			n++;
			ICARX_ASSERT(n < 0x7FFFFFFE);
		}
		return n;
	}

#	ifdef __cplusplus
}
#	endif

#else

#	ifndef _tcslen
#		define _tcslen wcslen
#	endif

#endif
