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
***     Description: Declaration of AcBrShellFaceTraverser class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class AcBrShell;
class AcBrFace;
class AcBrComplexShellTraverser;

#include "inc/icarx/IcArxPackPush.h"

class AcBrShellFaceTraverser : public AcBrTraverser
{
public:
	ACRX_DECLARE_MEMBERS(AcBrShellFaceTraverser);

	AcBrShellFaceTraverser();
	AcBrShellFaceTraverser(const AcBrShellFaceTraverser& src);
	~AcBrShellFaceTraverser();
	AcBrShellFaceTraverser& operator=(const AcBrShellFaceTraverser& src);
	AcBr::ErrorStatus getFace(AcBrFace& face) const;
	AcBr::ErrorStatus getShell(AcBrShell& shell) const;
	AcBr::ErrorStatus setFace(const AcBrFace& face);
	AcBr::ErrorStatus setShell(const AcBrComplexShellTraverser& complexShellTraverser);
	AcBr::ErrorStatus setShell(const AcBrShell& shell);
	AcBr::ErrorStatus setShellAndFace(const AcBrFace& face);
};

#include "inc/icarx/IcArxPackPop.h"
