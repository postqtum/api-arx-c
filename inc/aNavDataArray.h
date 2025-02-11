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
***     Description:
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include "aNavArray.h"
#include "aNavData.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class ANAV_PORT CNavDataArray : public CNavArray<CNavData>
{
public:
	CNavDataArray();
	~CNavDataArray();
};

#include "icarx/IcArxPackPop.h"
