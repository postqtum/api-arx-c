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

#include "AcPlObject.h"

class AcPlSystemInternals;
class AcString;

#include "icarx/IcArxPackPush.h"

class AcPlPlotErrorHandler : public AcPlObject
{
protected:
	using ACPL_ULONG_PTR = unsigned __int64;

public:
	enum ErrorResult
	{
		kAbort,
		kRetry,
		kIgnore
	};

	enum Handler
	{
		kInfo,
		kWarning,
		kError,
		kARI,
		kSevere,
		kTerminal,
		kNone
	};

protected:
	ACPL_PORT ErrorResult appARIError(ACPL_ULONG_PTR category, const unsigned int specific,
									  const ACHAR* pLocation, const ACHAR* pContextData,
									  const ACHAR* pRevision);
	ACPL_PORT ErrorResult appError(ACPL_ULONG_PTR category, const unsigned int specific,
								   const ACHAR* pLocation, const ACHAR* pContextData,
								   const ACHAR* pRevision);
	ACPL_PORT void appInfo(ACPL_ULONG_PTR category, const unsigned int specific,
						   const ACHAR* pLocation, const ACHAR* pContextData,
						   const ACHAR* pRevision);
	ACPL_PORT void appInfoMessage(const ACHAR* pMessage);
	ACPL_PORT void appLogMessage(const ACHAR* pTitle, const ACHAR* pMsg);
	ACPL_PORT int appMessageBox(const ACHAR* pText, const ACHAR* pCaption, unsigned int uType,
								int defaultReturn);
	ACPL_PORT bool appSetLogHandle(const ACHAR* pFilePathName);
	ACPL_PORT void appSevereError(ACPL_ULONG_PTR category, const unsigned int specific,
								  const ACHAR* pLocation, const ACHAR* pContextData,
								  const ACHAR* pRevision);
	ACPL_PORT void appTerminalError(ACPL_ULONG_PTR category, const unsigned int specific,
									const ACHAR* pLocation, const ACHAR* pContextData,
									const ACHAR* pRevision);
	ACPL_PORT ErrorResult appWarning(ACPL_ULONG_PTR category, const unsigned int specific,
									 const ACHAR* pLocation, const ACHAR* pContextData,
									 const ACHAR* pRevision);

public:
	ACPL_DECLARE_MEMBERS(AcPlPlotErrorHandler);

public:
	ACPL_PORT AcPlPlotErrorHandler();
	ACPL_PORT ~AcPlPlotErrorHandler();

	ACPL_PORT virtual ErrorResult ariError(ACPL_ULONG_PTR category, const unsigned int specific,
										   const ACHAR* pLocation, const ACHAR* pContextData,
										   const ACHAR* pRevision);
	ACPL_PORT virtual const ACHAR* ariTitle() const;
	ACPL_PORT virtual ErrorResult error(ACPL_ULONG_PTR category, const unsigned int specific,
										const ACHAR* pLocation, const ACHAR* pContextData,
										const ACHAR* pRevision);
	ACPL_PORT virtual const ACHAR* errorTitle() const;
	ACPL_PORT void getCompanyString(AcString& pCompanyString) const;
	ACPL_PORT void getProductString(AcString& pProductString) const;
	ACPL_PORT void getProgramString(AcString& pProgramString) const;
	ACPL_PORT virtual void info(ACPL_ULONG_PTR category, const unsigned int specific,
								const ACHAR* pLocation, const ACHAR* pContextData,
								const ACHAR* pRevision);
	ACPL_PORT virtual void infoMessage(const ACHAR* pMessage);
	ACPL_PORT virtual const ACHAR* infoTitle() const;
	ACPL_PORT virtual void logMessage(const ACHAR* pTitle, const ACHAR* pMsg);
	ACPL_PORT virtual bool logMode() const;
	ACPL_PORT virtual int messageBox(const ACHAR* pText, const ACHAR* pCaption, unsigned int uType,
									 int defaultReturn);
	ACPL_PORT virtual bool quietMode() const;
	ACPL_PORT virtual bool setLogHandle(const ACHAR* pFilePathName);
	ACPL_PORT virtual void setLogMode(bool bLog);
	ACPL_PORT virtual void setQuietMode(bool bQuiet);
	ACPL_PORT virtual void severeError(ACPL_ULONG_PTR category, const unsigned int specific,
									   const ACHAR* pLocation, const ACHAR* pContextData,
									   const ACHAR* pRevision);
	ACPL_PORT virtual const ACHAR* severeTitle() const;
	ACPL_PORT virtual bool takeResponsibility(Handler kind);
	ACPL_PORT virtual void terminalError(ACPL_ULONG_PTR category, const unsigned int specific,
										 const ACHAR* pLocation, const ACHAR* pContextData,
										 const ACHAR* pRevision);
	ACPL_PORT virtual const ACHAR* terminalTitle() const;
	ACPL_PORT virtual ErrorResult warning(ACPL_ULONG_PTR category, const unsigned int specific,
										  const ACHAR* pLocation, const ACHAR* pContextData,
										  const ACHAR* pRevision);
	ACPL_PORT virtual const ACHAR* warningTitle() const;
};

#include "icarx/IcArxPackPop.h"
