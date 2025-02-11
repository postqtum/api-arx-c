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
class AcBrFace;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrepFaceTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrepFaceTraverser);

	AcBrBrepFaceTraverser();
	AcBrBrepFaceTraverser(const AcBrBrepFaceTraverser& src);
	~AcBrBrepFaceTraverser();
	AcBrBrepFaceTraverser& operator=(const AcBrBrepFaceTraverser& src);
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getFace(AcBrFace& face) const;
	AcBr::ErrorStatus setBrep(AcBrBrep& brep);
	AcBr::ErrorStatus setBrep(const AcBrBrep& brep);
	AcBr::ErrorStatus setBrepAndFace(const AcBrFace& face);
	AcBr::ErrorStatus setFace(AcBrFace& face);
	AcBr::ErrorStatus setFace(const AcBrFace& face);
};

#include "inc/icarx/IcArxPackPop.h"
