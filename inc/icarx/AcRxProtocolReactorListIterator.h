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
***     Description: Declaration of AcRxProtocolReactorListIterator class
***
*****************************************************************************/
#pragma once

#include "AcRxProtocolReactorList.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxProtocolReactorListIterator : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcRxProtocolReactorListIterator);

	virtual bool done() const = 0;
	virtual bool next() = 0;
	virtual AcRxProtocolReactorList* object() const = 0;
	virtual void start() = 0;
};

#include "IcArxPackPop.h"
