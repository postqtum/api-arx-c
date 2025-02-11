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
***     Description: Declaration of CAdUiRegistryAccess class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#ifdef ACUTIL_INTERNAL
#	ifdef ADUI_PORT
#		undef ADUI_PORT
#	endif
#	ifdef ACCORE_BUILD
#		define ADUI_PORT __declspec(dllexport)
#	else
#		define ADUI_PORT
#	endif
#endif

#ifndef ADUI_PORT
#	define ADUI_PORT
#endif

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiRegistryAccess
{
protected:
	HKEY m_hKey = nullptr;
	CString m_sSubkey;

protected:
	void CommonConstruction();

public:
	CAdUiRegistryAccess();
	CAdUiRegistryAccess(HKEY hKey, const CString& sSubkey);
	virtual ~CAdUiRegistryAccess();
	virtual void Close();
	BOOL EnumKeyNames(DWORD dwEntryIndex, CString& sKeyName);
	BOOL EnumValueNames(DWORD dwEntryIndex, CString& sValueName, LPDWORD lpdwType = nullptr);
	BOOL GetBinary(const CString& sValueName, LPBYTE pbData, DWORD& dwSize);
	DWORD GetDWord(const CString& sValueName);
	DWORD GetDWordWithDefaultValue(const CString& sValueName, DWORD dwDefault);
	CString GetString(const CString& sValueName);
	BOOL IsOpen();
	virtual BOOL Open(HKEY hKey, const CString& sSubkey);
	DWORD ValueType(const CString& sValueName, LPDWORD lpdwSize = nullptr);
	operator HKEY() const;
};


#include "IcArxPackPop.h"
