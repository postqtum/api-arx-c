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
***     Description: Declaration of AcFdFieldEngine class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"
#include "../DbField.h"

class AcDbField;
class AcFdFieldEvaluator;
class AcFdFieldEvaluatorLoader;

#include "IcArxPackPush.h"

class AcFdFieldEngine : public AcRxObject
{
	friend class AcFdSystemInternals;

protected:
	void* mpImpObj = nullptr;

public:
	ACRX_DECLARE_MEMBERS(AcFdFieldEngine);

	ACDBCORE2D_PORT AcFdFieldEngine();
	ACDBCORE2D_PORT ~AcFdFieldEngine();

	ACDBCORE2D_PORT AcDbField::EvalOption evaluationOption() const;
	ACDBCORE2D_PORT int evaluatorLoaderCount() const;
	ACDBCORE2D_PORT AcFdFieldEvaluator* findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId);
	ACDBCORE2D_PORT AcFdFieldEvaluator* getEvaluator(const ACHAR* pszEvalId);
	ACDBCORE2D_PORT AcFdFieldEvaluatorLoader* getEvaluatorLoader(int iIndex);
	ACDBCORE2D_PORT Acad::ErrorStatus registerEvaluatorLoader(AcFdFieldEvaluatorLoader* pLoader);
	ACDBCORE2D_PORT Acad::ErrorStatus setEvaluationOption(AcDbField::EvalOption nEvalOption);
	ACDBCORE2D_PORT Acad::ErrorStatus unregisterEvaluatorLoader(AcFdFieldEvaluatorLoader* pLoader);
};

#include "IcArxPackPop.h"
