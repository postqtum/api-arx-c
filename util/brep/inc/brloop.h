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
***     Description: Declaration of AcBrLoop class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class AcBrFace;

#include "inc/icarx/IcArxPackPush.h"

class AcBrLoop : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrLoop);

	AcBrLoop();
	AcBrLoop(const AcBrLoop& src);
	~AcBrLoop();
	AcBrLoop& operator=(const AcBrLoop& src);
	AcBr::ErrorStatus getFace(AcBrFace& face) const;
	AcBr::ErrorStatus getType(AcBr::LoopType& type) const;
};

#include "inc/icarx/IcArxPackPop.h"
