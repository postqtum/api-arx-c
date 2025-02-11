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
***     Description: Declaration of AcDbEvalGraph class
***
*****************************************************************************/
#pragma once

#include "AcDbObject.h"
#include "AcDbDatabase.h"

class AcDbEvalEdgeInfo;
class AcDbEvalExpr;
class AcDbEvalContext;
class AcDbEvalIdMap;

using AcDbEvalNodeId = uint32_t;
using AcDbEvalNodeIdArray = AcArray<AcDbEvalNodeId>;
using AcDbEvalEdgeInfoArray = AcArray<AcDbEvalEdgeInfo*>;

#include "IcArxPackPush.h"

class AcDbEvalGraph : public AcDbObject
{
public:
	enum NodeId
	{
		kNullNodeId = 0
	};

public:
	ACDB_DECLARE_MEMBERS(AcDbEvalGraph);

	AcDbEvalGraph();
	~AcDbEvalGraph();

	virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray& activatedNodes) const;
	virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray& activatedNodes,
									   AcDbEvalNodeIdArray* pActiveSubgraph) const;
	virtual Acad::ErrorStatus activate(const AcDbEvalNodeIdArray& activatedNodes,
									   AcDbEvalNodeIdArray* pActiveSubgraph,
									   AcDbEvalNodeIdArray* pCycleNodes) const;
	virtual Acad::ErrorStatus addEdge(const AcDbEvalNodeId& idFrom, const AcDbEvalNodeId& idTo);
	virtual Acad::ErrorStatus addEdge(const AcDbEvalNodeId& idFrom, const AcDbEvalNodeId& idTo,
									  bool bInvertible);
	virtual Acad::ErrorStatus addGraph(AcDbEvalGraph* pGraphToAdd, AcDbEvalIdMap*& idMap);
	virtual Acad::ErrorStatus addNode(AcDbEvalExpr* pNode, AcDbEvalNodeId& id);
	static Acad::ErrorStatus createGraph(AcDbObject* pObj, const ACHAR* pKey);
	static Acad::ErrorStatus createGraph(AcDbDatabase* pDb, const ACHAR* pKey);
	virtual bool equals(const AcDbEvalGraph* pOther) const;
	virtual Acad::ErrorStatus evaluate() const;
	virtual Acad::ErrorStatus evaluate(const AcDbEvalContext* pContext) const;
	virtual Acad::ErrorStatus evaluate(const AcDbEvalContext* pContext,
									   const AcDbEvalNodeIdArray* activatedNodes) const;
	virtual Acad::ErrorStatus getAllNodes(AcDbEvalNodeIdArray& nodes) const;
	virtual Acad::ErrorStatus getEdgeInfo(const AcDbEvalNodeId& nodeFrom,
										  const AcDbEvalNodeId& nodeTo,
										  AcDbEvalEdgeInfo& einfo) const;
	static Acad::ErrorStatus getGraph(const AcDbObject* pObj, const ACHAR* pKey,
									  AcDbEvalGraph** pGraph, const AcDb::OpenMode mode);
	static Acad::ErrorStatus getGraph(AcDbDatabase* pDb, const ACHAR* pKey, AcDbEvalGraph** pGraph,
									  const AcDb::OpenMode mode);
	virtual Acad::ErrorStatus getIncomingEdges(const AcDbEvalNodeId& nodeId,
											   AcDbEvalEdgeInfoArray& edges) const;
	virtual Acad::ErrorStatus getIsActive(const AcDbEvalNodeId& id, bool& bIsActive) const;
	virtual Acad::ErrorStatus getNode(const AcDbEvalNodeId& nodeId, AcDb::OpenMode mode,
									  AcDbObject** ppNode) const;
	virtual Acad::ErrorStatus getOutgoingEdges(const AcDbEvalNodeId& nodeId,
											   AcDbEvalEdgeInfoArray& edges) const;
	static bool hasGraph(const AcDbObject* pObj, const ACHAR* pKey);
	static bool hasGraph(AcDbDatabase* pDb, const ACHAR* pKey);
	virtual bool isSubgraphOf(const AcDbEvalGraph* pOther) const;
	virtual Acad::ErrorStatus postInDatabase(AcDbObjectId& objId, AcDbDatabase* pDb);
	virtual Acad::ErrorStatus removeEdge(const AcDbEvalNodeId& idFrom, const AcDbEvalNodeId& idTo);
	static Acad::ErrorStatus removeGraph(AcDbObject* pObj, const ACHAR* pKey);
	static Acad::ErrorStatus removeGraph(AcDbDatabase* pDb, const ACHAR* pKey);
	virtual Acad::ErrorStatus removeNode(const AcDbEvalNodeId& id);
	virtual Acad::ErrorStatus removeNode(AcDbEvalExpr* pNode);
	static Acad::ErrorStatus replaceGraph(AcDbObject* pObj, const ACHAR* pKey, AcDbObjectId grphId);
};

#include "IcArxPackPop.h"
