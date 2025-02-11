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
***     Description: Declaration of AcDbObjectContextManager class
***
*****************************************************************************/
#pragma once

#include "acdb.h"
#include "dbmain.h"
#include "AcString.h"

class AcDbObjectContextCollection;
class AcDbObjectContext;
class AcDbImpObjectContextManager;

#include "icarx/IcArxPackPush.h"

class AcDbObjectContextManager : public AcRxObject
{
	friend class AcDbContextDataSubManager;

private:
	AcDbImpObjectContextManager* mpImp;

public:
	ACRX_DECLARE_MEMBERS(AcDbObjectContextManager);

	AcDbObjectContextManager();
	~AcDbObjectContextManager();

	AcDbObjectContextCollection* const contextCollection(const AcString& collectionName) const;
	Acad::ErrorStatus registerContextCollection(const AcString& collectionName,
												AcDbObjectContextCollection* pCollection);
	Acad::ErrorStatus unregisterContextCollection(const AcString& collectionName);
};

#include "icarx/IcArxPackPop.h"
