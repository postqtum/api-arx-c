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

#include "AcTcUiToolPaletteSet.h"
#include "AcTcUi.h"

class AcTcUiSystemInternals;

class ACTCUI_PORT CAcTcUiScheme : public CObject
{
public:
	enum RefreshScope
	{
		kAllPalettes = (0x1 << 0),
		kRefreshEnabledPalettes = (0x1 << 1),
		kAutoRefreshEnabledPalettes = (0x1 << 2),
	};

	enum ShowOption
	{
		kShow = (0x1 << 0),
		kHide = (0x1 << 1),
		kSaveState = (0x1 << 2),
		kRestoreState = (0x1 << 3),
	};

	CAcTcUiScheme(AcTcScheme* pScheme);
	~CAcTcUiScheme();

	BOOL Load(IUnknown* pUnknown);
	BOOL Save(IUnknown* pUnknown);
	BOOL Unload(void);
	CAcTcUiToolPaletteSet* CreatePaletteSet(LPCTSTR pszPalSetName);
	CAcTcUiToolPaletteSet* GetPaletteSet(void);
	BOOL FindPalette(const AcTcCatalogItem* pItem, CAcTcUiToolPalette** ppToolPalette) const;
	BOOL FindPalette(const AcTcCatalogItem* pItem, CAcTcUiToolPalette** ppToolPalette,
					 CAcTcUiToolPaletteSet** ppToolPaletteSet) const;
	BOOL FindPalette(const GUID& itemId, CAcTcUiToolPalette** ppToolPalette) const;
	BOOL FindPalette(const GUID& itemId, CAcTcUiToolPalette** ppToolPalette,
					 CAcTcUiToolPaletteSet** ppToolPaletteSet) const;
	BOOL Export(LPCTSTR pszFile);
	BOOL Export(LPCTSTR pszFile, const AcTcUiToolPaletteArray* palettes);
	BOOL Import(LPCTSTR pszFile);
	BOOL Refresh(RefreshScope nScope);
	BOOL Refresh(RefreshScope nScope, DWORD dwRefreshFlag);
	BOOL Show(ShowOption nOption, LONG_PTR lKey);

protected:
	void* mpImpObj;

private:
	friend class AcTcUiSystemInternals;
};
