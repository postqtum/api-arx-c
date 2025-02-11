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
***     Description: Declaration of AcDbEvalVariant class
***
*****************************************************************************/

#pragma once

#include "AcDbObject.h"
#include "AcDb.h"
#include "../adsdef.h"
#include "../AcString.h"
#include "../gepnt2d.h"
#include "../gepnt3d.h"

class AcDbEvalVariant;
class AcDbImpEvalContext;
class AcRxValue;
class AcRxValueType;

#include "IcArxPackPush.h"

class AcDbEvalVariant
		: public resbuf
		, public AcRxObject
{
protected:
	void init();

public:
	ACRX_DECLARE_MEMBERS(AcDbEvalVariant);

	AcDbEvalVariant();
	AcDbEvalVariant(const AcDbEvalVariant& other);
	ACDBCORE2D_PORT AcDbEvalVariant(AcDbEvalVariant&& other);
	AcDbEvalVariant(const AcDbEvalVariant* pOther);
	AcDbEvalVariant(double dVal);
	AcDbEvalVariant(short iVal);
	AcDbEvalVariant(const ACHAR* szVal);
	AcDbEvalVariant(int32_t lVal);
	AcDbEvalVariant(const AcDbObjectId& id);
	AcDbEvalVariant(const AcGePoint2d& pt);
	AcDbEvalVariant(const AcGePoint3d& pt);
	AcDbEvalVariant(const resbuf& rb);
	~AcDbEvalVariant();
	AcDbEvalVariant& operator=(const resbuf& rb);
	AcDbEvalVariant& operator=(double dVal);
	AcDbEvalVariant& operator=(short iVal);
	AcDbEvalVariant& operator=(int32_t lVal);
	AcDbEvalVariant& operator=(const ACHAR* szVal);
	AcDbEvalVariant& operator=(const AcDbEvalVariant& other);
	ACDBCORE2D_PORT AcDbEvalVariant& operator=(AcDbEvalVariant&& other);
	AcDbEvalVariant& operator=(const AcDbObjectId& id);
	AcDbEvalVariant& operator=(const AcGePoint2d& pt);
	AcDbEvalVariant& operator=(const AcGePoint3d& pt);
	bool operator==(const AcDbEvalVariant& val) const;
	bool operator!=(const AcDbEvalVariant& val) const;
	bool operator<(const AcDbEvalVariant& val) const;
	bool operator<=(const AcDbEvalVariant& val) const;
	bool operator>(const AcDbEvalVariant& val) const;
	bool operator>=(const AcDbEvalVariant& val) const;

	void clear();
	Acad::ErrorStatus copyFrom(const AcRxObject* pOther) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	Acad::ErrorStatus fromAcRxValue(const AcRxValue& value);
	AcDb::DwgDataType getType() const;
	Acad::ErrorStatus getValue(double& value) const;
	Acad::ErrorStatus getValue(short& value) const;
	Acad::ErrorStatus getValue(int32_t& value) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValue(AcString& value) const;
	Acad::ErrorStatus getValue(AcDbObjectId& value, AcDbDatabase* pDb = nullptr) const;
	ACDBCORE2D_PORT Acad::ErrorStatus getValue(AcGePoint3d& value) const;
	Acad::ErrorStatus getValue(AcGePoint2d& value) const;
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, double value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, short value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, int32_t value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, const AcString& value);
	ACDBCORE2D_PORT Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, const wchar_t* value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, AcDbObjectId value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, const AcGePoint3d& value);
	Acad::ErrorStatus setValue(AcDb::DxfCode groupcode, const AcGePoint2d& value);
	Acad::ErrorStatus toAcRxValue(const AcRxValueType& type, AcRxValue& value) const;
};

#include "IcArxPackPop.h"
