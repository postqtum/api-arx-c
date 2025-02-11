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
***     Description: Declaration of AcTransactionReactor class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

#include "IcArxPackPush.h"

class AcTransactionReactor : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcTransactionReactor);

	ACDBCORE2D_PORT ~AcTransactionReactor();

	virtual void endCalledOnOutermostTransaction(int& /*numTransactions*/, AcDbTransactionManager*)
	{
	}
	virtual void objectIdSwapped(const AcDbObject* /*pTransResObj*/,
								 const AcDbObject* /*pOtherObj*/, AcDbTransactionManager*)
	{
	}
	virtual void transactionAborted(int& /*numTransactions*/, AcDbTransactionManager*) {}
	virtual void transactionAboutToAbort(int& /*numTransactions*/, AcDbTransactionManager*) {}
	virtual void transactionAboutToEnd(int& /*numTransactions*/, AcDbTransactionManager*) {}
	virtual void transactionAboutToStart(int& /*numTransactions*/, AcDbTransactionManager*) {}
	virtual void transactionEnded(int& /*numTransactions*/, AcDbTransactionManager*) {}
	virtual void transactionStarted(int& /*numTransactions*/, AcDbTransactionManager*) {}
};

#include "IcArxPackPop.h"
