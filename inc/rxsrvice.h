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
***     Description: Declaration of AcRxService class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"

extern "C" {
typedef AcRx::AppRetCode (*DepFuncPtr)(AcRx::AppMsgCode, void*);
}

class AcRxServicePrototype;
class AcRxService;

#include "icarx/IcArxPackPush.h"

class AcRxService : public AcRxObject
{
private:
	AcRxServicePrototype* mpImpService = nullptr;

public:
	ACRX_DECLARE_MEMBERS(AcRxService);

	AcRxService();
	~AcRxService();

	void addDependency();
	DepFuncPtr dependencyFunctionPtr();
	AcRxObject* getSysInfo() const;
	void removeDependency();
	void setDependencyFunctionPtr(DepFuncPtr);
	// Assigns a system information object to this service.
	// The service will delete the information objects
	// when it is destroyed
	void setSysInfo(AcRxObject* sysInfoObj);
	bool unloadable() const;
};

#include "icarx/IcArxPackPop.h"
