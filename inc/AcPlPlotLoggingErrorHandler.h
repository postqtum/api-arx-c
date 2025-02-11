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

#include "AcPlPlotErrorHandler.h"

class AcPlPlotLogger;
class AcPlSystenInternals;

#include "icarx/IcArxPackPush.h"

class AcPlPlotLoggingErrorHandler : public AcPlPlotErrorHandler
{
public:
	ACPL_DECLARE_MEMBERS(AcPlPlotLoggingErrorHandler);

public:
	ACPL_PORT AcPlPlotLoggingErrorHandler();
	ACPL_PORT AcPlPlotLoggingErrorHandler(AcPlPlotLogger*);
	ACPL_PORT ~AcPlPlotLoggingErrorHandler();

	ACPL_PORT ErrorResult ariError(ACPL_ULONG_PTR category, const unsigned int specific,
								   const ACHAR* pLocation, const ACHAR* pContextData,
								   const ACHAR* pRevision) override;
	ACPL_PORT ErrorResult error(ACPL_ULONG_PTR category, const unsigned int specific,
								const ACHAR* pLocation, const ACHAR* pContextData,
								const ACHAR* pRevision) override;
	ACPL_PORT void info(ACPL_ULONG_PTR category, const unsigned int specific,
						const ACHAR* pLocation, const ACHAR* pContextData,
						const ACHAR* pRevision) override;
	ACPL_PORT void infoMessage(const ACHAR* pMessage) override;
	ACPL_PORT void logMessage(const ACHAR* pTitle, const ACHAR* pMsg) override;
	ACPL_PORT int messageBox(const ACHAR* pText, const ACHAR* pCaption, unsigned int uType,
							 int defaultReturn) override;
	ACPL_PORT void severeError(ACPL_ULONG_PTR category, const unsigned int specific,
							   const ACHAR* pLocation, const ACHAR* pContextData,
							   const ACHAR* pRevision) override;
	ACPL_PORT void terminalError(ACPL_ULONG_PTR category, const unsigned int specific,
								 const ACHAR* pLocation, const ACHAR* pContextData,
								 const ACHAR* pRevision) override;
	ACPL_PORT ErrorResult warning(ACPL_ULONG_PTR category, const unsigned int specific,
								  const ACHAR* pLocation, const ACHAR* pContextData,
								  const ACHAR* pRevision) override;
};

#include "icarx/IcArxPackPop.h"
