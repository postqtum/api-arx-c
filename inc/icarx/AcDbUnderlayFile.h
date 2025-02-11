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
***     Description: Declaration of AcDbUnderlayFile class
***
*****************************************************************************/
#pragma once

#include "AcDbUnderlayItem.h"

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcDbUnderlayFile
{
public:
	virtual ~AcDbUnderlayFile() = 0;
	virtual Acad::ErrorStatus getItem(int i, AcDbUnderlayItem*& pItem) const = 0;
	virtual Acad::ErrorStatus getItem(const ACHAR* name, AcDbUnderlayItem*& pItem) const = 0;
	virtual int getItemCount() const = 0;
};

#include "IcArxPackPop.h"
