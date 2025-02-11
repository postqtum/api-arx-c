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
***     Description: Declaration of AcDbObjectIdGraphNode class
***
*****************************************************************************/
#pragma once

#include "../graph.h"

#include "IcArxPackPush.h"

class AcDbObjectIdGraphNode : public AcDbGraphNode
{
private:
	AcDbObjectId mId;

public:
	AcDbObjectIdGraphNode(const AcDbObjectId id);
	~AcDbObjectIdGraphNode();

	AcDbObjectId id() const;
};

#include "IcArxPackPop.h"

inline AcDbObjectId AcDbObjectIdGraphNode::id() const
{
	return mId;
}
