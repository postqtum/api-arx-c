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
***     Description: Declaration of CNavData class
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include <afx.h>
#include <shtypes.h>

class CNavPathname;

enum NAV_DATA_TYPE
{
	kNavUnknown,
	kNavShellItem,
	kNavURL,
	kNavUNC,
	kNavExtension,
	kNavWebFolders,
};

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)
class ANAV_PORT CNavData : public CObject
{
protected:
	NAV_DATA_TYPE m_dataType;
	LPITEMIDLIST m_id;
	CString m_text;
	CString m_textInFolder;
	CNavPathname* m_pathname;
	CString m_userName;
	CString m_password;
	CString m_extensionName;
	void* m_userData;

public:
	CNavData();
	~CNavData();
	NAV_DATA_TYPE GetDataType();
	LPCTSTR GetExtensionName();
	LPITEMIDLIST GetID();
	LPCTSTR GetPassword();
	CNavPathname* GetPathname();
	LPCTSTR GetText();
	LPCTSTR GetTextInFolder();
	BOOL GetURL(CString& strURL);
	void* GetUserData();
	LPCTSTR GetUserName();
	BOOL IsExtension();
	BOOL IsRemote();
	void SetDataType(NAV_DATA_TYPE dataType);
	void SetExtensionName(LPCTSTR name);
	void SetID(LPITEMIDLIST id);
	void SetPassword(LPCTSTR password);
	void SetPathname(CNavPathname* pathname);
	void SetText(LPCTSTR text);
	void SetTextInFolder(LPCTSTR text);
	void* SetUserData(void* data);
	void SetUserName(LPCTSTR name);
};

#include "icarx/IcArxPackPop.h"
