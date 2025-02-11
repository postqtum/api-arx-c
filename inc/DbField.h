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

#include "icarx/AcFd.h"
#include "icarx/AcHyperlink.h"
#include "icarx/AcDbField.h"

#include "AdAChar.h"
#include "AcValue.h"
#include "AcString.h"
#include "dbidar.h"

class AcFdFieldEngine;

ACDBCORE2D_PORT Acad::ErrorStatus acdbConvertFieldsToText(AcDbDatabase* pDb,
														  const AcStringArray* pEvalIds,
														  AcFd::ConvertFieldToText nOption);
ACDBCORE2D_PORT Acad::ErrorStatus acdbConvertFieldsToText(const AcDbObjectIdArray& objIds,
														  const AcStringArray* pEvalIds,
														  AcFd::ConvertFieldToText nOption);
ACDBCORE2D_PORT Acad::ErrorStatus acdbEvaluateFields(
		const AcDbObjectId& objId, int nContext, const ACHAR* pszPropName = nullptr,
		AcDbDatabase* pDb = nullptr, AcFd::EvalFields nEvalFlag = AcFd::kEvalRecursive,
		int* pNumFound = nullptr, int* pNumEvaluated = nullptr);
ACDBCORE2D_PORT Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectId& objId, int nContext,
													 const AcDbObjectIdArray* pFieldsToEvaluate,
													 const ACHAR* pszEvaluatorId, AcDbDatabase* pDb,
													 AcFd::EvalFields nEvalFlag, int* pNumFound,
													 int* pNumEvaluated);
ACDBCORE2D_PORT Acad::ErrorStatus acdbEvaluateFields(
		const AcDbObjectIdArray& objIds, int nContext, const ACHAR* pszPropName = nullptr,
		AcDbDatabase* pDb = nullptr, AcFd::EvalFields nEvalFlag = AcFd::kEvalRecursive,
		int* pNumFound = nullptr, int* pNumEvaluated = nullptr);
ACDBCORE2D_PORT Acad::ErrorStatus acdbEvaluateFields(const AcDbObjectIdArray& objIds, int nContext,
													 const AcDbObjectIdArray* pFieldsToEvaluate,
													 const ACHAR* pszEvaluatorId, AcDbDatabase* pDb,
													 AcFd::EvalFields nEvalFlag, int* pNumFound,
													 int* pNumEvaluated);
ACDBCORE2D_PORT bool acdbFindField(const ACHAR* pszText, int iSearchFrom, int& nStartPos,
								   int& nEndPos);
ACDBCORE2D_PORT AcFdFieldEngine* acdbGetFieldEngine();
ACDBCORE2D_PORT bool acdbGetFieldMarkers(const ACHAR*& pszPrefix, const ACHAR*& pszSuffix);
ACDBCORE2D_PORT AcDbField::EvalOption acdbGlobalFieldEvaluationOption();
ACDBCORE2D_PORT bool acdbHasFields(const ACHAR* pszText);
ACDBCORE2D_PORT Acad::ErrorStatus acdbMakeFieldCode(const ACHAR* pszFieldExpr, AcString& sFieldCode,
													const ACHAR* pszEvalId = nullptr,
													const ACHAR* pszFormat = nullptr,
													const AcHyperlink* pHyperlink = nullptr);
inline Acad::ErrorStatus acdbMakeFieldCode(const ACHAR* pszFieldExpr, ACHAR*& pszFieldCode,
										   const ACHAR* pszEvalId, const ACHAR* pszFormat,
										   const AcHyperlink* pHyperlink)
{
	AcString sFieldCode;
	return ::acutAcStringToAChar(
			sFieldCode, pszFieldCode,
			::acdbMakeFieldCode(pszFieldExpr, sFieldCode, pszEvalId, pszFormat, pHyperlink));
}
ACDBCORE2D_PORT Acad::ErrorStatus acdbSetGlobalFieldEvaluationOption(
		AcDbField::EvalOption nEvalOption);
