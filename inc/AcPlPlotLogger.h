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
***     Description: Declaration of AcPlPlotLogger class
***
*****************************************************************************/
#pragma once

#include "adesk.h"
#include "acadstrc.h"

#include "icarx/IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlPlotLogger
{
public:
	AcPlPlotLogger() = default;
	virtual ~AcPlPlotLogger() = default;

	virtual Acad::ErrorStatus endJob() = 0;
	virtual Acad::ErrorStatus endSheet() = 0;
	virtual bool errorHasHappenedInJob() const = 0;
	virtual bool errorHasHappenedInSheet() const = 0;
	virtual Acad::ErrorStatus logARIError(const ACHAR* pErrorString) = 0;
	virtual Acad::ErrorStatus logError(const ACHAR* pErrorString) = 0;
	virtual Acad::ErrorStatus logInformation(const ACHAR* pMessageString) = 0;
	virtual Acad::ErrorStatus logMessage(const ACHAR* pMessageString) = 0;
	virtual Acad::ErrorStatus logSevereError(const ACHAR* pErrorString) = 0;
	virtual Acad::ErrorStatus logTerminalError(const ACHAR* pErrorString) = 0;
	virtual Acad::ErrorStatus logWarning(const ACHAR* pWarningString) = 0;
	virtual Acad::ErrorStatus startJob() = 0;
	virtual Acad::ErrorStatus startSheet() = 0;
	virtual bool warningHasHappenedInJob() const = 0;
	virtual bool warningHasHappenedInSheet() const = 0;
};

#include "icarx/IcArxPackPop.h"
