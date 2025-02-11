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
***     Description: Declaration of AcEditor class
***
*****************************************************************************/
#pragma once

#include "../rxevent.h"

#include "IcArxPackPush.h"

class AcEditor : public AcRxEvent
{
public:
	ACRX_DECLARE_MEMBERS(AcEditor);

	void addReactor(AcRxEventReactor* newObj) override = 0;
	void removeReactor(AcRxEventReactor* delObj) override = 0;
};

#include "IcArxPackPop.h"

#define ACED_EDITOR_OBJ ACRX_T("AcEditor")
