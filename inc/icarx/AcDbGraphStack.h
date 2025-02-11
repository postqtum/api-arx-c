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
***     Description: Declaration of AcDbGraphStack class
***
*****************************************************************************/
#pragma once

#include "AcDbGraphNode.h"

#include "IcArxPackPush.h"

class AcDbGraphStack : public AcHeapOperators
{
private:
	AcDbVoidPtrArray mStack;

public:
	AcDbGraphStack(int initPhysicalLength = 0, int initGrowLength = 8);
	~AcDbGraphStack() = default;

	bool isEmpty() const;
	AcDbGraphNode* pop();
	Acad::ErrorStatus push(AcDbGraphNode*);
	AcDbGraphNode* top() const;
};

#include "IcArxPackPop.h"

inline bool AcDbGraphStack::isEmpty() const
{
	return mStack.isEmpty();
}

inline AcDbGraphNode* AcDbGraphStack::top() const
{
	return isEmpty() ? nullptr : static_cast<AcDbGraphNode*>(mStack.last());
}
