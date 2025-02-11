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
***     Description: Declaration of AcTcStockTool class
***
*****************************************************************************/
#pragma once

#include "AcTcCatalogItem.h"

class AcTcTool;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcStockTool : public AcTcCatalogItem
{
public:
	AcTcStockTool();
	AcTcStockTool(const AcTcStockTool& srcItem);
	~AcTcStockTool();

	AcTcTool* CreateTool(BOOL bSetDefaults = TRUE);

	BOOL CreateAcadStockTool(IUnknown** ppStockTool);
	BOOL CreateAcadTool(IUnknown** ppUnknown);

	BOOL GetComClassID(CLSID& clsid) const;
	BOOL SetComClassID(const CLSID& clsid);
	int GetModuleFileName(LPTSTR pszString, int cchSize) const;
	BOOL SetModuleFileName(LPCTSTR pszString);
	int GetModuleInstallUrl(LPTSTR pszString, int cchSize) const;
	BOOL SetModuleInstallUrl(LPCTSTR pszString);
	int GetModuleInstallArguments(LPTSTR pszString, int cchSize) const;
	BOOL SetModuleInstallArguments(LPCTSTR pszString);

protected:
	AcTcStockTool(AcTcSystemInternals*);

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"
