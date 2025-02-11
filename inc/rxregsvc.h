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

#include "rxdlinkr.h"
#include "adesk.h"
#include "acarray.h"

class AcLocale;

ACDBCORE2D_PORT bool acrxAppIsLoaded(const ACHAR* pAppName);
bool acrxApplicationIsLocked(const ACHAR* modulename);
void* acrxGetServiceSymbolAddr(const ACHAR* serviceName, const ACHAR* symbol);
bool acrxIsAppMDIAware(const ACHAR* moduleName);
bool acrxLoadApp(const ACHAR* appname, bool asCmd = false);
ACDBCORE2D_PORT bool acrxLoadAutoloadApps(const ACHAR* appname);
bool acrxLoadModule(const ACHAR* moduleName, bool printit, bool asCmd = false);
ACDBCORE2D_PORT AcArray<wchar_t*>* acrxLoadedApps();
bool acrxLockApplication(void* appId);
const ACHAR* acrxObjectDBXRegistryKey();
ACDBCORE2D_PORT AcLocale acrxProductLocale();
ACDBCORE2D_PORT AcadApp::ErrorStatus acrxRegisterApp(AcadApp::LoadReasons alr, const ACHAR* logicalName);
bool acrxRegisterAppMDIAware(void* appId);
bool acrxRegisterAppNotMDIAware(void* appId);
void* acrxRegisterService(const ACHAR* serviceName);
ACDBCORE2D_PORT AcRxService* acrxRegisterService(const ACHAR* serviceName, AcRxService* pSvc);
bool acrxServiceIsRegistered(const ACHAR* serviceName);
bool acrxUnloadApp(const ACHAR* appName, bool asCmd = false);
ACDBCORE2D_PORT bool acrxUnloadAutoloadApps(const ACHAR* appname);
bool acrxUnloadModule(const ACHAR* moduleName, bool asCmd = false);
bool acrxUnlockApplication(void* appId);
ACDBCORE2D_PORT AcadApp::ErrorStatus acrxUnregisterApp(const ACHAR* logicalname);
