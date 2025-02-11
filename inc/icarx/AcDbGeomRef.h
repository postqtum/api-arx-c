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
***     Description: Declaration of AcDbGeomRef class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcDbEntity;

#include "IcArxPackPush.h"

class AcDbGeomRef : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbGeomRef, ACDBCORE2D_PORT);
	ACDBCORE2D_PORT	~AcDbGeomRef() = default;

	virtual AcDbEntity* createEntity() const = 0;
	virtual Acad::ErrorStatus evaluateAndCacheGeometry() = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isValid() const = 0;
	virtual void reset() = 0;
};

#include "IcArxPackPop.h"
