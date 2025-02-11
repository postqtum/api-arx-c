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
***     Description: Declaration of AcDbPropertiesOverrule class
***
*****************************************************************************/
#pragma once

#include "../rxoverrule.h"
#include "AcDbEntity.h"

#include "IcArxPackPush.h"

class AcDbPropertiesOverrule : public AcRxOverrule
{
public:
	ACRX_DECLARE_MEMBERS(AcDbPropertiesOverrule);

	ACDBCORE2D_PORT AcDbPropertiesOverrule();

	ACDBCORE2D_PORT virtual Acad::ErrorStatus getClassID(const AcDbObject* pSubject, CLSID* pClsid);
	ACDBCORE2D_PORT virtual void list(const AcDbEntity* pSubject);
};

#include "IcArxPackPop.h"
