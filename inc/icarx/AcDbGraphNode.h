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
***     Description: Declaration of AcDbGraphNode class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"
#include "IcArxAssert.h"

#include "IcArxPackPush.h"

class AcDbGraphNode : public AcHeapOperators
{
	friend class AcDbGraph;

public:
	enum Flags
	{
		kNone = 0x00,
		kVisited = 0x01,
		kOutsideRefed = 0x02,
		kSelected = 0x04,
		kInList = 0x08,
		kListAll = 0x0E,
		kFirstLevel = 0x10,
		kUnresTree = 0x20,
		kAll = 0x2F
	};

private:
	AcDbVoidPtrArray mOutgoing;
	AcDbVoidPtrArray mIncoming;
	void* mpData = nullptr;
	uint8_t mFlags = 0;
	AcDbGraph* mpOwner = nullptr;
	AcDbVoidPtrArray mCycleOut;
	AcDbVoidPtrArray mCycleIn;

private:
	AcDbGraphNode(const AcDbGraphNode&) = delete;
	AcDbGraphNode& operator=(const AcDbGraphNode&) = delete;

public:
	AcDbGraphNode(void* pData = nullptr);
	virtual ~AcDbGraphNode();

	Acad::ErrorStatus addRefTo(AcDbGraphNode*);
	Acad::ErrorStatus clear(uint8_t flags);
	AcDbGraphNode* cycleIn(int idx) const;
	AcDbGraphNode* cycleOut(int idx) const;
	void* data() const { return mpData; }
	Acad::ErrorStatus disconnectAll();
	AcDbGraphNode* in(int idx) const { return static_cast<AcDbGraphNode*>(mIncoming.at(idx)); }
	bool isCycleNode() const { return !mCycleIn.isEmpty() || !mCycleOut.isEmpty(); }
	bool isMarkedAs(uint8_t flag) const { return (this->mFlags & flag) != 0; }
	Acad::ErrorStatus markAs(uint8_t flags);
	Acad::ErrorStatus markTree(uint8_t flags, AcDbVoidPtrArray* = nullptr);
	AcDbGraphNode* nextCycleNode() const;
	int numCycleIn() const { return mCycleIn.length(); }
	int numCycleOut() const { return mCycleOut.length(); }
	int numIn() const { return mIncoming.length(); }
	int numOut() const { return mOutgoing.length(); }
	AcDbGraphNode* out(int idx) const { return static_cast<AcDbGraphNode*>(mOutgoing.at(idx)); }
	AcDbGraph* owner() const { return mpOwner; }
	Acad::ErrorStatus removeRefTo(AcDbGraphNode*);
	void setData(void* pData) { mpData = pData; }
	void setEdgeGrowthRate(int outEdgeRate, int inEdgeRate);
};

#include "IcArxPackPop.h"

inline AcDbGraphNode* AcDbGraphNode::cycleIn(int idx) const
{
	return static_cast<AcDbGraphNode*>(mCycleIn.isEmpty() ? nullptr : mCycleIn.at(idx));
}

inline AcDbGraphNode* AcDbGraphNode::cycleOut(int idx) const
{
	return static_cast<AcDbGraphNode*>(mCycleOut.isEmpty() ? nullptr : mCycleOut.at(idx));
}

inline AcDbGraphNode* AcDbGraphNode::nextCycleNode() const
{
	return cycleOut(0);
}
