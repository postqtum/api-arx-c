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
***     Description: Declaration of AcDbManagedHost class
***
*****************************************************************************/
#pragma once

#include "AdAChar.h"
#include "acadstrc.h"
#include "AcDbCore2dDefs.h"
#include "adesk.h"

class AcString;

#include "icarx/IcArxPackPush.h"

class AcDbManagedHost
{
public:
	virtual bool isLoaded() = 0;
	virtual Acad::ErrorStatus load(const ACHAR* fname) = 0;
	virtual bool loadIndirectString(const AcString& resAssemblyPath, const AcString& cmdString,
									AcString& localCmd) = 0;
	virtual int version() { return 1; }
};

#include "icarx/IcArxPackPop.h"

ACDBCORE2D_PORT AcDbManagedHost* ADESK_STDCALL acdbGetManagedHost();
ACDBCORE2D_PORT Acad::ErrorStatus ADESK_STDCALL acdbSetManagedHost(AcDbManagedHost* pHost);
