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
***     Description: Declaration of CAcFdUiFieldManager class
***
*****************************************************************************/
#pragma once

#include "AcFdUi.h"
#include "AcFdUiFieldDialogHook.h"

class AcTcUiSystemInternals;
class CAcFdUiFieldCatalog;
class CAcFdUiFieldDialogHook;

class ACFDUI_PORT CAcFdUiFieldManager : public CObject
{
protected:
	void* mpImpObj = nullptr;

	friend class AcFdUiSystemInternals;

public:
	CAcFdUiFieldManager();
	~CAcFdUiFieldManager() noexcept;
	int GetRegisteredDialogHooks(AcFdUiFieldDialogHookArray& hooks);
	BOOL RegisterFieldDialogHook(CAcFdUiFieldDialogHook* pDlgHook);
	BOOL UnregisterFieldDialogHook(const CAcFdUiFieldDialogHook* pDlgHook);
};
