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
#include "brent.h"

#include "inc/icarx/IcArxPackPush.h"

class AcBrComplex : public AcBrEntity
{
public:
	ACRX_DECLARE_MEMBERS(AcBrComplex);

	AcBrComplex();
	AcBrComplex(const AcBrComplex& src);
	~AcBrComplex();
	AcBrComplex& operator=(const AcBrComplex& src);
};

#include "inc/icarx/IcArxPackPop.h"
