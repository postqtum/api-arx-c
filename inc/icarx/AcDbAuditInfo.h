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
***     Description: Declaration of AcDbAuditInfo class
***
*****************************************************************************/
#pragma once

#include "../AdAChar.h"

class AcDbObject;
class AcDbObjectId;
class AcRxClass;
class AcDbHandle;

#include "IcArxPackPush.h"

class AcDbAuditInfo
{
	friend class AcDbImpAuditInfo;
	friend class AcDbAuditImp;

public:
	enum AuditPass
	{
		PASS1 = 1,
		PASS2 = 2
	};

private:
	AcDbImpAuditInfo* mpImpAudit;

public:
	AcDbAuditInfo();
	~AcDbAuditInfo();

	AcDbAuditInfo(const AcDbAuditInfo&) = delete;
	AcDbAuditInfo& operator=(const AcDbAuditInfo&) = delete;

	AuditPass auditPass() const;
	void errorsFixed(int count);
	void errorsFound(int count);
	Acad::ErrorStatus fetchObject(AcDbObjectId originalObjId, AcDbObjectId& newObjId,
								  AcRxClass* pObjClass, bool uneraseIfPossible = false,
								  bool createIfNotFound = true, bool externalDbOk = false);
	bool fixErrors() const;
	void incNumEntities();
	int numEntities();
	int numErrors() const;
	int numFixes() const;
	void printError(const ACHAR* name, const ACHAR* value, const ACHAR* validation,
					const ACHAR* defaultValue);
	void printError(const AcDbObject* pObj, const ACHAR* value, const ACHAR* validation,
					const ACHAR* defaultValue);
	void printNumEntities(const ACHAR* msg);
	Acad::ErrorStatus registerObject(AcDbHandle handle, bool objIsValid, AcRxClass* pObjClass);
	void requestRegen();
	void resetNumEntities();
	Acad::ErrorStatus updateObject(AcDbHandle handle, bool setFileObjIsValid, bool setNewObjIsValid,
								   bool setFileObjClass, bool setNewObjClass, bool setNewObjId,
								   bool fileObjIsValid, bool newObjIsValid,
								   AcRxClass* pFileObjClass, AcRxClass* pNewObjClass,
								   AcDbObjectId newObjId);
};

#include "IcArxPackPop.h"
