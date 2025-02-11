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
***     Description: Declaration of AcDbEmbeddedASMEntPropsPE class
***
*****************************************************************************/
#pragma once

#include "acdbport.h"
#include "rxobject.h"

class AcDbObject;

#include "icarx/IcArxPackPush.h"

class AcDbEmbeddedASMEntPropsPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbEmbeddedASMEntPropsPE);

	ACDB_PORT virtual void setIsEmbeddedEnt(AcDbObject* pObj, bool bIsEmbedded = true);
};

#include "icarx/IcArxPackPop.h"
