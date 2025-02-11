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
***     Description: Declaration of CNavFilterArray class
***
*****************************************************************************/
#pragma once

#ifndef ANAV_PORT
#	define ANAV_PORT
#endif

#include "aNavFilter.h"
#include "aNavArray.h"

#include "icarx/IcArxPackPush.h"

#pragma warning(disable : 4275)

class ANAV_PORT CNavFilterArray : public CNavArray<CNavFilter>
{
public:
	CNavFilterArray();
	~CNavFilterArray();

public:
	int Find(LPCTSTR str);
	int FindExact(LPCTSTR str);
	void SetFrom(LPCTSTR str, BOOL bUseFullDescrition = FALSE);
};

#include "icarx/IcArxPackPop.h"
