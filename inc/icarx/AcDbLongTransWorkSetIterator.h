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
***     Description: Declaration of AcDbLongTransWorkSetIterator class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

#include "AcDbObjectId.h"

#include "IcArxPackPush.h"

class AcDbLongTransWorkSetIterator : public AcRxObject
{
public:
	~AcDbLongTransWorkSetIterator() = default;

	ACRX_DECLARE_MEMBERS(AcDbLongTransWorkSetIterator);

	virtual bool curObjectIsErased() const = 0;
	virtual bool curObjectIsPrimary() const = 0;
	virtual bool curObjectIsRemoved() const = 0;
	virtual bool done() = 0;
	virtual AcDbObjectId objectId() const = 0;
	virtual void start(bool incRemovedObjs = false, bool incSecondaryObjs = false) = 0;
	virtual void step() = 0;
};

#include "IcArxPackPop.h"
