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
***     Description: Declaration of AcRxDictionaryIterator class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "rxiter.h"
#include "AdAChar.h"

#include "icarx/IcArxPackPush.h"

class AcRxDictionaryIterator : public AcRxIterator
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDictionaryIterator, ACBASE_PORT);

	virtual uint32_t id() const = 0;
	virtual const ACHAR* key() const = 0;
	AcRxObject* object() const override = 0;
};

#include "icarx/IcArxPackPop.h"
