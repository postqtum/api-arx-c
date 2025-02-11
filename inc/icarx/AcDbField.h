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
***     Description: Declaration of AcDbField class
***
*****************************************************************************/
#pragma once

#include "AcDbEnumMode.h"
#include "AcDbObject.h"
#include "../AcString.h"
#include "../AcValue.h"

class AcDbField;
class AcFdFieldValue;
struct AcHyperlink;

using AcDbFieldArray = AcArray<AcDbField*>;

#include "IcArxPackPush.h"

class AcDbField : public AcDbObject
{
public:
	enum EvalContext
	{
		kOpen = (0x1 << 0),
		kSave = (0x1 << 1),
		kPlot = (0x1 << 2),
		kEtransmit = (0x1 << 3),
		kRegen = (0x1 << 4),
		kDemand = (0x1 << 5),
		kPreview = (0x1 << 6),
		kPlotPreview = (0x1 << 7),
	};

	enum EvalOption
	{
		kDisable = 0,
		kOnOpen = (0x1 << 0),
		kOnSave = (0x1 << 1),
		kOnPlot = (0x1 << 2),
		kOnEtransmit = (0x1 << 3),
		kOnRegen = (0x1 << 4),
		kOnDemand = (0x1 << 5),
		kAutomatic = (kOnOpen | kOnSave | kOnPlot | kOnEtransmit | kOnRegen | kOnDemand),
	};

	enum EvalStatus
	{
		kNotYetEvaluated = (0x1 << 0),
		kSuccess = (0x1 << 1),
		kEvaluatorNotFound = (0x1 << 2),
		kSyntaxError = (0x1 << 3),
		kInvalidCode = (0x1 << 4),
		kInvalidContext = (0x1 << 5),
		kOtherError = (0x1 << 6),
	};

	enum FieldCodeFlag
	{
		kFieldCode = (0x1 << 0),
		kEvaluatedText = (0x1 << 1),
		kEvaluatedChildren = (0x1 << 2),
		kObjectReference = (0x1 << 3),
		kAddMarkers = (0x1 << 4),
		kEscapeBackslash = (0x1 << 5),
		kStripOptions = (0x1 << 6),
		kPreserveFields = (0x1 << 7),
		kTextField = (0x1 << 8),
		kPreserveOptions = (0x1 << 9),
		kDetachChildren = (0x1 << 10),
		kChildObjectReference = (0x1 << 11),
		kForExpression = (0x1 << 12),
	};

	enum FilingOption
	{
		kSkipFilingResult = (0x1 << 0),
	};

	enum State
	{
		kInitialized = (0x1 << 0),
		kCompiled = (0x1 << 1),
		kModified = (0x1 << 2),
		kEvaluated = (0x1 << 3),
		kHasCache = (0x1 << 4),
		kHasFormattedString = (0x1 << 5),
	};

public:
	ACDB_DECLARE_MEMBERS(AcDbField);

	ACDBCORE2D_PORT AcDbField();
	ACDBCORE2D_PORT AcDbField(const ACHAR* pszFieldCode, bool bTextField = false);
	ACDBCORE2D_PORT ~AcDbField();

	ACDBCORE2D_PORT int childCount() const;
	Acad::ErrorStatus convertToTextField();
	ACDBCORE2D_PORT AcValue::DataType dataType() const;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus evaluate(int nContext, AcDbDatabase* pDb,
											   int* pNumFound = nullptr, int* pNumEvaluated = nullptr);
	ACDBCORE2D_PORT AcDbField::EvalOption evaluationOption() const;
	ACDBCORE2D_PORT AcDbField::EvalStatus evaluationStatus() const;
	AcDbField::EvalStatus evaluationStatus(int* pnErrCode) const
	{
		AcString* pNullStr = nullptr;
		return this->evaluationStatus(pnErrCode, pNullStr);
	}
	ACDBCORE2D_PORT AcDbField::EvalStatus evaluationStatus(int* pnErrCode,
														   AcString* pszErrMsg) const;
	AcDbField::EvalStatus evaluationStatus(int* pnErrCode, ACHAR** pszErrMsg) const
	{
		AcString sErrMsg;
		AcString* pErrMsgStr = pszErrMsg ? &sErrMsg : nullptr;
		const AcDbField::EvalStatus es = this->evaluationStatus(pnErrCode, pErrMsgStr);
		if (pszErrMsg != nullptr)
		{
			if (*pErrMsgStr == nullptr)
				*pszErrMsg = nullptr;
			else
				::acutNewString(sErrMsg.kwszPtr(), *pszErrMsg);
		}
		return es;
	}
	ACDBCORE2D_PORT const ACHAR* evaluatorId() const;
	ACDBCORE2D_PORT AcDbField::FilingOption filingOption() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getChild(int iIndex, AcDbField*& pField, AcDb::OpenMode mode);
	ACDBCORE2D_PORT Acad::ErrorStatus getData(const ACHAR* pszKey, AcValue* pData) const;
	ACDBCORE2D_PORT const ACHAR* getFieldCode(AcDbField::FieldCodeFlag nFlag,
											  AcArray<AcDbField*>* pChildFields = nullptr,
											  AcDb::OpenMode mode = AcDb::kForRead) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFieldCode(AcString& sFieldCode,
												   AcDbField::FieldCodeFlag nFlag,
												   AcArray<AcDbField*>* pChildFields = nullptr,
												   AcDb::OpenMode mode = AcDb::kForRead) const;
	Acad::ErrorStatus getFieldCode(ACHAR*& pszFieldCode, AcDbField::FieldCodeFlag nFlag,
								   AcArray<AcDbField*>* pChildFields = nullptr,
								   AcDb::OpenMode mode = AcDb::kForRead) const
	{
		AcString sFieldCode;
		return ::acutAcStringToAChar(sFieldCode, pszFieldCode,
									 this->getFieldCode(sFieldCode, nFlag, pChildFields, mode));
	}
	ACDBCORE2D_PORT const ACHAR* getFormat() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getFormat(AcString& sFormat) const;
	Acad::ErrorStatus getFormat(ACHAR*& pszFormat) const
	{
		return ::acutGetAcStringConvertToAChar(this, &AcDbField::getFormat, pszFormat);
	}
	ACDBCORE2D_PORT Acad::ErrorStatus getHyperlink(AcString* psName, AcString* psDescription,
												   AcString* psSubLocation,
												   AcString* psDisplayString,
												   int32_t* pFlag) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getHyperlink(AcHyperlink& hlink) const;
	ACDBCORE2D_PORT const ACHAR* getValue() const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValue(AcFdFieldValue& value) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValue(AcString& sValue) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValue(AcValue& value) const;
	Acad::ErrorStatus getValue(ACHAR*& pszValue) const
	{
		return ::acutGetAcStringConvertToAChar(this, &AcDbField::getValue, pszValue);
	}
	ACDBCORE2D_PORT bool hasHyperlink() const;
	bool isTextField() const;
	ACDBCORE2D_PORT Acad::ErrorStatus postInDatabase(AcDbDatabase* pDb);
	ACDBCORE2D_PORT Acad::ErrorStatus removeHyperlink();
	ACDBCORE2D_PORT Acad::ErrorStatus setData(const ACHAR* pszKey, const AcValue* pData);
	ACDBCORE2D_PORT Acad::ErrorStatus setData(const ACHAR* pszKey, const AcValue* pData,
											  bool bRecursive);
	ACDBCORE2D_PORT Acad::ErrorStatus setEvaluationOption(AcDbField::EvalOption nEvalOption);
	ACDBCORE2D_PORT Acad::ErrorStatus setEvaluatorId(const ACHAR* pszEvaluatorId);
	ACDBCORE2D_PORT Acad::ErrorStatus setFieldCode(
			const ACHAR* pszFieldCode, AcDbField::FieldCodeFlag nFlag = (AcDbField::FieldCodeFlag)0,
			AcDbFieldArray* pChildFields = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus setFilingOption(AcDbField::FilingOption nOption);
	ACDBCORE2D_PORT Acad::ErrorStatus setFormat(const ACHAR* pszFormat);
	ACDBCORE2D_PORT Acad::ErrorStatus setHyperlink(const ACHAR* pszName,
												   const ACHAR* pszDescription,
												   const ACHAR* pszSubLocation = nullptr);
	ACDBCORE2D_PORT Acad::ErrorStatus setHyperlink(const ACHAR* pszName,
												   const ACHAR* pszDescription,
												   const ACHAR* pszSubLocation, int32_t lFlag);
	ACDBCORE2D_PORT Acad::ErrorStatus setHyperlink(const AcHyperlink& hlink);
	ACDBCORE2D_PORT Acad::ErrorStatus setInObject(AcDbObject* pObj, const ACHAR* pszPropName);
	ACDBCORE2D_PORT AcDbField::State state() const;
	ACDBCORE2D_PORT Acad::ErrorStatus subClose() override;
};

#include "IcArxPackPop.h"
