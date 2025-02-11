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
***     Description: Declaration of AcRxProtocolReactorList class
***
*****************************************************************************/
#pragma once

#include "AcRxProtocolReactorIterator.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxProtocolReactorList : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcRxProtocolReactorList);

	virtual Acad::ErrorStatus addReactor(AcRxProtocolReactor* pReactor) = 0;
	virtual AcRxProtocolReactorIterator* newIterator() const = 0;
	virtual AcRxClass* reactorClass() const = 0;
	virtual void removeReactor(AcRxProtocolReactor* pReactor) = 0;
};

#include "IcArxPackPop.h"
