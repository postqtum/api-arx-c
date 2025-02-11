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

class AcBrBrep;
class AcBrVertex;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrepVertexTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrepVertexTraverser);

	AcBrBrepVertexTraverser();
	AcBrBrepVertexTraverser(const AcBrBrepVertexTraverser& src);
	~AcBrBrepVertexTraverser();
	AcBrBrepVertexTraverser& operator=(const AcBrBrepVertexTraverser& src);
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getVertex(AcBrVertex& vertex) const;
	AcBr::ErrorStatus setBrep(const AcBrBrep& brep);
	AcBr::ErrorStatus setBrepAndVertex(const AcBrVertex& vertex);
	AcBr::ErrorStatus setVertex(const AcBrVertex& vertex);
};

#include "inc/icarx/IcArxPackPop.h"
