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
***     Description: Declaration of IAcRxNonBlittableType class
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h"

class IAcRxNonBlittableType
{
public:
	virtual void assign(void* dest, const void* source) const = 0;
	virtual void construct(void* dest, const void* source) const = 0;
	virtual void destruct(const void* instance) const = 0;
};

#include "IcArxPackPop.h"
