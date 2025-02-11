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
***     Description: Declaration of AcTcManager class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

class AcTcStockTool;
class AcTcCatalogItem;
class AcTcScheme;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcManager
{
public:
	AcTcManager();
	virtual ~AcTcManager();

	INT_PTR GetStockToolCatalogCount(void) const;
	AcTcCatalogItem* GetStockToolCatalog(int nIndex) const;
	AcTcStockTool* FindStockTool(const GUID& id) const;

	INT_PTR GetCatalogCount(void) const;
	AcTcCatalogItem* GetCatalog(int nIndex) const;
	AcTcCatalogItem* FindItem(const GUID& id) const;

	int GetCatalogPath(LPTSTR pszString, int cchSize) const;
	BOOL SetCatalogPath(LPCTSTR pszPath);
	int GetStockToolCatalogPath(LPTSTR pszString, int cchSize) const;
	BOOL SetStockToolCatalogPath(LPCTSTR pszPath);
	int GetShapeCatalogFile(LPTSTR pszString, int cchSize) const;
	BOOL SetShapeCatalogFile(LPCTSTR pszFile);
	INT_PTR AddStockToolCatalog(AcTcCatalogItem* pCatalogItem);
	INT_PTR AddCatalog(AcTcCatalogItem* pCatalogItem);
	BOOL LoadCatalogs(DWORD dwCatalogType = AcTc::kCatalog | AcTc::kStockToolCatalog,
					  DWORD dwLoadOption = AcTc::kLoadLinks);
	BOOL UnloadCatalogs(DWORD dwCatalogType = AcTc::kCatalog | AcTc::kStockToolCatalog);
	BOOL SaveCatalogs(DWORD dwCatalogType = AcTc::kCatalog | AcTc::kStockToolCatalog,
					  DWORD dwSaveOption = AcTc::kSaveLinksAsLinks);
	AcTcCatalogItem* GetShapeCatalog(void);
	AcTcCatalogItem* GetShapePackage(LPCTSTR lpszName = nullptr) const;
	INT_PTR InsertStockToolCatalog(INT_PTR nIndex, AcTcCatalogItem* pCatalog);
	AcTcCatalogItem* RemoveStockToolCatalog(int nIndex);

	INT_PTR GetSchemeCount(void) const;
	AcTcScheme* GetScheme(int nIndex) const;
	AcTcScheme* GetScheme(LPCTSTR pszSchemeName) const;
	INT_PTR AddScheme(AcTcScheme* pScheme);
	BOOL RemoveScheme(AcTcScheme* pScheme);

protected:
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"
