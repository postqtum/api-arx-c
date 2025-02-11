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
***     Description: Declaration of AcDbAnnoAlertDisabler class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcDbAnnoAlertDisabler
{
private:
	AcDbObjectId m_objId;

public:
	ACDBCORE2D_PORT AcDbAnnoAlertDisabler(const AcDbObjectId& objId);
	ACDBCORE2D_PORT ~AcDbAnnoAlertDisabler();
	AcDbAnnoAlertDisabler(const AcDbAnnoAlertDisabler&) = delete;
	AcDbAnnoAlertDisabler& operator=(const AcDbAnnoAlertDisabler&) = delete;
};

#include "IcArxPackPop.h"
