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
***     Description: Declaration of AcDbAssocPersSubentId class
***
*****************************************************************************/
#pragma once

#include "rxobject.h"
#include "dbsubeid.h"

class AcDbAuditInfo;
class AcDbDatabase;
class AcDbDwgFiler;
class AcDbDxfFiler;
class AcDbEntity;

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocPersSubentId : public AcRxObject
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocPersSubentId);

	AcDbAssocPersSubentId() = default;
	~AcDbAssocPersSubentId() = default;

	virtual Acad::ErrorStatus audit(AcDbAuditInfo*) { return Acad::eOk; }
	Acad::ErrorStatus copyFrom(const AcRxObject* pSource) override;
	static Acad::ErrorStatus createObjectAndDwgInFields(
			AcDbDatabase* pDatabase, AcDbDwgFiler* pFiler,
			AcDbAssocPersSubentId*& pCreatedPersSubentId);
	static Acad::ErrorStatus createObjectAndDxfInFields(
			AcDbDxfFiler* pFiler, AcDbAssocPersSubentId*& pCreatedPersSubentId);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	virtual Acad::ErrorStatus getTransientSubentIds(const AcDbEntity* pEntity,
													AcDbDatabase* pDatabase,
													AcArray<AcDbSubentId>& subents) const;
	virtual bool isEqualTo(const AcDbEntity* pEntity, AcDbDatabase* pDatabase,
						   const AcDbAssocPersSubentId* pOther) const;
	virtual bool isNull() const = 0;
	virtual Acad::ErrorStatus mirror(const AcDbEntity* pMirroredEntity, AcDbDatabase* pDatabase);
	virtual Acad::ErrorStatus release(AcDbEntity* pEntity, AcDbDatabase* pDatabase) const;
	virtual AcDb::SubentType subentType(const AcDbEntity* pEntity,
										AcDbDatabase* pDatabase) const = 0;
	virtual int transientSubentCount(const AcDbEntity* pEntity, AcDbDatabase* pDatabase) const;
};

#include "icarx/IcArxPackPop.h"
