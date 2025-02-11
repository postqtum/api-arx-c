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
***     Description: Declaration of AcDbLayerIndexIterator class
***
*****************************************************************************/
#pragma once

#include "AcDbLayerIndex.h"
#include "AcDbFilteredBlockIterator.h"

class AcDbImpLayerIndexIterator;
class AcDbLayerFilter;

#include "IcArxPackPush.h"

class AcDbLayerIndexIterator : public AcDbFilteredBlockIterator
{
private:
	AcDbImpLayerIndexIterator* m_Imp;

public:
	AcDbLayerIndexIterator(const AcDbLayerIndex* pIndex, const AcDbLayerFilter* pFilter);
	~AcDbLayerIndexIterator();
	AcDbLayerIndexIterator(const AcDbLayerIndexIterator&) = delete;
	AcDbLayerIndexIterator& operator=(const AcDbLayerIndexIterator&) = delete;

	Acad::ErrorStatus accepts(AcDbObjectId id, bool& idPassesFilter) const override;
	double estimatedHitFraction() const override;
	AcDbObjectId id() const override;
	AcDbObjectId next() override;
	Acad::ErrorStatus seek(AcDbObjectId id) override;
	Acad::ErrorStatus start() override;
};

#include "IcArxPackPop.h"
