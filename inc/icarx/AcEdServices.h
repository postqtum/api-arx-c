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
***     Description: Declaration of AcEdServices class
***
*****************************************************************************/
#pragma once

#include "../rxsrvice.h"
#include "AcEdCommand.h"

#include "IcArxPackPush.h"

class AcEdServices : public AcRxService
{
public:
	ACRX_DECLARE_MEMBERS(AcEdServices);

	virtual AcEdCommand* newAcEdCommand(AcRxFunctionPtr cmdFcnAddr, int32_t cmdFlags) const = 0;
};

#include "IcArxPackPop.h"

#define ACED_SERVICES ACRX_T("AcEdServices")
