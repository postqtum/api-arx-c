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
class AcBrEdge;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrepEdgeTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrepEdgeTraverser);

	AcBrBrepEdgeTraverser();
	AcBrBrepEdgeTraverser(const AcBrBrepEdgeTraverser& src);
	~AcBrBrepEdgeTraverser();
	AcBrBrepEdgeTraverser& operator=(const AcBrBrepEdgeTraverser& src);
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getEdge(AcBrEdge& edge) const;
	AcBr::ErrorStatus setBrep(const AcBrBrep& brep);
	AcBr::ErrorStatus setBrepAndEdge(const AcBrEdge& edge);
	AcBr::ErrorStatus setEdge(const AcBrEdge& edge);
};

#include "inc/icarx/IcArxPackPop.h"
