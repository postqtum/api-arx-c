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
***     Description: Declaration of AcRxDLinkerReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AdAChar.h"
#include "../AcDbCore2dDefs.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxDLinkerReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDLinkerReactor, ACDBCORE2D_PORT);

	ACDBCORE2D_PORT virtual ~AcRxDLinkerReactor() = default;

	virtual void rxAppLoadAborted(const ACHAR* /*moduleName*/) {}
	virtual void rxAppLoaded(const ACHAR* /*moduleName*/) {}
	virtual void rxAppUnloadAborted(const ACHAR* /*moduleName*/) {}
	virtual void rxAppUnloaded(const ACHAR* /*moduleName*/) {}
	virtual void rxAppWillBeLoaded(const ACHAR* /*moduleName*/) {}
	virtual void rxAppWillBeUnloaded(const ACHAR* /*moduleName*/) {}
};

#include "IcArxPackPop.h"
