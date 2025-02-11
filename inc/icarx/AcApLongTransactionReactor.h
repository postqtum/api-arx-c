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
***     Description: Declaration of AcApLongTransactionReactor class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../AcCoreDefs.h"
#include "../dbidar.h"

class AcDbLongTransaction;

#define AC_LONG_TRANSACTION_MANAGER_OBJ ACRX_T("AcApLongTransactionManager")

#include "IcArxPackPush.h"

class AcApLongTransactionReactor : public AcRxObject
{
	friend class AcApImpLongTransactionManager;

private:
	uint8_t mVeto;

protected:
	Acad::ErrorStatus veto();

public:
	ACRX_DECLARE_MEMBERS(AcApLongTransactionReactor);

	ACCORE_PORT virtual ~AcApLongTransactionReactor();

	virtual void abortLongTransaction(AcDbLongTransaction&) {}
	virtual void beginCheckIn(AcDbLongTransaction&) {}
	virtual void beginCheckOut(AcDbLongTransaction&, AcDbObjectIdArray& /*originList*/) {}
	virtual void endCheckIn(AcDbLongTransaction&) {}
	virtual void endCheckOut(AcDbLongTransaction&) {}
};

#include "IcArxPackPop.h"
