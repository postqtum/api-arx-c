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
***     Description: Declaration of AcBrMesh2dElement2dTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcBrMesh2d;
class AcBrElement2d;

#include "inc/icarx/IcArxPackPush.h"

class AcBrMesh2dElement2dTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrMesh2dElement2dTraverser);

	AcBrMesh2dElement2dTraverser();
	AcBrMesh2dElement2dTraverser(const AcBrMesh2dElement2dTraverser& src);
	~AcBrMesh2dElement2dTraverser();
	AcBrMesh2dElement2dTraverser& operator=(const AcBrMesh2dElement2dTraverser& src);
	AcBr::ErrorStatus getElement(AcBrElement2d& element2d) const;
	AcBr::ErrorStatus getMesh(AcBrMesh2d& mesh2d) const;
	AcBr::ErrorStatus setElement(const AcBrElement2d& element2d);
	AcBr::ErrorStatus setMesh(const AcBrMesh2d& mesh2d);
	AcBr::ErrorStatus setMeshAndElement(const AcBrElement2d& element2d);
};

#include "inc/icarx/IcArxPackPop.h"
