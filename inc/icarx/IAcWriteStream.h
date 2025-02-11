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
***     Description: Declaration of IAcWriteStream class
***
*****************************************************************************/
#pragma once

#include "IAcReadStream.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcWriteStream : public IAcReadStream
{
protected:
	~IAcWriteStream() = default;

public:
	virtual int flushBuffers() { return eNotSupported; }
	virtual int setEndOfFile() { return eNotSupported; }
	virtual int write(const void* pSrcBuf, size_t nNumBytes, size_t* pNumWritten) = 0;
};

#include "IcArxPackPop.h"
