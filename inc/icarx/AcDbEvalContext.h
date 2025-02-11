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
***     Description: Declaration of AcDbEvalContext class
***
*****************************************************************************/
#pragma once

#include "../AcHeapOpers.h"
#include "../rxobject.h"

class AcDbEvalContext;
class AcDbEvalContextPair;
class AcDbEvalContextIterator;
class AcDbImpEvalContext;
class AcDbImpEvalContextIterator;

#include "IcArxPackPush.h"

class AcDbEvalContext
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcDbImpEvalContextIterator;

private:
	AcDbImpEvalContext* mpImp;

public:
	AcDbEvalContext();
	~AcDbEvalContext();

	ACRX_DECLARE_MEMBERS(AcDbEvalContext);

	virtual Acad::ErrorStatus getAt(AcDbEvalContextPair& pair) const;
	virtual void insertAt(const AcDbEvalContextPair& pair);
	virtual AcDbEvalContextIterator* newIterator() const;
	virtual void removeAt(const ACHAR* szKey);
};

#include "IcArxPackPop.h"
