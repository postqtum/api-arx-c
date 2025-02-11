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
***     Description: Declaration of AcTcScheme class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

class AcTcCatalogSet;
class AcTcCatalogItem;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcScheme
{
public:
	AcTcScheme(LPCTSTR pszSchemeName);
	virtual ~AcTcScheme();

	int GetName(LPTSTR pszString, int cchSize) const;
	BOOL SetName(LPCTSTR pszString);

	AcTcCatalogSet* GetCatalogSet(DWORD dwCatalogType) const;

	AcTcCatalogItem* FindItem(const GUID& id) const;
	AcTcCatalogItem* FindItem(const GUID& id, DWORD dwCatalogType) const;

	BOOL LoadCatalogs(void);
	BOOL LoadCatalogs(DWORD dwCatalogType, DWORD dwLoadOption);
	BOOL UnloadCatalogs(void);
	BOOL UnloadCatalogs(DWORD dwCatalogType);
	BOOL SaveCatalogs(void);
	BOOL SaveCatalogs(DWORD dwCatalogType, DWORD dwSaveOption);

protected:
	void* mpImpObj;

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"
