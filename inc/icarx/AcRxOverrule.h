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
***     Description: Declaration of AcRxOverrule class
***
*****************************************************************************/
#pragma once

#include "AcRxOverruleBase.h"

#include "IcArxPackPush.h"

#pragma warning(disable : 4275)

class ACBASE_PORT AcRxOverrule : public AcRxOverruleBase
{
public:
	ACRX_DECLARE_MEMBERS(AcRxOverrule);

	~AcRxOverrule();

	static Acad::ErrorStatus addOverrule(AcRxClass* pClass, AcRxOverrule* pOverrule,
										 bool bAddAtLast = false);
	static Acad::ErrorStatus removeOverrule(AcRxClass* pClass, AcRxOverrule* pOverrule);
	static bool hasOverrule(const AcRxObject* pSubject, AcRxClass* pOverruleClass);
	static bool isOverruling();
	static void setIsOverruling(bool bIsOverruling);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const = 0;
};

#include "IcArxPackPop.h"
