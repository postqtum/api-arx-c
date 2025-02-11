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
***     Description: Declaration of AcTcCatalogSet class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

class AcTcCatalogItem;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcCatalogSet
{
public:
	virtual ~AcTcCatalogSet();

	AcTcScheme* GetScheme(void) const;

	INT_PTR GetCatalogCount(void) const;
	AcTcCatalogItem* GetCatalog(int nIndex) const;

	AcTcCatalogItem* FindItem(const GUID& id) const;

	int GetCatalogPath(LPTSTR pszString, int cchSize) const;
	BOOL SetCatalogPath(LPCTSTR pszPath);

	INT_PTR AddCatalog(AcTcCatalogItem* pCatalog);
	INT_PTR InsertCatalog(INT_PTR nIndex, AcTcCatalogItem* pCatalog);
	AcTcCatalogItem* RemoveCatalog(int nIndex);

	BOOL LoadCatalogs(void);
	BOOL LoadCatalogs(DWORD dwLoadOption);
	BOOL UnloadCatalogs(void);
	BOOL SaveCatalogs(void);
	BOOL SaveCatalogs(DWORD dwSaveOption);

protected:
	AcTcCatalogSet(DWORD dwCatalogType);

protected:
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"
