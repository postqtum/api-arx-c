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
***     Description: Declaration of AcDbGraph class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcDbGraph : public AcHeapOperators
{
	friend class AcDbGraphNode;

private:
	AcDbVoidPtrArray mNodes;
	int mCycleNodes = 0;
	bool mDirty = false;

private:
	AcDbGraph(const AcDbGraph&) = delete;
	AcDbGraph& operator=(const AcDbGraph&) = delete;

	void setDirty() { mDirty = true; }

protected:
	Acad::ErrorStatus clearAllCycles();

public:
	AcDbGraph(AcDbGraphNode* pRoot = nullptr);
	virtual ~AcDbGraph();

	Acad::ErrorStatus addEdge(AcDbGraphNode* pFrom, AcDbGraphNode* pTo);
	Acad::ErrorStatus addNode(AcDbGraphNode*);
	Acad::ErrorStatus breakCycleEdge(AcDbGraphNode* pFrom, AcDbGraphNode* pTo);
	void clearAll(uint8_t flags);
	Acad::ErrorStatus delNode(AcDbGraphNode*);
	virtual bool findCycles(AcDbGraphNode* pStart = nullptr);
	void getOutgoing(AcDbVoidPtrArray&);
	bool isEmpty() const { return numNodes() == 0; }
	AcDbGraphNode* node(int idx) const { return static_cast<AcDbGraphNode*>(mNodes.at(idx)); }
	int numNodes() const { return mNodes.length(); }
	void reset();
	AcDbGraphNode* rootNode() const { return (numNodes() > 0) ? node(0) : nullptr; }
	void setNodeGrowthRate(int rate);
};

#include "IcArxPackPop.h"
