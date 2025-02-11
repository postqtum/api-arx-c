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
***     Description: Declaration of AcFdFieldResult class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"

class AcValue;

#include "IcArxPackPush.h"

class AcFdFieldResult : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcFdFieldResult);

	AcFdFieldResult();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus setEvaluationStatus(int nStatus, int dwErrCode = 0,
																  const ACHAR* pszMsg = nullptr);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setFieldValue(const AcValue* pValue);
};

#include "IcArxPackPop.h"
