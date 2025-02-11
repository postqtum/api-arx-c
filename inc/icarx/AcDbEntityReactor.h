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
***     Description: Declaration of AcDbEntityReactor class
***
*****************************************************************************/
#pragma once

#include "AcDbObjectReactor.h"

class AcDbEntity;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbEntityReactor : public AcDbObjectReactor
{
protected:
	ACDBCORE2D_PORT AcDbEntityReactor();

public:
	ACRX_DECLARE_MEMBERS(AcDbEntityReactor);

	ACDBCORE2D_PORT ~AcDbEntityReactor();

	virtual void dragCloneToBeDeleted(const AcDbEntity* /*pOriginalObj*/,
									  const AcDbEntity* /*pClone*/){}
	virtual void modifiedGraphics(const AcDbEntity*) {}
};

#include "IcArxPackPop.h"
