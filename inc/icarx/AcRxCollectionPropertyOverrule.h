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
***     Description: Declaration of AcRxCollectionPropertyOverrule class
***
*****************************************************************************/
#pragma once

#include "AcRxMemberOverrule.h"
#include "AcRxValueIterator.h"
#include "AcRxCollectionProperty.h"

#include "IcArxPackPush.h"

class AcRxCollectionPropertyOverrule : public AcRxMemberOverrule
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxCollectionPropertyOverrule, ACBASE_PORT);

	ACBASE_PORT virtual AcRxValueIterator* newValueIterator(const AcRxCollectionProperty* pProp,
															const AcRxObject* pO) const;
	ACBASE_PORT virtual Acad::ErrorStatus tryGetCount(const AcRxCollectionProperty* pProp,
													  const AcRxObject* pO, int& count) const;
};

#include "IcArxPackPop.h"
