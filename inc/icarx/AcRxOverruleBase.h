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
***     Description: Declaration of AcRxOverruleBase class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"

class AcRxOverruleIteratorBase;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcRxOverruleBase : public AcRxObject
{
	friend class AcRxOverruleInternals;

private:
	mutable AcRxOverruleIteratorBase* m_pIter = nullptr;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxOverruleBase, ACBASE_PORT);
};

#include "IcArxPackPop.h"
