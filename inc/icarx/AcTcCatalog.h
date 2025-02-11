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
***     Description: Declaration of AcTcCatalog class
***
*****************************************************************************/
#pragma once

#include "AcTcCategory.h"

#include "IcArxPackPush.h"

class ACTC_PORT AcTcCatalog : public AcTcCategory
{
public:
	AcTcCatalog();
	AcTcCatalog(const AcTcCatalog& srcItem);
	~AcTcCatalog();

protected:
	AcTcCatalog(AcTcSystemInternals*);
};

#include "IcArxPackPop.h"
