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
***     Description: Declaration of AcDbEvalExpr class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "AcDbEnumMode.h"
#include "AcDbDatabase.h"
#include "AcDbEvalVariant.h"

class AcDbEvalIdMap;
class AcDbEvalGraph;
class AcDbEvalContext;

using AcDbEvalNodeId = uint32_t;
using AcDbEvalNodeIdArray = AcArray<AcDbEvalNodeId>;

#include "IcArxPackPush.h"

class AcDbEvalExpr : public AcDbObject
{
	friend class AcDbImpEvalExpr;

protected:
	AcDbEvalVariant m_lastValue;

public:
	ACDB_DECLARE_MEMBERS(AcDbEvalExpr);

	AcDbEvalExpr();
	~AcDbEvalExpr();

	virtual void activated(AcDbEvalNodeIdArray& argumentActiveList);
	virtual void addedToGraph(AcDbEvalGraph* pGraph);
	virtual void adjacentEdgeAdded(const AcDbEvalNodeId& fromId, const AcDbEvalNodeId& toId,
								   bool bIsInvertible);
	virtual void adjacentEdgeRemoved(const AcDbEvalNodeId& adjEdgeNodeId);
	virtual void adjacentNodeRemoved(const AcDbEvalNodeId& adjNodeId);
	virtual void copiedIntoGraph(AcDbEvalGraph* pIntoGraph);
	virtual bool equals(const AcDbEvalExpr* pOther) const;
	virtual Acad::ErrorStatus evaluate(const AcDbEvalContext* ctxt);
	Acad::ErrorStatus getGraph(AcDbEvalGraph** pGraph, AcDb::OpenMode mode) const;
	virtual void graphEvalAbort(bool bNodeIsActive);
	virtual void graphEvalEnd(bool bNodeIsActive);
	virtual void graphEvalStart(bool bNodeIsActive);
	virtual bool isActivatable();
	virtual void movedFromGraph(AcDbEvalGraph* pFromGraph);
	virtual void movedIntoGraph(AcDbEvalGraph* pIntoGraph);
	AcDbEvalNodeId nodeId() const;
	virtual Acad::ErrorStatus postInDatabase(AcDbObjectId& objId, AcDbDatabase* pDb);
	virtual void remappedNodeIds(AcDbEvalIdMap& idMap);
	virtual void removedFromGraph(AcDbEvalGraph* pGraph);
	AcDbEvalVariant value() const;
};

#include "IcArxPackPop.h"
