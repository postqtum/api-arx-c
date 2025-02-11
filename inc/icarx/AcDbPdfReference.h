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
***     Description: Declaration of AcDbPdfReference class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayReference.h"

#include "IcArxPackPush.h"

class AcDbPdfReference : public AcDbUnderlayReference
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbPdfReference);

	ACDBCORE2D_PORT AcDbPdfReference();
	ACDBCORE2D_PORT ~AcDbPdfReference();

	static uint8_t contrastDefault();
	static uint8_t fadeDefault();
	bool isFramePlottable() const override;
	bool isFrameVisible() const override;
};

#include "IcArxPackPop.h"
