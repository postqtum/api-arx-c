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
***     Description: Declaration of AcFdFieldValue class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../AcValue.h"

#include "IcArxPackPush.h"

class AcFdFieldValue : public AcValue
{
public:
	ACRX_DECLARE_MEMBERS(AcFdFieldValue);

	ACDBCORE2D_PORT AcFdFieldValue();
	ACDBCORE2D_PORT AcFdFieldValue(AcFdFieldValue::DataType nDataType);
	ACDBCORE2D_PORT AcFdFieldValue(int32_t lValue);
	ACDBCORE2D_PORT AcFdFieldValue(double fValue);
	ACDBCORE2D_PORT AcFdFieldValue(double x, double y);
	ACDBCORE2D_PORT AcFdFieldValue(double x, double y, double z);
	ACDBCORE2D_PORT AcFdFieldValue(const ACHAR* pszValue);
	ACDBCORE2D_PORT AcFdFieldValue(const AcDbEvalVariant& evalVar);
	ACDBCORE2D_PORT AcFdFieldValue(const AcDbObjectId& id);
	ACDBCORE2D_PORT AcFdFieldValue(const AcFdFieldValue& value);
	ACDBCORE2D_PORT AcFdFieldValue(const AcGePoint2d& pt);
	ACDBCORE2D_PORT AcFdFieldValue(const AcGePoint3d& pt);
	ACDBCORE2D_PORT AcFdFieldValue(const IcArx::Integers::Time64& date);
	ACDBCORE2D_PORT AcFdFieldValue(const resbuf& rb);
	ACDBCORE2D_PORT AcFdFieldValue(const std::tm& date);
	ACDB_PORT AcFdFieldValue(const VARIANT& var);
	ACDBCORE2D_PORT AcFdFieldValue(const void* pBuf, uint32_t dwBufSize);
};

#include "IcArxPackPop.h"
