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
***     Description: Declaration of AcRxMethod class
***
*****************************************************************************/
#pragma once

#include "acbasedefs.h"
#include "adesk.h"
#include "acadstrc.h"
#include "rxmember.h"

class AcRxValue;
class AcRxMethodImp;
class AcRxMethodIteratorImp;

#include "icarx/IcArxPackPush.h"

class AcRxMethod : public AcRxMember
{
	friend class AcRxMethodImp;

protected:
	ACBASE_PORT AcRxMethod(AcRxMethodImp*);
	ACBASE_PORT AcRxMethod(const ACHAR* name, const AcRxValueType& type);
	ACBASE_PORT ~AcRxMethod();

	virtual Acad::ErrorStatus subInvoke(AcRxObject* pO, AcRxValue& param) const;
	virtual Acad::ErrorStatus subIsExecutable(const AcRxObject* pO, const AcRxValue& param) const;

public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcRxMethod, ACBASE_PORT);

	ACBASE_PORT Acad::ErrorStatus invoke(AcRxObject* pO, AcRxValue& param) const;
	ACBASE_PORT Acad::ErrorStatus isExecutable(const AcRxObject* pO, const AcRxValue& param) const;
};

#include "icarx/IcArxPackPop.h"
