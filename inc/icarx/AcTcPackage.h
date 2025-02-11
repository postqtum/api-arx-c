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
***     Description: Declaration of AcTcPackage class
***
*****************************************************************************/
#pragma once

#include "AcTcCatalogItem.h"

class AcTcStockTool;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcPackage : public AcTcCatalogItem
{
public:
	AcTcPackage();
	AcTcPackage(const AcTcPackage& srcItem);
	~AcTcPackage();

protected:
	AcTcPackage(AcTcSystemInternals*);
};

#include "IcArxPackPop.h"
