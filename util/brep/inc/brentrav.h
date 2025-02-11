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
***     Description: Declaration of AcBrElement2dNodeTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "inc/gegbl.h"
#include "brgbl.h"
#include "brtrav.h"

class AcGePoint2d;
class AcGeVector3d;
class AcBrElement2d;
class AcBrNode;
class AcBrMesh2dElement2dTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrElement2dNodeTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrElement2dNodeTraverser);

	AcBrElement2dNodeTraverser();
	AcBrElement2dNodeTraverser(const AcBrElement2dNodeTraverser& src);
	~AcBrElement2dNodeTraverser();
	AcBrElement2dNodeTraverser& operator=(const AcBrElement2dNodeTraverser& src);
	AcBr::ErrorStatus getElement(AcBrElement2d& element) const;
	AcBr::ErrorStatus getNode(AcBrNode& node) const;
	AcBr::ErrorStatus getParamPoint(AcGePoint2d& point) const;
	AcBr::ErrorStatus getSurfaceNormal(AcGeVector3d& vector) const;
	AcBr::ErrorStatus setElement(const AcBrMesh2dElement2dTraverser& mesh2dElement2dTraverser);
	AcBr::ErrorStatus setElement(const AcBrElement2d& element);
	AcBr::ErrorStatus setNode(const AcBrNode& node);
};

#include "inc/icarx/IcArxPackPop.h"
