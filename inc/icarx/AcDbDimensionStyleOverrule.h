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
***     Description: Declaration of AcDbDimensionStyleOverrule class
***
*****************************************************************************/
#pragma once

#include "AcDbDimension.h"

#include "IcArxPackPush.h"

class AcDbDimensionStyleOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbDimensionStyleOverrule);

	ACDBCORE2D_PORT AcDbDimensionStyleOverrule();

	ACDBCORE2D_PORT virtual AcDbObjectId dimensionStyle(const AcDbDimension* pSubject);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus getDimstyleData(const AcDbDimension* pSubject,
															  AcDbDimStyleTableRecord*& pRecord);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setDimensionStyle(AcDbDimension* pSubject,
																AcDbObjectId dimStyleId);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setDimstyleData(AcDbDimension* pSubject,
															  AcDbDimStyleTableRecord* pRecord);
	ACDBCORE2D_PORT virtual Acad::ErrorStatus setDimstyleData(AcDbDimension* pSubject,
															  AcDbObjectId dimstyleId);
};

#include "IcArxPackPop.h"
