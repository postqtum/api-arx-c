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
***     Description: Declaration of AcDbEvalEdgeInfo class
***
*****************************************************************************/
#pragma once

#include "AcDbEvalGraph.h"

class AcDbEvalEdgeInfo;

using AcDbEvalNodeId = uint32_t;

#include "IcArxPackPush.h"

class AcDbEvalIdMap
{
public:
	virtual AcDbEvalNodeId find(const AcDbEvalNodeId& key) = 0;
	virtual void kill() = 0;
};

class AcDbEvalEdgeInfo
{
private:
	AcDbEvalNodeId mIdFrom = AcDbEvalGraph::kNullNodeId;
	AcDbEvalNodeId mIdTo = AcDbEvalGraph::kNullNodeId;
	int32_t mFlags = 0;
	uint32_t mRefCount = 0;

public:
	AcDbEvalEdgeInfo() = default;
	AcDbEvalEdgeInfo(AcDbEvalNodeId from, AcDbEvalNodeId to, int32_t flags,
					 uint32_t count)
			: mIdFrom(from), mIdTo(to), mFlags(flags), mRefCount(count)
	{
	}
	bool operator==(const AcDbEvalEdgeInfo& other) const;

	AcDbEvalNodeId from() const;
	uint32_t refCount() const;
	bool isInvertible() const;
	bool isSuppressed() const;
	AcDbEvalNodeId to() const;
};

#include "IcArxPackPop.h"
