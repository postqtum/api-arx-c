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
***     Description: Declaration of AcRxMemberIterator class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

class AcRxMemberIteratorImp;

#include "IcArxPackPush.h"

class AcRxMemberIterator : public Pimpl::ApiPart<void, AcRxMemberIteratorImp>
{
	friend class AcRxMemberIteratorImp;

private:
	AcRxMemberIterator(AcRxMemberIteratorImp*);

protected:
	ACBASE_PORT AcRxMemberIterator();

public:
	ACBASE_PORT virtual ~AcRxMemberIterator();

	ACBASE_PORT virtual AcRxMember* current() const;
	ACBASE_PORT virtual bool done();
	ACBASE_PORT virtual AcRxMember* find(const ACHAR* name) const;
	ACBASE_PORT virtual bool next();
};

#include "IcArxPackPop.h"
