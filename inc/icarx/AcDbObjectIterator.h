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
***     Description: Declaration of AcDbObjectIterator class
***
*****************************************************************************/
#pragma once

#include "../AcDbCore2dDefs.h"
#include "../rxobject.h"
#include "../AcHeapOpers.h"
#include "../dbid.h"

class AcDbEntity;
class AcDbSpaceIterator;

#include "IcArxPackPush.h"

class AcDbObjectIterator
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcDbSystemInternals;

private:
	AcDbSpaceIterator* mpImpIterator = nullptr;

private:
	AcDbObjectIterator();

public:
	ACRX_DECLARE_MEMBERS(AcDbObjectIterator);

	~AcDbObjectIterator();

	ACDBCORE2D_PORT bool done() const;
	ACDBCORE2D_PORT AcDbEntity* entity();
	ACDBCORE2D_PORT AcDbObjectId objectId();
	void setPosition(AcDbEntity* pEnt);
	void setPosition(AcDbObjectId pObj);
	ACDBCORE2D_PORT void step(bool backwards = false, bool skipDeleted = true);
	ACDBCORE2D_PORT void start(bool atEnd = false);
};

#include "IcArxPackPop.h"
