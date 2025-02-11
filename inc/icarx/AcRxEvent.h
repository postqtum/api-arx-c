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
***     Description: Declaration of AcRxEvent class
***
*****************************************************************************/
#pragma once

#include "AcRxEventReactor.h"

#include "IcArxPackPush.h"

class AcRxEvent : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcRxEvent);

	virtual void addReactor(AcRxEventReactor* reactor) = 0;
	virtual void removeReactor(AcRxEventReactor* reactor) = 0;
};

#include "IcArxPackPop.h"

#define ACRX_EVENT_OBJ ACRX_T("AcRxEvent")

#define acrxEvent AcRxEvent::cast(acrxSysRegistry()->at(ACRX_EVENT_OBJ))
