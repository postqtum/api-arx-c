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

#include "gepnt3d.h"
#include "AcTcUiToolPaletteSet.h"
#include "AcTcUi.h"

class AcTcUiSystemInternals;

class ACTCUI_PORT CAcTcUiManager
{
public:
	CAcTcUiManager();
	virtual ~CAcTcUiManager();
	CAcTcUiToolPaletteSet* GetToolPaletteWindow(void);
	BOOL Load(IUnknown* pUnknown);
	BOOL Save(IUnknown* pUnknown);
	BOOL SetApplicationWindow(HWND hWndApp);
	HWND GetApplicationWindow(void);
	COleDropTarget* GetDropTarget(void);
	CAcTcUiToolPalette* CreatePalette(LPCTSTR pszPalName = nullptr, DWORD dwFlags = 0);
	BOOL Export(LPCTSTR pszFile, const AcTcUiToolPaletteArray* palettes = nullptr);
	BOOL Import(LPCTSTR pszFile);
	BOOL FindPalette(const AcTcCatalogItem* pItem, CAcTcUiToolPalette** ppToolPalette) const;
	BOOL FindPalette(const GUID& itemId, CAcTcUiToolPalette** ppToolPalette) const;
	BOOL ShowToolPaletteWindow(BOOL bShow = TRUE);
	BOOL IsToolPaletteWindowVisible(void) const;
	int GetToolFilterCount(void) const;
	int AddToolFilter(LPCTSTR pszProductName, int nMajorVersion, int nMinorVersion,
					  DWORD dwLocaleId);
	BOOL GetToolFilter(int iIndex, LPTSTR pszProductName, int* pMajorVersion, int* pMinorVersion,
					   DWORD* pLocaleId) const;
	BOOL DeleteToolFilter(int iIndex);
	CAcTcUiScheme* GetScheme(LPCTSTR pszName) const;
	CAcTcUiScheme* GetScheme(int nIndex);
	int GetSchemeCount(void);
	int AddScheme(CAcTcUiScheme* pUiScheme);
	BOOL RemoveScheme(CAcTcUiScheme* pUiScheme);
	void NotifyDropPoint(const AcGePoint3d& point);

	BOOL ExecuteTool(ADUI_DRAGDATA* pDragData);

	void CreatePalette(ADUI_DRAGDATA* pDragData);

protected:
	void* mpImpObj;

private:
	friend class AcTcUiSystemInternals;
};
