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
***     Description: Declaration of AcRxMemberReactor class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

#include "IcArxPackPush.h"

class AcRxMemberReactor
{
public:
	virtual ~AcRxMemberReactor() = default;

	virtual void goodbye(const AcRxMember* pMember) { (pMember); }
};

#include "IcArxPackPop.h"
