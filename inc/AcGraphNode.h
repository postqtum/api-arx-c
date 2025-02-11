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

#include "acarray.h"
#include "rxobject.h"
#include "AcHeapOpers.h"

class AcImpGraphNode;
class AcGraph;
class AcDbDwgFiler;
class AcDbDxfFiler;

#include "icarx/IcArxPackPush.h"

class AcGraphNode
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcGraph;
	friend class AcImpGraph;

public:
	using Id = uint32_t;

	enum
	{
		kNullId = 0
	};

protected:
	AcImpGraphNode* mpImpGraphNode;

protected:
	ACDBCORE2D_PORT explicit AcGraphNode(bool bCreateImp = true);

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcGraphNode, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT ~AcGraphNode();

	AcGraphNode(const AcGraphNode& node) = delete;
	AcGraphNode& operator=(const AcGraphNode& node) = delete;

	ACDBCORE2D_PORT virtual void backup();
	ACDBCORE2D_PORT Acad::ErrorStatus connectNode(AcGraphNode* pNode);
	ACDBCORE2D_PORT Acad::ErrorStatus disconnectAllNodes();
	ACDBCORE2D_PORT Acad::ErrorStatus disconnectNode(AcGraphNode* pNode);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getAdjacentNodes(AcArray<AcGraphNode*>& adjacentNodes) const;
	ACDBCORE2D_PORT bool isAdjacentTo(AcGraphNode* pNode) const;
	ACDBCORE2D_PORT Id nodeId() const;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus nodeToBeConnectedNotification(AcGraphNode* pNode);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus nodeToBeDisconnectedNotification(AcGraphNode* pNode);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus nodeToBeMovedNotification(
			AcGraph* pGraph, AcArray<AcGraphNode*>& otherNodesToMove);
	ACDBCORE2D_PORT AcGraph* owningGraph() const;
};

#include "icarx/IcArxPackPop.h"
