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
***     Description: Declaration of AcGiGdiDrawObject class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../rxboiler.h"

#ifndef _WINDEF_
struct HDC__;
typedef struct HDC__* HDC;
#endif

#include "IcArxPackPush.h"

class AcGiGdiDrawObject : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcGiGdiDrawObject);

	virtual void addRef() = 0;
	virtual void delRef() = 0;
	virtual bool draw(HDC hDC, int x, int y, int w, int h) = 0;
	virtual int height() const = 0;
	virtual int width() const = 0;
};

#include "IcArxPackPop.h"
