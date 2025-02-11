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
***     Description: Declaration of IAcRxReferenceType class
***
*****************************************************************************/
#pragma once

#include "../rxclass.h"

class AcRxValue;

#include "IcArxPackPush.h"

class IAcRxReferenceType
{
public:
	enum OpenMode
	{
		kForRead = 0,
		kForWrite = 1,
		kForNotify = 2
	};

public:
	virtual AcRxObject* beginDereferencing(const AcRxValue& value, OpenMode mode) const = 0;
	virtual Acad::ErrorStatus endDereferencing(AcRxObject* pO) const = 0;
};

#include "IcArxPackPop.h"
