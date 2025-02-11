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
***     Description: Declaration of CAdUiRegistryWriteAccess class
***
*****************************************************************************/
#pragma once

#include "CAdUiRegistryAccess.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiRegistryWriteAccess : public CAdUiRegistryAccess
{
public:
	CAdUiRegistryWriteAccess();
	CAdUiRegistryWriteAccess(HKEY hKey, const CString& sSubkey);
	~CAdUiRegistryWriteAccess();
	BOOL Open(HKEY hKey, const CString& sSubkey) override;
	BOOL SetBinary(const CString& sValueName, const BYTE* pbData, DWORD dwLen);
	BOOL SetDWord(const CString& sValueName, DWORD dwValue);
	BOOL SetString(const CString& cValueName, const CString& sValue);
};

#include "IcArxPackPop.h"
