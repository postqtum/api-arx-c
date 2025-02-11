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
***     Description: Declaration of AcTcCatalogItemReactor class
***
*****************************************************************************/
#pragma once

#include "AcTcBase.h"

class AcTcCatalogItem;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcCatalogItemReactor
{
public:
	virtual ~AcTcCatalogItemReactor(void);

	BOOL Enable(BOOL bEnable);
	BOOL IsEnabled(void) const;

	virtual void ChildAdded(AcTcCatalogItem* pChild);
	virtual void ChildDeleted(AcTcCatalogItem* pChild);
	virtual void ChildDetached(AcTcCatalogItem* pChild);

protected:
	void* mpImpObj;

protected:
	AcTcCatalogItemReactor();

private:
	friend class AcTcSystemInternals;
};

#include "IcArxPackPop.h"
