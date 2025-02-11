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
***     Description:
***
*****************************************************************************/
#pragma once

#include "AcGraphNode.h"

#include <map>

class AcImpGraph;
class AcDbObject;

using NodeIdToPtrMap = std::map<AcGraphNode::Id, AcGraphNode*>;

#include "icarx/IcArxPackPush.h"

class AcGraph : public AcRxObject
{
	friend class AcGraphNode;
	friend class AcImpGraphNode;
	friend class AcImpGraph;

public:
	enum PartialUndoCode
	{
		kAddNodePartialUndoCode = 0,
		kRemoveNodePartialUndoCode,
		kModifyNodePartialUndoCode,
		kModifyNextNewNodeIdPartialUndoCode,
	};

	using iterator = NodeIdToPtrMap::iterator;
	using const_iterator = NodeIdToPtrMap::const_iterator;

protected:
	AcImpGraph* mpImpGraph;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGraph, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT explicit AcGraph(bool bCreateImp = true);
	ACDBCORE2D_PORT ~AcGraph();

	AcGraph(const AcGraph& graph) = delete;
	AcGraph& operator=(const AcGraph& graph) = delete;

	ACDBCORE2D_PORT Acad::ErrorStatus addGraphNode(AcGraphNode* pNewNode);
	ACDBCORE2D_PORT Acad::ErrorStatus addGraphNode(AcGraphNode* pNewNode, AcGraphNode::Id nodeId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* pUndoFiler,
															   PartialUndoCode code,
															   AcGraphNode::Id& nodeId);
	ACDBCORE2D_PORT const_iterator begin() const;
	ACDBCORE2D_PORT iterator begin();
	ACDBCORE2D_PORT void clear(bool bDelete);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	ACDBCORE2D_PORT const_iterator end() const;
	ACDBCORE2D_PORT iterator end();
	ACDBCORE2D_PORT AcGraphNode* getGraphNodePtr(AcGraphNode::Id nodeId) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getRelatedNodes(const AcArray<AcGraphNode*>& nodes,
													  AcArray<AcGraphNode*>& relatedNodes) const;
	ACDBCORE2D_PORT virtual uint32_t graphId() const;
	ACDBCORE2D_PORT Acad::ErrorStatus merge(const AcGraph& graph);
	ACDBCORE2D_PORT Acad::ErrorStatus moveAndMerge(const AcArray<AcGraphNode*>& nodesToMove);
	ACDBCORE2D_PORT AcDbObject* owningObject() const;
	ACDBCORE2D_PORT Acad::ErrorStatus removeGraphNode(AcGraphNode* pNode, bool bDelete = true);
	ACDBCORE2D_PORT virtual void setGraphId(uint32_t id);
	ACDBCORE2D_PORT void setOwningObject(AcDbObject* pObj);
	ACDBCORE2D_PORT size_t size() const;
};

#include "icarx/IcArxPackPop.h"
