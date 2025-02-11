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
***     Description: Declaration of AcDbLayerIndex class
***
*****************************************************************************/
#pragma once

#include "AcDbIndex.h"

#include "IcArxPackPush.h"

class AcDbLayerIndex : public AcDbIndex
{
protected:
	Acad::ErrorStatus rebuildModified(AcDbBlockChangeIterator* iter) override;

public:
	ACDB_DECLARE_MEMBERS(AcDbLayerIndex);

	AcDbLayerIndex();
	~AcDbLayerIndex();

	Acad::ErrorStatus compute(AcDbLayerTable* pLT, AcDbBlockTableRecord* pBTR);
	AcDbFilteredBlockIterator* newIterator(const AcDbFilter* pFilter) const override;
	Acad::ErrorStatus rebuildFull(AcDbIndexUpdateData* pIdxData) override;
};
#include "IcArxPackPop.h"
