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
***     Description: Declaration of AcDbObjectIdGraph class
***
*****************************************************************************/
#pragma once

#include "../dbidmap.h"

#include "AcDbObjectIdGraphNode.h"

#include "IcArxPackPush.h"

class AcDbObjectIdGraph : public AcDbGraph
{
private:
	AcDbIdMapping mIdNodeMap;

public:
	AcDbObjectIdGraph();
	~AcDbObjectIdGraph();

	Acad::ErrorStatus addNode(AcDbObjectIdGraphNode*);
	Acad::ErrorStatus delNode(AcDbObjectIdGraphNode*);
	AcDbObjectIdGraphNode* findNode(const AcDbObjectId) const;
	AcDbObjectIdGraphNode* idNode(int idx) const;
};

#include "IcArxPackPop.h"

inline AcDbObjectIdGraphNode* AcDbObjectIdGraph::idNode(int idx) const
{
	return static_cast<AcDbObjectIdGraphNode*>(node(idx));
}
