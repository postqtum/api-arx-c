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
***     Description: Declaration of AcDbDwfReference class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayReference.h"

#include "IcArxPackPush.h"

class AcDbDwfReference : public AcDbUnderlayReference
{
protected:
	Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
	ACDB_DECLARE_MEMBERS(AcDbDwfReference);
	AcDbDwfReference();
	~AcDbDwfReference();

	bool isFramePlottable() const override;
	bool isFrameVisible() const override;
};

#include "IcArxPackPop.h"
