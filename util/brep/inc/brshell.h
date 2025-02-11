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
***     Description: Declaration of AcBrShell class
***
*****************************************************************************/
#pragma once

#include "inc/adesk.h"
#include "inc/rxobject.h"
#include "inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class AcBrComplex;

#include "inc/icarx/IcArxPackPush.h"

class AcBrShell : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrShell);

	AcBrShell();
	AcBrShell(const AcBrShell& src);
	~AcBrShell();
	AcBrShell& operator=(const AcBrShell& src);
	AcBr::ErrorStatus getComplex(AcBrComplex& complex) const;
	AcBr::ErrorStatus getType(AcBr::ShellType& shellType) const;
};

#include "inc/icarx/IcArxPackPop.h"
