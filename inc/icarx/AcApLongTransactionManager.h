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
***     Description: Declaration of AcApLongTransactionManager class
***
*****************************************************************************/
#pragma once

#include "../rxobject.h"
#include "../dbidar.h"

#include "AcApLongTransactionReactor.h"

class AcDbIdMapping;
class AcApDocument;

#include "IcArxPackPush.h"

class AcApLongTransactionManager : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcApLongTransactionManager);

	virtual Acad::ErrorStatus abortLongTransaction(AcDbObjectId transId, bool keepObjs = false) = 0;
	virtual Acad::ErrorStatus addClassFilter(AcRxClass*) = 0;
	virtual void addReactor(AcApLongTransactionReactor*) = 0;
	virtual Acad::ErrorStatus checkIn(AcDbObjectId transId, AcDbIdMapping& errorMap,
									  bool keepObjs = false) = 0;
	virtual Acad::ErrorStatus checkOut(AcDbObjectId& transId, AcDbObjectIdArray& objList,
									   AcDbObjectId toBlock, AcDbIdMapping& errorMap,
									   AcDbObjectId lockBlkRef = AcDbObjectId::kNull) = 0;
	virtual AcDbObjectId currentLongTransactionFor(const AcApDocument* pDoc) const = 0;
	virtual bool isFiltered(AcRxClass*) const = 0;
	virtual void removeReactor(AcApLongTransactionReactor*) = 0;
};

#include "IcArxPackPop.h"

extern AcApLongTransactionManager* acapLongTransactionManagerPtr();
#define acapLongTransactionManager acapLongTransactionManagerPtr()
