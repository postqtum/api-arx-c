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
***     Description: Declaration of AcDbEvalContextPair class
***
*****************************************************************************/
#pragma once

#include "../AcHeapOpers.h"

#include "IcArxPackPush.h"

class AcDbEvalContextPair : public AcHeapOperators
{
private:
	ACHAR* mKey;
	void* mValue;

public:
	AcDbEvalContextPair();
	AcDbEvalContextPair(const ACHAR* szKey, void* pValue);
	virtual ~AcDbEvalContextPair();

	const ACHAR* key() const;
	void setKey(const ACHAR* szKey);
	void setValue(void* pValue);
	void* value() const;
};

#include "IcArxPackPop.h"
