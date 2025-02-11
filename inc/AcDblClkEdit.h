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
***     Description: Declaration of AcDbDoubleClickEdit class
***
*****************************************************************************/
#pragma once

#include "gepnt3d.h"
#include "icarx/AcDbEntity.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDoubleClickEdit : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbDoubleClickEdit);

	virtual void finishEdit(void) = 0;
	virtual void startEdit(AcDbEntity* pEnt, AcGePoint3d pt) = 0;
};

#include "icarx/IcArxPackPop.h"
