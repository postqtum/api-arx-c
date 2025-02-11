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
***     Description: Declaration of AcRxValueIterator class
***
*****************************************************************************/
#pragma once

#include "../pimplapi.h"
#include "../acbasedefs.h"
#include "AcRxValue.h"

class AcRxValueIteratorImp;

#include "IcArxPackPush.h"

class AcRxValueIterator : public Pimpl::ApiPart<void, AcRxValueIteratorImp>
{
	friend class AcRxValueIteratorImp;

private:
	AcRxValueIterator(AcRxValueIteratorImp*);

protected:
	ACBASE_PORT AcRxValueIterator();

public:
	ACBASE_PORT virtual ~AcRxValueIterator();

	ACBASE_PORT virtual AcRxValue current() const;
	ACBASE_PORT virtual bool done();
	ACBASE_PORT virtual bool next();
};

#include "IcArxPackPop.h"
