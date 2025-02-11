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
***     Description: Declaration of AcRxProtocolReactorIterator class
***
*****************************************************************************/
#pragma once

#include "AcRxProtocolReactor.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxProtocolReactorIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcRxProtocolReactorIterator);

	virtual bool done() const = 0;
	virtual bool next() = 0;
	virtual AcRxProtocolReactor* object() const = 0;
	virtual AcRxClass* reactorClass() const = 0;
	virtual void start() = 0;
};

#include "IcArxPackPop.h"
