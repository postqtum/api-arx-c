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
***     Description:
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "rxboiler.h"
#include "acbasedefs.h"

#include "icarx/IcArxPackPush.h"

class AcRxIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxIterator, ACBASE_PORT);

	virtual bool done() const = 0;
	virtual bool next() = 0;
	virtual AcRxObject* object() const = 0;
};

#include "icarx/IcArxPackPop.h"
