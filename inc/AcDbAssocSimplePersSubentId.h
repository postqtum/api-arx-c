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
***     Description: Declaration of AcDbAssocSimplePersSubentId class
***
*****************************************************************************/
#pragma once

#include "dbsubeid.h"
#include "AcDbAssocPersSubentId.h"

#include "icarx/IcArxPackPush.h"

class ACDBCORE2D_PORT AcDbAssocSimplePersSubentId : public AcDbAssocPersSubentId
{
public:
	ACRX_DECLARE_MEMBERS(AcDbAssocSimplePersSubentId);

public:
	explicit AcDbAssocSimplePersSubentId(AcDbSubentId subentId = kNullSubentId);

	Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	bool isEqualTo(const AcDbEntity* pEntity, AcDbDatabase* pDatabase,
				   const AcDbAssocPersSubentId* pOther) const override;
	bool isNull() const override;
	void setSubentId(const AcDbSubentId& newSubentId);
	virtual AcDbSubentId subentId(const AcDbEntity*) const;
	AcDb::SubentType subentType(const AcDbEntity* pEntity, AcDbDatabase* pDatabase) const override;
	int transientSubentCount(const AcDbEntity* pEntity, AcDbDatabase* pDatabase) const override;
};

#include "icarx/IcArxPackPop.h"
