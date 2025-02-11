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
***     Description: Declaration of AcGsColor class
***
*****************************************************************************/
#pragma once

#include "IcArxPackPush.h" 

struct AcGsColor
{
	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
	unsigned char m_filler;
};

#include "IcArxPackPop.h"
