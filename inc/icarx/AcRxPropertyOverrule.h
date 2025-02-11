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
***     Description: Declaration of AcRxPropertyOverrule class
***
*****************************************************************************/
#pragma once

#include "AcRxMemberOverrule.h"

class AcRxProperty;

#include "IcArxPackPush.h"

class AcRxPropertyOverrule : public AcRxMemberOverrule
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxPropertyOverrule, ACBASE_PORT);

	ACBASE_PORT virtual Acad::ErrorStatus getValue(const AcRxProperty* pProp, const AcRxObject* pO,
												   AcRxValue& value) const;
	ACBASE_PORT virtual Acad::ErrorStatus setValue(const AcRxProperty* pProp, AcRxObject* pO,
												   const AcRxValue& value) const;
};

#include "IcArxPackPop.h"
