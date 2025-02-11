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
***     Description: Declaration of AcDbDgnUnderlayItem class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayItem.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbDgnUnderlayItem : public AcDbUnderlayItem
{
public:
	virtual bool useMasterUnits() const = 0;
	virtual void setUseMasterUnits(bool bUseMasterUnits) = 0;
	virtual bool showRasterRef() const = 0;
	virtual void setShowRasterRef(bool bShow) = 0;
};

#include "IcArxPackPop.h"
