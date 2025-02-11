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
***     Description: Declaration of AcBrVertexEdgeTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcBrEdge;
class AcBrVertex;

#include "inc/icarx/IcArxPackPush.h"

class AcBrVertexEdgeTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrVertexEdgeTraverser);

	AcBrVertexEdgeTraverser();
	AcBrVertexEdgeTraverser(const AcBrVertexEdgeTraverser& src);
	~AcBrVertexEdgeTraverser();
	AcBrVertexEdgeTraverser& operator=(const AcBrVertexEdgeTraverser& src);
	AcBr::ErrorStatus getEdge(AcBrEdge& edge) const;
	AcBr::ErrorStatus getVertex(AcBrVertex& vertex) const;
	AcBr::ErrorStatus setEdge(const AcBrEdge& edge);
	AcBr::ErrorStatus setVertex(const AcBrVertex& vertex);
};

#include "inc/icarx/IcArxPackPop.h"
