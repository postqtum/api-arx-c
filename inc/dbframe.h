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
***     Description: Declaration of AcDbFrame class
***
*****************************************************************************/
#pragma once

#include "dbmain.h"
#include "gepnt3d.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbFrame : public AcDbEntity
{
protected:
	AcDbFrame();

public:
	ACDB_DECLARE_MEMBERS(AcDbFrame);
	~AcDbFrame();
};

#include "icarx/IcArxPackPop.h"
