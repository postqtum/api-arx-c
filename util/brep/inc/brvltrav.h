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
***     Description: Declaration of AcBrVertexLoopTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcBrLoop;
class AcBrVertex;
class AcBrLoopVertexTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrVertexLoopTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrVertexLoopTraverser);

	AcBrVertexLoopTraverser();
	AcBrVertexLoopTraverser(const AcBrVertexLoopTraverser& src);
	~AcBrVertexLoopTraverser();
	AcBrVertexLoopTraverser& operator=(const AcBrVertexLoopTraverser& src);
	AcBr::ErrorStatus getLoop(AcBrLoop& loop) const;
	AcBr::ErrorStatus getVertex(AcBrVertex& vertex) const;
	AcBr::ErrorStatus setLoop(const AcBrLoop& loop);
	AcBr::ErrorStatus setVertex(const AcBrVertex& vertex);
	AcBr::ErrorStatus setVertexAndLoop(const AcBrLoopVertexTraverser& LoopVertexTraverser);
};

#include "inc/icarx/IcArxPackPop.h"
