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
***     Description: Declaration of IAcReadStream class
***
*****************************************************************************/
#pragma once

#include "../adesk.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcReadStream
{
public:
	enum
	{
		eOk = 0,
		eNotSupported = 1,
		eNotOpen = 2,
		eInvalidArg = 3,
		eEndOfFile = 4,
		eDiskFull = 5,
		eDisconnected = 6,
		eJustAnError = 7
	};

	enum
	{
		eFromStart = 0,
		eFromCurrent = 1,
		eFromEnd = 2
	};

protected:
	virtual ~IAcReadStream() = default;

public:
	virtual int close() { return eNotSupported; }
	virtual int64_t control(int64_t nArg)
	{
		(void)(nArg);
		return 0;
	}
	virtual int read(void* pDestBuf, size_t nNumBytes, size_t* pNumRead) = 0;
	virtual int seek(int64_t nDistance, int nMode)
	{
		(void)(nDistance);
		(void)(nMode);
		return eNotSupported;
	}
	virtual int64_t tell() { return -1; }
};


#include "IcArxPackPop.h"
