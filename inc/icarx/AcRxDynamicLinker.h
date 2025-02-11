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
***     Description: Declaration of AcRxDynamicLinker class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AdAChar.h"
#include "../AcDbCore2dDefs.h"

class AcRxDLinkerReactor;
class AcRxService;
class AcLocale;

#include "IcArxPackPush.h"

struct AcadApp
{
	enum LoadReasons
	{
		kOnProxyDetection = 0x01,
		kOnAutoCADStartup = 0x02,
		kOnCommandInvocation = 0x04,
		kOnLoadRequest = 0x08,
		kLoadDisabled = 0x10,
		kTransparentlyLoadable = 0x20,
		kOnIdleLoad = 0x40
	};

	enum ErrorStatus
	{
		eOk = 0,
		eInvalidKey = 1,
		eInvalidSubKey = 2,
		eKeyNotFound = 3,
		eOutOfMemory = 4,
		eInvalidValue = 5,
		eValueNotFound = 6,
		eKeyExists = 7,
		eRegAccessDenied = 8,
		eRejected = 9,
		eUnknownError = 10
	};
};

class ADESK_NO_VTABLE AcRxDynamicLinker : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxDynamicLinker, ACDBCORE2D_PORT);

	virtual AcLocale ProductLocale() const = 0;
	virtual void addReactor(AcRxDLinkerReactor* newReactor) = 0;
	virtual void* getSymbolAddress(const ACHAR* serviceName, const char* symbol) const = 0;
	virtual void* getSymbolAddress(const ACHAR* serviceName, const ACHAR* symbol) const = 0;
	virtual bool initListedModules(const ACHAR* fileName) = 0;
	virtual bool isAppBusy(const ACHAR* modulename) const = 0;
	virtual bool isAppMDIAware(const ACHAR* modulename) const = 0;
	virtual bool isApplicationLocked(const ACHAR* modulename) const = 0;
	virtual bool loadApp(const ACHAR* appName, AcadApp::LoadReasons al, bool printit,
						 bool asCmd = false) = 0;
	virtual bool loadModule(const ACHAR* fileName, bool printit, bool asCmd = false) = 0;
	virtual bool lockApplication(void* appId) const = 0;
	virtual AcadApp::ErrorStatus registerApp(AcadApp::LoadReasons alr, const ACHAR* logicalName,
											 void* entryPoint = nullptr) = 0;
	virtual bool registerAppMDIAware(void* appId) const = 0;
	virtual bool registerAppNotMDIAware(void* appId) const = 0;
	virtual AcRxObject* registerService(const ACHAR* serviceName, AcRxService* serviceObj) = 0;
	virtual void removeReactor(AcRxDLinkerReactor* oldReactor) = 0;
	virtual void setAppBusy(const ACHAR* modulename, bool bBusyFlag) const = 0;
	virtual bool unloadApp(const ACHAR* appName, bool asCmd = false) = 0;
	virtual bool unloadModule(const ACHAR* fileName, bool asCmd = false) = 0;
	virtual bool unlockApplication(void* appId) const = 0;
	virtual AcadApp::ErrorStatus unregisterApp(const ACHAR* logicalName) = 0;
};

#include "IcArxPackPop.h"

#define acrxDynamicLinker AcRxDynamicLinker::cast(acrxSysRegistry()->at(ACRX_DYNAMIC_LINKER))
