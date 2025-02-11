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

#include "AdAChar.h"
#include "AcPlObject.h"

class AcPlPlotErrorHandler;

#include "icarx/IcArxPackPush.h"

class AcPlPlotErrorHandlerLock : public AcPlObject
{
public:
	enum LockStatus
	{
		kLocked,
		kUnLocked
	};

private:
	ACPL_DECLARE_MEMBERS(AcPlPlotErrorHandlerLock);

public:
	ACPL_PORT AcPlPlotErrorHandlerLock();
	ACPL_PORT AcPlPlotErrorHandlerLock(AcPlPlotErrorHandler* pAppErrHandler, const ACHAR* pAppName);

	ACPL_PORT const ACHAR* appName() const;
	ACPL_PORT void getErrorHandler(AcPlPlotErrorHandler*& pAppErrHandler) const;
	ACPL_PORT bool lock(AcPlPlotErrorHandler* pAppErrHandler, const ACHAR* pAppName);
	ACPL_PORT LockStatus status() const;
	ACPL_PORT bool unLock(AcPlPlotErrorHandler* pAppErrHandler);
};

#include "icarx/IcArxPackPop.h"
