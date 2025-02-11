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
***     Description: Declaration of CAdUiThemeManager class
***
*****************************************************************************/
#pragma once

#include <afxwin.h>

#include "AdAChar.h"

class CAdUiTheme;

class CAdUiThemeMgrReactor
{
public:
	CAdUiThemeMgrReactor() = default;
	virtual ~CAdUiThemeMgrReactor() = default;
	virtual void SystemColorChanged() = 0;
	virtual void ThemeAdded(const CString& strThemeName) = 0;
	virtual void ThemeRemoved(const CString& strThemeName) = 0;
};

class CAdUiThemeManager
{
	friend class CAdUiThemeMgrReactor;

private:
	CObArray m_list;
	CTypedPtrArray<CPtrArray, CAdUiThemeMgrReactor*> m_arrayThemeMgrReactors;

private:
	void Cleanup();
	int GetThemeIndex(const ACHAR* pThemeName) const;
	int GetThemeIndex(const CAdUiTheme* pTheme) const;
	void NotifySysColorReactors();
	void NotifyThemeAddedReactors(const CString& strThemeName);
	BOOL RegisterThemeMgrReactor(CAdUiThemeMgrReactor* pReactor);
	int RemoveTheme(const ACHAR* pThemeName);
	BOOL UnregisterThemeMgrReactor(CAdUiThemeMgrReactor* pReactor);

public:
	CAdUiThemeManager();
	~CAdUiThemeManager();
	void ActiveThemeChanged();
	CAdUiTheme* GetTheme(const ACHAR* pThemeName);
	BOOL HasTheme(const ACHAR* pThemeName) const;
	BOOL ReleaseTheme(CAdUiTheme* pTheme);
	void SystemColorChanged();
};
