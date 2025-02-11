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
***     Description: Declaration of AcRxMemberQueryEngine class
***
*****************************************************************************/
#pragma once

#include "AcRxMemberReactor.h"
#include "AcRxMemberQueryContext.h"

class AcRxPromotingQueryContext;
class AcRxMemberQueryEngineImp;
class AcRxFacetProvider;

#include "IcArxPackPush.h"

class AcRxMemberQueryEngine : public Pimpl::ApiPart<void, AcRxMemberQueryEngineImp>
{
	friend class AcRxMemberQueryEngineImp;

private:
	AcRxMemberQueryEngine(AcRxMemberQueryEngineImp*);
	~AcRxMemberQueryEngine();

public:
	ACBASE_PORT Acad::ErrorStatus addFacetProvider(AcRxFacetProvider* pProvider);
	ACBASE_PORT Acad::ErrorStatus removeFacetProvider(AcRxFacetProvider* pProvider);
	ACBASE_PORT AcRxMember* find(const AcRxObject* pO, const ACHAR* name,
								 const AcRxMemberQueryContext* pContext = nullptr) const;
	ACBASE_PORT AcRxMemberIterator* newMemberIterator(
			const AcRxObject* pO, const AcRxMemberQueryContext* pContext = nullptr) const;
	ACBASE_PORT const AcRxMemberQueryContext* defaultContext();
	ACBASE_PORT const AcRxPromotingQueryContext* promotingContext();
	ACBASE_PORT static AcRxMemberQueryEngine* theEngine();
	ACBASE_PORT void addReactor(AcRxMemberReactor* pReactor);
	ACBASE_PORT void removeReactor(AcRxMemberReactor* pReactor);
};

#include "IcArxPackPop.h"
