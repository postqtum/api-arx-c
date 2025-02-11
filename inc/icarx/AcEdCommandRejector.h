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
***     Description: AcEdCommandRejector API
***
*****************************************************************************/
#pragma once

#include "../accoredefs.h"
#include "../adsdef.h"

#include "IcArxPackPush.h"

#ifdef __cplusplus

class AcEdCommandRejector
{
public:
	virtual bool reject(const ACHAR* globalCmdName, const ACHAR* localCmdName) = 0;
};

ACCORE_PORT void acedRegisterCommandRejector(AcEdCommandRejector* pRejector);
ACCORE_PORT void acedUnRegisterCommandRejector(AcEdCommandRejector* pRejector);

#endif /* __cplusplus */

#include "IcArxPackPop.h"
