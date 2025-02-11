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

#include "AdExportDef.h"

class AdImpMenuBar;

typedef bool(CALLBACK* LPFNADMENUCALLBACK)(unsigned int nItemId);

class ADAF_PORT AdMenuBar
{
	friend class AdApplicationFrame;

public:
	virtual ~AdMenuBar();

	bool GetMenuItemHelpString(UINT nItemID, const wchar_t** wszHelpString);
	bool RemoveMenuItem(HMENU hMenu, UINT nMenuItemId);
	bool AddMenuItem(HMENU hMenu, UINT nPos, const MENUITEMINFO& menuItem,
					 LPFNADMENUCALLBACK pfnCallback, const wchar_t* wszHelpString);
	bool SetMenuHandle(HMENU hMenu);
	void UpdateMenu();
	HMENU GetMenuHandle();
	bool TrackingPopup();
	void SetChildWindowMenuPopup(bool bShow);
	bool GetChildWindowMenuPopup(void);

private:
	AdMenuBar(AdImpMenuBar* pImpMenuBar);
	AdMenuBar();

	AdImpMenuBar* mpImpMenuBar;
};
