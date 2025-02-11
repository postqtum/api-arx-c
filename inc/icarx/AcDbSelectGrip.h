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
***     Description: Declaration of AcDbSelectGrip class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbSelectGrip : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbSelectGrip, ACDBCORE2D_PORT);

	virtual bool SelectGrip(const AcDbEntity* pEnt, const AcGiViewportDraw* pVd,
							const void* pAppData) = 0;
};

#include "IcArxPackPop.h"
