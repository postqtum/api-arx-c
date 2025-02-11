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

#include "adesk.h"
#include "AdAChar.h"
#include "acarray.h"
#include "rxobject.h"

#include "icarx/acut_str_util.h"

class AcDbEvalVariant;
typedef struct tagVARIANT VARIANT;
typedef struct _SYSTEMTIME SYSTEMTIME;
class AcDbObjectId;
class AcGePoint2d;
class AcGePoint3d;
class AcCmColor;
struct resbuf;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcValueImp;

#include "icarx/IcArxPackPush.h"

class AcValue : public AcRxObject
{
	friend class AcSystemInternals;

public:
	enum DataType
	{
		kUnknown = 0,
		kLong = (0x1 << 0),
		kDouble = (0x1 << 1),
		kString = (0x1 << 2),
		kDate = (0x1 << 3),
		kPoint = (0x1 << 4),
		k3dPoint = (0x1 << 5),
		kObjectId = (0x1 << 6),
		kBuffer = (0x1 << 7),
		kResbuf = (0x1 << 8),
		kGeneral = (0x1 << 9),
		kColor = (0x1 << 10),
	};

	enum FormatOption
	{
		kFormatOptionNone = 0,
		kForEditing = (0x1 << 0),
		kForExpression = (0x1 << 1),
		kUseMaximumPrecision = (0x1 << 2),
		kIgnoreMtextFormat = (0x1 << 3),
	};

	enum ParseOption
	{
		kParseOptionNone = 0,
		kSetDefaultFormat = (0x1 << 0),
		kPreserveMtextFormat = (0x1 << 1),
		kConvertTextToValue = (0x1 << 2),
		kChangeDataType = (0x1 << 3),
		kParseTextForFieldCode = (0x1 << 4),
	};

	enum UnitType
	{
		kUnitless = 0,
		kDistance = (0x1 << 0),
		kAngle = (0x1 << 1),
		kArea = (0x1 << 2),
		kVolume = (0x1 << 3),
		kCurrency = (0x1 << 4),
		kPercentage = (0x1 << 5),
		kAngleNotTransformed = (0x1 << 16),
	};

protected:
	AcValueImp* mpImpObj = nullptr;

private:
	static bool ACharAllocHelper(const AcString& sValue, ACHAR*& pszValue, bool bRet)
	{
		pszValue = nullptr;
		if (bRet)
			::acutNewString(sValue.kwszPtr(), pszValue);
		return bRet;
	}

public:
	ACRX_DECLARE_MEMBERS(AcValue);

	ACDBCORE2D_PORT AcValue();
	ACDBCORE2D_PORT AcValue(AcValue::DataType nDataType);
	explicit ACDBCORE2D_PORT AcValue(int32_t lValue);
	ACDBCORE2D_PORT AcValue(double fValue);
	ACDBCORE2D_PORT AcValue(double x, double y);
	ACDBCORE2D_PORT AcValue(double x, double y, double z);
	ACDBCORE2D_PORT AcValue(const ACHAR* pszValue);
	ACDBCORE2D_PORT AcValue(const AcCmColor& var);
	ACDBCORE2D_PORT AcValue(const AcDbEvalVariant& evalVar);
	ACDBCORE2D_PORT AcValue(const AcDbObjectId& id);
	ACDBCORE2D_PORT AcValue(const AcGePoint2d& pt);
	ACDBCORE2D_PORT AcValue(const AcGePoint3d& pt);
	explicit ACDBCORE2D_PORT AcValue(const IcArx::Integers::Time64& date);
	ACDB_PORT AcValue(const SYSTEMTIME& date);
	ACDB_PORT AcValue(const VARIANT& var);
	ACDBCORE2D_PORT AcValue(const resbuf& rb);
	ACDBCORE2D_PORT AcValue(const std::tm& date);
	ACDBCORE2D_PORT AcValue(const void* pBuf, uint32_t dwBufSize);
	ACDBCORE2D_PORT AcValue(AcValue&& value);
	ACDBCORE2D_PORT AcValue(const AcValue& value);
	ACDBCORE2D_PORT ~AcValue();
	ACDBCORE2D_PORT AcValue& operator=(int32_t lValue);
	ACDBCORE2D_PORT AcValue& operator=(double fValue);
	ACDBCORE2D_PORT AcValue& operator=(const ACHAR* pszValue);
	ACDBCORE2D_PORT AcValue& operator=(const AcCmColor& clr);
	ACDBCORE2D_PORT AcValue& operator=(const AcDbObjectId& objId);
	ACDBCORE2D_PORT AcValue& operator=(const AcGePoint2d& pt);
	ACDBCORE2D_PORT AcValue& operator=(const AcGePoint3d& pt);
	ACDBCORE2D_PORT AcValue& operator=(const AcDbEvalVariant& evalVar);
	ACDB_PORT AcValue& operator=(const VARIANT& var);
	ACDBCORE2D_PORT AcValue& operator=(const resbuf& rb);
	ACDBCORE2D_PORT AcValue& operator=(IcArx::Integers::Time64 date);
	ACDBCORE2D_PORT AcValue& operator=(AcValue&& value);
	ACDBCORE2D_PORT AcValue& operator=(const AcValue& value);
	ACDBCORE2D_PORT bool operator==(const AcValue& val) const;
	ACDBCORE2D_PORT bool operator!=(const AcValue& val) const;
	ACDBCORE2D_PORT operator int32_t() const;
	ACDBCORE2D_PORT operator double() const;
	ACDBCORE2D_PORT operator const ACHAR*() const;
	ACDBCORE2D_PORT operator AcDbObjectId() const;
	ACDBCORE2D_PORT operator AcGePoint2d() const;
	ACDBCORE2D_PORT operator AcGePoint3d() const;
	explicit ACDBCORE2D_PORT operator IcArx::Integers::Time64() const;

	static ACDB_PORT bool isValidDataType(const VARIANT& var);

	ACDBCORE2D_PORT bool convertTo(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
	ACDBCORE2D_PORT bool convertTo(AcValue::DataType nDataType, AcValue::UnitType nUnitType,
								   bool bResetIfIncompatible);
	ACDBCORE2D_PORT AcValue::DataType dataType() const;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	ACDBCORE2D_PORT const ACHAR* format() const;
	ACDBCORE2D_PORT AcString format(const ACHAR* pszFormat) const;
	bool format(ACHAR*& pszValue) const
	{
		AcString sValue;
		return ACharAllocHelper(sValue, pszValue, this->format(sValue));
	}
	ACDBCORE2D_PORT bool format(AcString& sValue) const;
	ACDBCORE2D_PORT bool format(const ACHAR* pszFormat, AcString& sValue) const;
	bool format(const ACHAR* pszFormat, ACHAR*& pszValue) const
	{
		AcString sValue;
		return ACharAllocHelper(sValue, pszValue, this->format(pszFormat, sValue));
	}
	ACDBCORE2D_PORT AcString format(AcValue::FormatOption nOption);
	ACDBCORE2D_PORT AcString format(const ACHAR* pszFormat, AcValue::FormatOption nOption);
	ACDBCORE2D_PORT bool get(int32_t& lValue) const;
	ACDBCORE2D_PORT bool get(double& fValue) const;
	ACDBCORE2D_PORT bool get(double& x, double& y) const;
	ACDBCORE2D_PORT bool get(double& x, double& y, double& z) const;
	ACDBCORE2D_PORT bool get(const ACHAR*& pszValue) const;
	bool get(ACHAR*& pszValue) const
	{
		AcString sValue;
		return ACharAllocHelper(sValue, pszValue, this->get(sValue));
	}
	ACDBCORE2D_PORT bool get(AcCmColor& clr) const;
	ACDBCORE2D_PORT bool get(AcDbEvalVariant& evalVar) const;
	ACDBCORE2D_PORT bool get(AcDbObjectId& objId) const;
	ACDBCORE2D_PORT bool get(AcGePoint2d& pt) const;
	ACDBCORE2D_PORT bool get(AcGePoint3d& pt) const;
	ACDBCORE2D_PORT bool get(AcString& sValue) const;
	ACDBCORE2D_PORT bool get(IcArx::Integers::Time64& date) const;
	ACDB_PORT bool get(SYSTEMTIME& date) const;
	ACDB_PORT bool get(VARIANT& var) const;
	ACDBCORE2D_PORT bool get(resbuf** pRb) const;
	ACDBCORE2D_PORT bool get(std::tm& date) const;
	ACDBCORE2D_PORT bool get(void*& pBuf, uint32_t& dwBufSize) const;
	ACDBCORE2D_PORT const ACHAR* getFormat() const;
	bool isEqualTo(const AcRxObject* pOther) const override;
	ACDBCORE2D_PORT bool isValid() const;
	ACDBCORE2D_PORT bool parse(const ACHAR* pszText, AcValue::DataType nDataType,
							   AcValue::UnitType nUnitType, const ACHAR* pszFormat,
							   AcValue::ParseOption nOption, const AcDbObjectId* pTextStyleId);
	ACDBCORE2D_PORT bool reset();
	ACDBCORE2D_PORT bool reset(AcValue::DataType nDataType);
	ACDBCORE2D_PORT bool resetValue();
	ACDBCORE2D_PORT bool set(int32_t lValue);
	ACDBCORE2D_PORT bool set(double fValue);
	ACDBCORE2D_PORT bool set(double x, double y);
	ACDBCORE2D_PORT bool set(double x, double y, double z);
	ACDBCORE2D_PORT bool set(AcValue::DataType nDataType, const ACHAR* pszValue);
	ACDBCORE2D_PORT bool set(const ACHAR* pszValue);
	ACDBCORE2D_PORT bool set(const AcCmColor& clr);
	ACDBCORE2D_PORT bool set(const AcDbEvalVariant& evalVar);
	ACDBCORE2D_PORT bool set(const AcDbObjectId& objId);
	ACDBCORE2D_PORT bool set(const AcGePoint2d& pt);
	ACDBCORE2D_PORT bool set(const AcGePoint3d& pt);
	ACDBCORE2D_PORT bool set(const IcArx::Integers::Time64& date);
	ACDB_PORT bool set(const SYSTEMTIME& date);
	ACDB_PORT bool set(const VARIANT& var);
	ACDBCORE2D_PORT bool set(const resbuf& rb);
	ACDBCORE2D_PORT bool set(const std::tm& date);
	ACDBCORE2D_PORT bool set(const void* pBuf, uint32_t dwBufSize);
	ACDBCORE2D_PORT bool set(const AcValue& value);
	ACDBCORE2D_PORT bool setFormat(const ACHAR* pszFormat);
	ACDBCORE2D_PORT bool setUnitType(AcValue::UnitType nUnitType);
	ACDBCORE2D_PORT AcValue::UnitType unitType() const;
};

#include "icarx/IcArxPackPop.h"

using AcValueArray = AcArray<AcValue, AcArrayObjectCopyReallocator<AcValue>>;
