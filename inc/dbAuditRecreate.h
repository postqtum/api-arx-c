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

#include "acdb.h"

class AcDbAuditRecreatePE : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAuditRecreatePE);

	virtual bool redirect(AcDbObjectId& newObjId, AcDbObjectId originalObjId, AcRxClass* pObjClass,
						  AcDbDatabase* pDb, AcDbAuditInfo* pAuditInfo)
	{
		(void)(newObjId);
		(void)(originalObjId);
		(void)(pObjClass);
		(void)(pDb);
		(void)(pAuditInfo);
		return false;
	};

	virtual bool replace(AcDbObject*& pNewObj, AcDbObjectId originalObjId, AcRxClass* pObjClass,
						 AcDbDatabase* pDb, AcDbAuditInfo* pAuditInfo)
	{
		(void)(pNewObj);
		(void)(originalObjId);
		(void)(pObjClass);
		(void)(pDb);
		(void)(pAuditInfo);
		return false;
	};
};
