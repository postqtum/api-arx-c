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
***     Description: Declaration of AcDbSectionManagerIterator class
***
*****************************************************************************/
#pragma once

#include "AcDbSectionManager.h"

class AcDbImpSectionManager;

#include "IcArxPackPush.h"

class AcDbSectionManagerIterator
{
	friend class AcDbImpSectionManager;

protected:
	void* mpImpObj = nullptr;

protected:
	ACDB_PORT AcDbSectionManagerIterator(AcDbSectionManager* pMgr);

public:
	ACDB_PORT virtual ~AcDbSectionManagerIterator();

	ACDB_PORT bool done() const;
	ACDB_PORT AcDbObjectId getSection() const;
	ACDB_PORT Acad::ErrorStatus getSection(AcDbSection*& pSecPlane, AcDb::OpenMode openMode) const;
	ACDB_PORT void start();
	ACDB_PORT void step();
};

#include "IcArxPackPop.h"
