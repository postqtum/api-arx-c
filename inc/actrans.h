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

#include "rxnames.h"
#include "dbptrar.h"
#include "dbtrans.h"
#include "acdocman.h"

#include "icarx/IcArxPackPush.h"

class AcTransactionManager : public AcDbTransactionManager
{
public:
	ACRX_DECLARE_MEMBERS(AcTransactionManager);

	virtual Acad::ErrorStatus enableGraphicsFlush(bool doEnable) = 0;
	virtual void flushGraphics() = 0;
};

#include "icarx/IcArxPackPop.h"

inline AcTransactionManager* acTransactionManagerPtr()
{
	AcApDocument* pDoc = acDocManager->curDocument();
	return pDoc ? pDoc->transactionManager() : nullptr;
}

#define actrTransactionManager acTransactionManagerPtr()
