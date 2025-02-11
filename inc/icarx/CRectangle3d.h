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
***     Description: Declaration of CRectangle3d class
***
*****************************************************************************/
#pragma once

#include "../gepnt3d.h"

#include "IcArxPackPush.h"

class CRectangle3d
{
public:
	AcGePoint3d upLeft;
	AcGePoint3d upRight;
	AcGePoint3d lowLeft;
	AcGePoint3d lowRight;
};

#include "IcArxPackPop.h"

bool operator==(const CRectangle3d& l, const CRectangle3d& r);
