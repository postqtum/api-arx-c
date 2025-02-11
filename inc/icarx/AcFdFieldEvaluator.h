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
***     Description: Declaration of AcFdFieldEvaluator class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../acadstrc.h"
#include "../AcDbCore2dDefs.h"
#include "acut_str_util.h"

class AcDbField;
class AcDbDatabase;
class AcFdFieldResult;
class AcString;

#include "IcArxPackPush.h"

class AcFdFieldEvaluator : public AcRxObject
{
	friend class AcFdSystemInternals;

protected:
	void* mpImpObj = nullptr;

protected:
	AcFdFieldEvaluator(void*);

public:
	ACRX_DECLARE_MEMBERS(AcFdFieldEvaluator);

	ACDBCORE2D_PORT AcFdFieldEvaluator();
	ACDBCORE2D_PORT ~AcFdFieldEvaluator();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus compile(AcDbField* pField, AcDbDatabase* pDb,
													  AcFdFieldResult* pResult);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus evaluate(AcDbField* pField, int nContext,
													   AcDbDatabase* pDb, AcFdFieldResult* pResult);
	ACDBCORE2D_PORT virtual const ACHAR* evaluatorId() const;
	ACDBCORE2D_PORT virtual const ACHAR* evaluatorId(AcDbField* pField);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus format(AcDbField* pField, AcString& sValue);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus format(AcDbField* pField, ACHAR*& pszValue) final;
	ACDBCORE2D_PORT virtual Acad::ErrorStatus initialize(AcDbField* pField);
};

#include "IcArxPackPop.h"

inline Acad::ErrorStatus AcFdFieldEvaluator::format(AcDbField* pField, ACHAR*& pszValue)
{
	AcString sValue;
	return ::acutAcStringToAChar(sValue, pszValue, this->format(pField, sValue));
}
