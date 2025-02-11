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
***     Description: Declaration of CAdUiImageResource class
***
*****************************************************************************/
#pragma once

#include "CAdUiImage.h"

#include "IcArxPackPush.h"

class ADUI_PORT CAdUiImageResource : public CAdUiImage
{
protected:
	HGLOBAL m_hBuffer = nullptr;
	UINT m_lightId = -1;
	UINT m_darkId = -1;
	LPCTSTR m_pType = nullptr;
	CString m_strType;
	HMODULE m_hInst = nullptr;

private:
	CAdUiImageResource(const CAdUiImageResource& image);
	void clear();
	bool isPredefinedResourceType(LPCTSTR pType);
	bool isValidPredefinedResourceType(LPCTSTR pType);
	bool loadIcon(LPCTSTR pName, HMODULE hInst = nullptr);
	bool loadResource(LPCTSTR pName, LPCTSTR pType, HMODULE hInst);
	CAdUiImageResource& operator=(const CAdUiImageResource& image);
	void saveType(LPCTSTR pType);

public:
	CAdUiImageResource();
	CAdUiImageResource(bool bIsThemed);
	CAdUiImageResource(LPCTSTR pName, LPCTSTR pType = RT_RCDATA,
					   HMODULE hInst = nullptr, bool bIsThemed = false);
	CAdUiImageResource(UINT id, LPCTSTR pType = RT_RCDATA,
					   HMODULE hInst = nullptr);
	CAdUiImageResource(UINT id, UINT type, HMODULE hInst = nullptr);
	CAdUiImageResource(UINT lightId, UINT darkId,
					   LPCTSTR pType = RT_RCDATA,
					   HMODULE hInst = nullptr);
	CAdUiImageResource(UINT lightId, UINT darkId, UINT type, HMODULE hInst = nullptr);
	~CAdUiImageResource();
	void Empty();
	static CString GetThemedResourceName(LPCTSTR pName, const CAdUiTheme* pTheme = nullptr);
	bool Load(LPCTSTR pName, LPCTSTR pType = RT_RCDATA,
			  HMODULE hInst = nullptr);
	bool Load(UINT id, LPCTSTR pType = RT_RCDATA,
			  HMODULE hInst = nullptr);
	bool Load(UINT id, UINT type, HMODULE hInst = nullptr);
	bool Load(UINT lightId, UINT darkId, LPCTSTR pType = RT_RCDATA,
			  HMODULE hInst = nullptr);
	bool Load(UINT lightId, UINT darkId, UINT type, HMODULE hInst = nullptr);
	bool Reload();
};


#include "IcArxPackPop.h"
