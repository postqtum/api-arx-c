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

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcBrLoop;
class AcBrEdge;
class AcBrLoopEdgeTraverser;
class AcBrVertexEdgeTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrEdgeLoopTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrEdgeLoopTraverser);

	AcBrEdgeLoopTraverser();
	AcBrEdgeLoopTraverser(const AcBrEdgeLoopTraverser& src);
	~AcBrEdgeLoopTraverser();
	AcBrEdgeLoopTraverser& operator=(const AcBrEdgeLoopTraverser& src);
	AcBr::ErrorStatus getEdge(AcBrEdge& edge) const;
	AcBr::ErrorStatus getLoop(AcBrLoop& loop) const;
	AcBr::ErrorStatus setEdge(AcBrEdge& edge);
	AcBr::ErrorStatus setEdge(const AcBrEdge& edge);
	AcBr::ErrorStatus setEdge(const AcBrVertexEdgeTraverser& vertexEdge);
	AcBr::ErrorStatus setEdgeAndLoop(AcBrLoopEdgeTraverser& loopEdge);
	AcBr::ErrorStatus setEdgeAndLoop(const AcBrLoopEdgeTraverser& loopEdge);
	AcBr::ErrorStatus setLoop(const AcBrLoop& loop);
};

#include "inc/icarx/IcArxPackPop.h"
