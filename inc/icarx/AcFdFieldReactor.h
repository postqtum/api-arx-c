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
***     Description: Declaration of AcFdFieldReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"
#include "../acarray.h"

class AcDbDatabase;

#include "IcArxPackPush.h"

class AcFdFieldReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcFdFieldReactor);

	ACDBCORE2D_PORT virtual ~AcFdFieldReactor() = default;

	virtual Acad::ErrorStatus beginEvaluateFields(int, AcDbDatabase*)
	{
		return Acad::eNotApplicable;
	}
	virtual Acad::ErrorStatus endEvaluateFields(int, AcDbDatabase*)
	{
		return Acad::eNotApplicable;
	}
};

#include "IcArxPackPop.h"

using FieldReactors = AcArray<AcFdFieldReactor*>;

ACDBCORE2D_PORT Acad::ErrorStatus acdbAddFieldReactor(AcFdFieldReactor* pReactor);
ACDBCORE2D_PORT Acad::ErrorStatus acdbRemoveFieldReactor(AcFdFieldReactor* pReactor);
