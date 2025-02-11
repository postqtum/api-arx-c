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
***     Description: Declaration of AcRxMemberQueryContext class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

class AcRxMemberIterator;
class AcRxMemberQueryContextImp;

#include "IcArxPackPush.h"

class AcRxMemberQueryContext : public Pimpl::ApiPart<AcRxObject, AcRxMemberQueryContextImp>
{
	friend class AcRxMemberQueryContextImp;

protected:
	ACBASE_PORT AcRxMemberQueryContext();
	ACBASE_PORT ~AcRxMemberQueryContext();

	virtual AcRxMemberIterator* subNewMemberIterator(
			const AcArray<const AcRxClass*>& facets) const = 0;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxMemberQueryContext, ACBASE_PORT);

	ACBASE_PORT AcRxMemberIterator* newMemberIterator(
			const AcArray<const AcRxClass*>& facets) const;
};

#include "IcArxPackPop.h"
