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
class AcBrComplex;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrepComplexTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrepComplexTraverser);

	AcBrBrepComplexTraverser();
	AcBrBrepComplexTraverser(const AcBrBrepComplexTraverser& src);
	~AcBrBrepComplexTraverser();
	AcBrBrepComplexTraverser& operator=(const AcBrBrepComplexTraverser& src);
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getComplex(AcBrComplex& complex) const;
	AcBr::ErrorStatus setBrep(const AcBrBrep& brep);
	AcBr::ErrorStatus setBrepAndComplex(const AcBrComplex& complex);
	AcBr::ErrorStatus setComplex(const AcBrComplex& complex);
};

#include "inc/icarx/IcArxPackPop.h"
