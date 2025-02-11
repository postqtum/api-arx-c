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
***     Description: Declaration of AcDbAssocEdgePersSubentId class
***
*****************************************************************************/
#pragma once

#include "acarray.h"
#include "dbsubeid.h"
#include "AcDbAssocPersSubentId.h"

#include "icarx/IcArxPackPush.h"

class AcDbAssocEdgePersSubentId : public AcDbAssocPersSubentId
{
public:
	ACRX_DECLARE_MEMBERS_EXPIMP(AcDbAssocEdgePersSubentId, ACDBCORE2D_PORT);

public:
	ACDBCORE2D_PORT AcDbAssocEdgePersSubentId() = default;
	ACDBCORE2D_PORT explicit AcDbAssocEdgePersSubentId(int vertexIdentifier1,
													   int vertexIdentifier2);
	ACDBCORE2D_PORT explicit AcDbAssocEdgePersSubentId(int vertexIdentifier1, int vertexIdentifier2,
													   bool isSegArcCenter, bool isSegMidpoint);

	ACDBCORE2D_PORT Acad::ErrorStatus audit(AcDbAuditInfo* pAuditInfo) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler) override;
	ACDBCORE2D_PORT Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const override;
	ACDBCORE2D_PORT int index1() const;
	ACDBCORE2D_PORT int index2() const;
	ACDBCORE2D_PORT bool isEqualTo(const AcDbEntity* pEntity, AcDbDatabase* pDatabase,
								   const AcDbAssocPersSubentId* pOther) const override;
	ACDBCORE2D_PORT bool isNull() const override;
	ACDBCORE2D_PORT bool isSegmentArcCenter() const;
	ACDBCORE2D_PORT bool isSegmentMidpoint() const;
	ACDBCORE2D_PORT AcDb::SubentType subentType(const AcDbEntity* pEntity,
												AcDbDatabase* pDatabase) const override;
	ACDBCORE2D_PORT int transientSubentCount(const AcDbEntity* pEntity,
											 AcDbDatabase* pDatabase) const override;
};

#include "icarx/IcArxPackPop.h"
