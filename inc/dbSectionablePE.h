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
***     Description: Declaration of AcDbSectionablePE class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"

#include "icarx/AcDbObject.h"

#include "icarx/IcArxPackPush.h"

class AcDbSectionablePE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbSectionablePE, ACDBCORE2D_PORT);

	virtual bool supportSection(const AcDbObject& pObject) = 0;
};

#include "icarx/IcArxPackPop.h"
