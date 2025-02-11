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
***     Description:  Declaration of AcDbPropertyFilterCustomizationPE class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dynprops-AcFilterablePropertyContext.h"

#include "icarx/IcArxPackPush.h"

class AcDbPropertyFilterCustomizationPE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbPropertyFilterCustomizationPE);

	virtual bool createObject(AcDbDatabase* pDb, AcRxClass* pCls, AcDbEntity** ppEnt,
							  AcDbObjectId& objId, const AcString& sGUID) const = 0;
	virtual bool vetoCustomization(AcFilterablePropertyContext context, AcRxClass* pCls) const = 0;
};

#include "icarx/IcArxPackPop.h"
