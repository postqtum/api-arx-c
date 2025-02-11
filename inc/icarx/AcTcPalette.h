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
***     Description: Declaration of AcTcPalette class
***
*****************************************************************************/
#pragma once

#include "AcTcPackage.h"

class AcTcStockTool;

#include "IcArxPackPush.h"

class ACTC_PORT AcTcPalette : public AcTcPackage
{
public:
	AcTcPalette();
	AcTcPalette(const AcTcPalette& srcItem);
	~AcTcPalette();

protected:
	AcTcPalette(AcTcSystemInternals*);
};

#include "IcArxPackPop.h"
