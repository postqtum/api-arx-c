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
***     Description: Declaration of IAcPcPointFilter and IAcPcPointProcessor classes
***
*****************************************************************************/
#pragma once

#include "../acdbport.h"

class IAcPcDataBuffer;

#include "IcArxPackPush.h"

class ACDB_PORT IAcPcPointFilter
{
public:
	virtual void doFilter(const IAcPcDataBuffer& inBuffer, IAcPcDataBuffer& outBuffer) = 0;
};

class ACDB_PORT IAcPcPointProcessor
{
private:
	IAcPcDataBuffer* mpBuffer;

public:
	virtual void abort() = 0;
	IAcPcDataBuffer* buffer();
	virtual bool cancel() = 0;
	virtual IAcPcPointFilter* filter() = 0;
	virtual void finished() = 0;
	virtual bool processPoints() = 0;
	void setBuffer(IAcPcDataBuffer* buffer);
};

#include "IcArxPackPop.h"
