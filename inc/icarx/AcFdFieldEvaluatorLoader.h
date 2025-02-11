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
***     Description: Declaration of AcFdFieldEvaluatorLoader class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AcDbCore2dDefs.h"

class AcDbField;
class AcFdFieldEvaluator;

#include "IcArxPackPush.h"

class AcFdFieldEvaluatorLoader : public AcRxObject
{
	friend class AcFdSystemInternals;

protected:
	void* mpImpObj = nullptr;

public:
	ACRX_DECLARE_MEMBERS(AcFdFieldEvaluatorLoader);

	ACDBCORE2D_PORT AcFdFieldEvaluatorLoader();
	ACDBCORE2D_PORT AcFdFieldEvaluatorLoader(void*);
	ACDBCORE2D_PORT ~AcFdFieldEvaluatorLoader();

	ACDBCORE2D_PORT virtual AcFdFieldEvaluator* findEvaluator(AcDbField* pField,
															  const ACHAR*& pszEvalId);
	ACDBCORE2D_PORT virtual AcFdFieldEvaluator* getEvaluator(const ACHAR* pszEvalId);
};

#include "IcArxPackPop.h"
