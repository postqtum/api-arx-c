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
***     Description: Declaration of AcDbLayerFilter class
***
*****************************************************************************/
#pragma once

#include "dbfilter.h"
#include "AdAChar.h"

#include "icarx/IcArxPackPush.h"

class AcDbLayerFilter : public AcDbFilter
{
public:
	ACDB_DECLARE_MEMBERS(AcDbLayerFilter);

	AcDbLayerFilter();
	~AcDbLayerFilter();

	Acad::ErrorStatus add(const ACHAR* pLayer);
	Acad::ErrorStatus getAt(int index, const ACHAR*& pName) const;
	AcRxClass* indexClass() const override;
	virtual bool isValid() const;
	int layerCount() const;
	Acad::ErrorStatus remove(const ACHAR* pLayer);
};

#include "icarx/IcArxPackPop.h"
