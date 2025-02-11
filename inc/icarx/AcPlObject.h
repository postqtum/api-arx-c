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
***     Description: Declaration of AcPlObject class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AcHeapOpers.h"
#include "../AcPl.h"

class AcPlObjectImp;
class AcPlSystemInternals;

#include "IcArxPackPush.h"

class ADESK_NO_VTABLE AcPlObject
		: public AcRxObject
		, public AcHeapOperators
{
	friend class AcPlSystemInternals;

private:
	AcPlObjectImp* m_pImpl;

protected:
	AcPlObject();
	AcPlObject(AcPlSystemInternals*);

public:
	ACRX_DECLARE_MEMBERS(AcPlObject);

	ACPL_PORT virtual ~AcPlObject();
};

#include "IcArxPackPop.h"
