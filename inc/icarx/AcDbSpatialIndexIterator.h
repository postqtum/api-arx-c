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
***     Description: Declaration of AcDbSpatialIndexIterator class
***
*****************************************************************************/
#pragma once

#include "AcDbFilteredBlockIterator.h"
#include "AcDbSpatialIndex.h"

class AcDbImpSpatialIndexIterator;
class AcDbSpatialFilter;

#include "IcArxPackPush.h"

class AcDbSpatialIndexIterator : public AcDbFilteredBlockIterator
{
private:
	AcDbImpSpatialIndexIterator* m_Imp;

public:
	AcDbSpatialIndexIterator(const AcDbSpatialIndex* pIndex, const AcDbSpatialFilter* pFilter);
	~AcDbSpatialIndexIterator();
	AcDbSpatialIndexIterator(const AcDbSpatialIndexIterator&) = delete;
	AcDbSpatialIndexIterator& operator=(const AcDbSpatialIndexIterator&) = delete;

	virtual Acad::ErrorStatus accepts(AcDbObjectId id, bool& stat) const;
	virtual double estimatedHitFraction() const;
	virtual AcDbObjectId id() const;
	virtual AcDbObjectId next();
	virtual Acad::ErrorStatus seek(AcDbObjectId id);
	virtual Acad::ErrorStatus start();
};

#include "IcArxPackPop.h"
