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
***     Description: Declaration of AcOfstream class
***
*****************************************************************************/
#pragma once

#include "AcFStream.h"

#include "IcArxPackPush.h"

class AcOfstream : public std::wofstream
{
public:
	AcOfstream() = default;
	AcOfstream(const wchar_t* pName) { open(pName); }

	void open(const wchar_t* pName)
	{
		std::wofstream::open(pName);
		imbue(AcFStream_curLocale());
	}
	void open(const wchar_t* pName, ios_base::openmode nMode)
	{
		std::wofstream::open(pName, nMode);
		imbue(AcFStream_curLocale());
	}
};

#include "IcArxPackPop.h"
