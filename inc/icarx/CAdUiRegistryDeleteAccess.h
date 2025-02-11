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
***     Description: Declaration of CAdUiRegistryDeleteAccess class
***
*****************************************************************************/
#pragma once

#include "CAdUiRegistryWriteAccess.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiRegistryDeleteAccess : public CAdUiRegistryWriteAccess
{
public:
	CAdUiRegistryDeleteAccess();
	CAdUiRegistryDeleteAccess(HKEY hKey, const CString& sSubkey);
	~CAdUiRegistryDeleteAccess();
	BOOL DeleteAllKeys();
	BOOL DeleteAllValues();
	BOOL DeleteKey(const CString& sKeyName);
	BOOL DeleteKeyAndSubkeys(const CString& sKeyName);
	BOOL DeleteValue(const CString& sValueName);
};

#include "IcArxPackPop.h"
