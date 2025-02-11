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
***     Description: Declaration of AcDbInterferencePE class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"

#include "icarx/IcArxPackPush.h"

class AcDbInterferencePE : public AcRxObject
{
public:
	enum Flags
	{
		kDefault = 0x00,
	};

public:
	ACRX_DECLARE_MEMBERS(AcDbInterferencePE);

	virtual Acad::ErrorStatus createInterferenceObjects(AcArray<AcDbEntity*>& interferenceObjects,
														AcDbEntity* pEnt1, AcDbEntity* pEnt2,
														unsigned int flags) const = 0;
};

#include "icarx/IcArxPackPop.h"
