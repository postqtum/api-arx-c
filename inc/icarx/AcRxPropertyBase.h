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
***     Description: Declaration of AcRxPropertyBase class
***
*****************************************************************************/
#pragma once

#include "AcRxMember.h"

class AcRxPropertyBaseImp;

#include "IcArxPackPush.h"

class AcRxPropertyBase : public AcRxMember
{
protected:
	ACBASE_PORT AcRxPropertyBase(AcRxPropertyBaseImp*);
	ACBASE_PORT ~AcRxPropertyBase();

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxPropertyBase, ACBASE_PORT);

	ACBASE_PORT bool isReadOnly(const AcRxObject* pO) const;
};

#include "IcArxPackPop.h"
