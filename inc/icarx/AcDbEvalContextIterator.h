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
***     Description: Declaration of AcDbEvalContextIterator class
***
*****************************************************************************/
#pragma once

#include "../AcHeapOpers.h"
#include "../rxobject.h"

class AcDbEvalContextPair;
class AcDbEvalContext;

#include "IcArxPackPush.h"

class AcDbEvalContextIterator
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcDbImpEvalContext;

public:
	ACRX_DECLARE_MEMBERS(AcDbEvalContextIterator);

	AcDbEvalContextIterator();
	~AcDbEvalContextIterator();

	virtual AcDbEvalContextPair contextPair() const;
	virtual bool done() const;
	virtual bool next();
	virtual void start();
};

#include "IcArxPackPop.h"
