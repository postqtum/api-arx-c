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
***     Description: Declaration of IAcDbPointCloudPointProcessor interface
***
*****************************************************************************/
#pragma once

#include "IAcDbPointCloudDataBuffer.h"

#include "IcArxPackPush.h"

class __declspec(novtable) IAcDbPointCloudPointProcessor
{
public:
	enum ProcessSate
	{
		Abort,
		Continue
	};

public:
	virtual ~IAcDbPointCloudPointProcessor() = 0 {};

	virtual ProcessSate process(const IAcDbPointCloudDataBuffer* buffer) = 0;
};

#include "IcArxPackPop.h"
