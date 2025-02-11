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
***     Description: Declaration of AcDbXrefGraph class
***
*****************************************************************************/
#pragma once

#include "AcDbGraph.h"
#include "AcDbXrefGraphNode.h"

#include "IcArxPackPush.h"

class AcDbXrefGraph : public AcDbGraph
{
public:
	AcDbXrefGraph(AcDbXrefGraphNode* pHostDwg = nullptr);
	~AcDbXrefGraph();

	virtual bool findCycles(AcDbGraphNode* pStart = nullptr);
	AcDbXrefGraphNode* hostDwg() const;
	bool markUnresolvedTrees();
	AcDbXrefGraphNode* xrefNode(AcDbObjectId btrId) const;
	AcDbXrefGraphNode* xrefNode(const ACHAR* pName) const;
	AcDbXrefGraphNode* xrefNode(const AcDbDatabase* pDb) const;
	AcDbXrefGraphNode* xrefNode(int idx) const;
};

#include "IcArxPackPop.h"

inline AcDbXrefGraphNode* AcDbXrefGraph::hostDwg() const
{
	return static_cast<AcDbXrefGraphNode*>(rootNode());
}

inline AcDbXrefGraphNode* AcDbXrefGraph::xrefNode(int idx) const
{
	return static_cast<AcDbXrefGraphNode*>(node(idx));
}
