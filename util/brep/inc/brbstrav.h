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
class AcBrShell;

#include "inc/icarx/IcArxPackPush.h"

class AcBrBrepShellTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrBrepShellTraverser);

	AcBrBrepShellTraverser();
	AcBrBrepShellTraverser(const AcBrBrepShellTraverser& src);
	~AcBrBrepShellTraverser();
	AcBrBrepShellTraverser& operator=(const AcBrBrepShellTraverser& src);
	AcBr::ErrorStatus getBrep(AcBrBrep& brep) const;
	AcBr::ErrorStatus getShell(AcBrShell& shell) const;
	AcBr::ErrorStatus setBrep(const AcBrBrep& brep);
	AcBr::ErrorStatus setBrepAndShell(const AcBrShell& shell);
	AcBr::ErrorStatus setShell(const AcBrShell& shell);
};

#include "inc/icarx/IcArxPackPop.h"
