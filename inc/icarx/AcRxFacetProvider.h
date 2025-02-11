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
***     Description: Declaration of AcRxFacetProvider class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

class AcRxMemberQueryContext;

#include "IcArxPackPush.h"

class AcRxFacetProvider : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxFacetProvider, ACBASE_PORT);

	virtual void getFacets(const AcRxObject* pO, const AcRxMemberQueryContext* pContext,
						   AcArray<const AcRxClass*>& facets) = 0;
};

#include "IcArxPackPop.h"
