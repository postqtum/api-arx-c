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

class AcGePoint2d;
class AcBrLoop;
class AcBrVertex;
class AcBrFaceLoopTraverser;
class AcBrVertexLoopTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrLoopVertexTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrLoopVertexTraverser);

	AcBrLoopVertexTraverser();
	AcBrLoopVertexTraverser(const AcBrLoopVertexTraverser& src);
	~AcBrLoopVertexTraverser();
	AcBrLoopVertexTraverser& operator=(const AcBrLoopVertexTraverser& src);
	AcBr::ErrorStatus getLoop(AcBrLoop& loop) const;
	AcBr::ErrorStatus getParamPoint(AcGePoint2d*& ppoint) const;
	AcBr::ErrorStatus getParamPoint(AcGePoint2d& ppoint) const;
	AcBr::ErrorStatus getVertex(AcBrVertex& vertex) const;
	AcBr::ErrorStatus setLoop(AcBrFaceLoopTraverser& faceLoop);
	AcBr::ErrorStatus setLoop(const AcBrFaceLoopTraverser& faceLoop);
	AcBr::ErrorStatus setLoop(const AcBrLoop& loop);
	AcBr::ErrorStatus setLoopAndVertex(const AcBrVertexLoopTraverser& vertexLoop);
	AcBr::ErrorStatus setVertex(const AcBrVertex& vertex);
};

#include "inc/icarx/IcArxPackPop.h"
