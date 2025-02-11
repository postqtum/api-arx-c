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
***     Description: Declaration of AcTcCategory class
***
*****************************************************************************/
#pragma once

#include "AcTcCatalogItem.h"

#include "IcArxPackPush.h"

class ACTC_PORT AcTcCategory : public AcTcCatalogItem
{
public:
	AcTcCategory();
	AcTcCategory(const AcTcCategory& srcItem);
	~AcTcCategory();

protected:
	AcTcCategory(AcTcSystemInternals*);
};

#include "IcArxPackPop.h"
