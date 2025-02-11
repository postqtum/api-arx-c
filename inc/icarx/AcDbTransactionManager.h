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
***     Description: Declaration of AcDbTransactionManager class
***
*****************************************************************************/
#pragma once

#include "../dbmain.h"

class AcTransaction;
class AcTransactionReactor;

#include "IcArxPackPush.h"

class AcDbTransactionManager : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbTransactionManager);

	virtual Acad::ErrorStatus abortTransaction() = 0;
	virtual Acad::ErrorStatus addNewlyCreatedDBRObject(AcDbObject* obj, bool add = true) = 0;
	virtual void addReactor(AcTransactionReactor* reactor) = 0;
	virtual Acad::ErrorStatus endTransaction() = 0;
	virtual Acad::ErrorStatus getAllObjects(AcArray<AcDbObject*>& objs) = 0;
	virtual Acad::ErrorStatus getObject(AcDbObject*& obj, AcDbObjectId id,
										AcDb::OpenMode mode = AcDb::kForRead,
										bool openErasedObj = false) = 0;
	virtual Acad::ErrorStatus markObjectPageable(AcDbObject* pObject) = 0;
	virtual int numActiveTransactions() = 0;
	virtual int numOpenedObjects() = 0;
	virtual Acad::ErrorStatus queueForGraphicsFlush() = 0;
	virtual void removeReactor(AcTransactionReactor* reactor) = 0;
	virtual AcTransaction* startTransaction() = 0;
	virtual AcTransaction* topTransaction() = 0;
};

#include "IcArxPackPop.h"
