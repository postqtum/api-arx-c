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
***     Description: Declaration of AcDbIndex class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcDbFilteredBlockIterator;
class AcDbFilter;
class AcDbIndexUpdateData;
class AcDbBlockChangeIterator;

#include "IcArxPackPush.h"

class AcDbIndex : public AcDbObject
{
	friend class AcDbImpIndex;

protected:
	//friend Acad::ErrorStatus processBTRIndexObjects(AcDbBlockTableRecord* pBTR, int indexCtlVal,
	//												AcDbBlockChangeIterator* pBlkChgIter,
	//												AcDbIndexUpdateData* pIdxUpdData);
	virtual Acad::ErrorStatus rebuildModified(AcDbBlockChangeIterator* iter);

public:
	ACDB_DECLARE_MEMBERS(AcDbIndex);

	AcDbIndex();
	~AcDbIndex();

	bool isUptoDate() const;
	AcDbDate lastUpdatedAt() const;
	AcDbDate lastUpdatedAtU() const;
	virtual AcDbFilteredBlockIterator* newIterator(const AcDbFilter* pFilter) const;
	virtual AcDbObjectId objectBeingIndexedId() const;
	virtual Acad::ErrorStatus rebuildFull(AcDbIndexUpdateData* pIdxData);
	void setLastUpdatedAt(const AcDbDate& time);
	void setLastUpdatedAtU(const AcDbDate& time);
};

#include "IcArxPackPop.h"
